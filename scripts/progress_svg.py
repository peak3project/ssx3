"""Regenerates docs/progress.svg, the progress bars shown in README.md.

Requires a dual build first: `./configure.py -c -o && ninja`.

Every function is put in one of four states from objdiff's report: Matched (100%), Close (90-99%),
Partial (an attempt below 90%) and Not attempted (no C implementation, so objdiff scores it 0).
The top bar counts functions; the bottom bar weighs them by code size.
"""

import datetime
import json
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).parent.parent
OBJDIFF_CLI = ROOT / "tools" / "objdiff" / "objdiff-cli"
if os.environ.get("OBJDIFF_CLI"):
    OBJDIFF_CLI = Path(os.environ["OBJDIFF_CLI"])
elif sys.platform == "darwin":
    # The committed objdiff-cli is a Linux binary; on macOS use the
    # objdiff-cli-macos-* release asset saved as tools/objdiff/objdiff-cli-macos.
    OBJDIFF_CLI = ROOT / "tools" / "objdiff" / "objdiff-cli-macos"
OUTPUT = ROOT / "docs" / "progress.svg"

WIDTH, HEIGHT = 840, 196
BAR_X, BAR_W, BAR_H, GAP = 20, 800, 20, 2

STATES = [
    ("matched", "Matched (100%)"),
    ("close", "Close (90-99%)"),
    ("partial", "Partial (&lt;90%)"),
    ("track", "Not attempted"),
]

STYLE = """<style>
  .surface { fill: #fcfcfb; } text { font-family: system-ui, -apple-system, "Segoe UI", sans-serif; fill: #0b0b0b; }
  .ink2 { fill: #52514e; } .muted { fill: #898781; } .track { fill: #c3c2b7; } .num { font-variant-numeric: tabular-nums; }
  .matched { fill: #0ca30c; } .close { fill: #fab219; } .partial { fill: #d03b3b; }
  @media (prefers-color-scheme: dark) {
    .surface { fill: #0d1117; } text { fill: #ffffff; } .ink2 { fill: #c3c2b7; } .track { fill: #45443f; }
  }
</style>"""


def generate_report():
    if not (ROOT / "obj" / "target").exists() or not (ROOT / "obj" / "current").exists():
        print("obj/target and obj/current not found.")
        print("Run `./configure.py -c -o && ninja` first (the -o flag builds the")
        print("dual target/current objects objdiff needs to compare).")
        sys.exit(1)
    report_path = ROOT / "objdiff_report_svg.tmp.json"
    result = subprocess.run(
        [str(OBJDIFF_CLI), "report", "generate", "-p", str(ROOT), "-o", str(report_path), "-f", "json"],
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        print("objdiff-cli failed:", result.stderr, file=sys.stderr)
        sys.exit(1)
    data = json.loads(report_path.read_text())
    report_path.unlink()
    return data


def state_of(percent):
    if percent >= 100.0:
        return "matched"
    if percent >= 90.0:
        return "close"
    if percent > 0.0:
        return "partial"
    return "track"


def tally(report):
    """Function counts and code bytes per state, summed over every unit's functions."""
    counts = {s: 0 for s, _ in STATES}
    sizes = {s: 0 for s, _ in STATES}
    for unit in report["units"]:
        for f in unit.get("functions", []):
            s = state_of(f.get("fuzzy_match_percent", 0.0))
            counts[s] += 1
            sizes[s] += int(f.get("size", 0))
    return counts, sizes


def bar(y, label, values, unit_word, fmt):
    """One stacked bar: segments are laid out proportionally with a GAP between visible segments."""
    total = sum(values.values())
    visible = [s for s, _ in STATES if values[s] > 0]
    usable = BAR_W - GAP * (len(visible) - 1)
    out = [f'<clipPath id="clip{BAR_X}_{y}_{BAR_W}"><rect x="{BAR_X}" y="{y}" width="{BAR_W}" height="{BAR_H}" rx="4"/></clipPath>'
           f'<g clip-path="url(#clip{BAR_X}_{y}_{BAR_W})">']
    x = float(BAR_X)
    for i, (s, name) in enumerate(STATES):
        v = values[s]
        if v == 0:
            continue
        w = usable * v / total
        if s == visible[-1]:
            w = BAR_X + BAR_W - x  # absorb rounding so the bar ends exactly at the right edge
        pct = 100.0 * v / total
        out.append(f'<rect class="{s}" x="{x:.2f}" y="{y}" width="{w:.2f}" height="{BAR_H}">'
                   f'<title>{label} · {name}: {fmt(v)} {unit_word} ({pct:.1f}%)</title></rect>')
        x += w + GAP
    out.append("</g>")
    return "".join(out)


def main():
    report = generate_report()
    m = report["measures"]
    counts, sizes = tally(report)
    total_f = int(m["total_functions"])
    matched_f = int(m["matched_functions"])
    total_code = int(m["total_code"])
    matched_code = int(m["matched_code"])
    func_pct = float(m["matched_functions_percent"])
    code_pct = float(m["matched_code_percent"])
    today = datetime.date.today().isoformat()

    lines = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{WIDTH}" height="{HEIGHT}" viewBox="0 0 {WIDTH} {HEIGHT}" role="img" aria-labelledby="t d">',
        '<title id="t">SSX 3 decompilation progress</title>',
        f'<desc id="d">{matched_f:,} of {total_f:,} functions match ({func_pct:.1f}%); {code_pct:.1f}% of code bytes ({today}).</desc>',
        STYLE,
        f'<rect class="surface" width="{WIDTH}" height="{HEIGHT}" rx="8"/>',
        '<text x="20" y="34" font-size="14" font-weight="600">Functions</text>',
        f'<text x="124" y="34" font-size="14" font-weight="600">{func_pct:.1f}% matched</text>',
        f'<text x="820" y="34" font-size="13" class="ink2 num" text-anchor="end">{matched_f:,} / {total_f:,} functions</text>',
        bar(44, "Functions", counts, "functions", lambda v: f"{v:,}"),
        '<text x="20" y="96" font-size="14" font-weight="600">Code bytes</text>',
        f'<text x="124" y="96" font-size="14" font-weight="600">{code_pct:.1f}% matched</text>',
        f'<text x="820" y="96" font-size="13" class="ink2 num" text-anchor="end">{matched_code / 1e6:.2f} / {total_code / 1e6:.2f} MB of code</text>',
        bar(106, "Code bytes", sizes, "bytes", lambda v: f"{v:,}"),
    ]
    for i, (s, name) in enumerate(STATES):
        x = 20 + 200 * i
        lines.append(f'<rect class="{s}" x="{x}" y="162" width="12" height="12" rx="3"/>')
        lines.append(f'<text x="{x + 18}" y="172" font-size="12"><tspan>{name}</tspan>'
                     f'<tspan class="muted num"> · {counts[s]:,}</tspan></text>')
    lines.append(f'<text x="820" y="190" font-size="10" class="muted" text-anchor="end">updated {today}</text>')
    lines.append("</svg>")

    OUTPUT.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {OUTPUT.relative_to(ROOT)}: {matched_f:,} / {total_f:,} functions ({func_pct:.1f}%), "
          f"{code_pct:.1f}% of code bytes")


if __name__ == "__main__":
    main()
