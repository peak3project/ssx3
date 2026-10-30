# Function matching report

Auto-generated from [objdiff](tools/objdiff) by diffing every unit's `obj/target` against `obj/current`. Regenerate with a dual build (`./configure.py -c -o && ninja`) followed by `python3 scripts/matching_report.py`; see [CONTRIBUTING.md](CONTRIBUTING.md).

Snapshot of commit `de860dcd`, generated 2026-10-30.

**Status definitions:**
- **Matching** — byte-for-byte identical to the retail binary (100%), or a near-miss that objdiff's own report scores as matched despite a lower raw percentage (the only remaining byte difference is a relocation immediate baked in at link time by the original SN toolchain, not a real code difference — see the gp-relative note in [README.md](README.md)). Taken per function from objdiff's report; nothing is promoted to make counts agree.
- **Partial** — has a C implementation (not raw `INCLUDE_ASM`) but doesn't yet byte-match; the percentage is objdiff's fuzzy match score.
- **Not started** — still a raw `INCLUDE_ASM` stub with no C implementation attempted.

| | Count | % of total |
|---|---|---|
| Matching | 14,253 | 94.29% |
| Partial | 5 | 0.03% |
| Not started | 858 | 5.68% |
| **Total** | **15,116** | |

(Total here may differ slightly from the function count in README.md's progress table — that one comes from objdiff's own aggregate report, this one from summing every unit's individual symbol list, and the two count a handful of duplicated/weak symbols differently.)

## Per-file summary

Only files with at least one Matching or Partial function are listed here; files that are 100% Not Started are omitted from this table (see the full per-file breakdown further down for every file, including those).

| File | Matching | Partial | Not started | Total |
|---|---|---|---|---|
| `fe/feasyncfile` | 524 | 0 | 12 | 536 |
| `ealib/seg_2B4578` | 506 | 1 | 98 | 605 |
| `render/font` | 432 | 0 | 1 | 433 |
| `fe/fepopupmisc` | 375 | 1 | 5 | 381 |
| `object/railmodifier` | 354 | 0 | 15 | 369 |
| `dirtysock/tagsunk` | 307 | 0 | 10 | 317 |
| `ealib/seg_2DCAE8` | 302 | 0 | 27 | 329 |
| `bx/seg_1BA100` | 297 | 0 | 2 | 299 |
| `sound/soundsys` | 292 | 0 | 13 | 305 |
| `seg/seg_2FE810` | 288 | 0 | 78 | 366 |
| `ui/uivector` | 288 | 0 | 1 | 289 |
| `main/all_in_one_main` | 277 | 0 | 3 | 280 |
| `camera/camera` | 224 | 0 | 14 | 238 |
| `ai/control/handplantcontrol` | 219 | 0 | 14 | 233 |
| `seg/seg_2F41F8` | 219 | 0 | 34 | 253 |
| `seg/seg_325220` | 210 | 0 | 22 | 232 |
| `sound/bankmonitor` | 206 | 0 | 7 | 213 |
| `main/ssxappdtor` | 196 | 0 | 1 | 197 |
| `util/menu` | 193 | 0 | 4 | 197 |
| `replay/replaycache` | 192 | 0 | 6 | 198 |
| `scripter/ssxscriptengine` | 181 | 0 | 6 | 187 |
| `render/particle` | 171 | 0 | 44 | 215 |
| `ai/ai` | 169 | 0 | 5 | 174 |
| `wscript/wscriptman` | 149 | 0 | 3 | 152 |
| `fe/all_in_one_fe` | 146 | 0 | 8 | 154 |
| `world/wscriptcache` | 145 | 0 | 9 | 154 |
| `worldpainter/quadtree` | 145 | 0 | 6 | 151 |
| `camera/trigger/cameratriggerfactory` | 140 | 0 | 4 | 144 |
| `seg/seg_316FB8` | 137 | 0 | 0 | 137 |
| `seg/seg_3249A0` | 136 | 0 | 0 | 136 |
| `be/bedbreward` | 135 | 0 | 1 | 136 |
| `visualfx/worldlightman` | 133 | 0 | 4 | 137 |
| `movie/movieplayer` | 124 | 0 | 3 | 127 |
| `fe/fepopup` | 118 | 0 | 4 | 122 |
| `seg/seg_1FBE38` | 116 | 0 | 9 | 125 |
| `be/beintreward` | 112 | 0 | 1 | 113 |
| `seg/seg_1D3510` | 112 | 0 | 1 | 113 |
| `ai/rider` | 104 | 0 | 11 | 115 |
| `be/beintplayer` | 104 | 0 | 0 | 104 |
| `ealib/seg_2D7498` | 100 | 0 | 12 | 112 |
| `seg/seg_1218` | 97 | 0 | 13 | 110 |
| `seg/seg_156860` | 97 | 0 | 4 | 101 |
| `bx/bxstringctor` | 95 | 0 | 4 | 99 |
| `object/movenode` | 95 | 0 | 1 | 96 |
| `main/debugmenu` | 94 | 0 | 0 | 94 |
| `mem/memstd` | 91 | 0 | 5 | 96 |
| `sound/streamsys` | 87 | 0 | 0 | 87 |
| `sound/ssxAudio` | 85 | 0 | 3 | 88 |
| `fe/debugfe` | 84 | 0 | 4 | 88 |
| `fe/festatecharequipdetail` | 81 | 0 | 8 | 89 |
| `intersect/worldsphtree` | 79 | 0 | 7 | 86 |
| `worldpainter/worldpaintermanquery` | 76 | 0 | 0 | 76 |
| `fe/festaterewards` | 74 | 0 | 1 | 75 |
| `ai/computer` | 73 | 0 | 5 | 78 |
| `be/belibrary` | 70 | 0 | 10 | 80 |
| `main/gamestate` | 70 | 0 | 3 | 73 |
| `scripter/all_in_one_scripter` | 70 | 0 | 0 | 70 |
| `visualfx/boardwakefx` | 69 | 0 | 15 | 84 |
| `seg/seg_315B68_tinfo` | 68 | 0 | 0 | 68 |
| `sound/bankmanager` | 68 | 0 | 5 | 73 |
| `intersect/riderspheretree` | 67 | 0 | 10 | 77 |
| `ai/ridermetrix` | 65 | 0 | 3 | 68 |
| `bx/cubicspline` | 63 | 2 | 5 | 70 |
| `scripter/bxscriptengine` | 65 | 0 | 0 | 65 |
| `wscript/wscriptprocess` | 62 | 0 | 0 | 62 |
| `render/lightman` | 61 | 0 | 2 | 63 |
| `fe/festateoptions` | 57 | 1 | 1 | 59 |
| `fe/fememcardcallbacks` | 57 | 0 | 0 | 57 |
| `scripter/datamanager` | 57 | 0 | 0 | 57 |
| `input/inputparse` | 56 | 0 | 3 | 59 |
| `fe/ovstatepause` | 55 | 0 | 5 | 60 |
| `sound/icepick/worldtriggermanager` | 55 | 0 | 5 | 60 |
| `visualfx/renderstateman` | 55 | 0 | 0 | 55 |
| `seg/seg_2EEF50` | 51 | 0 | 6 | 57 |
| `seg/seg_14B10` | 50 | 0 | 6 | 56 |
| `ui/uiscreen` | 50 | 0 | 2 | 52 |
| `world/worldcache` | 49 | 0 | 3 | 52 |
| `main/gamemode` | 48 | 0 | 5 | 53 |
| `seg/seg_1F1548` | 48 | 0 | 8 | 56 |
| `be/beintmission` | 47 | 0 | 3 | 50 |
| `world/worldview` | 47 | 0 | 5 | 52 |
| `render/graphicsman` | 46 | 0 | 13 | 59 |
| `visualfx/lensfx` | 46 | 0 | 4 | 50 |
| `animation/animsequencer` | 44 | 0 | 0 | 44 |
| `bx/bxstring` | 44 | 0 | 0 | 44 |
| `main/ssxapp` | 44 | 0 | 5 | 49 |
| `be/beintnewrace` | 41 | 0 | 0 | 41 |
| `camera/script/scriptcontroller` | 41 | 0 | 0 | 41 |
| `fe/feridermanager` | 40 | 0 | 1 | 41 |
| `replay/playbackman` | 40 | 0 | 3 | 43 |
| `bx/memblockman` | 39 | 0 | 1 | 40 |
| `object/debouncenode` | 38 | 0 | 6 | 44 |
| `object/modifierblock` | 37 | 0 | 0 | 37 |
| `replay/frameptr` | 37 | 0 | 2 | 39 |
| `dirtysock/tags` | 35 | 0 | 5 | 40 |
| `fe/festatetrophyroom` | 35 | 0 | 1 | 36 |
| `ui/uitext` | 35 | 0 | 3 | 38 |
| `animation/rideranimbase` | 34 | 0 | 1 | 35 |
| `main/loadscreens_prestart` | 34 | 0 | 0 | 34 |
| `main/gameload` | 33 | 0 | 6 | 39 |
| `object/flagset` | 33 | 0 | 3 | 36 |
| `seg/seg_313F58` | 33 | 0 | 0 | 33 |
| `ui/uiengine` | 33 | 0 | 3 | 36 |
| `object/multiparticle` | 32 | 0 | 1 | 33 |
| `object/splinemodifier` | 32 | 0 | 3 | 35 |
| `bx/execman` | 31 | 0 | 0 | 31 |
| `fe/ovstatehud` | 31 | 0 | 5 | 36 |
| `object/flexrailnode` | 31 | 0 | 3 | 34 |
| `render/ps2graphicsman` | 31 | 0 | 1 | 32 |
| `animation/animmodel` | 30 | 0 | 4 | 34 |
| `be/beintecon` | 30 | 0 | 2 | 32 |
| `fe/festatebuyattrib` | 30 | 0 | 1 | 31 |
| `fe/uitemplatemap` | 30 | 0 | 8 | 38 |
| `object/effectlink` | 30 | 0 | 0 | 30 |
| `seg/seg_32F020` | 30 | 0 | 0 | 30 |
| `fe/festateloadscreen` | 29 | 0 | 0 | 29 |
| `main/game` | 28 | 0 | 4 | 32 |
| `seg/seg_2F0F40` | 28 | 0 | 3 | 31 |
| `luno/lunovm` | 27 | 0 | 1 | 28 |
| `visualfx/avalanche` | 27 | 0 | 8 | 35 |
| `fe/festateloadhint` | 25 | 0 | 2 | 27 |
| `seg/seg_313800_exception` | 25 | 0 | 0 | 25 |
| `fe/festatenethelppopup` | 24 | 0 | 0 | 24 |
| `fe/ovstatemap` | 24 | 0 | 1 | 25 |
| `object/instanceman` | 24 | 0 | 1 | 25 |
| `path/pathsys` | 24 | 0 | 0 | 24 |
| `seg/seg_3113A0_eh` | 24 | 0 | 5 | 29 |
| `ui/uistatestack` | 24 | 0 | 1 | 25 |
| `util/objectinterface` | 24 | 0 | 1 | 25 |
| `visualfx/boardtrailfx` | 24 | 0 | 6 | 30 |
| `be/beintscore` | 23 | 0 | 1 | 24 |
| `fe/ovstateprofile` | 23 | 0 | 1 | 24 |
| `ui/uimenu` | 23 | 0 | 2 | 25 |
| `fe/messagecenter` | 22 | 0 | 1 | 23 |
| `fe/ovstateenterlodge` | 22 | 0 | 0 | 22 |
| `replay/replay` | 22 | 0 | 0 | 22 |
| `be/beintbagt` | 21 | 0 | 1 | 22 |
| `camera/trigger/cameratriggerman` | 21 | 0 | 7 | 28 |
| `fe/fereal` | 21 | 0 | 1 | 22 |
| `fe/ovstatelodge` | 21 | 0 | 1 | 22 |
| `fe/ovstatetrophy` | 21 | 0 | 3 | 24 |
| `seg/seg_312310` | 21 | 0 | 0 | 21 |
| `sound/asyncsys` | 21 | 0 | 2 | 23 |
| `fe/fememcard` | 20 | 0 | 1 | 21 |
| `fe/festateprofile` | 20 | 0 | 1 | 21 |
| `fe/ovtemplatedialog` | 20 | 0 | 3 | 23 |
| `be/beintnetwork` | 19 | 0 | 0 | 19 |
| `object/bucketman` | 19 | 0 | 0 | 19 |
| `world/world` | 19 | 0 | 0 | 19 |
| `bx/appman` | 18 | 0 | 0 | 18 |
| `fe/festateruleselect` | 18 | 0 | 0 | 18 |
| `intersect/aifwddiff` | 18 | 0 | 3 | 21 |
| `animation/gameanimmap` | 17 | 0 | 1 | 18 |
| `be/beintoption` | 17 | 0 | 0 | 17 |
| `fe/festatecharselect` | 17 | 0 | 1 | 18 |
| `input/inputmap` | 17 | 0 | 0 | 17 |
| `seg/seg_2FDDC8` | 17 | 0 | 1 | 18 |
| `bx/ps2main` | 16 | 0 | 2 | 18 |
| `fe/festatebigradio` | 16 | 0 | 1 | 17 |
| `fe/ovstates` | 16 | 0 | 0 | 16 |
| `fe/ovtemplatepausemenu` | 16 | 0 | 0 | 16 |
| `object/instancenode` | 16 | 0 | 1 | 17 |
| `scripter/videngine` | 16 | 0 | 0 | 16 |
| `ui/uilistbox` | 16 | 0 | 0 | 16 |
| `util/list` | 16 | 0 | 0 | 16 |
| `util/locale` | 16 | 0 | 0 | 16 |
| `camera/cameracontroller` | 15 | 0 | 0 | 15 |
| `render/bezierman` | 15 | 0 | 5 | 20 |
| `seg/seg_1C9348` | 15 | 0 | 3 | 18 |
| `seg/seg_21A1C0` | 15 | 0 | 1 | 16 |
| `be/beintstat` | 14 | 0 | 1 | 15 |
| `fe/festatestore` | 14 | 0 | 0 | 14 |
| `ai/motion/wipeoutmotion` | 13 | 0 | 3 | 16 |
| `be/beprepoststate` | 13 | 0 | 0 | 13 |
| `fe/festateload` | 13 | 0 | 0 | 13 |
| `fe/festatelodge` | 13 | 0 | 0 | 13 |
| `object/flexbridgenode` | 13 | 0 | 4 | 17 |
| `be/be` | 12 | 0 | 0 | 12 |
| `fe/ovstatemission` | 12 | 0 | 0 | 12 |
| `object/deadfadenode` | 12 | 0 | 1 | 13 |
| `be/beintsavefile` | 11 | 0 | 1 | 12 |
| `camera/trigger/cameratriggerlist` | 11 | 0 | 0 | 11 |
| `fe/festateriderbio` | 11 | 0 | 0 | 11 |
| `object/objnode` | 11 | 0 | 0 | 11 |
| `scripter/scsndmgr` | 11 | 0 | 0 | 11 |
| `ui/uianimation` | 11 | 0 | 0 | 11 |
| `ui/uistate` | 11 | 0 | 0 | 11 |
| `ui/uithing` | 11 | 0 | 1 | 12 |
| `world/streamman` | 11 | 0 | 0 | 11 |
| `animation/mdfarchive` | 10 | 0 | 0 | 10 |
| `be/beintaggression` | 10 | 0 | 0 | 10 |
| `be/beintcharacter` | 10 | 0 | 0 | 10 |
| `bx/bxrandom` | 10 | 0 | 0 | 10 |
| `camera/trigger/triggeralgorithms` | 10 | 0 | 0 | 10 |
| `fe/festatecredits` | 10 | 0 | 0 | 10 |
| `main/streampause` | 10 | 0 | 0 | 10 |
| `util/statemachine` | 10 | 0 | 2 | 12 |
| `visualfx/angerfx` | 10 | 0 | 1 | 11 |
| `ai/airpredictor` | 9 | 0 | 1 | 10 |
| `fe/festatecharsetup` | 9 | 0 | 0 | 9 |
| `fe/festateriderbiodetail` | 9 | 0 | 0 | 9 |
| `object/animnode` | 9 | 0 | 0 | 9 |
| `camera/cameraalgorithms` | 8 | 0 | 1 | 9 |
| `main/gamerender` | 8 | 0 | 0 | 8 |
| `scripter/scanimmgr` | 8 | 0 | 0 | 8 |
| `visualfx/crowdrender2d` | 8 | 0 | 0 | 8 |
| `bx/bigfile` | 7 | 0 | 0 | 7 |
| `bx/memman` | 7 | 0 | 1 | 8 |
| `fe/festateaudiooptions` | 7 | 0 | 1 | 8 |
| `main/sectionman` | 7 | 0 | 0 | 7 |
| `object/floatingnode` | 7 | 0 | 3 | 10 |
| `fe/ovstatereplay` | 6 | 0 | 2 | 8 |
| `hashvalue` | 6 | 0 | 0 | 6 |
| `be/bedbprofile` | 5 | 0 | 0 | 5 |
| `fe/festatebonusmaterial` | 5 | 0 | 0 | 5 |
| `fe/festatecharequip` | 5 | 0 | 0 | 5 |
| `fe/festatetransition` | 5 | 0 | 0 | 5 |
| `seg/seg_2125C8` | 5 | 0 | 1 | 6 |
| `seg/seg_218AE8` | 5 | 0 | 0 | 5 |
| `seg/seg_218F38` | 5 | 0 | 0 | 5 |
| `wscript/wscriptcompile` | 5 | 0 | 0 | 5 |
| `be/bestate` | 4 | 0 | 0 | 4 |
| `bx/blockman` | 4 | 0 | 1 | 5 |
| `fe/feflowstate` | 4 | 0 | 0 | 4 |
| `fe/festateselectmp` | 4 | 0 | 0 | 4 |
| `fe/ovstaterewardslist` | 4 | 0 | 0 | 4 |
| `md5` | 4 | 0 | 0 | 4 |
| `object/spline3d` | 4 | 0 | 0 | 4 |
| `object/spring` | 4 | 0 | 0 | 4 |
| `seg/seg_1DCD10` | 4 | 0 | 3 | 7 |
| `seg/seg_6D428` | 4 | 0 | 0 | 4 |
| `seg/seg_CF758` | 4 | 0 | 0 | 4 |
| `visualfx/boardsparkfx` | 4 | 0 | 1 | 5 |
| `camera/cameraalgolist` | 3 | 0 | 0 | 3 |
| `camera/trigger/cameratriggervolumes` | 3 | 0 | 0 | 3 |
| `fe/festatedebug` | 3 | 0 | 0 | 3 |
| `fe/festatelegal` | 3 | 0 | 1 | 4 |
| `seg/seg_21E5A8` | 3 | 0 | 0 | 3 |
| `sound/ps2soundman` | 3 | 0 | 0 | 3 |
| `worldpainter/worldpainterqueryctor` | 3 | 0 | 1 | 4 |
| `main/loadscreens` | 2 | 0 | 2 | 4 |
| `render/irradiance` | 2 | 0 | 0 | 2 |
| `render/ps2bezierman` | 2 | 0 | 0 | 2 |
| `render/ps2lightman` | 2 | 0 | 0 | 2 |
| `wscript/wscriptmission` | 2 | 0 | 0 | 2 |
| `worldpainter/worldpainterman` | 1 | 0 | 0 | 1 |
| `worldpainter/worldpainterquery` | 1 | 0 | 0 | 1 |

## Full per-file breakdown

Every unit, including ones with no progress yet. Matching and Partial functions are listed individually with their match percentage; Not Started functions are only counted (there's nothing to report per-function until an implementation is attempted).

### `ai/ai`

169 matching, 0 partial, 5 not started (174 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAI_cAI` | Matching | 100.00% | 276 |
| `func_001287B8` | Matching | 100.00% | 96 |
| `func_00128818` | Matching | 100.00% | 320 |
| `func_00128958` | Matching | 100.00% | 64 |
| `func_00128998` | Matching | 100.00% | 88 |
| `func_001289F0(void*)` | Matching | 100.00% | 28 |
| `func_00128A10` | Matching | 100.00% | 52 |
| `func_00128A48` | Matching | 100.00% | 116 |
| `func_00128AC0` | Matching | 100.00% | 48 |
| `func_00128AF0` | Matching | 100.00% | 1644 |
| `func_00129160` | Matching | 100.00% | 128 |
| `func_001291E0` | Matching | 100.00% | 1300 |
| `func_001296F8` | Matching | 100.00% | 108 |
| `func_00129768` | Matching | 100.00% | 92 |
| `func_001297C8` | Matching | 100.00% | 252 |
| `func_001298C8` | Matching | 100.00% | 20 |
| `cAI_initMissionRiders` | Matching | 100.00% | 544 |
| `cAI_initComputerRiders` | Matching | 100.00% | 472 |
| `cAI_initComputerActors` | Matching | 100.00% | 392 |
| `func_0012A180` | Matching | 100.00% | 112 |
| `func_0012A1F0` | Matching | 100.00% | 76 |
| `func_0012A240` | Matching | 100.00% | 16 |
| `func_0012A250` | Matching | 100.00% | 92 |
| `func_0012A2B0` | Matching | 100.00% | 140 |
| `func_0012A340` | Matching | 100.00% | 336 |
| `func_0012A490` | Matching | 100.00% | 60 |
| `func_0012A4D0` | Matching | 100.00% | 32 |
| `func_0012A4F0` | Matching | 100.00% | 104 |
| `func_0012A558` | Matching | 100.00% | 8 |
| `func_0012A560` | Matching | 100.00% | 520 |
| `func_0012A998` | Matching | 100.00% | 224 |
| `func_0012AA78` | Matching | 100.00% | 168 |
| `func_0012AB20` | Matching | 100.00% | 176 |
| `func_0012ABD0` | Matching | 100.00% | 116 |
| `func_0012AC48` | Matching | 100.00% | 176 |
| `func_0012ACF8` | Matching | 100.00% | 116 |
| `func_0012AD70` | Matching | 100.00% | 80 |
| `func_0012ADC0` | Matching | 100.00% | 116 |
| `func_0012AE38` | Matching | 100.00% | 152 |
| `func_0012AED0` | Matching | 100.00% | 152 |
| `cAI_purgeMissionRiders` | Matching | 100.00% | 152 |
| `func_0012B000` | Matching | 100.00% | 44 |
| `func_0012B030` | Matching | 100.00% | 48 |
| `func_0012B060` | Matching | 100.00% | 48 |
| `func_0012B090` | Matching | 100.00% | 236 |
| `func_0012B180` | Matching | 100.00% | 124 |
| `func_0012B200` | Matching | 100.00% | 128 |
| `cAI_loadAnims` | Matching | 100.00% | 188 |
| `func_0012B340` | Matching | 100.00% | 224 |
| `func_0012B420` | Matching | 100.00% | 120 |
| `func_0012B498` | Matching | 100.00% | 508 |
| `func_0012B698` | Matching | 100.00% | 240 |
| `func_0012B788` | Matching | 100.00% | 100 |
| `func_0012B7F0` | Matching | 100.00% | 340 |
| `cAI_readFromReplayFrame` | Matching | 100.00% | 372 |
| `func_0012BAC0` | Matching | 100.00% | 44 |
| `func_0012BAF0` | Matching | 100.00% | 44 |
| `func_0012BB20` | Matching | 100.00% | 768 |
| `func_0012BE20` | Matching | 100.00% | 324 |
| `func_0012BF68` | Matching | 100.00% | 188 |
| `func_0012C028` | Matching | 100.00% | 80 |
| `func_0012C078` | Matching | 100.00% | 72 |
| `func_0012C0C0` | Matching | 100.00% | 112 |
| `func_0012C130` | Matching | 100.00% | 256 |
| `func_0012C230` | Matching | 100.00% | 468 |
| `func_0012C408` | Matching | 100.00% | 332 |
| `func_0012C558` | Matching | 100.00% | 52 |
| `func_0012C590` | Matching | 100.00% | 52 |
| `func_0012C5C8` | Matching | 100.00% | 172 |
| `func_0012C678` | Matching | 100.00% | 840 |
| `func_0012C9C0` | Matching | 100.00% | 52 |
| `func_0012C9F8` | Matching | 100.00% | 52 |
| `func_0012CA30` | Matching | 100.00% | 308 |
| `func_0012CB68` | Matching | 100.00% | 436 |
| `func_0012CD20` | Matching | 100.00% | 1084 |
| `func_0012D160` | Matching | 100.00% | 904 |
| `func_0012D4E8` | Matching | 100.00% | 860 |
| `func_0012D848` | Matching | 100.00% | 400 |
| `func_0012D9D8` | Matching | 100.00% | 172 |
| `func_0012DA88` | Matching | 100.00% | 548 |
| `func_0012DCB0` | Matching | 100.00% | 232 |
| `func_0012DD98` | Matching | 100.00% | 232 |
| `func_0012DE80` | Matching | 100.00% | 200 |
| `func_0012DF48` | Matching | 100.00% | 200 |
| `func_0012E010` | Matching | 100.00% | 1112 |
| `func_0012E468` | Matching | 100.00% | 188 |
| `func_0012E528` | Matching | 100.00% | 356 |
| `func_0012E690` | Matching | 100.00% | 120 |
| `func_0012E708` | Matching | 100.00% | 52 |
| `func_0012E740` | Matching | 100.00% | 52 |
| `func_0012E778` | Matching | 100.00% | 516 |
| `func_0012E980` | Matching | 100.00% | 48 |
| `func_0012E9B0(void*)` | Matching | 100.00% | 8 |
| `func_0012E9B8` | Matching | 100.00% | 1140 |
| `func_0012EE30` | Matching | 100.00% | 744 |
| `func_0012F118` | Matching | 100.00% | 280 |
| `func_0012F230` | Matching | 100.00% | 360 |
| `func_0012F398` | Matching | 100.00% | 496 |
| `func_0012F588` | Matching | 100.00% | 36 |
| `func_0012F5B0` | Matching | 100.00% | 52 |
| `func_0012F5E8` | Matching | 100.00% | 52 |
| `func_0012F620` | Matching | 100.00% | 272 |
| `func_0012F730` | Matching | 100.00% | 1080 |
| `func_0012FB68` | Matching | 100.00% | 136 |
| `func_0012FBF0` | Matching | 100.00% | 52 |
| `func_0012FC28` | Matching | 100.00% | 52 |
| `func_0012FC60(void*)` | Matching | 100.00% | 32 |
| `func_0012FC80` | Matching | 100.00% | 536 |
| `func_0012FE98` | Matching | 100.00% | 44 |
| `func_0012FEC8` | Matching | 100.00% | 300 |
| `func_0012FFF8` | Matching | 100.00% | 556 |
| `func_00130228` | Matching | 100.00% | 440 |
| `func_001303E0` | Matching | 100.00% | 236 |
| `func_001304D0(void*)` | Matching | 100.00% | 12 |
| `func_001304E0` | Matching | 100.00% | 460 |
| `func_001306B0` | Matching | 100.00% | 264 |
| `func_001307B8` | Matching | 100.00% | 284 |
| `func_001308D8` | Matching | 100.00% | 1268 |
| `func_00130DD0` | Matching | 100.00% | 1072 |
| `func_00131200` | Matching | 100.00% | 324 |
| `func_00131348` | Matching | 100.00% | 92 |
| `func_001313A8` | Matching | 100.00% | 124 |
| `func_00131428` | Matching | 100.00% | 368 |
| `func_00131598` | Matching | 100.00% | 52 |
| `func_001315D0` | Matching | 100.00% | 52 |
| `func_00131608(void*)` | Matching | 100.00% | 20 |
| `func_00131620` | Matching | 100.00% | 1552 |
| `func_00131C30` | Matching | 100.00% | 140 |
| `func_00131CC0` | Matching | 100.00% | 68 |
| `func_00131D08` | Matching | 100.00% | 40 |
| `func_00131D30` | Matching | 100.00% | 788 |
| `func_00132048` | Matching | 100.00% | 20 |
| `func_00132060` | Matching | 100.00% | 1472 |
| `func_00132620` | Matching | 100.00% | 164 |
| `func_001326C8` | Matching | 100.00% | 164 |
| `func_00132770` | Matching | 100.00% | 208 |
| `func_00132840` | Matching | 100.00% | 52 |
| `func_00132878` | Matching | 100.00% | 52 |
| `func_001328B0` | Matching | 100.00% | 252 |
| `func_001329B0` | Matching | 100.00% | 128 |
| `func_001330B8` | Matching | 100.00% | 52 |
| `func_001330F0` | Matching | 100.00% | 52 |
| `func_00135EB0` | Matching | 100.00% | 64 |
| `func_00135EF0` | Matching | 100.00% | 64 |
| `func_00135F30` | Matching | 100.00% | 64 |
| `func_001361F8` | Matching | 100.00% | 52 |
| `func_00136230` | Matching | 100.00% | 52 |
| `func_001368E8` | Matching | 100.00% | 52 |
| `func_00136920` | Matching | 100.00% | 52 |
| `func_00136958` | Matching | 100.00% | 28 |
| `func_00136978(void*)` | Matching | 100.00% | 8 |
| `func_00136980` | Matching | 100.00% | 332 |
| `func_00134DD0` | Matching | 99.98% | 940 |
| `func_00132FB8` | Matching | 99.92% | 252 |
| `func_00136268` | Matching | 99.88% | 672 |
| `func_00136508` | Matching | 99.88% | 992 |
| `func_00135F70` | Matching | 99.76% | 340 |
| `func_00135CB0` | Matching | 99.76% | 252 |
| `func_00135DB0` | Matching | 99.76% | 252 |
| `func_00135BE0` | Matching | 99.71% | 208 |
| `func_00133128` | Matching | 99.71% | 476 |
| `func_001360C8` | Matching | 99.62% | 52 |
| `func_00135B30` | Matching | 99.53% | 172 |
| `func_00134CB0` | Matching | 99.51% | 284 |
| `func_00136168` | Matching | 99.44% | 144 |
| `func_00136AD0` | Matching | 99.40% | 368 |
| `func_00136100` | Matching | 99.40% | 100 |
| `func_00135180` | Matching | 99.38% | 292 |
| `func_00132F98` | Matching | 99.29% | 28 |

### `ai/airpredictor`

9 matching, 0 partial, 1 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAirPredictor_reset` | Matching | 100.00% | 104 |
| `cAirPredictor_startLaunchIntoAir` | Matching | 100.00% | 92 |
| `cAirPredictor_initLaunch(char *, sQuad *, sQuad *)` | Matching | 100.00% | 48 |
| `func_00113998(void*)` | Matching | 100.00% | 8 |
| `func_00113A98` | Matching | 100.00% | 8 |
| `func_00113AA0` | Matching | 100.00% | 52 |
| `func_00113AD8` | Matching | 100.00% | 52 |
| `func_00113648` | Matching | 99.81% | 844 |
| `func_001139A0` | Matching | 99.68% | 248 |

### `ai/computer`

73 matching, 0 partial, 5 not started (78 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cComputer_setIndividualRiderDifficulty` | Matching | 100.00% | 608 |
| `func_0010C9A8` | Matching | 100.00% | 268 |
| `func_0010CAD8` | Matching | 100.00% | 264 |
| `func_0010CBE0` | Matching | 100.00% | 316 |
| `func_0010CD20` | Matching | 100.00% | 584 |
| `func_0010CF68` | Matching | 100.00% | 516 |
| `func_0010D170` | Matching | 100.00% | 44 |
| `func_0010D8F8` | Matching | 100.00% | 60 |
| `func_0010D938` | Matching | 100.00% | 88 |
| `func_0010D990` | Matching | 100.00% | 88 |
| `func_0010D9E8` | Matching | 100.00% | 36 |
| `func_0010DEB0` | Matching | 100.00% | 64 |
| `func_0010E028` | Matching | 100.00% | 108 |
| `func_0010E098` | Matching | 100.00% | 396 |
| `func_0010E228` | Matching | 100.00% | 188 |
| `func_0010E2E8` | Matching | 100.00% | 188 |
| `func_0010E3A8` | Matching | 100.00% | 188 |
| `func_0010E468` | Matching | 100.00% | 240 |
| `func_0010E558` | Matching | 100.00% | 124 |
| `func_0010E5D8` | Matching | 100.00% | 408 |
| `func_0010E770` | Matching | 100.00% | 96 |
| `func_0010E7D0` | Matching | 100.00% | 96 |
| `func_0010E830` | Matching | 100.00% | 136 |
| `func_0010E8B8` | Matching | 100.00% | 88 |
| `func_0010E910` | Matching | 100.00% | 544 |
| `func_0010F1C0` | Matching | 100.00% | 192 |
| `func_0010F280` | Matching | 100.00% | 56 |
| `func_0010F2B8(void*)` | Matching | 100.00% | 28 |
| `func_0010F2D8` | Matching | 100.00% | 92 |
| `func_0010F338` | Matching | 100.00% | 92 |
| `func_0010F398(void*)` | Matching | 100.00% | 28 |
| `func_0010F878` | Matching | 100.00% | 288 |
| `func_0010FBF0` | Matching | 100.00% | 64 |
| `func_0010FC30` | Matching | 100.00% | 164 |
| `func_001112B8` | Matching | 100.00% | 64 |
| `func_001112F8` | Matching | 100.00% | 136 |
| `func_00111380` | Matching | 100.00% | 136 |
| `func_00111408` | Matching | 100.00% | 152 |
| `func_001114A0` | Matching | 100.00% | 152 |
| `func_00111538` | Matching | 100.00% | 64 |
| `func_00111578` | Matching | 100.00% | 184 |
| `func_00111630` | Matching | 100.00% | 248 |
| `func_00111728` | Matching | 100.00% | 264 |
| `func_00111830` | Matching | 100.00% | 48 |
| `func_00111860` | Matching | 100.00% | 48 |
| `func_00111890` | Matching | 100.00% | 184 |
| `func_00111948` | Matching | 100.00% | 172 |
| `func_001119F8` | Matching | 100.00% | 164 |
| `func_00111AA0(void*)` | Matching | 100.00% | 32 |
| `func_00111AC0` | Matching | 100.00% | 724 |
| `func_00111D98` | Matching | 100.00% | 996 |
| `func_00112180` | Matching | 100.00% | 436 |
| `func_00112338` | Matching | 100.00% | 592 |
| `func_00112588` | Matching | 100.00% | 32 |
| `func_001125A8` | Matching | 100.00% | 12 |
| `func_001125B8(void*)` | Matching | 100.00% | 8 |
| `func_00113128(void*)` | Matching | 100.00% | 8 |
| `func_00113130(void*)` | Matching | 100.00% | 8 |
| `func_00113138` | Matching | 100.00% | 52 |
| `func_00113170` | Matching | 100.00% | 36 |
| `func_00112A50` | Matching | 99.97% | 776 |
| `func_001127F0` | Matching | 99.97% | 604 |
| `func_00112D58` | Matching | 99.97% | 596 |
| `func_0010DA10` | Matching | 99.96% | 480 |
| `func_0010F3B8` | Matching | 99.95% | 420 |
| `func_0010D410` | Matching | 99.91% | 1116 |
| `func_001125C0` | Matching | 99.86% | 560 |
| `func_0010D870` | Matching | 99.85% | 136 |
| `func_0010F560` | Matching | 99.82% | 792 |
| `func_0010DEF0` | Matching | 99.81% | 312 |
| `func_0010DBF0` | Matching | 99.80% | 704 |
| `func_0010D1A0` | Matching | 99.78% | 624 |
| `func_0010CAB8` | Matching | 99.29% | 28 |

### `ai/control/handplantcontrol`

219 matching, 0 partial, 14 not started (233 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cHandplantMotion_gainFocus` | Matching | 100.00% | 84 |
| `func_00139178` | Matching | 100.00% | 48 |
| `func_00139528(void*)` | Matching | 100.00% | 32 |
| `func_00139970` | Matching | 100.00% | 52 |
| `func_001399A8` | Matching | 100.00% | 52 |
| `func_00139A18(void*)` | Matching | 100.00% | 8 |
| `func_0013ACB0` | Matching | 100.00% | 52 |
| `func_0013ACE8` | Matching | 100.00% | 52 |
| `func_0013C5E0` | Matching | 100.00% | 52 |
| `func_0013C618` | Matching | 100.00% | 52 |
| `func_0013C650` | Matching | 100.00% | 344 |
| `func_0013F848` | Matching | 100.00% | 52 |
| `func_0013F880` | Matching | 100.00% | 52 |
| `func_0013F8F8` | Matching | 100.00% | 476 |
| `func_0013FAD8` | Matching | 100.00% | 68 |
| `func_00140680` | Matching | 100.00% | 48 |
| `func_001406B0(void*)` | Matching | 100.00% | 12 |
| `func_001406C0(void*)` | Matching | 100.00% | 8 |
| `func_001406C8(void*)` | Matching | 100.00% | 8 |
| `func_001406D0(void*)` | Matching | 100.00% | 12 |
| `func_001406E0(void*)` | Matching | 100.00% | 12 |
| `func_001406F0(void*)` | Matching | 100.00% | 8 |
| `func_001406F8(void*)` | Matching | 100.00% | 8 |
| `func_00140700(void*)` | Matching | 100.00% | 8 |
| `func_00140708(void*)` | Matching | 100.00% | 8 |
| `func_00140710(void*)` | Matching | 100.00% | 8 |
| `func_00140718(void*)` | Matching | 100.00% | 8 |
| `func_00140720(void*)` | Matching | 100.00% | 8 |
| `func_00140728(void*)` | Matching | 100.00% | 8 |
| `func_00140730(void*)` | Matching | 100.00% | 8 |
| `func_00140738` | Matching | 100.00% | 300 |
| `func_00140868` | Matching | 100.00% | 8 |
| `func_00140870` | Matching | 100.00% | 8 |
| `func_00140878` | Matching | 100.00% | 8 |
| `func_00140880` | Matching | 100.00% | 8 |
| `func_00140888` | Matching | 100.00% | 8 |
| `func_00140890` | Matching | 100.00% | 8 |
| `func_00140898` | Matching | 100.00% | 8 |
| `func_001408A0` | Matching | 100.00% | 8 |
| `func_001408A8` | Matching | 100.00% | 8 |
| `func_001408B0` | Matching | 100.00% | 8 |
| `func_001408B8` | Matching | 100.00% | 8 |
| `func_001408C0` | Matching | 100.00% | 16 |
| `func_001408D0` | Matching | 100.00% | 16 |
| `func_001408E0` | Matching | 100.00% | 16 |
| `func_001408F0(void*)` | Matching | 100.00% | 8 |
| `func_001408F8` | Matching | 100.00% | 8 |
| `func_00140900` | Matching | 100.00% | 16 |
| `func_00140910(void*)` | Matching | 100.00% | 8 |
| `func_00140918` | Matching | 100.00% | 12 |
| `func_00140928` | Matching | 100.00% | 48 |
| `func_00140958` | Matching | 100.00% | 16 |
| `func_00140A28` | Matching | 100.00% | 8 |
| `func_00140A30` | Matching | 100.00% | 8 |
| `func_00140A38` | Matching | 100.00% | 8 |
| `func_00140A40` | Matching | 100.00% | 8 |
| `func_00140A48` | Matching | 100.00% | 8 |
| `func_00140A50` | Matching | 100.00% | 12 |
| `func_00140A60` | Matching | 100.00% | 16 |
| `func_00140A70` | Matching | 100.00% | 8 |
| `func_00140A78` | Matching | 100.00% | 8 |
| `func_00140A80` | Matching | 100.00% | 8 |
| `func_00140A88` | Matching | 100.00% | 8 |
| `func_00140A90` | Matching | 100.00% | 8 |
| `func_00140A98` | Matching | 100.00% | 8 |
| `func_00140AA0` | Matching | 100.00% | 8 |
| `func_00140AA8` | Matching | 100.00% | 8 |
| `func_00140AB0` | Matching | 100.00% | 8 |
| `func_00140AB8` | Matching | 100.00% | 8 |
| `func_00140AC0` | Matching | 100.00% | 16 |
| `func_00140AD0` | Matching | 100.00% | 32 |
| `func_00140AF0` | Matching | 100.00% | 36 |
| `func_00140B18` | Matching | 100.00% | 40 |
| `func_00140B40` | Matching | 100.00% | 8 |
| `func_00140B48` | Matching | 100.00% | 8 |
| `func_00140B50` | Matching | 100.00% | 8 |
| `func_00140B58` | Matching | 100.00% | 8 |
| `func_00140B60` | Matching | 100.00% | 8 |
| `func_00140B68` | Matching | 100.00% | 8 |
| `func_00140B70` | Matching | 100.00% | 8 |
| `func_00140B78` | Matching | 100.00% | 8 |
| `func_00140B80(void*)` | Matching | 100.00% | 8 |
| `func_00140B88` | Matching | 100.00% | 8 |
| `func_00140B90` | Matching | 100.00% | 8 |
| `func_00140B98` | Matching | 100.00% | 8 |
| `func_00140BA0` | Matching | 100.00% | 12 |
| `func_00140BB0` | Matching | 100.00% | 12 |
| `func_00140BC0(void*)` | Matching | 100.00% | 8 |
| `func_00140BC8` | Matching | 100.00% | 12 |
| `func_00140BD8` | Matching | 100.00% | 8 |
| `func_00140BE0` | Matching | 100.00% | 28 |
| `func_00140C00` | Matching | 100.00% | 8 |
| `func_00140C08` | Matching | 100.00% | 16 |
| `func_00140C18` | Matching | 100.00% | 8 |
| `func_00140C20` | Matching | 100.00% | 8 |
| `func_00140C28` | Matching | 100.00% | 8 |
| `func_00140C30` | Matching | 100.00% | 8 |
| `func_00140C38` | Matching | 100.00% | 8 |
| `func_00140C40` | Matching | 100.00% | 8 |
| `func_00140C48` | Matching | 100.00% | 8 |
| `func_00140C50` | Matching | 100.00% | 8 |
| `func_00140C58` | Matching | 100.00% | 8 |
| `func_00140C60` | Matching | 100.00% | 8 |
| `func_00140C68(void*)` | Matching | 100.00% | 8 |
| `func_00140C70(void*)` | Matching | 100.00% | 8 |
| `func_00140C78(void*)` | Matching | 100.00% | 8 |
| `func_00140C80(void*)` | Matching | 100.00% | 8 |
| `func_00140C88` | Matching | 100.00% | 8 |
| `func_00140C90` | Matching | 100.00% | 8 |
| `func_00140C98` | Matching | 100.00% | 8 |
| `func_00140CA0` | Matching | 100.00% | 8 |
| `func_00140CA8` | Matching | 100.00% | 40 |
| `func_00140CD0` | Matching | 100.00% | 8 |
| `func_00140CD8` | Matching | 100.00% | 8 |
| `func_00140CE0(void*)` | Matching | 100.00% | 8 |
| `func_00140CE8` | Matching | 100.00% | 8 |
| `func_00140CF0` | Matching | 100.00% | 28 |
| `func_00140D10` | Matching | 100.00% | 8 |
| `func_00140D18` | Matching | 100.00% | 8 |
| `func_00140D20` | Matching | 100.00% | 8 |
| `func_00140D28` | Matching | 100.00% | 8 |
| `func_00140D30` | Matching | 100.00% | 8 |
| `func_00140D38` | Matching | 100.00% | 8 |
| `func_00140D40` | Matching | 100.00% | 8 |
| `func_00140D48` | Matching | 100.00% | 8 |
| `func_00140D50` | Matching | 100.00% | 12 |
| `func_00140D60` | Matching | 100.00% | 16 |
| `func_00140D70` | Matching | 100.00% | 8 |
| `func_00140D78` | Matching | 100.00% | 8 |
| `func_001411A0` | Matching | 100.00% | 8 |
| `func_001411A8` | Matching | 100.00% | 8 |
| `func_001411B0` | Matching | 100.00% | 8 |
| `func_001411B8` | Matching | 100.00% | 8 |
| `func_00141480` | Matching | 100.00% | 328 |
| `func_00142388` | Matching | 100.00% | 328 |
| `func_00143FF0` | Matching | 100.00% | 8 |
| `func_00143FF8` | Matching | 100.00% | 8 |
| `func_00144000` | Matching | 100.00% | 8 |
| `func_00144008` | Matching | 100.00% | 8 |
| `func_00144010` | Matching | 100.00% | 44 |
| `func_00144040` | Matching | 100.00% | 40 |
| `func_00144068(void*)` | Matching | 100.00% | 8 |
| `func_00144070` | Matching | 100.00% | 8 |
| `func_00144078` | Matching | 100.00% | 8 |
| `func_00144080` | Matching | 100.00% | 8 |
| `func_00144088` | Matching | 100.00% | 8 |
| `func_00144090` | Matching | 100.00% | 8 |
| `func_00144098` | Matching | 100.00% | 8 |
| `func_001440A0` | Matching | 100.00% | 16 |
| `func_001440B0` | Matching | 100.00% | 16 |
| `func_001440C0` | Matching | 100.00% | 16 |
| `func_001440D0` | Matching | 100.00% | 16 |
| `func_001440E0` | Matching | 100.00% | 16 |
| `func_001440F0` | Matching | 100.00% | 8 |
| `func_001440F8` | Matching | 100.00% | 8 |
| `func_00144100` | Matching | 100.00% | 8 |
| `func_00144108` | Matching | 100.00% | 8 |
| `func_00144110` | Matching | 100.00% | 8 |
| `func_00144118` | Matching | 100.00% | 8 |
| `func_00144120` | Matching | 100.00% | 16 |
| `func_00144130` | Matching | 100.00% | 8 |
| `func_00144158` | Matching | 100.00% | 8 |
| `func_00144160` | Matching | 100.00% | 8 |
| `func_00144168` | Matching | 100.00% | 8 |
| `func_00144170` | Matching | 100.00% | 16 |
| `func_00144180` | Matching | 100.00% | 16 |
| `func_00144190` | Matching | 100.00% | 8 |
| `func_00144198` | Matching | 100.00% | 8 |
| `func_001441A0(void *, void *)` | Matching | 100.00% | 24 |
| `func_00144610(void*)` | Matching | 100.00% | 28 |
| `func_00144630` | Matching | 100.00% | 60 |
| `func_00144670` | Matching | 100.00% | 44 |
| `func_001446A0` | Matching | 100.00% | 24 |
| `func_001446B8` | Matching | 100.00% | 24 |
| `func_001446D0` | Matching | 100.00% | 12 |
| `func_001446E0` | Matching | 100.00% | 8 |
| `func_001446E8(void*)` | Matching | 100.00% | 12 |
| `func_001448A8` | Matching | 100.00% | 16 |
| `func_0013D1B8` | Matching | 99.99% | 1632 |
| `func_00144368` | Matching | 99.97% | 680 |
| `func_0013F178` | Matching | 99.97% | 664 |
| `func_0013BFA8` | Matching | 99.95% | 404 |
| `func_0013A7B0` | Matching | 99.94% | 328 |
| `func_0013F488` | Matching | 99.92% | 960 |
| `func_001441B8` | Matching | 99.91% | 428 |
| `func_0013C878` | Matching | 99.90% | 208 |
| `func_0013D028` | Matching | 99.90% | 400 |
| `func_0013AD20` | Matching | 99.88% | 160 |
| `func_0013A8F8` | Matching | 99.82% | 112 |
| `func_00139A20` | Matching | 99.81% | 616 |
| `func_0013CCF0` | Matching | 99.73% | 820 |
| `func_0013A968` | Matching | 99.73% | 220 |
| `func_0013C7A8` | Matching | 99.71% | 208 |
| `func_0013C5A0` | Matching | 99.67% | 60 |
| `func_0013F410` | Matching | 99.67% | 120 |
| `func_001399E0` | Matching | 99.64% | 56 |
| `func_00140968` | Matching | 99.57% | 188 |
| `func_00140D80` | Matching | 99.43% | 348 |
| `func_00140EE0` | Matching | 99.43% | 348 |
| `func_00141040` | Matching | 99.43% | 348 |
| `func_001411C0` | Matching | 99.43% | 348 |
| `func_00141320` | Matching | 99.43% | 348 |
| `func_001415C8` | Matching | 99.43% | 348 |
| `func_00141728` | Matching | 99.43% | 348 |
| `func_00141888` | Matching | 99.43% | 348 |
| `func_001419E8` | Matching | 99.43% | 348 |
| `func_00141B48` | Matching | 99.43% | 348 |
| `func_00141CA8` | Matching | 99.43% | 348 |
| `func_00141E08` | Matching | 99.43% | 348 |
| `func_00141F68` | Matching | 99.43% | 348 |
| `func_001420C8` | Matching | 99.43% | 348 |
| `func_00142228` | Matching | 99.43% | 348 |
| `func_001424D0` | Matching | 99.43% | 348 |
| `func_00142630` | Matching | 99.43% | 348 |
| `func_00142790` | Matching | 99.43% | 348 |
| `func_001428F0` | Matching | 99.43% | 348 |
| `func_001446F8` | Matching | 99.40% | 432 |
| `func_00144138` | Matching | 99.38% | 32 |
| `func_001448B8(void*)` | Matching | 99.38% | 32 |

### `ai/motion/wipeoutmotion`

13 matching, 0 partial, 3 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWipeoutMotion_gainFocus` | Matching | 100.00% | 252 |
| `func_00136D40` | Matching | 100.00% | 156 |
| `func_00136DE0` | Matching | 100.00% | 184 |
| `func_00136E98` | Matching | 100.00% | 72 |
| `func_00136EE0` | Matching | 100.00% | 72 |
| `func_00136F28(void*)` | Matching | 100.00% | 8 |
| `func_00136F30` | Matching | 100.00% | 516 |
| `func_00137550` | Matching | 100.00% | 508 |
| `func_00138AD8` | Matching | 100.00% | 52 |
| `func_00138B10` | Matching | 100.00% | 52 |
| `func_00138960` | Matching | 99.95% | 372 |
| `func_00137860` | Matching | 99.93% | 1204 |
| `func_00137750` | Matching | 99.71% | 272 |

### `ai/rider`

104 matching, 0 partial, 11 not started (115 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_0011B978` | Matching | 100.00% | 452 |
| `cRider_addFocusBox` | Matching | 100.00% | 84 |
| `cRider_addRiderMetrix(cRider*)` | Matching | 100.00% | 80 |
| `func_0011BBE8` | Matching | 100.00% | 372 |
| `func_0011BD60` | Matching | 100.00% | 296 |
| `func_0011BE88` | Matching | 100.00% | 596 |
| `func_0011C0E0` | Matching | 100.00% | 84 |
| `func_0011C138` | Matching | 100.00% | 244 |
| `cRider_initOnce` | Matching | 100.00% | 104 |
| `func_0011D390` | Matching | 100.00% | 688 |
| `func_0011D640` | Matching | 100.00% | 32 |
| `func_0011DFE0` | Matching | 100.00% | 184 |
| `cRider_updateOrientationImplicit` | Matching | 100.00% | 184 |
| `func_0011EB60` | Matching | 100.00% | 52 |
| `func_0011FE78(void*)` | Matching | 100.00% | 28 |
| `func_0011FE98(void*)` | Matching | 100.00% | 12 |
| `func_0011FEA8` | Matching | 100.00% | 28 |
| `func_0011FEC8(void*)` | Matching | 100.00% | 28 |
| `func_0011FEE8(void*)` | Matching | 100.00% | 12 |
| `func_0011FEF8` | Matching | 100.00% | 28 |
| `func_0011FF18` | Matching | 100.00% | 44 |
| `func_0011FF48` | Matching | 100.00% | 36 |
| `func_0011FF70` | Matching | 100.00% | 36 |
| `func_00120D58` | Matching | 100.00% | 56 |
| `func_00120E30` | Matching | 100.00% | 28 |
| `func_00120E50` | Matching | 100.00% | 52 |
| `func_00120E88` | Matching | 100.00% | 48 |
| `func_00120EB8` | Matching | 100.00% | 28 |
| `func_00120ED8` | Matching | 100.00% | 72 |
| `func_00121068` | Matching | 100.00% | 72 |
| `func_001211F8` | Matching | 100.00% | 1252 |
| `func_001216E0(void*)` | Matching | 100.00% | 28 |
| `func_00121700` | Matching | 100.00% | 40 |
| `func_00121728` | Matching | 100.00% | 40 |
| `func_00121750` | Matching | 100.00% | 164 |
| `func_001217F8(void*)` | Matching | 100.00% | 28 |
| `func_00121818` | Matching | 100.00% | 180 |
| `func_00122048` | Matching | 100.00% | 64 |
| `func_00122088` | Matching | 100.00% | 76 |
| `func_001220D8` | Matching | 100.00% | 412 |
| `func_00122278` | Matching | 100.00% | 464 |
| `func_00122448` | Matching | 100.00% | 376 |
| `func_001225C0` | Matching | 100.00% | 44 |
| `func_001225F0` | Matching | 100.00% | 40 |
| `func_00122618` | Matching | 100.00% | 28 |
| `func_00122638(void*)` | Matching | 100.00% | 28 |
| `func_00122658` | Matching | 100.00% | 36 |
| `func_00122680` | Matching | 100.00% | 532 |
| `func_00122C28` | Matching | 100.00% | 96 |
| `func_00122CD0(void*)` | Matching | 100.00% | 28 |
| `func_00122CF0` | Matching | 100.00% | 132 |
| `func_00122D78` | Matching | 100.00% | 216 |
| `func_00122E50` | Matching | 100.00% | 148 |
| `func_00122EE8` | Matching | 100.00% | 572 |
| `func_00123128` | Matching | 100.00% | 60 |
| `func_00123168` | Matching | 100.00% | 60 |
| `func_001231A8` | Matching | 100.00% | 100 |
| `func_001235F8` | Matching | 100.00% | 72 |
| `func_00123B48` | Matching | 100.00% | 608 |
| `func_00123DA8` | Matching | 100.00% | 136 |
| `func_00123E30` | Matching | 100.00% | 264 |
| `func_001241C0` | Matching | 100.00% | 240 |
| `func_00125038` | Matching | 100.00% | 112 |
| `func_00125108` | Matching | 100.00% | 284 |
| `cRider_quitEvent` | Matching | 100.00% | 116 |
| `func_00125448` | Matching | 100.00% | 1292 |
| `func_00125958` | Matching | 100.00% | 24 |
| `func_00125AD0(void*)` | Matching | 100.00% | 8 |
| `func_00125AD8` | Matching | 100.00% | 64 |
| `func_001276F0` | Matching | 100.00% | 340 |
| `func_00127848` | Matching | 100.00% | 120 |
| `func_001278C0(void*)` | Matching | 100.00% | 12 |
| `func_001278D0` | Matching | 100.00% | 16 |
| `func_001278E0(void*, float)` | Matching | 100.00% | 8 |
| `func_001278E8` | Matching | 100.00% | 176 |
| `func_00127998` | Matching | 100.00% | 3268 |
| `func_00128660(void*)` | Matching | 100.00% | 28 |
| `func_00128680(void*)` | Matching | 100.00% | 28 |
| `func_00123640` | Matching | 99.97% | 1288 |
| `func_00120378` | Matching | 99.97% | 2528 |
| `func_00125C70` | Matching | 99.97% | 584 |
| `func_00122898` | Matching | 99.96% | 912 |
| `func_00125228` | Matching | 99.95% | 420 |
| `func_001242B0` | Matching | 99.95% | 1240 |
| `func_00120F20` | Matching | 99.94% | 328 |
| `func_001234D0` | Matching | 99.93% | 296 |
| `func_00121F30` | Matching | 99.93% | 276 |
| `func_00123F38` | Matching | 99.91% | 644 |
| `func_0011DF18` | Matching | 99.90% | 200 |
| `func_0011DE60` | Matching | 99.89% | 180 |
| `cRider_getMass` | Matching | 99.88% | 160 |
| `func_001200D0` | Matching | 99.85% | 680 |
| `func_001218D0` | Matching | 99.84% | 128 |
| `func_001210B0` | Matching | 99.81% | 324 |
| `func_0011DD98` | Matching | 99.80% | 196 |
| `func_001250A8` | Matching | 99.79% | 96 |
| `func_00120038` | Matching | 99.76% | 84 |
| `func_00120090` | Matching | 99.67% | 60 |
| `func_00125970` | Matching | 99.66% | 352 |
| `func_00122C98` | Matching | 99.62% | 52 |
| `func_00125B18` | Matching | 99.59% | 340 |
| `func_00121950` | Matching | 99.46% | 332 |
| `func_00120D90` | Matching | 99.36% | 156 |
| `func_00122C88` | Matching | 98.33% | 12 |

### `ai/ridermetrix`

65 matching, 0 partial, 3 not started (68 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cRiderMetrix_linkToRider` | Matching | 100.00% | 212 |
| `func_001173B8` | Matching | 100.00% | 72 |
| `func_00117400` | Matching | 100.00% | 172 |
| `func_001174B0` | Matching | 100.00% | 52 |
| `func_001174E8` | Matching | 100.00% | 52 |
| `func_00117520` | Matching | 100.00% | 28 |
| `func_00117540` | Matching | 100.00% | 120 |
| `func_001175B8` | Matching | 100.00% | 64 |
| `func_001175F8` | Matching | 100.00% | 60 |
| `func_00117638` | Matching | 100.00% | 188 |
| `func_001176F8` | Matching | 100.00% | 16 |
| `func_00117708` | Matching | 100.00% | 16 |
| `func_00117718` | Matching | 100.00% | 288 |
| `func_00117838` | Matching | 100.00% | 200 |
| `func_00117900(void*)` | Matching | 100.00% | 8 |
| `func_00117908` | Matching | 100.00% | 60 |
| `func_00117948` | Matching | 100.00% | 68 |
| `func_00117990` | Matching | 100.00% | 76 |
| `func_001179E0` | Matching | 100.00% | 120 |
| `func_00117A58` | Matching | 100.00% | 140 |
| `func_00117AE8` | Matching | 100.00% | 156 |
| `func_00117B88` | Matching | 100.00% | 156 |
| `func_00117C28` | Matching | 100.00% | 948 |
| `func_00118FF8` | Matching | 100.00% | 108 |
| `func_00119068` | Matching | 100.00% | 132 |
| `func_001190F0` | Matching | 100.00% | 284 |
| `func_00119210` | Matching | 100.00% | 252 |
| `func_00119310` | Matching | 100.00% | 84 |
| `func_001193E0` | Matching | 100.00% | 32 |
| `func_00119400` | Matching | 100.00% | 68 |
| `func_00119448` | Matching | 100.00% | 116 |
| `func_001194C0` | Matching | 100.00% | 228 |
| `func_001195A8` | Matching | 100.00% | 48 |
| `func_001195D8` | Matching | 100.00% | 48 |
| `func_001197D8` | Matching | 100.00% | 188 |
| `func_00119918(void*, int)` | Matching | 100.00% | 28 |
| `func_00119938(void*, int, int)` | Matching | 100.00% | 32 |
| `func_00119958` | Matching | 100.00% | 156 |
| `func_001199F8` | Matching | 100.00% | 64 |
| `func_00119A38` | Matching | 100.00% | 156 |
| `func_00119B08` | Matching | 100.00% | 168 |
| `func_00119C38` | Matching | 100.00% | 96 |
| `func_00119C98` | Matching | 100.00% | 164 |
| `func_00119E38` | Matching | 100.00% | 188 |
| `cRiderMetrix_evAutoResetSurface(void*)` | Matching | 100.00% | 52 |
| `func_0011A0C0(void*)` | Matching | 100.00% | 12 |
| `func_0011A0D0` | Matching | 100.00% | 12 |
| `func_0011A0E0` | Matching | 100.00% | 48 |
| `func_0011A110` | Matching | 100.00% | 88 |
| `func_0011A7A8` | Matching | 100.00% | 284 |
| `func_0011B1A8` | Matching | 100.00% | 280 |
| `func_0011B2C0` | Matching | 100.00% | 312 |
| `func_0011B678(void*)` | Matching | 100.00% | 28 |
| `func_00119EF8` | Matching | 99.95% | 400 |
| `func_0011A228` | Matching | 99.94% | 1404 |
| `func_00119608` | Matching | 99.92% | 252 |
| `func_00119D40` | Matching | 99.92% | 248 |
| `func_0011A168` | Matching | 99.89% | 188 |
| `func_00119708` | Matching | 99.81% | 208 |
| `func_00119BF0` | Matching | 99.71% | 68 |
| `func_00119BB0` | Matching | 99.69% | 64 |
| `func_00119368` | Matching | 99.67% | 120 |
| `func_00119898` | Matching | 99.67% | 60 |
| `func_001198D8` | Matching | 99.67% | 60 |
| `func_00119AD8` | Matching | 99.55% | 44 |

### `animation/animmodel`

30 matching, 0 partial, 4 not started (34 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAnimModel_addModelPartLOD` | Matching | 100.00% | 692 |
| `func_0030DB70(void*, int)` | Matching | 100.00% | 28 |
| `func_0030DB90` | Matching | 100.00% | 16 |
| `func_0030DBA0` | Matching | 100.00% | 44 |
| `func_0030E9E0` | Matching | 100.00% | 156 |
| `func_0030EA80` | Matching | 100.00% | 220 |
| `func_0030EB60` | Matching | 100.00% | 92 |
| `func_0030EBC0` | Matching | 100.00% | 84 |
| `func_0030EC18` | Matching | 100.00% | 132 |
| `func_0030ECA0` | Matching | 100.00% | 52 |
| `func_00310120` | Matching | 100.00% | 220 |
| `func_00310200` | Matching | 100.00% | 492 |
| `func_003103F0` | Matching | 100.00% | 100 |
| `func_00310458` | Matching | 100.00% | 216 |
| `func_00310530` | Matching | 100.00% | 272 |
| `func_00310640` | Matching | 100.00% | 776 |
| `func_00310948` | Matching | 100.00% | 768 |
| `func_00310C48` | Matching | 100.00% | 160 |
| `func_00310CE8` | Matching | 100.00% | 448 |
| `func_00310EA8` | Matching | 100.00% | 56 |
| `func_00310EE0` | Matching | 100.00% | 56 |
| `func_00310F18` | Matching | 100.00% | 300 |
| `func_00311048` | Matching | 100.00% | 60 |
| `func_00311088` | Matching | 100.00% | 72 |
| `func_003110D0` | Matching | 100.00% | 60 |
| `func_00311110` | Matching | 100.00% | 272 |
| `func_00311220` | Matching | 100.00% | 44 |
| `func_00311250` | Matching | 100.00% | 64 |
| `func_00311290` | Matching | 100.00% | 52 |
| `func_003112C8` | Matching | 100.00% | 80 |

### `animation/animsequencer`

44 matching, 0 partial, 0 not started (44 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAnimSequence_fadeWeight(cAnimSequence*, float, float)` | Matching | 100.00% | 16 |
| `func_00313A20` | Matching | 100.00% | 80 |
| `func_00313A70` | Matching | 100.00% | 104 |
| `func_00313AD8` | Matching | 100.00% | 96 |
| `func_00313B38` | Matching | 100.00% | 112 |
| `func_00313BA8` | Matching | 100.00% | 92 |
| `func_00313C08` | Matching | 100.00% | 72 |
| `func_00313C50` | Matching | 100.00% | 160 |
| `func_00313CF0` | Matching | 100.00% | 28 |
| `func_00313D10` | Matching | 100.00% | 20 |
| `func_00313D28` | Matching | 100.00% | 20 |
| `func_00313D40` | Matching | 100.00% | 20 |
| `func_00313D58` | Matching | 100.00% | 20 |
| `func_00313D70` | Matching | 100.00% | 96 |
| `func_00313DD0` | Matching | 100.00% | 636 |
| `func_00314050` | Matching | 100.00% | 660 |
| `func_003142E8(void*)` | Matching | 100.00% | 12 |
| `func_003142F8` | Matching | 100.00% | 108 |
| `func_00314368` | Matching | 100.00% | 92 |
| `func_003143C8` | Matching | 100.00% | 76 |
| `func_00314418` | Matching | 100.00% | 252 |
| `func_00314518` | Matching | 100.00% | 112 |
| `func_00314588` | Matching | 100.00% | 112 |
| `func_003145F8` | Matching | 100.00% | 112 |
| `func_00314668` | Matching | 100.00% | 104 |
| `func_003146D0` | Matching | 100.00% | 72 |
| `func_00314718` | Matching | 100.00% | 72 |
| `cAnimSequencer_getSequence(cAnimSequencer*, int)` | Matching | 100.00% | 36 |
| `func_00314788` | Matching | 100.00% | 48 |
| `func_003147B8` | Matching | 100.00% | 52 |
| `func_003147F0` | Matching | 100.00% | 140 |
| `func_00314880` | Matching | 100.00% | 244 |
| `func_00314978(void*)` | Matching | 100.00% | 12 |
| `func_00314988` | Matching | 100.00% | 68 |
| `func_003149D0` | Matching | 100.00% | 68 |
| `func_00314A18(void*, int)` | Matching | 100.00% | 36 |
| `func_00314A40(void*)` | Matching | 100.00% | 32 |
| `func_00314A60` | Matching | 100.00% | 60 |
| `func_00314AA0` | Matching | 100.00% | 32 |
| `func_00314AC0` | Matching | 100.00% | 28 |
| `func_00314AE0` | Matching | 100.00% | 140 |
| `func_00314B70` | Matching | 100.00% | 144 |
| `func_00314C00` | Matching | 100.00% | 152 |
| `func_00314C98` | Matching | 100.00% | 20 |

### `animation/gameanimmap`

17 matching, 0 partial, 1 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGameAnimMap_testResolve()` | Matching | 100.00% | 8 |
| `func_003150B8` | Matching | 100.00% | 60 |
| `func_003158B8` | Matching | 100.00% | 8 |
| `func_003158C0` | Matching | 100.00% | 8 |
| `func_003158C8` | Matching | 100.00% | 8 |
| `func_003158D0` | Matching | 100.00% | 8 |
| `func_003158D8` | Matching | 100.00% | 8 |
| `func_003158E0` | Matching | 100.00% | 8 |
| `func_003158E8` | Matching | 100.00% | 156 |
| `func_00315988` | Matching | 100.00% | 20 |
| `func_003159A0` | Matching | 100.00% | 8 |
| `func_003159A8` | Matching | 100.00% | 12 |
| `func_003159B8` | Matching | 100.00% | 44 |
| `func_003159E8` | Matching | 100.00% | 24 |
| `func_00315A00(void*)` | Matching | 100.00% | 32 |
| `func_003150F8` | Matching | 99.97% | 1984 |
| `func_00316878(void*)` | Matching | 99.38% | 32 |

### `animation/mdfarchive`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cMdfArchive_getModelPartByIndex` | Matching | 100.00% | 176 |
| `func_00314D60` | Matching | 100.00% | 56 |
| `func_00314D98` | Matching | 100.00% | 20 |
| `func_00314DB0` | Matching | 100.00% | 40 |
| `func_00314DD8` | Matching | 100.00% | 172 |
| `func_00314E88` | Matching | 100.00% | 100 |
| `func_00314EF0` | Matching | 100.00% | 64 |
| `func_00314F30` | Matching | 100.00% | 184 |
| `func_00314FE8` | Matching | 100.00% | 132 |
| `func_00315070` | Matching | 100.00% | 64 |

### `animation/rideranimbase`

34 matching, 0 partial, 1 not started (35 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cRiderAnimBase_cRiderAnimBase` | Matching | 100.00% | 132 |
| `func_00311958` | Matching | 100.00% | 140 |
| `func_003119E8` | Matching | 100.00% | 16 |
| `func_003119F8` | Matching | 100.00% | 52 |
| `func_00311A30` | Matching | 100.00% | 28 |
| `func_00311A50` | Matching | 100.00% | 152 |
| `func_00311AE8` | Matching | 100.00% | 56 |
| `func_00311B20` | Matching | 100.00% | 40 |
| `cRiderAnimBase_changeHeadingOffset` | Matching | 100.00% | 168 |
| `cRiderAnimBase_changeOrientationOffset` | Matching | 100.00% | 408 |
| `func_00311D88` | Matching | 100.00% | 172 |
| `func_00311E38` | Matching | 100.00% | 76 |
| `func_00311E88` | Matching | 100.00% | 116 |
| `func_003123C0` | Matching | 100.00% | 204 |
| `func_00312490` | Matching | 100.00% | 260 |
| `func_00312598` | Matching | 100.00% | 196 |
| `func_00312AA0(void*, int)` | Matching | 100.00% | 16 |
| `func_00312AB0` | Matching | 100.00% | 52 |
| `func_00312AE8` | Matching | 100.00% | 44 |
| `func_00312B18` | Matching | 100.00% | 184 |
| `func_00312BD0` | Matching | 100.00% | 80 |
| `func_003130A8` | Matching | 100.00% | 1120 |
| `func_00313508` | Matching | 100.00% | 164 |
| `func_003135B0` | Matching | 100.00% | 592 |
| `func_00313800` | Matching | 100.00% | 104 |
| `func_00313868` | Matching | 100.00% | 204 |
| `func_00313938` | Matching | 100.00% | 112 |
| `func_003139A8` | Matching | 100.00% | 100 |
| `func_00312C20` | Matching | 99.98% | 1156 |
| `func_00312660` | Matching | 99.93% | 300 |
| `cRiderAnimBase_play` | Matching | 99.92% | 244 |
| `func_00312820` | Matching | 99.90% | 200 |
| `func_003129E0` | Matching | 99.89% | 188 |
| `func_00312790` | Matching | 99.86% | 140 |

### `be/be`

12 matching, 0 partial, 0 not started (12 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBE_getBE` | Matching | 100.00% | 200 |
| `func_0014DD48` | Matching | 100.00% | 12 |
| `cBE_getInterface()` | Matching | 100.00% | 64 |
| `func_0014DD98` | Matching | 100.00% | 140 |
| `func_0014DE28` | Matching | 100.00% | 60 |
| `cBE_setState` | Matching | 100.00% | 124 |
| `func_0014DEE8` | Matching | 100.00% | 32 |
| `func_0014DF08` | Matching | 100.00% | 156 |
| `cBE_readFromReplayFrame` | Matching | 100.00% | 156 |
| `func_0014E048` | Matching | 100.00% | 8 |
| `func_0014E050` | Matching | 100.00% | 112 |
| `func_0014E0C0(void*, int)` | Matching | 100.00% | 28 |

### `be/bedbprofile`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBECharProfileDB_getScoreStats(void*, int, int)` | Matching | 100.00% | 76 |
| `func_001523E8` | Matching | 100.00% | 68 |
| `func_00152430` | Matching | 100.00% | 48 |
| `func_00152460` | Matching | 100.00% | 200 |
| `func_00152528` | Matching | 100.00% | 268 |

### `be/bedbreward`

135 matching, 0 partial, 1 not started (136 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBERewardDB_init` | Matching | 100.00% | 168 |
| `func_0015AE00` | Matching | 100.00% | 188 |
| `func_0015AEC0` | Matching | 100.00% | 128 |
| `func_0015AF40` | Matching | 100.00% | 168 |
| `func_0015AFE8` | Matching | 100.00% | 60 |
| `func_0015BB00(void*)` | Matching | 100.00% | 8 |
| `func_0015BB08(void*)` | Matching | 100.00% | 8 |
| `func_0015BB10(void*)` | Matching | 100.00% | 8 |
| `func_0015BB18(void*)` | Matching | 100.00% | 8 |
| `func_0015BB20` | Matching | 100.00% | 36 |
| `func_0015BB48` | Matching | 100.00% | 12 |
| `func_0015BB58` | Matching | 100.00% | 12 |
| `func_0015BB68` | Matching | 100.00% | 12 |
| `func_0015BB78` | Matching | 100.00% | 12 |
| `func_0015BB88` | Matching | 100.00% | 12 |
| `func_0015BB98` | Matching | 100.00% | 12 |
| `func_0015BBA8` | Matching | 100.00% | 12 |
| `func_0015BBB8` | Matching | 100.00% | 12 |
| `func_0015BBC8` | Matching | 100.00% | 12 |
| `func_0015BBD8` | Matching | 100.00% | 20 |
| `func_0015BBF0` | Matching | 100.00% | 8 |
| `func_0015BBF8` | Matching | 100.00% | 8 |
| `func_0015BC00` | Matching | 100.00% | 8 |
| `func_0015BC08` | Matching | 100.00% | 8 |
| `func_0015BC10` | Matching | 100.00% | 32 |
| `func_0015BC30` | Matching | 100.00% | 44 |
| `func_0015BC60` | Matching | 100.00% | 12 |
| `func_0015BC70` | Matching | 100.00% | 20 |
| `func_0015BC88` | Matching | 100.00% | 36 |
| `func_0015BCB0` | Matching | 100.00% | 12 |
| `func_0015BCC0(void*)` | Matching | 100.00% | 8 |
| `func_0015BCC8(void*)` | Matching | 100.00% | 8 |
| `func_0015BCD0` | Matching | 100.00% | 36 |
| `func_0015BCF8` | Matching | 100.00% | 8 |
| `func_0015BD00` | Matching | 100.00% | 8 |
| `func_0015BD08` | Matching | 100.00% | 12 |
| `func_0015BD18` | Matching | 100.00% | 20 |
| `func_0015BD30` | Matching | 100.00% | 36 |
| `func_0015BD58` | Matching | 100.00% | 184 |
| `func_0015BE10` | Matching | 100.00% | 172 |
| `func_0015BEC0` | Matching | 100.00% | 40 |
| `func_0015BEE8` | Matching | 100.00% | 40 |
| `func_0015BF10` | Matching | 100.00% | 40 |
| `func_0015BF38` | Matching | 100.00% | 40 |
| `func_0015BF60` | Matching | 100.00% | 40 |
| `func_0015BF88` | Matching | 100.00% | 8 |
| `func_0015BF90` | Matching | 100.00% | 20 |
| `func_0015BFA8` | Matching | 100.00% | 36 |
| `func_0015BFD0` | Matching | 100.00% | 40 |
| `func_0015BFF8` | Matching | 100.00% | 32 |
| `func_0015C018` | Matching | 100.00% | 36 |
| `func_0015C040` | Matching | 100.00% | 36 |
| `func_0015C068` | Matching | 100.00% | 40 |
| `func_0015C090` | Matching | 100.00% | 40 |
| `func_0015C0B8` | Matching | 100.00% | 40 |
| `func_0015C0E0` | Matching | 100.00% | 20 |
| `func_0015C0F8` | Matching | 100.00% | 20 |
| `func_0015C110` | Matching | 100.00% | 16 |
| `func_0015C120` | Matching | 100.00% | 16 |
| `func_0015C130` | Matching | 100.00% | 20 |
| `func_0015C148` | Matching | 100.00% | 16 |
| `func_0015C158` | Matching | 100.00% | 20 |
| `func_0015C170` | Matching | 100.00% | 20 |
| `func_0015C188` | Matching | 100.00% | 44 |
| `func_0015C1B8` | Matching | 100.00% | 36 |
| `func_0015C1E0` | Matching | 100.00% | 12 |
| `func_0015C1F0` | Matching | 100.00% | 12 |
| `func_0015C200` | Matching | 100.00% | 12 |
| `func_0015C210` | Matching | 100.00% | 20 |
| `func_0015C228` | Matching | 100.00% | 40 |
| `func_0015C250` | Matching | 100.00% | 36 |
| `func_0015C278` | Matching | 100.00% | 12 |
| `func_0015C288` | Matching | 100.00% | 12 |
| `func_0015C298` | Matching | 100.00% | 12 |
| `func_0015C2A8` | Matching | 100.00% | 12 |
| `func_0015C2B8` | Matching | 100.00% | 12 |
| `func_0015C2C8` | Matching | 100.00% | 12 |
| `func_0015C2D8` | Matching | 100.00% | 12 |
| `func_0015C2E8` | Matching | 100.00% | 12 |
| `func_0015C2F8` | Matching | 100.00% | 12 |
| `func_0015C308` | Matching | 100.00% | 12 |
| `func_0015C318` | Matching | 100.00% | 12 |
| `func_0015C328` | Matching | 100.00% | 12 |
| `func_0015C338` | Matching | 100.00% | 32 |
| `func_0015C358` | Matching | 100.00% | 12 |
| `func_0015C368` | Matching | 100.00% | 32 |
| `func_0015C388` | Matching | 100.00% | 12 |
| `func_0015C398` | Matching | 100.00% | 32 |
| `func_0015C3B8` | Matching | 100.00% | 12 |
| `func_0015C3C8` | Matching | 100.00% | 12 |
| `func_0015C3D8` | Matching | 100.00% | 12 |
| `func_0015C3E8` | Matching | 100.00% | 12 |
| `func_0015C3F8` | Matching | 100.00% | 12 |
| `func_0015C408` | Matching | 100.00% | 12 |
| `func_0015C418` | Matching | 100.00% | 180 |
| `func_0015C4D0` | Matching | 100.00% | 12 |
| `func_0015C4E0` | Matching | 100.00% | 180 |
| `func_0015C598` | Matching | 100.00% | 12 |
| `func_0015C5A8` | Matching | 100.00% | 12 |
| `func_0015C5B8` | Matching | 100.00% | 12 |
| `func_0015C5C8` | Matching | 100.00% | 56 |
| `func_0015C600` | Matching | 100.00% | 12 |
| `func_0015C610` | Matching | 100.00% | 8 |
| `func_0015C618` | Matching | 100.00% | 72 |
| `func_0015C660` | Matching | 100.00% | 20 |
| `func_0015C678` | Matching | 100.00% | 36 |
| `func_0015C6A0` | Matching | 100.00% | 12 |
| `func_0015C6B0` | Matching | 100.00% | 20 |
| `func_0015C6C8(void*)` | Matching | 100.00% | 8 |
| `func_0015C6D0(void*)` | Matching | 100.00% | 8 |
| `func_0015C6D8(void*)` | Matching | 100.00% | 8 |
| `func_0015C6E0(void*)` | Matching | 100.00% | 8 |
| `func_0015C6E8` | Matching | 100.00% | 36 |
| `func_0015C710` | Matching | 100.00% | 12 |
| `func_0015C720` | Matching | 100.00% | 20 |
| `func_0015C738` | Matching | 100.00% | 36 |
| `func_0015C760` | Matching | 100.00% | 36 |
| `func_0015C788` | Matching | 100.00% | 36 |
| `func_0015C7B0` | Matching | 100.00% | 16 |
| `func_0015C7C0` | Matching | 100.00% | 12 |
| `func_0015C7D0(void*)` | Matching | 100.00% | 8 |
| `func_0015C7D8(void*)` | Matching | 100.00% | 8 |
| `func_0015C7E0` | Matching | 100.00% | 36 |
| `func_0015C808` | Matching | 100.00% | 12 |
| `func_0015C818` | Matching | 100.00% | 20 |
| `func_0015C830` | Matching | 100.00% | 36 |
| `func_0015C858` | Matching | 100.00% | 20 |
| `func_0015C870` | Matching | 100.00% | 36 |
| `func_0015C898` | Matching | 100.00% | 20 |
| `func_0015C8B0` | Matching | 100.00% | 36 |
| `func_0015C8D8` | Matching | 100.00% | 20 |
| `func_0015C930(void*)` | Matching | 100.00% | 16 |
| `func_0015C940` | Matching | 100.00% | 68 |
| `func_0015C8F0(void*)` | Matching | 99.38% | 32 |
| `func_0015C910(void*)` | Matching | 99.38% | 32 |

### `be/beintaggression`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEAggressionInterface_getThis()` | Matching | 100.00% | 76 |
| `func_00155AA0(void*)` | Matching | 100.00% | 8 |
| `func_00155AA8(void*)` | Matching | 100.00% | 8 |
| `func_00155AB0` | Matching | 100.00% | 160 |
| `func_00155B50` | Matching | 100.00% | 160 |
| `func_00155BF0` | Matching | 100.00% | 612 |
| `func_001560A0` | Matching | 100.00% | 272 |
| `func_001561B0` | Matching | 100.00% | 264 |
| `func_001562B8` | Matching | 100.00% | 124 |
| `func_00155E58` | Matching | 99.55% | 580 |

### `be/beintbagt`

21 matching, 0 partial, 1 not started (22 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEBAGTInterface_getThis()` | Matching | 100.00% | 96 |
| `func_0014F960` | Matching | 100.00% | 364 |
| `func_0014FAD0` | Matching | 100.00% | 364 |
| `func_0014FC40` | Matching | 100.00% | 316 |
| `func_0014FD80` | Matching | 100.00% | 136 |
| `func_0014FE08` | Matching | 100.00% | 160 |
| `func_0014FEA8` | Matching | 100.00% | 228 |
| `func_0014FF90` | Matching | 100.00% | 40 |
| `func_0014FFB8` | Matching | 100.00% | 140 |
| `func_00150048` | Matching | 100.00% | 140 |
| `func_001500D8` | Matching | 100.00% | 28 |
| `func_001500F8` | Matching | 100.00% | 28 |
| `func_00150118` | Matching | 100.00% | 28 |
| `func_00150138` | Matching | 100.00% | 28 |
| `func_00150158` | Matching | 100.00% | 28 |
| `func_00150178` | Matching | 100.00% | 28 |
| `func_00150198` | Matching | 100.00% | 300 |
| `func_001502C8` | Matching | 100.00% | 300 |
| `func_001503F8` | Matching | 100.00% | 300 |
| `func_00150528(void*, int)` | Matching | 100.00% | 24 |
| `func_00150540(void*, int)` | Matching | 100.00% | 24 |

### `be/beintcharacter`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBECharacterInterface_getWeight(void*, int)` | Matching | 100.00% | 60 |
| `func_0014EF70` | Matching | 100.00% | 56 |
| `func_0014EFA8` | Matching | 100.00% | 344 |
| `func_0014F100` | Matching | 100.00% | 8 |
| `func_0014F138` | Matching | 100.00% | 56 |
| `func_0014F170` | Matching | 100.00% | 60 |
| `func_0014F210` | Matching | 100.00% | 60 |
| `func_0014F108` | Matching | 99.17% | 48 |
| `func_0014F1B0` | Matching | 99.17% | 48 |
| `func_0014F1E0` | Matching | 99.17% | 48 |

### `be/beintecon`

30 matching, 0 partial, 2 not started (32 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEEconInterface_getThis()` | Matching | 100.00% | 76 |
| `func_00150928` | Matching | 100.00% | 56 |
| `func_00150960` | Matching | 100.00% | 96 |
| `cBEEconInterface_getTotalMoneyEarned(void*, int, int)` | Matching | 100.00% | 56 |
| `func_001509F8` | Matching | 100.00% | 96 |
| `func_00150A58` | Matching | 100.00% | 52 |
| `func_00150A90` | Matching | 100.00% | 80 |
| `func_00150AE0` | Matching | 100.00% | 104 |
| `func_00150B48` | Matching | 100.00% | 64 |
| `func_00150B88` | Matching | 100.00% | 152 |
| `func_00150C20` | Matching | 100.00% | 560 |
| `func_00150E50(void*, int)` | Matching | 100.00% | 24 |
| `func_00150E68` | Matching | 100.00% | 468 |
| `func_00151040` | Matching | 100.00% | 312 |
| `func_00151178` | Matching | 100.00% | 52 |
| `func_001511B0` | Matching | 100.00% | 52 |
| `func_001511E8` | Matching | 100.00% | 384 |
| `func_00151368` | Matching | 100.00% | 80 |
| `func_001513B8` | Matching | 100.00% | 508 |
| `func_001515B8` | Matching | 100.00% | 68 |
| `func_001519E0` | Matching | 100.00% | 168 |
| `func_00151A88` | Matching | 100.00% | 328 |
| `func_00151BD0` | Matching | 100.00% | 80 |
| `func_00151C20` | Matching | 100.00% | 36 |
| `func_00151C48` | Matching | 100.00% | 72 |
| `func_00151EF0` | Matching | 100.00% | 504 |
| `func_001520E8` | Matching | 100.00% | 260 |
| `func_001521F0` | Matching | 100.00% | 332 |
| `func_00152340` | Matching | 100.00% | 40 |
| `func_00152368` | Matching | 100.00% | 44 |

### `be/beintmission`

47 matching, 0 partial, 3 not started (50 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEMissionInterface_getThis()` | Matching | 100.00% | 76 |
| `func_001532F0` | Matching | 100.00% | 60 |
| `func_00153330` | Matching | 100.00% | 32 |
| `func_00153350` | Matching | 100.00% | 60 |
| `func_00153390` | Matching | 100.00% | 104 |
| `func_001533F8` | Matching | 100.00% | 160 |
| `func_00153498` | Matching | 100.00% | 132 |
| `func_00153520` | Matching | 100.00% | 160 |
| `cBEMissionInterface_getCurrentCollectForPeak` | Matching | 100.00% | 196 |
| `func_00153688` | Matching | 100.00% | 128 |
| `func_00153858` | Matching | 100.00% | 140 |
| `func_001538E8` | Matching | 100.00% | 192 |
| `func_00153C88` | Matching | 100.00% | 80 |
| `func_00153CD8` | Matching | 100.00% | 80 |
| `func_00153D28` | Matching | 100.00% | 80 |
| `func_00153D78` | Matching | 100.00% | 88 |
| `func_00153DD0` | Matching | 100.00% | 88 |
| `func_00153E28` | Matching | 100.00% | 84 |
| `func_00153E80` | Matching | 100.00% | 88 |
| `func_00153ED8` | Matching | 100.00% | 88 |
| `func_00153F30` | Matching | 100.00% | 52 |
| `func_00153F68` | Matching | 100.00% | 52 |
| `func_00153FA0` | Matching | 100.00% | 52 |
| `func_00153FD8` | Matching | 100.00% | 52 |
| `func_00154010` | Matching | 100.00% | 108 |
| `func_00154080` | Matching | 100.00% | 112 |
| `func_001540F0` | Matching | 100.00% | 112 |
| `func_00154160` | Matching | 100.00% | 112 |
| `func_001541D0` | Matching | 100.00% | 112 |
| `func_00154240` | Matching | 100.00% | 56 |
| `func_00154278` | Matching | 100.00% | 36 |
| `func_001542A0` | Matching | 100.00% | 60 |
| `func_001542E0` | Matching | 100.00% | 136 |
| `func_00154368` | Matching | 100.00% | 116 |
| `func_001544D0` | Matching | 100.00% | 184 |
| `func_00154588` | Matching | 100.00% | 36 |
| `func_001545B0` | Matching | 100.00% | 72 |
| `func_001545F8` | Matching | 100.00% | 52 |
| `func_00154630` | Matching | 100.00% | 68 |
| `func_00154678` | Matching | 100.00% | 228 |
| `func_00154760` | Matching | 100.00% | 64 |
| `func_001547A0` | Matching | 100.00% | 52 |
| `func_001547D8(void*)` | Matching | 100.00% | 8 |
| `func_001547E0(void*)` | Matching | 100.00% | 8 |
| `func_001547E8` | Matching | 100.00% | 172 |
| `func_00154898` | Matching | 100.00% | 172 |
| `func_001543E0` | Matching | 99.83% | 240 |

### `be/beintnetwork`

19 matching, 0 partial, 0 not started (19 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBENetworkInterface_getThis()` | Matching | 100.00% | 76 |
| `func_0014E130` | Matching | 100.00% | 196 |
| `func_0014E1F8` | Matching | 100.00% | 196 |
| `func_0014E2C0(void*)` | Matching | 100.00% | 8 |
| `func_0014E2C8` | Matching | 100.00% | 764 |
| `func_0014E5C8` | Matching | 100.00% | 1012 |
| `func_0014E9C0` | Matching | 100.00% | 52 |
| `func_0014E9F8` | Matching | 100.00% | 152 |
| `func_0014EA90` | Matching | 100.00% | 116 |
| `func_0014EB08` | Matching | 100.00% | 172 |
| `func_0014EBB8` | Matching | 100.00% | 32 |
| `func_0014EBD8` | Matching | 100.00% | 32 |
| `func_0014EBF8` | Matching | 100.00% | 168 |
| `func_0014ECA0` | Matching | 100.00% | 308 |
| `func_0014EDD8` | Matching | 100.00% | 76 |
| `func_0014EE28` | Matching | 100.00% | 48 |
| `func_0014EE58` | Matching | 100.00% | 112 |
| `func_0014EEC8` | Matching | 100.00% | 56 |
| `func_0014EF00` | Matching | 99.17% | 48 |

### `be/beintnewrace`

41 matching, 0 partial, 0 not started (41 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBENewRaceInterface_getThis()` | Matching | 100.00% | 76 |
| `func_00144928` | Matching | 100.00% | 188 |
| `func_001449E8` | Matching | 100.00% | 188 |
| `cBENewRaceInterface_setNumberHumans(void*, int)` | Matching | 100.00% | 76 |
| `cBENewRaceInterface_setNumberMission(void*, int)` | Matching | 100.00% | 36 |
| `func_00144B20` | Matching | 100.00% | 156 |
| `func_00144BC0` | Matching | 100.00% | 32 |
| `func_00144BE0` | Matching | 100.00% | 12 |
| `func_00144BF0` | Matching | 100.00% | 32 |
| `func_00144C10` | Matching | 100.00% | 32 |
| `func_00144C30` | Matching | 100.00% | 24 |
| `func_00144C48` | Matching | 100.00% | 24 |
| `func_00144C60` | Matching | 100.00% | 24 |
| `func_00144C78` | Matching | 100.00% | 28 |
| `func_00144C98` | Matching | 100.00% | 36 |
| `func_00144CC0` | Matching | 100.00% | 28 |
| `func_00144CE0` | Matching | 100.00% | 52 |
| `func_00144D18` | Matching | 100.00% | 28 |
| `func_00144D38` | Matching | 100.00% | 24 |
| `func_00144D50` | Matching | 100.00% | 28 |
| `func_00144D70(void*, int, int)` | Matching | 100.00% | 36 |
| `cBENewRaceInterface_setNumberAI` | Matching | 100.00% | 84 |
| `cBENewRaceInterface_setGameMode` | Matching | 100.00% | 788 |
| `func_00145108` | Matching | 100.00% | 224 |
| `cBENewRaceInterface_setGameEvent` | Matching | 100.00% | 340 |
| `func_00145340` | Matching | 100.00% | 32 |
| `func_00145360` | Matching | 100.00% | 24 |
| `func_00145378` | Matching | 100.00% | 32 |
| `func_00145398` | Matching | 100.00% | 32 |
| `func_001453B8` | Matching | 100.00% | 24 |
| `func_001453D0` | Matching | 100.00% | 292 |
| `func_001454F8` | Matching | 100.00% | 216 |
| `func_001455D0` | Matching | 100.00% | 44 |
| `func_00145600` | Matching | 100.00% | 44 |
| `func_00145630` | Matching | 100.00% | 52 |
| `func_00145668` | Matching | 100.00% | 52 |
| `func_001456A0` | Matching | 100.00% | 172 |
| `func_00145750` | Matching | 100.00% | 200 |
| `func_00145818` | Matching | 100.00% | 84 |
| `func_00145870` | Matching | 100.00% | 84 |
| `func_001458C8` | Matching | 100.00% | 100 |

### `be/beintoption`

17 matching, 0 partial, 0 not started (17 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEOptionInterface_getThis()` | Matching | 100.00% | 84 |
| `func_0014F2A8` | Matching | 100.00% | 180 |
| `func_0014F360` | Matching | 100.00% | 180 |
| `func_0014F418` | Matching | 100.00% | 60 |
| `func_0014F458` | Matching | 100.00% | 160 |
| `func_0014F4F8` | Matching | 100.00% | 260 |
| `func_0014F600` | Matching | 100.00% | 68 |
| `func_0014F648` | Matching | 100.00% | 44 |
| `cBEOptionInterface_getDefaultQuickKeyMessageHashValue(void*, int)` | Matching | 100.00% | 48 |
| `func_0014F6A8` | Matching | 100.00% | 60 |
| `func_0014F6E8` | Matching | 100.00% | 112 |
| `func_0014F758` | Matching | 100.00% | 76 |
| `func_0014F7A8` | Matching | 100.00% | 60 |
| `func_0014F7E8` | Matching | 100.00% | 40 |
| `func_0014F810` | Matching | 100.00% | 96 |
| `func_0014F870` | Matching | 100.00% | 40 |
| `func_0014F898` | Matching | 100.00% | 100 |

### `be/beintplayer`

104 matching, 0 partial, 0 not started (104 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBENewPlayerInterface_cBENewPlayerInterface(cBENewPlayerInterfaceCtor*)` | Matching | 100.00% | 64 |
| `cBENewPlayerInterface_getThis()` | Matching | 100.00% | 68 |
| `func_001459B8` | Matching | 100.00% | 220 |
| `func_00145A98` | Matching | 100.00% | 132 |
| `func_00145B20` | Matching | 100.00% | 180 |
| `cBENewPlayerInterface_defaultCtrl` | Matching | 100.00% | 92 |
| `func_00145C38` | Matching | 100.00% | 120 |
| `func_00145CB0` | Matching | 100.00% | 132 |
| `func_00145D38` | Matching | 100.00% | 148 |
| `func_00145DD0` | Matching | 100.00% | 152 |
| `func_00145E68` | Matching | 100.00% | 136 |
| `func_00145EF0` | Matching | 100.00% | 160 |
| `cBENewPlayerInterface_isPeakLocked` | Matching | 100.00% | 120 |
| `cBENewPlayerInterface_isPeakLocked1` | Matching | 100.00% | 104 |
| `func_00146070` | Matching | 100.00% | 220 |
| `func_00146150` | Matching | 100.00% | 464 |
| `func_00146320` | Matching | 100.00% | 432 |
| `func_001464D0` | Matching | 100.00% | 460 |
| `func_001466A0` | Matching | 100.00% | 528 |
| `func_001468B0` | Matching | 100.00% | 448 |
| `func_00146A70` | Matching | 100.00% | 412 |
| `func_00146C10` | Matching | 100.00% | 388 |
| `func_00146D98` | Matching | 100.00% | 120 |
| `func_00146E10` | Matching | 100.00% | 132 |
| `func_00146E98` | Matching | 100.00% | 168 |
| `func_00146F40` | Matching | 100.00% | 72 |
| `func_00146F88` | Matching | 100.00% | 428 |
| `func_00147138` | Matching | 100.00% | 52 |
| `func_00147170` | Matching | 100.00% | 172 |
| `cBENewPlayerInterface_setRiderCtrlID` | Matching | 100.00% | 108 |
| `func_00147290` | Matching | 100.00% | 52 |
| `func_001472C8` | Matching | 100.00% | 76 |
| `func_00147318` | Matching | 100.00% | 28 |
| `cBENewPlayerInterface_setRiderCharID` | Matching | 100.00% | 92 |
| `cBENewPlayerInterface_getRiderCharID(void*, int)` | Matching | 100.00% | 52 |
| `func_001473D0` | Matching | 100.00% | 64 |
| `func_00147410` | Matching | 100.00% | 52 |
| `func_00147448` | Matching | 100.00% | 64 |
| `cBENewPlayerInterface_getPlayerCharID(void*, int)` | Matching | 100.00% | 28 |
| `func_001474A8` | Matching | 100.00% | 28 |
| `func_001474C8` | Matching | 100.00% | 28 |
| `func_001474E8` | Matching | 100.00% | 60 |
| `func_00147528` | Matching | 100.00% | 88 |
| `func_00147580` | Matching | 100.00% | 60 |
| `func_001475C0` | Matching | 100.00% | 88 |
| `func_00147618` | Matching | 100.00% | 60 |
| `func_00147658` | Matching | 100.00% | 64 |
| `func_00147698` | Matching | 100.00% | 60 |
| `func_001476D8` | Matching | 100.00% | 64 |
| `func_00147718` | Matching | 100.00% | 60 |
| `func_00147758` | Matching | 100.00% | 64 |
| `cBENewPlayerInterface_getPlayerID(int)` | Matching | 100.00% | 24 |
| `func_001477B0` | Matching | 100.00% | 56 |
| `cBENewPlayerInterface_isMissionMan(int)` | Matching | 100.00% | 60 |
| `func_00147828` | Matching | 100.00% | 108 |
| `cBENewPlayerInterface_resetFromMissionMan` | Matching | 100.00% | 112 |
| `func_00147908` | Matching | 100.00% | 120 |
| `func_00147980` | Matching | 100.00% | 176 |
| `func_00147A30` | Matching | 100.00% | 236 |
| `func_00147B20` | Matching | 100.00% | 140 |
| `func_00147BB0` | Matching | 100.00% | 140 |
| `func_00147C40` | Matching | 100.00% | 120 |
| `func_00147CB8` | Matching | 100.00% | 100 |
| `func_00147D20` | Matching | 100.00% | 248 |
| `func_00147E18` | Matching | 100.00% | 248 |
| `func_00147F10` | Matching | 100.00% | 100 |
| `func_00147F78` | Matching | 100.00% | 92 |
| `func_00147FD8` | Matching | 100.00% | 192 |
| `func_00148098` | Matching | 100.00% | 192 |
| `func_00148158` | Matching | 100.00% | 376 |
| `func_001482D0` | Matching | 100.00% | 84 |
| `func_00148328` | Matching | 100.00% | 120 |
| `func_001483A0` | Matching | 100.00% | 108 |
| `func_00148410` | Matching | 100.00% | 96 |
| `func_00148470` | Matching | 100.00% | 108 |
| `func_001484E0` | Matching | 100.00% | 96 |
| `func_00148540` | Matching | 100.00% | 108 |
| `func_001485B0` | Matching | 100.00% | 96 |
| `func_00148610` | Matching | 100.00% | 108 |
| `func_00148680` | Matching | 100.00% | 96 |
| `func_001486E0` | Matching | 100.00% | 108 |
| `func_00148750` | Matching | 100.00% | 96 |
| `func_001487B0` | Matching | 100.00% | 108 |
| `func_00148820` | Matching | 100.00% | 96 |
| `func_00148880` | Matching | 100.00% | 108 |
| `func_001488F0` | Matching | 100.00% | 96 |
| `func_00148950` | Matching | 100.00% | 340 |
| `func_00148AA8` | Matching | 100.00% | 164 |
| `func_00148B50` | Matching | 100.00% | 40 |
| `func_00148B78` | Matching | 100.00% | 40 |
| `func_00148BA0` | Matching | 100.00% | 40 |
| `func_00148BC8` | Matching | 100.00% | 40 |
| `func_00148BF0` | Matching | 100.00% | 40 |
| `func_00148C18` | Matching | 100.00% | 40 |
| `func_00148C40` | Matching | 100.00% | 40 |
| `func_00148C68` | Matching | 100.00% | 40 |
| `func_00148C90` | Matching | 100.00% | 40 |
| `func_00148CB8` | Matching | 100.00% | 40 |
| `func_00148CE0` | Matching | 100.00% | 40 |
| `func_00148D08` | Matching | 100.00% | 40 |
| `func_00148D30` | Matching | 100.00% | 40 |
| `func_00148D58` | Matching | 100.00% | 40 |
| `func_00148D80` | Matching | 100.00% | 228 |
| `func_00148E68` | Matching | 100.00% | 228 |

### `be/beintreward`

112 matching, 0 partial, 1 not started (113 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBERewardInterface_getThis()` | Matching | 100.00% | 76 |
| `func_00156A10` | Matching | 100.00% | 36 |
| `func_00156A38` | Matching | 100.00% | 40 |
| `cBERewardInterface_isBetterMedal(void*, int, int)` | Matching | 100.00% | 44 |
| `func_00156A90` | Matching | 100.00% | 76 |
| `func_00156AE0` | Matching | 100.00% | 72 |
| `func_00156B28` | Matching | 100.00% | 72 |
| `func_00156B70` | Matching | 100.00% | 32 |
| `func_00156B90` | Matching | 100.00% | 32 |
| `func_00156BB0` | Matching | 100.00% | 32 |
| `func_00156BD0` | Matching | 100.00% | 32 |
| `func_00156BF0` | Matching | 100.00% | 32 |
| `func_00156C10` | Matching | 100.00% | 32 |
| `func_00156C30` | Matching | 100.00% | 32 |
| `func_00156C50` | Matching | 100.00% | 32 |
| `func_00156C70` | Matching | 100.00% | 624 |
| `func_00156EE0` | Matching | 100.00% | 416 |
| `func_00157080` | Matching | 100.00% | 400 |
| `func_00157210` | Matching | 100.00% | 156 |
| `func_001572B0(void*)` | Matching | 100.00% | 32 |
| `func_001572D0(void*)` | Matching | 100.00% | 32 |
| `func_001572F0(void*)` | Matching | 100.00% | 32 |
| `func_00157310(void*)` | Matching | 100.00% | 32 |
| `func_00157330(void*)` | Matching | 100.00% | 32 |
| `func_00157350(void*)` | Matching | 100.00% | 32 |
| `func_00157370(void*)` | Matching | 100.00% | 32 |
| `func_00157390` | Matching | 100.00% | 96 |
| `func_001573F0` | Matching | 100.00% | 60 |
| `func_00157430` | Matching | 100.00% | 52 |
| `func_00157468` | Matching | 100.00% | 172 |
| `func_00157518` | Matching | 100.00% | 164 |
| `func_001575C0` | Matching | 100.00% | 92 |
| `func_00157620` | Matching | 100.00% | 92 |
| `func_00157680` | Matching | 100.00% | 92 |
| `func_001576E0` | Matching | 100.00% | 92 |
| `func_00157740` | Matching | 100.00% | 92 |
| `func_001577A0` | Matching | 100.00% | 64 |
| `func_001577E0` | Matching | 100.00% | 192 |
| `func_001578A0` | Matching | 100.00% | 124 |
| `func_00157920` | Matching | 100.00% | 344 |
| `func_00157A78` | Matching | 100.00% | 140 |
| `func_00157B08` | Matching | 100.00% | 104 |
| `func_00157B70` | Matching | 100.00% | 128 |
| `func_00157BF0` | Matching | 100.00% | 364 |
| `func_00157D60` | Matching | 100.00% | 64 |
| `func_00157DA0` | Matching | 100.00% | 64 |
| `func_00157DE0` | Matching | 100.00% | 64 |
| `func_00157E20` | Matching | 100.00% | 64 |
| `func_00157E60` | Matching | 100.00% | 64 |
| `func_00157EA0` | Matching | 100.00% | 60 |
| `func_00157EE0` | Matching | 100.00% | 64 |
| `func_00157F20` | Matching | 100.00% | 176 |
| `func_00157FD0` | Matching | 100.00% | 292 |
| `func_001580F8` | Matching | 100.00% | 292 |
| `func_00158220` | Matching | 100.00% | 292 |
| `func_00158348` | Matching | 100.00% | 292 |
| `func_00158470` | Matching | 100.00% | 232 |
| `func_00158558` | Matching | 100.00% | 188 |
| `func_00158618` | Matching | 100.00% | 232 |
| `func_00158700` | Matching | 100.00% | 40 |
| `func_00158728` | Matching | 100.00% | 40 |
| `func_00158750` | Matching | 100.00% | 40 |
| `func_00158778` | Matching | 100.00% | 64 |
| `func_001587B8` | Matching | 100.00% | 64 |
| `func_001587F8` | Matching | 100.00% | 40 |
| `func_00158820` | Matching | 100.00% | 40 |
| `func_00158848` | Matching | 100.00% | 40 |
| `func_00158870` | Matching | 100.00% | 32 |
| `func_00158890` | Matching | 100.00% | 32 |
| `func_001588B0(void*, int)` | Matching | 100.00% | 24 |
| `func_001588C8` | Matching | 100.00% | 68 |
| `cBERewardInterface_getTrackMedal(void*, int, int, int, int)` | Matching | 100.00% | 76 |
| `func_00158960` | Matching | 100.00% | 76 |
| `func_001589B0` | Matching | 100.00% | 160 |
| `func_00158A50` | Matching | 100.00% | 160 |
| `cBERewardInterface_getEarningsMedal` | Matching | 100.00% | 128 |
| `func_00158B70` | Matching | 100.00% | 68 |
| `func_00158BB8` | Matching | 100.00% | 40 |
| `func_00158BE0` | Matching | 100.00% | 156 |
| `func_00158C80` | Matching | 100.00% | 216 |
| `func_00158D58` | Matching | 100.00% | 216 |
| `func_00158E30` | Matching | 100.00% | 236 |
| `func_00158F20(void*)` | Matching | 100.00% | 12 |
| `func_00158F30(void*)` | Matching | 100.00% | 32 |
| `func_00158F50` | Matching | 100.00% | 12 |
| `func_00158F60` | Matching | 100.00% | 288 |
| `func_00159080` | Matching | 100.00% | 236 |
| `func_00159170` | Matching | 100.00% | 120 |
| `func_001597B0` | Matching | 100.00% | 104 |
| `func_00159818` | Matching | 100.00% | 388 |
| `func_001599A0` | Matching | 100.00% | 356 |
| `func_00159B08` | Matching | 100.00% | 352 |
| `func_00159C68` | Matching | 100.00% | 104 |
| `func_00159CD0` | Matching | 100.00% | 1552 |
| `func_0015A2E0` | Matching | 100.00% | 64 |
| `func_0015A320` | Matching | 100.00% | 52 |
| `func_0015A358` | Matching | 100.00% | 60 |
| `func_0015A398` | Matching | 100.00% | 28 |
| `func_0015A3B8` | Matching | 100.00% | 188 |
| `func_0015A478` | Matching | 100.00% | 12 |
| `func_0015A488` | Matching | 100.00% | 136 |
| `func_0015A510` | Matching | 100.00% | 52 |
| `func_0015A548` | Matching | 100.00% | 104 |
| `func_0015A5B0` | Matching | 100.00% | 60 |
| `func_0015A5F0` | Matching | 100.00% | 52 |
| `func_0015A628` | Matching | 100.00% | 200 |
| `func_0015A6F0` | Matching | 100.00% | 92 |
| `func_0015A750` | Matching | 100.00% | 24 |
| `func_0015A768(void*, int)` | Matching | 100.00% | 16 |
| `func_0015A778` | Matching | 100.00% | 88 |
| `func_0015A7D0` | Matching | 100.00% | 68 |
| `func_0015A818` | Matching | 100.00% | 1340 |

### `be/beintsavefile`

11 matching, 0 partial, 1 not started (12 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBESaveInterface_getThis()` | Matching | 100.00% | 80 |
| `func_00152688` | Matching | 100.00% | 68 |
| `func_001526D0` | Matching | 100.00% | 44 |
| `func_00152700` | Matching | 100.00% | 40 |
| `func_00152728` | Matching | 100.00% | 44 |
| `func_00152758` | Matching | 100.00% | 492 |
| `func_00152948(void*)` | Matching | 100.00% | 8 |
| `func_00152BA8` | Matching | 100.00% | 8 |
| `func_00152BB0` | Matching | 100.00% | 560 |
| `func_00152DE0` | Matching | 100.00% | 620 |
| `func_00153050` | Matching | 100.00% | 56 |

### `be/beintscore`

23 matching, 0 partial, 1 not started (24 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEScoreInterface_getThis()` | Matching | 100.00% | 92 |
| `func_001549A8` | Matching | 100.00% | 52 |
| `func_001549E0(void*)` | Matching | 100.00% | 8 |
| `func_001549E8` | Matching | 100.00% | 108 |
| `func_00154A58` | Matching | 100.00% | 96 |
| `func_00154EE8` | Matching | 100.00% | 512 |
| `func_001550E8` | Matching | 100.00% | 72 |
| `func_00155130` | Matching | 100.00% | 96 |
| `func_00155190` | Matching | 100.00% | 116 |
| `func_00155208` | Matching | 100.00% | 100 |
| `func_00155270` | Matching | 100.00% | 20 |
| `func_00155288` | Matching | 100.00% | 40 |
| `cBEScoreInterface_getCurrentHighlightLevel(void*, int)` | Matching | 100.00% | 68 |
| `func_001552F8` | Matching | 100.00% | 44 |
| `func_00155328` | Matching | 100.00% | 84 |
| `func_00155380(void*)` | Matching | 100.00% | 8 |
| `func_00155388(void*)` | Matching | 100.00% | 8 |
| `func_00155390` | Matching | 100.00% | 140 |
| `func_00155420` | Matching | 100.00% | 956 |
| `func_001557E0` | Matching | 100.00% | 104 |
| `func_00155848` | Matching | 100.00% | 172 |
| `func_001558F8` | Matching | 100.00% | 172 |
| `func_001559A8` | Matching | 100.00% | 168 |

### `be/beintstat`

14 matching, 0 partial, 1 not started (15 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEStatInterface_getCollisionAttrib` | Matching | 100.00% | 228 |
| `func_00149038` | Matching | 100.00% | 228 |
| `func_00149120` | Matching | 100.00% | 228 |
| `func_00149208` | Matching | 100.00% | 228 |
| `func_001492F0` | Matching | 100.00% | 228 |
| `func_001493D8` | Matching | 100.00% | 228 |
| `func_001494C0` | Matching | 100.00% | 228 |
| `func_001495A8` | Matching | 100.00% | 228 |
| `func_00149690` | Matching | 100.00% | 228 |
| `func_00149778` | Matching | 100.00% | 232 |
| `func_00149860` | Matching | 100.00% | 324 |
| `func_001499A8` | Matching | 100.00% | 220 |
| `func_00149A88` | Matching | 100.00% | 304 |
| `func_0014A078` | Matching | 100.00% | 8 |

### `be/belibrary`

70 matching, 0 partial, 10 not started (80 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBELibrary_getCharacterID(int)` | Matching | 100.00% | 48 |
| `func_0014A0B0` | Matching | 100.00% | 48 |
| `cBELibrary_getProfileIndex(int)` | Matching | 100.00% | 76 |
| `cBELibrary_getRiderIndex(int)` | Matching | 100.00% | 80 |
| `func_0014A180` | Matching | 100.00% | 8 |
| `func_0014AB20` | Matching | 100.00% | 68 |
| `cBELibrary_getScoreType` | Matching | 100.00% | 116 |
| `func_0014ABE0` | Matching | 100.00% | 76 |
| `func_0014AC30` | Matching | 100.00% | 28 |
| `func_0014AC50` | Matching | 100.00% | 28 |
| `func_0014AC70` | Matching | 100.00% | 64 |
| `func_0014ACB0` | Matching | 100.00% | 68 |
| `func_0014ACF8` | Matching | 100.00% | 48 |
| `func_0014AD28` | Matching | 100.00% | 36 |
| `func_0014AD50` | Matching | 100.00% | 88 |
| `func_0014ADA8` | Matching | 100.00% | 48 |
| `func_0014ADD8` | Matching | 100.00% | 76 |
| `func_0014AEA8` | Matching | 100.00% | 100 |
| `func_0014AF10` | Matching | 100.00% | 156 |
| `func_0014AFB0` | Matching | 100.00% | 320 |
| `func_0014B0F0` | Matching | 100.00% | 124 |
| `func_0014B170` | Matching | 100.00% | 64 |
| `func_0014B1B0` | Matching | 100.00% | 104 |
| `func_0014B2F8` | Matching | 100.00% | 128 |
| `func_0014B378` | Matching | 100.00% | 252 |
| `func_0014B478` | Matching | 100.00% | 228 |
| `func_0014B560` | Matching | 100.00% | 412 |
| `func_0014B700` | Matching | 100.00% | 164 |
| `func_0014B7A8` | Matching | 100.00% | 372 |
| `func_0014B920` | Matching | 100.00% | 104 |
| `func_0014B988` | Matching | 100.00% | 536 |
| `func_0014BBA0` | Matching | 100.00% | 120 |
| `func_0014BC18` | Matching | 100.00% | 348 |
| `func_0014BD78(void*)` | Matching | 100.00% | 32 |
| `func_0014BD98(void*)` | Matching | 100.00% | 32 |
| `func_0014BDB8(void*)` | Matching | 100.00% | 12 |
| `func_0014BDC8` | Matching | 100.00% | 52 |
| `func_0014BE00` | Matching | 100.00% | 52 |
| `func_0014BE38` | Matching | 100.00% | 52 |
| `func_0014BE70` | Matching | 100.00% | 500 |
| `func_0014C2B0` | Matching | 100.00% | 108 |
| `func_0014C320` | Matching | 100.00% | 164 |
| `func_0014C3C8` | Matching | 100.00% | 192 |
| `func_0014C488` | Matching | 100.00% | 192 |
| `func_0014C548` | Matching | 100.00% | 68 |
| `func_0014C590` | Matching | 100.00% | 68 |
| `func_0014C5D8` | Matching | 100.00% | 68 |
| `func_0014C620` | Matching | 100.00% | 52 |
| `func_0014C658` | Matching | 100.00% | 68 |
| `func_0014C6A0` | Matching | 100.00% | 256 |
| `func_0014D240` | Matching | 100.00% | 292 |
| `func_0014D448` | Matching | 100.00% | 128 |
| `func_0014D4C8` | Matching | 100.00% | 140 |
| `func_0014D558` | Matching | 100.00% | 172 |
| `func_0014D608` | Matching | 100.00% | 480 |
| `func_0014D7E8` | Matching | 100.00% | 284 |
| `func_0014D908` | Matching | 100.00% | 128 |
| `func_0014D988(void*, int)` | Matching | 100.00% | 16 |
| `func_0014D998` | Matching | 100.00% | 52 |
| `func_0014D9D0` | Matching | 100.00% | 52 |
| `func_0014DA08` | Matching | 100.00% | 16 |
| `func_0014DA18` | Matching | 100.00% | 16 |
| `func_0014DAA0` | Matching | 100.00% | 28 |
| `func_0014DB40` | Matching | 100.00% | 188 |
| `func_0014DC00(void*, int)` | Matching | 100.00% | 16 |
| `func_0014DC10` | Matching | 100.00% | 48 |
| `func_0014DC40(void*, int)` | Matching | 100.00% | 16 |
| `func_0014DC50` | Matching | 100.00% | 48 |
| `func_0014D068` | Matching | 99.96% | 468 |
| `func_0014AE60` | Matching | 99.72% | 72 |

### `be/beprepoststate`

13 matching, 0 partial, 0 not started (13 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBEPostRaceState_getState(void*)` | Matching | 100.00% | 88 |
| `func_00156390` | Matching | 100.00% | 284 |
| `func_001564B0` | Matching | 100.00% | 92 |
| `func_00156510` | Matching | 100.00% | 96 |
| `cBEPreRaceState_getState(void*)` | Matching | 100.00% | 88 |
| `func_001565C8` | Matching | 100.00% | 284 |
| `func_001566E8` | Matching | 100.00% | 100 |
| `func_00156750` | Matching | 100.00% | 104 |
| `func_001567B8` | Matching | 100.00% | 88 |
| `func_00156810` | Matching | 100.00% | 72 |
| `func_00156858` | Matching | 100.00% | 248 |
| `func_00156950` | Matching | 100.00% | 56 |
| `func_00156988` | Matching | 100.00% | 52 |

### `be/bestate`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBERaceState_getState(void*)` | Matching | 100.00% | 88 |
| `func_001530E0` | Matching | 100.00% | 284 |
| `func_00153200` | Matching | 100.00% | 84 |
| `func_00153258` | Matching | 100.00% | 72 |

### `bx/appman`

18 matching, 0 partial, 0 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAppMan_cAppMan` | Matching | 100.00% | 84 |
| `cAppMan__cAppMan(void *, int)` | Matching | 100.00% | 52 |
| `cAppMan_run` | Matching | 100.00% | 408 |
| `cAppMan_setNextModule(cAppMan*, unsigned int)` | Matching | 100.00% | 8 |
| `cAppMan_mainLoop` | Matching | 100.00% | 1032 |
| `func_00317308` | Matching | 100.00% | 28 |
| `cAppMan_checkHalt(cAppMan*)` | Matching | 100.00% | 32 |
| `func_00317348(void*)` | Matching | 100.00% | 180 |
| `cAppMan_loadexecpurge` | Matching | 100.00% | 88 |
| `cExecutionMan_halt(cExecutionMan*)` | Matching | 100.00% | 28 |
| `func_00317478` | Matching | 100.00% | 48 |
| `cExecutionMan_checkHalt(void*, int)` | Matching | 100.00% | 88 |
| `func_00317500()` | Matching | 100.00% | 32 |
| `func_00317520()` | Matching | 100.00% | 12 |
| `func_00317530(void*, float)` | Matching | 100.00% | 28 |
| `func_00317550(void*, float)` | Matching | 100.00% | 80 |
| `func_003175A0(void*)` | Matching | 100.00% | 96 |
| `func_00317600(void*)` | Matching | 100.00% | 24 |

### `bx/bigfile`

7 matching, 0 partial, 0 not started (7 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBigFile_cBigFile(cBigFile*)` | Matching | 100.00% | 20 |
| `cBigFile_cBigFile1(cBigFile*)` | Matching | 100.00% | 52 |
| `cBigFile__cBigFile(cBigFile *, int)` | Matching | 100.00% | 68 |
| `cBigFile_close(cBigFile*)` | Matching | 100.00% | 68 |
| `cBigFile_open` | Matching | 100.00% | 136 |
| `func_00316A00(void*)` | Matching | 100.00% | 32 |
| `func_00316A20` | Matching | 100.00% | 36 |

### `bx/blockman`

4 matching, 0 partial, 1 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00316BE0` | Matching | 100.00% | 32 |
| `func_00316C00` | Matching | 100.00% | 96 |
| `func_00316C60` | Matching | 100.00% | 104 |
| `func_00316CC8` | Matching | 100.00% | 8 |

### `bx/bxrandom`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `BXsrand(unsigned int)` | Matching | 100.00% | 36 |
| `BXrand()` | Matching | 100.00% | 32 |
| `AIrand()` | Matching | 100.00% | 32 |
| `AIrandf(float, float)` | Matching | 100.00% | 96 |
| `func_00317890(float, float)` | Matching | 100.00% | 76 |
| `func_003178E0(void*)` | Matching | 100.00% | 36 |
| `func_00317908(void*)` | Matching | 100.00% | 40 |
| `func_00317930(void*)` | Matching | 100.00% | 36 |
| `cBxPseudoRng_Seed` | Matching | 100.00% | 172 |
| `cBxPseudoRng_NextInt` | Matching | 100.00% | 224 |

### `bx/bxstring`

44 matching, 0 partial, 0 not started (44 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBXString_cBXString1` | Matching | 100.00% | 88 |
| `cBXString_Realloc` | Matching | 100.00% | 116 |
| `cBXString_Reset` | Matching | 100.00% | 100 |
| `func_00318120` | Matching | 100.00% | 100 |
| `cBXString_Resize` | Matching | 100.00% | 96 |
| `func_003181E8` | Matching | 100.00% | 120 |
| `cBXString__cBXString` | Matching | 100.00% | 120 |
| `cBXString_cBXString2` | Matching | 100.00% | 120 |
| `func_00318350` | Matching | 100.00% | 132 |
| `cBXString_InitFromCString` | Matching | 100.00% | 108 |
| `cBXString_operatorE` | Matching | 100.00% | 156 |
| `cBXString_cBXString4` | Matching | 100.00% | 88 |
| `func_00318540` | Matching | 100.00% | 132 |
| `func_003185C8` | Matching | 100.00% | 100 |
| `func_00318630` | Matching | 100.00% | 156 |
| `func_003186D0` | Matching | 100.00% | 140 |
| `func_00318760` | Matching | 100.00% | 100 |
| `func_003187C8` | Matching | 100.00% | 100 |
| `cBXString_ConcatImpl` | Matching | 100.00% | 224 |
| `cBXString_Concat` | Matching | 100.00% | 88 |
| `func_00318968` | Matching | 100.00% | 52 |
| `func_003189A0` | Matching | 100.00% | 48 |
| `func_003189D0` | Matching | 100.00% | 184 |
| `func_00318A88` | Matching | 100.00% | 108 |
| `func_00318AF8` | Matching | 100.00% | 72 |
| `func_00318B40` | Matching | 100.00% | 124 |
| `func_00318BC0` | Matching | 100.00% | 52 |
| `func_00318BF8` | Matching | 100.00% | 32 |
| `cBXString_FindLastOf(cBXString*, char, int)` | Matching | 100.00% | 72 |
| `func_00318C60` | Matching | 100.00% | 60 |
| `cBXString_FindFirstOf(cBXString*, char)` | Matching | 100.00% | 68 |
| `func_00318CE8` | Matching | 100.00% | 64 |
| `func_00318D28` | Matching | 100.00% | 104 |
| `func_00318D90` | Matching | 100.00% | 104 |
| `func_00318DF8` | Matching | 100.00% | 112 |
| `func_00318E68` | Matching | 100.00% | 76 |
| `func_00318EB8` | Matching | 100.00% | 100 |
| `func_00318F20` | Matching | 100.00% | 52 |
| `func_00318F58` | Matching | 100.00% | 52 |
| `func_00318F90` | Matching | 100.00% | 148 |
| `func_00319028` | Matching | 100.00% | 124 |
| `cBXString_cBXString5` | Matching | 100.00% | 116 |
| `func_00319120` | Matching | 100.00% | 76 |
| `func_00319170` | Matching | 100.00% | 76 |

### `bx/bxstringctor`

95 matching, 0 partial, 4 not started (99 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBXString_cBXString(cBXString2*)` | Matching | 100.00% | 76 |
| `func_002688E0` | Matching | 100.00% | 112 |
| `func_00268950` | Matching | 100.00% | 100 |
| `func_00268A80` | Matching | 100.00% | 8 |
| `func_00268A88` | Matching | 100.00% | 8 |
| `func_00268A90` | Matching | 100.00% | 36 |
| `func_00268AB8` | Matching | 100.00% | 36 |
| `func_00268AE0` | Matching | 100.00% | 36 |
| `func_00268B08` | Matching | 100.00% | 36 |
| `func_00268B30` | Matching | 100.00% | 36 |
| `func_00268B58` | Matching | 100.00% | 36 |
| `func_00268B80` | Matching | 100.00% | 36 |
| `func_00268BA8` | Matching | 100.00% | 36 |
| `func_00268BD0` | Matching | 100.00% | 36 |
| `func_00268BF8` | Matching | 100.00% | 36 |
| `func_00268C20` | Matching | 100.00% | 36 |
| `func_00268C48` | Matching | 100.00% | 36 |
| `func_00268C70` | Matching | 100.00% | 36 |
| `func_00268C98` | Matching | 100.00% | 36 |
| `func_00268CC0` | Matching | 100.00% | 36 |
| `func_00268CE8` | Matching | 100.00% | 36 |
| `func_00268D10` | Matching | 100.00% | 36 |
| `func_00268D38` | Matching | 100.00% | 36 |
| `func_00268D60` | Matching | 100.00% | 36 |
| `func_00268D88` | Matching | 100.00% | 36 |
| `func_00268DB0` | Matching | 100.00% | 36 |
| `func_00268DD8` | Matching | 100.00% | 36 |
| `func_00268E00` | Matching | 100.00% | 36 |
| `func_00268E28` | Matching | 100.00% | 36 |
| `func_00268E50` | Matching | 100.00% | 36 |
| `func_00268E78` | Matching | 100.00% | 36 |
| `func_00268EA0` | Matching | 100.00% | 36 |
| `func_00268EC8` | Matching | 100.00% | 36 |
| `func_00268EF0` | Matching | 100.00% | 36 |
| `func_00268F18` | Matching | 100.00% | 36 |
| `func_00268F40` | Matching | 100.00% | 36 |
| `func_00268F68` | Matching | 100.00% | 36 |
| `func_00268F90` | Matching | 100.00% | 36 |
| `func_00268FB8` | Matching | 100.00% | 36 |
| `func_00268FE0` | Matching | 100.00% | 36 |
| `func_00269008` | Matching | 100.00% | 188 |
| `func_002690C8` | Matching | 100.00% | 188 |
| `func_00269188` | Matching | 100.00% | 184 |
| `func_00269240` | Matching | 100.00% | 192 |
| `func_00269300` | Matching | 100.00% | 192 |
| `func_002693C0` | Matching | 100.00% | 184 |
| `func_00269478` | Matching | 100.00% | 188 |
| `func_00269538` | Matching | 100.00% | 204 |
| `func_00269608` | Matching | 100.00% | 240 |
| `func_002696F8` | Matching | 100.00% | 212 |
| `func_002697D0` | Matching | 100.00% | 188 |
| `func_00269890` | Matching | 100.00% | 184 |
| `func_00269948` | Matching | 100.00% | 204 |
| `func_00269A18` | Matching | 100.00% | 200 |
| `func_00269AE0` | Matching | 100.00% | 176 |
| `func_00269B90` | Matching | 100.00% | 172 |
| `func_00269C40` | Matching | 100.00% | 176 |
| `func_00269CF0` | Matching | 100.00% | 172 |
| `func_00269DA0(void*)` | Matching | 100.00% | 28 |
| `func_00269DC0` | Matching | 100.00% | 92 |
| `func_00269E20(void*)` | Matching | 100.00% | 28 |
| `func_00269E40` | Matching | 100.00% | 92 |
| `func_00269EA0(void*)` | Matching | 100.00% | 32 |
| `func_00269EC0(void*)` | Matching | 100.00% | 20 |
| `func_00269ED8` | Matching | 100.00% | 64 |
| `func_00269F18` | Matching | 100.00% | 228 |
| `func_0026A000` | Matching | 100.00% | 100 |
| `func_0026A068(void*)` | Matching | 100.00% | 8 |
| `func_0026A070` | Matching | 100.00% | 32 |
| `func_0026A090` | Matching | 100.00% | 36 |
| `func_0026A0B8` | Matching | 100.00% | 124 |
| `func_0026A138` | Matching | 100.00% | 72 |
| `func_0026A180` | Matching | 100.00% | 440 |
| `func_0026A338` | Matching | 100.00% | 64 |
| `func_0026A378` | Matching | 100.00% | 176 |
| `func_0026A8B8` | Matching | 100.00% | 100 |
| `func_0026A920` | Matching | 100.00% | 76 |
| `func_0026A970` | Matching | 100.00% | 64 |
| `func_0026A9B0` | Matching | 100.00% | 208 |
| `func_0026AA80` | Matching | 100.00% | 160 |
| `func_0026AB20` | Matching | 100.00% | 292 |
| `func_0026AC48` | Matching | 100.00% | 60 |
| `func_0026AC88` | Matching | 100.00% | 120 |
| `func_0026AD00` | Matching | 100.00% | 108 |
| `func_0026AD70` | Matching | 100.00% | 44 |
| `func_0026ADA0(void*)` | Matching | 100.00% | 8 |
| `func_0026ADA8` | Matching | 100.00% | 64 |
| `func_0026ADE8` | Matching | 100.00% | 8 |
| `func_0026ADF0` | Matching | 100.00% | 128 |
| `func_0026AE70` | Matching | 100.00% | 144 |
| `func_0026AF00` | Matching | 100.00% | 112 |
| `func_0026AF70` | Matching | 100.00% | 20 |
| `func_0026AF88` | Matching | 100.00% | 16 |
| `func_0026AF98(void*)` | Matching | 100.00% | 28 |
| `func_0026B178` | Matching | 99.90% | 404 |

### `bx/cubicspline`

63 matching, 2 partial, 5 not started (70 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCubicSplineInterpolant_initCommon` | Matching | 100.00% | 160 |
| `func_0031D700(void*)` | Matching | 100.00% | 52 |
| `func_0031D738(void*, float, float)` | Matching | 100.00% | 84 |
| `func_0031D790(void*)` | Matching | 100.00% | 80 |
| `func_0031D7E0` | Matching | 100.00% | 208 |
| `func_0031E260(void*)` | Matching | 100.00% | 116 |
| `func_0031E2D8` | Matching | 100.00% | 1024 |
| `func_0031E6D8` | Matching | 100.00% | 316 |
| `func_0031ED60` | Matching | 100.00% | 392 |
| `func_0031EEE8` | Matching | 100.00% | 304 |
| `func_0031F018` | Matching | 100.00% | 688 |
| `func_0031F2C8` | Matching | 100.00% | 540 |
| `func_0031F4E8` | Matching | 100.00% | 560 |
| `func_0031F718` | Matching | 100.00% | 212 |
| `func_0031F7F0` | Matching | 100.00% | 28 |
| `func_0031F810` | Matching | 100.00% | 40 |
| `func_0031F838` | Matching | 100.00% | 32 |
| `func_0031F858` | Matching | 100.00% | 588 |
| `func_0031FAA8` | Matching | 100.00% | 88 |
| `func_0031FB00` | Matching | 100.00% | 100 |
| `func_0031FB68` | Matching | 100.00% | 80 |
| `func_0031FBB8(void *, void *)` | Matching | 100.00% | 104 |
| `func_0031FC20` | Matching | 100.00% | 516 |
| `func_0031FE28` | Matching | 100.00% | 8 |
| `func_0031FE30` | Matching | 100.00% | 240 |
| `func_0031FF20(void*)` | Matching | 100.00% | 24 |
| `func_0031FF38(void*, int)` | Matching | 100.00% | 36 |
| `func_0031FF60` | Matching | 100.00% | 116 |
| `func_0031FFD8` | Matching | 100.00% | 96 |
| `func_00320038` | Matching | 100.00% | 28 |
| `func_00320058(void*)` | Matching | 100.00% | 28 |
| `func_00320078(void*)` | Matching | 100.00% | 28 |
| `func_00320098` | Matching | 100.00% | 36 |
| `func_003200C0(void*)` | Matching | 100.00% | 28 |
| `func_003200E0` | Matching | 100.00% | 8 |
| `func_003200E8(void*)` | Matching | 100.00% | 56 |
| `func_00320120(void*)` | Matching | 100.00% | 56 |
| `func_00320158(void*)` | Matching | 100.00% | 56 |
| `func_00320190(void*)` | Matching | 100.00% | 72 |
| `func_003201D8(void*)` | Matching | 100.00% | 72 |
| `func_00320220(void*)` | Matching | 100.00% | 76 |
| `func_00320270(void*)` | Matching | 100.00% | 76 |
| `func_003202C0(void*)` | Matching | 100.00% | 52 |
| `func_003202F8(void*)` | Matching | 100.00% | 52 |
| `func_00320330(void*)` | Matching | 100.00% | 52 |
| `func_00320368(void*)` | Matching | 100.00% | 76 |
| `func_003203B8(void*)` | Matching | 100.00% | 76 |
| `func_00320488(void*, void**)` | Matching | 100.00% | 16 |
| `func_00320498(void*, void**)` | Matching | 100.00% | 16 |
| `func_003204A8(void*, void**)` | Matching | 100.00% | 16 |
| `func_003204B8(void*, void**)` | Matching | 100.00% | 24 |
| `func_003204D0(void*, void**)` | Matching | 100.00% | 24 |
| `func_003204E8(void*, void**)` | Matching | 100.00% | 24 |
| `func_00320500(void*, void**)` | Matching | 100.00% | 24 |
| `func_00320518()` | Matching | 100.00% | 8 |
| `func_00320520()` | Matching | 100.00% | 8 |
| `func_00320528()` | Matching | 100.00% | 8 |
| `func_00320530()` | Matching | 100.00% | 8 |
| `func_00320538()` | Matching | 100.00% | 8 |
| `func_00320540()` | Matching | 100.00% | 8 |
| `func_00320548()` | Matching | 100.00% | 8 |
| `func_00320550` | Matching | 100.00% | 976 |
| `func_0031E0E0` | Matching | 99.77% | 176 |
| `func_00320408(void*)` | Partial | 92.50% | 64 |
| `func_00320448(void*)` | Partial | 92.50% | 64 |

### `bx/execman`

31 matching, 0 partial, 0 not started (31 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cExecutionMan__cExecutionMan(cExecutionMan *, int)` | Matching | 100.00% | 48 |
| `cExecutionMan_prepause()` | Matching | 100.00% | 8 |
| `cExecutionMan_postpause()` | Matching | 100.00% | 8 |
| `func_00320960` | Matching | 100.00% | 12 |
| `func_00320970` | Matching | 100.00% | 8 |
| `func_00320978` | Matching | 100.00% | 8 |
| `func_00320980` | Matching | 100.00% | 8 |
| `func_00320988` | Matching | 100.00% | 8 |
| `func_00320990` | Matching | 100.00% | 8 |
| `func_00320998` | Matching | 100.00% | 8 |
| `func_003209A0` | Matching | 100.00% | 8 |
| `func_003209A8` | Matching | 100.00% | 8 |
| `func_003209B0` | Matching | 100.00% | 8 |
| `func_003209B8` | Matching | 100.00% | 8 |
| `func_003209C0` | Matching | 100.00% | 44 |
| `func_003209F0` | Matching | 100.00% | 44 |
| `func_00320A20` | Matching | 100.00% | 60 |
| `func_00320A60` | Matching | 100.00% | 44 |
| `func_00320A90` | Matching | 100.00% | 44 |
| `func_00320AC0` | Matching | 100.00% | 8 |
| `func_00320AC8` | Matching | 100.00% | 8 |
| `func_00320AD0` | Matching | 100.00% | 8 |
| `func_00320AD8` | Matching | 100.00% | 48 |
| `func_00320B08(void*)` | Matching | 100.00% | 28 |
| `func_00320B28(void*)` | Matching | 100.00% | 32 |
| `func_00320B48(void*)` | Matching | 100.00% | 32 |
| `func_00320B68` | Matching | 100.00% | 132 |
| `func_00320BF0` | Matching | 100.00% | 36 |
| `func_00320C18` | Matching | 100.00% | 44 |
| `func_00320C48(void*, int)` | Matching | 100.00% | 36 |
| `func_00320C70` | Matching | 100.00% | 44 |

### `bx/memblockman`

39 matching, 0 partial, 1 not started (40 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cMemMan_initialize` | Matching | 100.00% | 96 |
| `func_00319A90` | Matching | 100.00% | 184 |
| `func_00319B48` | Matching | 100.00% | 80 |
| `func_00319B98` | Matching | 100.00% | 60 |
| `cMemMan_internalResizeBlock` | Matching | 100.00% | 236 |
| `func_00319CC8` | Matching | 100.00% | 60 |
| `func_00319D08` | Matching | 100.00% | 8 |
| `func_00319D10(void*)` | Matching | 100.00% | 8 |
| `func_00319D18(void*)` | Matching | 100.00% | 8 |
| `cMemBlockMan_initialize` | Matching | 100.00% | 296 |
| `func_00319E48` | Matching | 100.00% | 284 |
| `func_00319F68` | Matching | 100.00% | 284 |
| `func_0031A088` | Matching | 100.00% | 168 |
| `func_0031A130` | Matching | 100.00% | 204 |
| `func_0031A200` | Matching | 100.00% | 84 |
| `func_0031A258` | Matching | 100.00% | 8 |
| `func_0031A260` | Matching | 100.00% | 8 |
| `func_0031A268` | Matching | 100.00% | 156 |
| `func_0031A308` | Matching | 100.00% | 180 |
| `func_0031A3C0` | Matching | 100.00% | 204 |
| `func_0031A490` | Matching | 100.00% | 552 |
| `func_0031A6B8` | Matching | 100.00% | 32 |
| `func_0031A920` | Matching | 100.00% | 180 |
| `func_0031A9D8` | Matching | 100.00% | 60 |
| `func_0031AA18` | Matching | 100.00% | 60 |
| `func_0031AA58` | Matching | 100.00% | 112 |
| `func_0031AAC8` | Matching | 100.00% | 40 |
| `func_0031AAF0(void*)` | Matching | 100.00% | 28 |
| `func_0031AB10` | Matching | 100.00% | 32 |
| `func_0031AB30` | Matching | 100.00% | 144 |
| `func_0031ABC0(void*)` | Matching | 100.00% | 8 |
| `func_0031ABC8(void*)` | Matching | 100.00% | 8 |
| `func_0031ABD0` | Matching | 100.00% | 52 |
| `func_0031AC08` | Matching | 100.00% | 84 |
| `func_0031AC60` | Matching | 100.00% | 116 |
| `func_0031ACD8` | Matching | 100.00% | 40 |
| `func_0031AD00` | Matching | 100.00% | 20 |
| `func_0031AD18` | Matching | 100.00% | 8 |
| `func_0031AD20` | Matching | 100.00% | 144 |

### `bx/memman`

7 matching, 0 partial, 1 not started (8 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `operator_new1(int)` | Matching | 100.00% | 40 |
| `operator_new2(int)` | Matching | 100.00% | 40 |
| `operator_new(unsigned int)` | Matching | 100.00% | 28 |
| `operator_delete(int*)` | Matching | 100.00% | 72 |
| `cMemMan_free(void*)` | Matching | 100.00% | 72 |
| `func_00317EE0` | Matching | 100.00% | 52 |
| `func_00317F18` | Matching | 100.00% | 28 |

### `bx/ps2main`

16 matching, 0 partial, 2 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `systemInit` | Matching | 100.00% | 460 |
| `main` | Matching | 100.00% | 136 |
| `func_0031B008` | Matching | 100.00% | 128 |
| `func_0031B088` | Matching | 100.00% | 16 |
| `func_0031B098` | Matching | 100.00% | 224 |
| `func_0031B178` | Matching | 100.00% | 404 |
| `func_0031B310` | Matching | 100.00% | 948 |
| `func_0031B6C8` | Matching | 100.00% | 124 |
| `func_0031B748` | Matching | 100.00% | 96 |
| `func_0031B7A8` | Matching | 100.00% | 520 |
| `func_0031B9B0` | Matching | 100.00% | 380 |
| `func_0031BB30` | Matching | 100.00% | 380 |
| `func_0031BCB0` | Matching | 100.00% | 416 |
| `func_0031BE50` | Matching | 100.00% | 272 |
| `func_0031BF60` | Matching | 100.00% | 224 |
| `func_0031C040` | Matching | 100.00% | 228 |

### `bx/seg_1BA100`

297 matching, 0 partial, 2 not started (299 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `bxLogPrint` | Matching | 100.00% | 56 |
| `func_002B9138` | Matching | 100.00% | 8 |
| `func_002B9140` | Matching | 100.00% | 12 |
| `func_002B9150` | Matching | 100.00% | 24 |
| `func_002B9168` | Matching | 100.00% | 20 |
| `func_002B9180` | Matching | 100.00% | 24 |
| `func_002B9198` | Matching | 100.00% | 24 |
| `func_002B91B0` | Matching | 100.00% | 24 |
| `func_002B9208` | Matching | 100.00% | 28 |
| `func_002B9228` | Matching | 100.00% | 28 |
| `func_002B9248` | Matching | 100.00% | 20 |
| `func_002B9260` | Matching | 100.00% | 24 |
| `func_002B9278` | Matching | 100.00% | 24 |
| `func_002B9290` | Matching | 100.00% | 24 |
| `func_002B92A8` | Matching | 100.00% | 24 |
| `func_002B92C0` | Matching | 100.00% | 24 |
| `func_002B92D8` | Matching | 100.00% | 24 |
| `func_002B92F0` | Matching | 100.00% | 24 |
| `func_002B9308` | Matching | 100.00% | 24 |
| `func_002B9320` | Matching | 100.00% | 24 |
| `func_002B9338` | Matching | 100.00% | 44 |
| `func_002B9368` | Matching | 100.00% | 76 |
| `func_002B93B8` | Matching | 100.00% | 504 |
| `func_002B95B0` | Matching | 100.00% | 516 |
| `func_002B97B8` | Matching | 100.00% | 20 |
| `func_002B97D0` | Matching | 100.00% | 28 |
| `func_002B97F0` | Matching | 100.00% | 28 |
| `func_002B9810` | Matching | 100.00% | 148 |
| `func_002B98A8` | Matching | 100.00% | 316 |
| `func_002B99E8` | Matching | 100.00% | 352 |
| `func_002B9B48` | Matching | 100.00% | 28 |
| `func_002B9B68` | Matching | 100.00% | 28 |
| `func_002B9B88` | Matching | 100.00% | 24 |
| `func_002B9BA0` | Matching | 100.00% | 24 |
| `func_002B9BB8` | Matching | 100.00% | 24 |
| `func_002B9BD0` | Matching | 100.00% | 24 |
| `func_002B9BE8` | Matching | 100.00% | 28 |
| `func_002B9C08` | Matching | 100.00% | 28 |
| `func_002B9C28` | Matching | 100.00% | 20 |
| `func_002B9C40` | Matching | 100.00% | 28 |
| `func_002B9C60` | Matching | 100.00% | 24 |
| `func_002B9C78` | Matching | 100.00% | 56 |
| `func_002B9CB0` | Matching | 100.00% | 24 |
| `func_002B9CC8` | Matching | 100.00% | 24 |
| `func_002B9CE0` | Matching | 100.00% | 44 |
| `func_002B9D10` | Matching | 100.00% | 24 |
| `func_002B9D28` | Matching | 100.00% | 24 |
| `func_002B9D40` | Matching | 100.00% | 24 |
| `func_002B9D58` | Matching | 100.00% | 24 |
| `func_002B9D70` | Matching | 100.00% | 24 |
| `func_002B9D88` | Matching | 100.00% | 12 |
| `func_002B9D98` | Matching | 100.00% | 8 |
| `func_002B9DA0` | Matching | 100.00% | 8 |
| `func_002B9DA8` | Matching | 100.00% | 12 |
| `func_002B9DB8` | Matching | 100.00% | 36 |
| `func_002B9DE0` | Matching | 100.00% | 20 |
| `func_002B9DF8` | Matching | 100.00% | 8 |
| `func_002B9E00` | Matching | 100.00% | 8 |
| `func_002B9E08` | Matching | 100.00% | 8 |
| `func_002B9E10` | Matching | 100.00% | 8 |
| `func_002B9E18` | Matching | 100.00% | 8 |
| `func_002B9E20` | Matching | 100.00% | 8 |
| `func_002B9E28` | Matching | 100.00% | 68 |
| `func_002B9E70` | Matching | 100.00% | 28 |
| `func_002B9E90` | Matching | 100.00% | 28 |
| `func_002B9EB0` | Matching | 100.00% | 24 |
| `func_002B9EC8` | Matching | 100.00% | 32 |
| `func_002B9EE8` | Matching | 100.00% | 32 |
| `func_002B9F08` | Matching | 100.00% | 128 |
| `func_002B9F88` | Matching | 100.00% | 48 |
| `func_002B9FB8` | Matching | 100.00% | 28 |
| `func_002B9FD8` | Matching | 100.00% | 28 |
| `func_002B9FF8` | Matching | 100.00% | 528 |
| `func_002BA208` | Matching | 100.00% | 576 |
| `func_002BA448` | Matching | 100.00% | 612 |
| `func_002BA6B0` | Matching | 100.00% | 620 |
| `func_002BA920` | Matching | 100.00% | 784 |
| `func_002BAC30` | Matching | 100.00% | 8 |
| `func_002BAC38` | Matching | 100.00% | 40 |
| `func_002BAC60` | Matching | 100.00% | 8 |
| `func_002BAC68` | Matching | 100.00% | 8 |
| `func_002BAC70` | Matching | 100.00% | 8 |
| `func_002BAC78` | Matching | 100.00% | 24 |
| `func_002BAC90` | Matching | 100.00% | 8 |
| `func_002BAC98` | Matching | 100.00% | 32 |
| `func_002BACB8` | Matching | 100.00% | 8 |
| `func_002BACC0` | Matching | 100.00% | 8 |
| `func_002BACC8` | Matching | 100.00% | 12 |
| `func_002BACD8` | Matching | 100.00% | 8 |
| `func_002BACE0` | Matching | 100.00% | 8 |
| `func_002BACE8` | Matching | 100.00% | 8 |
| `func_002BACF0` | Matching | 100.00% | 8 |
| `func_002BACF8` | Matching | 100.00% | 8 |
| `func_002BAD00` | Matching | 100.00% | 20 |
| `func_002BAD18` | Matching | 100.00% | 20 |
| `func_002BAD30` | Matching | 100.00% | 20 |
| `func_002BAD48` | Matching | 100.00% | 8 |
| `func_002BAD50` | Matching | 100.00% | 8 |
| `func_002BAD58` | Matching | 100.00% | 8 |
| `func_002BAD60` | Matching | 100.00% | 8 |
| `func_002BAD68` | Matching | 100.00% | 8 |
| `func_002BAD70` | Matching | 100.00% | 8 |
| `func_002BAD78` | Matching | 100.00% | 8 |
| `func_002BAD80` | Matching | 100.00% | 20 |
| `func_002BAD98` | Matching | 100.00% | 8 |
| `func_002BADA0` | Matching | 100.00% | 8 |
| `func_002BADA8` | Matching | 100.00% | 8 |
| `func_002BADB0` | Matching | 100.00% | 8 |
| `func_002BADB8` | Matching | 100.00% | 8 |
| `func_002BADC0` | Matching | 100.00% | 8 |
| `func_002BADC8` | Matching | 100.00% | 8 |
| `func_002BADD0` | Matching | 100.00% | 276 |
| `func_002BAEE8` | Matching | 100.00% | 32 |
| `func_002BAF08` | Matching | 100.00% | 132 |
| `func_002BAF90` | Matching | 100.00% | 32 |
| `func_002BAFB0` | Matching | 100.00% | 304 |
| `func_002BB0E0` | Matching | 100.00% | 32 |
| `func_002BB100` | Matching | 100.00% | 44 |
| `func_002BB130` | Matching | 100.00% | 12 |
| `func_002BB140` | Matching | 100.00% | 144 |
| `func_002BB1D0` | Matching | 100.00% | 232 |
| `func_002BB2B8` | Matching | 100.00% | 96 |
| `func_002BB318` | Matching | 100.00% | 44 |
| `func_002BB348` | Matching | 100.00% | 40 |
| `func_002BB370` | Matching | 100.00% | 28 |
| `func_002BB390` | Matching | 100.00% | 92 |
| `func_002BB3F0` | Matching | 100.00% | 232 |
| `func_002BB4D8` | Matching | 100.00% | 148 |
| `func_002BB570` | Matching | 100.00% | 52 |
| `func_002BB5A8` | Matching | 100.00% | 72 |
| `func_002BB5F0` | Matching | 100.00% | 200 |
| `func_002BB6B8` | Matching | 100.00% | 40 |
| `func_002BB928` | Matching | 100.00% | 716 |
| `func_002BBBF8` | Matching | 100.00% | 60 |
| `func_002BC4E0` | Matching | 100.00% | 32 |
| `func_002BC500` | Matching | 100.00% | 8 |
| `func_002BC508` | Matching | 100.00% | 8 |
| `func_002BC510` | Matching | 100.00% | 8 |
| `func_002BC518` | Matching | 100.00% | 8 |
| `func_002BC520` | Matching | 100.00% | 8 |
| `func_002BC528` | Matching | 100.00% | 8 |
| `func_002BC530` | Matching | 100.00% | 8 |
| `func_002BC538` | Matching | 100.00% | 8 |
| `func_002BC540` | Matching | 100.00% | 8 |
| `func_002BC548` | Matching | 100.00% | 8 |
| `func_002BC550` | Matching | 100.00% | 8 |
| `func_002BC558` | Matching | 100.00% | 8 |
| `func_002BC560` | Matching | 100.00% | 8 |
| `func_002BC568` | Matching | 100.00% | 8 |
| `func_002BC570` | Matching | 100.00% | 8 |
| `func_002BC578` | Matching | 100.00% | 8 |
| `func_002BC580` | Matching | 100.00% | 8 |
| `func_002BC588` | Matching | 100.00% | 8 |
| `func_002BC590` | Matching | 100.00% | 8 |
| `func_002BC598` | Matching | 100.00% | 8 |
| `func_002BC5A0` | Matching | 100.00% | 8 |
| `func_002BC5A8` | Matching | 100.00% | 8 |
| `func_002BC5B0` | Matching | 100.00% | 8 |
| `func_002BC5B8` | Matching | 100.00% | 8 |
| `func_002BC5C0` | Matching | 100.00% | 8 |
| `func_002BC5C8` | Matching | 100.00% | 8 |
| `func_002BC5D0` | Matching | 100.00% | 8 |
| `func_002BC5D8` | Matching | 100.00% | 8 |
| `func_002BC5E0` | Matching | 100.00% | 8 |
| `func_002BC5E8` | Matching | 100.00% | 8 |
| `func_002BC5F0` | Matching | 100.00% | 8 |
| `func_002BC5F8` | Matching | 100.00% | 8 |
| `func_002BC600` | Matching | 100.00% | 8 |
| `func_002BC608` | Matching | 100.00% | 8 |
| `func_002BC610` | Matching | 100.00% | 8 |
| `func_002BC618` | Matching | 100.00% | 8 |
| `func_002BC620` | Matching | 100.00% | 8 |
| `func_002BC628` | Matching | 100.00% | 8 |
| `func_002BC630` | Matching | 100.00% | 8 |
| `func_002BC638` | Matching | 100.00% | 8 |
| `func_002BC640` | Matching | 100.00% | 8 |
| `func_002BC648` | Matching | 100.00% | 8 |
| `func_002BC650` | Matching | 100.00% | 8 |
| `func_002BC658` | Matching | 100.00% | 8 |
| `func_002BC660` | Matching | 100.00% | 8 |
| `func_002BC668` | Matching | 100.00% | 8 |
| `func_002BC670` | Matching | 100.00% | 8 |
| `func_002BC678` | Matching | 100.00% | 8 |
| `func_002BC680` | Matching | 100.00% | 8 |
| `func_002BC688` | Matching | 100.00% | 8 |
| `func_002BC690` | Matching | 100.00% | 8 |
| `func_002BC698` | Matching | 100.00% | 8 |
| `func_002BC6A0` | Matching | 100.00% | 8 |
| `func_002BC6A8` | Matching | 100.00% | 8 |
| `func_002BC6B0` | Matching | 100.00% | 8 |
| `func_002BC6B8` | Matching | 100.00% | 8 |
| `func_002BC6C0` | Matching | 100.00% | 8 |
| `func_002BC6C8` | Matching | 100.00% | 8 |
| `func_002BC6D0` | Matching | 100.00% | 8 |
| `func_002BC6D8` | Matching | 100.00% | 8 |
| `func_002BC6E0` | Matching | 100.00% | 8 |
| `func_002BC6E8` | Matching | 100.00% | 8 |
| `func_002BC6F0` | Matching | 100.00% | 8 |
| `func_002BC6F8` | Matching | 100.00% | 48 |
| `func_002BC728` | Matching | 100.00% | 40 |
| `func_002BC750` | Matching | 100.00% | 40 |
| `func_002BC778` | Matching | 100.00% | 40 |
| `func_002BC7A0` | Matching | 100.00% | 40 |
| `func_002BC7C8` | Matching | 100.00% | 100 |
| `func_002BC830` | Matching | 100.00% | 96 |
| `func_002BC890` | Matching | 100.00% | 88 |
| `func_002BC8E8` | Matching | 100.00% | 40 |
| `func_002BC910` | Matching | 100.00% | 112 |
| `func_002BC980` | Matching | 100.00% | 44 |
| `func_002BCAF8` | Matching | 100.00% | 212 |
| `func_002BCBD0` | Matching | 100.00% | 48 |
| `func_002BCC00` | Matching | 100.00% | 200 |
| `func_002BCCC8` | Matching | 100.00% | 156 |
| `func_002BCD68` | Matching | 100.00% | 156 |
| `func_002BCE08` | Matching | 100.00% | 156 |
| `func_002BCEA8` | Matching | 100.00% | 144 |
| `func_002BCF38` | Matching | 100.00% | 304 |
| `func_002BD068` | Matching | 100.00% | 336 |
| `func_002BD1B8` | Matching | 100.00% | 304 |
| `func_002BD2E8` | Matching | 100.00% | 144 |
| `func_002BD378` | Matching | 100.00% | 412 |
| `func_002BD518` | Matching | 100.00% | 144 |
| `func_002BD5A8` | Matching | 100.00% | 240 |
| `func_002BD698` | Matching | 100.00% | 720 |
| `func_002BD968` | Matching | 100.00% | 188 |
| `func_002BDA28` | Matching | 100.00% | 8 |
| `func_002BDA30` | Matching | 100.00% | 8 |
| `func_002BDA38` | Matching | 100.00% | 8 |
| `func_002BDA40` | Matching | 100.00% | 8 |
| `func_002BDA48` | Matching | 100.00% | 8 |
| `func_002BDA50` | Matching | 100.00% | 8 |
| `func_002BDA58` | Matching | 100.00% | 8 |
| `func_002BDA60` | Matching | 100.00% | 8 |
| `func_002BDA68` | Matching | 100.00% | 8 |
| `func_002BDA70` | Matching | 100.00% | 8 |
| `func_002BDA78` | Matching | 100.00% | 8 |
| `func_002BDA80` | Matching | 100.00% | 8 |
| `func_002BDA88` | Matching | 100.00% | 8 |
| `func_002BDA90` | Matching | 100.00% | 8 |
| `func_002BDA98` | Matching | 100.00% | 44 |
| `func_002BDAC8` | Matching | 100.00% | 20 |
| `func_002BDAE0` | Matching | 100.00% | 20 |
| `func_002BDAF8` | Matching | 100.00% | 20 |
| `func_002BDB10` | Matching | 100.00% | 36 |
| `func_002BDB38` | Matching | 100.00% | 148 |
| `func_002BDBD0` | Matching | 100.00% | 168 |
| `func_002BDC78` | Matching | 100.00% | 148 |
| `func_002BDD10` | Matching | 100.00% | 36 |
| `func_002BDD38` | Matching | 100.00% | 204 |
| `func_002BDE08` | Matching | 100.00% | 36 |
| `func_002BDE30` | Matching | 100.00% | 176 |
| `func_002BDEE0` | Matching | 100.00% | 408 |
| `func_002BE078` | Matching | 100.00% | 52 |
| `func_002BE0B0` | Matching | 100.00% | 20 |
| `func_002BE0C8` | Matching | 100.00% | 16 |
| `func_002BE0D8` | Matching | 100.00% | 16 |
| `func_002BE0E8` | Matching | 100.00% | 16 |
| `func_002BE0F8` | Matching | 100.00% | 16 |
| `func_002BE108` | Matching | 100.00% | 52 |
| `func_002BE140` | Matching | 100.00% | 44 |
| `func_002BE170` | Matching | 100.00% | 40 |
| `func_002BE198` | Matching | 100.00% | 12 |
| `func_002BE1A8` | Matching | 100.00% | 52 |
| `func_002BE1E0` | Matching | 100.00% | 20 |
| `func_002BE258` | Matching | 100.00% | 112 |
| `func_002BE2C8` | Matching | 100.00% | 16 |
| `func_002BE2D8` | Matching | 100.00% | 156 |
| `func_002BE378` | Matching | 100.00% | 100 |
| `func_002BE3E0` | Matching | 100.00% | 100 |
| `func_002BE448` | Matching | 100.00% | 100 |
| `func_002BE4B0` | Matching | 100.00% | 100 |
| `func_002BE518` | Matching | 100.00% | 380 |
| `func_002BE698` | Matching | 100.00% | 436 |
| `func_002BE850` | Matching | 100.00% | 380 |
| `func_002BE9D0` | Matching | 100.00% | 100 |
| `func_002BEA38` | Matching | 100.00% | 548 |
| `func_002BEC60` | Matching | 100.00% | 100 |
| `func_002BECC8` | Matching | 100.00% | 380 |
| `func_002BEE48` | Matching | 100.00% | 1108 |
| `func_002BF2A0` | Matching | 100.00% | 156 |
| `func_002BF340` | Matching | 100.00% | 156 |
| `func_002BF3E0` | Matching | 100.00% | 100 |
| `func_002BF448` | Matching | 100.00% | 100 |
| `func_002BF4B0` | Matching | 100.00% | 100 |
| `func_002BF518` | Matching | 100.00% | 100 |
| `func_002BF580` | Matching | 100.00% | 380 |
| `func_002BF700` | Matching | 100.00% | 436 |
| `func_002BF8B8` | Matching | 100.00% | 380 |
| `func_002BFA38` | Matching | 100.00% | 100 |
| `func_002BFAA0` | Matching | 100.00% | 548 |
| `func_002BFCC8` | Matching | 100.00% | 100 |
| `func_002BFD30` | Matching | 100.00% | 380 |
| `func_002BFEB0` | Matching | 100.00% | 1108 |
| `func_002C0308` | Matching | 100.00% | 156 |
| `func_002BBC38` | Matching | 99.99% | 2212 |
| `func_002BC9B0` | Matching | 99.75% | 324 |
| `func_002BE1F8` | Matching | 99.17% | 96 |

### `camera/camera`

224 matching, 0 partial, 14 not started (238 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCamera_resetChaseControllerSwitches` | Matching | 100.00% | 88 |
| `cCamera_cCamera` | Matching | 100.00% | 276 |
| `func_0015DD88` | Matching | 100.00% | 216 |
| `cCamera_init` | Matching | 100.00% | 312 |
| `func_0015DF98` | Matching | 100.00% | 64 |
| `func_0015DFD8` | Matching | 100.00% | 84 |
| `func_0015E030(void*)` | Matching | 100.00% | 28 |
| `func_0015E2A8` | Matching | 100.00% | 180 |
| `func_0015E360` | Matching | 100.00% | 256 |
| `func_0015E460` | Matching | 100.00% | 520 |
| `func_0015EDC8` | Matching | 100.00% | 56 |
| `func_0015F568` | Matching | 100.00% | 44 |
| `func_0015F598` | Matching | 100.00% | 20 |
| `func_0015F5B0` | Matching | 100.00% | 72 |
| `func_0015F5F8` | Matching | 100.00% | 20 |
| `func_0015F610` | Matching | 100.00% | 20 |
| `func_0015F628` | Matching | 100.00% | 20 |
| `func_0015F640(void*)` | Matching | 100.00% | 12 |
| `func_0015F650` | Matching | 100.00% | 20 |
| `func_0015F668` | Matching | 100.00% | 20 |
| `func_0015F680(void*)` | Matching | 100.00% | 16 |
| `func_0015F690(void*)` | Matching | 100.00% | 16 |
| `func_0015F6A0(void*)` | Matching | 100.00% | 16 |
| `func_0015F6B0` | Matching | 100.00% | 24 |
| `func_0015F6C8` | Matching | 100.00% | 24 |
| `func_0015F6E0(void*)` | Matching | 100.00% | 16 |
| `func_0015F6F0(void*)` | Matching | 100.00% | 12 |
| `func_0015F700(void*)` | Matching | 100.00% | 12 |
| `func_0015F710(void*)` | Matching | 100.00% | 12 |
| `func_0015F720` | Matching | 100.00% | 48 |
| `func_0015F750(void*)` | Matching | 100.00% | 12 |
| `func_0015F760(void*)` | Matching | 100.00% | 12 |
| `func_0015F770(void*)` | Matching | 100.00% | 12 |
| `func_0015F908(void*)` | Matching | 100.00% | 12 |
| `func_0015F918(void*)` | Matching | 100.00% | 16 |
| `func_0015F928(void*)` | Matching | 100.00% | 16 |
| `func_0015F9B8` | Matching | 100.00% | 844 |
| `func_0015FD08` | Matching | 100.00% | 60 |
| `func_0015FD48(void*)` | Matching | 100.00% | 8 |
| `func_0015FFB0` | Matching | 100.00% | 60 |
| `func_00160228` | Matching | 100.00% | 456 |
| `func_00160438` | Matching | 100.00% | 60 |
| `func_00160478(void*)` | Matching | 100.00% | 40 |
| `func_001604A0(void*)` | Matching | 100.00% | 12 |
| `func_001604B0(void *, void *)` | Matching | 100.00% | 8 |
| `func_001606D8` | Matching | 100.00% | 136 |
| `func_00160760` | Matching | 100.00% | 64 |
| `func_001607A0(void*)` | Matching | 100.00% | 40 |
| `func_001607C8(void*)` | Matching | 100.00% | 12 |
| `func_001607D8(void *, void *)` | Matching | 100.00% | 8 |
| `func_00160AE8` | Matching | 100.00% | 136 |
| `func_00160B70` | Matching | 100.00% | 72 |
| `func_00160BB8(void*)` | Matching | 100.00% | 40 |
| `func_00160BE0(void*)` | Matching | 100.00% | 12 |
| `func_00160BF0(void *, void *)` | Matching | 100.00% | 8 |
| `func_00160FD0` | Matching | 100.00% | 140 |
| `func_00161370` | Matching | 100.00% | 104 |
| `func_001613D8(void*)` | Matching | 100.00% | 12 |
| `func_001613E8(void *, void *)` | Matching | 100.00% | 8 |
| `func_00161630` | Matching | 100.00% | 116 |
| `func_001616A8` | Matching | 100.00% | 60 |
| `func_001616E8(void*)` | Matching | 100.00% | 40 |
| `func_00161710(void*)` | Matching | 100.00% | 12 |
| `func_00161720(void *, void *)` | Matching | 100.00% | 8 |
| `func_00161950` | Matching | 100.00% | 88 |
| `func_001619A8` | Matching | 100.00% | 100 |
| `func_00161A10` | Matching | 100.00% | 76 |
| `func_00161A60` | Matching | 100.00% | 64 |
| `func_00161AA0` | Matching | 100.00% | 12 |
| `func_00161E58` | Matching | 100.00% | 152 |
| `func_00161EF0` | Matching | 100.00% | 92 |
| `func_00161F50` | Matching | 100.00% | 76 |
| `func_00161FA0` | Matching | 100.00% | 192 |
| `func_00162060` | Matching | 100.00% | 112 |
| `func_001620D0` | Matching | 100.00% | 104 |
| `func_00162138` | Matching | 100.00% | 56 |
| `func_00162170` | Matching | 100.00% | 52 |
| `func_00162290(void*)` | Matching | 100.00% | 32 |
| `func_00162310(void*, int)` | Matching | 100.00% | 8 |
| `func_00162458` | Matching | 100.00% | 144 |
| `func_001624E8` | Matching | 100.00% | 116 |
| `func_00162560` | Matching | 100.00% | 8 |
| `func_00162B80` | Matching | 100.00% | 12 |
| `func_00163158` | Matching | 100.00% | 280 |
| `func_001635C0` | Matching | 100.00% | 8 |
| `func_001635C8` | Matching | 100.00% | 12 |
| `func_001635D8` | Matching | 100.00% | 8 |
| `func_001635E0` | Matching | 100.00% | 8 |
| `func_001635E8` | Matching | 100.00% | 8 |
| `func_001635F0` | Matching | 100.00% | 8 |
| `func_00164868` | Matching | 100.00% | 8 |
| `func_00164870` | Matching | 100.00% | 8 |
| `func_00165540` | Matching | 100.00% | 364 |
| `func_00166228` | Matching | 100.00% | 116 |
| `func_00166530(void*)` | Matching | 100.00% | 28 |
| `func_00166550` | Matching | 100.00% | 236 |
| `func_001668B8` | Matching | 100.00% | 932 |
| `func_00166F28` | Matching | 100.00% | 100 |
| `func_001673A0` | Matching | 100.00% | 24 |
| `func_001673B8` | Matching | 100.00% | 60 |
| `func_00167DB8` | Matching | 100.00% | 44 |
| `func_00167DE8` | Matching | 100.00% | 48 |
| `func_00167E18(void*)` | Matching | 100.00% | 8 |
| `func_00167E20(void*)` | Matching | 100.00% | 8 |
| `func_00167E28(void*)` | Matching | 100.00% | 8 |
| `func_00167E40` | Matching | 100.00% | 24 |
| `func_00167E58(void*)` | Matching | 100.00% | 8 |
| `func_00167E60(void*)` | Matching | 100.00% | 8 |
| `func_00167E68` | Matching | 100.00% | 40 |
| `func_00167E90(void*)` | Matching | 100.00% | 8 |
| `func_00167E98(void*)` | Matching | 100.00% | 8 |
| `func_00167EA0` | Matching | 100.00% | 48 |
| `func_00167ED0` | Matching | 100.00% | 12 |
| `func_00167EE0` | Matching | 100.00% | 8 |
| `func_00167EE8` | Matching | 100.00% | 8 |
| `func_00167EF0` | Matching | 100.00% | 16 |
| `func_00167F00` | Matching | 100.00% | 8 |
| `func_00167F08` | Matching | 100.00% | 8 |
| `func_00167F10` | Matching | 100.00% | 48 |
| `func_00167F40` | Matching | 100.00% | 48 |
| `func_00167F70` | Matching | 100.00% | 48 |
| `func_00167FA0` | Matching | 100.00% | 16 |
| `func_00167FB0(void*)` | Matching | 100.00% | 8 |
| `func_00167FB8(void*)` | Matching | 100.00% | 8 |
| `func_00167FC0` | Matching | 100.00% | 8 |
| `func_00167FC8` | Matching | 100.00% | 8 |
| `func_00167FD0` | Matching | 100.00% | 8 |
| `func_00167FD8` | Matching | 100.00% | 8 |
| `func_00167FE0` | Matching | 100.00% | 8 |
| `func_00167FE8` | Matching | 100.00% | 8 |
| `func_00167FF0` | Matching | 100.00% | 8 |
| `func_00167FF8` | Matching | 100.00% | 8 |
| `func_00168000` | Matching | 100.00% | 8 |
| `func_00168008` | Matching | 100.00% | 8 |
| `func_00168010` | Matching | 100.00% | 8 |
| `func_00168018` | Matching | 100.00% | 8 |
| `func_00168020` | Matching | 100.00% | 8 |
| `func_00168028` | Matching | 100.00% | 8 |
| `func_00168030` | Matching | 100.00% | 48 |
| `func_00168060(void*)` | Matching | 100.00% | 28 |
| `func_00168080` | Matching | 100.00% | 8 |
| `func_00168088` | Matching | 100.00% | 8 |
| `func_00168090` | Matching | 100.00% | 8 |
| `func_00168098` | Matching | 100.00% | 8 |
| `func_001680A0` | Matching | 100.00% | 8 |
| `func_001680A8` | Matching | 100.00% | 8 |
| `func_001680B0` | Matching | 100.00% | 8 |
| `func_001680B8` | Matching | 100.00% | 12 |
| `func_001680C8` | Matching | 100.00% | 12 |
| `func_001680D8` | Matching | 100.00% | 20 |
| `func_001680F0` | Matching | 100.00% | 8 |
| `func_001680F8` | Matching | 100.00% | 8 |
| `func_00168100` | Matching | 100.00% | 8 |
| `func_00168108` | Matching | 100.00% | 8 |
| `func_00168110` | Matching | 100.00% | 8 |
| `func_00168118` | Matching | 100.00% | 8 |
| `func_00168120` | Matching | 100.00% | 8 |
| `func_00168128` | Matching | 100.00% | 8 |
| `func_00168130` | Matching | 100.00% | 8 |
| `func_00168138` | Matching | 100.00% | 8 |
| `func_00168140` | Matching | 100.00% | 8 |
| `func_00168148` | Matching | 100.00% | 8 |
| `func_00168298(void*)` | Matching | 100.00% | 32 |
| `func_001682B8` | Matching | 100.00% | 60 |
| `func_001682F8(void*)` | Matching | 100.00% | 40 |
| `func_00168320(void*)` | Matching | 100.00% | 12 |
| `func_00168330(void *, void *)` | Matching | 100.00% | 8 |
| `func_00168650` | Matching | 100.00% | 60 |
| `func_00168690(void*)` | Matching | 100.00% | 40 |
| `func_001686B8(void*)` | Matching | 100.00% | 12 |
| `func_001686C8(void *, void *)` | Matching | 100.00% | 8 |
| `func_001689C8` | Matching | 100.00% | 60 |
| `func_00168A08(void*)` | Matching | 100.00% | 40 |
| `func_00168CD8` | Matching | 100.00% | 60 |
| `func_00168D18(void*)` | Matching | 100.00% | 40 |
| `func_00161BB8` | Matching | 99.97% | 672 |
| `func_001656B0` | Matching | 99.97% | 648 |
| `func_00162568` | Matching | 99.96% | 1072 |
| `func_00163450` | Matching | 99.95% | 364 |
| `func_00168150` | Matching | 99.94% | 328 |
| `func_00160028` | Matching | 99.92% | 260 |
| `func_00161AB0` | Matching | 99.92% | 260 |
| `func_001643A8` | Matching | 99.92% | 760 |
| `func_00160130` | Matching | 99.92% | 244 |
| `func_001662A0` | Matching | 99.91% | 652 |
| `func_00161060` | Matching | 99.90% | 784 |
| `func_0015F780` | Matching | 99.90% | 388 |
| `func_00162A20` | Matching | 99.89% | 348 |
| `func_00162998` | Matching | 99.85% | 136 |
| `func_00168940` | Matching | 99.85% | 136 |
| `func_00168C50` | Matching | 99.85% | 136 |
| `func_00168F60` | Matching | 99.85% | 136 |
| `func_00161848` | Matching | 99.85% | 264 |
| `func_00162C78` | Matching | 99.85% | 916 |
| `func_0015F938` | Matching | 99.84% | 128 |
| `func_00162B90` | Matching | 99.82% | 228 |
| `func_00162318` | Matching | 99.81% | 316 |
| `func_0015FD50` | Matching | 99.80% | 604 |
| `func_001622B0` | Matching | 99.79% | 96 |
| `func_00163270` | Matching | 99.75% | 316 |
| `func_0015EC98` | Matching | 99.74% | 304 |
| `func_001603F0` | Matching | 99.72% | 72 |
| `func_00160BF8` | Matching | 99.70% | 984 |
| `func_00162218` | Matching | 99.67% | 60 |
| `func_001607E0` | Matching | 99.64% | 776 |
| `func_001633B0` | Matching | 99.62% | 160 |
| `func_00162258` | Matching | 99.62% | 52 |
| `func_001604B8` | Matching | 99.52% | 540 |
| `func_001621A8` | Matching | 99.44% | 108 |
| `func_001673F8` | Matching | 99.41% | 2444 |
| `func_00168338` | Matching | 99.35% | 464 |
| `func_0015FFF0` | Matching | 99.29% | 56 |
| `func_00161728` | Matching | 99.23% | 284 |
| `func_001686D0` | Matching | 99.16% | 620 |
| `func_00167D88` | Matching | 98.33% | 12 |
| `func_00167D98` | Matching | 98.33% | 12 |
| `func_00167DA8` | Matching | 98.33% | 12 |
| `func_00167E30` | Matching | 98.33% | 12 |
| `func_00168A30` | Matching | 98.33% | 12 |
| `func_00168D40` | Matching | 98.33% | 12 |
| `func_00168A40` | Matching | 98.18% | 44 |
| `func_00168D50` | Matching | 98.18% | 44 |
| `func_00168A70` | Matching | 98.00% | 480 |
| `func_00168D80` | Matching | 98.00% | 480 |

### `camera/cameraalgolist`

3 matching, 0 partial, 0 not started (3 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCameraAlgoList_insert` | Matching | 100.00% | 200 |
| `func_0015CA50` | Matching | 100.00% | 180 |
| `func_0015CB08` | Matching | 100.00% | 152 |

### `camera/cameraalgorithms`

8 matching, 0 partial, 1 not started (9 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cChaseCameraController_createChaseAlgorithmBlend` | Matching | 100.00% | 1564 |
| `func_0015D698` | Matching | 100.00% | 100 |
| `func_0015D700` | Matching | 100.00% | 124 |
| `func_0015D880` | Matching | 100.00% | 164 |
| `func_0015D928` | Matching | 100.00% | 408 |
| `func_0015DAC0` | Matching | 100.00% | 28 |
| `func_0015DAE0` | Matching | 100.00% | 120 |
| `func_0015DB58` | Matching | 100.00% | 192 |

### `camera/cameracontroller`

15 matching, 0 partial, 0 not started (15 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCameraController_cCameraController` | Matching | 100.00% | 112 |
| `func_0015CC10` | Matching | 100.00% | 92 |
| `func_0015CC70` | Matching | 100.00% | 124 |
| `func_0015CCF0` | Matching | 100.00% | 108 |
| `func_0015CD60(void*)` | Matching | 100.00% | 28 |
| `cManualCameraController_cManualCameraController` | Matching | 100.00% | 144 |
| `func_0015CE10` | Matching | 100.00% | 132 |
| `func_0015CE98` | Matching | 100.00% | 76 |
| `func_0015CEE8` | Matching | 100.00% | 60 |
| `func_0015CF28` | Matching | 100.00% | 84 |
| `func_0015CF80` | Matching | 100.00% | 80 |
| `func_0015CFD0` | Matching | 100.00% | 20 |
| `func_0015CFE8` | Matching | 100.00% | 52 |
| `func_0015D020` | Matching | 100.00% | 44 |
| `func_0015D050` | Matching | 100.00% | 36 |

### `camera/script/scriptcontroller`

41 matching, 0 partial, 0 not started (41 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cScriptCameraController_cScriptCameraController` | Matching | 100.00% | 232 |
| `func_001690D0` | Matching | 100.00% | 188 |
| `cScriptCameraController_addCamera` | Matching | 100.00% | 324 |
| `func_001692D8` | Matching | 100.00% | 104 |
| `func_00169340` | Matching | 100.00% | 36 |
| `func_00169368` | Matching | 100.00% | 176 |
| `func_00169418` | Matching | 100.00% | 140 |
| `func_001694A8(void*, int)` | Matching | 100.00% | 8 |
| `func_001694B0(void*)` | Matching | 100.00% | 8 |
| `func_001694B8` | Matching | 100.00% | 96 |
| `func_00169518` | Matching | 100.00% | 40 |
| `func_00169540` | Matching | 100.00% | 44 |
| `func_00169570` | Matching | 100.00% | 692 |
| `func_00169828` | Matching | 100.00% | 1232 |
| `func_00169CF8` | Matching | 100.00% | 96 |
| `func_00169D58` | Matching | 100.00% | 40 |
| `func_00169D80` | Matching | 100.00% | 44 |
| `func_00169DB0` | Matching | 100.00% | 468 |
| `func_00169F88` | Matching | 100.00% | 1232 |
| `func_0016A458` | Matching | 100.00% | 96 |
| `func_0016A4B8` | Matching | 100.00% | 40 |
| `func_0016A4E0` | Matching | 100.00% | 44 |
| `func_0016A510` | Matching | 100.00% | 852 |
| `func_0016A868` | Matching | 100.00% | 1232 |
| `func_0016AD38` | Matching | 100.00% | 96 |
| `func_0016AD98` | Matching | 100.00% | 948 |
| `func_0016B150` | Matching | 100.00% | 44 |
| `func_0016B180` | Matching | 100.00% | 1592 |
| `func_0016B7B8` | Matching | 100.00% | 1232 |
| `func_0016BC88` | Matching | 100.00% | 48 |
| `func_0016BCB8` | Matching | 100.00% | 40 |
| `func_0016BCE0` | Matching | 100.00% | 76 |
| `func_0016BD30` | Matching | 100.00% | 108 |
| `func_0016BDA0` | Matching | 100.00% | 72 |
| `func_0016BDE8` | Matching | 100.00% | 72 |
| `func_0016BE30` | Matching | 100.00% | 48 |
| `func_0016BE60` | Matching | 100.00% | 44 |
| `func_0016BE90` | Matching | 100.00% | 44 |
| `func_0016BEC0` | Matching | 100.00% | 40 |
| `func_0016BEE8(void*)` | Matching | 100.00% | 12 |
| `func_0016BEF8` | Matching | 100.00% | 36 |

### `camera/trigger/cameratriggerfactory`

140 matching, 0 partial, 4 not started (144 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `get_camaction` | Matching | 100.00% | 564 |
| `get_cCTActionBoundedCam` | Matching | 100.00% | 184 |
| `get_cCTActionSwitchCam` | Matching | 100.00% | 84 |
| `get_cCTActionSpline` | Matching | 100.00% | 136 |
| `get_cCTActionNone(void*, int*)` | Matching | 100.00% | 16 |
| `get_camboundobj` | Matching | 100.00% | 908 |
| `get_cCTBoundObjEllipse` | Matching | 100.00% | 236 |
| `get_cCTBoundObjBox` | Matching | 100.00% | 240 |
| `get_cCTBoundObjLine` | Matching | 100.00% | 272 |
| `get_cCTBoundObjPoint(void*, sBoundObjPoint*)` | Matching | 100.00% | 72 |
| `get_camspline` | Matching | 100.00% | 592 |
| `func_00171FA8` | Matching | 100.00% | 536 |
| `func_001721C0` | Matching | 100.00% | 184 |
| `func_00172278` | Matching | 100.00% | 1476 |
| `func_00172840` | Matching | 100.00% | 184 |
| `get_camvolume` | Matching | 100.00% | 456 |
| `get_cCTVolumeEllipse` | Matching | 100.00% | 236 |
| `get_cCTVolumeBox` | Matching | 100.00% | 240 |
| `func_001731C0` | Matching | 100.00% | 68 |
| `func_00173208` | Matching | 100.00% | 172 |
| `func_001732B8` | Matching | 100.00% | 48 |
| `func_001732E8` | Matching | 100.00% | 912 |
| `func_00173678` | Matching | 100.00% | 100 |
| `func_001736E0` | Matching | 100.00% | 1884 |
| `func_00173E40` | Matching | 100.00% | 844 |
| `func_00174190` | Matching | 100.00% | 68 |
| `func_001741D8(void*)` | Matching | 100.00% | 40 |
| `func_00174200` | Matching | 100.00% | 688 |
| `func_001744B0` | Matching | 100.00% | 748 |
| `func_001747A0` | Matching | 100.00% | 100 |
| `func_00174808` | Matching | 100.00% | 60 |
| `func_00174848` | Matching | 100.00% | 4564 |
| `func_00176270` | Matching | 100.00% | 48 |
| `func_001762A0` | Matching | 100.00% | 8 |
| `func_001762A8` | Matching | 100.00% | 8 |
| `func_001762B0` | Matching | 100.00% | 8 |
| `func_001762B8` | Matching | 100.00% | 12 |
| `func_001762C8` | Matching | 100.00% | 24 |
| `func_001762E0` | Matching | 100.00% | 8 |
| `func_001762E8` | Matching | 100.00% | 8 |
| `func_001762F0` | Matching | 100.00% | 40 |
| `func_00176318` | Matching | 100.00% | 8 |
| `func_00176320` | Matching | 100.00% | 8 |
| `func_00176328` | Matching | 100.00% | 48 |
| `func_00176358` | Matching | 100.00% | 16 |
| `func_00176368` | Matching | 100.00% | 48 |
| `func_00176398` | Matching | 100.00% | 48 |
| `func_001763C8` | Matching | 100.00% | 48 |
| `func_001763F8` | Matching | 100.00% | 48 |
| `func_00176428` | Matching | 100.00% | 8 |
| `func_00176430` | Matching | 100.00% | 8 |
| `func_00176438` | Matching | 100.00% | 8 |
| `func_00176440(void*)` | Matching | 100.00% | 8 |
| `func_00176448(void*)` | Matching | 100.00% | 8 |
| `func_00176450(void*)` | Matching | 100.00% | 8 |
| `func_00176458(void*)` | Matching | 100.00% | 8 |
| `func_00176460(void*)` | Matching | 100.00% | 8 |
| `func_00176468` | Matching | 100.00% | 128 |
| `func_001764E8` | Matching | 100.00% | 132 |
| `func_00176570` | Matching | 100.00% | 136 |
| `func_001765F8(void*)` | Matching | 100.00% | 8 |
| `func_00176600` | Matching | 100.00% | 132 |
| `func_00176688` | Matching | 100.00% | 136 |
| `func_00176710` | Matching | 100.00% | 228 |
| `func_001767F8` | Matching | 100.00% | 8 |
| `func_00176800` | Matching | 100.00% | 8 |
| `func_00176808` | Matching | 100.00% | 56 |
| `func_00176840` | Matching | 100.00% | 40 |
| `func_00176868` | Matching | 100.00% | 40 |
| `func_00176890` | Matching | 100.00% | 404 |
| `func_00176A28(void*)` | Matching | 100.00% | 32 |
| `func_00176A48(void*)` | Matching | 100.00% | 32 |
| `func_00176A68` | Matching | 100.00% | 60 |
| `func_00176AA8(void*)` | Matching | 100.00% | 40 |
| `func_00176AD0` | Matching | 100.00% | 12 |
| `func_00176AE0` | Matching | 100.00% | 44 |
| `func_00176B10` | Matching | 100.00% | 464 |
| `func_00176CE0` | Matching | 100.00% | 136 |
| `func_00176D68` | Matching | 100.00% | 60 |
| `func_00176DA8(void*)` | Matching | 100.00% | 40 |
| `func_00176DD0` | Matching | 100.00% | 12 |
| `func_00176DE0` | Matching | 100.00% | 44 |
| `func_00176E10` | Matching | 100.00% | 460 |
| `func_00176FE0` | Matching | 100.00% | 136 |
| `func_00177068` | Matching | 100.00% | 60 |
| `func_001770A8(void*)` | Matching | 100.00% | 40 |
| `func_001770D0` | Matching | 100.00% | 12 |
| `func_001770E0` | Matching | 100.00% | 44 |
| `func_00177110` | Matching | 100.00% | 460 |
| `func_001772E0` | Matching | 100.00% | 136 |
| `func_00177368` | Matching | 100.00% | 344 |
| `func_001774C0` | Matching | 100.00% | 92 |
| `func_00177520(void*)` | Matching | 100.00% | 40 |
| `func_00177548(void*)` | Matching | 100.00% | 12 |
| `func_00177558` | Matching | 100.00% | 44 |
| `func_00177588` | Matching | 100.00% | 136 |
| `func_00177610` | Matching | 100.00% | 60 |
| `func_00177E28` | Matching | 100.00% | 8 |
| `func_00177E30(void*)` | Matching | 100.00% | 32 |
| `func_00177E50` | Matching | 100.00% | 60 |
| `func_00177E90(void*)` | Matching | 100.00% | 40 |
| `func_00177EB8` | Matching | 100.00% | 12 |
| `func_00177EC8` | Matching | 100.00% | 44 |
| `func_00177EF8` | Matching | 100.00% | 196 |
| `func_00178520` | Matching | 100.00% | 100 |
| `func_00178588(void*)` | Matching | 100.00% | 40 |
| `func_00178758` | Matching | 100.00% | 132 |
| `func_00178B70(void*)` | Matching | 100.00% | 40 |
| `func_00178B98(void*)` | Matching | 100.00% | 12 |
| `func_00178BA8(void *, void *)` | Matching | 100.00% | 8 |
| `func_00178E90` | Matching | 100.00% | 136 |
| `func_00178F18` | Matching | 100.00% | 60 |
| `func_00179730` | Matching | 100.00% | 8 |
| `func_00179738(void*)` | Matching | 100.00% | 32 |
| `func_00179758` | Matching | 100.00% | 60 |
| `func_00179FA8(void*)` | Matching | 100.00% | 32 |
| `func_00179FC8` | Matching | 100.00% | 92 |
| `func_0017A028` | Matching | 100.00% | 144 |
| `func_0017A0B8` | Matching | 100.00% | 156 |
| `func_0017A158` | Matching | 100.00% | 200 |
| `func_0017A220` | Matching | 100.00% | 168 |
| `func_0017A2C8` | Matching | 100.00% | 172 |
| `func_0017A638` | Matching | 100.00% | 500 |
| `func_0017A830` | Matching | 100.00% | 328 |
| `func_0017A978` | Matching | 100.00% | 592 |
| `func_0017ABC8(void*)` | Matching | 100.00% | 24 |
| `func_0017ABE0` | Matching | 100.00% | 180 |
| `func_0017AC98` | Matching | 100.00% | 44 |
| `func_00177650` | Matching | 99.98% | 2008 |
| `func_00175A20` | Matching | 99.97% | 2128 |
| `func_001789E8` | Matching | 99.95% | 392 |
| `func_001785F0` | Matching | 99.94% | 360 |
| `func_00178938` | Matching | 99.89% | 176 |
| `func_00178BB0` | Matching | 99.65% | 736 |
| `func_001787E0` | Matching | 99.47% | 340 |
| `func_00178208` | Matching | 99.41% | 472 |
| `func_00179798` | Matching | 99.30% | 2064 |
| `func_00178F58` | Matching | 99.29% | 2008 |
| `func_001785B0` | Matching | 98.33% | 12 |
| `func_001785C0` | Matching | 98.18% | 44 |

### `camera/trigger/cameratriggerlist`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCameraTriggerList_init(cCameraTriggerList*)` | Matching | 100.00% | 32 |
| `func_0016BF40` | Matching | 100.00% | 340 |
| `func_0016C098` | Matching | 100.00% | 60 |
| `func_0016C0D8` | Matching | 100.00% | 68 |
| `cCameraTriggerList_insert(cCameraTriggerList2*, void*, int)` | Matching | 100.00% | 80 |
| `cCameraTriggerList_loadFromFile` | Matching | 100.00% | 180 |
| `cCameraTriggerList_loadFromBuffer` | Matching | 100.00% | 348 |
| `func_0016C388` | Matching | 100.00% | 8 |
| `cCameraTriggerList_initHeader(cCameraTriggerList*)` | Matching | 100.00% | 24 |
| `cCameraTriggerList_readCookie(cCameraTriggerList*, void*)` | Matching | 100.00% | 36 |
| `cCameraTriggerList_readHeader` | Matching | 100.00% | 84 |

### `camera/trigger/cameratriggerman`

21 matching, 0 partial, 7 not started (28 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCameraTriggerMan_cleanupOnExit` | Matching | 100.00% | 88 |
| `func_0016CA08` | Matching | 100.00% | 8 |
| `func_0016CA10(void*)` | Matching | 100.00% | 8 |
| `func_0016CA18` | Matching | 100.00% | 452 |
| `cCameraTriggerMan_purge` | Matching | 100.00% | 488 |
| `cCameraTriggerMan_loadTriggers` | Matching | 100.00% | 104 |
| `cCameraTriggerMan_streamIn` | Matching | 100.00% | 120 |
| `func_0016CEA8` | Matching | 100.00% | 28 |
| `func_0016CEC8(void*, int)` | Matching | 100.00% | 40 |
| `func_0016CEF0` | Matching | 100.00% | 36 |
| `func_0016CF18` | Matching | 100.00% | 36 |
| `func_0016CF40(void*)` | Matching | 100.00% | 8 |
| `func_0016CF48` | Matching | 100.00% | 620 |
| `cCameraTriggerMan_setInGameTriggers(void*)` | Matching | 100.00% | 28 |
| `func_0016D1D8(void*)` | Matching | 100.00% | 28 |
| `func_0016D1F8` | Matching | 100.00% | 8 |
| `cCameraTriggerStack_init(cCameraTriggerStack*)` | Matching | 100.00% | 12 |
| `func_0016D210` | Matching | 100.00% | 40 |
| `func_0016D238(void*, int)` | Matching | 100.00% | 36 |
| `func_0016D260` | Matching | 100.00% | 188 |
| `func_0016D320` | Matching | 100.00% | 3764 |

### `camera/trigger/cameratriggervolumes`

3 matching, 0 partial, 0 not started (3 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `tCameraTrigger__tCameraTrigger__FPvi` | Matching | 100.00% | 36 |
| `func_0016C5D0(void*)` | Matching | 100.00% | 12 |
| `func_0016C5E0` | Matching | 100.00% | 68 |

### `camera/trigger/triggeralgorithms`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cActiveTriggerList_purge(cActiveTriggerList*)` | Matching | 100.00% | 80 |
| `func_0016C678` | Matching | 100.00% | 52 |
| `func_0016C6B0` | Matching | 100.00% | 48 |
| `func_0016C6E0` | Matching | 100.00% | 52 |
| `cActiveTriggerList_add` | Matching | 100.00% | 96 |
| `func_0016C778` | Matching | 100.00% | 136 |
| `func_0016C800` | Matching | 100.00% | 132 |
| `func_0016C888` | Matching | 100.00% | 144 |
| `func_0016C918` | Matching | 100.00% | 76 |
| `func_0016C968` | Matching | 100.00% | 72 |

### `data/vutext`

0 matching, 0 partial, 1 not started (1 total)

### `dirtysock/tags`

35 matching, 0 partial, 5 not started (40 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cDirtysock_tag__TagFieldSetupAppend(char *, char *, char *)` | Matching | 100.00% | 72 |
| `func_003EB578` | Matching | 100.00% | 12 |
| `func_003EB588` | Matching | 100.00% | 336 |
| `cDirtysock_tag_TagFieldDupl` | Matching | 100.00% | 72 |
| `func_003EBBA8` | Matching | 100.00% | 264 |
| `func_003EBCB0` | Matching | 100.00% | 192 |
| `func_003EBD70` | Matching | 100.00% | 208 |
| `func_003EC8B8` | Matching | 100.00% | 232 |
| `func_003EC9A0` | Matching | 100.00% | 228 |
| `func_003ECE38` | Matching | 100.00% | 248 |
| `cDirtysock_tag_TagFieldGetNumber` | Matching | 100.00% | 124 |
| `cDirtysock_tag_TagFieldGetFlags` | Matching | 100.00% | 72 |
| `cDirtysock_tag_TagFieldGetAddr` | Matching | 100.00% | 120 |
| `cDirtysock_tag_TagFieldGetFourCC` | Matching | 100.00% | 132 |
| `cDirtysock_tag_TagFieldGetString` | Matching | 100.00% | 512 |
| `cDirtysock_tag_TagFieldGetBinary` | Matching | 100.00% | 256 |
| `cDirtysock_tag_TagFieldGetStructure` | Matching | 100.00% | 756 |
| `cDirtysock_tag_TagFieldGetCrypt` | Matching | 100.00% | 404 |
| `cDirtysock_tag_TagFieldGetTime` | Matching | 100.00% | 612 |
| `func_003EDD70` | Matching | 100.00% | 268 |
| `func_003EDE80` | Matching | 100.00% | 204 |
| `cDirtysock_tag_TagFieldSetStructure` | Matching | 99.97% | 780 |
| `func_003ECBD8` | Matching | 99.97% | 608 |
| `func_003EB9E8` | Matching | 99.95% | 376 |
| `cDirtysock_tag_TagFieldSetAddress` | Matching | 99.93% | 304 |
| `cDirtysock_tag_TagFieldSetNumber` | Matching | 99.91% | 232 |
| `func_003ECB00` | Matching | 99.91% | 216 |
| `cDirtysock_tag_TagFieldSetEpoch` | Matching | 99.91% | 212 |
| `cDirtysock_tag_TagFieldDelete` | Matching | 99.90% | 204 |
| `cDirtysock_tag_TagFieldSetBinary` | Matching | 99.89% | 188 |
| `cDirtysock_tag_TagFieldSetFlags` | Matching | 99.87% | 156 |
| `cDirtysock_tag_TagFieldSetFourCC` | Matching | 99.85% | 136 |
| `func_003EB8B8` | Matching | 99.78% | 92 |
| `func_003ECA88` | Matching | 99.66% | 116 |
| `func_003EB840` | Matching | 99.50% | 120 |

### `dirtysock/tagsunk`

307 matching, 0 partial, 10 not started (317 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cDirtysock_tag_TagFieldSetUnk` | Matching | 100.00% | 132 |
| `cDirtysock_tag_TagFieldGetUnk` | Matching | 100.00% | 124 |
| `func_00259390(void*)` | Matching | 100.00% | 8 |
| `func_00259398(void *, int, void *, void *)` | Matching | 100.00% | 32 |
| `func_002593B8(void *, int, void *, void *)` | Matching | 100.00% | 32 |
| `func_002593D8` | Matching | 100.00% | 20 |
| `func_002593F0` | Matching | 100.00% | 16 |
| `func_00259400` | Matching | 100.00% | 100 |
| `func_00259468` | Matching | 100.00% | 100 |
| `func_002594D0` | Matching | 100.00% | 340 |
| `func_00259628` | Matching | 100.00% | 640 |
| `func_002598A8(void*)` | Matching | 100.00% | 28 |
| `func_002598C8` | Matching | 100.00% | 232 |
| `func_002599B0` | Matching | 100.00% | 172 |
| `func_00259A60` | Matching | 100.00% | 172 |
| `func_0025A1D0` | Matching | 100.00% | 1152 |
| `func_0025A650` | Matching | 100.00% | 168 |
| `func_0025A6F8` | Matching | 100.00% | 56 |
| `func_0025A730` | Matching | 100.00% | 68 |
| `func_0025A778` | Matching | 100.00% | 212 |
| `func_0025A850` | Matching | 100.00% | 96 |
| `func_0025A8B0` | Matching | 100.00% | 152 |
| `func_0025A948` | Matching | 100.00% | 336 |
| `func_0025AA98` | Matching | 100.00% | 68 |
| `func_0025AAE0` | Matching | 100.00% | 96 |
| `func_0025AB40` | Matching | 100.00% | 272 |
| `func_0025B608` | Matching | 100.00% | 68 |
| `func_0025B650` | Matching | 100.00% | 56 |
| `func_0025B688` | Matching | 100.00% | 80 |
| `func_0025B6D8` | Matching | 100.00% | 296 |
| `func_0025B800` | Matching | 100.00% | 68 |
| `func_0025B848` | Matching | 100.00% | 384 |
| `func_0025B9C8` | Matching | 100.00% | 640 |
| `func_0025BC48` | Matching | 100.00% | 232 |
| `func_0025BD30` | Matching | 100.00% | 484 |
| `func_0025BF18` | Matching | 100.00% | 420 |
| `func_0025C0C0` | Matching | 100.00% | 288 |
| `func_0025C1E0` | Matching | 100.00% | 248 |
| `func_0025C2D8` | Matching | 100.00% | 288 |
| `func_0025C3F8` | Matching | 100.00% | 248 |
| `func_0025C4F0` | Matching | 100.00% | 288 |
| `func_0025C610` | Matching | 100.00% | 612 |
| `func_0025C878` | Matching | 100.00% | 48 |
| `func_0025CD28(void*, int)` | Matching | 100.00% | 36 |
| `func_0025CD50` | Matching | 100.00% | 352 |
| `func_0025CEB0` | Matching | 100.00% | 300 |
| `func_0025CFE0` | Matching | 100.00% | 100 |
| `func_0025D048` | Matching | 100.00% | 368 |
| `func_0025D1B8` | Matching | 100.00% | 284 |
| `func_0025D2D8` | Matching | 100.00% | 332 |
| `func_0025D428` | Matching | 100.00% | 272 |
| `func_0025D538` | Matching | 100.00% | 392 |
| `func_0025D6C0` | Matching | 100.00% | 172 |
| `func_0025D770` | Matching | 100.00% | 140 |
| `func_0025D800` | Matching | 100.00% | 92 |
| `func_0025D860` | Matching | 100.00% | 148 |
| `func_0025D8F8` | Matching | 100.00% | 404 |
| `func_0025DA90` | Matching | 100.00% | 48 |
| `func_0025DAC0` | Matching | 100.00% | 192 |
| `func_0025DB80` | Matching | 100.00% | 388 |
| `func_0025DD08` | Matching | 100.00% | 92 |
| `func_0025DD68` | Matching | 100.00% | 116 |
| `func_0025DDE0` | Matching | 100.00% | 284 |
| `func_0025DF00` | Matching | 100.00% | 148 |
| `func_0025DF98` | Matching | 100.00% | 300 |
| `func_0025E0C8` | Matching | 100.00% | 108 |
| `func_0025E138` | Matching | 100.00% | 528 |
| `func_0025E348` | Matching | 100.00% | 212 |
| `func_0025E420` | Matching | 100.00% | 364 |
| `func_0025E590` | Matching | 100.00% | 316 |
| `func_0025E6D0` | Matching | 100.00% | 288 |
| `func_0025E7F0` | Matching | 100.00% | 684 |
| `func_0025EAA0` | Matching | 100.00% | 92 |
| `func_0025EB00` | Matching | 100.00% | 796 |
| `func_0025EE20` | Matching | 100.00% | 180 |
| `func_0025EED8` | Matching | 100.00% | 340 |
| `func_0025F030` | Matching | 100.00% | 236 |
| `func_0025F120` | Matching | 100.00% | 48 |
| `func_0025F150` | Matching | 100.00% | 44 |
| `func_0025F180` | Matching | 100.00% | 48 |
| `func_0025F1B0` | Matching | 100.00% | 48 |
| `func_0025F1E0` | Matching | 100.00% | 104 |
| `func_0025F248` | Matching | 100.00% | 64 |
| `func_0025F288` | Matching | 100.00% | 172 |
| `func_0025F388` | Matching | 100.00% | 164 |
| `func_0025F430` | Matching | 100.00% | 72 |
| `func_0025F478` | Matching | 100.00% | 68 |
| `func_0025F628` | Matching | 100.00% | 280 |
| `func_0025F740` | Matching | 100.00% | 280 |
| `func_0025F858` | Matching | 100.00% | 72 |
| `func_0025F8A0` | Matching | 100.00% | 420 |
| `func_0025FA48` | Matching | 100.00% | 136 |
| `func_0025FAD0` | Matching | 100.00% | 136 |
| `func_0025FB58` | Matching | 100.00% | 40 |
| `func_0025FB80` | Matching | 100.00% | 156 |
| `func_0025FC20(void*)` | Matching | 100.00% | 8 |
| `func_0025FC28(void*, int)` | Matching | 100.00% | 32 |
| `func_0025FC48(void*)` | Matching | 100.00% | 36 |
| `func_0025FC70` | Matching | 100.00% | 224 |
| `func_00260C68` | Matching | 100.00% | 488 |
| `func_00260E50` | Matching | 100.00% | 192 |
| `func_00260F10` | Matching | 100.00% | 108 |
| `func_00260F80` | Matching | 100.00% | 132 |
| `func_00261008` | Matching | 100.00% | 76 |
| `func_00261058(void*)` | Matching | 100.00% | 24 |
| `func_00261070` | Matching | 100.00% | 92 |
| `func_002610D0` | Matching | 100.00% | 376 |
| `func_00261248` | Matching | 100.00% | 380 |
| `func_002613C8` | Matching | 100.00% | 64 |
| `func_00261408` | Matching | 100.00% | 84 |
| `func_00261460` | Matching | 100.00% | 48 |
| `func_00261490` | Matching | 100.00% | 76 |
| `func_002614E0` | Matching | 100.00% | 8 |
| `func_002614E8` | Matching | 100.00% | 72 |
| `func_00261530` | Matching | 100.00% | 152 |
| `func_002615C8` | Matching | 100.00% | 424 |
| `func_002618C0` | Matching | 100.00% | 172 |
| `func_00261970` | Matching | 100.00% | 172 |
| `func_00261A20(void*)` | Matching | 100.00% | 8 |
| `func_00261CD0` | Matching | 100.00% | 552 |
| `func_00261EF8` | Matching | 100.00% | 476 |
| `func_002620D8` | Matching | 100.00% | 424 |
| `func_00262280` | Matching | 100.00% | 108 |
| `func_002622F0` | Matching | 100.00% | 108 |
| `func_00262360` | Matching | 100.00% | 48 |
| `func_00262390(void*)` | Matching | 100.00% | 32 |
| `func_002623B0` | Matching | 100.00% | 48 |
| `func_002623E0(void*)` | Matching | 100.00% | 32 |
| `func_00262400` | Matching | 100.00% | 52 |
| `func_00262438` | Matching | 100.00% | 48 |
| `func_00262468` | Matching | 100.00% | 144 |
| `func_002624F8` | Matching | 100.00% | 156 |
| `func_00262598` | Matching | 100.00% | 48 |
| `func_002625C8` | Matching | 100.00% | 84 |
| `func_00262620` | Matching | 100.00% | 56 |
| `func_00262658` | Matching | 100.00% | 56 |
| `func_00262690` | Matching | 100.00% | 216 |
| `func_00262768` | Matching | 100.00% | 340 |
| `func_002628C0` | Matching | 100.00% | 116 |
| `func_00262938` | Matching | 100.00% | 20 |
| `func_00262950` | Matching | 100.00% | 180 |
| `func_00262A08` | Matching | 100.00% | 48 |
| `func_00262A38` | Matching | 100.00% | 116 |
| `func_00262AB0` | Matching | 100.00% | 60 |
| `func_00262AF0` | Matching | 100.00% | 816 |
| `func_00262E20` | Matching | 100.00% | 160 |
| `func_00262EC0` | Matching | 100.00% | 344 |
| `func_00263018` | Matching | 100.00% | 268 |
| `func_00263128` | Matching | 100.00% | 184 |
| `func_002631E0` | Matching | 100.00% | 140 |
| `func_00263270` | Matching | 100.00% | 152 |
| `func_00263308` | Matching | 100.00% | 48 |
| `func_00263338` | Matching | 100.00% | 140 |
| `func_002633C8` | Matching | 100.00% | 48 |
| `func_002633F8` | Matching | 100.00% | 148 |
| `func_00263490` | Matching | 100.00% | 48 |
| `func_002634C0` | Matching | 100.00% | 64 |
| `func_00263500` | Matching | 100.00% | 168 |
| `func_002635A8` | Matching | 100.00% | 136 |
| `func_00263630` | Matching | 100.00% | 48 |
| `func_00263660(void*)` | Matching | 100.00% | 24 |
| `func_00263678` | Matching | 100.00% | 48 |
| `func_002636A8` | Matching | 100.00% | 72 |
| `func_002636F0` | Matching | 100.00% | 312 |
| `func_00263828` | Matching | 100.00% | 364 |
| `func_00263998(void*)` | Matching | 100.00% | 24 |
| `func_002639B0` | Matching | 100.00% | 48 |
| `func_002639E0` | Matching | 100.00% | 456 |
| `func_00263BA8` | Matching | 100.00% | 324 |
| `func_00263CF0` | Matching | 100.00% | 828 |
| `func_00264030` | Matching | 100.00% | 104 |
| `func_00264098` | Matching | 100.00% | 40 |
| `func_002640C0` | Matching | 100.00% | 116 |
| `func_00264138` | Matching | 100.00% | 380 |
| `func_00264960` | Matching | 100.00% | 44 |
| `func_00264990` | Matching | 100.00% | 28 |
| `func_002649B0` | Matching | 100.00% | 164 |
| `func_00264A58` | Matching | 100.00% | 200 |
| `func_00264B20` | Matching | 100.00% | 200 |
| `func_00264BE8` | Matching | 100.00% | 208 |
| `func_00264CB8` | Matching | 100.00% | 56 |
| `func_00264CF0` | Matching | 100.00% | 140 |
| `func_00264D80` | Matching | 100.00% | 204 |
| `func_00264E50` | Matching | 100.00% | 312 |
| `func_00264F88` | Matching | 100.00% | 140 |
| `func_00265018` | Matching | 100.00% | 292 |
| `func_00265140` | Matching | 100.00% | 80 |
| `func_00265190` | Matching | 100.00% | 252 |
| `func_00265290` | Matching | 100.00% | 264 |
| `func_00265398` | Matching | 100.00% | 192 |
| `func_00265458` | Matching | 100.00% | 272 |
| `func_00265568` | Matching | 100.00% | 284 |
| `func_00265688` | Matching | 100.00% | 116 |
| `func_00265700` | Matching | 100.00% | 104 |
| `func_00265880` | Matching | 100.00% | 56 |
| `func_002658B8` | Matching | 100.00% | 40 |
| `func_002658E0` | Matching | 100.00% | 40 |
| `func_00265908` | Matching | 100.00% | 68 |
| `func_00265950` | Matching | 100.00% | 108 |
| `func_002659C0` | Matching | 100.00% | 36 |
| `func_002659E8` | Matching | 100.00% | 80 |
| `func_00265A38` | Matching | 100.00% | 44 |
| `func_00265A68` | Matching | 100.00% | 580 |
| `func_00265CB0` | Matching | 100.00% | 84 |
| `func_00265D08` | Matching | 100.00% | 44 |
| `func_00265D38` | Matching | 100.00% | 44 |
| `func_00265D68` | Matching | 100.00% | 48 |
| `func_00265D98` | Matching | 100.00% | 88 |
| `func_00265DF0(void*)` | Matching | 100.00% | 12 |
| `func_00265E00(void*)` | Matching | 100.00% | 12 |
| `func_00265E10(void*)` | Matching | 100.00% | 12 |
| `func_00265E20(void*)` | Matching | 100.00% | 12 |
| `func_00265E30(void*)` | Matching | 100.00% | 12 |
| `func_00265E40` | Matching | 100.00% | 60 |
| `func_00265E80` | Matching | 100.00% | 68 |
| `func_00265EC8` | Matching | 100.00% | 52 |
| `func_00265F00` | Matching | 100.00% | 20 |
| `func_00265F18` | Matching | 100.00% | 76 |
| `func_00265F68` | Matching | 100.00% | 76 |
| `func_00265FB8` | Matching | 100.00% | 84 |
| `func_00266010` | Matching | 100.00% | 36 |
| `func_00266038` | Matching | 100.00% | 36 |
| `func_00266060` | Matching | 100.00% | 64 |
| `func_002660A0` | Matching | 100.00% | 36 |
| `func_002660C8` | Matching | 100.00% | 128 |
| `func_00266148` | Matching | 100.00% | 40 |
| `func_00266170` | Matching | 100.00% | 104 |
| `func_002661D8` | Matching | 100.00% | 104 |
| `func_00266240` | Matching | 100.00% | 88 |
| `func_00266298` | Matching | 100.00% | 40 |
| `func_002662C0` | Matching | 100.00% | 40 |
| `func_002662E8` | Matching | 100.00% | 56 |
| `func_00266320` | Matching | 100.00% | 40 |
| `func_00266348` | Matching | 100.00% | 12 |
| `func_00266358` | Matching | 100.00% | 500 |
| `func_00266550` | Matching | 100.00% | 40 |
| `func_00266578` | Matching | 100.00% | 428 |
| `func_00266728` | Matching | 100.00% | 56 |
| `func_00266760` | Matching | 100.00% | 36 |
| `func_00266788` | Matching | 100.00% | 56 |
| `func_002667C0` | Matching | 100.00% | 40 |
| `func_002667E8` | Matching | 100.00% | 100 |
| `func_00266850` | Matching | 100.00% | 84 |
| `func_002668A8` | Matching | 100.00% | 60 |
| `func_002668E8` | Matching | 100.00% | 660 |
| `func_00266B80` | Matching | 100.00% | 40 |
| `func_00266BA8` | Matching | 100.00% | 248 |
| `func_00266CA0` | Matching | 100.00% | 56 |
| `func_00266CD8` | Matching | 100.00% | 40 |
| `func_00266D00(void*)` | Matching | 100.00% | 16 |
| `func_00266D10` | Matching | 100.00% | 68 |
| `func_00266D58` | Matching | 100.00% | 160 |
| `func_00266DF8` | Matching | 100.00% | 56 |
| `func_00266E30` | Matching | 100.00% | 88 |
| `func_00266E88` | Matching | 100.00% | 68 |
| `func_00266ED0` | Matching | 100.00% | 56 |
| `func_00266F08` | Matching | 100.00% | 44 |
| `func_00266F38(void*)` | Matching | 100.00% | 28 |
| `func_00266F58` | Matching | 100.00% | 56 |
| `func_00266F90` | Matching | 100.00% | 44 |
| `func_00266FC0` | Matching | 100.00% | 60 |
| `func_00267000` | Matching | 100.00% | 104 |
| `func_00267068` | Matching | 100.00% | 96 |
| `func_002670C8` | Matching | 100.00% | 96 |
| `func_00267128` | Matching | 100.00% | 416 |
| `func_002672C8` | Matching | 100.00% | 416 |
| `func_00267D88` | Matching | 100.00% | 8 |
| `func_00267D90` | Matching | 100.00% | 12 |
| `func_00267DA0` | Matching | 100.00% | 8 |
| `func_00267DA8(void*)` | Matching | 100.00% | 28 |
| `func_00267DC8(void*)` | Matching | 100.00% | 8 |
| `func_00267DD0(void*)` | Matching | 100.00% | 8 |
| `func_00267DD8` | Matching | 100.00% | 12 |
| `func_00267DE8(void*)` | Matching | 100.00% | 8 |
| `func_00267DF0(void*)` | Matching | 100.00% | 8 |
| `func_00267DF8(void*)` | Matching | 100.00% | 8 |
| `func_00267E00` | Matching | 100.00% | 16 |
| `func_00267E10(void*)` | Matching | 100.00% | 8 |
| `func_00267E18` | Matching | 100.00% | 48 |
| `func_00267E48` | Matching | 100.00% | 80 |
| `func_00267E98` | Matching | 100.00% | 48 |
| `func_00267EC8` | Matching | 100.00% | 92 |
| `func_00267F28` | Matching | 100.00% | 48 |
| `func_00267F58` | Matching | 100.00% | 92 |
| `func_00267FB8` | Matching | 100.00% | 48 |
| `func_00267FE8` | Matching | 100.00% | 92 |
| `func_00268048` | Matching | 100.00% | 96 |
| `func_002680A8` | Matching | 100.00% | 176 |
| `func_00268158` | Matching | 100.00% | 84 |
| `func_002681B0` | Matching | 100.00% | 96 |
| `func_00268210` | Matching | 100.00% | 48 |
| `func_00268240` | Matching | 100.00% | 104 |
| `func_002682A8` | Matching | 100.00% | 96 |
| `func_00268308` | Matching | 100.00% | 140 |
| `func_00268398` | Matching | 100.00% | 84 |
| `func_002683F0` | Matching | 100.00% | 108 |
| `func_00268460` | Matching | 100.00% | 96 |
| `func_002684C0` | Matching | 100.00% | 200 |
| `func_00268588` | Matching | 100.00% | 84 |
| `func_002685E0` | Matching | 100.00% | 120 |
| `func_00268658` | Matching | 100.00% | 48 |
| `func_00268688` | Matching | 100.00% | 100 |
| `func_002686F0` | Matching | 100.00% | 48 |
| `func_00268720` | Matching | 100.00% | 108 |
| `func_00268790` | Matching | 100.00% | 48 |
| `func_002687C0` | Matching | 100.00% | 208 |
| `func_00267468` | Matching | 99.99% | 2332 |

### `ealib/seg_2B4578`

506 matching, 1 partial, 98 not started (605 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003B38B8` | Matching | 100.00% | 72 |
| `func_003B3900` | Matching | 100.00% | 180 |
| `SHAPE_locate` | Matching | 100.00% | 28 |
| `func_003B39D8` | Matching | 100.00% | 28 |
| `func_003B39F8` | Matching | 100.00% | 24 |
| `func_003B3A10` | Matching | 100.00% | 64 |
| `func_003B3DA8` | Matching | 100.00% | 152 |
| `func_003B4218` | Matching | 100.00% | 148 |
| `func_003B4448` | Matching | 100.00% | 16 |
| `func_003B4458` | Matching | 100.00% | 28 |
| `SHAPE_cloneat` | Matching | 100.00% | 336 |
| `func_003B4690` | Matching | 100.00% | 116 |
| `func_003B4708` | Matching | 100.00% | 56 |
| `func_003B4818` | Matching | 100.00% | 408 |
| `func_003B49B0` | Matching | 100.00% | 28 |
| `func_003B4D00` | Matching | 100.00% | 216 |
| `func_003B4DD8` | Matching | 100.00% | 484 |
| `func_003B4FC0` | Matching | 100.00% | 404 |
| `func_003B5320` | Matching | 100.00% | 288 |
| `func_003B5440` | Matching | 100.00% | 12 |
| `func_003B5450` | Matching | 100.00% | 32 |
| `func_003B5470` | Matching | 100.00% | 8 |
| `func_003B5478` | Matching | 100.00% | 100 |
| `func_003B54E0` | Matching | 100.00% | 92 |
| `func_003B5540` | Matching | 100.00% | 172 |
| `func_003B5860` | Matching | 100.00% | 28 |
| `func_003B5880` | Matching | 100.00% | 28 |
| `func_003B58A0` | Matching | 100.00% | 56 |
| `func_003B58D8` | Matching | 100.00% | 56 |
| `func_003B5910` | Matching | 100.00% | 56 |
| `func_003B5948` | Matching | 100.00% | 220 |
| `func_003B5A28` | Matching | 100.00% | 56 |
| `func_003B5A60` | Matching | 100.00% | 188 |
| `func_003B5B20` | Matching | 100.00% | 72 |
| `func_003B5B68` | Matching | 100.00% | 56 |
| `func_003B5BA0` | Matching | 100.00% | 48 |
| `func_003B5BD0` | Matching | 100.00% | 112 |
| `func_003B5C40` | Matching | 100.00% | 28 |
| `func_003B5E98` | Matching | 100.00% | 200 |
| `func_003B5F60` | Matching | 100.00% | 52 |
| `func_003B6098` | Matching | 100.00% | 612 |
| `func_003B64D8` | Matching | 100.00% | 80 |
| `func_003B6528` | Matching | 100.00% | 28 |
| `func_003B6548` | Matching | 100.00% | 136 |
| `func_003B65D0` | Matching | 100.00% | 160 |
| `func_003B6670` | Matching | 100.00% | 276 |
| `func_003B6820` | Matching | 100.00% | 152 |
| `func_003B68B8` | Matching | 100.00% | 140 |
| `func_003B6948` | Matching | 100.00% | 140 |
| `func_003B69D8` | Matching | 100.00% | 92 |
| `func_003B6A38` | Matching | 100.00% | 56 |
| `func_003B6A70` | Matching | 100.00% | 104 |
| `func_003B6AD8` | Matching | 100.00% | 56 |
| `func_003B6B10` | Matching | 100.00% | 192 |
| `func_003B7410` | Matching | 100.00% | 60 |
| `func_003B76E8` | Matching | 100.00% | 304 |
| `func_003B78D8` | Matching | 100.00% | 28 |
| `func_003B78F8` | Matching | 100.00% | 376 |
| `func_003B7A70` | Matching | 100.00% | 88 |
| `func_003B7AC8` | Matching | 100.00% | 52 |
| `func_003B7B00` | Matching | 100.00% | 68 |
| `func_003B7B48` | Matching | 100.00% | 248 |
| `func_003B7C40` | Matching | 100.00% | 320 |
| `func_003B7D80` | Matching | 100.00% | 104 |
| `func_003B7DE8` | Matching | 100.00% | 36 |
| `func_003B7E10` | Matching | 100.00% | 36 |
| `func_003B7E70` | Matching | 100.00% | 64 |
| `func_003B7EB0` | Matching | 100.00% | 104 |
| `func_003B7F18` | Matching | 100.00% | 68 |
| `func_003B7F60` | Matching | 100.00% | 84 |
| `func_003B7FB8` | Matching | 100.00% | 84 |
| `func_003B8010` | Matching | 100.00% | 64 |
| `func_003B80A0` | Matching | 100.00% | 64 |
| `func_003B80E0` | Matching | 100.00% | 64 |
| `func_003B8120` | Matching | 100.00% | 60 |
| `func_003B8160` | Matching | 100.00% | 180 |
| `func_003B8218` | Matching | 100.00% | 120 |
| `func_003B8290` | Matching | 100.00% | 36 |
| `func_003B82B8` | Matching | 100.00% | 228 |
| `func_003B83A0` | Matching | 100.00% | 320 |
| `func_003B84E0` | Matching | 100.00% | 76 |
| `func_003B8530` | Matching | 100.00% | 188 |
| `func_003B85F0` | Matching | 100.00% | 208 |
| `func_003B86C0` | Matching | 100.00% | 64 |
| `func_003B8700` | Matching | 100.00% | 140 |
| `func_003B8790` | Matching | 100.00% | 164 |
| `func_003B8838` | Matching | 100.00% | 140 |
| `func_003B88C8` | Matching | 100.00% | 172 |
| `func_003B8978` | Matching | 100.00% | 100 |
| `func_003B89E0` | Matching | 100.00% | 88 |
| `func_003B8A38` | Matching | 100.00% | 124 |
| `func_003B8AB8` | Matching | 100.00% | 32 |
| `func_003B8C00` | Matching | 100.00% | 200 |
| `func_003B8CC8` | Matching | 100.00% | 100 |
| `func_003B8D30` | Matching | 100.00% | 100 |
| `func_003B8D98` | Matching | 100.00% | 76 |
| `func_003B8DE8` | Matching | 100.00% | 252 |
| `func_003B8EE8` | Matching | 100.00% | 140 |
| `func_003B9140` | Matching | 100.00% | 160 |
| `func_003B91E0` | Matching | 100.00% | 488 |
| `func_003B93C8` | Matching | 100.00% | 228 |
| `func_003B97D8` | Matching | 100.00% | 168 |
| `func_003B9880` | Matching | 100.00% | 64 |
| `func_003B98C0` | Matching | 100.00% | 92 |
| `func_003B9920` | Matching | 100.00% | 220 |
| `func_003B9B68` | Matching | 100.00% | 184 |
| `func_003B9C20` | Matching | 100.00% | 220 |
| `func_003B9D00` | Matching | 100.00% | 200 |
| `func_003B9DC8` | Matching | 100.00% | 124 |
| `func_003B9E48` | Matching | 100.00% | 240 |
| `func_003B9F38` | Matching | 100.00% | 144 |
| `func_003B9FC8` | Matching | 100.00% | 88 |
| `func_003BA020` | Matching | 100.00% | 84 |
| `func_003BA078` | Matching | 100.00% | 56 |
| `func_003BA550` | Matching | 100.00% | 404 |
| `func_003BA6E8` | Matching | 100.00% | 88 |
| `func_003BA888` | Matching | 100.00% | 172 |
| `func_003BAA00` | Matching | 100.00% | 192 |
| `func_003BB0C8` | Matching | 100.00% | 116 |
| `func_003BBDA0` | Matching | 100.00% | 608 |
| `func_003BC000` | Matching | 100.00% | 176 |
| `func_003BC4C0` | Matching | 100.00% | 108 |
| `func_003BC530` | Matching | 100.00% | 60 |
| `func_003BC570` | Matching | 100.00% | 24 |
| `func_003BC588` | Matching | 100.00% | 60 |
| `func_003BC5C8` | Matching | 100.00% | 236 |
| `func_003BC6B8` | Matching | 100.00% | 180 |
| `func_003BC770` | Matching | 100.00% | 204 |
| `func_003BC840` | Matching | 100.00% | 204 |
| `func_003BC910` | Matching | 100.00% | 28 |
| `func_003BC930` | Matching | 100.00% | 52 |
| `func_003BC968` | Matching | 100.00% | 188 |
| `func_003BCA28` | Matching | 100.00% | 188 |
| `func_003BCAE8` | Matching | 100.00% | 180 |
| `func_003BD078` | Matching | 100.00% | 420 |
| `func_003BD220` | Matching | 100.00% | 916 |
| `func_003BD5B8` | Matching | 100.00% | 1032 |
| `func_003BD9C0` | Matching | 100.00% | 1096 |
| `func_003BECA0` | Matching | 100.00% | 140 |
| `func_003BF3E0` | Matching | 100.00% | 92 |
| `func_003BF440` | Matching | 100.00% | 124 |
| `func_003BF4C0` | Matching | 100.00% | 216 |
| `func_003BF5A0` | Matching | 100.00% | 272 |
| `func_003BF6B0` | Matching | 100.00% | 328 |
| `func_003BF800` | Matching | 100.00% | 208 |
| `func_003BF8D0` | Matching | 100.00% | 132 |
| `func_003BF960` | Matching | 100.00% | 352 |
| `func_003BFAC0` | Matching | 100.00% | 204 |
| `func_003BFB90` | Matching | 100.00% | 188 |
| `func_003BFC50` | Matching | 100.00% | 268 |
| `func_003BFD60` | Matching | 100.00% | 276 |
| `func_003BFE80` | Matching | 100.00% | 288 |
| `func_003BFFA0` | Matching | 100.00% | 512 |
| `func_003C01A0` | Matching | 100.00% | 572 |
| `func_003C04F0` | Matching | 100.00% | 116 |
| `func_003C0564` | Matching | 100.00% | 116 |
| `func_003C05E0` | Matching | 100.00% | 96 |
| `func_003C0640` | Matching | 100.00% | 112 |
| `func_003C06B0` | Matching | 100.00% | 244 |
| `func_003C07A8` | Matching | 100.00% | 172 |
| `func_003C0858` | Matching | 100.00% | 160 |
| `func_003C08F8` | Matching | 100.00% | 188 |
| `func_003C0A60` | Matching | 100.00% | 176 |
| `func_003C0BE8` | Matching | 100.00% | 48 |
| `func_003C0C18` | Matching | 100.00% | 120 |
| `func_003C0E28` | Matching | 100.00% | 1132 |
| `func_003C1298` | Matching | 100.00% | 732 |
| `func_003C1578` | Matching | 100.00% | 96 |
| `func_003C15D8` | Matching | 100.00% | 92 |
| `func_003C1980` | Matching | 100.00% | 36 |
| `func_003C2268` | Matching | 100.00% | 460 |
| `func_003C2438` | Matching | 100.00% | 8 |
| `func_003C2440` | Matching | 100.00% | 412 |
| `func_003C25E0` | Matching | 100.00% | 508 |
| `func_003C27E0` | Matching | 100.00% | 620 |
| `func_003C2A50` | Matching | 100.00% | 1144 |
| `func_003C3010` | Matching | 100.00% | 180 |
| `func_003C30C8` | Matching | 100.00% | 176 |
| `func_003C3250` | Matching | 100.00% | 176 |
| `func_003C3300` | Matching | 100.00% | 88 |
| `func_003C3358` | Matching | 100.00% | 40 |
| `func_003C33E0` | Matching | 100.00% | 112 |
| `func_003C3450` | Matching | 100.00% | 176 |
| `func_003C3500` | Matching | 100.00% | 248 |
| `func_003C35F8` | Matching | 100.00% | 176 |
| `func_003C36A8` | Matching | 100.00% | 32 |
| `func_003C36C8` | Matching | 100.00% | 96 |
| `func_003C3728` | Matching | 100.00% | 84 |
| `func_003C3EA8` | Matching | 100.00% | 56 |
| `func_003C3EE0` | Matching | 100.00% | 1016 |
| `func_003C42D8` | Matching | 100.00% | 28 |
| `func_003C42F8` | Matching | 100.00% | 28 |
| `func_003C43C0` | Matching | 100.00% | 140 |
| `func_003C4450` | Matching | 100.00% | 404 |
| `func_003C45E8` | Matching | 100.00% | 124 |
| `func_003C4898` | Matching | 100.00% | 128 |
| `func_003C4918` | Matching | 100.00% | 96 |
| `func_003C4978` | Matching | 100.00% | 188 |
| `func_003C4A38` | Matching | 100.00% | 188 |
| `func_003C4AF8` | Matching | 100.00% | 120 |
| `func_003C4EC8` | Matching | 100.00% | 416 |
| `func_003C5068` | Matching | 100.00% | 192 |
| `func_003C5128` | Matching | 100.00% | 180 |
| `func_003C51E0` | Matching | 100.00% | 8 |
| `func_003C52F8` | Matching | 100.00% | 56 |
| `func_003C5330` | Matching | 100.00% | 52 |
| `func_003C5368` | Matching | 100.00% | 56 |
| `func_003C53A0` | Matching | 100.00% | 56 |
| `func_003C53D8` | Matching | 100.00% | 56 |
| `func_003C5410` | Matching | 100.00% | 84 |
| `func_003C5468` | Matching | 100.00% | 84 |
| `func_003C54C0` | Matching | 100.00% | 120 |
| `func_003C5538` | Matching | 100.00% | 196 |
| `func_003C5600` | Matching | 100.00% | 68 |
| `func_003C5648` | Matching | 100.00% | 20 |
| `func_003C5660` | Matching | 100.00% | 176 |
| `func_003C5710` | Matching | 100.00% | 120 |
| `func_003C5788` | Matching | 100.00% | 104 |
| `func_003C57F0` | Matching | 100.00% | 144 |
| `func_003C5880` | Matching | 100.00% | 136 |
| `func_003C5908` | Matching | 100.00% | 140 |
| `func_003C5998` | Matching | 100.00% | 140 |
| `func_003C5A28` | Matching | 100.00% | 120 |
| `func_003C5AA0` | Matching | 100.00% | 8 |
| `func_003C5AA8` | Matching | 100.00% | 8 |
| `func_003C5AB0` | Matching | 100.00% | 8 |
| `func_003C5AB8` | Matching | 100.00% | 8 |
| `func_003C5AC0` | Matching | 100.00% | 56 |
| `func_003C5AF8` | Matching | 100.00% | 56 |
| `func_003C5B30` | Matching | 100.00% | 76 |
| `func_003C5B80` | Matching | 100.00% | 56 |
| `func_003C5BB8` | Matching | 100.00% | 56 |
| `func_003C5BF0` | Matching | 100.00% | 8 |
| `func_003C5BF8` | Matching | 100.00% | 56 |
| `func_003C5DF0` | Matching | 100.00% | 20 |
| `func_003C5E08` | Matching | 100.00% | 40 |
| `func_003C5E30` | Matching | 100.00% | 36 |
| `func_003C5E58` | Matching | 100.00% | 116 |
| `func_003C5ED0` | Matching | 100.00% | 72 |
| `func_003C5F18` | Matching | 100.00% | 88 |
| `func_003C5F70` | Matching | 100.00% | 92 |
| `func_003C5FD0` | Matching | 100.00% | 72 |
| `func_003C6018` | Matching | 100.00% | 40 |
| `func_003C6040` | Matching | 100.00% | 156 |
| `func_003C60E0` | Matching | 100.00% | 116 |
| `func_003C6240` | Matching | 100.00% | 52 |
| `func_003C6278` | Matching | 100.00% | 16 |
| `func_003C6288` | Matching | 100.00% | 48 |
| `func_003C62B8` | Matching | 100.00% | 48 |
| `func_003C62E8` | Matching | 100.00% | 56 |
| `func_003C6320` | Matching | 100.00% | 96 |
| `func_003C64A8` | Matching | 100.00% | 88 |
| `func_003C6500` | Matching | 100.00% | 64 |
| `func_003C6540` | Matching | 100.00% | 60 |
| `func_003C6580` | Matching | 100.00% | 96 |
| `func_003C65E0` | Matching | 100.00% | 12 |
| `func_003C65F0` | Matching | 100.00% | 48 |
| `func_003C6AB8` | Matching | 100.00% | 364 |
| `func_003C6C28` | Matching | 100.00% | 112 |
| `func_003C6C98` | Matching | 100.00% | 36 |
| `func_003C6CC0` | Matching | 100.00% | 32 |
| `func_003C6CE0` | Matching | 100.00% | 8 |
| `func_003C6CE8` | Matching | 100.00% | 180 |
| `func_003C6DA0` | Matching | 100.00% | 60 |
| `func_003C6DE0` | Matching | 100.00% | 560 |
| `func_003C7010` | Matching | 100.00% | 108 |
| `func_003C7138` | Matching | 100.00% | 224 |
| `func_003C7218` | Matching | 100.00% | 132 |
| `func_003C72A0` | Matching | 100.00% | 88 |
| `func_003C72F8` | Matching | 100.00% | 140 |
| `func_003C7388` | Matching | 100.00% | 244 |
| `func_003C7480` | Matching | 100.00% | 380 |
| `func_003C7600` | Matching | 100.00% | 552 |
| `func_003C7828` | Matching | 100.00% | 636 |
| `func_003C7AA8` | Matching | 100.00% | 8 |
| `func_003C7AB0` | Matching | 100.00% | 524 |
| `func_003C7CC0` | Matching | 100.00% | 28 |
| `func_003C7CE0` | Matching | 100.00% | 28 |
| `func_003C8018` | Matching | 100.00% | 268 |
| `func_003C8128` | Matching | 100.00% | 32 |
| `func_003C8148` | Matching | 100.00% | 12 |
| `func_003C83A0` | Matching | 100.00% | 144 |
| `func_003C8430` | Matching | 100.00% | 52 |
| `func_003C8468` | Matching | 100.00% | 248 |
| `func_003C8560` | Matching | 100.00% | 56 |
| `func_003C8598` | Matching | 100.00% | 56 |
| `func_003C85D0` | Matching | 100.00% | 920 |
| `func_003C8968` | Matching | 100.00% | 212 |
| `func_003C8A40` | Matching | 100.00% | 68 |
| `func_003C8B40` | Matching | 100.00% | 60 |
| `func_003C8B80` | Matching | 100.00% | 176 |
| `func_003C8C30` | Matching | 100.00% | 208 |
| `func_003C8E28` | Matching | 100.00% | 152 |
| `func_003C8EC0` | Matching | 100.00% | 132 |
| `func_003C8F48` | Matching | 100.00% | 104 |
| `func_003C8FB0` | Matching | 100.00% | 92 |
| `func_003C9010` | Matching | 100.00% | 44 |
| `func_003C9040` | Matching | 100.00% | 124 |
| `func_003C90C0` | Matching | 100.00% | 200 |
| `func_003C9188` | Matching | 100.00% | 220 |
| `func_003C9268` | Matching | 100.00% | 72 |
| `func_003C92B0` | Matching | 100.00% | 72 |
| `func_003C92F8` | Matching | 100.00% | 96 |
| `func_003C9358` | Matching | 100.00% | 8 |
| `func_003C9360` | Matching | 100.00% | 148 |
| `func_003C93F8` | Matching | 100.00% | 40 |
| `func_003C9420` | Matching | 100.00% | 244 |
| `func_003C9518` | Matching | 100.00% | 8 |
| `func_003C9520` | Matching | 100.00% | 208 |
| `func_003C95F0` | Matching | 100.00% | 40 |
| `func_003C9618` | Matching | 100.00% | 212 |
| `func_003C96F0` | Matching | 100.00% | 584 |
| `func_003C9938` | Matching | 100.00% | 40 |
| `func_003C9960` | Matching | 100.00% | 148 |
| `func_003C99F8` | Matching | 100.00% | 8 |
| `func_003C9A00` | Matching | 100.00% | 196 |
| `func_003C9AC8` | Matching | 100.00% | 60 |
| `func_003C9B08` | Matching | 100.00% | 8 |
| `func_003C9B10` | Matching | 100.00% | 184 |
| `func_003C9BC8` | Matching | 100.00% | 64 |
| `func_003C9C08` | Matching | 100.00% | 288 |
| `func_003C9D28` | Matching | 100.00% | 116 |
| `func_003C9DA0` | Matching | 100.00% | 172 |
| `func_003C9F58` | Matching | 100.00% | 160 |
| `func_003C9FF8` | Matching | 100.00% | 8 |
| `func_003CA000` | Matching | 100.00% | 40 |
| `func_003CA028` | Matching | 100.00% | 144 |
| `func_003CA358` | Matching | 100.00% | 8 |
| `func_003CA360` | Matching | 100.00% | 40 |
| `func_003CA460` | Matching | 100.00% | 392 |
| `func_003CA5E8` | Matching | 100.00% | 40 |
| `func_003CA610` | Matching | 100.00% | 148 |
| `func_003CA6A8` | Matching | 100.00% | 248 |
| `func_003CA7A0` | Matching | 100.00% | 20 |
| `func_003CA7B8` | Matching | 100.00% | 180 |
| `func_003CA870` | Matching | 100.00% | 48 |
| `func_003CA8A0` | Matching | 100.00% | 96 |
| `func_003CA900` | Matching | 100.00% | 140 |
| `func_003CA990` | Matching | 100.00% | 72 |
| `func_003CA9D8` | Matching | 100.00% | 76 |
| `func_003CADF0` | Matching | 100.00% | 172 |
| `func_003CB280` | Matching | 100.00% | 168 |
| `func_003CB4A8` | Matching | 100.00% | 124 |
| `func_003CB538` | Matching | 100.00% | 8 |
| `func_003CBB78` | Matching | 100.00% | 136 |
| `func_003CBC00` | Matching | 100.00% | 12 |
| `func_003CBC10` | Matching | 100.00% | 12 |
| `func_003CBC20` | Matching | 100.00% | 56 |
| `func_003CC878` | Matching | 100.00% | 156 |
| `func_003CC918` | Matching | 100.00% | 12 |
| `func_003CC928` | Matching | 100.00% | 12 |
| `func_003CC938` | Matching | 100.00% | 204 |
| `func_003CCA08` | Matching | 100.00% | 48 |
| `func_003CCA38` | Matching | 100.00% | 1204 |
| `func_003CCEF0` | Matching | 100.00% | 36 |
| `func_003CCF18` | Matching | 100.00% | 36 |
| `func_003CCF40` | Matching | 100.00% | 28 |
| `func_003CCF60` | Matching | 100.00% | 48 |
| `func_003CCF90` | Matching | 100.00% | 424 |
| `func_003CD138` | Matching | 100.00% | 88 |
| `func_003CD190` | Matching | 100.00% | 20 |
| `func_003CD1A8` | Matching | 100.00% | 36 |
| `func_003CD1D0` | Matching | 100.00% | 36 |
| `func_003CD1F8` | Matching | 100.00% | 104 |
| `func_003CD260` | Matching | 100.00% | 80 |
| `func_003CD518` | Matching | 100.00% | 120 |
| `func_003CD590` | Matching | 100.00% | 252 |
| `func_003CD690` | Matching | 100.00% | 96 |
| `func_003CDDB8` | Matching | 100.00% | 44 |
| `func_003CE078` | Matching | 100.00% | 64 |
| `func_003CE0B8` | Matching | 100.00% | 28 |
| `func_003CE0D8` | Matching | 100.00% | 8 |
| `func_003CE0E0` | Matching | 100.00% | 56 |
| `func_003CE118` | Matching | 100.00% | 124 |
| `func_003CE198` | Matching | 100.00% | 8 |
| `func_003CE1A0` | Matching | 100.00% | 8 |
| `func_003CE1A8` | Matching | 100.00% | 8 |
| `func_003CE1B0` | Matching | 100.00% | 456 |
| `func_003CE378` | Matching | 100.00% | 152 |
| `func_003CE410` | Matching | 100.00% | 940 |
| `func_003CEB90` | Matching | 100.00% | 84 |
| `func_003CEBE8` | Matching | 100.00% | 540 |
| `func_003CEE08` | Matching | 100.00% | 128 |
| `func_003CEE88` | Matching | 100.00% | 72 |
| `func_003CEED0` | Matching | 100.00% | 80 |
| `func_003CEF20` | Matching | 100.00% | 140 |
| `func_003CEFB0` | Matching | 100.00% | 72 |
| `func_003CEFF8` | Matching | 100.00% | 104 |
| `func_003CF060` | Matching | 100.00% | 200 |
| `func_003CF128` | Matching | 100.00% | 48 |
| `func_003CF158` | Matching | 100.00% | 28 |
| `func_003CF178` | Matching | 100.00% | 288 |
| `func_003CF298` | Matching | 100.00% | 40 |
| `func_003CF2C0` | Matching | 100.00% | 60 |
| `func_003CF300` | Matching | 100.00% | 260 |
| `func_003CF408` | Matching | 100.00% | 140 |
| `func_003CF498` | Matching | 100.00% | 56 |
| `func_003CF4D0` | Matching | 100.00% | 252 |
| `func_003CF5D0` | Matching | 100.00% | 256 |
| `func_003CF6D0` | Matching | 100.00% | 40 |
| `func_003CF6F8` | Matching | 100.00% | 72 |
| `func_003CF740` | Matching | 100.00% | 88 |
| `func_003CF798` | Matching | 100.00% | 24 |
| `func_003CF7B0` | Matching | 100.00% | 32 |
| `func_003CF7D0` | Matching | 100.00% | 388 |
| `func_003CF958` | Matching | 100.00% | 60 |
| `func_003CF998` | Matching | 100.00% | 60 |
| `func_003CF9D8` | Matching | 100.00% | 188 |
| `func_003CFA98` | Matching | 100.00% | 156 |
| `func_003CFB38` | Matching | 100.00% | 48 |
| `func_003CFB68` | Matching | 100.00% | 44 |
| `func_003CFB98` | Matching | 100.00% | 152 |
| `func_003D0B18` | Matching | 100.00% | 92 |
| `func_003D0B78` | Matching | 100.00% | 164 |
| `func_003D0C20` | Matching | 100.00% | 84 |
| `func_003D0C78` | Matching | 100.00% | 36 |
| `func_003D0CA0` | Matching | 100.00% | 36 |
| `func_003D0CC8` | Matching | 100.00% | 164 |
| `func_003D0D70` | Matching | 100.00% | 348 |
| `func_003D0ED0` | Matching | 100.00% | 356 |
| `func_003D11B8` | Matching | 100.00% | 696 |
| `func_003D1470` | Matching | 100.00% | 340 |
| `func_003D15C8` | Matching | 100.00% | 64 |
| `func_003D1608` | Matching | 100.00% | 76 |
| `func_003D1658` | Matching | 100.00% | 56 |
| `func_003D1690` | Matching | 100.00% | 56 |
| `func_003D16C8` | Matching | 100.00% | 8 |
| `func_003D16D0` | Matching | 100.00% | 12 |
| `func_003D16E0` | Matching | 100.00% | 8 |
| `func_003D16E8` | Matching | 100.00% | 8 |
| `func_003D1940` | Matching | 100.00% | 328 |
| `func_003D1A88` | Matching | 100.00% | 288 |
| `func_003D1E80` | Matching | 100.00% | 256 |
| `func_003D1F80` | Matching | 100.00% | 232 |
| `PATHI_copyevent` | Matching | 100.00% | 204 |
| `func_003D2138` | Matching | 100.00% | 136 |
| `func_003D21C0` | Matching | 100.00% | 88 |
| `func_003D2290` | Matching | 100.00% | 188 |
| `func_003D2C20` | Matching | 100.00% | 468 |
| `func_003D2DF8` | Matching | 100.00% | 420 |
| `func_003D2FA0` | Matching | 100.00% | 28 |
| `func_003D2FC0` | Matching | 100.00% | 28 |
| `func_003D3010` | Matching | 100.00% | 8 |
| `func_003D3018` | Matching | 100.00% | 20 |
| `func_003D3030` | Matching | 100.00% | 40 |
| `func_003D3058` | Matching | 100.00% | 76 |
| `func_003D30A8` | Matching | 100.00% | 152 |
| `func_003D3140` | Matching | 100.00% | 164 |
| `func_003D31E8` | Matching | 100.00% | 188 |
| `func_003D32A8` | Matching | 100.00% | 12 |
| `func_003D3C90` | Matching | 100.00% | 144 |
| `func_003D4050` | Matching | 100.00% | 340 |
| `func_003D4898` | Matching | 100.00% | 100 |
| `func_003D4900` | Matching | 100.00% | 80 |
| `func_003D4950` | Matching | 100.00% | 124 |
| `func_003D49D0` | Matching | 100.00% | 128 |
| `func_003D4A50` | Matching | 100.00% | 176 |
| `func_003D4BB0` | Matching | 100.00% | 144 |
| `func_003D4C40` | Matching | 100.00% | 720 |
| `func_003D4F10` | Matching | 100.00% | 532 |
| `func_003D5290` | Matching | 100.00% | 160 |
| `func_003D53B8` | Matching | 100.00% | 148 |
| `func_003D5450` | Matching | 100.00% | 116 |
| `func_003D5698` | Matching | 100.00% | 360 |
| `func_003D5800` | Matching | 100.00% | 360 |
| `func_003D5968` | Matching | 100.00% | 300 |
| `func_003D5A98` | Matching | 100.00% | 548 |
| `func_003D5CC0` | Matching | 100.00% | 552 |
| `func_003D5EE8` | Matching | 100.00% | 544 |
| `func_003D6108` | Matching | 100.00% | 220 |
| `func_003D61E8` | Matching | 100.00% | 220 |
| `func_003D62C8` | Matching | 100.00% | 80 |
| `func_003D6318` | Matching | 100.00% | 72 |
| `func_003D6360` | Matching | 100.00% | 20 |
| `func_003D6378` | Matching | 100.00% | 124 |
| `func_003D63F8` | Matching | 100.00% | 76 |
| `func_003D6448` | Matching | 100.00% | 76 |
| `func_003D3900` | Matching | 99.98% | 912 |
| `func_003D3D20` | Matching | 99.98% | 816 |
| `func_003B6300` | Matching | 99.96% | 472 |
| `func_003C5C30` | Matching | 99.96% | 448 |
| `func_003D1D28` | Matching | 99.94% | 340 |
| `func_003BB588` | Matching | 99.94% | 664 |
| `func_003B96B8` | Matching | 99.93% | 288 |
| `func_003B3BB0` | Matching | 99.93% | 284 |
| `func_003C4788` | Matching | 99.93% | 268 |
| `func_003BF0F0` | Matching | 99.92% | 752 |
| `func_003CAC88` | Matching | 99.89% | 360 |
| `func_003CC630` | Matching | 99.89% | 532 |
| `func_003B6788` | Matching | 99.87% | 152 |
| `func_003CA388` | Matching | 99.81% | 216 |
| `func_003CB1A8` | Matching | 99.81% | 216 |
| `func_003C7080` | Matching | 99.78% | 184 |
| `func_003B7838` | Matching | 99.75% | 160 |
| `func_003C0B10` | Matching | 99.72% | 212 |
| `func_003CDDE8` | Matching | 99.69% | 128 |
| `func_003B7E38` | Matching | 99.64% | 56 |
| `func_003CC848` | Matching | 99.58% | 48 |
| `func_003D2FE0` | Matching | 99.58% | 48 |
| `func_003CBB28` | Matching | 99.47% | 76 |
| `func_003CB110` | Matching | 99.46% | 148 |
| `func_003B7818` | Matching | 99.38% | 32 |
| `func_003B47F8` | Matching | 99.29% | 28 |
| `func_003D54C8` | Matching | 99.29% | 28 |
| `func_003D54E8` | Matching | 99.29% | 28 |
| `func_003CB528` | Matching | 97.50% | 16 |
| `func_003B7080` | Partial | 91.50% | 120 |

### `ealib/seg_2D7498`

100 matching, 0 partial, 12 not started (112 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003D6498` | Matching | 100.00% | 384 |
| `func_003D6618` | Matching | 100.00% | 164 |
| `func_003D66C0` | Matching | 100.00% | 48 |
| `func_003D66F0` | Matching | 100.00% | 88 |
| `func_003D6748` | Matching | 100.00% | 28 |
| `func_003D6768` | Matching | 100.00% | 12 |
| `func_003D6778` | Matching | 100.00% | 124 |
| `func_003D67F8` | Matching | 100.00% | 72 |
| `func_003D6840` | Matching | 100.00% | 252 |
| `func_003D6940` | Matching | 100.00% | 40 |
| `func_003D6968` | Matching | 100.00% | 32 |
| `func_003D6988` | Matching | 100.00% | 32 |
| `func_003D69A8` | Matching | 100.00% | 72 |
| `func_003D69F0` | Matching | 100.00% | 460 |
| `func_003D6BC0` | Matching | 100.00% | 148 |
| `func_003D6C58` | Matching | 100.00% | 8 |
| `func_003D6C60` | Matching | 100.00% | 64 |
| `func_003D6CA0` | Matching | 100.00% | 28 |
| `func_003D6CC0` | Matching | 100.00% | 52 |
| `func_003D6CF8` | Matching | 100.00% | 56 |
| `func_003D6D30` | Matching | 100.00% | 12 |
| `func_003D6D40` | Matching | 100.00% | 12 |
| `func_003D6D50` | Matching | 100.00% | 100 |
| `func_003D6DB8` | Matching | 100.00% | 120 |
| `func_003D6E30` | Matching | 100.00% | 180 |
| `func_003D6EE8` | Matching | 100.00% | 148 |
| `func_003D6F80` | Matching | 100.00% | 184 |
| `func_003D7038` | Matching | 100.00% | 116 |
| `func_003D70B0` | Matching | 100.00% | 92 |
| `func_003D7110` | Matching | 100.00% | 196 |
| `func_003D71D8` | Matching | 100.00% | 200 |
| `func_003D72A0` | Matching | 100.00% | 376 |
| `func_003D7B98` | Matching | 100.00% | 156 |
| `func_003D7C38` | Matching | 100.00% | 288 |
| `func_003D7EC8` | Matching | 100.00% | 316 |
| `func_003D8008` | Matching | 100.00% | 28 |
| `func_003D8028` | Matching | 100.00% | 24 |
| `func_003D8040` | Matching | 100.00% | 108 |
| `func_003D80B0` | Matching | 100.00% | 164 |
| `func_003D8158` | Matching | 100.00% | 24 |
| `func_003D8170` | Matching | 100.00% | 28 |
| `func_003D8190` | Matching | 100.00% | 96 |
| `func_003D81F0` | Matching | 100.00% | 132 |
| `func_003D8278` | Matching | 100.00% | 52 |
| `func_003D82B0` | Matching | 100.00% | 128 |
| `func_003D8330` | Matching | 100.00% | 136 |
| `func_003D83B8` | Matching | 100.00% | 164 |
| `func_003D8460` | Matching | 100.00% | 64 |
| `func_003D84A0` | Matching | 100.00% | 92 |
| `func_003D8500` | Matching | 100.00% | 44 |
| `func_003D8530` | Matching | 100.00% | 12 |
| `func_003D8540` | Matching | 100.00% | 84 |
| `func_003D8780` | Matching | 100.00% | 328 |
| `func_003D8CB0` | Matching | 100.00% | 420 |
| `func_003D8E58` | Matching | 100.00% | 556 |
| `func_003D9A40` | Matching | 100.00% | 132 |
| `func_003D9AC8` | Matching | 100.00% | 272 |
| `func_003DA3A8` | Matching | 100.00% | 20 |
| `func_003DA3C0` | Matching | 100.00% | 8 |
| `func_003DA3C8` | Matching | 100.00% | 40 |
| `func_003DA3F0` | Matching | 100.00% | 36 |
| `func_003DA4E0` | Matching | 100.00% | 148 |
| `func_003DA578` | Matching | 100.00% | 80 |
| `func_003DA5C8` | Matching | 100.00% | 232 |
| `func_003DA6B0` | Matching | 100.00% | 104 |
| `func_003DA718` | Matching | 100.00% | 56 |
| `func_003DA750` | Matching | 100.00% | 188 |
| `func_003DA810` | Matching | 100.00% | 52 |
| `func_003DA848` | Matching | 100.00% | 152 |
| `func_003DA8E0` | Matching | 100.00% | 44 |
| `func_003DA910` | Matching | 100.00% | 184 |
| `func_003DA9C8` | Matching | 100.00% | 68 |
| `func_003DAA10` | Matching | 100.00% | 60 |
| `func_003DAA50` | Matching | 100.00% | 92 |
| `func_003DAAB0` | Matching | 100.00% | 168 |
| `func_003DAB58` | Matching | 100.00% | 196 |
| `func_003DAC20` | Matching | 100.00% | 136 |
| `func_003DACA8` | Matching | 100.00% | 60 |
| `func_003DACE8` | Matching | 100.00% | 352 |
| `func_003DAE48` | Matching | 100.00% | 392 |
| `func_003DAFD0` | Matching | 100.00% | 52 |
| `func_003DB008` | Matching | 100.00% | 52 |
| `func_003DB040` | Matching | 100.00% | 452 |
| `func_003DB208` | Matching | 100.00% | 428 |
| `func_003DB3B8` | Matching | 100.00% | 40 |
| `func_003DB3E0` | Matching | 100.00% | 92 |
| `func_003DB440` | Matching | 100.00% | 144 |
| `func_003DB4D0` | Matching | 100.00% | 236 |
| `func_003DB790` | Matching | 100.00% | 168 |
| `func_003DB978` | Matching | 100.00% | 40 |
| `func_003DB9A0` | Matching | 100.00% | 52 |
| `func_003DB9D8` | Matching | 100.00% | 208 |
| `func_003DBAA8` | Matching | 100.00% | 28 |
| `func_003DBAC8` | Matching | 100.00% | 28 |
| `func_003D95B8` | Matching | 99.97% | 628 |
| `func_003DB5C0` | Matching | 99.91% | 460 |
| `func_003D7D58` | Matching | 99.89% | 364 |
| `func_003D76F0` | Matching | 99.82% | 112 |
| `func_003D7A50` | Matching | 99.81% | 324 |
| `func_003DA418` | Matching | 99.80% | 196 |

### `ealib/seg_2DCAE8`

302 matching, 0 partial, 27 not started (329 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003DBAE8` | Matching | 100.00% | 128 |
| `func_003DBB68` | Matching | 100.00% | 304 |
| `func_003DBC98` | Matching | 100.00% | 8 |
| `USTR_length` | Matching | 100.00% | 52 |
| `func_003DBCD8` | Matching | 100.00% | 60 |
| `func_003DBD18` | Matching | 100.00% | 148 |
| `func_003DBDB0` | Matching | 100.00% | 32 |
| `func_003DBDD0` | Matching | 100.00% | 76 |
| `USTR_copy` | Matching | 100.00% | 32 |
| `USTR_ncopy` | Matching | 100.00% | 76 |
| `func_003DBE90` | Matching | 100.00% | 60 |
| `func_003DBED0` | Matching | 100.00% | 28 |
| `func_003DBEF0` | Matching | 100.00% | 228 |
| `func_003DBFD8` | Matching | 100.00% | 96 |
| `func_003DC038` | Matching | 100.00% | 44 |
| `func_003DC068` | Matching | 100.00% | 224 |
| `func_003DC9F8` | Matching | 100.00% | 68 |
| `func_003DCB20` | Matching | 100.00% | 184 |
| `func_003DCBD8` | Matching | 100.00% | 172 |
| `func_003DCC88` | Matching | 100.00% | 268 |
| `func_003DCD98` | Matching | 100.00% | 72 |
| `func_003DCDE0` | Matching | 100.00% | 172 |
| `func_003DCE90` | Matching | 100.00% | 128 |
| `func_003DCF10` | Matching | 100.00% | 44 |
| `func_003DCF40` | Matching | 100.00% | 44 |
| `func_003DCF70` | Matching | 100.00% | 80 |
| `func_003DCFC0` | Matching | 100.00% | 388 |
| `func_003DD148` | Matching | 100.00% | 144 |
| `func_003DD310` | Matching | 100.00% | 292 |
| `func_003DD438` | Matching | 100.00% | 176 |
| `func_003DD4E8` | Matching | 100.00% | 184 |
| `func_003DD5A0` | Matching | 100.00% | 168 |
| `func_003DD648` | Matching | 100.00% | 212 |
| `func_003DD720` | Matching | 100.00% | 192 |
| `func_003DD7E0` | Matching | 100.00% | 152 |
| `func_003DD878` | Matching | 100.00% | 108 |
| `func_003DD8E8` | Matching | 100.00% | 292 |
| `func_003DDA10` | Matching | 100.00% | 172 |
| `func_003DDAC0` | Matching | 100.00% | 320 |
| `func_003DDC00` | Matching | 100.00% | 44 |
| `func_003DDC30` | Matching | 100.00% | 444 |
| `FILESYS_atomic` | Matching | 100.00% | 96 |
| `func_003DDE50` | Matching | 100.00% | 36 |
| `func_003DDE78` | Matching | 100.00% | 264 |
| `func_003DDF80` | Matching | 100.00% | 36 |
| `iFILESYS_CommandCompleteCallback` | Matching | 100.00% | 164 |
| `func_003DE4C8` | Matching | 100.00% | 8 |
| `FILESYS_bypassqueuefileinfo` | Matching | 100.00% | 408 |
| `func_003DE668` | Matching | 100.00% | 8 |
| `func_003DE7B0` | Matching | 100.00% | 80 |
| `func_003DE800` | Matching | 100.00% | 188 |
| `func_003DE8C0` | Matching | 100.00% | 80 |
| `func_003DE910` | Matching | 100.00% | 20 |
| `func_003DE928` | Matching | 100.00% | 140 |
| `func_003DE9B8` | Matching | 100.00% | 144 |
| `func_003DEA48` | Matching | 100.00% | 264 |
| `func_003DEC60` | Matching | 100.00% | 32 |
| `func_003DEC80` | Matching | 100.00% | 32 |
| `queueadd` | Matching | 100.00% | 104 |
| `func_003DEED8` | Matching | 100.00% | 100 |
| `func_003DEF40` | Matching | 100.00% | 48 |
| `func_003DEF70` | Matching | 100.00% | 76 |
| `releaserequest` | Matching | 100.00% | 104 |
| `func_003DF028` | Matching | 100.00% | 144 |
| `func_003DF0B8` | Matching | 100.00% | 52 |
| `func_003DF0F0` | Matching | 100.00% | 236 |
| `func_003DF1E0` | Matching | 100.00% | 220 |
| `func_003DF2C0` | Matching | 100.00% | 256 |
| `func_003DF3C0` | Matching | 100.00% | 196 |
| `func_003DF488` | Matching | 100.00% | 228 |
| `func_003DF690` | Matching | 100.00% | 180 |
| `func_003DF748` | Matching | 100.00% | 188 |
| `func_003DF808` | Matching | 100.00% | 220 |
| `func_003DF8E8` | Matching | 100.00% | 148 |
| `func_003DF980` | Matching | 100.00% | 88 |
| `func_003DFAF0` | Matching | 100.00% | 220 |
| `func_003DFBD0` | Matching | 100.00% | 56 |
| `func_003DFC08` | Matching | 100.00% | 64 |
| `func_003DFC48` | Matching | 100.00% | 144 |
| `func_003DFCD8` | Matching | 100.00% | 128 |
| `func_003DFD58` | Matching | 100.00% | 116 |
| `func_003DFDD0` | Matching | 100.00% | 72 |
| `func_003DFE18` | Matching | 100.00% | 112 |
| `func_003DFE88` | Matching | 100.00% | 72 |
| `func_003DFED0` | Matching | 100.00% | 520 |
| `func_003E00D8` | Matching | 100.00% | 60 |
| `func_003E0118` | Matching | 100.00% | 84 |
| `func_003E0170` | Matching | 100.00% | 252 |
| `func_003E06B0` | Matching | 100.00% | 40 |
| `func_003E06D8` | Matching | 100.00% | 624 |
| `func_003E0948` | Matching | 100.00% | 220 |
| `func_003E0A28` | Matching | 100.00% | 176 |
| `func_003E0AD8` | Matching | 100.00% | 80 |
| `func_003E0B28` | Matching | 100.00% | 108 |
| `func_003E0B98` | Matching | 100.00% | 96 |
| `func_003E0BF8` | Matching | 100.00% | 96 |
| `func_003E0C58` | Matching | 100.00% | 48 |
| `func_003E0C88` | Matching | 100.00% | 248 |
| `func_003E0D80` | Matching | 100.00% | 268 |
| `func_003E0E90` | Matching | 100.00% | 640 |
| `func_003E12E0` | Matching | 100.00% | 264 |
| `func_003E13E8` | Matching | 100.00% | 224 |
| `func_003E14C8` | Matching | 100.00% | 48 |
| `func_003E14F8` | Matching | 100.00% | 56 |
| `func_003E1580` | Matching | 100.00% | 56 |
| `func_003E15B8` | Matching | 100.00% | 48 |
| `func_003E15E8` | Matching | 100.00% | 196 |
| `func_003E16B0` | Matching | 100.00% | 76 |
| `func_003E1700` | Matching | 100.00% | 36 |
| `func_003E1728` | Matching | 100.00% | 108 |
| `func_003E1798` | Matching | 100.00% | 60 |
| `func_003E17D8` | Matching | 100.00% | 56 |
| `func_003E1810` | Matching | 100.00% | 184 |
| `FILE_load` | Matching | 100.00% | 64 |
| `func_003E1908` | Matching | 100.00% | 60 |
| `func_003E1948` | Matching | 100.00% | 196 |
| `func_003E1A10` | Matching | 100.00% | 96 |
| `FILE_loadsizez` | Matching | 100.00% | 92 |
| `func_003E1AD0` | Matching | 100.00% | 152 |
| `func_003E1B68` | Matching | 100.00% | 76 |
| `func_003E1BB8` | Matching | 100.00% | 72 |
| `func_003E1C00` | Matching | 100.00% | 148 |
| `func_003E1C98` | Matching | 100.00% | 104 |
| `func_003E1D00` | Matching | 100.00% | 104 |
| `func_003E1F48` | Matching | 100.00% | 232 |
| `func_003E2030` | Matching | 100.00% | 252 |
| `func_003E2130` | Matching | 100.00% | 56 |
| `func_003E2168` | Matching | 100.00% | 40 |
| `func_003E2190` | Matching | 100.00% | 348 |
| `func_003E22F0` | Matching | 100.00% | 28 |
| `FILE_loadpackatz` | Matching | 100.00% | 348 |
| `FILE_loadpackat` | Matching | 100.00% | 28 |
| `func_003E2490` | Matching | 100.00% | 112 |
| `BIG_typeofheader` | Matching | 100.00% | 128 |
| `BIG_sizeofheader` | Matching | 100.00% | 144 |
| `BIG_debuginfo` | Matching | 100.00% | 300 |
| `func_003E2740` | Matching | 100.00% | 40 |
| `func_003E2CE0` | Matching | 100.00% | 28 |
| `func_003E2D00` | Matching | 100.00% | 48 |
| `func_003E2D30` | Matching | 100.00% | 48 |
| `func_003E2D60` | Matching | 100.00% | 72 |
| `func_003E2DA8` | Matching | 100.00% | 72 |
| `func_003E2DF0` | Matching | 100.00% | 48 |
| `func_003E2E20` | Matching | 100.00% | 48 |
| `func_003E2E50` | Matching | 100.00% | 144 |
| `func_003E2EE0` | Matching | 100.00% | 140 |
| `func_003E2F70` | Matching | 100.00% | 84 |
| `func_003E2FC8` | Matching | 100.00% | 84 |
| `func_003E3020` | Matching | 100.00% | 120 |
| `func_003E3098` | Matching | 100.00% | 368 |
| `func_003E3208` | Matching | 100.00% | 236 |
| `func_003E32F8` | Matching | 100.00% | 88 |
| `func_003E3350` | Matching | 100.00% | 92 |
| `func_003E33B0` | Matching | 100.00% | 200 |
| `func_003E3478` | Matching | 100.00% | 108 |
| `func_003E34E8` | Matching | 100.00% | 80 |
| `func_003E3538` | Matching | 100.00% | 76 |
| `func_003E3588` | Matching | 100.00% | 36 |
| `func_003E35B0` | Matching | 100.00% | 104 |
| `func_003E3618` | Matching | 100.00% | 224 |
| `func_003E36F8` | Matching | 100.00% | 92 |
| `func_003E3968` | Matching | 100.00% | 64 |
| `func_003E39A8` | Matching | 100.00% | 300 |
| `func_003E3AD8` | Matching | 100.00% | 36 |
| `func_003E44B0` | Matching | 100.00% | 88 |
| `func_003E48D8` | Matching | 100.00% | 140 |
| `func_003E4968` | Matching | 100.00% | 80 |
| `func_003E49B8` | Matching | 100.00% | 84 |
| `func_003E4A10` | Matching | 100.00% | 32 |
| `func_003E4A30` | Matching | 100.00% | 112 |
| `func_003E4AA0` | Matching | 100.00% | 80 |
| `func_003E4D68` | Matching | 100.00% | 80 |
| `func_003E4E98` | Matching | 100.00% | 16 |
| `func_003E4EA8` | Matching | 100.00% | 64 |
| `func_003E4EE8` | Matching | 100.00% | 28 |
| `func_003E4F08` | Matching | 100.00% | 56 |
| `func_003E4F40` | Matching | 100.00% | 60 |
| `func_003E4F80` | Matching | 100.00% | 48 |
| `func_003E4FB0` | Matching | 100.00% | 84 |
| `func_003E5008` | Matching | 100.00% | 12 |
| `func_003E5018` | Matching | 100.00% | 76 |
| `func_003E5068` | Matching | 100.00% | 48 |
| `func_003E5098` | Matching | 100.00% | 44 |
| `func_003E50C8` | Matching | 100.00% | 212 |
| `func_003E51A0` | Matching | 100.00% | 200 |
| `func_003E5268` | Matching | 100.00% | 28 |
| `func_003E5288` | Matching | 100.00% | 8 |
| `func_003E5290` | Matching | 100.00% | 28 |
| `THREAD_yieldticks` | Matching | 100.00% | 228 |
| `func_003E5398` | Matching | 100.00% | 168 |
| `func_003E5440` | Matching | 100.00% | 84 |
| `func_003E5498` | Matching | 100.00% | 108 |
| `func_003E5508` | Matching | 100.00% | 120 |
| `func_003E5580` | Matching | 100.00% | 96 |
| `func_003E55E0` | Matching | 100.00% | 152 |
| `func_003E5678` | Matching | 100.00% | 28 |
| `func_003E5698` | Matching | 100.00% | 68 |
| `func_003E56E0` | Matching | 100.00% | 28 |
| `MUTEX_lock` | Matching | 100.00% | 96 |
| `MUTEX_unlock` | Matching | 100.00% | 108 |
| `SYNCTASK_init` | Matching | 100.00% | 40 |
| `SYNCTASK_add` | Matching | 100.00% | 204 |
| `SYNCTASK_del` | Matching | 100.00% | 96 |
| `func_003E5A10` | Matching | 100.00% | 100 |
| `func_003E5A78` | Matching | 100.00% | 48 |
| `func_003E5AA8` | Matching | 100.00% | 184 |
| `func_003E5B60` | Matching | 100.00% | 256 |
| `func_003E5C60` | Matching | 100.00% | 24 |
| `func_003E5C78` | Matching | 100.00% | 184 |
| `func_003E5D30` | Matching | 100.00% | 68 |
| `func_003E5D78` | Matching | 100.00% | 80 |
| `func_003E5DC8` | Matching | 100.00% | 108 |
| `func_003E5E38` | Matching | 100.00% | 80 |
| `func_003E5E88` | Matching | 100.00% | 108 |
| `func_003E5EF8` | Matching | 100.00% | 76 |
| `func_003E5F48` | Matching | 100.00% | 76 |
| `func_003E5F98` | Matching | 100.00% | 84 |
| `func_003E5FF0` | Matching | 100.00% | 124 |
| `REAL_abortmessage` | Matching | 100.00% | 120 |
| `SYSTEM_abortmessage` | Matching | 100.00% | 160 |
| `func_003E6188` | Matching | 100.00% | 112 |
| `func_003E61F8` | Matching | 100.00% | 36 |
| `func_003E6220` | Matching | 100.00% | 32 |
| `func_003E6240` | Matching | 100.00% | 112 |
| `func_003E62B0` | Matching | 100.00% | 28 |
| `func_003E62D0` | Matching | 100.00% | 84 |
| `func_003E6328` | Matching | 100.00% | 252 |
| `func_003E6428` | Matching | 100.00% | 28 |
| `func_003E6690` | Matching | 100.00% | 96 |
| `func_003E67F8` | Matching | 100.00% | 128 |
| `func_003E6878` | Matching | 100.00% | 220 |
| `func_003E6958` | Matching | 100.00% | 280 |
| `func_003E6A70` | Matching | 100.00% | 156 |
| `func_003E6B10` | Matching | 100.00% | 368 |
| `func_003E6C80` | Matching | 100.00% | 248 |
| `func_003E6D78` | Matching | 100.00% | 144 |
| `func_003E6E08` | Matching | 100.00% | 100 |
| `func_003E6E70` | Matching | 100.00% | 104 |
| `func_003E6ED8` | Matching | 100.00% | 104 |
| `func_003E6F40` | Matching | 100.00% | 136 |
| `func_003E6FC8` | Matching | 100.00% | 112 |
| `func_003E7038` | Matching | 100.00% | 124 |
| `func_003E70B8` | Matching | 100.00% | 104 |
| `func_003E7120` | Matching | 100.00% | 144 |
| `func_003E71B0` | Matching | 100.00% | 104 |
| `func_003E7218` | Matching | 100.00% | 136 |
| `func_003E72A0` | Matching | 100.00% | 160 |
| `func_003E7340` | Matching | 100.00% | 156 |
| `func_003E73E0` | Matching | 100.00% | 112 |
| `func_003E7450` | Matching | 100.00% | 148 |
| `func_003E76A8` | Matching | 100.00% | 108 |
| `func_003E7718` | Matching | 100.00% | 212 |
| `func_003E77F0` | Matching | 100.00% | 292 |
| `func_003E7918` | Matching | 100.00% | 420 |
| `func_003E7AC0` | Matching | 100.00% | 64 |
| `func_003E7B00` | Matching | 100.00% | 160 |
| `func_003E7BA0` | Matching | 100.00% | 160 |
| `func_003E7C40` | Matching | 100.00% | 788 |
| `func_003E7F58` | Matching | 100.00% | 24 |
| `func_003E7F70` | Matching | 100.00% | 124 |
| `func_003E7FF0` | Matching | 100.00% | 204 |
| `func_003E80C0` | Matching | 100.00% | 264 |
| `func_003E81C8` | Matching | 100.00% | 124 |
| `func_003E8248` | Matching | 100.00% | 24 |
| `func_003E8260` | Matching | 100.00% | 260 |
| `func_003E8368` | Matching | 100.00% | 580 |
| `func_003E85B0` | Matching | 100.00% | 156 |
| `func_003E8650` | Matching | 100.00% | 56 |
| `func_003E8688` | Matching | 100.00% | 236 |
| `func_003E8778` | Matching | 100.00% | 496 |
| `func_003E8968` | Matching | 100.00% | 192 |
| `func_003E8A28` | Matching | 100.00% | 72 |
| `func_003E8A70` | Matching | 100.00% | 136 |
| `func_003E8AF8` | Matching | 100.00% | 24 |
| `func_003E8B10` | Matching | 100.00% | 608 |
| `func_003E8D70` | Matching | 100.00% | 80 |
| `func_003E8DC0` | Matching | 100.00% | 328 |
| `func_003E8F08` | Matching | 100.00% | 176 |
| `func_003E8FB8` | Matching | 100.00% | 24 |
| `func_003E8FD0` | Matching | 100.00% | 396 |
| `func_003E9378` | Matching | 100.00% | 376 |
| `func_003E94F0` | Matching | 100.00% | 160 |
| `func_003E9590` | Matching | 100.00% | 52 |
| `func_003EAE68` | Matching | 100.00% | 80 |
| `func_003EAEB8` | Matching | 100.00% | 468 |
| `func_003EB090` | Matching | 100.00% | 256 |
| `func_003EB190` | Matching | 100.00% | 8 |
| `USTR_vsprintf` | Matching | 99.99% | 1448 |
| `ASYNCFILE_release` | Matching | 99.93% | 280 |
| `func_003E7500` | Matching | 99.90% | 420 |
| `func_003DEB50` | Matching | 99.87% | 156 |
| `func_003DEBF0` | Matching | 99.82% | 112 |
| `func_003DED50` | Matching | 99.82% | 112 |
| `func_003DE670` | Matching | 99.81% | 320 |
| `func_003DECA0` | Matching | 99.76% | 84 |
| `func_003DECF8` | Matching | 99.76% | 84 |
| `func_003DEDC0` | Matching | 99.76% | 84 |
| `func_003DEE18` | Matching | 99.76% | 84 |
| `func_003E4000` | Matching | 99.67% | 60 |
| `func_003E3B00` | Matching | 99.64% | 220 |
| `func_003E1EC8` | Matching | 99.38% | 64 |
| `func_003E1F08` | Matching | 99.33% | 60 |

### `fe/all_in_one_fe`

146 matching, 0 partial, 8 not started (154 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_0021C640` | Matching | 100.00% | 56 |
| `func_0021C678` | Matching | 100.00% | 92 |
| `func_0021C6D8` | Matching | 100.00% | 40 |
| `func_0021C700` | Matching | 100.00% | 8 |
| `func_0021C708` | Matching | 100.00% | 40 |
| `func_0021C730` | Matching | 100.00% | 104 |
| `func_0021C798` | Matching | 100.00% | 40 |
| `func_0021C7C0` | Matching | 100.00% | 104 |
| `func_0021C828` | Matching | 100.00% | 28 |
| `func_0021C848` | Matching | 100.00% | 40 |
| `func_0021C870` | Matching | 100.00% | 40 |
| `func_0021C898` | Matching | 100.00% | 104 |
| `func_0021C900` | Matching | 100.00% | 40 |
| `func_0021C928` | Matching | 100.00% | 40 |
| `func_0021C950` | Matching | 100.00% | 112 |
| `func_0021C9C0` | Matching | 100.00% | 40 |
| `func_0021C9E8` | Matching | 100.00% | 40 |
| `func_0021CA10` | Matching | 100.00% | 40 |
| `func_0021CA38` | Matching | 100.00% | 40 |
| `func_0021CA60` | Matching | 100.00% | 40 |
| `func_0021CA88` | Matching | 100.00% | 28 |
| `func_0021CAA8` | Matching | 100.00% | 52 |
| `func_0021CAE0` | Matching | 100.00% | 40 |
| `func_0021CB08` | Matching | 100.00% | 56 |
| `func_0021CB40` | Matching | 100.00% | 40 |
| `func_0021CB68` | Matching | 100.00% | 8 |
| `func_0021CB70` | Matching | 100.00% | 32 |
| `func_0021CB90` | Matching | 100.00% | 8 |
| `func_0021CB98` | Matching | 100.00% | 8 |
| `func_0021CBA0` | Matching | 100.00% | 156 |
| `func_0021CC40` | Matching | 100.00% | 132 |
| `func_0021CCC8` | Matching | 100.00% | 20 |
| `func_0021CCE0` | Matching | 100.00% | 40 |
| `func_0021CD08` | Matching | 100.00% | 104 |
| `func_0021CD70` | Matching | 100.00% | 40 |
| `func_0021CD98` | Matching | 100.00% | 104 |
| `func_0021CE00` | Matching | 100.00% | 40 |
| `func_0021CE28` | Matching | 100.00% | 104 |
| `func_0021CE90` | Matching | 100.00% | 40 |
| `func_0021CEB8` | Matching | 100.00% | 128 |
| `func_0021CF38` | Matching | 100.00% | 40 |
| `func_0021CF60` | Matching | 100.00% | 128 |
| `func_0021CFE0` | Matching | 100.00% | 40 |
| `func_0021D008` | Matching | 100.00% | 104 |
| `func_0021D070` | Matching | 100.00% | 96 |
| `func_0021D0D0` | Matching | 100.00% | 104 |
| `func_0021D138` | Matching | 100.00% | 40 |
| `func_0021D160` | Matching | 100.00% | 64 |
| `func_0021E750` | Matching | 100.00% | 88 |
| `func_0021E7A8` | Matching | 100.00% | 52 |
| `func_0021E7E0` | Matching | 100.00% | 540 |
| `func_0021F338` | Matching | 100.00% | 808 |
| `func_00220AD0` | Matching | 100.00% | 616 |
| `func_00220D38` | Matching | 100.00% | 56 |
| `func_00220D70` | Matching | 100.00% | 40 |
| `func_00220D98` | Matching | 100.00% | 56 |
| `func_00220DD0` | Matching | 100.00% | 40 |
| `func_00220DF8` | Matching | 100.00% | 56 |
| `func_00220E30` | Matching | 100.00% | 40 |
| `func_00220E58` | Matching | 100.00% | 56 |
| `func_00220E90` | Matching | 100.00% | 40 |
| `func_00220EB8` | Matching | 100.00% | 40 |
| `func_00220EE0` | Matching | 100.00% | 104 |
| `func_00220F48` | Matching | 100.00% | 96 |
| `func_00220FA8` | Matching | 100.00% | 112 |
| `func_00221018` | Matching | 100.00% | 40 |
| `func_00221040` | Matching | 100.00% | 96 |
| `func_002210A0` | Matching | 100.00% | 112 |
| `func_00221110` | Matching | 100.00% | 40 |
| `func_00221138` | Matching | 100.00% | 40 |
| `func_00221160` | Matching | 100.00% | 104 |
| `func_002211C8` | Matching | 100.00% | 96 |
| `func_00221228` | Matching | 100.00% | 112 |
| `func_00221298` | Matching | 100.00% | 40 |
| `func_002212C0` | Matching | 100.00% | 8 |
| `func_002212C8` | Matching | 100.00% | 132 |
| `func_00221350` | Matching | 100.00% | 136 |
| `func_002213D8` | Matching | 100.00% | 40 |
| `func_00221400` | Matching | 100.00% | 8 |
| `func_00221408` | Matching | 100.00% | 96 |
| `func_00221468` | Matching | 100.00% | 104 |
| `func_002214D0` | Matching | 100.00% | 40 |
| `func_002214F8` | Matching | 100.00% | 96 |
| `func_00221558` | Matching | 100.00% | 108 |
| `func_002215C8` | Matching | 100.00% | 40 |
| `func_002215F0` | Matching | 100.00% | 100 |
| `func_00221658` | Matching | 100.00% | 108 |
| `func_002216C8` | Matching | 100.00% | 40 |
| `func_002216F0` | Matching | 100.00% | 100 |
| `func_00221758` | Matching | 100.00% | 108 |
| `func_002217C8` | Matching | 100.00% | 40 |
| `func_002217F0` | Matching | 100.00% | 100 |
| `func_00221858` | Matching | 100.00% | 108 |
| `func_002218C8` | Matching | 100.00% | 40 |
| `func_002218F0` | Matching | 100.00% | 100 |
| `func_00221958` | Matching | 100.00% | 108 |
| `func_002219C8` | Matching | 100.00% | 40 |
| `func_002219F0` | Matching | 100.00% | 100 |
| `func_00221A58` | Matching | 100.00% | 108 |
| `func_00221AC8` | Matching | 100.00% | 40 |
| `func_00221AF0` | Matching | 100.00% | 100 |
| `func_00221B58` | Matching | 100.00% | 108 |
| `func_00221BC8` | Matching | 100.00% | 40 |
| `func_00221BF0` | Matching | 100.00% | 40 |
| `func_00221C18` | Matching | 100.00% | 104 |
| `func_00221C80` | Matching | 100.00% | 96 |
| `func_00221CE0` | Matching | 100.00% | 116 |
| `func_00221D58` | Matching | 100.00% | 40 |
| `func_00221D80` | Matching | 100.00% | 8 |
| `func_00221D88` | Matching | 100.00% | 40 |
| `func_00221DB0` | Matching | 100.00% | 60 |
| `func_00221DF0` | Matching | 100.00% | 40 |
| `func_00221E18` | Matching | 100.00% | 104 |
| `func_00221E80` | Matching | 100.00% | 40 |
| `func_00221EA8` | Matching | 100.00% | 104 |
| `func_00221F10` | Matching | 100.00% | 40 |
| `func_00221F38` | Matching | 100.00% | 104 |
| `func_00221FA0` | Matching | 100.00% | 40 |
| `func_00221FC8` | Matching | 100.00% | 104 |
| `func_00222030` | Matching | 100.00% | 40 |
| `func_00222058` | Matching | 100.00% | 60 |
| `func_00222098` | Matching | 100.00% | 40 |
| `func_002220C0` | Matching | 100.00% | 60 |
| `func_00222100` | Matching | 100.00% | 96 |
| `func_00222160` | Matching | 100.00% | 104 |
| `func_002221C8` | Matching | 100.00% | 40 |
| `func_002221F0` | Matching | 100.00% | 40 |
| `func_00222218` | Matching | 100.00% | 104 |
| `func_00222280` | Matching | 100.00% | 40 |
| `func_002222A8` | Matching | 100.00% | 8 |
| `func_002222B0` | Matching | 100.00% | 8 |
| `func_002222B8` | Matching | 100.00% | 60 |
| `func_002222F8` | Matching | 100.00% | 96 |
| `func_00222358` | Matching | 100.00% | 104 |
| `func_002223C0` | Matching | 100.00% | 40 |
| `func_002223E8` | Matching | 100.00% | 64 |
| `func_00222448` | Matching | 100.00% | 84 |
| `func_002224A0` | Matching | 100.00% | 8 |
| `func_002224A8` | Matching | 100.00% | 8 |
| `func_002224B0` | Matching | 100.00% | 8 |
| `func_002224B8` | Matching | 100.00% | 396 |
| `func_00222648` | Matching | 100.00% | 388 |
| `func_0021F660` | Matching | 99.95% | 844 |
| `func_0021F9B0` | Matching | 99.89% | 900 |
| `func_0021E1B0` | Matching | 99.86% | 1436 |
| `func_00222428` | Matching | 99.38% | 32 |

### `fe/debugfe`

84 matching, 0 partial, 4 not started (88 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_0017D008` | Matching | 100.00% | 160 |
| `func_0017D0A8` | Matching | 100.00% | 272 |
| `func_0017D1B8` | Matching | 100.00% | 72 |
| `func_0017D200` | Matching | 100.00% | 96 |
| `func_0017D260` | Matching | 100.00% | 56 |
| `func_0017D298` | Matching | 100.00% | 276 |
| `func_0017D3B0` | Matching | 100.00% | 728 |
| `func_0017D688` | Matching | 100.00% | 104 |
| `func_0017D6F0` | Matching | 100.00% | 832 |
| `func_0017DA30` | Matching | 100.00% | 232 |
| `func_0017DB18` | Matching | 100.00% | 856 |
| `func_0017DE70` | Matching | 100.00% | 448 |
| `func_0017E030` | Matching | 100.00% | 232 |
| `func_0017E118` | Matching | 100.00% | 168 |
| `func_0017E1C0` | Matching | 100.00% | 104 |
| `func_0017E228` | Matching | 100.00% | 104 |
| `func_0017E290` | Matching | 100.00% | 104 |
| `func_0017E2F8` | Matching | 100.00% | 108 |
| `func_0017E368` | Matching | 100.00% | 80 |
| `func_0017E3B8` | Matching | 100.00% | 92 |
| `func_0017E418` | Matching | 100.00% | 116 |
| `func_0017E490` | Matching | 100.00% | 96 |
| `func_0017E4F0` | Matching | 100.00% | 104 |
| `func_0017E558` | Matching | 100.00% | 108 |
| `func_0017F7B8` | Matching | 100.00% | 128 |
| `func_0017F838` | Matching | 100.00% | 48 |
| `func_0017FA60` | Matching | 100.00% | 76 |
| `func_0017FAB0(void*)` | Matching | 100.00% | 32 |
| `func_0017FAD0` | Matching | 100.00% | 196 |
| `func_0017FB98` | Matching | 100.00% | 84 |
| `func_0017FDF0` | Matching | 100.00% | 140 |
| `func_0017FE80(void*)` | Matching | 100.00% | 32 |
| `func_0017FEA0(void*)` | Matching | 100.00% | 32 |
| `func_0017FEC0(void*)` | Matching | 100.00% | 32 |
| `func_0017FEE0(void*)` | Matching | 100.00% | 32 |
| `func_0017FF00(void*)` | Matching | 100.00% | 32 |
| `func_0017FF20(void*)` | Matching | 100.00% | 32 |
| `func_0017FF40(void*)` | Matching | 100.00% | 32 |
| `func_0017FF60(void*)` | Matching | 100.00% | 32 |
| `func_0017FF80(void*)` | Matching | 100.00% | 32 |
| `func_0017FFA0(void*)` | Matching | 100.00% | 32 |
| `func_0017FFC0(void*)` | Matching | 100.00% | 32 |
| `func_0017FFE0(void*)` | Matching | 100.00% | 32 |
| `func_00180000(void*)` | Matching | 100.00% | 32 |
| `func_00180020(void*)` | Matching | 100.00% | 32 |
| `func_00180040(void*)` | Matching | 100.00% | 32 |
| `func_00180060(void*)` | Matching | 100.00% | 32 |
| `func_00180080(void*)` | Matching | 100.00% | 32 |
| `func_001800A0(void*)` | Matching | 100.00% | 32 |
| `func_001800C0(void*)` | Matching | 100.00% | 32 |
| `func_001800E0(void*)` | Matching | 100.00% | 32 |
| `func_00180100(void*)` | Matching | 100.00% | 32 |
| `func_00180120(void*)` | Matching | 100.00% | 32 |
| `func_00180140(void*)` | Matching | 100.00% | 32 |
| `func_00180160(void*)` | Matching | 100.00% | 32 |
| `func_00180180(void*)` | Matching | 100.00% | 32 |
| `func_001801A0(void*)` | Matching | 100.00% | 32 |
| `func_001801C0(void*)` | Matching | 100.00% | 32 |
| `func_001801E0(void*)` | Matching | 100.00% | 32 |
| `func_00180200(void*)` | Matching | 100.00% | 32 |
| `func_00180220(void*)` | Matching | 100.00% | 32 |
| `func_00180240(void*)` | Matching | 100.00% | 32 |
| `func_00180260(void*)` | Matching | 100.00% | 32 |
| `func_00180280(void*)` | Matching | 100.00% | 32 |
| `func_001802A0(void*)` | Matching | 100.00% | 32 |
| `func_001802C0(void*)` | Matching | 100.00% | 32 |
| `func_001802E0(void*)` | Matching | 100.00% | 32 |
| `func_00180300` | Matching | 100.00% | 372 |
| `func_00180478` | Matching | 100.00% | 32 |
| `func_00180498` | Matching | 100.00% | 32 |
| `func_001804B8` | Matching | 100.00% | 80 |
| `func_00180508` | Matching | 100.00% | 204 |
| `func_001805D8` | Matching | 100.00% | 64 |
| `func_00180618` | Matching | 100.00% | 96 |
| `func_00180678` | Matching | 100.00% | 96 |
| `func_001806D8` | Matching | 100.00% | 140 |
| `func_00180768` | Matching | 100.00% | 92 |
| `func_001807C8` | Matching | 100.00% | 16 |
| `func_00180840` | Matching | 100.00% | 364 |
| `func_001809B0` | Matching | 100.00% | 220 |
| `func_00180A90` | Matching | 100.00% | 204 |
| `func_0017FBF0` | Matching | 99.96% | 508 |
| `func_0017F868` | Matching | 99.96% | 500 |
| `func_0017F2D0` | Matching | 99.75% | 560 |

### `fe/feasyncfile`

524 matching, 0 partial, 12 not started (536 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEAsyncManager_Load3PeakPic` | Matching | 100.00% | 124 |
| `cFEAsyncManager_Load1PeakPic` | Matching | 100.00% | 140 |
| `func_001A37F8` | Matching | 100.00% | 200 |
| `cFEAsyncManager_UnloadFEAsyncFile` | Matching | 100.00% | 252 |
| `cFEAsyncManager_GetFileStatus(cFEAsyncManager*, int)` | Matching | 100.00% | 20 |
| `cFEAsyncManager_SetFileStatus(cFEAsyncManager*, int, int)` | Matching | 100.00% | 20 |
| `func_001A39F0` | Matching | 100.00% | 512 |
| `func_001A3BF0` | Matching | 100.00% | 92 |
| `func_001A3C50` | Matching | 100.00% | 136 |
| `cFEAsyncManager_LoadDataFile` | Matching | 100.00% | 240 |
| `func_001A3DC8` | Matching | 100.00% | 104 |
| `func_001A3E30` | Matching | 100.00% | 108 |
| `func_001A3EA0` | Matching | 100.00% | 196 |
| `func_001A3F68` | Matching | 100.00% | 116 |
| `func_001A3FE0` | Matching | 100.00% | 96 |
| `func_001A4040` | Matching | 100.00% | 304 |
| `func_001A4170` | Matching | 100.00% | 80 |
| `func_001A41C0` | Matching | 100.00% | 320 |
| `func_001A4300` | Matching | 100.00% | 48 |
| `func_001A4330` | Matching | 100.00% | 828 |
| `func_001A4670` | Matching | 100.00% | 204 |
| `func_001A4740` | Matching | 100.00% | 12 |
| `func_001A4750` | Matching | 100.00% | 192 |
| `func_001A4810` | Matching | 100.00% | 280 |
| `func_001A4928` | Matching | 100.00% | 116 |
| `func_001A49A0` | Matching | 100.00% | 384 |
| `func_001A4B20` | Matching | 100.00% | 308 |
| `func_001A4C58` | Matching | 100.00% | 144 |
| `func_001A4CE8` | Matching | 100.00% | 168 |
| `func_001A4D90` | Matching | 100.00% | 152 |
| `func_001A4E28` | Matching | 100.00% | 388 |
| `func_001A4FB0` | Matching | 100.00% | 96 |
| `func_001A5010` | Matching | 100.00% | 280 |
| `func_001A5128` | Matching | 100.00% | 392 |
| `func_001A52B0` | Matching | 100.00% | 412 |
| `func_001A5450` | Matching | 100.00% | 132 |
| `func_001A54D8` | Matching | 100.00% | 500 |
| `func_001A56D0` | Matching | 100.00% | 152 |
| `func_001A5768` | Matching | 100.00% | 152 |
| `func_001A5800` | Matching | 100.00% | 152 |
| `func_001A5FB8` | Matching | 100.00% | 180 |
| `func_001A6070` | Matching | 100.00% | 856 |
| `func_001A63C8` | Matching | 100.00% | 592 |
| `func_001A6618` | Matching | 100.00% | 140 |
| `func_001A66A8` | Matching | 100.00% | 716 |
| `func_001A6978` | Matching | 100.00% | 712 |
| `func_001A6C40` | Matching | 100.00% | 96 |
| `func_001A6CA0` | Matching | 100.00% | 464 |
| `func_001A6E70` | Matching | 100.00% | 256 |
| `func_001A6F70` | Matching | 100.00% | 572 |
| `func_001A71B0` | Matching | 100.00% | 480 |
| `func_001A7390` | Matching | 100.00% | 1040 |
| `func_001A77A0` | Matching | 100.00% | 164 |
| `func_001A7848` | Matching | 100.00% | 296 |
| `func_001A7970` | Matching | 100.00% | 432 |
| `func_001A7B20(void*)` | Matching | 100.00% | 28 |
| `func_001A7B40` | Matching | 100.00% | 108 |
| `func_001A7BB0(void*)` | Matching | 100.00% | 8 |
| `func_001A7BB8` | Matching | 100.00% | 344 |
| `func_001A7D10` | Matching | 100.00% | 48 |
| `func_001A7D40` | Matching | 100.00% | 76 |
| `func_001A7D90` | Matching | 100.00% | 72 |
| `func_001A7DD8` | Matching | 100.00% | 252 |
| `func_001A7ED8` | Matching | 100.00% | 160 |
| `func_001A7F78` | Matching | 100.00% | 632 |
| `func_001A81F0` | Matching | 100.00% | 488 |
| `func_001A83D8` | Matching | 100.00% | 292 |
| `func_001A8500` | Matching | 100.00% | 204 |
| `func_001A86E8` | Matching | 100.00% | 124 |
| `func_001A8768(void*)` | Matching | 100.00% | 8 |
| `func_001A8770` | Matching | 100.00% | 96 |
| `func_001A87D0` | Matching | 100.00% | 84 |
| `func_001A8828(void*)` | Matching | 100.00% | 8 |
| `func_001A8830` | Matching | 100.00% | 232 |
| `func_001A8918` | Matching | 100.00% | 148 |
| `func_001A89B0` | Matching | 100.00% | 144 |
| `func_001A8A40` | Matching | 100.00% | 164 |
| `func_001A8AE8` | Matching | 100.00% | 156 |
| `func_001A8B88` | Matching | 100.00% | 696 |
| `func_001A8E40` | Matching | 100.00% | 340 |
| `func_001A8F98` | Matching | 100.00% | 248 |
| `func_001A9090` | Matching | 100.00% | 96 |
| `func_001A90F0` | Matching | 100.00% | 96 |
| `func_001A9150` | Matching | 100.00% | 96 |
| `func_001A91B0` | Matching | 100.00% | 180 |
| `func_001A9268` | Matching | 100.00% | 112 |
| `func_001A92D8` | Matching | 100.00% | 248 |
| `func_001A93D0` | Matching | 100.00% | 100 |
| `func_001A9438` | Matching | 100.00% | 156 |
| `func_001A94D8(void*)` | Matching | 100.00% | 8 |
| `func_001A94E0` | Matching | 100.00% | 152 |
| `func_001A9578` | Matching | 100.00% | 192 |
| `func_001A9638` | Matching | 100.00% | 48 |
| `func_001A9668` | Matching | 100.00% | 168 |
| `func_001A9710` | Matching | 100.00% | 168 |
| `func_001A97B8` | Matching | 100.00% | 212 |
| `func_001A9890` | Matching | 100.00% | 28 |
| `func_001A98B0(void*)` | Matching | 100.00% | 8 |
| `func_001A98B8` | Matching | 100.00% | 120 |
| `func_001A9930` | Matching | 100.00% | 232 |
| `func_001A9A18` | Matching | 100.00% | 156 |
| `func_001A9AB8` | Matching | 100.00% | 156 |
| `func_001A9B58` | Matching | 100.00% | 104 |
| `func_001A9BC0` | Matching | 100.00% | 140 |
| `func_001A9C50` | Matching | 100.00% | 108 |
| `func_001AA9B0` | Matching | 100.00% | 436 |
| `func_001AAB68` | Matching | 100.00% | 488 |
| `func_001AAD50` | Matching | 100.00% | 572 |
| `func_001AAF90` | Matching | 100.00% | 372 |
| `func_001AB108` | Matching | 100.00% | 112 |
| `func_001AB178` | Matching | 100.00% | 268 |
| `func_001AB288` | Matching | 100.00% | 232 |
| `func_001AB370` | Matching | 100.00% | 92 |
| `func_001AB3D0` | Matching | 100.00% | 164 |
| `func_001ABB30` | Matching | 100.00% | 288 |
| `func_001ABC50` | Matching | 100.00% | 128 |
| `func_001ABE58` | Matching | 100.00% | 128 |
| `func_001ABED8` | Matching | 100.00% | 148 |
| `func_001ABF70` | Matching | 100.00% | 52 |
| `func_001ABFA8` | Matching | 100.00% | 100 |
| `func_001AC010` | Matching | 100.00% | 84 |
| `func_001AC068` | Matching | 100.00% | 80 |
| `func_001AC0B8` | Matching | 100.00% | 148 |
| `func_001AC150(void*)` | Matching | 100.00% | 28 |
| `func_001AC170` | Matching | 100.00% | 328 |
| `func_001AC2B8` | Matching | 100.00% | 168 |
| `func_001AC360` | Matching | 100.00% | 168 |
| `func_001AC408` | Matching | 100.00% | 64 |
| `func_001AC448` | Matching | 100.00% | 164 |
| `func_001AC4F0` | Matching | 100.00% | 184 |
| `func_001AC5A8` | Matching | 100.00% | 20 |
| `func_001AC5C0` | Matching | 100.00% | 860 |
| `func_001AC920` | Matching | 100.00% | 160 |
| `func_001AC9C0` | Matching | 100.00% | 196 |
| `func_001ACA88` | Matching | 100.00% | 192 |
| `func_001ACB48` | Matching | 100.00% | 392 |
| `func_001ACCD0` | Matching | 100.00% | 256 |
| `func_001ACDD0` | Matching | 100.00% | 292 |
| `func_001ACEF8` | Matching | 100.00% | 568 |
| `func_001AD130` | Matching | 100.00% | 68 |
| `func_001AD178` | Matching | 100.00% | 108 |
| `func_001AD1E8(void*)` | Matching | 100.00% | 28 |
| `func_001AD208` | Matching | 100.00% | 252 |
| `func_001AD308` | Matching | 100.00% | 224 |
| `func_001AD3E8` | Matching | 100.00% | 260 |
| `func_001AD4F0` | Matching | 100.00% | 244 |
| `func_001AD5E8` | Matching | 100.00% | 724 |
| `func_001AD8C0` | Matching | 100.00% | 108 |
| `func_001AD930` | Matching | 100.00% | 148 |
| `func_001AD9C8` | Matching | 100.00% | 100 |
| `func_001ADA30` | Matching | 100.00% | 512 |
| `func_001ADC30` | Matching | 100.00% | 416 |
| `func_001ADDD0` | Matching | 100.00% | 184 |
| `func_001ADE88` | Matching | 100.00% | 300 |
| `func_001ADFB8` | Matching | 100.00% | 44 |
| `func_001ADFE8` | Matching | 100.00% | 248 |
| `func_001AE0E0(void*)` | Matching | 100.00% | 28 |
| `func_001AE100` | Matching | 100.00% | 36 |
| `func_001AE680` | Matching | 100.00% | 284 |
| `func_001AE7A0` | Matching | 100.00% | 1104 |
| `func_001AEBF0` | Matching | 100.00% | 112 |
| `func_001AEC60` | Matching | 100.00% | 1080 |
| `func_001AF098` | Matching | 100.00% | 364 |
| `func_001AF208` | Matching | 100.00% | 468 |
| `func_001AF3E0` | Matching | 100.00% | 68 |
| `func_001AF428` | Matching | 100.00% | 72 |
| `func_001AF470` | Matching | 100.00% | 248 |
| `func_001AF568` | Matching | 100.00% | 284 |
| `func_001AF688` | Matching | 100.00% | 160 |
| `func_001AF728` | Matching | 100.00% | 516 |
| `func_001AF930` | Matching | 100.00% | 300 |
| `func_001AFA60` | Matching | 100.00% | 804 |
| `func_001AFD88` | Matching | 100.00% | 124 |
| `func_001AFE08` | Matching | 100.00% | 92 |
| `func_001AFE68` | Matching | 100.00% | 588 |
| `func_001B00B8` | Matching | 100.00% | 120 |
| `func_001B0130(void*)` | Matching | 100.00% | 28 |
| `func_001B0150` | Matching | 100.00% | 1000 |
| `func_001B0538` | Matching | 100.00% | 164 |
| `func_001B05E0` | Matching | 100.00% | 72 |
| `func_001B0628` | Matching | 100.00% | 68 |
| `func_001B0670` | Matching | 100.00% | 112 |
| `func_001B06E0` | Matching | 100.00% | 36 |
| `func_001B0708` | Matching | 100.00% | 328 |
| `func_001B0850` | Matching | 100.00% | 948 |
| `func_001B0C08` | Matching | 100.00% | 296 |
| `func_001B0D30` | Matching | 100.00% | 220 |
| `func_001B0E10` | Matching | 100.00% | 276 |
| `func_001B0F28` | Matching | 100.00% | 56 |
| `func_001B0F60` | Matching | 100.00% | 76 |
| `func_001B0FB0` | Matching | 100.00% | 148 |
| `func_001B1048(void*)` | Matching | 100.00% | 28 |
| `func_001B1068` | Matching | 100.00% | 144 |
| `func_001B10F8` | Matching | 100.00% | 392 |
| `func_001B1280` | Matching | 100.00% | 596 |
| `func_001B14D8` | Matching | 100.00% | 184 |
| `func_001B1590` | Matching | 100.00% | 68 |
| `func_001B15D8` | Matching | 100.00% | 388 |
| `func_001B1760` | Matching | 100.00% | 164 |
| `func_001B1808` | Matching | 100.00% | 508 |
| `func_001B1B10` | Matching | 100.00% | 132 |
| `func_001B1B98` | Matching | 100.00% | 804 |
| `func_001B1EC0` | Matching | 100.00% | 84 |
| `func_001B1F18` | Matching | 100.00% | 108 |
| `func_001B1F88` | Matching | 100.00% | 188 |
| `func_001B2048(void*)` | Matching | 100.00% | 40 |
| `func_001B2070` | Matching | 100.00% | 556 |
| `func_001B22A0` | Matching | 100.00% | 128 |
| `func_001B2320` | Matching | 100.00% | 84 |
| `func_001B2378` | Matching | 100.00% | 616 |
| `func_001B25E0` | Matching | 100.00% | 464 |
| `func_001B27B0` | Matching | 100.00% | 1312 |
| `func_001B2CD0` | Matching | 100.00% | 208 |
| `func_001B2DA0` | Matching | 100.00% | 280 |
| `func_001B2EB8` | Matching | 100.00% | 740 |
| `func_001B31A0` | Matching | 100.00% | 564 |
| `func_001B33D8` | Matching | 100.00% | 184 |
| `func_001B3490` | Matching | 100.00% | 152 |
| `func_001B3528` | Matching | 100.00% | 60 |
| `func_001B3568` | Matching | 100.00% | 72 |
| `func_001B35B0` | Matching | 100.00% | 428 |
| `func_001B3760` | Matching | 100.00% | 116 |
| `func_001B37D8` | Matching | 100.00% | 116 |
| `func_001B3850` | Matching | 100.00% | 128 |
| `func_001B38D0` | Matching | 100.00% | 168 |
| `func_001B3978` | Matching | 100.00% | 184 |
| `func_001B3A30` | Matching | 100.00% | 448 |
| `func_001B3BF0` | Matching | 100.00% | 304 |
| `func_001B3D20` | Matching | 100.00% | 596 |
| `func_001B3F78` | Matching | 100.00% | 160 |
| `func_001B4018` | Matching | 100.00% | 184 |
| `func_001B40D0` | Matching | 100.00% | 148 |
| `func_001B4168` | Matching | 100.00% | 44 |
| `func_001B4198(void*)` | Matching | 100.00% | 12 |
| `func_001B41A8` | Matching | 100.00% | 512 |
| `func_001B43A8` | Matching | 100.00% | 196 |
| `func_001B4470` | Matching | 100.00% | 376 |
| `func_001B45E8` | Matching | 100.00% | 468 |
| `func_001B47C0` | Matching | 100.00% | 200 |
| `func_001B4888` | Matching | 100.00% | 884 |
| `func_001B4C00` | Matching | 100.00% | 64 |
| `func_001B4C40` | Matching | 100.00% | 148 |
| `func_001B4FA0` | Matching | 100.00% | 200 |
| `func_001B5068` | Matching | 100.00% | 508 |
| `func_001B5268` | Matching | 100.00% | 96 |
| `func_001B52C8` | Matching | 100.00% | 496 |
| `func_001B54B8` | Matching | 100.00% | 248 |
| `func_001B55B0` | Matching | 100.00% | 396 |
| `func_001B5740` | Matching | 100.00% | 240 |
| `func_001B5830` | Matching | 100.00% | 548 |
| `func_001B5A58` | Matching | 100.00% | 380 |
| `func_001B5BD8` | Matching | 100.00% | 288 |
| `func_001B5CF8` | Matching | 100.00% | 92 |
| `func_001B5D58` | Matching | 100.00% | 204 |
| `func_001B5E28` | Matching | 100.00% | 592 |
| `func_001B6078(void*)` | Matching | 100.00% | 8 |
| `func_001B6080` | Matching | 100.00% | 36 |
| `func_001B60A8` | Matching | 100.00% | 476 |
| `func_001B6288` | Matching | 100.00% | 224 |
| `func_001B6368` | Matching | 100.00% | 128 |
| `func_001B63E8` | Matching | 100.00% | 472 |
| `func_001B65C0` | Matching | 100.00% | 244 |
| `func_001B66B8` | Matching | 100.00% | 136 |
| `func_001B6740` | Matching | 100.00% | 44 |
| `func_001B6770` | Matching | 100.00% | 36 |
| `func_001B6798` | Matching | 100.00% | 756 |
| `func_001B6A90` | Matching | 100.00% | 36 |
| `func_001B6AB8` | Matching | 100.00% | 108 |
| `func_001B6B28(void*)` | Matching | 100.00% | 40 |
| `func_001B6B50` | Matching | 100.00% | 100 |
| `func_001B6BB8` | Matching | 100.00% | 224 |
| `func_001B6C98` | Matching | 100.00% | 376 |
| `func_001B6E10` | Matching | 100.00% | 44 |
| `func_001B6E40` | Matching | 100.00% | 104 |
| `func_001B6EA8` | Matching | 100.00% | 36 |
| `func_001B6ED0` | Matching | 100.00% | 348 |
| `func_001B7030` | Matching | 100.00% | 84 |
| `func_001B7088(void*)` | Matching | 100.00% | 28 |
| `func_001B70A8(void*)` | Matching | 100.00% | 36 |
| `func_001B70D0` | Matching | 100.00% | 1408 |
| `func_001B7650` | Matching | 100.00% | 292 |
| `func_001B7778` | Matching | 100.00% | 48 |
| `func_001B77A8(void*)` | Matching | 100.00% | 28 |
| `func_001B77C8` | Matching | 100.00% | 88 |
| `func_001B7820` | Matching | 100.00% | 204 |
| `func_001B78F0` | Matching | 100.00% | 72 |
| `func_001B7938` | Matching | 100.00% | 204 |
| `func_001B7A08` | Matching | 100.00% | 72 |
| `func_001B7A50` | Matching | 100.00% | 72 |
| `func_001B7A98` | Matching | 100.00% | 296 |
| `func_001B7BC0` | Matching | 100.00% | 100 |
| `func_001B7C28` | Matching | 100.00% | 72 |
| `func_001B7C70` | Matching | 100.00% | 72 |
| `func_001B7CB8` | Matching | 100.00% | 388 |
| `func_001B8238` | Matching | 100.00% | 388 |
| `func_001B83C0` | Matching | 100.00% | 280 |
| `func_001B84D8` | Matching | 100.00% | 904 |
| `func_001B8860` | Matching | 100.00% | 44 |
| `func_001B8890` | Matching | 100.00% | 96 |
| `func_001B88F0` | Matching | 100.00% | 112 |
| `func_001B8960` | Matching | 100.00% | 136 |
| `func_001B89E8(void*)` | Matching | 100.00% | 28 |
| `func_001B8A08` | Matching | 100.00% | 148 |
| `func_001B8AA0` | Matching | 100.00% | 408 |
| `func_001B8C38` | Matching | 100.00% | 1100 |
| `func_001B9088` | Matching | 100.00% | 320 |
| `func_001B91C8` | Matching | 100.00% | 256 |
| `func_001B92C8` | Matching | 100.00% | 352 |
| `func_001B9428` | Matching | 100.00% | 92 |
| `func_001B9488` | Matching | 100.00% | 208 |
| `func_001B9558` | Matching | 100.00% | 100 |
| `func_001B95C0` | Matching | 100.00% | 80 |
| `func_001B9610` | Matching | 100.00% | 100 |
| `func_001B9678` | Matching | 100.00% | 100 |
| `func_001B96E0` | Matching | 100.00% | 96 |
| `func_001B9740` | Matching | 100.00% | 112 |
| `func_001B97B0` | Matching | 100.00% | 112 |
| `func_001B9820` | Matching | 100.00% | 304 |
| `func_001B9950` | Matching | 100.00% | 452 |
| `func_001B9B18` | Matching | 100.00% | 448 |
| `func_001B9CD8` | Matching | 100.00% | 140 |
| `func_001B9D68` | Matching | 100.00% | 512 |
| `func_001B9F68` | Matching | 100.00% | 52 |
| `func_001B9FA0` | Matching | 100.00% | 364 |
| `func_001BA110` | Matching | 100.00% | 104 |
| `func_001BA178` | Matching | 100.00% | 160 |
| `func_001BA218` | Matching | 100.00% | 104 |
| `func_001BA280` | Matching | 100.00% | 212 |
| `func_001BA358` | Matching | 100.00% | 136 |
| `func_001BA3E0` | Matching | 100.00% | 68 |
| `func_001BA428` | Matching | 100.00% | 184 |
| `func_001BA4E0(void*)` | Matching | 100.00% | 28 |
| `func_001BA500` | Matching | 100.00% | 276 |
| `func_001BA618` | Matching | 100.00% | 672 |
| `func_001BA8B8` | Matching | 100.00% | 320 |
| `func_001BA9F8` | Matching | 100.00% | 144 |
| `func_001BAA88` | Matching | 100.00% | 156 |
| `func_001BAB28` | Matching | 100.00% | 360 |
| `func_001BAC90` | Matching | 100.00% | 344 |
| `func_001BADE8` | Matching | 100.00% | 240 |
| `func_001BAED8` | Matching | 100.00% | 448 |
| `func_001BB098` | Matching | 100.00% | 76 |
| `func_001BB0E8` | Matching | 100.00% | 108 |
| `func_001BB158` | Matching | 100.00% | 376 |
| `func_001BB2D0` | Matching | 100.00% | 108 |
| `func_001BB340` | Matching | 100.00% | 108 |
| `func_001BB3B0` | Matching | 100.00% | 140 |
| `func_001BB440` | Matching | 100.00% | 108 |
| `func_001BB4B0` | Matching | 100.00% | 112 |
| `func_001BB520` | Matching | 100.00% | 176 |
| `func_001BB5D0` | Matching | 100.00% | 456 |
| `func_001BB798` | Matching | 100.00% | 164 |
| `func_001BB840` | Matching | 100.00% | 292 |
| `func_001BB968` | Matching | 100.00% | 72 |
| `func_001BBA18` | Matching | 100.00% | 140 |
| `func_001BBAA8(void*)` | Matching | 100.00% | 32 |
| `func_001BBAC8` | Matching | 100.00% | 376 |
| `func_001BBC40` | Matching | 100.00% | 200 |
| `func_001BBD08` | Matching | 100.00% | 84 |
| `func_001BBD60` | Matching | 100.00% | 128 |
| `func_001BBDE0(void*)` | Matching | 100.00% | 28 |
| `func_001BBE00` | Matching | 100.00% | 276 |
| `func_001BBF18` | Matching | 100.00% | 628 |
| `func_001BC190` | Matching | 100.00% | 256 |
| `func_001BC290` | Matching | 100.00% | 112 |
| `func_001BC300` | Matching | 100.00% | 252 |
| `func_001BC400` | Matching | 100.00% | 240 |
| `func_001BC4F0` | Matching | 100.00% | 428 |
| `func_001BC6A0` | Matching | 100.00% | 136 |
| `func_001BC728` | Matching | 100.00% | 240 |
| `func_001BC818` | Matching | 100.00% | 376 |
| `func_001BC990` | Matching | 100.00% | 452 |
| `func_001BCB58` | Matching | 100.00% | 212 |
| `func_001BCC30` | Matching | 100.00% | 120 |
| `func_001BCCA8` | Matching | 100.00% | 108 |
| `func_001BCD18` | Matching | 100.00% | 256 |
| `func_001BCE18(void*)` | Matching | 100.00% | 28 |
| `func_001BCE38` | Matching | 100.00% | 892 |
| `func_001BD1B8` | Matching | 100.00% | 624 |
| `func_001BD428` | Matching | 100.00% | 52 |
| `func_001BD460` | Matching | 100.00% | 224 |
| `func_001BD540` | Matching | 100.00% | 208 |
| `func_001BD610` | Matching | 100.00% | 296 |
| `func_001BD738` | Matching | 100.00% | 268 |
| `func_001BD848` | Matching | 100.00% | 124 |
| `func_001BD8C8` | Matching | 100.00% | 444 |
| `func_001BDA88` | Matching | 100.00% | 396 |
| `func_001BDC18` | Matching | 100.00% | 136 |
| `func_001BDCF8` | Matching | 100.00% | 100 |
| `func_001BDD60` | Matching | 100.00% | 132 |
| `func_001BDDE8` | Matching | 100.00% | 92 |
| `func_001BDE48` | Matching | 100.00% | 280 |
| `func_001BDF60` | Matching | 100.00% | 120 |
| `func_001BDFD8` | Matching | 100.00% | 92 |
| `func_001BE038` | Matching | 100.00% | 112 |
| `func_001BE0A8` | Matching | 100.00% | 768 |
| `func_001BE3A8` | Matching | 100.00% | 360 |
| `func_001BE510` | Matching | 100.00% | 44 |
| `func_001BE540` | Matching | 100.00% | 480 |
| `func_001BE720` | Matching | 100.00% | 180 |
| `func_001BE7D8` | Matching | 100.00% | 76 |
| `func_001BE828` | Matching | 100.00% | 100 |
| `func_001BE890(void*)` | Matching | 100.00% | 28 |
| `func_001BE8B0` | Matching | 100.00% | 384 |
| `func_001BEA30(void*)` | Matching | 100.00% | 8 |
| `func_001BEA38` | Matching | 100.00% | 576 |
| `func_001BEC78` | Matching | 100.00% | 176 |
| `func_001BED28` | Matching | 100.00% | 44 |
| `func_001BED58` | Matching | 100.00% | 216 |
| `func_001BEE30` | Matching | 100.00% | 72 |
| `func_001BEE78` | Matching | 100.00% | 88 |
| `func_001BEED0` | Matching | 100.00% | 108 |
| `func_001BEF40(void*)` | Matching | 100.00% | 28 |
| `func_001BEF60` | Matching | 100.00% | 712 |
| `func_001BF228` | Matching | 100.00% | 332 |
| `func_001BF378` | Matching | 100.00% | 192 |
| `func_001BF438` | Matching | 100.00% | 364 |
| `func_001BF5A8` | Matching | 100.00% | 276 |
| `func_001BF6C0` | Matching | 100.00% | 148 |
| `func_001BF758` | Matching | 100.00% | 900 |
| `func_001BFAE0` | Matching | 100.00% | 216 |
| `func_001BFBB8` | Matching | 100.00% | 64 |
| `func_001BFBF8` | Matching | 100.00% | 164 |
| `func_001BFCA0(void*)` | Matching | 100.00% | 28 |
| `func_001BFCC0` | Matching | 100.00% | 212 |
| `func_001BFD98` | Matching | 100.00% | 216 |
| `func_001BFE70` | Matching | 100.00% | 708 |
| `func_001C0138` | Matching | 100.00% | 224 |
| `func_001C0218` | Matching | 100.00% | 36 |
| `func_001C0240` | Matching | 100.00% | 180 |
| `func_001C02F8` | Matching | 100.00% | 92 |
| `func_001C0358` | Matching | 100.00% | 116 |
| `func_001C03D0` | Matching | 100.00% | 68 |
| `func_001C0418` | Matching | 100.00% | 72 |
| `func_001C0460` | Matching | 100.00% | 68 |
| `func_001C04A8` | Matching | 100.00% | 152 |
| `func_001C0540` | Matching | 100.00% | 1252 |
| `func_001C0A28` | Matching | 100.00% | 88 |
| `func_001C0A80` | Matching | 100.00% | 136 |
| `func_001C0B08` | Matching | 100.00% | 20 |
| `func_001C0B20` | Matching | 100.00% | 448 |
| `func_001C0CE0` | Matching | 100.00% | 72 |
| `func_001C0D28` | Matching | 100.00% | 348 |
| `func_001C0E88(void*)` | Matching | 100.00% | 28 |
| `func_001C0EA8` | Matching | 100.00% | 152 |
| `func_001C0F40` | Matching | 100.00% | 124 |
| `func_001C0FC0` | Matching | 100.00% | 120 |
| `func_001C1038` | Matching | 100.00% | 68 |
| `func_001C1080` | Matching | 100.00% | 860 |
| `func_001C13E0` | Matching | 100.00% | 164 |
| `func_001C1488` | Matching | 100.00% | 216 |
| `func_001C1560` | Matching | 100.00% | 632 |
| `func_001C17D8(void*)` | Matching | 100.00% | 8 |
| `func_001C17E0` | Matching | 100.00% | 20 |
| `func_001C17F8` | Matching | 100.00% | 460 |
| `func_001C19C8` | Matching | 100.00% | 380 |
| `func_001C1B48` | Matching | 100.00% | 60 |
| `func_001C1B88` | Matching | 100.00% | 196 |
| `func_001C1C50` | Matching | 100.00% | 64 |
| `func_001C1C90` | Matching | 100.00% | 124 |
| `func_001C1D10(void*)` | Matching | 100.00% | 28 |
| `func_001C1D30` | Matching | 100.00% | 216 |
| `func_001C1E08` | Matching | 100.00% | 156 |
| `func_001C1EA8` | Matching | 100.00% | 588 |
| `func_001C20F8` | Matching | 100.00% | 64 |
| `func_001C2138` | Matching | 100.00% | 104 |
| `func_001C21A0(void*)` | Matching | 100.00% | 28 |
| `func_001C21C0` | Matching | 100.00% | 216 |
| `func_001C2298` | Matching | 100.00% | 292 |
| `func_001C23C0` | Matching | 100.00% | 84 |
| `func_001C2418` | Matching | 100.00% | 76 |
| `func_001C2468` | Matching | 100.00% | 272 |
| `func_001C2578` | Matching | 100.00% | 452 |
| `func_001C2740` | Matching | 100.00% | 724 |
| `func_001C2A18` | Matching | 100.00% | 304 |
| `func_001C2B48` | Matching | 100.00% | 92 |
| `func_001C2BA8` | Matching | 100.00% | 164 |
| `func_001C2C50` | Matching | 100.00% | 200 |
| `func_001C2D18` | Matching | 100.00% | 120 |
| `func_001C2D90` | Matching | 100.00% | 112 |
| `func_001C2E00` | Matching | 100.00% | 108 |
| `func_001C2E70` | Matching | 100.00% | 108 |
| `func_001C2EE0(void*)` | Matching | 100.00% | 28 |
| `func_001C2F00` | Matching | 100.00% | 952 |
| `func_001C32B8` | Matching | 100.00% | 84 |
| `func_001C3310` | Matching | 100.00% | 608 |
| `func_001C3570` | Matching | 100.00% | 248 |
| `func_001C3668` | Matching | 100.00% | 1788 |
| `func_001C3D68` | Matching | 100.00% | 384 |
| `func_001C4538` | Matching | 100.00% | 620 |
| `func_001C47A8` | Matching | 100.00% | 540 |
| `func_001C49C8` | Matching | 100.00% | 432 |
| `func_001C4B78` | Matching | 100.00% | 32 |
| `func_001C4B98` | Matching | 100.00% | 60 |
| `func_001C4BD8` | Matching | 100.00% | 252 |
| `func_001C4CD8` | Matching | 100.00% | 80 |
| `func_001C4D28` | Matching | 100.00% | 276 |
| `func_001C4E40` | Matching | 100.00% | 276 |
| `func_001C4F58` | Matching | 100.00% | 192 |
| `func_001C5018` | Matching | 100.00% | 64 |
| `func_001C5058` | Matching | 100.00% | 60 |
| `func_001C5098` | Matching | 100.00% | 112 |
| `func_001C5108` | Matching | 100.00% | 108 |
| `func_001C5178(void*)` | Matching | 100.00% | 28 |
| `func_001C5198` | Matching | 100.00% | 372 |
| `func_001C5310` | Matching | 100.00% | 88 |
| `func_001C5368` | Matching | 100.00% | 180 |
| `func_001C5420` | Matching | 100.00% | 16 |
| `func_001C5430` | Matching | 100.00% | 268 |
| `func_001C5540` | Matching | 100.00% | 184 |
| `func_001C55F8` | Matching | 100.00% | 52 |
| `func_001C5630` | Matching | 100.00% | 288 |
| `func_001C5750` | Matching | 100.00% | 48 |
| `func_001C5780(void*, int, int)` | Matching | 100.00% | 28 |
| `func_001C57A0(void*, int, int)` | Matching | 100.00% | 28 |
| `func_001C57C0(void*, int, int)` | Matching | 100.00% | 28 |
| `func_001C57E0` | Matching | 100.00% | 32 |
| `func_001C5800` | Matching | 100.00% | 16 |
| `func_001C5810` | Matching | 100.00% | 40 |
| `func_001C5838` | Matching | 100.00% | 40 |
| `func_001C5860` | Matching | 100.00% | 20 |
| `func_001C5878` | Matching | 100.00% | 40 |
| `func_001C58A0` | Matching | 100.00% | 44 |
| `func_001C58D0` | Matching | 100.00% | 20 |

### `fe/feflowstate`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEFlowState_setNumStates` | Matching | 100.00% | 100 |
| `func_001A06B0` | Matching | 100.00% | 60 |
| `func_001A06F0` | Matching | 100.00% | 24 |
| `func_001A0708` | Matching | 100.00% | 24 |

### `fe/fememcard`

20 matching, 0 partial, 1 not started (21 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateMemCard_onCreateScreen` | Matching | 100.00% | 156 |
| `func_00186BF0` | Matching | 100.00% | 164 |
| `func_00186C98` | Matching | 100.00% | 196 |
| `func_00186D60` | Matching | 100.00% | 480 |
| `func_00186F40` | Matching | 100.00% | 76 |
| `func_00186F90` | Matching | 100.00% | 440 |
| `func_00187148` | Matching | 100.00% | 56 |
| `func_00187180` | Matching | 100.00% | 36 |
| `func_001871A8` | Matching | 100.00% | 132 |
| `func_00187230` | Matching | 100.00% | 64 |
| `func_00187270` | Matching | 100.00% | 164 |
| `func_00187318` | Matching | 100.00% | 68 |
| `func_00187360` | Matching | 100.00% | 392 |
| `func_001874E8` | Matching | 100.00% | 152 |
| `func_001876A8` | Matching | 100.00% | 260 |
| `func_001877B0` | Matching | 100.00% | 364 |
| `func_00187920` | Matching | 100.00% | 280 |
| `func_00187A38` | Matching | 100.00% | 472 |
| `func_00187C10(void*)` | Matching | 100.00% | 8 |
| `func_00187C18` | Matching | 100.00% | 56 |

### `fe/fememcardcallbacks`

57 matching, 0 partial, 0 not started (57 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEMemCard_callbackSaveSuccess` | Matching | 100.00% | 280 |
| `cFEMemCard_callbackReadSuccess` | Matching | 100.00% | 288 |
| `func_001D68E8` | Matching | 100.00% | 248 |
| `func_001D69E0` | Matching | 100.00% | 236 |
| `func_001D6AD0` | Matching | 100.00% | 344 |
| `func_001D6C28` | Matching | 100.00% | 348 |
| `func_001D6D88` | Matching | 100.00% | 648 |
| `func_001D7010` | Matching | 100.00% | 380 |
| `func_001D7190` | Matching | 100.00% | 276 |
| `func_001D72A8` | Matching | 100.00% | 108 |
| `func_001D7318` | Matching | 100.00% | 264 |
| `cFEMemCard_callbackConfirmFormatDone` | Matching | 100.00% | 296 |
| `func_001D7548` | Matching | 100.00% | 316 |
| `cFEMemCard_callbackConfirmDelete` | Matching | 100.00% | 352 |
| `func_001D77E8` | Matching | 100.00% | 432 |
| `func_001D7998` | Matching | 100.00% | 380 |
| `func_001D7B18` | Matching | 100.00% | 332 |
| `cFEMemCard_callbackFileExists` | Matching | 100.00% | 260 |
| `func_001D7D70` | Matching | 100.00% | 348 |
| `cFEMemCard_callbackDeleteDone` | Matching | 100.00% | 332 |
| `func_001D8020` | Matching | 100.00% | 320 |
| `func_001D8160` | Matching | 100.00% | 224 |
| `func_001D8240` | Matching | 100.00% | 276 |
| `func_001D8358` | Matching | 100.00% | 76 |
| `func_001D83A8` | Matching | 100.00% | 392 |
| `func_001D8530` | Matching | 100.00% | 316 |
| `func_001D8670` | Matching | 100.00% | 44 |
| `func_001D86A0(void*)` | Matching | 100.00% | 12 |
| `func_001D86B0` | Matching | 100.00% | 76 |
| `func_001D8700` | Matching | 100.00% | 1248 |
| `func_001D8BE0` | Matching | 100.00% | 84 |
| `func_001D8C38(void*)` | Matching | 100.00% | 20 |
| `cFEMemCard_onInputBegin` | Matching | 100.00% | 276 |
| `func_001D8D68` | Matching | 100.00% | 116 |
| `func_001D8DE0` | Matching | 100.00% | 1140 |
| `func_001D9258` | Matching | 100.00% | 172 |
| `func_001D9308` | Matching | 100.00% | 92 |
| `func_001D9368` | Matching | 100.00% | 64 |
| `func_001D93A8(void*)` | Matching | 100.00% | 8 |
| `func_001D93B0(void*)` | Matching | 100.00% | 12 |
| `func_001D93C0(void*)` | Matching | 100.00% | 8 |
| `func_001D93C8(void*)` | Matching | 100.00% | 8 |
| `func_001D93D0(void*)` | Matching | 100.00% | 8 |
| `func_001D93D8` | Matching | 100.00% | 16 |
| `func_001D93E8` | Matching | 100.00% | 136 |
| `cFEMemCard_triggerDisplayState` | Matching | 100.00% | 880 |
| `func_001D97E0` | Matching | 100.00% | 56 |
| `func_001D9818` | Matching | 100.00% | 92 |
| `func_001D9878(void*)` | Matching | 100.00% | 8 |
| `func_001D9880` | Matching | 100.00% | 200 |
| `cFEMemCard_createReadBuffer` | Matching | 100.00% | 124 |
| `func_001D99C8` | Matching | 100.00% | 180 |
| `func_001D9A80` | Matching | 100.00% | 332 |
| `func_001D9BD0` | Matching | 100.00% | 212 |
| `func_001D9CA8` | Matching | 100.00% | 112 |
| `func_001D9D18` | Matching | 100.00% | 44 |
| `func_001D9D48` | Matching | 100.00% | 108 |

### `fe/fepopup`

118 matching, 0 partial, 4 not started (122 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cScreenPopup_cScreenPopup` | Matching | 100.00% | 424 |
| `func_001C5A90` | Matching | 100.00% | 104 |
| `cScreenPopup_onCreateScreen` | Matching | 100.00% | 108 |
| `func_001C5B68(void*)` | Matching | 100.00% | 32 |
| `func_001C5B88` | Matching | 100.00% | 168 |
| `cScreenPopup_onGainTransition` | Matching | 100.00% | 416 |
| `func_001C5DD0(void*)` | Matching | 100.00% | 8 |
| `func_001C5DD8` | Matching | 100.00% | 124 |
| `func_001C5E58` | Matching | 100.00% | 200 |
| `func_001C5F20` | Matching | 100.00% | 784 |
| `cScreenPopup_FillObjectPointers` | Matching | 100.00% | 1208 |
| `func_001C66E8` | Matching | 100.00% | 1052 |
| `func_001C6B08` | Matching | 100.00% | 552 |
| `func_001C6D30` | Matching | 100.00% | 784 |
| `func_001C7040` | Matching | 100.00% | 172 |
| `func_001C70F0` | Matching | 100.00% | 356 |
| `func_001C7258` | Matching | 100.00% | 300 |
| `func_001C7388` | Matching | 100.00% | 572 |
| `func_001C75C8` | Matching | 100.00% | 84 |
| `func_001C7738` | Matching | 100.00% | 388 |
| `func_001C78C0` | Matching | 100.00% | 796 |
| `func_001C7BE0` | Matching | 100.00% | 64 |
| `func_001C7C20` | Matching | 100.00% | 656 |
| `func_001C7EB0` | Matching | 100.00% | 416 |
| `func_001C8050` | Matching | 100.00% | 148 |
| `func_001C80E8` | Matching | 100.00% | 368 |
| `cScreenPopup_setTextString` | Matching | 100.00% | 200 |
| `func_001C8320` | Matching | 100.00% | 388 |
| `func_001C84A8` | Matching | 100.00% | 192 |
| `func_001C8568` | Matching | 100.00% | 192 |
| `func_001C8628` | Matching | 100.00% | 76 |
| `func_001C8678` | Matching | 100.00% | 220 |
| `func_001C8758` | Matching | 100.00% | 364 |
| `func_001C88C8` | Matching | 100.00% | 100 |
| `func_001C8930` | Matching | 100.00% | 260 |
| `func_001C8A38` | Matching | 100.00% | 1208 |
| `func_001C8EF0` | Matching | 100.00% | 328 |
| `func_001C9038` | Matching | 100.00% | 468 |
| `func_001C9210` | Matching | 100.00% | 416 |
| `func_001C93B0` | Matching | 100.00% | 252 |
| `func_001C94B0` | Matching | 100.00% | 408 |
| `func_001C97E0` | Matching | 100.00% | 340 |
| `func_001C9938` | Matching | 100.00% | 496 |
| `func_001C9B28` | Matching | 100.00% | 60 |
| `func_001C9B68` | Matching | 100.00% | 44 |
| `cScreenPopup_createConfirmationPopup` | Matching | 100.00% | 308 |
| `func_001CA0F0` | Matching | 100.00% | 92 |
| `func_001CA150` | Matching | 100.00% | 48 |
| `func_001CA180` | Matching | 100.00% | 276 |
| `func_001CA298` | Matching | 100.00% | 496 |
| `func_001CA488` | Matching | 100.00% | 52 |
| `func_001CA4C0` | Matching | 100.00% | 52 |
| `func_001CA4F8` | Matching | 100.00% | 44 |
| `func_001CA528` | Matching | 100.00% | 76 |
| `func_001CA578(void*)` | Matching | 100.00% | 28 |
| `func_001CA598` | Matching | 100.00% | 260 |
| `cScreenPopup_checkAndFixTextEntry` | Matching | 100.00% | 512 |
| `func_001CA8A0` | Matching | 100.00% | 92 |
| `cBuyPopupInfo_initBuySongByCredit` | Matching | 100.00% | 124 |
| `cBuyPopupInfo_initBuySong` | Matching | 100.00% | 148 |
| `func_001CAA18` | Matching | 100.00% | 248 |
| `cBuyPopupInfo_initBuyBolt` | Matching | 100.00% | 148 |
| `func_001CABA8` | Matching | 100.00% | 136 |
| `func_001CAC30` | Matching | 100.00% | 100 |
| `cUIStateBuyPopup_onWidgetCreate` | Matching | 100.00% | 576 |
| `func_001CAED8` | Matching | 100.00% | 36 |
| `func_001CAF00` | Matching | 100.00% | 88 |
| `cUIStateBuyPopup_initBuyTrick` | Matching | 100.00% | 104 |
| `func_001CAFC0` | Matching | 100.00% | 108 |
| `func_001CB030` | Matching | 100.00% | 264 |
| `func_001CB138` | Matching | 100.00% | 100 |
| `cKeyboardPopup_onCreateScreen` | Matching | 100.00% | 100 |
| `func_001CB208` | Matching | 100.00% | 132 |
| `func_001CB290` | Matching | 100.00% | 56 |
| `cKeyboardPopup_onWidgetCreate` | Matching | 100.00% | 260 |
| `func_001CB3D0` | Matching | 100.00% | 72 |
| `func_001CB418` | Matching | 100.00% | 228 |
| `func_001CB500` | Matching | 100.00% | 332 |
| `func_001CB650` | Matching | 100.00% | 416 |
| `func_001CB7F0` | Matching | 100.00% | 448 |
| `func_001CB9B0` | Matching | 100.00% | 448 |
| `func_001CBB70` | Matching | 100.00% | 212 |
| `func_001CBC48` | Matching | 100.00% | 156 |
| `func_001CBCE8` | Matching | 100.00% | 196 |
| `func_001CBDB0` | Matching | 100.00% | 368 |
| `func_001CBF20` | Matching | 100.00% | 156 |
| `func_001CBFC0` | Matching | 100.00% | 204 |
| `func_001CC090` | Matching | 100.00% | 80 |
| `func_001CC0E0` | Matching | 100.00% | 96 |
| `func_001CC140` | Matching | 100.00% | 80 |
| `func_001CC190` | Matching | 100.00% | 80 |
| `func_001CC1E0` | Matching | 100.00% | 1088 |
| `func_001CC620` | Matching | 100.00% | 196 |
| `func_001CC6E8` | Matching | 100.00% | 220 |
| `func_001CC7C8` | Matching | 100.00% | 128 |
| `func_001CC848` | Matching | 100.00% | 140 |
| `func_001CCC30` | Matching | 100.00% | 616 |
| `func_001CCE98` | Matching | 100.00% | 100 |
| `func_001CCF00` | Matching | 100.00% | 108 |
| `cKeyboardPopup_setStatic` | Matching | 100.00% | 176 |
| `func_001CD020` | Matching | 100.00% | 100 |
| `func_001CD088` | Matching | 100.00% | 40 |
| `func_001CD0B0` | Matching | 100.00% | 40 |
| `cKeyboardPopup_getObjName` | Matching | 100.00% | 536 |
| `func_001CD2F0` | Matching | 100.00% | 84 |
| `cKeyboardPopup_onGainTransition` | Matching | 100.00% | 956 |
| `cKeyboardPopup_redrawScreen` | Matching | 100.00% | 660 |
| `cKeyboardPopup_SetNameForKey` | Matching | 100.00% | 504 |
| `func_001CDB98` | Matching | 100.00% | 1808 |
| `func_001CE2A8` | Matching | 100.00% | 284 |
| `func_001CE3C8` | Matching | 100.00% | 60 |
| `func_001CE408` | Matching | 100.00% | 96 |
| `func_001CE468` | Matching | 100.00% | 96 |
| `func_001CE4C8` | Matching | 100.00% | 84 |
| `func_001CE520` | Matching | 100.00% | 64 |
| `func_001CE5E0` | Matching | 100.00% | 268 |
| `func_001CE6F0` | Matching | 100.00% | 100 |
| `func_001C7620` | Matching | 99.86% | 276 |

### `fe/fepopupmisc`

375 matching, 1 partial, 5 not started (381 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEPopupVideoCalibration_onCreateScreen` | Matching | 100.00% | 212 |
| `func_001DEC68` | Matching | 100.00% | 384 |
| `func_001DEDE8(void*)` | Matching | 100.00% | 40 |
| `func_001DEE10` | Matching | 100.00% | 532 |
| `func_001DF028` | Matching | 100.00% | 40 |
| `cFEPopupScreenPos_onUpdate` | Matching | 100.00% | 808 |
| `func_001DF378(void*)` | Matching | 100.00% | 8 |
| `func_001DF380` | Matching | 100.00% | 56 |
| `func_001DF3B8(void*)` | Matching | 100.00% | 40 |
| `func_001DF3E0` | Matching | 100.00% | 56 |
| `func_001DF418(void*)` | Matching | 100.00% | 40 |
| `func_001DF440` | Matching | 100.00% | 48 |
| `func_001DF470` | Matching | 100.00% | 116 |
| `func_001DF4E8` | Matching | 100.00% | 144 |
| `func_001DF578(void*)` | Matching | 100.00% | 8 |
| `func_001DF580` | Matching | 100.00% | 64 |
| `func_001DF5C0(void*)` | Matching | 100.00% | 8 |
| `func_001DF5C8` | Matching | 100.00% | 60 |
| `func_001DF608(void*)` | Matching | 100.00% | 40 |
| `func_001DF630(void*)` | Matching | 100.00% | 8 |
| `func_001DF638` | Matching | 100.00% | 64 |
| `func_001DF678(void*)` | Matching | 100.00% | 40 |
| `func_001DF6A0(void*)` | Matching | 100.00% | 8 |
| `func_001DF6A8` | Matching | 100.00% | 60 |
| `func_001DF6E8(void*)` | Matching | 100.00% | 40 |
| `func_001DF710` | Matching | 100.00% | 60 |
| `func_001DF750(void*)` | Matching | 100.00% | 40 |
| `func_001DF778` | Matching | 100.00% | 8 |
| `func_001DF780` | Matching | 100.00% | 72 |
| `func_001DF7C8` | Matching | 100.00% | 92 |
| `func_001DF828` | Matching | 100.00% | 76 |
| `func_001DF878` | Matching | 100.00% | 104 |
| `func_001DF8E0(void*)` | Matching | 100.00% | 8 |
| `func_001DF8E8` | Matching | 100.00% | 8 |
| `func_001DF8F0` | Matching | 100.00% | 8 |
| `func_001DF8F8` | Matching | 100.00% | 8 |
| `func_001DF900` | Matching | 100.00% | 92 |
| `func_001DF960(void*)` | Matching | 100.00% | 40 |
| `func_001DF988(void*)` | Matching | 100.00% | 8 |
| `func_001DF990` | Matching | 100.00% | 8 |
| `func_001DF998` | Matching | 100.00% | 8 |
| `func_001DF9A0` | Matching | 100.00% | 8 |
| `func_001DF9A8` | Matching | 100.00% | 8 |
| `func_001DF9B0` | Matching | 100.00% | 16 |
| `func_001DF9C0` | Matching | 100.00% | 8 |
| `func_001DF9C8` | Matching | 100.00% | 8 |
| `func_001DF9D0` | Matching | 100.00% | 8 |
| `func_001DF9D8` | Matching | 100.00% | 56 |
| `func_001DFA10` | Matching | 100.00% | 92 |
| `func_001DFA70` | Matching | 100.00% | 8 |
| `func_001DFA78` | Matching | 100.00% | 16 |
| `func_001DFA88(void*)` | Matching | 100.00% | 8 |
| `func_001DFA90` | Matching | 100.00% | 16 |
| `func_001DFAA0(void*)` | Matching | 100.00% | 8 |
| `func_001DFAA8(void*)` | Matching | 100.00% | 8 |
| `func_001DFAB0` | Matching | 100.00% | 16 |
| `func_001DFAC0(void*)` | Matching | 100.00% | 8 |
| `func_001DFAC8(void*)` | Matching | 100.00% | 8 |
| `func_001DFAD0(void*)` | Matching | 100.00% | 8 |
| `func_001DFAD8(void*)` | Matching | 100.00% | 8 |
| `func_001DFAE0(void*)` | Matching | 100.00% | 8 |
| `func_001DFAE8(void*)` | Matching | 100.00% | 8 |
| `func_001DFAF0` | Matching | 100.00% | 56 |
| `func_001DFB28` | Matching | 100.00% | 92 |
| `func_001DFB88(void*, int)` | Matching | 100.00% | 16 |
| `func_001DFB98` | Matching | 100.00% | 24 |
| `func_001DFBB0(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFBB8(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFBC0` | Matching | 100.00% | 56 |
| `func_001DFBF8` | Matching | 100.00% | 92 |
| `func_001DFC58(void*, int)` | Matching | 100.00% | 16 |
| `func_001DFC68` | Matching | 100.00% | 24 |
| `func_001DFC80(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFC88(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFC90` | Matching | 100.00% | 56 |
| `func_001DFCC8` | Matching | 100.00% | 92 |
| `func_001DFD28(void*, int)` | Matching | 100.00% | 16 |
| `func_001DFD38` | Matching | 100.00% | 24 |
| `func_001DFD50(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFD58(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFD60` | Matching | 100.00% | 56 |
| `func_001DFD98` | Matching | 100.00% | 92 |
| `func_001DFDF8(void*, int)` | Matching | 100.00% | 16 |
| `func_001DFE08` | Matching | 100.00% | 24 |
| `func_001DFE20(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFE28(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFE30` | Matching | 100.00% | 56 |
| `func_001DFE68` | Matching | 100.00% | 92 |
| `func_001DFEC8(void*, int)` | Matching | 100.00% | 16 |
| `func_001DFED8` | Matching | 100.00% | 24 |
| `func_001DFEF0(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFEF8(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFF00` | Matching | 100.00% | 56 |
| `func_001DFF38` | Matching | 100.00% | 92 |
| `func_001DFF98(void*, int)` | Matching | 100.00% | 16 |
| `func_001DFFA8` | Matching | 100.00% | 24 |
| `func_001DFFC0(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFFC8(void *, void *)` | Matching | 100.00% | 8 |
| `func_001DFFD0` | Matching | 100.00% | 56 |
| `func_001E0008` | Matching | 100.00% | 8 |
| `func_001E0010` | Matching | 100.00% | 8 |
| `func_001E0018` | Matching | 100.00% | 8 |
| `func_001E0020(void*)` | Matching | 100.00% | 8 |
| `func_001E0028(void*)` | Matching | 100.00% | 8 |
| `func_001E0030` | Matching | 100.00% | 8 |
| `func_001E0038` | Matching | 100.00% | 8 |
| `func_001E0040` | Matching | 100.00% | 8 |
| `func_001E0048` | Matching | 100.00% | 80 |
| `func_001E0098` | Matching | 100.00% | 56 |
| `func_001E00D0` | Matching | 100.00% | 16 |
| `func_001E00E0` | Matching | 100.00% | 48 |
| `func_001E0110` | Matching | 100.00% | 32 |
| `func_001E0130` | Matching | 100.00% | 68 |
| `func_001E0178` | Matching | 100.00% | 56 |
| `func_001E01B0(void*)` | Matching | 100.00% | 40 |
| `func_001E01D8` | Matching | 100.00% | 56 |
| `func_001E0210` | Matching | 100.00% | 84 |
| `func_001E0268` | Matching | 100.00% | 56 |
| `func_001E02A0(void*)` | Matching | 100.00% | 40 |
| `func_001E02C8` | Matching | 100.00% | 8 |
| `func_001E02D0(void*)` | Matching | 100.00% | 40 |
| `cFEPopupSelectMultiplayerMode_onCreateScreen` | Matching | 100.00% | 92 |
| `cFEPopupSelectMultiplayerMode_onWidgetCreate` | Matching | 100.00% | 160 |
| `func_001E03F8` | Matching | 100.00% | 120 |
| `func_001E0470` | Matching | 100.00% | 136 |
| `func_001E04F8(void*)` | Matching | 100.00% | 8 |
| `func_001E0500(void*)` | Matching | 100.00% | 8 |
| `func_001E0508(void*)` | Matching | 100.00% | 8 |
| `func_001E0510` | Matching | 100.00% | 56 |
| `func_001E0548(void*)` | Matching | 100.00% | 40 |
| `func_001E0570` | Matching | 100.00% | 8 |
| `func_001E0578` | Matching | 100.00% | 56 |
| `func_001E05B0(void*)` | Matching | 100.00% | 40 |
| `func_001E05D8` | Matching | 100.00% | 8 |
| `func_001E05E0` | Matching | 100.00% | 44 |
| `func_001E0610` | Matching | 100.00% | 24 |
| `func_001E0628` | Matching | 100.00% | 28 |
| `func_001E0648` | Matching | 100.00% | 12 |
| `func_001E0658` | Matching | 100.00% | 28 |
| `func_001E0678` | Matching | 100.00% | 28 |
| `func_001E0698` | Matching | 100.00% | 52 |
| `func_001E06D0` | Matching | 100.00% | 28 |
| `func_001E06F0` | Matching | 100.00% | 24 |
| `func_001E0708` | Matching | 100.00% | 52 |
| `func_001E0740` | Matching | 100.00% | 48 |
| `func_001E0770(void*)` | Matching | 100.00% | 8 |
| `func_001E0778(void*)` | Matching | 100.00% | 8 |
| `func_001E0780` | Matching | 100.00% | 48 |
| `func_001E07B0(void*)` | Matching | 100.00% | 8 |
| `func_001E07B8(void*)` | Matching | 100.00% | 8 |
| `func_001E07C0` | Matching | 100.00% | 56 |
| `func_001E07F8(void*)` | Matching | 100.00% | 40 |
| `func_001E0820` | Matching | 100.00% | 56 |
| `func_001E0858(void*)` | Matching | 100.00% | 40 |
| `func_001E0880` | Matching | 100.00% | 76 |
| `func_001E08D0(void*)` | Matching | 100.00% | 8 |
| `func_001E08D8` | Matching | 100.00% | 60 |
| `func_001E0918(void*)` | Matching | 100.00% | 40 |
| `func_001E0940(void*)` | Matching | 100.00% | 8 |
| `func_001E0948(void*)` | Matching | 100.00% | 8 |
| `func_001E0950` | Matching | 100.00% | 76 |
| `func_001E09A0` | Matching | 100.00% | 92 |
| `func_001E0A00(void*)` | Matching | 100.00% | 8 |
| `func_001E0A08` | Matching | 100.00% | 68 |
| `func_001E0A50` | Matching | 100.00% | 104 |
| `func_001E0AB8(void*)` | Matching | 100.00% | 8 |
| `func_001E0AC0` | Matching | 100.00% | 64 |
| `func_001E0B00(void*)` | Matching | 100.00% | 40 |
| `func_001E0B28` | Matching | 100.00% | 120 |
| `func_001E0BA0(void*)` | Matching | 100.00% | 8 |
| `func_001E0BA8(void*)` | Matching | 100.00% | 8 |
| `func_001E0BB0` | Matching | 100.00% | 92 |
| `func_001E0C10(void*)` | Matching | 100.00% | 8 |
| `func_001E0C18(void*)` | Matching | 100.00% | 8 |
| `func_001E0C20(void*)` | Matching | 100.00% | 8 |
| `func_001E0C28(void*)` | Matching | 100.00% | 8 |
| `func_001E0C30` | Matching | 100.00% | 72 |
| `func_001E0C78(void*)` | Matching | 100.00% | 8 |
| `func_001E0C80(void*)` | Matching | 100.00% | 8 |
| `func_001E0C88(void*)` | Matching | 100.00% | 8 |
| `func_001E0C90(void*)` | Matching | 100.00% | 8 |
| `func_001E0C98(void*)` | Matching | 100.00% | 8 |
| `func_001E0CA0` | Matching | 100.00% | 88 |
| `func_001E0CF8` | Matching | 100.00% | 104 |
| `func_001E0D60(void*)` | Matching | 100.00% | 8 |
| `func_001E0D68` | Matching | 100.00% | 60 |
| `func_001E0DA8(void*)` | Matching | 100.00% | 40 |
| `func_001E0DD0(void*)` | Matching | 100.00% | 8 |
| `func_001E0DD8` | Matching | 100.00% | 60 |
| `func_001E0E18(void*)` | Matching | 100.00% | 40 |
| `func_001E0E40(void*)` | Matching | 100.00% | 8 |
| `func_001E0E48` | Matching | 100.00% | 64 |
| `func_001E0E88(void*)` | Matching | 100.00% | 8 |
| `func_001E0E90(void*)` | Matching | 100.00% | 8 |
| `func_001E0E98(void*)` | Matching | 100.00% | 40 |
| `func_001E0EC0(void*)` | Matching | 100.00% | 8 |
| `func_001E0EC8(void*)` | Matching | 100.00% | 40 |
| `func_001E0EF0(void*)` | Matching | 100.00% | 8 |
| `func_001E0EF8` | Matching | 100.00% | 56 |
| `func_001E0F30(void*)` | Matching | 100.00% | 40 |
| `func_001E0F58(void*)` | Matching | 100.00% | 8 |
| `func_001E0F60` | Matching | 100.00% | 88 |
| `func_001E0FB8(void*)` | Matching | 100.00% | 8 |
| `func_001E0FC0` | Matching | 100.00% | 44 |
| `func_001E0FF0` | Matching | 100.00% | 80 |
| `func_001E1040(void*)` | Matching | 100.00% | 8 |
| `func_001E1048` | Matching | 100.00% | 48 |
| `func_001E1078(void*)` | Matching | 100.00% | 8 |
| `func_001E1080(void*)` | Matching | 100.00% | 8 |
| `func_001E1088(void*)` | Matching | 100.00% | 8 |
| `func_001E1090` | Matching | 100.00% | 36 |
| `func_001E10B8` | Matching | 100.00% | 48 |
| `func_001E10E8(void*)` | Matching | 100.00% | 8 |
| `func_001E10F0(void*)` | Matching | 100.00% | 8 |
| `func_001E10F8(void*)` | Matching | 100.00% | 8 |
| `func_001E1100(void*)` | Matching | 100.00% | 8 |
| `func_001E1108` | Matching | 100.00% | 48 |
| `func_001E1138(void*)` | Matching | 100.00% | 8 |
| `func_001E1140(void*)` | Matching | 100.00% | 8 |
| `func_001E1148(void*)` | Matching | 100.00% | 8 |
| `func_001E1150(void*)` | Matching | 100.00% | 8 |
| `func_001E1158(void*)` | Matching | 100.00% | 8 |
| `func_001E1160(void*)` | Matching | 100.00% | 8 |
| `func_001E1168(void*)` | Matching | 100.00% | 8 |
| `func_001E1170(void*)` | Matching | 100.00% | 8 |
| `func_001E1178(void*)` | Matching | 100.00% | 8 |
| `func_001E1180(void*)` | Matching | 100.00% | 8 |
| `func_001E1188(void*)` | Matching | 100.00% | 8 |
| `func_001E1190(void*)` | Matching | 100.00% | 8 |
| `func_001E1198(void*)` | Matching | 100.00% | 8 |
| `func_001E11A0(void*)` | Matching | 100.00% | 8 |
| `func_001E11A8(void*)` | Matching | 100.00% | 8 |
| `func_001E11B0(void*)` | Matching | 100.00% | 8 |
| `func_001E11B8(void*)` | Matching | 100.00% | 8 |
| `func_001E11C0(void*)` | Matching | 100.00% | 8 |
| `func_001E11C8(void*)` | Matching | 100.00% | 8 |
| `func_001E11D0(void*)` | Matching | 100.00% | 8 |
| `func_001E11D8(void*)` | Matching | 100.00% | 8 |
| `func_001E11E0(void*)` | Matching | 100.00% | 8 |
| `func_001E11E8(void*)` | Matching | 100.00% | 8 |
| `func_001E11F0(void*)` | Matching | 100.00% | 8 |
| `func_001E11F8(void*)` | Matching | 100.00% | 8 |
| `func_001E1200(void*)` | Matching | 100.00% | 8 |
| `func_001E1208(void*)` | Matching | 100.00% | 8 |
| `func_001E1210(void*)` | Matching | 100.00% | 8 |
| `func_001E1218(void*)` | Matching | 100.00% | 8 |
| `func_001E1220(void*)` | Matching | 100.00% | 8 |
| `func_001E1228(void*)` | Matching | 100.00% | 8 |
| `func_001E1230(void*)` | Matching | 100.00% | 8 |
| `func_001E1238(void*)` | Matching | 100.00% | 8 |
| `func_001E1240(void*)` | Matching | 100.00% | 8 |
| `func_001E1248(void*)` | Matching | 100.00% | 12 |
| `func_001E1258(void*)` | Matching | 100.00% | 12 |
| `func_001E1268(void*)` | Matching | 100.00% | 12 |
| `func_001E1278(void*)` | Matching | 100.00% | 8 |
| `func_001E1280(void*)` | Matching | 100.00% | 8 |
| `func_001E1288(void*)` | Matching | 100.00% | 8 |
| `func_001E1290(void*)` | Matching | 100.00% | 8 |
| `func_001E1298(void*, int)` | Matching | 100.00% | 8 |
| `func_001E12A0(void*)` | Matching | 100.00% | 8 |
| `func_001E12A8(void*)` | Matching | 100.00% | 8 |
| `func_001E12B0(void*)` | Matching | 100.00% | 32 |
| `func_001E12D0(void*)` | Matching | 100.00% | 32 |
| `func_001E1450` | Matching | 100.00% | 8 |
| `func_001E14C0` | Matching | 100.00% | 136 |
| `func_001E1548(void*)` | Matching | 100.00% | 8 |
| `func_001E1550` | Matching | 100.00% | 1248 |
| `func_001E1A30` | Matching | 100.00% | 160 |
| `func_001E1AD0` | Matching | 100.00% | 316 |
| `func_001E1C10` | Matching | 100.00% | 448 |
| `func_001E1DD0` | Matching | 100.00% | 232 |
| `func_001E1EB8` | Matching | 100.00% | 536 |
| `func_001E20D0` | Matching | 100.00% | 332 |
| `func_001E2220` | Matching | 100.00% | 332 |
| `func_001E2370` | Matching | 100.00% | 184 |
| `func_001E2428` | Matching | 100.00% | 236 |
| `func_001E2518` | Matching | 100.00% | 96 |
| `func_001E2578` | Matching | 100.00% | 96 |
| `func_001E25D8` | Matching | 100.00% | 112 |
| `func_001E2648` | Matching | 100.00% | 480 |
| `func_001E2828` | Matching | 100.00% | 480 |
| `func_001E2A08` | Matching | 100.00% | 300 |
| `func_001E2B38` | Matching | 100.00% | 124 |
| `func_001E2BB8` | Matching | 100.00% | 164 |
| `func_001E2C60` | Matching | 100.00% | 28 |
| `func_001E2C80` | Matching | 100.00% | 216 |
| `func_001E2D58` | Matching | 100.00% | 60 |
| `func_001E2D98` | Matching | 100.00% | 36 |
| `func_001E2DC0` | Matching | 100.00% | 192 |
| `func_001E2E80` | Matching | 100.00% | 32 |
| `func_001E2EA0` | Matching | 100.00% | 320 |
| `func_001E2FE0` | Matching | 100.00% | 288 |
| `func_001E3100` | Matching | 100.00% | 180 |
| `func_001E31B8` | Matching | 100.00% | 176 |
| `func_001E3268` | Matching | 100.00% | 96 |
| `func_001E32C8` | Matching | 100.00% | 188 |
| `func_001E3388` | Matching | 100.00% | 92 |
| `func_001E33E8(void*)` | Matching | 100.00% | 32 |
| `func_001E3408` | Matching | 100.00% | 84 |
| `func_001E3460` | Matching | 100.00% | 116 |
| `func_001E34D8` | Matching | 100.00% | 56 |
| `func_001E3510` | Matching | 100.00% | 92 |
| `func_001E3570` | Matching | 100.00% | 128 |
| `func_001E35F0` | Matching | 100.00% | 44 |
| `func_001E3620` | Matching | 100.00% | 48 |
| `func_001E3650` | Matching | 100.00% | 48 |
| `func_001E3680` | Matching | 100.00% | 220 |
| `func_001E3760` | Matching | 100.00% | 344 |
| `func_001E38B8` | Matching | 100.00% | 316 |
| `func_001E39F8` | Matching | 100.00% | 52 |
| `func_001E3A30` | Matching | 100.00% | 68 |
| `func_001E3A78` | Matching | 100.00% | 80 |
| `func_001E3AC8` | Matching | 100.00% | 312 |
| `func_001E3C00` | Matching | 100.00% | 344 |
| `func_001E3D58` | Matching | 100.00% | 216 |
| `func_001E3E30` | Matching | 100.00% | 144 |
| `func_001E3EC0` | Matching | 100.00% | 676 |
| `func_001E4168` | Matching | 100.00% | 148 |
| `func_001E4200` | Matching | 100.00% | 596 |
| `func_001E4458` | Matching | 100.00% | 288 |
| `func_001E4610` | Matching | 100.00% | 72 |
| `func_001E4658` | Matching | 100.00% | 252 |
| `func_001E4758` | Matching | 100.00% | 232 |
| `func_001E4840` | Matching | 100.00% | 52 |
| `func_001E4878` | Matching | 100.00% | 52 |
| `func_001E48B0` | Matching | 100.00% | 720 |
| `func_001E4B80` | Matching | 100.00% | 248 |
| `func_001E4C78` | Matching | 100.00% | 760 |
| `func_001E4F70` | Matching | 100.00% | 340 |
| `func_001E50C8` | Matching | 100.00% | 128 |
| `func_001E5148` | Matching | 100.00% | 132 |
| `func_001E51D0` | Matching | 100.00% | 116 |
| `func_001E5248` | Matching | 100.00% | 100 |
| `func_001E52B0(void*)` | Matching | 100.00% | 28 |
| `func_001E52D0` | Matching | 100.00% | 36 |
| `func_001E52F8` | Matching | 100.00% | 304 |
| `func_001E5428` | Matching | 100.00% | 420 |
| `func_001E55D0` | Matching | 100.00% | 100 |
| `func_001E5638` | Matching | 100.00% | 328 |
| `func_001E5780` | Matching | 100.00% | 128 |
| `func_001E5800` | Matching | 100.00% | 224 |
| `func_001E58E0` | Matching | 100.00% | 308 |
| `func_001E5A18` | Matching | 100.00% | 136 |
| `func_001E5AA0` | Matching | 100.00% | 224 |
| `func_001E64A8(void*)` | Matching | 100.00% | 28 |
| `func_001E64C8` | Matching | 100.00% | 240 |
| `func_001E65B8` | Matching | 100.00% | 116 |
| `func_001E6630` | Matching | 100.00% | 16 |
| `func_001E6640` | Matching | 100.00% | 36 |
| `func_001E6668` | Matching | 100.00% | 172 |
| `func_001E7558` | Matching | 100.00% | 116 |
| `func_001E75D0` | Matching | 100.00% | 848 |
| `func_001E7920(void*)` | Matching | 100.00% | 8 |
| `func_001E7928` | Matching | 100.00% | 384 |
| `func_001E7AA8` | Matching | 100.00% | 204 |
| `func_001E7B78` | Matching | 100.00% | 16 |
| `func_001E7B88` | Matching | 100.00% | 36 |
| `func_001E8160` | Matching | 100.00% | 80 |
| `func_001E81D0` | Matching | 100.00% | 48 |
| `func_001E8200` | Matching | 100.00% | 1464 |
| `func_001E8880` | Matching | 100.00% | 80 |
| `func_001E88F0` | Matching | 100.00% | 48 |
| `func_001E8E70(void*)` | Matching | 100.00% | 28 |
| `func_001E8E90(void*)` | Matching | 100.00% | 8 |
| `func_001E8E98` | Matching | 100.00% | 16 |
| `func_001E8EA8` | Matching | 100.00% | 36 |
| `func_001E8ED0` | Matching | 100.00% | 48 |
| `func_001E8F00` | Matching | 100.00% | 192 |
| `func_001E8FC0(void*)` | Matching | 100.00% | 8 |
| `func_001E8FC8` | Matching | 100.00% | 36 |
| `func_001E7BB0` | Matching | 99.98% | 1252 |
| `func_001E8920` | Matching | 99.97% | 1360 |
| `func_001E8098` | Matching | 99.90% | 196 |
| `func_001E87B8` | Matching | 99.90% | 196 |
| `func_001E1458` | Matching | 99.80% | 100 |
| `func_001E81B0` | Partial | 88.12% | 32 |

### `fe/fereal`

21 matching, 0 partial, 1 not started (22 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFECustom_cFECustom` | Matching | 100.00% | 164 |
| `func_001A07C8` | Matching | 100.00% | 104 |
| `func_001A16C0` | Matching | 100.00% | 1528 |
| `func_001A1CB8` | Matching | 100.00% | 20 |
| `func_001A1CD0` | Matching | 100.00% | 20 |
| `func_001A1CE8` | Matching | 100.00% | 104 |
| `func_001A1D50` | Matching | 100.00% | 108 |
| `func_001A1DC0` | Matching | 100.00% | 252 |
| `cRealFE_load` | Matching | 100.00% | 616 |
| `func_001A2128` | Matching | 100.00% | 104 |
| `func_001A2190` | Matching | 100.00% | 116 |
| `func_001A2208` | Matching | 100.00% | 1428 |
| `func_001A27A0` | Matching | 100.00% | 864 |
| `cRealFE_loadCharAnimations` | Matching | 100.00% | 188 |
| `func_001A2BC0` | Matching | 100.00% | 128 |
| `cRealFE_loadStartState` | Matching | 100.00% | 476 |
| `func_001A2E20` | Matching | 100.00% | 56 |
| `func_001A2E58` | Matching | 100.00% | 220 |
| `func_001A2F38` | Matching | 100.00% | 56 |
| `func_001A2F70` | Matching | 100.00% | 220 |
| `func_001A3050` | Matching | 100.00% | 60 |

### `fe/feridermanager`

40 matching, 0 partial, 1 not started (41 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFERider_initBoneMap` | Matching | 100.00% | 368 |
| `func_0019E7F0` | Matching | 100.00% | 364 |
| `cFERider_init` | Matching | 100.00% | 576 |
| `func_0019EBA0` | Matching | 100.00% | 196 |
| `func_0019EC68` | Matching | 100.00% | 276 |
| `func_0019ED80` | Matching | 100.00% | 264 |
| `func_0019EE88` | Matching | 100.00% | 684 |
| `func_0019F138` | Matching | 100.00% | 408 |
| `func_0019F2D0` | Matching | 100.00% | 276 |
| `func_0019F3E8` | Matching | 100.00% | 44 |
| `func_0019F418` | Matching | 100.00% | 108 |
| `func_0019F488` | Matching | 100.00% | 192 |
| `func_0019F548` | Matching | 100.00% | 44 |
| `func_0019F578` | Matching | 100.00% | 108 |
| `func_0019F5E8` | Matching | 100.00% | 192 |
| `func_0019F6A8` | Matching | 100.00% | 32 |
| `func_0019F6C8` | Matching | 100.00% | 40 |
| `func_0019F6F0` | Matching | 100.00% | 36 |
| `func_0019F718` | Matching | 100.00% | 40 |
| `func_0019F740` | Matching | 100.00% | 32 |
| `func_0019F760` | Matching | 100.00% | 32 |
| `func_0019F780` | Matching | 100.00% | 244 |
| `func_0019F878` | Matching | 100.00% | 140 |
| `func_0019F908` | Matching | 100.00% | 368 |
| `func_0019FA78` | Matching | 100.00% | 360 |
| `func_0019FBE0` | Matching | 100.00% | 376 |
| `func_0019FD58` | Matching | 100.00% | 420 |
| `func_0019FF00` | Matching | 100.00% | 508 |
| `func_001A0358` | Matching | 100.00% | 104 |
| `func_001A03C0` | Matching | 100.00% | 92 |
| `func_001A0420` | Matching | 100.00% | 120 |
| `func_001A0498` | Matching | 100.00% | 44 |
| `func_001A04C8` | Matching | 100.00% | 64 |
| `func_001A0508` | Matching | 100.00% | 44 |
| `func_001A0538` | Matching | 100.00% | 16 |
| `func_001A0548` | Matching | 100.00% | 16 |
| `func_001A0558` | Matching | 100.00% | 20 |
| `func_001A0570` | Matching | 100.00% | 40 |
| `func_001A0598` | Matching | 100.00% | 108 |
| `func_001A0608` | Matching | 100.00% | 64 |

### `fe/festateaudiooptions`

7 matching, 0 partial, 1 not started (8 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateAudioOptions_onWidgetEvent` | Matching | 100.00% | 1060 |
| `func_00196B08` | Matching | 100.00% | 132 |
| `func_00196B90` | Matching | 100.00% | 540 |
| `func_00196DB0` | Matching | 100.00% | 208 |
| `func_00196E80` | Matching | 100.00% | 128 |
| `func_00196F00` | Matching | 100.00% | 80 |
| `func_00196F50` | Matching | 100.00% | 72 |

### `fe/festatebigradio`

16 matching, 0 partial, 1 not started (17 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateBraggingRights_onCreateScreen` | Matching | 100.00% | 1420 |
| `func_00193310(void*)` | Matching | 100.00% | 8 |
| `func_00193318(void*)` | Matching | 100.00% | 28 |
| `func_00193568` | Matching | 100.00% | 232 |
| `cFEStateBraggingRights_onWidgetCreate` | Matching | 100.00% | 676 |
| `func_001938F8` | Matching | 100.00% | 776 |
| `func_00193C00` | Matching | 100.00% | 244 |
| `func_00193CF8` | Matching | 100.00% | 228 |
| `func_00193DE0` | Matching | 100.00% | 344 |
| `func_00193F38` | Matching | 100.00% | 328 |
| `func_00194080` | Matching | 100.00% | 180 |
| `func_00194138` | Matching | 100.00% | 48 |
| `func_00194168` | Matching | 100.00% | 72 |
| `func_001941B0` | Matching | 100.00% | 652 |
| `func_00194440` | Matching | 100.00% | 84 |
| `func_00194498` | Matching | 100.00% | 140 |

### `fe/festatebonusmaterial`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateBonusMaterial_onCreateScreen` | Matching | 100.00% | 100 |
| `func_00195540` | Matching | 100.00% | 120 |
| `func_001955B8` | Matching | 100.00% | 36 |
| `func_001955E0(void*)` | Matching | 100.00% | 28 |
| `func_00195600` | Matching | 100.00% | 248 |

### `fe/festatebuyattrib`

30 matching, 0 partial, 1 not started (31 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateBuyAttrib_onCreateScreen` | Matching | 100.00% | 220 |
| `cFEStateBuyAttrib_onWidgetCreate` | Matching | 100.00% | 192 |
| `func_001F49D0` | Matching | 100.00% | 36 |
| `func_001F49F8` | Matching | 100.00% | 64 |
| `func_001F4A38` | Matching | 100.00% | 36 |
| `func_001F4A60` | Matching | 100.00% | 48 |
| `func_001F4A90` | Matching | 100.00% | 412 |
| `func_001F4C30` | Matching | 100.00% | 628 |
| `cFEStateBuyAttrib_updateLevels` | Matching | 100.00% | 276 |
| `cFEStateBuyAttrib_updateCostPerLevel` | Matching | 100.00% | 240 |
| `cFEStateBuyAttrib_updateExperienceDisplay` | Matching | 100.00% | 400 |
| `cFEStateBuyAttrib_updateTotalCost` | Matching | 100.00% | 96 |
| `cFEStateBuyAttrib_updateBank` | Matching | 100.00% | 96 |
| `func_001F5300` | Matching | 100.00% | 420 |
| `func_001F54A8` | Matching | 100.00% | 8 |
| `func_001F54B0` | Matching | 100.00% | 84 |
| `cFEStateCareerStats_onCreateScreen` | Matching | 100.00% | 184 |
| `func_001F55C0` | Matching | 100.00% | 36 |
| `func_001F55E8` | Matching | 100.00% | 48 |
| `func_001F5618` | Matching | 100.00% | 52 |
| `func_001F5650` | Matching | 100.00% | 116 |
| `cFEStateCareerStats_onInputBegin` | Matching | 100.00% | 876 |
| `func_001F5A38` | Matching | 100.00% | 364 |
| `cFEStateCareerStats_setupMenuFocus` | Matching | 100.00% | 504 |
| `cFEStateCareerStats_setupHighlightsList` | Matching | 100.00% | 832 |
| `func_001F60E0` | Matching | 100.00% | 940 |
| `func_001F6490` | Matching | 100.00% | 944 |
| `func_001F6840` | Matching | 100.00% | 80 |
| `func_001F6EE0` | Matching | 100.00% | 76 |
| `func_001F6F30` | Matching | 100.00% | 612 |

### `fe/festatecharequip`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFE_cFE` | Matching | 100.00% | 212 |
| `func_001957D0` | Matching | 100.00% | 172 |
| `func_00195880` | Matching | 100.00% | 108 |
| `func_001958F0` | Matching | 100.00% | 88 |
| `func_00195948` | Matching | 100.00% | 92 |

### `fe/festatecharequipdetail`

81 matching, 0 partial, 8 not started (89 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateCharEquip_cFEStateCharEquip` | Matching | 100.00% | 908 |
| `func_00199148` | Matching | 100.00% | 244 |
| `cFEStateCharEquip_onCreateScreen` | Matching | 100.00% | 268 |
| `func_00199350` | Matching | 100.00% | 80 |
| `func_001993A0` | Matching | 100.00% | 128 |
| `func_00199420` | Matching | 100.00% | 52 |
| `func_00199870` | Matching | 100.00% | 196 |
| `cFEStateCharEquip_onUpdate` | Matching | 100.00% | 256 |
| `func_00199A38` | Matching | 100.00% | 492 |
| `func_00199C28` | Matching | 100.00% | 760 |
| `func_00199F20` | Matching | 100.00% | 372 |
| `func_0019A098` | Matching | 100.00% | 324 |
| `func_0019A1E0` | Matching | 100.00% | 88 |
| `func_0019A238` | Matching | 100.00% | 204 |
| `func_0019A308` | Matching | 100.00% | 196 |
| `func_0019A3D0` | Matching | 100.00% | 200 |
| `func_0019A498` | Matching | 100.00% | 76 |
| `func_0019A4E8` | Matching | 100.00% | 332 |
| `func_0019A638` | Matching | 100.00% | 284 |
| `func_0019A758` | Matching | 100.00% | 64 |
| `func_0019A798` | Matching | 100.00% | 544 |
| `func_0019A9B8` | Matching | 100.00% | 80 |
| `func_0019AA08` | Matching | 100.00% | 364 |
| `func_0019AB78` | Matching | 100.00% | 296 |
| `func_0019ACA0` | Matching | 100.00% | 116 |
| `func_0019AFD0` | Matching | 100.00% | 200 |
| `func_0019B098` | Matching | 100.00% | 228 |
| `func_0019B458` | Matching | 100.00% | 188 |
| `func_0019B518` | Matching | 100.00% | 124 |
| `func_0019B598` | Matching | 100.00% | 124 |
| `func_0019B618` | Matching | 100.00% | 456 |
| `func_0019B7E0` | Matching | 100.00% | 640 |
| `func_0019BA60` | Matching | 100.00% | 316 |
| `func_0019BBA0` | Matching | 100.00% | 64 |
| `cFEStateCharEquip_updateHeading` | Matching | 100.00% | 176 |
| `func_0019BC90` | Matching | 100.00% | 180 |
| `func_0019BD48` | Matching | 100.00% | 308 |
| `func_0019BE80` | Matching | 100.00% | 104 |
| `func_0019BEE8` | Matching | 100.00% | 248 |
| `func_0019BFE0` | Matching | 100.00% | 8 |
| `func_0019C7E8` | Matching | 100.00% | 148 |
| `func_0019C880` | Matching | 100.00% | 80 |
| `func_0019C8D0` | Matching | 100.00% | 36 |
| `func_0019C8F8` | Matching | 100.00% | 36 |
| `func_0019C920` | Matching | 100.00% | 24 |
| `func_0019C938` | Matching | 100.00% | 308 |
| `func_0019CA70` | Matching | 100.00% | 200 |
| `func_0019CB38` | Matching | 100.00% | 40 |
| `func_0019CB60` | Matching | 100.00% | 128 |
| `func_0019CBE0` | Matching | 100.00% | 76 |
| `func_0019CC30` | Matching | 100.00% | 180 |
| `func_0019CCE8` | Matching | 100.00% | 76 |
| `func_0019CD38` | Matching | 100.00% | 180 |
| `func_0019CDF0` | Matching | 100.00% | 44 |
| `func_0019CE20` | Matching | 100.00% | 72 |
| `func_0019CE68` | Matching | 100.00% | 216 |
| `func_0019CF40` | Matching | 100.00% | 192 |
| `func_0019D000` | Matching | 100.00% | 316 |
| `func_0019D3B0` | Matching | 100.00% | 116 |
| `func_0019D428` | Matching | 100.00% | 144 |
| `func_0019D4B8` | Matching | 100.00% | 188 |
| `func_0019D578` | Matching | 100.00% | 444 |
| `func_0019D738` | Matching | 100.00% | 380 |
| `func_0019D8B8` | Matching | 100.00% | 344 |
| `func_0019DA10` | Matching | 100.00% | 528 |
| `func_0019DC20` | Matching | 100.00% | 240 |
| `func_0019DD10` | Matching | 100.00% | 260 |
| `func_0019DE18` | Matching | 100.00% | 260 |
| `func_0019E1C0` | Matching | 100.00% | 68 |
| `func_0019E208` | Matching | 100.00% | 44 |
| `func_0019E238` | Matching | 100.00% | 44 |
| `func_0019E268` | Matching | 100.00% | 68 |
| `func_0019E2B0` | Matching | 100.00% | 64 |
| `func_0019E2F0` | Matching | 100.00% | 64 |
| `func_0019E330` | Matching | 100.00% | 80 |
| `func_0019E380` | Matching | 100.00% | 36 |
| `func_0019E3A8` | Matching | 100.00% | 36 |
| `func_0019E498` | Matching | 100.00% | 160 |
| `func_0019E538` | Matching | 100.00% | 80 |
| `func_0019E588` | Matching | 100.00% | 248 |
| `func_0019D250` | Matching | 99.94% | 352 |

### `fe/festatecharselect`

17 matching, 0 partial, 1 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateCharSelect_onCreateScreen` | Matching | 100.00% | 240 |
| `func_00181238` | Matching | 100.00% | 108 |
| `func_001812A8` | Matching | 100.00% | 92 |
| `func_00181308` | Matching | 100.00% | 244 |
| `func_00181400(void*)` | Matching | 100.00% | 28 |
| `func_00181420` | Matching | 100.00% | 44 |
| `func_00181450` | Matching | 100.00% | 460 |
| `cFEStateCharSelect_onWidgetCreate` | Matching | 100.00% | 452 |
| `func_001817E8` | Matching | 100.00% | 1000 |
| `func_00181BD0` | Matching | 100.00% | 796 |
| `func_00182220` | Matching | 100.00% | 512 |
| `func_00182420` | Matching | 100.00% | 100 |
| `cFEStateCheatCharSelect_onWidgetCreate` | Matching | 100.00% | 516 |
| `func_00182690` | Matching | 100.00% | 376 |
| `func_00182808` | Matching | 100.00% | 104 |
| `func_00182870` | Matching | 100.00% | 80 |
| `func_001828C0` | Matching | 100.00% | 104 |

### `fe/festatecharsetup`

9 matching, 0 partial, 0 not started (9 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateCharSetup_onCreateScreen` | Matching | 100.00% | 736 |
| `func_00182C08` | Matching | 100.00% | 48 |
| `func_00182C38` | Matching | 100.00% | 44 |
| `func_00182C68` | Matching | 100.00% | 20 |
| `func_00182C80` | Matching | 100.00% | 312 |
| `func_00182DB8` | Matching | 100.00% | 264 |
| `func_00182EC0` | Matching | 100.00% | 784 |
| `func_001831D0` | Matching | 100.00% | 104 |
| `func_00183238` | Matching | 100.00% | 108 |

### `fe/festatecredits`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateCredits_onCreateScreen` | Matching | 100.00% | 264 |
| `cFEStateCredits_onGainFocus` | Matching | 100.00% | 924 |
| `func_00185F40` | Matching | 100.00% | 1140 |
| `func_001863B8` | Matching | 100.00% | 44 |
| `func_001863E8` | Matching | 100.00% | 144 |
| `func_00186478` | Matching | 100.00% | 52 |
| `func_001864B0` | Matching | 100.00% | 104 |
| `func_00186518` | Matching | 100.00% | 140 |
| `func_001865A8` | Matching | 100.00% | 104 |
| `func_00186610` | Matching | 100.00% | 68 |

### `fe/festatedebug`

3 matching, 0 partial, 0 not started (3 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cScreenKeyboard_initScreenKeyboard` | Matching | 100.00% | 908 |
| `func_00180EF0` | Matching | 100.00% | 416 |
| `func_00181090` | Matching | 100.00% | 180 |

### `fe/festatelegal`

3 matching, 0 partial, 1 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateLegal_onCreateScreen` | Matching | 100.00% | 104 |
| `func_00187CB8` | Matching | 100.00% | 124 |
| `func_001887A0` | Matching | 100.00% | 92 |

### `fe/festateload`

13 matching, 0 partial, 0 not started (13 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateEventSelect_onCreateScreen` | Matching | 100.00% | 176 |
| `func_00186708(void*)` | Matching | 100.00% | 28 |
| `func_00186728(void*)` | Matching | 100.00% | 28 |
| `func_00186748` | Matching | 100.00% | 44 |
| `func_00186778` | Matching | 100.00% | 44 |
| `func_001867A8` | Matching | 100.00% | 420 |
| `func_00186950` | Matching | 100.00% | 40 |
| `func_00186978` | Matching | 100.00% | 28 |
| `func_00186998` | Matching | 100.00% | 64 |
| `func_001869D8` | Matching | 100.00% | 44 |
| `func_00186A08` | Matching | 100.00% | 268 |
| `func_00186B18` | Matching | 100.00% | 44 |
| `func_00186B48(void*)` | Matching | 100.00% | 8 |

### `fe/festateloadhint`

25 matching, 0 partial, 2 not started (27 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFELoadHintState_onCreateScreen` | Matching | 100.00% | 400 |
| `func_00245AE0` | Matching | 100.00% | 112 |
| `func_00245B50(void*)` | Matching | 100.00% | 8 |
| `func_00245B58` | Matching | 100.00% | 40 |
| `cFELoadState_onCreateScreen` | Matching | 100.00% | 224 |
| `func_00245C60` | Matching | 100.00% | 112 |
| `func_00245CD0` | Matching | 100.00% | 88 |
| `func_00245D28` | Matching | 100.00% | 40 |
| `cFELoadStateInLodge_onCreateScreen` | Matching | 100.00% | 100 |
| `func_00245DB8(void*)` | Matching | 100.00% | 8 |
| `func_00245DC0` | Matching | 100.00% | 112 |
| `func_00245E30` | Matching | 100.00% | 68 |
| `func_00245E78` | Matching | 100.00% | 68 |
| `func_00245EC0` | Matching | 100.00% | 60 |
| `func_00245F00` | Matching | 100.00% | 48 |
| `func_00245F30(void*)` | Matching | 100.00% | 28 |
| `func_00245F50` | Matching | 100.00% | 324 |
| `func_00246098` | Matching | 100.00% | 328 |
| `func_002461E0` | Matching | 100.00% | 132 |
| `func_00246268` | Matching | 100.00% | 16 |
| `func_00246278` | Matching | 100.00% | 620 |
| `func_002464E8` | Matching | 100.00% | 2060 |
| `cFELoadState_widgetCreateQP` | Matching | 100.00% | 880 |
| `func_00247E20(void*)` | Matching | 100.00% | 32 |
| `func_00247E40(void*)` | Matching | 100.00% | 32 |

### `fe/festateloadscreen`

29 matching, 0 partial, 0 not started (29 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFELoadScreen_load` | Matching | 100.00% | 520 |
| `func_00233640` | Matching | 100.00% | 644 |
| `func_002338C8` | Matching | 100.00% | 100 |
| `func_00233930` | Matching | 100.00% | 200 |
| `func_002339F8` | Matching | 100.00% | 116 |
| `func_00233A70` | Matching | 100.00% | 48 |
| `func_00233AA0` | Matching | 100.00% | 44 |
| `func_00233AD0` | Matching | 100.00% | 32 |
| `func_00233AF0` | Matching | 100.00% | 52 |
| `func_00233B28` | Matching | 100.00% | 52 |
| `func_00233B60` | Matching | 100.00% | 40 |
| `func_00233B88(void*)` | Matching | 100.00% | 8 |
| `func_00233B90(void*)` | Matching | 100.00% | 28 |
| `func_00233BB0(void*)` | Matching | 100.00% | 28 |
| `func_00233BD0(void*)` | Matching | 100.00% | 28 |
| `func_00233BF0(void*)` | Matching | 100.00% | 28 |
| `func_00233C10` | Matching | 100.00% | 64 |
| `func_00233C50` | Matching | 100.00% | 132 |
| `func_00233CD8` | Matching | 100.00% | 816 |
| `func_00234008` | Matching | 100.00% | 172 |
| `func_002340B8` | Matching | 100.00% | 104 |
| `func_00234120` | Matching | 100.00% | 104 |
| `func_00234188` | Matching | 100.00% | 72 |
| `func_002341D0` | Matching | 100.00% | 480 |
| `func_002343B0` | Matching | 100.00% | 928 |
| `func_00234750` | Matching | 100.00% | 448 |
| `func_00234910` | Matching | 100.00% | 128 |
| `func_00234990` | Matching | 100.00% | 160 |
| `func_00234A30` | Matching | 100.00% | 160 |

### `fe/festatelodge`

13 matching, 0 partial, 0 not started (13 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateLodge_onCreateScreen` | Matching | 100.00% | 176 |
| `cFEStateLodge_onWidgetCreate` | Matching | 100.00% | 500 |
| `func_001F3A38` | Matching | 100.00% | 652 |
| `func_001F3CC8` | Matching | 100.00% | 36 |
| `func_001F3CF0` | Matching | 100.00% | 776 |
| `func_001F3FF8` | Matching | 100.00% | 84 |
| `cFEStateLodgeRiderDetail_onCreateScreen` | Matching | 100.00% | 180 |
| `func_001F4108` | Matching | 100.00% | 272 |
| `cFEStateLodgeRiderDetail_onWidgetCreate` | Matching | 100.00% | 360 |
| `func_001F4380` | Matching | 100.00% | 84 |
| `func_001F43D8` | Matching | 100.00% | 36 |
| `func_001F4400` | Matching | 100.00% | 808 |
| `func_001F4728` | Matching | 100.00% | 264 |

### `fe/festatenethelppopup`

24 matching, 0 partial, 0 not started (24 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateNetHelpPopup_onCreateScreen` | Matching | 100.00% | 100 |
| `func_001D9E20` | Matching | 100.00% | 72 |
| `func_001D9E68` | Matching | 100.00% | 196 |
| `func_001D9F30(void*)` | Matching | 100.00% | 8 |
| `cFEStateNetHelpPopup_onWidgetCreate` | Matching | 100.00% | 472 |
| `func_001DA110` | Matching | 100.00% | 292 |
| `func_001DA238` | Matching | 100.00% | 572 |
| `func_001DA478` | Matching | 100.00% | 44 |
| `func_001DA4A8` | Matching | 100.00% | 100 |
| `func_001DA510(void*, int, int, int)` | Matching | 100.00% | 24 |
| `func_001DA528(void*, int)` | Matching | 100.00% | 8 |
| `func_001DA530(void*, int, int)` | Matching | 100.00% | 16 |
| `func_001DA540` | Matching | 100.00% | 60 |
| `func_001DA580` | Matching | 100.00% | 104 |
| `func_001DA5E8` | Matching | 100.00% | 96 |
| `func_001DA648` | Matching | 100.00% | 412 |
| `func_001DA7E8` | Matching | 100.00% | 412 |
| `func_001DA988` | Matching | 100.00% | 320 |
| `func_001DAAC8` | Matching | 100.00% | 260 |
| `func_001DABD0` | Matching | 100.00% | 232 |
| `func_001DACB8` | Matching | 100.00% | 356 |
| `func_001DAE20` | Matching | 100.00% | 232 |
| `func_001DAF08` | Matching | 100.00% | 288 |
| `func_001DB028` | Matching | 100.00% | 284 |

### `fe/festateoptions`

57 matching, 1 partial, 1 not started (59 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateOptions_onCreateScreen` | Matching | 100.00% | 112 |
| `func_00188870` | Matching | 100.00% | 268 |
| `func_00188980` | Matching | 100.00% | 728 |
| `func_00188C58` | Matching | 100.00% | 16 |
| `func_00188C68` | Matching | 100.00% | 156 |
| `func_00188D08` | Matching | 100.00% | 332 |
| `func_00188E58` | Matching | 100.00% | 144 |
| `func_00188EE8` | Matching | 100.00% | 60 |
| `cFEStateOptionsGame_onCreateScreen` | Matching | 100.00% | 1736 |
| `func_001895F0(void*)` | Matching | 100.00% | 28 |
| `func_00189610` | Matching | 100.00% | 836 |
| `func_00189958` | Matching | 100.00% | 20 |
| `func_00189970` | Matching | 100.00% | 12 |
| `cFEStateOptionsGame_onWidgetEvent` | Matching | 100.00% | 992 |
| `func_00189D60` | Matching | 100.00% | 1272 |
| `func_0018A258` | Matching | 100.00% | 64 |
| `cFEStateOptionsSound_onCreateScreen` | Matching | 100.00% | 320 |
| `func_0018A3D8` | Matching | 100.00% | 1176 |
| `func_0018A870(void*)` | Matching | 100.00% | 28 |
| `func_0018A890` | Matching | 100.00% | 44 |
| `func_0018A8C0` | Matching | 100.00% | 12 |
| `func_0018A8D0` | Matching | 100.00% | 2732 |
| `func_0018BEF8` | Matching | 100.00% | 492 |
| `func_0018C0E8` | Matching | 100.00% | 64 |
| `func_0018C128` | Matching | 100.00% | 108 |
| `func_0018C198(void*)` | Matching | 100.00% | 28 |
| `func_0018C1B8` | Matching | 100.00% | 184 |
| `func_0018C270` | Matching | 100.00% | 44 |
| `func_0018C2A0` | Matching | 100.00% | 468 |
| `func_0018C478` | Matching | 100.00% | 480 |
| `func_0018C658` | Matching | 100.00% | 68 |
| `cFEStateOptionsController_onCreateScreen` | Matching | 100.00% | 536 |
| `func_0018C8B8` | Matching | 100.00% | 88 |
| `func_0018C910` | Matching | 100.00% | 252 |
| `func_0018CA10` | Matching | 100.00% | 720 |
| `func_0018CCE0` | Matching | 100.00% | 208 |
| `func_0018CDB0` | Matching | 100.00% | 12 |
| `func_0018CDC0` | Matching | 100.00% | 396 |
| `func_0018CF50` | Matching | 100.00% | 260 |
| `func_0018D058` | Matching | 100.00% | 172 |
| `func_0018D108` | Matching | 100.00% | 312 |
| `func_0018D240` | Matching | 100.00% | 64 |
| `cFEStateOptionsSaveLoad_onCreateScreen` | Matching | 100.00% | 100 |
| `cFEStateOptionsSaveLoad_onWidgetCreate` | Matching | 100.00% | 212 |
| `func_0018D3C0` | Matching | 100.00% | 120 |
| `func_0018D438` | Matching | 100.00% | 36 |
| `func_0018D460` | Matching | 100.00% | 488 |
| `cFEStateOptionsSaveLoad_onWidgetEvent` | Matching | 100.00% | 424 |
| `func_0018D7F0` | Matching | 100.00% | 116 |
| `cFEStateOptionsDeviceSelect_onCreateScreen` | Matching | 100.00% | 1384 |
| `func_0018DDD0` | Matching | 100.00% | 204 |
| `func_0018DEA0` | Matching | 100.00% | 724 |
| `func_0018E178` | Matching | 100.00% | 324 |
| `func_0018E2C0` | Matching | 100.00% | 168 |
| `func_0018E368` | Matching | 100.00% | 268 |
| `func_0018E478` | Matching | 100.00% | 148 |
| `func_0018EA98` | Matching | 100.00% | 60 |
| `cFEStateOptionsSound_updateWidget` | Partial | 99.86% | 2932 |

### `fe/festateprofile`

20 matching, 0 partial, 1 not started (21 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateProfileSelect_onCreateScreen` | Matching | 100.00% | 100 |
| `func_0018EB40` | Matching | 100.00% | 352 |
| `func_0018ECA0` | Matching | 100.00% | 292 |
| `cFEStateProfileLoad_onCreateScreen` | Matching | 100.00% | 208 |
| `func_0018EE98(void*)` | Matching | 100.00% | 28 |
| `func_0018EEB8` | Matching | 100.00% | 180 |
| `func_0018EF70` | Matching | 100.00% | 328 |
| `func_0018F0B8` | Matching | 100.00% | 172 |
| `func_0018F168` | Matching | 100.00% | 272 |
| `func_0018F278` | Matching | 100.00% | 60 |
| `func_0018F9D8` | Matching | 100.00% | 280 |
| `func_0018FAF0` | Matching | 100.00% | 384 |
| `func_0018FC70(void*)` | Matching | 100.00% | 40 |
| `func_0018FC98` | Matching | 100.00% | 244 |
| `func_0018FD90` | Matching | 100.00% | 1324 |
| `func_001902C0` | Matching | 100.00% | 636 |
| `cFEStateProfileLoad_initCreateScreen` | Matching | 100.00% | 300 |
| `func_00190670` | Matching | 100.00% | 248 |
| `func_00190768` | Matching | 100.00% | 236 |
| `func_00190858` | Matching | 100.00% | 100 |

### `fe/festaterewards`

74 matching, 0 partial, 1 not started (75 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateRewardGalleryBase_onCreateScreen` | Matching | 100.00% | 184 |
| `func_001CF168` | Matching | 100.00% | 204 |
| `func_001CF238` | Matching | 100.00% | 52 |
| `cFEStateRewardGalleryBase_onWidgetCreate` | Matching | 100.00% | 1268 |
| `func_001CFD18` | Matching | 100.00% | 184 |
| `func_001CFDD0` | Matching | 100.00% | 140 |
| `func_001CFE60` | Matching | 100.00% | 172 |
| `func_001CFF10` | Matching | 100.00% | 232 |
| `func_001CFFF8` | Matching | 100.00% | 200 |
| `func_001D00C0` | Matching | 100.00% | 188 |
| `func_001D0180` | Matching | 100.00% | 180 |
| `func_001D0238` | Matching | 100.00% | 228 |
| `func_001D0320` | Matching | 100.00% | 212 |
| `cFEStateRewardGalleryBase_showReward` | Matching | 100.00% | 280 |
| `func_001D0510` | Matching | 100.00% | 220 |
| `func_001D05F0` | Matching | 100.00% | 84 |
| `cFEStateRewardGalleryBase_updateHelpText` | Matching | 100.00% | 580 |
| `cFEStateRewardGalleryBase_updateRow` | Matching | 100.00% | 624 |
| `func_001D0B00` | Matching | 100.00% | 200 |
| `cFEStateRewardGalleryBase_updatePageNumber` | Matching | 100.00% | 356 |
| `func_001D0D30` | Matching | 100.00% | 328 |
| `func_001D0E78` | Matching | 100.00% | 64 |
| `func_001D0EB8` | Matching | 100.00% | 120 |
| `func_001D0F30` | Matching | 100.00% | 376 |
| `func_001D10A8` | Matching | 100.00% | 124 |
| `func_001D1128` | Matching | 100.00% | 112 |
| `func_001D1198(void*)` | Matching | 100.00% | 12 |
| `func_001D11A8` | Matching | 100.00% | 76 |
| `func_001D11F8` | Matching | 100.00% | 148 |
| `func_001D1290` | Matching | 100.00% | 52 |
| `func_001D12C8` | Matching | 100.00% | 104 |
| `func_001D1330(void*)` | Matching | 100.00% | 12 |
| `func_001D1340` | Matching | 100.00% | 76 |
| `func_001D1390` | Matching | 100.00% | 148 |
| `func_001D1428` | Matching | 100.00% | 52 |
| `func_001D1460` | Matching | 100.00% | 104 |
| `func_001D14C8(void*)` | Matching | 100.00% | 12 |
| `func_001D14D8` | Matching | 100.00% | 76 |
| `func_001D1528` | Matching | 100.00% | 148 |
| `func_001D15C0` | Matching | 100.00% | 52 |
| `func_001D15F8` | Matching | 100.00% | 104 |
| `func_001D1660(void*)` | Matching | 100.00% | 12 |
| `func_001D1670` | Matching | 100.00% | 76 |
| `func_001D16C0` | Matching | 100.00% | 148 |
| `func_001D1758` | Matching | 100.00% | 52 |
| `func_001D1790` | Matching | 100.00% | 104 |
| `func_001D17F8(void*)` | Matching | 100.00% | 12 |
| `func_001D1808` | Matching | 100.00% | 76 |
| `func_001D1858` | Matching | 100.00% | 148 |
| `func_001D18F0` | Matching | 100.00% | 52 |
| `func_001D1928` | Matching | 100.00% | 104 |
| `func_001D1990` | Matching | 100.00% | 148 |
| `func_001D1A28` | Matching | 100.00% | 52 |
| `func_001D1A60` | Matching | 100.00% | 64 |
| `func_001D1AA0` | Matching | 100.00% | 196 |
| `func_001D1B68` | Matching | 100.00% | 156 |
| `cFEStatePreviewReward_onCreateScreen` | Matching | 100.00% | 144 |
| `cFEStatePreviewReward_onWidgetCreate` | Matching | 100.00% | 732 |
| `func_001D1F78` | Matching | 100.00% | 52 |
| `func_001D1FB0` | Matching | 100.00% | 60 |
| `func_001D1FF0` | Matching | 100.00% | 232 |
| `func_001D20D8` | Matching | 100.00% | 116 |
| `func_001D2150` | Matching | 100.00% | 72 |
| `func_001D2198` | Matching | 100.00% | 340 |
| `func_001D22F0` | Matching | 100.00% | 144 |
| `func_001D2380` | Matching | 100.00% | 96 |
| `func_001D23E0` | Matching | 100.00% | 76 |
| `func_001D2430` | Matching | 100.00% | 56 |
| `func_001D2468` | Matching | 100.00% | 64 |
| `func_001D24A8` | Matching | 100.00% | 108 |
| `func_001D2518` | Matching | 100.00% | 124 |
| `func_001D2598` | Matching | 100.00% | 80 |
| `func_001D25E8` | Matching | 100.00% | 80 |
| `func_001D2638` | Matching | 100.00% | 64 |

### `fe/festateriderbio`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateRiderDetail_onCreateScreen` | Matching | 100.00% | 296 |
| `func_001833D0` | Matching | 100.00% | 384 |
| `func_00183550` | Matching | 100.00% | 84 |
| `func_001835A8(void*)` | Matching | 100.00% | 28 |
| `func_001835C8` | Matching | 100.00% | 44 |
| `func_001835F8` | Matching | 100.00% | 280 |
| `func_00183710` | Matching | 100.00% | 900 |
| `func_00183A98` | Matching | 100.00% | 112 |
| `func_00183B08` | Matching | 100.00% | 256 |
| `func_00183C08` | Matching | 100.00% | 256 |
| `func_00183D08` | Matching | 100.00% | 216 |

### `fe/festateriderbiodetail`

9 matching, 0 partial, 0 not started (9 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateRiderBio_onCreateScreen` | Matching | 100.00% | 328 |
| `func_00190A08` | Matching | 100.00% | 720 |
| `func_00190CD8` | Matching | 100.00% | 264 |
| `cFEStateRiderBio_fillDNAInfo` | Matching | 100.00% | 360 |
| `cFEStateRiderBio_fillFavesInfo` | Matching | 100.00% | 372 |
| `cFEStateRiderBio_fillQnAInfo` | Matching | 100.00% | 360 |
| `cFEStateRiderBio_fillBioInfo` | Matching | 100.00% | 164 |
| `func_001912D0` | Matching | 100.00% | 144 |
| `func_00191360` | Matching | 100.00% | 88 |

### `fe/festateruleselect`

18 matching, 0 partial, 0 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateRuleSelect_setupMenu` | Matching | 100.00% | 1408 |
| `cFEStateRuleSelect_onCreateScreen` | Matching | 100.00% | 780 |
| `func_00191C48(void*)` | Matching | 100.00% | 28 |
| `func_00191C68` | Matching | 100.00% | 416 |
| `func_00191E08` | Matching | 100.00% | 60 |
| `func_00191E48` | Matching | 100.00% | 572 |
| `func_00192240` | Matching | 100.00% | 316 |
| `func_00192380` | Matching | 100.00% | 260 |
| `cFEStateRuleSelect_updateMenuColor` | Matching | 100.00% | 612 |
| `func_001926F0` | Matching | 100.00% | 76 |
| `func_00192740` | Matching | 100.00% | 108 |
| `func_001927B0` | Matching | 100.00% | 356 |
| `func_00192918` | Matching | 100.00% | 48 |
| `func_00192948` | Matching | 100.00% | 28 |
| `func_00192968(void*, int)` | Matching | 100.00% | 8 |
| `func_00192970` | Matching | 100.00% | 908 |
| `func_00192D00` | Matching | 100.00% | 128 |
| `func_00192088` | Matching | 99.91% | 440 |

### `fe/festateselectmp`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateSelectMultiplayerMode_onCreateScreen` | Matching | 100.00% | 100 |
| `func_001A30F8` | Matching | 100.00% | 100 |
| `func_001A3160` | Matching | 100.00% | 184 |
| `func_001A3218` | Matching | 100.00% | 60 |

### `fe/festatestore`

14 matching, 0 partial, 0 not started (14 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateUberTrick_costVisible` | Matching | 100.00% | 276 |
| `func_00184780` | Matching | 100.00% | 164 |
| `cFEStateUberTrick_trickVisible` | Matching | 100.00% | 388 |
| `func_001849B0` | Matching | 100.00% | 448 |
| `func_00184B70` | Matching | 100.00% | 68 |
| `func_00184BB8` | Matching | 100.00% | 36 |
| `func_00184BE0` | Matching | 100.00% | 124 |
| `func_00184C60` | Matching | 100.00% | 736 |
| `func_00184F40` | Matching | 100.00% | 320 |
| `cFEStateUberTrick_onWidgetCreate` | Matching | 100.00% | 488 |
| `func_00185268` | Matching | 100.00% | 1904 |
| `func_001859D8` | Matching | 100.00% | 60 |
| `func_00185A18` | Matching | 100.00% | 88 |
| `func_00185A70(void*)` | Matching | 100.00% | 40 |

### `fe/festatetransition`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateBackground_onCreateScreen` | Matching | 100.00% | 96 |
| `cFEStateTransition_onCreateScreen` | Matching | 100.00% | 120 |
| `cFEStateTransition_onScreenEvent` | Matching | 100.00% | 168 |
| `func_001946A8` | Matching | 100.00% | 140 |
| `func_00194738` | Matching | 100.00% | 60 |

### `fe/festatetrophyroom`

35 matching, 0 partial, 1 not started (36 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateTrophyRoom_onCreateScreen` | Matching | 100.00% | 100 |
| `func_001D43D0(void*)` | Matching | 100.00% | 28 |
| `cFEStateTrophyRoom_onWidgetCreate` | Matching | 100.00% | 620 |
| `func_001D4660` | Matching | 100.00% | 52 |
| `func_001D4698` | Matching | 100.00% | 196 |
| `func_001D4760` | Matching | 100.00% | 60 |
| `func_001D47A0` | Matching | 100.00% | 236 |
| `func_001D4890` | Matching | 100.00% | 136 |
| `func_001D4918` | Matching | 100.00% | 264 |
| `func_001D4A20` | Matching | 100.00% | 252 |
| `func_001D4B20` | Matching | 100.00% | 168 |
| `func_001D4BC8` | Matching | 100.00% | 148 |
| `cFEStateRewardsRoom_onCreateScreen` | Matching | 100.00% | 120 |
| `cFEStateRewardsRoom_onWidgetCreate` | Matching | 100.00% | 460 |
| `func_001D4EA8` | Matching | 100.00% | 192 |
| `func_001D4F68` | Matching | 100.00% | 36 |
| `func_001D4F90` | Matching | 100.00% | 164 |
| `func_001D5038` | Matching | 100.00% | 60 |
| `func_001D5078` | Matching | 100.00% | 100 |
| `func_001D50E0` | Matching | 100.00% | 88 |
| `func_001D5138` | Matching | 100.00% | 264 |
| `func_001D5240` | Matching | 100.00% | 60 |
| `func_001D5280` | Matching | 100.00% | 176 |
| `func_001D5330` | Matching | 100.00% | 128 |
| `func_001D53B0` | Matching | 100.00% | 116 |
| `func_001D5428` | Matching | 100.00% | 56 |
| `func_001D5460` | Matching | 100.00% | 36 |
| `func_001D5488` | Matching | 100.00% | 1068 |
| `func_001D58B8` | Matching | 100.00% | 228 |
| `func_001D59A0` | Matching | 100.00% | 644 |
| `func_001D5C28` | Matching | 100.00% | 336 |
| `func_001D5DF0` | Matching | 100.00% | 324 |
| `func_001D5F38(void*)` | Matching | 100.00% | 8 |
| `func_001D5F40` | Matching | 100.00% | 1408 |
| `func_001D64C0` | Matching | 100.00% | 492 |

### `fe/messagecenter`

22 matching, 0 partial, 1 not started (23 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00197500` | Matching | 100.00% | 720 |
| `func_001977D0` | Matching | 100.00% | 520 |
| `func_001979D8` | Matching | 100.00% | 256 |
| `func_00197AD8` | Matching | 100.00% | 172 |
| `func_00197B88` | Matching | 100.00% | 60 |
| `func_00197BC8` | Matching | 100.00% | 216 |
| `func_00197CA0` | Matching | 100.00% | 280 |
| `func_00197DB8` | Matching | 100.00% | 180 |
| `func_00197E70` | Matching | 100.00% | 680 |
| `func_00198118` | Matching | 100.00% | 220 |
| `cFEStateRequestLine_updateHelpText` | Matching | 100.00% | 328 |
| `cFEStateRequestLine_updateButtonsText` | Matching | 100.00% | 620 |
| `func_001985B0` | Matching | 100.00% | 64 |
| `func_001985F0` | Matching | 100.00% | 220 |
| `cFEStateRequestLine_updateHilightedSongInfo` | Matching | 100.00% | 516 |
| `func_001988D8` | Matching | 100.00% | 176 |
| `func_00198988` | Matching | 100.00% | 256 |
| `func_00198A88` | Matching | 100.00% | 48 |
| `func_00198AB8` | Matching | 100.00% | 48 |
| `func_00198AE8(void*)` | Matching | 100.00% | 8 |
| `func_00198AF0` | Matching | 100.00% | 688 |
| `func_00198DA0` | Matching | 100.00% | 24 |

### `fe/ovstateenterlodge`

22 matching, 0 partial, 0 not started (22 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVState_ENTERLODGE_onCreateScreen` | Matching | 100.00% | 116 |
| `func_001F7210` | Matching | 100.00% | 132 |
| `func_001F7298(void*)` | Matching | 100.00% | 32 |
| `func_001F72B8` | Matching | 100.00% | 36 |
| `func_001F72E0` | Matching | 100.00% | 196 |
| `cOVState_BIGCHALLENGE_START_onCreateScreen` | Matching | 100.00% | 108 |
| `cOVState_BIGCHALLENGE_START_onGainTransition` | Matching | 100.00% | 200 |
| `func_001F74E0` | Matching | 100.00% | 100 |
| `func_001F7548` | Matching | 100.00% | 72 |
| `func_001F7590` | Matching | 100.00% | 16 |
| `func_001F75A0` | Matching | 100.00% | 280 |
| `func_001F76B8` | Matching | 100.00% | 124 |
| `func_001F7738` | Matching | 100.00% | 52 |
| `func_001F7770` | Matching | 100.00% | 128 |
| `func_001F77F0` | Matching | 100.00% | 16 |
| `func_001F7800` | Matching | 100.00% | 340 |
| `func_001F7958` | Matching | 100.00% | 1296 |
| `cOVState_TOPTIMES_onWidgetCreate` | Matching | 100.00% | 160 |
| `func_001F7F08` | Matching | 100.00% | 448 |
| `func_001F80C8` | Matching | 100.00% | 16 |
| `func_001F80D8` | Matching | 100.00% | 60 |
| `func_001F8118` | Matching | 100.00% | 80 |

### `fe/ovstatehud`

31 matching, 0 partial, 5 not started (36 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVStateHiScoreList_onCreateScreen` | Matching | 100.00% | 320 |
| `func_001E9130` | Matching | 100.00% | 116 |
| `func_001E91A8(void *, void *)` | Matching | 100.00% | 36 |
| `func_001E91D0(void *, void *)` | Matching | 100.00% | 36 |
| `func_001E91F8` | Matching | 100.00% | 36 |
| `func_001E9220` | Matching | 100.00% | 108 |
| `func_001E9290(void *, void *)` | Matching | 100.00% | 20 |
| `func_001E92A8` | Matching | 100.00% | 568 |
| `func_001E94E0` | Matching | 100.00% | 92 |
| `func_001E9540` | Matching | 100.00% | 92 |
| `func_001E9A30` | Matching | 100.00% | 156 |
| `func_001EC1F0` | Matching | 100.00% | 516 |
| `func_001F10F8` | Matching | 100.00% | 148 |
| `func_001F1190` | Matching | 100.00% | 420 |
| `func_001F1338` | Matching | 100.00% | 372 |
| `func_001F14B0` | Matching | 100.00% | 524 |
| `func_001F16C0` | Matching | 100.00% | 380 |
| `cOVStateHUD1P_renderTime` | Matching | 100.00% | 748 |
| `func_001F1B30` | Matching | 100.00% | 756 |
| `func_001F1E28` | Matching | 100.00% | 1216 |
| `func_001F22E8` | Matching | 100.00% | 756 |
| `func_001F25E0` | Matching | 100.00% | 1216 |
| `func_001F2AA0` | Matching | 100.00% | 780 |
| `func_001F2DB0` | Matching | 100.00% | 780 |
| `func_001F30C0(void*)` | Matching | 100.00% | 24 |
| `func_001F30D8` | Matching | 100.00% | 152 |
| `func_001F3170(void*)` | Matching | 100.00% | 20 |
| `func_001F36C0` | Matching | 100.00% | 24 |
| `func_001F36D8` | Matching | 100.00% | 40 |
| `func_001F3700` | Matching | 100.00% | 144 |
| `func_001F3188` | Matching | 99.76% | 84 |

### `fe/ovstatelodge`

21 matching, 0 partial, 1 not started (22 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateMountainRoom_cFEStateMountainRoom` | Matching | 100.00% | 640 |
| `func_001D28F8` | Matching | 100.00% | 148 |
| `cFEStateMountainRoom_onCreateScreen` | Matching | 100.00% | 252 |
| `func_001D2A90` | Matching | 100.00% | 60 |
| `cFEStateMountainRoom_onWidgetCreate` | Matching | 100.00% | 972 |
| `func_001D2EA0` | Matching | 100.00% | 160 |
| `func_001D2F40` | Matching | 100.00% | 36 |
| `cFEStateMountainRoom_onWidgetEvent` | Matching | 100.00% | 440 |
| `func_001D3120` | Matching | 100.00% | 64 |
| `func_001D3160` | Matching | 100.00% | 92 |
| `func_001D31C0` | Matching | 100.00% | 288 |
| `func_001D32E0` | Matching | 100.00% | 96 |
| `func_001D3780` | Matching | 100.00% | 272 |
| `cFEStatePeakRoom_onCreateScreen` | Matching | 100.00% | 100 |
| `cFEStatePeakRoom_onWidgetCreate` | Matching | 100.00% | 868 |
| `func_001D3C60(void*)` | Matching | 100.00% | 28 |
| `func_001D3C80` | Matching | 100.00% | 388 |
| `func_001D3E08` | Matching | 100.00% | 188 |
| `cFEStatePeakRoom_updateHelpText` | Matching | 100.00% | 184 |
| `func_001D3F80` | Matching | 100.00% | 744 |
| `func_001D4268` | Matching | 100.00% | 252 |

### `fe/ovstatemap`

24 matching, 0 partial, 1 not started (25 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVState_MAP_onCreateScreen` | Matching | 100.00% | 316 |
| `func_002087E8(void*)` | Matching | 100.00% | 8 |
| `cOVState_MAP_onGainTransition` | Matching | 100.00% | 780 |
| `func_00208B00` | Matching | 100.00% | 116 |
| `func_00208B78` | Matching | 100.00% | 64 |
| `func_00208BB8` | Matching | 100.00% | 108 |
| `func_00208C28` | Matching | 100.00% | 716 |
| `func_00208EF8` | Matching | 100.00% | 20 |
| `func_00208F10` | Matching | 100.00% | 120 |
| `cOVState_MAP_setupPopup` | Matching | 100.00% | 884 |
| `func_00209300` | Matching | 100.00% | 108 |
| `func_00209370` | Matching | 100.00% | 632 |
| `func_002095E8` | Matching | 100.00% | 92 |
| `func_00209648` | Matching | 100.00% | 92 |
| `cOVState_MAP_setupPlayerIndicator` | Matching | 100.00% | 708 |
| `func_00209E78` | Matching | 100.00% | 340 |
| `func_00209FD0` | Matching | 100.00% | 180 |
| `func_0020A088` | Matching | 100.00% | 284 |
| `func_0020A1A8` | Matching | 100.00% | 468 |
| `func_0020A380` | Matching | 100.00% | 176 |
| `func_0020A430` | Matching | 100.00% | 172 |
| `func_0020A4E0` | Matching | 100.00% | 456 |
| `func_0020A6A8` | Matching | 100.00% | 68 |
| `func_0020A6F0` | Matching | 100.00% | 136 |

### `fe/ovstatemission`

12 matching, 0 partial, 0 not started (12 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateMPCircuit_onCreateScreen` | Matching | 100.00% | 164 |
| `func_001A3300(void*)` | Matching | 100.00% | 8 |
| `func_001A3308` | Matching | 100.00% | 152 |
| `func_001A33A0` | Matching | 100.00% | 252 |
| `func_001A34A0(void*)` | Matching | 100.00% | 8 |
| `func_001A34A8(void*)` | Matching | 100.00% | 8 |
| `func_001A34B0` | Matching | 100.00% | 8 |
| `func_001A34B8` | Matching | 100.00% | 212 |
| `func_001A3590` | Matching | 100.00% | 84 |
| `func_001A35E8` | Matching | 100.00% | 96 |
| `func_001A3648` | Matching | 100.00% | 80 |
| `func_001A3698` | Matching | 100.00% | 76 |

### `fe/ovstatepause`

55 matching, 0 partial, 5 not started (60 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_001FA100` | Matching | 100.00% | 308 |
| `func_001FA9E0` | Matching | 100.00% | 152 |
| `func_001FAA78` | Matching | 100.00% | 120 |
| `func_001FAAF0` | Matching | 100.00% | 20 |
| `func_001FAB08` | Matching | 100.00% | 16 |
| `cOVState_PAUSE_ONLINE_ERROR_onCreateScreen` | Matching | 100.00% | 1004 |
| `func_001FAF08(void*)` | Matching | 100.00% | 8 |
| `func_001FAF10` | Matching | 100.00% | 232 |
| `func_001FAFF8` | Matching | 100.00% | 196 |
| `func_001FB0C0` | Matching | 100.00% | 192 |
| `cOVState_PAUSE_ONLINE_ERROR_displayPingTimedOut` | Matching | 100.00% | 148 |
| `cOVState_PAUSE_ONLINE_ERROR_displayPingReceived` | Matching | 100.00% | 156 |
| `func_001FB2B8` | Matching | 100.00% | 188 |
| `cOVState_PAUSE_ONLINE_ERROR_setContinueOptionVisible` | Matching | 100.00% | 220 |
| `func_001FB458` | Matching | 100.00% | 300 |
| `func_001FB588` | Matching | 100.00% | 300 |
| `func_001FBBD8` | Matching | 100.00% | 240 |
| `func_001FBCC8` | Matching | 100.00% | 24 |
| `func_001FBCE0` | Matching | 100.00% | 64 |
| `func_001FC768` | Matching | 100.00% | 272 |
| `func_001FC878` | Matching | 100.00% | 1604 |
| `func_001FCEC0` | Matching | 100.00% | 532 |
| `func_001FD0D8` | Matching | 100.00% | 64 |
| `func_001FD118` | Matching | 100.00% | 52 |
| `func_001FD150` | Matching | 100.00% | 64 |
| `func_001FD190` | Matching | 100.00% | 216 |
| `func_001FD268` | Matching | 100.00% | 184 |
| `func_001FD320` | Matching | 100.00% | 2132 |
| `func_001FDB78` | Matching | 100.00% | 16 |
| `func_001FDB88` | Matching | 100.00% | 104 |
| `func_001FDBF0` | Matching | 100.00% | 64 |
| `func_001FDC30` | Matching | 100.00% | 560 |
| `func_001FDE60` | Matching | 100.00% | 160 |
| `func_001FDF00` | Matching | 100.00% | 64 |
| `func_001FDF40` | Matching | 100.00% | 1380 |
| `func_001FE4A8` | Matching | 100.00% | 260 |
| `func_001FE5B0` | Matching | 100.00% | 148 |
| `func_001FE648` | Matching | 100.00% | 160 |
| `func_001FE6E8` | Matching | 100.00% | 520 |
| `func_001FE8F0` | Matching | 100.00% | 116 |
| `func_001FE968` | Matching | 100.00% | 64 |
| `func_001FE9A8` | Matching | 100.00% | 660 |
| `func_001FEC40(void*)` | Matching | 100.00% | 28 |
| `func_001FEC60` | Matching | 100.00% | 64 |
| `func_001FECA0` | Matching | 100.00% | 1232 |
| `func_001FF170` | Matching | 100.00% | 260 |
| `func_001FF278` | Matching | 100.00% | 148 |
| `func_001FF310` | Matching | 100.00% | 160 |
| `func_001FF3B0` | Matching | 100.00% | 480 |
| `cOVState_REWARDS_onCreateScreen` | Matching | 100.00% | 316 |
| `func_001FF6D0` | Matching | 100.00% | 48 |
| `func_001FF700` | Matching | 100.00% | 68 |
| `func_001FF748` | Matching | 100.00% | 112 |
| `cOVState_REWARDS_onGainTransition` | Matching | 100.00% | 672 |
| `func_001FFD08` | Matching | 99.90% | 620 |

### `fe/ovstateprofile`

23 matching, 0 partial, 1 not started (24 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVState_PROFILE_onCreateScreen` | Matching | 100.00% | 124 |
| `func_00211220` | Matching | 100.00% | 76 |
| `func_00211270` | Matching | 100.00% | 272 |
| `func_00211380` | Matching | 100.00% | 1228 |
| `func_00211850` | Matching | 100.00% | 288 |
| `func_00211970` | Matching | 100.00% | 148 |
| `func_00211A08` | Matching | 100.00% | 160 |
| `func_00211AA8` | Matching | 100.00% | 100 |
| `func_00211B10(void*)` | Matching | 100.00% | 40 |
| `func_00211B38` | Matching | 100.00% | 140 |
| `func_00211BC8` | Matching | 100.00% | 1204 |
| `func_00212080` | Matching | 100.00% | 180 |
| `func_00212138` | Matching | 100.00% | 96 |
| `cOVState_AUTOSAVE_onCreateScreen` | Matching | 100.00% | 108 |
| `func_002122E0(void*)` | Matching | 100.00% | 8 |
| `func_002122E8` | Matching | 100.00% | 116 |
| `cOVState_AUTOSAVE_displayOn` | Matching | 100.00% | 360 |
| `func_002124C8` | Matching | 100.00% | 64 |
| `func_00212508` | Matching | 100.00% | 372 |
| `func_00212680` | Matching | 100.00% | 60 |
| `func_002126C0` | Matching | 100.00% | 104 |
| `func_00212728` | Matching | 100.00% | 96 |
| `func_00212788` | Matching | 100.00% | 96 |

### `fe/ovstatereplay`

6 matching, 0 partial, 2 not started (8 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVState_REPLAY_onWidgetCreate` | Matching | 100.00% | 224 |
| `cOVState_REPLAY_onUpdate` | Matching | 100.00% | 384 |
| `cOVState_REPLAY_setupTicker` | Matching | 100.00% | 196 |
| `func_0020E8E0(void*)` | Matching | 100.00% | 28 |
| `func_0020E900` | Matching | 100.00% | 56 |
| `cOVState_REPLAY_setupCameraName` | Matching | 98.65% | 356 |

### `fe/ovstaterewardslist`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVStateRewardsList_onCreateScreen` | Matching | 100.00% | 108 |
| `func_00200288` | Matching | 100.00% | 252 |
| `func_00200388` | Matching | 100.00% | 816 |
| `func_002006B8` | Matching | 100.00% | 68 |

### `fe/ovstates`

16 matching, 0 partial, 0 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFEStateTitle_onCreateScreen` | Matching | 100.00% | 124 |
| `func_001947F8` | Matching | 100.00% | 176 |
| `func_001948A8` | Matching | 100.00% | 216 |
| `func_00194980(void*)` | Matching | 100.00% | 8 |
| `func_00194988` | Matching | 100.00% | 84 |
| `func_001949E0` | Matching | 100.00% | 100 |
| `func_00194A48` | Matching | 100.00% | 20 |
| `func_00194A60` | Matching | 100.00% | 68 |
| `cFEStateMainMenu_onCreateScreen` | Matching | 100.00% | 328 |
| `func_00194BF0` | Matching | 100.00% | 292 |
| `cFEStateMainMenu_onWidgetCreate` | Matching | 100.00% | 184 |
| `func_00194DD0` | Matching | 100.00% | 216 |
| `cFEStateMainMenu_onWidgetEvent` | Matching | 100.00% | 1084 |
| `func_001952E8` | Matching | 100.00% | 64 |
| `func_00195328` | Matching | 100.00% | 364 |
| `func_00195498` | Matching | 100.00% | 60 |

### `fe/ovstatetrophy`

21 matching, 0 partial, 3 not started (24 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVStateTrophy_onCreateScreen` | Matching | 100.00% | 100 |
| `func_0020E9A0` | Matching | 100.00% | 252 |
| `func_0020EAA0` | Matching | 100.00% | 104 |
| `func_0020EB08` | Matching | 100.00% | 72 |
| `func_0020EB50` | Matching | 100.00% | 200 |
| `func_0020EC18` | Matching | 100.00% | 264 |
| `func_0020ED20` | Matching | 100.00% | 124 |
| `func_002105B0` | Matching | 100.00% | 32 |
| `func_002105D0` | Matching | 100.00% | 52 |
| `func_00210608` | Matching | 100.00% | 16 |
| `func_00210820` | Matching | 100.00% | 216 |
| `func_002108F8` | Matching | 100.00% | 72 |
| `func_00210940` | Matching | 100.00% | 536 |
| `func_00210B58` | Matching | 100.00% | 128 |
| `func_00210BD8` | Matching | 100.00% | 324 |
| `func_00210D20` | Matching | 100.00% | 172 |
| `func_00210DD0` | Matching | 100.00% | 32 |
| `func_00210DF0` | Matching | 100.00% | 332 |
| `func_00210F40` | Matching | 100.00% | 96 |
| `func_00210FA0` | Matching | 100.00% | 232 |
| `func_00210618` | Matching | 99.96% | 520 |

### `fe/ovtemplatedialog`

20 matching, 0 partial, 3 not started (23 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPDATemplate_onCreateScreen` | Matching | 100.00% | 308 |
| `func_0020A8B0` | Matching | 100.00% | 68 |
| `func_0020A8F8` | Matching | 100.00% | 596 |
| `func_0020CA10` | Matching | 100.00% | 324 |
| `func_0020CB58` | Matching | 100.00% | 72 |
| `func_0020CBA0` | Matching | 100.00% | 72 |
| `func_0020CBE8` | Matching | 100.00% | 116 |
| `func_0020CC60` | Matching | 100.00% | 148 |
| `func_0020CCF8` | Matching | 100.00% | 728 |
| `func_0020CFD0` | Matching | 100.00% | 316 |
| `cOVStateManager_addPDATemplate` | Matching | 100.00% | 124 |
| `func_0020D190` | Matching | 100.00% | 72 |
| `func_0020D1D8` | Matching | 100.00% | 300 |
| `func_0020D308` | Matching | 100.00% | 16 |
| `func_0020D318` | Matching | 100.00% | 28 |
| `cOVTemplate_Dialog_onCreateScreen` | Matching | 100.00% | 440 |
| `func_0020D4F0` | Matching | 100.00% | 116 |
| `func_0020D568` | Matching | 100.00% | 36 |
| `func_0020DBD0` | Matching | 100.00% | 152 |
| `func_0020DC68` | Matching | 100.00% | 456 |

### `fe/ovtemplatepausemenu`

16 matching, 0 partial, 0 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cOVTemplate_PauseMenu_onCreateScreen` | Matching | 100.00% | 732 |
| `func_001F8448` | Matching | 100.00% | 376 |
| `func_001F85C0` | Matching | 100.00% | 352 |
| `func_001F8720(void*)` | Matching | 100.00% | 8 |
| `func_001F8728` | Matching | 100.00% | 444 |
| `func_001F88E8(void*)` | Matching | 100.00% | 32 |
| `func_001F8908` | Matching | 100.00% | 60 |
| `cOVTemplate_PauseMenu_onWidgetEvent` | Matching | 100.00% | 1188 |
| `func_001F8DF0(void*)` | Matching | 100.00% | 8 |
| `func_001F8DF8` | Matching | 100.00% | 232 |
| `func_001F8EE0` | Matching | 100.00% | 100 |
| `func_001F8F48` | Matching | 100.00% | 100 |
| `func_001F8FB0` | Matching | 100.00% | 100 |
| `func_001F9018` | Matching | 100.00% | 100 |
| `func_001F9080` | Matching | 100.00% | 100 |
| `func_001F90E8` | Matching | 100.00% | 156 |

### `fe/uitemplatemap`

30 matching, 0 partial, 8 not started (38 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUITemplate_MAP_onCreateScreen` | Matching | 100.00% | 720 |
| `func_002009D0` | Matching | 100.00% | 156 |
| `func_00200A70` | Matching | 100.00% | 76 |
| `func_00200AC0` | Matching | 100.00% | 48 |
| `func_00200AF0` | Matching | 100.00% | 96 |
| `func_00200D00` | Matching | 100.00% | 228 |
| `cUITemplate_MAP_setupEventUnlock(cUITemplate_MAP*)` | Matching | 100.00% | 44 |
| `cUITemplate_MAP_setupPeakUnlock` | Matching | 100.00% | 276 |
| `func_00201868` | Matching | 100.00% | 64 |
| `func_00202738` | Matching | 100.00% | 44 |
| `func_00202768(void*)` | Matching | 100.00% | 8 |
| `func_00202770` | Matching | 100.00% | 180 |
| `cUITemplate_MAP_onUpdate` | Matching | 100.00% | 688 |
| `cUITemplate_MAP_setupMenuFocus` | Matching | 100.00% | 2284 |
| `cUITemplate_MAP_setupMapPic` | Matching | 100.00% | 200 |
| `cUITemplate_MAP_setupPopup` | Matching | 100.00% | 608 |
| `cUITemplate_MAP_setShowInfo` | Matching | 100.00% | 136 |
| `func_00204FF0` | Matching | 100.00% | 164 |
| `func_002083D8` | Matching | 100.00% | 96 |
| `func_00208438` | Matching | 100.00% | 96 |
| `func_00208498` | Matching | 100.00% | 124 |
| `func_00208518(void*)` | Matching | 100.00% | 28 |
| `func_00208538(void*)` | Matching | 100.00% | 28 |
| `func_00208558` | Matching | 100.00% | 44 |
| `func_00208588` | Matching | 100.00% | 48 |
| `func_00208610` | Matching | 100.00% | 40 |
| `func_00208638` | Matching | 100.00% | 28 |
| `func_00208658(void*)` | Matching | 100.00% | 28 |
| `func_00208678` | Matching | 100.00% | 44 |
| `func_002085B8` | Matching | 99.77% | 88 |

### `hashvalue`

6 matching, 0 partial, 0 not started (6 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `tHashName32_getHashValue(unsigned int*, char*)` | Matching | 100.00% | 88 |
| `GetHashValue32(char*)` | Matching | 100.00% | 32 |
| `tHashName64_getHashValue(unsigned long*, char*)` | Matching | 100.00% | 96 |
| `GetHashValue64(char*)` | Matching | 100.00% | 32 |
| `func_00317710` | Matching | 100.00% | 132 |
| `func_00317798` | Matching | 100.00% | 48 |

### `input/inputmap`

17 matching, 0 partial, 0 not started (17 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cInputMap_init` | Matching | 100.00% | 104 |
| `func_00320D08` | Matching | 100.00% | 72 |
| `func_00320D50` | Matching | 100.00% | 92 |
| `cInputMap_loadMapFile` | Matching | 100.00% | 104 |
| `cInputMap_compileMap` | Matching | 100.00% | 248 |
| `cInputMap_purgeMapFile` | Matching | 100.00% | 148 |
| `func_00320FA8` | Matching | 100.00% | 104 |
| `func_00321010` | Matching | 100.00% | 248 |
| `func_00321108` | Matching | 100.00% | 128 |
| `func_00321188` | Matching | 100.00% | 272 |
| `func_00321298` | Matching | 100.00% | 400 |
| `func_00321428` | Matching | 100.00% | 212 |
| `func_00321500` | Matching | 100.00% | 144 |
| `func_00321590` | Matching | 100.00% | 104 |
| `func_003215F8` | Matching | 100.00% | 64 |
| `func_00321638` | Matching | 100.00% | 176 |
| `func_003216E8` | Matching | 100.00% | 232 |

### `input/inputparse`

56 matching, 0 partial, 3 not started (59 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cInputMapParser_lookupModifierName` | Matching | 100.00% | 176 |
| `cInputMapParser_lookupConfigName` | Matching | 100.00% | 448 |
| `func_00321A40` | Matching | 100.00% | 140 |
| `func_00321AD0` | Matching | 100.00% | 8 |
| `func_00321AD8` | Matching | 100.00% | 20 |
| `cInputMapParser_compileStatement` | Matching | 100.00% | 204 |
| `func_00324678` | Matching | 100.00% | 2128 |
| `func_00324EC8` | Matching | 100.00% | 528 |
| `func_003250D8` | Matching | 100.00% | 372 |
| `func_00325250(void*)` | Matching | 100.00% | 12 |
| `func_00325260` | Matching | 100.00% | 132 |
| `func_003252E8` | Matching | 100.00% | 16 |
| `func_003252F8` | Matching | 100.00% | 312 |
| `func_00325430` | Matching | 100.00% | 32 |
| `func_00325F48` | Matching | 100.00% | 304 |
| `func_00326078` | Matching | 100.00% | 212 |
| `func_00326150` | Matching | 100.00% | 440 |
| `func_00326308` | Matching | 100.00% | 84 |
| `func_00326360` | Matching | 100.00% | 204 |
| `func_00326430` | Matching | 100.00% | 68 |
| `func_00326478` | Matching | 100.00% | 52 |
| `func_003264B0` | Matching | 100.00% | 272 |
| `func_003265C0` | Matching | 100.00% | 184 |
| `func_00326678` | Matching | 100.00% | 112 |
| `func_00326A20(void*)` | Matching | 100.00% | 8 |
| `func_00326A28` | Matching | 100.00% | 60 |
| `func_00326A68` | Matching | 100.00% | 116 |
| `func_00326AE0` | Matching | 100.00% | 100 |
| `func_00326B48` | Matching | 100.00% | 64 |
| `func_00326B88` | Matching | 100.00% | 212 |
| `func_00326C60` | Matching | 100.00% | 64 |
| `func_00326CA0` | Matching | 100.00% | 36 |
| `func_00326CC8` | Matching | 100.00% | 36 |
| `func_00326CF0` | Matching | 100.00% | 112 |
| `func_00326D60` | Matching | 100.00% | 144 |
| `func_00326DF0` | Matching | 100.00% | 96 |
| `func_00326E50` | Matching | 100.00% | 96 |
| `func_00327738(void*)` | Matching | 100.00% | 8 |
| `func_00327740` | Matching | 100.00% | 140 |
| `func_003277D0` | Matching | 100.00% | 48 |
| `func_00327800(void*)` | Matching | 100.00% | 8 |
| `func_00327808(void*)` | Matching | 100.00% | 8 |
| `func_00327810(void*)` | Matching | 100.00% | 24 |
| `func_00327828` | Matching | 100.00% | 100 |
| `func_00326EB0` | Matching | 99.98% | 2184 |
| `func_003236D8` | Matching | 99.96% | 552 |
| `func_00323540` | Matching | 99.95% | 408 |
| `func_003233B8` | Matching | 99.95% | 388 |
| `func_00323A68` | Matching | 99.95% | 368 |
| `func_00323900` | Matching | 99.94% | 360 |
| `cInputMapParser_parseUnaryFunc` | Matching | 99.92% | 528 |
| `cInputMapParser_parseBinaryFunc` | Matching | 99.90% | 604 |
| `cInputMapParser_parseExpression` | Matching | 99.88% | 332 |
| `cInputMapParser_parseStatement` | Matching | 99.85% | 392 |
| `func_00323098` | Matching | 99.71% | 68 |
| `cInputMapParser_parseTerm` | Matching | 99.62% | 1376 |

### `intersect/aifwddiff`

18 matching, 0 partial, 3 not started (21 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAIFwdDiffCache_Init` | Matching | 100.00% | 316 |
| `func_003279D0` | Matching | 100.00% | 236 |
| `func_00327AC0` | Matching | 100.00% | 108 |
| `func_00327BB0` | Matching | 100.00% | 80 |
| `func_00327C00` | Matching | 100.00% | 100 |
| `func_00327C68` | Matching | 100.00% | 92 |
| `func_00327CC8` | Matching | 100.00% | 224 |
| `func_00327DA8` | Matching | 100.00% | 364 |
| `func_00327F18` | Matching | 100.00% | 280 |
| `func_00328030` | Matching | 100.00% | 316 |
| `func_00328170` | Matching | 100.00% | 92 |
| `func_003281D0` | Matching | 100.00% | 396 |
| `func_00328360` | Matching | 100.00% | 340 |
| `func_003284B8` | Matching | 100.00% | 424 |
| `func_00328660` | Matching | 100.00% | 420 |
| `func_00328C20` | Matching | 100.00% | 776 |
| `func_00328F28` | Matching | 100.00% | 692 |
| `func_00329590` | Matching | 100.00% | 896 |

### `intersect/riderspheretree`

67 matching, 0 partial, 10 not started (77 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cRiderSphereTree_cRiderSphereTree(cRiderSphereTree*)` | Matching | 100.00% | 36 |
| `func_00329938` | Matching | 100.00% | 52 |
| `func_00329970` | Matching | 100.00% | 36 |
| `func_00329998` | Matching | 100.00% | 48 |
| `func_003299C8` | Matching | 100.00% | 92 |
| `func_00329A28` | Matching | 100.00% | 104 |
| `func_00329A90` | Matching | 100.00% | 76 |
| `func_00329AE0` | Matching | 100.00% | 96 |
| `func_00329B40` | Matching | 100.00% | 76 |
| `func_00329B90` | Matching | 100.00% | 336 |
| `func_00329CE0` | Matching | 100.00% | 232 |
| `func_00329DC8` | Matching | 100.00% | 464 |
| `func_0032B2B8` | Matching | 100.00% | 420 |
| `func_0032B460` | Matching | 100.00% | 8 |
| `func_0032B468` | Matching | 100.00% | 440 |
| `func_0032B620` | Matching | 100.00% | 136 |
| `func_0032B6A8` | Matching | 100.00% | 56 |
| `func_0032C508` | Matching | 100.00% | 56 |
| `func_0032C540` | Matching | 100.00% | 76 |
| `func_0032C590` | Matching | 100.00% | 24 |
| `func_0032C5A8` | Matching | 100.00% | 52 |
| `func_0032C5E0` | Matching | 100.00% | 80 |
| `func_0032C630` | Matching | 100.00% | 24 |
| `func_0032C898` | Matching | 100.00% | 144 |
| `func_0032C928` | Matching | 100.00% | 144 |
| `func_0032C9B8` | Matching | 100.00% | 192 |
| `func_0032CA78` | Matching | 100.00% | 220 |
| `func_0032CB58` | Matching | 100.00% | 160 |
| `func_0032CBF8` | Matching | 100.00% | 440 |
| `func_0032CDB0` | Matching | 100.00% | 628 |
| `func_0032D028` | Matching | 100.00% | 476 |
| `func_0032D208` | Matching | 100.00% | 564 |
| `func_0032DA40` | Matching | 100.00% | 252 |
| `func_0032DB40` | Matching | 100.00% | 204 |
| `func_0032DC10` | Matching | 100.00% | 524 |
| `func_0032DE20` | Matching | 100.00% | 264 |
| `func_0032DF28` | Matching | 100.00% | 472 |
| `func_0032E100` | Matching | 100.00% | 388 |
| `func_0032E288` | Matching | 100.00% | 268 |
| `func_0032E4B8` | Matching | 100.00% | 24 |
| `func_0032E688(void*)` | Matching | 100.00% | 8 |
| `func_0032F650` | Matching | 100.00% | 184 |
| `func_0032F708` | Matching | 100.00% | 88 |
| `func_0032F760` | Matching | 100.00% | 220 |
| `func_0032F840` | Matching | 100.00% | 108 |
| `func_0032F8B0(void*)` | Matching | 100.00% | 16 |
| `func_0032F8C0` | Matching | 100.00% | 44 |
| `func_0032FA30` | Matching | 100.00% | 140 |
| `func_0032FAC0` | Matching | 100.00% | 132 |
| `func_0032FB48` | Matching | 100.00% | 188 |
| `func_0032FC08` | Matching | 100.00% | 312 |
| `func_0032FD40` | Matching | 100.00% | 84 |
| `func_0032FD98` | Matching | 100.00% | 24 |
| `func_0032FDB0` | Matching | 100.00% | 144 |
| `func_0032FE40` | Matching | 100.00% | 56 |
| `func_003300F8` | Matching | 100.00% | 44 |
| `func_00330128` | Matching | 100.00% | 296 |
| `func_00330250` | Matching | 100.00% | 268 |
| `func_00330360` | Matching | 100.00% | 140 |
| `func_0032E690` | Matching | 99.97% | 780 |
| `func_0032C0F8` | Matching | 99.96% | 1040 |
| `func_0032FFA0` | Matching | 99.94% | 344 |
| `func_0032FE78` | Matching | 99.93% | 292 |
| `func_0032F8F0` | Matching | 99.88% | 160 |
| `func_0032F990` | Matching | 99.88% | 160 |
| `func_0032E4D0` | Matching | 99.86% | 280 |
| `func_0032D440` | Matching | 99.55% | 44 |

### `intersect/worldsphtree`

79 matching, 0 partial, 7 not started (86 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldSphTree_cWorldSphTree` | Matching | 100.00% | 248 |
| `func_003304E8` | Matching | 100.00% | 84 |
| `func_00330540` | Matching | 100.00% | 408 |
| `func_003306D8` | Matching | 100.00% | 56 |
| `func_00330710` | Matching | 100.00% | 100 |
| `func_00330778(void*)` | Matching | 100.00% | 16 |
| `func_00330788` | Matching | 100.00% | 160 |
| `func_00330828` | Matching | 100.00% | 160 |
| `func_003308C8` | Matching | 100.00% | 132 |
| `func_00330950` | Matching | 100.00% | 132 |
| `func_003309D8` | Matching | 100.00% | 460 |
| `func_00330BA8` | Matching | 100.00% | 2216 |
| `func_00333EF8` | Matching | 100.00% | 980 |
| `func_003342D0` | Matching | 100.00% | 392 |
| `func_00334458` | Matching | 100.00% | 552 |
| `func_00334680` | Matching | 100.00% | 380 |
| `func_00334800` | Matching | 100.00% | 80 |
| `func_00334850` | Matching | 100.00% | 56 |
| `func_00335960` | Matching | 100.00% | 556 |
| `func_00335B90` | Matching | 100.00% | 488 |
| `func_00335D78` | Matching | 100.00% | 2772 |
| `func_00336850` | Matching | 100.00% | 392 |
| `func_00336D40` | Matching | 100.00% | 496 |
| `func_00336F30` | Matching | 100.00% | 2444 |
| `func_003378C0` | Matching | 100.00% | 392 |
| `func_003388E0` | Matching | 100.00% | 60 |
| `func_00340A08(void*)` | Matching | 100.00% | 8 |
| `func_00340A10(void*)` | Matching | 100.00% | 8 |
| `func_00340A18` | Matching | 100.00% | 40 |
| `func_00340A40` | Matching | 100.00% | 216 |
| `func_00340B18` | Matching | 100.00% | 260 |
| `func_00340C20` | Matching | 100.00% | 416 |
| `func_00340DC0` | Matching | 100.00% | 476 |
| `func_00340FA0` | Matching | 100.00% | 284 |
| `func_003410C0` | Matching | 100.00% | 244 |
| `func_003411B8` | Matching | 100.00% | 432 |
| `func_00341368(void*)` | Matching | 100.00% | 32 |
| `func_00341548` | Matching | 100.00% | 92 |
| `func_003415A8(void*)` | Matching | 100.00% | 40 |
| `func_003415D0` | Matching | 100.00% | 412 |
| `func_00341770` | Matching | 100.00% | 164 |
| `func_00341818` | Matching | 100.00% | 532 |
| `func_00341A30` | Matching | 100.00% | 28 |
| `func_00341A50` | Matching | 100.00% | 76 |
| `func_00341C80` | Matching | 100.00% | 108 |
| `func_00341CF0` | Matching | 100.00% | 88 |
| `func_00341E48` | Matching | 100.00% | 116 |
| `func_00341EC0` | Matching | 100.00% | 116 |
| `func_00341F38` | Matching | 100.00% | 144 |
| `func_00341FC8` | Matching | 100.00% | 32 |
| `func_00342150` | Matching | 100.00% | 80 |
| `func_003422E8` | Matching | 100.00% | 108 |
| `func_003424D0` | Matching | 100.00% | 104 |
| `func_00342538` | Matching | 100.00% | 480 |
| `func_00342718` | Matching | 100.00% | 80 |
| `func_00342768` | Matching | 100.00% | 156 |
| `func_00342808` | Matching | 100.00% | 120 |
| `func_00342880` | Matching | 100.00% | 348 |
| `func_003429E0` | Matching | 100.00% | 164 |
| `func_00342A88` | Matching | 100.00% | 244 |
| `func_00342B80` | Matching | 100.00% | 28 |
| `func_00342BA0` | Matching | 100.00% | 100 |
| `func_00342C08` | Matching | 100.00% | 264 |
| `func_0033DBE8` | Matching | 99.98% | 1008 |
| `func_0033B748` | Matching | 99.98% | 5548 |
| `func_003369D8` | Matching | 99.98% | 868 |
| `func_0033ED60` | Matching | 99.98% | 4984 |
| `func_0033A3D8` | Matching | 99.98% | 4976 |
| `func_0033CCF8` | Matching | 99.97% | 3824 |
| `func_00339598` | Matching | 99.97% | 3644 |
| `func_0033DFD8` | Matching | 99.97% | 3464 |
| `func_00338920` | Matching | 99.96% | 3188 |
| `func_00341388` | Matching | 99.95% | 444 |
| `func_00341D48` | Matching | 99.92% | 256 |
| `func_00342358` | Matching | 99.89% | 372 |
| `func_00341AA0` | Matching | 99.79% | 476 |
| `func_00341FE8` | Matching | 99.78% | 356 |
| `func_003421A0` | Matching | 99.75% | 324 |
| `func_003400D8` | Matching | 99.37% | 2196 |

### `luno/lunovm`

27 matching, 0 partial, 1 not started (28 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00224C00` | Matching | 100.00% | 120 |
| `func_00224C78` | Matching | 100.00% | 132 |
| `func_00224D00` | Matching | 100.00% | 156 |
| `func_00224DA0` | Matching | 100.00% | 44 |
| `func_00224DD0` | Matching | 100.00% | 28 |
| `func_00224DF0` | Matching | 100.00% | 92 |
| `luno_cLunoTable_constructTable` | Matching | 100.00% | 224 |
| `func_00224F30` | Matching | 100.00% | 56 |
| `func_00224F68` | Matching | 100.00% | 256 |
| `func_00225068` | Matching | 100.00% | 116 |
| `func_002250E0` | Matching | 100.00% | 356 |
| `func_00225248` | Matching | 100.00% | 236 |
| `luno_cLunoTable_set` | Matching | 100.00% | 1188 |
| `func_002257E0` | Matching | 100.00% | 452 |
| `func_002259A8` | Matching | 100.00% | 488 |
| `func_00225B90` | Matching | 100.00% | 84 |
| `func_00225BE8` | Matching | 100.00% | 180 |
| `func_00225CA0` | Matching | 100.00% | 324 |
| `func_00226600(void*, int, int)` | Matching | 100.00% | 12 |
| `func_00226610(void*)` | Matching | 100.00% | 8 |
| `func_00226618(void*)` | Matching | 100.00% | 8 |
| `func_00226620(void*)` | Matching | 100.00% | 8 |
| `func_00226628` | Matching | 100.00% | 316 |
| `func_00226768` | Matching | 100.00% | 132 |
| `func_002267F0(void*)` | Matching | 100.00% | 32 |
| `func_00226810(void*)` | Matching | 100.00% | 32 |
| `func_00225DE8` | Matching | 99.98% | 2068 |

### `main/all_in_one_main`

277 matching, 0 partial, 3 not started (280 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `__sti__all_in_one_main_cpp` | Matching | 100.00% | 360 |
| `func_001DB2B0` | Matching | 100.00% | 124 |
| `func_001DB528` | Matching | 100.00% | 244 |
| `func_001DB620` | Matching | 100.00% | 244 |
| `func_001DB718` | Matching | 100.00% | 96 |
| `func_001DB778` | Matching | 100.00% | 416 |
| `func_001DB918` | Matching | 100.00% | 416 |
| `func_001DBAB8` | Matching | 100.00% | 32 |
| `func_001DBAD8` | Matching | 100.00% | 68 |
| `func_001DBB20` | Matching | 100.00% | 36 |
| `func_001DBB48` | Matching | 100.00% | 72 |
| `func_001DBB90` | Matching | 100.00% | 44 |
| `func_001DBBC0` | Matching | 100.00% | 36 |
| `func_001DBBE8` | Matching | 100.00% | 40 |
| `func_001DBC10` | Matching | 100.00% | 36 |
| `func_001DBC38` | Matching | 100.00% | 44 |
| `func_001DBC68` | Matching | 100.00% | 44 |
| `func_001DC900` | Matching | 100.00% | 48 |
| `func_001DC930` | Matching | 100.00% | 8 |
| `func_001DC938` | Matching | 100.00% | 8 |
| `func_001DC940` | Matching | 100.00% | 48 |
| `func_001DC970` | Matching | 100.00% | 8 |
| `func_001DC978` | Matching | 100.00% | 8 |
| `func_001DC980` | Matching | 100.00% | 12 |
| `func_001DC990` | Matching | 100.00% | 64 |
| `func_001DC9D0` | Matching | 100.00% | 112 |
| `func_001DCA40` | Matching | 100.00% | 64 |
| `func_001DCA80` | Matching | 100.00% | 64 |
| `func_001DCAC0` | Matching | 100.00% | 48 |
| `func_001DCAF0` | Matching | 100.00% | 112 |
| `func_001DCB60` | Matching | 100.00% | 8 |
| `func_001DCB68` | Matching | 100.00% | 8 |
| `func_001DCB70` | Matching | 100.00% | 28 |
| `func_001DCB90` | Matching | 100.00% | 28 |
| `func_001DCBB0` | Matching | 100.00% | 8 |
| `func_001DCBB8` | Matching | 100.00% | 8 |
| `func_001DCBC0` | Matching | 100.00% | 8 |
| `func_001DCBC8` | Matching | 100.00% | 8 |
| `func_001DCBD0` | Matching | 100.00% | 8 |
| `func_001DCBD8` | Matching | 100.00% | 48 |
| `func_001DCC08` | Matching | 100.00% | 48 |
| `func_001DCC38` | Matching | 100.00% | 8 |
| `func_001DCC40` | Matching | 100.00% | 20 |
| `func_001DCC58` | Matching | 100.00% | 8 |
| `func_001DCC60` | Matching | 100.00% | 24 |
| `func_001DCC78` | Matching | 100.00% | 48 |
| `func_001DCCA8` | Matching | 100.00% | 8 |
| `func_001DCCB0` | Matching | 100.00% | 8 |
| `func_001DCCB8` | Matching | 100.00% | 8 |
| `func_001DCCC0` | Matching | 100.00% | 8 |
| `func_001DCCC8` | Matching | 100.00% | 16 |
| `func_001DCCD8` | Matching | 100.00% | 16 |
| `func_001DCCE8` | Matching | 100.00% | 16 |
| `func_001DCCF8` | Matching | 100.00% | 8 |
| `func_001DCD00` | Matching | 100.00% | 88 |
| `func_001DCD58` | Matching | 100.00% | 68 |
| `func_001DCDA0` | Matching | 100.00% | 128 |
| `func_001DCE20` | Matching | 100.00% | 128 |
| `func_001DCEA0` | Matching | 100.00% | 296 |
| `func_001DCFC8` | Matching | 100.00% | 152 |
| `func_001DD060` | Matching | 100.00% | 104 |
| `func_001DD258` | Matching | 100.00% | 152 |
| `func_001DD2F0` | Matching | 100.00% | 168 |
| `func_001DD398` | Matching | 100.00% | 164 |
| `func_001DD440` | Matching | 100.00% | 128 |
| `func_001DD4C0` | Matching | 100.00% | 68 |
| `func_001DD508` | Matching | 100.00% | 40 |
| `func_001DD530` | Matching | 100.00% | 48 |
| `func_001DD560` | Matching | 100.00% | 8 |
| `func_001DD568` | Matching | 100.00% | 8 |
| `func_001DD570` | Matching | 100.00% | 8 |
| `func_001DD578` | Matching | 100.00% | 8 |
| `func_001DD580` | Matching | 100.00% | 24 |
| `func_001DD598` | Matching | 100.00% | 28 |
| `func_001DD5B8` | Matching | 100.00% | 144 |
| `func_001DD648` | Matching | 100.00% | 8 |
| `func_001DD650` | Matching | 100.00% | 8 |
| `func_001DD658` | Matching | 100.00% | 8 |
| `func_001DD660` | Matching | 100.00% | 8 |
| `func_001DD668` | Matching | 100.00% | 8 |
| `func_001DD670` | Matching | 100.00% | 32 |
| `func_001DD690` | Matching | 100.00% | 24 |
| `func_001DD6A8` | Matching | 100.00% | 56 |
| `func_001DD6E0` | Matching | 100.00% | 52 |
| `func_001DD718` | Matching | 100.00% | 52 |
| `func_001DD750` | Matching | 100.00% | 40 |
| `func_001DD778` | Matching | 100.00% | 136 |
| `func_001DD800` | Matching | 100.00% | 60 |
| `func_001DD840` | Matching | 100.00% | 40 |
| `func_001DD868` | Matching | 100.00% | 40 |
| `func_001DD890` | Matching | 100.00% | 8 |
| `func_001DD898` | Matching | 100.00% | 8 |
| `func_001DD8A0` | Matching | 100.00% | 40 |
| `func_001DD8C8` | Matching | 100.00% | 40 |
| `func_001DD8F0` | Matching | 100.00% | 40 |
| `func_001DD918` | Matching | 100.00% | 8 |
| `func_001DD920` | Matching | 100.00% | 8 |
| `func_001DD928` | Matching | 100.00% | 8 |
| `func_001DD930` | Matching | 100.00% | 8 |
| `func_001DD938` | Matching | 100.00% | 8 |
| `func_001DD940` | Matching | 100.00% | 8 |
| `func_001DD948` | Matching | 100.00% | 8 |
| `func_001DD950` | Matching | 100.00% | 60 |
| `func_001DD990` | Matching | 100.00% | 32 |
| `func_001DD9B0` | Matching | 100.00% | 8 |
| `func_001DD9B8` | Matching | 100.00% | 8 |
| `func_001DD9C0` | Matching | 100.00% | 8 |
| `func_001DD9C8` | Matching | 100.00% | 8 |
| `func_001DD9D0` | Matching | 100.00% | 8 |
| `func_001DD9D8` | Matching | 100.00% | 8 |
| `func_001DD9E0` | Matching | 100.00% | 8 |
| `func_001DD9E8` | Matching | 100.00% | 8 |
| `func_001DD9F0` | Matching | 100.00% | 8 |
| `func_001DD9F8` | Matching | 100.00% | 8 |
| `func_001DDA00` | Matching | 100.00% | 8 |
| `func_001DDA08` | Matching | 100.00% | 8 |
| `func_001DDA10` | Matching | 100.00% | 8 |
| `func_001DDA18` | Matching | 100.00% | 8 |
| `func_001DDA20` | Matching | 100.00% | 8 |
| `func_001DDA28` | Matching | 100.00% | 8 |
| `func_001DDA30` | Matching | 100.00% | 16 |
| `func_001DDA40` | Matching | 100.00% | 16 |
| `func_001DDA50` | Matching | 100.00% | 16 |
| `func_001DDA60` | Matching | 100.00% | 24 |
| `func_001DDA78` | Matching | 100.00% | 8 |
| `func_001DDA80` | Matching | 100.00% | 16 |
| `func_001DDA90` | Matching | 100.00% | 16 |
| `func_001DDAA0` | Matching | 100.00% | 16 |
| `func_001DDAB0` | Matching | 100.00% | 24 |
| `func_001DDAC8` | Matching | 100.00% | 8 |
| `func_001DDAD0` | Matching | 100.00% | 16 |
| `func_001DDAE0` | Matching | 100.00% | 16 |
| `func_001DDAF0` | Matching | 100.00% | 16 |
| `func_001DDB00` | Matching | 100.00% | 24 |
| `func_001DDB18` | Matching | 100.00% | 8 |
| `func_001DDB20` | Matching | 100.00% | 16 |
| `func_001DDB30` | Matching | 100.00% | 16 |
| `func_001DDB40` | Matching | 100.00% | 16 |
| `func_001DDB50` | Matching | 100.00% | 24 |
| `func_001DDB68` | Matching | 100.00% | 8 |
| `func_001DDB70` | Matching | 100.00% | 16 |
| `func_001DDB80` | Matching | 100.00% | 16 |
| `func_001DDB90` | Matching | 100.00% | 16 |
| `func_001DDBA0` | Matching | 100.00% | 24 |
| `func_001DDBB8` | Matching | 100.00% | 8 |
| `func_001DDBC0` | Matching | 100.00% | 8 |
| `func_001DDBC8` | Matching | 100.00% | 8 |
| `func_001DDBD0` | Matching | 100.00% | 80 |
| `func_001DDC20` | Matching | 100.00% | 8 |
| `func_001DDC28` | Matching | 100.00% | 8 |
| `func_001DDC30` | Matching | 100.00% | 8 |
| `func_001DDC38` | Matching | 100.00% | 8 |
| `func_001DDC40` | Matching | 100.00% | 8 |
| `func_001DDC48` | Matching | 100.00% | 68 |
| `func_001DDC90` | Matching | 100.00% | 40 |
| `func_001DDCB8` | Matching | 100.00% | 8 |
| `func_001DDCC0` | Matching | 100.00% | 8 |
| `func_001DDCC8` | Matching | 100.00% | 28 |
| `func_001DDCE8` | Matching | 100.00% | 28 |
| `func_001DDD08` | Matching | 100.00% | 28 |
| `func_001DDD28` | Matching | 100.00% | 12 |
| `func_001DDD38` | Matching | 100.00% | 12 |
| `func_001DDD48` | Matching | 100.00% | 12 |
| `func_001DDD58` | Matching | 100.00% | 16 |
| `func_001DDD68` | Matching | 100.00% | 12 |
| `func_001DDD78` | Matching | 100.00% | 12 |
| `func_001DDD88` | Matching | 100.00% | 16 |
| `func_001DDD98` | Matching | 100.00% | 16 |
| `func_001DDDA8` | Matching | 100.00% | 12 |
| `func_001DDDB8` | Matching | 100.00% | 16 |
| `func_001DDDC8` | Matching | 100.00% | 12 |
| `func_001DDDD8` | Matching | 100.00% | 8 |
| `func_001DDDE0` | Matching | 100.00% | 8 |
| `func_001DDDE8` | Matching | 100.00% | 8 |
| `func_001DDDF0` | Matching | 100.00% | 8 |
| `func_001DDDF8` | Matching | 100.00% | 8 |
| `func_001DDE00` | Matching | 100.00% | 8 |
| `func_001DDE08` | Matching | 100.00% | 8 |
| `func_001DDE10` | Matching | 100.00% | 8 |
| `func_001DDE18` | Matching | 100.00% | 96 |
| `func_001DDE78` | Matching | 100.00% | 60 |
| `func_001DDEB8` | Matching | 100.00% | 40 |
| `func_001DDEE0` | Matching | 100.00% | 8 |
| `func_001DDEE8` | Matching | 100.00% | 56 |
| `func_001DDF20` | Matching | 100.00% | 40 |
| `func_001DDF48` | Matching | 100.00% | 56 |
| `func_001DDF80` | Matching | 100.00% | 40 |
| `func_001DDFA8` | Matching | 100.00% | 8 |
| `func_001DDFB0` | Matching | 100.00% | 56 |
| `func_001DDFE8` | Matching | 100.00% | 40 |
| `func_001DE010` | Matching | 100.00% | 8 |
| `func_001DE018` | Matching | 100.00% | 56 |
| `func_001DE050` | Matching | 100.00% | 40 |
| `func_001DE078` | Matching | 100.00% | 8 |
| `func_001DE080` | Matching | 100.00% | 60 |
| `func_001DE0C0` | Matching | 100.00% | 40 |
| `func_001DE0E8` | Matching | 100.00% | 8 |
| `func_001DE0F0` | Matching | 100.00% | 56 |
| `func_001DE128` | Matching | 100.00% | 40 |
| `func_001DE150` | Matching | 100.00% | 40 |
| `func_001DE178` | Matching | 100.00% | 60 |
| `func_001DE1B8` | Matching | 100.00% | 56 |
| `func_001DE1F0` | Matching | 100.00% | 40 |
| `func_001DE218` | Matching | 100.00% | 40 |
| `func_001DE240` | Matching | 100.00% | 60 |
| `func_001DE280` | Matching | 100.00% | 8 |
| `func_001DE288` | Matching | 100.00% | 76 |
| `func_001DE2D8` | Matching | 100.00% | 8 |
| `func_001DE2E0` | Matching | 100.00% | 8 |
| `func_001DE2E8` | Matching | 100.00% | 28 |
| `func_001DE308` | Matching | 100.00% | 8 |
| `func_001DE310` | Matching | 100.00% | 8 |
| `func_001DE318` | Matching | 100.00% | 8 |
| `func_001DE320` | Matching | 100.00% | 8 |
| `func_001DE328` | Matching | 100.00% | 8 |
| `func_001DE330` | Matching | 100.00% | 8 |
| `func_001DE338` | Matching | 100.00% | 8 |
| `func_001DE340` | Matching | 100.00% | 8 |
| `func_001DE348` | Matching | 100.00% | 8 |
| `func_001DE350` | Matching | 100.00% | 36 |
| `func_001DE378` | Matching | 100.00% | 36 |
| `func_001DE3A0` | Matching | 100.00% | 36 |
| `func_001DE3C8` | Matching | 100.00% | 36 |
| `func_001DE3F0` | Matching | 100.00% | 36 |
| `func_001DE418` | Matching | 100.00% | 36 |
| `func_001DE440` | Matching | 100.00% | 8 |
| `func_001DE448` | Matching | 100.00% | 8 |
| `func_001DE450` | Matching | 100.00% | 8 |
| `func_001DE458` | Matching | 100.00% | 8 |
| `func_001DE460` | Matching | 100.00% | 8 |
| `func_001DE468` | Matching | 100.00% | 8 |
| `func_001DE470` | Matching | 100.00% | 36 |
| `func_001DE498` | Matching | 100.00% | 24 |
| `func_001DE4B0` | Matching | 100.00% | 56 |
| `func_001DE4E8` | Matching | 100.00% | 64 |
| `func_001DE528` | Matching | 100.00% | 40 |
| `func_001DE550` | Matching | 100.00% | 8 |
| `func_001DE558` | Matching | 100.00% | 56 |
| `func_001DE590` | Matching | 100.00% | 52 |
| `func_001DE5C8` | Matching | 100.00% | 40 |
| `func_001DE5F0` | Matching | 100.00% | 56 |
| `func_001DE628` | Matching | 100.00% | 60 |
| `func_001DE668` | Matching | 100.00% | 40 |
| `func_001DE690` | Matching | 100.00% | 56 |
| `func_001DE6C8` | Matching | 100.00% | 40 |
| `func_001DE6F0` | Matching | 100.00% | 56 |
| `func_001DE728` | Matching | 100.00% | 40 |
| `func_001DE750` | Matching | 100.00% | 56 |
| `func_001DE788` | Matching | 100.00% | 40 |
| `func_001DE7B0` | Matching | 100.00% | 176 |
| `func_001DE860` | Matching | 100.00% | 8 |
| `func_001DE868` | Matching | 100.00% | 8 |
| `func_001DE870` | Matching | 100.00% | 8 |
| `func_001DE878` | Matching | 100.00% | 8 |
| `func_001DE880` | Matching | 100.00% | 16 |
| `func_001DE890` | Matching | 100.00% | 12 |
| `func_001DE8A0` | Matching | 100.00% | 8 |
| `func_001DE8A8` | Matching | 100.00% | 28 |
| `func_001DE8C8` | Matching | 100.00% | 60 |
| `func_001DE908` | Matching | 100.00% | 8 |
| `func_001DE910` | Matching | 100.00% | 8 |
| `func_001DE918` | Matching | 100.00% | 40 |
| `func_001DE940` | Matching | 100.00% | 8 |
| `func_001DE948` | Matching | 100.00% | 8 |
| `func_001DE950` | Matching | 100.00% | 60 |
| `func_001DE990` | Matching | 100.00% | 56 |
| `func_001DE9C8` | Matching | 100.00% | 40 |
| `func_001DE9F0` | Matching | 100.00% | 8 |
| `func_001DE9F8` | Matching | 100.00% | 40 |
| `func_001DEA20` | Matching | 100.00% | 92 |
| `func_001DEA80` | Matching | 100.00% | 36 |
| `func_001DEAA8` | Matching | 100.00% | 164 |
| `func_001DEB50` | Matching | 100.00% | 8 |
| `func_001DEB58` | Matching | 100.00% | 40 |
| `func_001DEB80` | Matching | 100.00% | 8 |
| `func_001DEB88` | Matching | 100.00% | 8 |
| `func_001DB418` | Matching | 99.93% | 268 |

### `main/debugmenu`

94 matching, 0 partial, 0 not started (94 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cRenderTogglesMenu_cRenderTogglesMenu` | Matching | 100.00% | 2832 |
| `cVisualEffectsTestMenu_cVisualEffectsTestMenu` | Matching | 100.00% | 1112 |
| `cPlantsMenu_cPlantsMenu` | Matching | 100.00% | 892 |
| `cLightGlowMenu_cLightGlowMenu` | Matching | 100.00% | 1880 |
| `cDepthFogMenu_cDepthFogMenu` | Matching | 100.00% | 648 |
| `cHeightFogMenu_cHeightFogMenu` | Matching | 100.00% | 316 |
| `cDetailSystemMenu_cDetailSystemMenu` | Matching | 100.00% | 792 |
| `cShellRendererMenu_cShellRendererMenu` | Matching | 100.00% | 676 |
| `cScreenTintMenu_cScreenTintMenu` | Matching | 100.00% | 2444 |
| `cShadowMenu_cShadowMenu` | Matching | 100.00% | 728 |
| `cSnowSurfaceMenu_cSnowSurfaceMenu` | Matching | 100.00% | 596 |
| `cBoardTrailMenu_cBoardTrailMenu` | Matching | 100.00% | 1508 |
| `cFlagsMenu_cFlagsMenu` | Matching | 100.00% | 256 |
| `cPowerUpFXTogglesMenu_cPowerUpFXTogglesMenu` | Matching | 100.00% | 1048 |
| `cSnowfallTogglesMenu_cSnowfallTogglesMenu` | Matching | 100.00% | 888 |
| `cSplashTogglesMenu_cSplashTogglesMenu` | Matching | 100.00% | 3392 |
| `cTubeMenu_cTubeMenu` | Matching | 100.00% | 524 |
| `cPathArrowMenu_cPathArrowMenu` | Matching | 100.00% | 1088 |
| `cVisualEffectsMainMenu_cVisualEffectsMainMenu` | Matching | 100.00% | 928 |
| `func_0024D690(void*)` | Matching | 100.00% | 28 |
| `func_0024D6B0(void*)` | Matching | 100.00% | 28 |
| `func_0024D6D0` | Matching | 100.00% | 60 |
| `func_0024D710` | Matching | 100.00% | 644 |
| `func_0024D998` | Matching | 100.00% | 284 |
| `func_0024DAB8` | Matching | 100.00% | 428 |
| `func_0024DC68` | Matching | 100.00% | 260 |
| `func_0024DD70` | Matching | 100.00% | 560 |
| `func_0024DFA0` | Matching | 100.00% | 344 |
| `func_0024E0F8` | Matching | 100.00% | 260 |
| `func_0024E200` | Matching | 100.00% | 392 |
| `func_0024E388` | Matching | 100.00% | 1088 |
| `func_0024E7C8` | Matching | 100.00% | 272 |
| `func_0024F6C0` | Matching | 100.00% | 284 |
| `func_0024F7E0(void*)` | Matching | 100.00% | 28 |
| `func_0024F800(void*)` | Matching | 100.00% | 28 |
| `func_0024F820(void*)` | Matching | 100.00% | 28 |
| `func_0024F840(void*)` | Matching | 100.00% | 28 |
| `func_0024F860` | Matching | 100.00% | 224 |
| `func_0024F940(void*)` | Matching | 100.00% | 28 |
| `func_0024F960(void*)` | Matching | 100.00% | 28 |
| `func_0024F980(void*)` | Matching | 100.00% | 28 |
| `func_0024F9A0(void*)` | Matching | 100.00% | 28 |
| `func_0024F9C0(void*)` | Matching | 100.00% | 28 |
| `func_0024F9E0(void*)` | Matching | 100.00% | 28 |
| `func_0024FA00` | Matching | 100.00% | 116 |
| `func_0024FA78(void*)` | Matching | 100.00% | 28 |
| `func_0024FA98(void*)` | Matching | 100.00% | 28 |
| `func_0024FAB8` | Matching | 100.00% | 200 |
| `func_0024FB80(void*)` | Matching | 100.00% | 28 |
| `func_0024FBA0(void*)` | Matching | 100.00% | 28 |
| `func_0024FBC0` | Matching | 100.00% | 188 |
| `func_0024FC80(void*)` | Matching | 100.00% | 28 |
| `func_0024FCA0(void*)` | Matching | 100.00% | 28 |
| `func_0024FCC0(void*)` | Matching | 100.00% | 28 |
| `func_0024FCE0(void*)` | Matching | 100.00% | 28 |
| `func_0024FD00` | Matching | 100.00% | 188 |
| `func_0024FDC0(void*)` | Matching | 100.00% | 28 |
| `func_0024FDE0(void*)` | Matching | 100.00% | 28 |
| `func_0024FE00` | Matching | 100.00% | 164 |
| `func_0024FEA8(void*)` | Matching | 100.00% | 28 |
| `func_0024FEC8(void*)` | Matching | 100.00% | 28 |
| `func_0024FEE8(void*)` | Matching | 100.00% | 28 |
| `func_0024FF08(void*)` | Matching | 100.00% | 28 |
| `func_0024FF28` | Matching | 100.00% | 104 |
| `func_0024FF90(void*)` | Matching | 100.00% | 28 |
| `func_0024FFB0(void*)` | Matching | 100.00% | 28 |
| `func_0024FFD0(void*)` | Matching | 100.00% | 28 |
| `func_0024FFF0(void*)` | Matching | 100.00% | 28 |
| `func_00250010(void*)` | Matching | 100.00% | 28 |
| `func_00250030(void*)` | Matching | 100.00% | 28 |
| `func_00250050(void*)` | Matching | 100.00% | 28 |
| `func_00250070(void*)` | Matching | 100.00% | 28 |
| `func_00250090` | Matching | 100.00% | 152 |
| `func_00250128(void*)` | Matching | 100.00% | 28 |
| `func_00250148(void*)` | Matching | 100.00% | 28 |
| `func_00250168(void*)` | Matching | 100.00% | 28 |
| `func_00250188(void*)` | Matching | 100.00% | 28 |
| `func_002501A8(void*)` | Matching | 100.00% | 32 |
| `func_002501C8(void*)` | Matching | 100.00% | 32 |
| `cAvalancheMenu_cAvalancheMenu` | Matching | 100.00% | 2032 |
| `cAIVisualEffectsMainMenu_cAIVisualEffectsMainMenu` | Matching | 100.00% | 132 |
| `func_00250A60(void*)` | Matching | 100.00% | 28 |
| `func_00250A80(void*)` | Matching | 100.00% | 28 |
| `func_00250AA0` | Matching | 100.00% | 60 |
| `func_00250AE0` | Matching | 100.00% | 464 |
| `func_002515F0(void*)` | Matching | 100.00% | 28 |
| `func_00251610(void*)` | Matching | 100.00% | 28 |
| `func_00251630` | Matching | 100.00% | 92 |
| `func_00251690(void*)` | Matching | 100.00% | 32 |
| `func_002516B0(void*)` | Matching | 100.00% | 32 |
| `MEM_initblock` | Matching | 100.00% | 32 |
| `func_002516F0` | Matching | 100.00% | 40 |
| `func_0024E8D8` | Matching | 99.99% | 3560 |
| `func_00250CB0` | Matching | 99.99% | 2368 |

### `main/game`

28 matching, 0 partial, 4 not started (32 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGame_renderModels` | Matching | 100.00% | 312 |
| `func_0022C1B0` | Matching | 100.00% | 520 |
| `func_0022C3B8` | Matching | 100.00% | 88 |
| `cGame_renderFogVolumes` | Matching | 100.00% | 132 |
| `cGame_renderLightHalos` | Matching | 100.00% | 156 |
| `func_0022CCE8` | Matching | 100.00% | 44 |
| `func_0022CD18` | Matching | 100.00% | 36 |
| `func_0022CD40` | Matching | 100.00% | 360 |
| `func_0022D278` | Matching | 100.00% | 280 |
| `func_0022D390` | Matching | 100.00% | 68 |
| `func_0022D3D8` | Matching | 100.00% | 160 |
| `func_0022D598` | Matching | 100.00% | 164 |
| `func_0022D640` | Matching | 100.00% | 36 |
| `func_0022D668` | Matching | 100.00% | 92 |
| `func_0022D6C8` | Matching | 100.00% | 524 |
| `func_0022D8D8` | Matching | 100.00% | 1408 |
| `func_0022DE58` | Matching | 100.00% | 64 |
| `func_0022DE98` | Matching | 100.00% | 184 |
| `func_0022DF50` | Matching | 100.00% | 124 |
| `func_0022DFD0(void*)` | Matching | 100.00% | 28 |
| `func_0022DFF0` | Matching | 100.00% | 136 |
| `func_0022E078` | Matching | 100.00% | 32 |
| `func_0022E098` | Matching | 100.00% | 48 |
| `func_0022E0C8` | Matching | 100.00% | 24 |
| `func_0022E0E0` | Matching | 100.00% | 56 |
| `func_0022D478` | Matching | 99.94% | 284 |
| `cGame_renderPatches` | Matching | 99.82% | 228 |
| `func_0022E118` | Matching | 99.80% | 100 |

### `main/gameload`

33 matching, 0 partial, 6 not started (39 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGame_loadTrack` | Matching | 100.00% | 1000 |
| `func_00230050` | Matching | 100.00% | 160 |
| `func_002300F0` | Matching | 100.00% | 140 |
| `func_00230180` | Matching | 100.00% | 296 |
| `cGame_restart` | Matching | 100.00% | 144 |
| `func_00230338` | Matching | 100.00% | 36 |
| `func_00230360` | Matching | 100.00% | 204 |
| `cGame_exit` | Matching | 100.00% | 208 |
| `func_002305C8` | Matching | 100.00% | 116 |
| `func_00230640` | Matching | 100.00% | 88 |
| `func_00230698(void*, int)` | Matching | 100.00% | 16 |
| `func_002306A8(void*, int)` | Matching | 100.00% | 16 |
| `func_00230E90` | Matching | 100.00% | 8 |
| `func_00230E98` | Matching | 100.00% | 168 |
| `func_00230F40` | Matching | 100.00% | 780 |
| `func_00231250` | Matching | 100.00% | 40 |
| `func_00231278(void*, int)` | Matching | 100.00% | 8 |
| `func_00231280` | Matching | 100.00% | 88 |
| `func_002312D8` | Matching | 100.00% | 72 |
| `func_00231320` | Matching | 100.00% | 40 |
| `func_00231348` | Matching | 100.00% | 388 |
| `func_002314D0` | Matching | 100.00% | 876 |
| `func_00231840` | Matching | 100.00% | 632 |
| `func_00231AB8` | Matching | 100.00% | 152 |
| `func_00231C70` | Matching | 100.00% | 60 |
| `func_00231CB0(void*)` | Matching | 100.00% | 28 |
| `func_00231D60` | Matching | 100.00% | 540 |
| `func_00232328(void*)` | Matching | 100.00% | 28 |
| `func_00231FC0` | Matching | 99.93% | 868 |
| `func_00231F80` | Matching | 99.67% | 60 |
| `func_00231CF0` | Matching | 99.50% | 40 |
| `func_00231D18` | Matching | 99.41% | 68 |
| `func_00231CD0` | Matching | 99.38% | 32 |

### `main/gamemode`

48 matching, 0 partial, 5 not started (53 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGameModeMan_getGM` | Matching | 100.00% | 1004 |
| `func_002380E8` | Matching | 100.00% | 120 |
| `cGameModeMan_initGameMode` | Matching | 100.00% | 344 |
| `func_002382B8` | Matching | 100.00% | 28 |
| `cGameModeMan_restartHeat` | Matching | 100.00% | 112 |
| `func_00238348(void*)` | Matching | 100.00% | 12 |
| `func_00238358` | Matching | 100.00% | 440 |
| `func_00238510` | Matching | 100.00% | 64 |
| `func_00238550` | Matching | 100.00% | 64 |
| `func_00238590` | Matching | 100.00% | 64 |
| `func_002385D0` | Matching | 100.00% | 720 |
| `func_002388A0` | Matching | 100.00% | 720 |
| `func_00238B70` | Matching | 100.00% | 136 |
| `func_00238BF8` | Matching | 100.00% | 136 |
| `func_00238C80` | Matching | 100.00% | 172 |
| `func_00238D30` | Matching | 100.00% | 120 |
| `func_00238DA8` | Matching | 100.00% | 120 |
| `func_00238E20` | Matching | 100.00% | 1036 |
| `func_00239230` | Matching | 100.00% | 1716 |
| `func_00239938` | Matching | 100.00% | 356 |
| `func_00239AA0` | Matching | 100.00% | 576 |
| `func_00239CE0` | Matching | 100.00% | 52 |
| `func_00239D18` | Matching | 100.00% | 52 |
| `func_00239D50` | Matching | 100.00% | 52 |
| `func_00239D88` | Matching | 100.00% | 320 |
| `func_0023A070` | Matching | 100.00% | 148 |
| `func_0023A108` | Matching | 100.00% | 1000 |
| `func_0023A4F0` | Matching | 100.00% | 376 |
| `func_0023AC10(void*)` | Matching | 100.00% | 8 |
| `func_0023AC18` | Matching | 100.00% | 52 |
| `func_0023AC50` | Matching | 100.00% | 52 |
| `func_0023AC88` | Matching | 100.00% | 372 |
| `func_0023AE00` | Matching | 100.00% | 564 |
| `func_0023B038` | Matching | 100.00% | 52 |
| `func_0023B070` | Matching | 100.00% | 52 |
| `func_0023B170` | Matching | 100.00% | 248 |
| `func_0023B268` | Matching | 100.00% | 512 |
| `func_0023B468` | Matching | 100.00% | 396 |
| `func_0023B6C0` | Matching | 100.00% | 520 |
| `func_0023B8C8` | Matching | 100.00% | 716 |
| `func_0023BB98` | Matching | 100.00% | 544 |
| `func_0023BDB8` | Matching | 100.00% | 788 |
| `func_0023C0D0` | Matching | 100.00% | 516 |
| `func_0023C2D8` | Matching | 100.00% | 648 |
| `func_0023C560` | Matching | 100.00% | 180 |
| `func_0023C618` | Matching | 100.00% | 344 |
| `func_0023C770` | Matching | 100.00% | 152 |
| `func_0023B5F8` | Matching | 99.90% | 196 |

### `main/gamerender`

8 matching, 0 partial, 0 not started (8 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGameViewMan_cGameViewMan` | Matching | 100.00% | 404 |
| `func_0022E550` | Matching | 100.00% | 480 |
| `func_0022E730` | Matching | 100.00% | 148 |
| `func_0022E7C8` | Matching | 100.00% | 120 |
| `cGameViewMan_updateAll` | Matching | 100.00% | 116 |
| `func_0022E8B8` | Matching | 100.00% | 100 |
| `func_0022E920` | Matching | 100.00% | 68 |
| `func_0022E968` | Matching | 100.00% | 608 |

### `main/gamestate`

70 matching, 0 partial, 3 not started (73 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGFGateState_gainFocus` | Matching | 100.00% | 280 |
| `func_00234BE8` | Matching | 100.00% | 128 |
| `cGFGateState_update` | Matching | 100.00% | 376 |
| `func_00234DE0(void*)` | Matching | 100.00% | 28 |
| `func_00234E00(void*)` | Matching | 100.00% | 28 |
| `func_00234E20` | Matching | 100.00% | 148 |
| `func_00234EB8(void*)` | Matching | 100.00% | 28 |
| `func_00234ED8(void*)` | Matching | 100.00% | 28 |
| `func_00234EF8` | Matching | 100.00% | 72 |
| `func_00234F40` | Matching | 100.00% | 320 |
| `func_00235570` | Matching | 100.00% | 60 |
| `func_002355B0` | Matching | 100.00% | 16 |
| `func_002355C0` | Matching | 100.00% | 564 |
| `func_002357F8` | Matching | 100.00% | 112 |
| `func_00235868` | Matching | 100.00% | 296 |
| `func_00235990` | Matching | 100.00% | 132 |
| `func_00235A18` | Matching | 100.00% | 132 |
| `func_00235AA0` | Matching | 100.00% | 552 |
| `func_00235CC8` | Matching | 100.00% | 600 |
| `func_00235F20` | Matching | 100.00% | 40 |
| `func_00235F48` | Matching | 100.00% | 132 |
| `func_00235FD0` | Matching | 100.00% | 132 |
| `func_00236058` | Matching | 100.00% | 316 |
| `func_00236198` | Matching | 100.00% | 44 |
| `func_002361C8(void*)` | Matching | 100.00% | 28 |
| `func_002361E8(void*)` | Matching | 100.00% | 28 |
| `func_00236208` | Matching | 100.00% | 68 |
| `func_00236250` | Matching | 100.00% | 456 |
| `func_00236728` | Matching | 100.00% | 160 |
| `func_002367C8` | Matching | 100.00% | 160 |
| `func_00236868` | Matching | 100.00% | 52 |
| `func_002368A0` | Matching | 100.00% | 192 |
| `func_00236960` | Matching | 100.00% | 396 |
| `func_00236AF0(void*)` | Matching | 100.00% | 8 |
| `func_00236AF8(void*)` | Matching | 100.00% | 28 |
| `func_00236B18(void*)` | Matching | 100.00% | 28 |
| `func_00236B38` | Matching | 100.00% | 52 |
| `func_00236B70(void*)` | Matching | 100.00% | 28 |
| `func_00236B90(void*)` | Matching | 100.00% | 28 |
| `func_00236BB0` | Matching | 100.00% | 152 |
| `func_00236C48` | Matching | 100.00% | 64 |
| `func_00236C88` | Matching | 100.00% | 80 |
| `func_00236CD8` | Matching | 100.00% | 132 |
| `func_00236D60(void*)` | Matching | 100.00% | 28 |
| `func_00236D80(void*)` | Matching | 100.00% | 28 |
| `func_00236DA0` | Matching | 100.00% | 188 |
| `func_00236E60` | Matching | 100.00% | 60 |
| `func_00236EA0` | Matching | 100.00% | 36 |
| `func_00236EC8(void*)` | Matching | 100.00% | 28 |
| `func_00236EE8(void*)` | Matching | 100.00% | 28 |
| `func_00236F08` | Matching | 100.00% | 56 |
| `func_00236F40` | Matching | 100.00% | 76 |
| `func_00236F90` | Matching | 100.00% | 20 |
| `func_00236FA8(void*)` | Matching | 100.00% | 28 |
| `func_00236FC8(void*)` | Matching | 100.00% | 28 |
| `func_00236FE8` | Matching | 100.00% | 68 |
| `func_00237030(void*)` | Matching | 100.00% | 8 |
| `func_00237038` | Matching | 100.00% | 40 |
| `func_00237060` | Matching | 100.00% | 60 |
| `func_002370A0` | Matching | 100.00% | 160 |
| `func_00237140` | Matching | 100.00% | 320 |
| `func_00237280` | Matching | 100.00% | 312 |
| `func_00237948(void*)` | Matching | 100.00% | 8 |
| `func_00237950` | Matching | 100.00% | 116 |
| `func_002379C8` | Matching | 100.00% | 204 |
| `func_00237A98` | Matching | 100.00% | 140 |
| `func_00237B28` | Matching | 100.00% | 188 |
| `func_00237BE8` | Matching | 100.00% | 196 |
| `func_00237CB0` | Matching | 100.00% | 36 |
| `func_00237CD8` | Matching | 100.00% | 32 |

### `main/loadscreens`

2 matching, 0 partial, 2 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBackgroundMan_loadImages` | Matching | 100.00% | 308 |
| `func_0017AE00` | Matching | 100.00% | 940 |

### `main/loadscreens_prestart`

34 matching, 0 partial, 0 not started (34 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPreStartScreen_update` | Matching | 100.00% | 320 |
| `func_00232488` | Matching | 100.00% | 136 |
| `func_00232510` | Matching | 100.00% | 40 |
| `func_00232538` | Matching | 100.00% | 48 |
| `func_00232568` | Matching | 100.00% | 32 |
| `func_00232588` | Matching | 100.00% | 200 |
| `func_00232650` | Matching | 100.00% | 136 |
| `func_002326D8` | Matching | 100.00% | 52 |
| `func_00232710(void*)` | Matching | 100.00% | 8 |
| `func_00232718(void*)` | Matching | 100.00% | 8 |
| `func_00232720(void*)` | Matching | 100.00% | 24 |
| `func_00232738(void*)` | Matching | 100.00% | 24 |
| `func_00232750` | Matching | 100.00% | 48 |
| `func_00232780` | Matching | 100.00% | 48 |
| `func_002327B0` | Matching | 100.00% | 52 |
| `func_002327E8` | Matching | 100.00% | 52 |
| `func_00232820` | Matching | 100.00% | 136 |
| `func_002328A8` | Matching | 100.00% | 136 |
| `func_00232930` | Matching | 100.00% | 216 |
| `cPreFELoadScreen_update` | Matching | 100.00% | 216 |
| `func_00232AE0` | Matching | 100.00% | 72 |
| `func_00232B28` | Matching | 100.00% | 364 |
| `func_00232C98` | Matching | 100.00% | 96 |
| `func_00232CF8(void*)` | Matching | 100.00% | 28 |
| `func_00232D18` | Matching | 100.00% | 56 |
| `func_00232D50` | Matching | 100.00% | 88 |
| `func_00232DA8` | Matching | 100.00% | 116 |
| `func_00232E20` | Matching | 100.00% | 552 |
| `cGameLoadScreen_loadTexture` | Matching | 100.00% | 536 |
| `func_00233260` | Matching | 100.00% | 100 |
| `func_002332C8(void*)` | Matching | 100.00% | 32 |
| `func_002332E8` | Matching | 100.00% | 168 |
| `func_00233390` | Matching | 100.00% | 116 |
| `func_00233408` | Matching | 100.00% | 48 |

### `main/sectionman`

7 matching, 0 partial, 0 not started (7 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSectionMan_setSky` | Matching | 100.00% | 164 |
| `func_0022E228` | Matching | 100.00% | 76 |
| `func_0022E278(void*)` | Matching | 100.00% | 16 |
| `func_0022E288(void *, void *)` | Matching | 100.00% | 16 |
| `func_0022E298` | Matching | 100.00% | 172 |
| `func_0022E348` | Matching | 100.00% | 24 |
| `func_0022E360` | Matching | 100.00% | 84 |

### `main/ssxapp`

44 matching, 0 partial, 5 not started (49 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSSXApp_cSSXApp` | Matching | 100.00% | 208 |
| `cSSXApp_init` | Matching | 100.00% | 608 |
| `cSSXApp_loadInputMap` | Matching | 100.00% | 4236 |
| `cSSXApp_parseCommandLine` | Matching | 100.00% | 628 |
| `cSSXApp_flush()` | Matching | 100.00% | 44 |
| `cSSXApp_preUpdate` | Matching | 100.00% | 192 |
| `cSSXApp_timerCallback()` | Matching | 100.00% | 36 |
| `func_00227F80` | Matching | 100.00% | 28 |
| `func_00227FA0` | Matching | 100.00% | 28 |
| `cSSXApp_purge` | Matching | 100.00% | 536 |
| `cSSXApp_startGameLoad` | Matching | 100.00% | 92 |
| `func_00228238` | Matching | 100.00% | 148 |
| `cSSXApp_initload` | Matching | 100.00% | 1956 |
| `cSSXApp_initLocale` | Matching | 100.00% | 320 |
| `cSSXApp_loadexecpurge(void*)` | Matching | 100.00% | 76 |
| `func_00228C08` | Matching | 100.00% | 728 |
| `initOnline` | Matching | 100.00% | 672 |
| `func_00229180` | Matching | 100.00% | 248 |
| `func_00229278` | Matching | 100.00% | 100 |
| `func_002292E0` | Matching | 100.00% | 184 |
| `func_00229398` | Matching | 100.00% | 112 |
| `func_00229408` | Matching | 100.00% | 140 |
| `func_00229498` | Matching | 100.00% | 44 |
| `func_002294C8` | Matching | 100.00% | 100 |
| `func_00229530` | Matching | 100.00% | 516 |
| `func_00229738` | Matching | 100.00% | 76 |
| `func_00229788` | Matching | 100.00% | 80 |
| `func_002297D8` | Matching | 100.00% | 72 |
| `func_00229820` | Matching | 100.00% | 236 |
| `func_00229B90` | Matching | 100.00% | 24 |
| `func_00229E20` | Matching | 100.00% | 52 |
| `func_00229E58` | Matching | 100.00% | 216 |
| `func_00229F30` | Matching | 100.00% | 80 |
| `func_00229F80(void*)` | Matching | 100.00% | 8 |
| `func_00229F88` | Matching | 100.00% | 64 |
| `func_00229FC8` | Matching | 100.00% | 352 |
| `func_0022A128` | Matching | 100.00% | 324 |
| `func_0022A270` | Matching | 100.00% | 244 |
| `func_0022A368` | Matching | 100.00% | 156 |
| `func_0022A408` | Matching | 100.00% | 156 |
| `func_0022A4A8` | Matching | 100.00% | 248 |
| `func_0022A698` | Matching | 100.00% | 212 |
| `func_0022A770` | Matching | 100.00% | 192 |
| `func_0022ADD8` | Matching | 99.68% | 556 |

### `main/ssxappdtor`

196 matching, 0 partial, 1 not started (197 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSSXApp__cSSXApp` | Matching | 100.00% | 92 |
| `func_00243950` | Matching | 100.00% | 8 |
| `func_00243958` | Matching | 100.00% | 8 |
| `func_00243960` | Matching | 100.00% | 8 |
| `func_00243968` | Matching | 100.00% | 8 |
| `func_00243970` | Matching | 100.00% | 8 |
| `func_00243978` | Matching | 100.00% | 8 |
| `func_00243980` | Matching | 100.00% | 16 |
| `func_00243990` | Matching | 100.00% | 16 |
| `func_002439A0` | Matching | 100.00% | 8 |
| `func_002439A8` | Matching | 100.00% | 8 |
| `func_002439B0` | Matching | 100.00% | 8 |
| `func_002439B8` | Matching | 100.00% | 8 |
| `func_002439C0` | Matching | 100.00% | 8 |
| `func_002439C8` | Matching | 100.00% | 8 |
| `func_002439D0` | Matching | 100.00% | 8 |
| `func_002439D8` | Matching | 100.00% | 8 |
| `func_002439E0` | Matching | 100.00% | 8 |
| `func_002439E8` | Matching | 100.00% | 12 |
| `func_002439F8` | Matching | 100.00% | 8 |
| `func_00243A00` | Matching | 100.00% | 12 |
| `func_00243A10` | Matching | 100.00% | 36 |
| `func_00243A38` | Matching | 100.00% | 8 |
| `func_00243A40` | Matching | 100.00% | 48 |
| `func_00243A70` | Matching | 100.00% | 12 |
| `func_00243A80` | Matching | 100.00% | 48 |
| `func_00243AB0(void*)` | Matching | 100.00% | 8 |
| `func_00243AB8` | Matching | 100.00% | 28 |
| `func_00243AD8` | Matching | 100.00% | 12 |
| `func_00243AE8` | Matching | 100.00% | 48 |
| `func_00243B18` | Matching | 100.00% | 56 |
| `func_00243B50` | Matching | 100.00% | 48 |
| `func_00243B80` | Matching | 100.00% | 48 |
| `func_00243BB0` | Matching | 100.00% | 64 |
| `func_00243BF0` | Matching | 100.00% | 16 |
| `func_00243C00` | Matching | 100.00% | 48 |
| `func_00243C30` | Matching | 100.00% | 64 |
| `func_00243C70` | Matching | 100.00% | 16 |
| `func_00243C80` | Matching | 100.00% | 48 |
| `func_00243CB0(void*)` | Matching | 100.00% | 8 |
| `func_00243CB8(void*)` | Matching | 100.00% | 8 |
| `func_00243CC0(void*)` | Matching | 100.00% | 8 |
| `func_00243CC8(void*)` | Matching | 100.00% | 8 |
| `func_00243CD0(void*)` | Matching | 100.00% | 8 |
| `func_00243CD8(void*)` | Matching | 100.00% | 8 |
| `func_00243CE0(void*)` | Matching | 100.00% | 8 |
| `func_00243CE8(void*)` | Matching | 100.00% | 8 |
| `func_00243CF0` | Matching | 100.00% | 48 |
| `func_00243D20` | Matching | 100.00% | 52 |
| `func_00243D58` | Matching | 100.00% | 48 |
| `func_00243D88` | Matching | 100.00% | 48 |
| `func_00243DB8` | Matching | 100.00% | 48 |
| `func_00243DE8` | Matching | 100.00% | 52 |
| `func_00243E20` | Matching | 100.00% | 48 |
| `func_00243E50` | Matching | 100.00% | 48 |
| `func_00243E80` | Matching | 100.00% | 52 |
| `func_00243EB8` | Matching | 100.00% | 48 |
| `func_00243EE8` | Matching | 100.00% | 52 |
| `func_00243F20` | Matching | 100.00% | 48 |
| `func_00243F50` | Matching | 100.00% | 48 |
| `func_00243F80` | Matching | 100.00% | 64 |
| `func_00243FC0` | Matching | 100.00% | 48 |
| `func_00243FF0` | Matching | 100.00% | 52 |
| `func_00244028` | Matching | 100.00% | 48 |
| `func_00244058` | Matching | 100.00% | 8 |
| `func_00244060` | Matching | 100.00% | 48 |
| `func_00244090` | Matching | 100.00% | 48 |
| `func_002440C0` | Matching | 100.00% | 52 |
| `func_002440F8` | Matching | 100.00% | 48 |
| `func_00244128` | Matching | 100.00% | 52 |
| `func_00244160` | Matching | 100.00% | 48 |
| `func_00244190` | Matching | 100.00% | 52 |
| `func_002441C8` | Matching | 100.00% | 48 |
| `func_002441F8` | Matching | 100.00% | 52 |
| `func_00244230` | Matching | 100.00% | 8 |
| `func_00244238` | Matching | 100.00% | 8 |
| `func_00244240` | Matching | 100.00% | 52 |
| `func_00244278` | Matching | 100.00% | 8 |
| `func_00244280` | Matching | 100.00% | 8 |
| `func_00244288` | Matching | 100.00% | 8 |
| `func_00244290` | Matching | 100.00% | 8 |
| `func_00244298` | Matching | 100.00% | 8 |
| `func_002442A0` | Matching | 100.00% | 8 |
| `func_002442A8` | Matching | 100.00% | 8 |
| `func_002442B0` | Matching | 100.00% | 8 |
| `func_002442B8` | Matching | 100.00% | 8 |
| `func_002442C0` | Matching | 100.00% | 8 |
| `func_002442C8` | Matching | 100.00% | 8 |
| `func_002442D0` | Matching | 100.00% | 8 |
| `func_002442D8` | Matching | 100.00% | 8 |
| `func_002442E0` | Matching | 100.00% | 8 |
| `func_002442E8` | Matching | 100.00% | 8 |
| `func_002442F0` | Matching | 100.00% | 8 |
| `func_002442F8` | Matching | 100.00% | 8 |
| `func_00244300` | Matching | 100.00% | 8 |
| `func_00244308` | Matching | 100.00% | 8 |
| `func_00244310` | Matching | 100.00% | 8 |
| `func_00244318` | Matching | 100.00% | 8 |
| `func_00244320` | Matching | 100.00% | 8 |
| `func_00244328` | Matching | 100.00% | 8 |
| `func_00244330` | Matching | 100.00% | 8 |
| `func_00244338` | Matching | 100.00% | 8 |
| `func_00244340` | Matching | 100.00% | 8 |
| `func_00244348` | Matching | 100.00% | 8 |
| `func_00244350` | Matching | 100.00% | 8 |
| `func_00244358` | Matching | 100.00% | 8 |
| `func_00244360` | Matching | 100.00% | 8 |
| `func_00244368` | Matching | 100.00% | 8 |
| `func_00244370` | Matching | 100.00% | 20 |
| `func_00244388` | Matching | 100.00% | 12 |
| `func_00244398` | Matching | 100.00% | 24 |
| `func_002443B0` | Matching | 100.00% | 12 |
| `func_002443C0` | Matching | 100.00% | 48 |
| `func_002443F0` | Matching | 100.00% | 8 |
| `func_002443F8(void*)` | Matching | 100.00% | 8 |
| `func_00244400(void*, int)` | Matching | 100.00% | 8 |
| `func_00244408(void*, int)` | Matching | 100.00% | 8 |
| `func_00244410` | Matching | 100.00% | 100 |
| `func_00244478` | Matching | 100.00% | 44 |
| `func_002444A8` | Matching | 100.00% | 44 |
| `func_002444D8` | Matching | 100.00% | 20 |
| `func_002444F0` | Matching | 100.00% | 48 |
| `func_00244520` | Matching | 100.00% | 8 |
| `func_00244528(void*)` | Matching | 100.00% | 8 |
| `func_00244530(void*)` | Matching | 100.00% | 8 |
| `func_00244538(void*)` | Matching | 100.00% | 8 |
| `func_00244540(void*)` | Matching | 100.00% | 8 |
| `func_00244548(void*)` | Matching | 100.00% | 8 |
| `func_00244550(void*)` | Matching | 100.00% | 8 |
| `func_00244558(void*)` | Matching | 100.00% | 8 |
| `func_00244560` | Matching | 100.00% | 48 |
| `func_00244590` | Matching | 100.00% | 48 |
| `func_002445C0` | Matching | 100.00% | 48 |
| `func_002445F0` | Matching | 100.00% | 48 |
| `func_00244620(void*)` | Matching | 100.00% | 8 |
| `func_00244628(void*)` | Matching | 100.00% | 8 |
| `func_00244630` | Matching | 100.00% | 48 |
| `func_00244660` | Matching | 100.00% | 48 |
| `func_00244690` | Matching | 100.00% | 48 |
| `func_002446C0` | Matching | 100.00% | 48 |
| `func_002446F0` | Matching | 100.00% | 48 |
| `func_00244720` | Matching | 100.00% | 48 |
| `func_00244750` | Matching | 100.00% | 8 |
| `func_00244758` | Matching | 100.00% | 8 |
| `func_00244760` | Matching | 100.00% | 8 |
| `func_00244768` | Matching | 100.00% | 8 |
| `func_00244770` | Matching | 100.00% | 32 |
| `func_00244790` | Matching | 100.00% | 28 |
| `func_002447B0` | Matching | 100.00% | 12 |
| `func_002447C0` | Matching | 100.00% | 8 |
| `func_002447C8` | Matching | 100.00% | 12 |
| `func_002447D8` | Matching | 100.00% | 20 |
| `func_002447F0` | Matching | 100.00% | 28 |
| `func_00244810` | Matching | 100.00% | 28 |
| `func_00244830` | Matching | 100.00% | 8 |
| `func_00244838` | Matching | 100.00% | 8 |
| `func_00244840` | Matching | 100.00% | 8 |
| `func_00244848` | Matching | 100.00% | 8 |
| `func_00244850` | Matching | 100.00% | 8 |
| `func_00244858` | Matching | 100.00% | 8 |
| `func_00244860(void*)` | Matching | 100.00% | 8 |
| `func_00244868(void*)` | Matching | 100.00% | 8 |
| `func_00244870(void*)` | Matching | 100.00% | 8 |
| `func_00244878(void*)` | Matching | 100.00% | 8 |
| `func_00244880(void*)` | Matching | 100.00% | 8 |
| `func_00244888` | Matching | 100.00% | 84 |
| `func_002448E0` | Matching | 100.00% | 100 |
| `func_00244948` | Matching | 100.00% | 44 |
| `func_00244978` | Matching | 100.00% | 44 |
| `func_002449A8` | Matching | 100.00% | 76 |
| `func_002449F8` | Matching | 100.00% | 28 |
| `func_00244A18` | Matching | 100.00% | 28 |
| `func_00244A38` | Matching | 100.00% | 8 |
| `func_00244A40` | Matching | 100.00% | 264 |
| `func_00244E60` | Matching | 100.00% | 692 |
| `func_00245118` | Matching | 100.00% | 36 |
| `func_00245140` | Matching | 100.00% | 36 |
| `func_00245168` | Matching | 100.00% | 68 |
| `func_002451B0` | Matching | 100.00% | 116 |
| `func_00245228(void*)` | Matching | 100.00% | 28 |
| `func_00245248` | Matching | 100.00% | 144 |
| `func_002452D8` | Matching | 100.00% | 264 |
| `func_002453E0` | Matching | 100.00% | 16 |
| `func_002453F0` | Matching | 100.00% | 40 |
| `func_00245418` | Matching | 100.00% | 224 |
| `func_002454F8` | Matching | 100.00% | 160 |
| `func_00245598` | Matching | 100.00% | 104 |
| `func_00245600` | Matching | 100.00% | 40 |
| `func_00245628` | Matching | 100.00% | 100 |
| `func_00245690(void*)` | Matching | 100.00% | 8 |
| `func_00245698` | Matching | 100.00% | 112 |
| `func_00245708` | Matching | 100.00% | 40 |
| `func_00245730` | Matching | 100.00% | 380 |
| `func_002458B0(void*)` | Matching | 100.00% | 8 |
| `func_002458B8` | Matching | 100.00% | 112 |
| `func_00245928` | Matching | 100.00% | 40 |

### `main/streampause`

10 matching, 0 partial, 0 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cStreamPause_construct()` | Matching | 100.00% | 60 |
| `func_00242D50` | Matching | 100.00% | 60 |
| `func_00242D90` | Matching | 100.00% | 104 |
| `func_00242DF8` | Matching | 100.00% | 96 |
| `func_00242E58` | Matching | 100.00% | 96 |
| `func_00243838` | Matching | 100.00% | 120 |
| `func_002438B0` | Matching | 100.00% | 48 |
| `func_002438E0` | Matching | 100.00% | 8 |
| `func_002438E8` | Matching | 100.00% | 8 |
| `func_00242EB8` | Matching | 99.98% | 2428 |

### `md5`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `md5_process` | Matching | 100.00% | 4116 |
| `md5_init(md5_ctx*)` | Matching | 100.00% | 60 |
| `md5_append` | Matching | 100.00% | 292 |
| `md5_finish` | Matching | 100.00% | 212 |

### `mem/memstd`

91 matching, 0 partial, 5 not started (96 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `MEMCLASS_create` | Matching | 100.00% | 636 |
| `func_00251998` | Matching | 100.00% | 112 |
| `func_00251A08` | Matching | 100.00% | 120 |
| `func_00251A80` | Matching | 100.00% | 64 |
| `func_00251AC0` | Matching | 100.00% | 144 |
| `func_00251C38` | Matching | 100.00% | 184 |
| `func_00251CF0` | Matching | 100.00% | 8 |
| `func_00251CF8` | Matching | 100.00% | 8 |
| `func_00251D00` | Matching | 100.00% | 8 |
| `func_00251D08` | Matching | 100.00% | 72 |
| `MEMCLASS_link` | Matching | 100.00% | 536 |
| `func_00251F68` | Matching | 100.00% | 92 |
| `MEM_printclass(void*)` | Matching | 100.00% | 40 |
| `MEM_print()` | Matching | 100.00% | 32 |
| `MEM_printclassf` | Matching | 100.00% | 564 |
| `func_00252248` | Matching | 100.00% | 104 |
| `func_002522B0` | Matching | 100.00% | 240 |
| `func_002523A0` | Matching | 100.00% | 8 |
| `func_002523A8` | Matching | 100.00% | 36 |
| `func_002523D0` | Matching | 100.00% | 552 |
| `func_002525F8` | Matching | 100.00% | 80 |
| `func_00252648` | Matching | 100.00% | 8 |
| `func_00252650` | Matching | 100.00% | 8 |
| `func_00252658(void*)` | Matching | 100.00% | 8 |
| `func_00252660` | Matching | 100.00% | 40 |
| `func_00252688` | Matching | 100.00% | 44 |
| `func_002526B8` | Matching | 100.00% | 96 |
| `func_00252718` | Matching | 100.00% | 580 |
| `func_00252960` | Matching | 100.00% | 32 |
| `func_00252980` | Matching | 100.00% | 144 |
| `func_00252F60(void*)` | Matching | 100.00% | 28 |
| `func_00252FA0` | Matching | 100.00% | 40 |
| `func_00252FF0` | Matching | 100.00% | 40 |
| `func_00253040` | Matching | 100.00% | 48 |
| `func_002530A0` | Matching | 100.00% | 48 |
| `func_00253100` | Matching | 100.00% | 108 |
| `func_00253170` | Matching | 100.00% | 188 |
| `func_00253230` | Matching | 100.00% | 128 |
| `func_002532B0` | Matching | 100.00% | 184 |
| `func_00253368` | Matching | 100.00% | 40 |
| `func_00253390` | Matching | 100.00% | 52 |
| `func_002533C8` | Matching | 100.00% | 76 |
| `func_00253418` | Matching | 100.00% | 68 |
| `func_00253460` | Matching | 100.00% | 72 |
| `func_002535F8` | Matching | 100.00% | 204 |
| `func_002536C8` | Matching | 100.00% | 128 |
| `func_00253748` | Matching | 100.00% | 276 |
| `func_00253860` | Matching | 100.00% | 44 |
| `func_00253890` | Matching | 100.00% | 164 |
| `func_00253938` | Matching | 100.00% | 168 |
| `func_002539E0` | Matching | 100.00% | 96 |
| `func_00253A40` | Matching | 100.00% | 92 |
| `func_00253AA0` | Matching | 100.00% | 44 |
| `func_00253AD0` | Matching | 100.00% | 40 |
| `func_00253AF8(void*)` | Matching | 100.00% | 28 |
| `func_00253B18` | Matching | 100.00% | 60 |
| `func_00254330(void*)` | Matching | 100.00% | 32 |
| `func_00254350` | Matching | 100.00% | 24 |
| `func_00254368` | Matching | 100.00% | 132 |
| `func_002543F0` | Matching | 100.00% | 16 |
| `func_00254400(void*, float, float)` | Matching | 100.00% | 12 |
| `func_002547B8` | Matching | 100.00% | 276 |
| `func_002548D0` | Matching | 100.00% | 884 |
| `func_00254C48` | Matching | 100.00% | 344 |
| `func_00254DA0(void*)` | Matching | 100.00% | 28 |
| `func_00254DC0` | Matching | 100.00% | 92 |
| `func_00254E20` | Matching | 100.00% | 60 |
| `func_00255638` | Matching | 100.00% | 48 |
| `func_00255668(void*)` | Matching | 100.00% | 8 |
| `func_00255670` | Matching | 100.00% | 60 |
| `func_002556B0` | Matching | 100.00% | 60 |
| `func_002556F0` | Matching | 100.00% | 44 |
| `func_00255720` | Matching | 100.00% | 44 |
| `func_00255750` | Matching | 100.00% | 36 |
| `func_00255778` | Matching | 100.00% | 36 |
| `func_002557A0` | Matching | 100.00% | 8 |
| `func_002557A8` | Matching | 100.00% | 8 |
| `func_002557B0` | Matching | 100.00% | 8 |
| `func_002557B8` | Matching | 100.00% | 8 |
| `func_002557C0(void*)` | Matching | 100.00% | 32 |
| `func_002557E0(void*)` | Matching | 100.00% | 28 |
| `func_00255800` | Matching | 100.00% | 48 |
| `func_00255830(void*)` | Matching | 100.00% | 16 |
| `func_00255840` | Matching | 100.00% | 28 |
| `func_00253B58` | Matching | 99.98% | 2008 |
| `func_00254E60` | Matching | 99.98% | 2008 |
| `func_00253070` | Matching | 99.58% | 48 |
| `func_002530D0` | Matching | 99.58% | 48 |
| `func_00252FC8` | Matching | 99.50% | 40 |
| `func_00253018` | Matching | 99.50% | 40 |
| `func_00252F80` | Matching | 99.29% | 28 |

### `movie/movieplayer`

124 matching, 0 partial, 3 not started (127 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cMCOverlayManager_getManager()` | Matching | 100.00% | 68 |
| `func_0023C850` | Matching | 100.00% | 12 |
| `func_0023C860` | Matching | 100.00% | 56 |
| `func_0023C898` | Matching | 100.00% | 16 |
| `func_0023C8A8` | Matching | 100.00% | 16 |
| `func_0023C8B8` | Matching | 100.00% | 8 |
| `func_0023C8C0` | Matching | 100.00% | 12 |
| `func_0023C8D0` | Matching | 100.00% | 28 |
| `func_0023C8F0` | Matching | 100.00% | 312 |
| `func_0023CA28` | Matching | 100.00% | 72 |
| `func_0023CA70` | Matching | 100.00% | 44 |
| `func_0023CAA0` | Matching | 100.00% | 72 |
| `func_0023CAE8` | Matching | 100.00% | 308 |
| `func_0023CC20` | Matching | 100.00% | 56 |
| `func_0023CC58(void*)` | Matching | 100.00% | 28 |
| `func_0023CC78` | Matching | 100.00% | 312 |
| `cMCOverlayManager_setTitleString` | Matching | 100.00% | 392 |
| `func_0023D5E8` | Matching | 100.00% | 44 |
| `func_0023D618` | Matching | 100.00% | 72 |
| `func_0023D660` | Matching | 100.00% | 324 |
| `func_0023D7A8` | Matching | 100.00% | 44 |
| `func_0023E268` | Matching | 100.00% | 88 |
| `func_0023E2C0(void*)` | Matching | 100.00% | 8 |
| `func_0023E2C8` | Matching | 100.00% | 88 |
| `func_0023E320` | Matching | 100.00% | 160 |
| `func_0023E3C0` | Matching | 100.00% | 104 |
| `func_0023E428` | Matching | 100.00% | 108 |
| `func_0023E498` | Matching | 100.00% | 88 |
| `func_0023E4F0(void*)` | Matching | 100.00% | 8 |
| `func_0023E4F8` | Matching | 100.00% | 68 |
| `func_0023E540` | Matching | 100.00% | 736 |
| `func_0023E820` | Matching | 100.00% | 128 |
| `func_0023E8A0` | Matching | 100.00% | 400 |
| `func_0023EA30` | Matching | 100.00% | 92 |
| `func_0023EA90` | Matching | 100.00% | 192 |
| `func_0023EB50` | Matching | 100.00% | 44 |
| `func_0023EB80` | Matching | 100.00% | 128 |
| `func_0023EC00` | Matching | 100.00% | 868 |
| `func_0023EF68` | Matching | 100.00% | 228 |
| `func_0023F050` | Matching | 100.00% | 168 |
| `func_0023F0F8` | Matching | 100.00% | 84 |
| `func_0023F150` | Matching | 100.00% | 136 |
| `func_0023F1D8` | Matching | 100.00% | 128 |
| `func_0023F258` | Matching | 100.00% | 124 |
| `func_0023F2D8` | Matching | 100.00% | 44 |
| `func_0023F308` | Matching | 100.00% | 152 |
| `func_0023F3A0` | Matching | 100.00% | 148 |
| `func_0023F438` | Matching | 100.00% | 188 |
| `func_0023F4F8` | Matching | 100.00% | 128 |
| `func_0023F578` | Matching | 100.00% | 284 |
| `func_0023FAE0` | Matching | 100.00% | 56 |
| `func_0023FB18(void*, int)` | Matching | 100.00% | 8 |
| `func_0023FB20` | Matching | 100.00% | 52 |
| `func_0023FB58` | Matching | 100.00% | 92 |
| `func_0023FBB8` | Matching | 100.00% | 184 |
| `func_0023FC70` | Matching | 100.00% | 152 |
| `func_0023FD08` | Matching | 100.00% | 52 |
| `func_0023FD40` | Matching | 100.00% | 304 |
| `func_0023FE70` | Matching | 100.00% | 144 |
| `func_0023FF00` | Matching | 100.00% | 192 |
| `func_0023FFC0` | Matching | 100.00% | 44 |
| `func_0023FFF0` | Matching | 100.00% | 192 |
| `func_002400B0` | Matching | 100.00% | 128 |
| `func_00240130` | Matching | 100.00% | 412 |
| `func_002402D0` | Matching | 100.00% | 768 |
| `func_002405D0` | Matching | 100.00% | 184 |
| `func_00240688` | Matching | 100.00% | 220 |
| `func_00240768` | Matching | 100.00% | 148 |
| `func_00240800` | Matching | 100.00% | 92 |
| `func_00240860` | Matching | 100.00% | 256 |
| `func_00240960` | Matching | 100.00% | 104 |
| `func_002409C8` | Matching | 100.00% | 232 |
| `func_00240AB0` | Matching | 100.00% | 216 |
| `func_00240B88` | Matching | 100.00% | 168 |
| `func_00240C30` | Matching | 100.00% | 92 |
| `func_00240C90` | Matching | 100.00% | 44 |
| `func_00240CC0` | Matching | 100.00% | 208 |
| `func_00240D90` | Matching | 100.00% | 284 |
| `func_00240EB0` | Matching | 100.00% | 44 |
| `func_00240EE0` | Matching | 100.00% | 44 |
| `func_00240F10(void*)` | Matching | 100.00% | 28 |
| `func_00240F30` | Matching | 100.00% | 124 |
| `func_00240FB0` | Matching | 100.00% | 80 |
| `func_00241000` | Matching | 100.00% | 80 |
| `func_00241050` | Matching | 100.00% | 80 |
| `func_002410A0` | Matching | 100.00% | 44 |
| `func_002410D0` | Matching | 100.00% | 104 |
| `func_00241138` | Matching | 100.00% | 68 |
| `func_00241180` | Matching | 100.00% | 124 |
| `func_00241200` | Matching | 100.00% | 60 |
| `func_00241240` | Matching | 100.00% | 92 |
| `func_002412A0` | Matching | 100.00% | 224 |
| `func_00241380` | Matching | 100.00% | 128 |
| `func_00241400` | Matching | 100.00% | 320 |
| `func_00241540` | Matching | 100.00% | 308 |
| `func_00241678` | Matching | 100.00% | 72 |
| `func_002416C0` | Matching | 100.00% | 76 |
| `cMCOverlayManager_GetDeviceDisplayString` | Matching | 100.00% | 532 |
| `func_00241928` | Matching | 100.00% | 172 |
| `func_002419D8` | Matching | 100.00% | 20 |
| `cMCOverlayManager_GetDeviceTotalString` | Matching | 100.00% | 172 |
| `func_00241AA0` | Matching | 100.00% | 32 |
| `func_00241AC0` | Matching | 100.00% | 92 |
| `func_00241B20` | Matching | 100.00% | 436 |
| `func_00241CD8` | Matching | 100.00% | 100 |
| `func_00241D40` | Matching | 100.00% | 128 |
| `func_00241DC0` | Matching | 100.00% | 8 |
| `func_00241DC8` | Matching | 100.00% | 76 |
| `func_00241E18` | Matching | 100.00% | 404 |
| `func_00241FB0(void*)` | Matching | 100.00% | 28 |
| `func_00241FD0` | Matching | 100.00% | 124 |
| `func_00242050` | Matching | 100.00% | 116 |
| `func_002420C8` | Matching | 100.00% | 444 |
| `func_002424C8` | Matching | 100.00% | 52 |
| `func_00242500(void*)` | Matching | 100.00% | 24 |
| `func_00242518` | Matching | 100.00% | 36 |
| `func_00242540` | Matching | 100.00% | 44 |
| `func_00242570` | Matching | 100.00% | 76 |
| `func_002425C0` | Matching | 100.00% | 952 |
| `func_00242978` | Matching | 100.00% | 56 |
| `func_002429B0` | Matching | 100.00% | 860 |
| `func_0023F698` | Matching | 99.98% | 1092 |
| `func_0023D5A8` | Matching | 99.69% | 64 |
| `func_0023D570` | Matching | 99.62% | 52 |

### `object/animnode`

9 matching, 0 partial, 0 not started (9 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAnimNode_setAnimMeshCache` | Matching | 100.00% | 440 |
| `func_0034E600` | Matching | 100.00% | 148 |
| `func_0034E698` | Matching | 100.00% | 252 |
| `func_0034E798` | Matching | 100.00% | 1032 |
| `func_0034EBA0` | Matching | 100.00% | 60 |
| `func_0034EBE0` | Matching | 100.00% | 116 |
| `func_0034EC58` | Matching | 100.00% | 304 |
| `func_0034ED88` | Matching | 100.00% | 220 |
| `func_0034EE68` | Matching | 100.00% | 80 |

### `object/bucketman`

19 matching, 0 partial, 0 not started (19 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBucketMan_init` | Matching | 100.00% | 344 |
| `func_00354B38` | Matching | 100.00% | 204 |
| `cBucketMan_add` | Matching | 100.00% | 140 |
| `func_00354C98` | Matching | 100.00% | 428 |
| `func_00354E48` | Matching | 100.00% | 48 |
| `func_00354E78` | Matching | 100.00% | 44 |
| `cBucketMan_first(cBucketMan*, int)` | Matching | 100.00% | 36 |
| `func_00354ED0` | Matching | 100.00% | 36 |
| `cBucketMan_next(cBucketMan*, void*, int)` | Matching | 100.00% | 36 |
| `func_00354F20` | Matching | 100.00% | 36 |
| `cBucketMan_addfirst(cBucketMan*, int)` | Matching | 100.00% | 36 |
| `func_00354F70` | Matching | 100.00% | 36 |
| `func_00354F98` | Matching | 100.00% | 144 |
| `func_00355028` | Matching | 100.00% | 116 |
| `func_003550A0` | Matching | 100.00% | 116 |
| `cBucketMan_purgeBucket` | Matching | 100.00% | 140 |
| `func_003551A8` | Matching | 100.00% | 180 |
| `func_00355260` | Matching | 100.00% | 32 |
| `func_00355280` | Matching | 100.00% | 88 |

### `object/deadfadenode`

12 matching, 0 partial, 1 not started (13 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00350B98` | Matching | 100.00% | 68 |
| `func_00350BE0` | Matching | 100.00% | 84 |
| `func_00350C38` | Matching | 100.00% | 88 |
| `func_00350C90` | Matching | 100.00% | 36 |
| `func_00350CB8` | Matching | 100.00% | 436 |
| `func_00350E70(void*)` | Matching | 100.00% | 28 |
| `func_00350E90` | Matching | 100.00% | 116 |
| `func_00350F08` | Matching | 100.00% | 52 |
| `func_00350F40(void*)` | Matching | 100.00% | 28 |
| `func_00350F60` | Matching | 100.00% | 116 |
| `func_00350FD8` | Matching | 100.00% | 52 |
| `func_00351010(void*)` | Matching | 100.00% | 28 |

### `object/debouncenode`

38 matching, 0 partial, 6 not started (44 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cDebounceNode_cDebounceNode` | Matching | 100.00% | 120 |
| `func_00342D88` | Matching | 100.00% | 80 |
| `func_00342DD8` | Matching | 100.00% | 160 |
| `func_00342E78(void*)` | Matching | 100.00% | 28 |
| `func_00342E98` | Matching | 100.00% | 272 |
| `func_00342FA8` | Matching | 100.00% | 104 |
| `func_00343010` | Matching | 100.00% | 192 |
| `func_003430D0` | Matching | 100.00% | 92 |
| `func_003434E8` | Matching | 100.00% | 160 |
| `func_00343588` | Matching | 100.00% | 400 |
| `func_00343718` | Matching | 100.00% | 76 |
| `func_00343768` | Matching | 100.00% | 84 |
| `func_003437C0` | Matching | 100.00% | 92 |
| `func_00343820` | Matching | 100.00% | 68 |
| `func_00343868` | Matching | 100.00% | 432 |
| `func_00343A18` | Matching | 100.00% | 76 |
| `func_00343A68` | Matching | 100.00% | 192 |
| `func_00343B28` | Matching | 100.00% | 148 |
| `func_00343BC0` | Matching | 100.00% | 72 |
| `func_00343C08` | Matching | 100.00% | 88 |
| `func_003440C8` | Matching | 100.00% | 112 |
| `func_00344138` | Matching | 100.00% | 112 |
| `func_003441A8` | Matching | 100.00% | 152 |
| `func_00344240` | Matching | 100.00% | 160 |
| `func_003442E0` | Matching | 100.00% | 100 |
| `func_00344348(void*)` | Matching | 100.00% | 28 |
| `func_00344368` | Matching | 100.00% | 64 |
| `func_00344730` | Matching | 100.00% | 204 |
| `func_00344800` | Matching | 100.00% | 152 |
| `func_003449F0` | Matching | 100.00% | 172 |
| `func_00344E18` | Matching | 100.00% | 424 |
| `func_00344FC0` | Matching | 100.00% | 52 |
| `func_00344FF8` | Matching | 100.00% | 80 |
| `func_00345048` | Matching | 100.00% | 372 |
| `func_003451C0` | Matching | 100.00% | 132 |
| `func_00345248` | Matching | 100.00% | 216 |
| `func_00345320` | Matching | 100.00% | 268 |
| `func_00345430` | Matching | 100.00% | 180 |

### `object/effectlink`

30 matching, 0 partial, 0 not started (30 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cEffectLink_add(cEffectLink *, cEffectLink *)` | Matching | 100.00% | 32 |
| `func_00345720` | Matching | 100.00% | 60 |
| `func_00345760` | Matching | 100.00% | 52 |
| `func_00345798` | Matching | 100.00% | 44 |
| `func_003457C8` | Matching | 100.00% | 92 |
| `func_00345828` | Matching | 100.00% | 104 |
| `func_00345890` | Matching | 100.00% | 48 |
| `func_003458C0` | Matching | 100.00% | 228 |
| `func_003459A8` | Matching | 100.00% | 296 |
| `func_00345AD0` | Matching | 100.00% | 108 |
| `func_00345B40` | Matching | 100.00% | 132 |
| `func_00345BC8` | Matching | 100.00% | 40 |
| `func_00345BF0` | Matching | 100.00% | 156 |
| `func_00345C90` | Matching | 100.00% | 236 |
| `func_00345D80` | Matching | 100.00% | 264 |
| `func_00345E88` | Matching | 100.00% | 108 |
| `func_00345EF8` | Matching | 100.00% | 152 |
| `func_00345F90` | Matching | 100.00% | 208 |
| `func_00346060(void*)` | Matching | 100.00% | 12 |
| `func_00346070` | Matching | 100.00% | 44 |
| `func_003460A0` | Matching | 100.00% | 128 |
| `func_00346120` | Matching | 100.00% | 156 |
| `func_003461C0` | Matching | 100.00% | 104 |
| `func_00346228` | Matching | 100.00% | 48 |
| `func_00346258` | Matching | 100.00% | 72 |
| `func_003462A0` | Matching | 100.00% | 92 |
| `func_00346300` | Matching | 100.00% | 76 |
| `func_00346350` | Matching | 100.00% | 396 |
| `func_003464E0` | Matching | 100.00% | 132 |
| `func_00346568` | Matching | 100.00% | 312 |

### `object/flagset`

33 matching, 0 partial, 3 not started (36 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFlagSet_CreateMesh` | Matching | 100.00% | 1424 |
| `func_0034B7B8` | Matching | 100.00% | 92 |
| `func_0034B818` | Matching | 100.00% | 408 |
| `func_0034B9B0` | Matching | 100.00% | 748 |
| `func_0034C2E0` | Matching | 100.00% | 152 |
| `func_0034C378` | Matching | 100.00% | 172 |
| `func_0034C428` | Matching | 100.00% | 140 |
| `func_0034C4B8` | Matching | 100.00% | 144 |
| `func_0034C548` | Matching | 100.00% | 180 |
| `func_0034C600` | Matching | 100.00% | 100 |
| `func_0034C7F8` | Matching | 100.00% | 76 |
| `func_0034C848` | Matching | 100.00% | 80 |
| `func_0034C898` | Matching | 100.00% | 80 |
| `func_0034CAB8` | Matching | 100.00% | 196 |
| `func_0034CB80` | Matching | 100.00% | 104 |
| `func_0034CBE8` | Matching | 100.00% | 148 |
| `func_0034CDE8` | Matching | 100.00% | 92 |
| `func_0034CF98` | Matching | 100.00% | 588 |
| `func_0034D778` | Matching | 100.00% | 484 |
| `func_0034D960` | Matching | 100.00% | 76 |
| `func_0034DAC8` | Matching | 100.00% | 220 |
| `func_0034DBA8` | Matching | 100.00% | 228 |
| `func_0034DC90` | Matching | 100.00% | 132 |
| `func_0034E320` | Matching | 100.00% | 40 |
| `func_0034E348` | Matching | 100.00% | 140 |
| `func_0034E3D8` | Matching | 100.00% | 108 |
| `func_0034D1E8` | Matching | 99.98% | 1124 |
| `func_0034D9B0` | Matching | 99.93% | 276 |
| `func_0034CC80` | Matching | 99.89% | 356 |
| `func_0034D650` | Matching | 99.87% | 156 |
| `func_0034C668` | Matching | 99.85% | 396 |
| `func_0034CE48` | Matching | 99.82% | 332 |
| `func_0034D6F0` | Matching | 99.55% | 132 |

### `object/flexbridgenode`

13 matching, 0 partial, 4 not started (17 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFlexBridgeNode_setupGrid` | Matching | 100.00% | 1684 |
| `func_00346D38` | Matching | 100.00% | 252 |
| `func_003470D0` | Matching | 100.00% | 404 |
| `func_003475A8` | Matching | 100.00% | 48 |
| `func_00347B80` | Matching | 100.00% | 440 |
| `func_00347D38` | Matching | 100.00% | 88 |
| `func_00347D90` | Matching | 100.00% | 280 |
| `func_00347EA8` | Matching | 100.00% | 232 |
| `func_00347F90` | Matching | 100.00% | 116 |
| `func_00348008` | Matching | 100.00% | 80 |
| `func_00348058` | Matching | 100.00% | 112 |
| `func_00348B40` | Matching | 100.00% | 76 |
| `func_003480C8` | Matching | 99.61% | 456 |

### `object/flexrailnode`

31 matching, 0 partial, 3 not started (34 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFlexRailNode_addSpaceHash` | Matching | 100.00% | 180 |
| `func_00348C48` | Matching | 100.00% | 332 |
| `func_00348D98` | Matching | 100.00% | 516 |
| `func_00348FA0` | Matching | 100.00% | 272 |
| `func_003490B0` | Matching | 100.00% | 92 |
| `func_00349110` | Matching | 100.00% | 268 |
| `func_00349220` | Matching | 100.00% | 136 |
| `func_00349798` | Matching | 100.00% | 168 |
| `func_00349840` | Matching | 100.00% | 168 |
| `func_003498E8` | Matching | 100.00% | 488 |
| `func_00349AD0` | Matching | 100.00% | 116 |
| `func_00349B48` | Matching | 100.00% | 616 |
| `func_00349DB0` | Matching | 100.00% | 264 |
| `func_00349EB8` | Matching | 100.00% | 92 |
| `func_00349F18` | Matching | 100.00% | 268 |
| `func_0034A028` | Matching | 100.00% | 132 |
| `func_0034A568` | Matching | 100.00% | 720 |
| `func_0034A8C8` | Matching | 100.00% | 836 |
| `func_0034AC10` | Matching | 100.00% | 116 |
| `func_0034AC88` | Matching | 100.00% | 332 |
| `func_0034ADD8` | Matching | 100.00% | 144 |
| `func_0034AE68` | Matching | 100.00% | 52 |
| `func_0034AEA0` | Matching | 100.00% | 84 |
| `func_0034AEF8(void*)` | Matching | 100.00% | 28 |
| `func_0034AF18(void*)` | Matching | 100.00% | 8 |
| `func_0034AF20` | Matching | 100.00% | 24 |
| `func_0034AF38` | Matching | 100.00% | 124 |
| `func_0034AFB8` | Matching | 100.00% | 48 |
| `func_0034AFE8` | Matching | 100.00% | 76 |
| `func_0034B038` | Matching | 100.00% | 304 |
| `func_0034B168` | Matching | 100.00% | 188 |

### `object/floatingnode`

7 matching, 0 partial, 3 not started (10 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFloatingNode_initInfo(cFloatingNode*)` | Matching | 100.00% | 76 |
| `func_0034EF08` | Matching | 100.00% | 56 |
| `func_0034EF40` | Matching | 100.00% | 260 |
| `func_0034F048` | Matching | 100.00% | 216 |
| `func_0034F930` | Matching | 100.00% | 340 |
| `func_0034FA88` | Matching | 100.00% | 116 |
| `func_0034FB00` | Matching | 100.00% | 144 |

### `object/instanceman`

24 matching, 0 partial, 1 not started (25 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cInstanceMan_copyInstance(void *, sInstanceStruct *, void *)` | Matching | 100.00% | 76 |
| `func_003512C0` | Matching | 100.00% | 112 |
| `func_00351330` | Matching | 100.00% | 100 |
| `func_00351398` | Matching | 100.00% | 56 |
| `func_003513D0` | Matching | 100.00% | 64 |
| `func_00351410` | Matching | 100.00% | 52 |
| `func_00351448` | Matching | 100.00% | 52 |
| `func_00351480` | Matching | 100.00% | 136 |
| `func_00351508` | Matching | 100.00% | 48 |
| `func_00351538` | Matching | 100.00% | 296 |
| `func_00351660` | Matching | 100.00% | 416 |
| `func_00351800` | Matching | 100.00% | 324 |
| `func_00351948` | Matching | 100.00% | 196 |
| `func_00351A10` | Matching | 100.00% | 76 |
| `func_00351A60(void*)` | Matching | 100.00% | 28 |
| `func_00351A80` | Matching | 100.00% | 192 |
| `func_00351B40` | Matching | 100.00% | 1576 |
| `func_00352168` | Matching | 100.00% | 160 |
| `func_00352208(void*)` | Matching | 100.00% | 40 |
| `func_00352230` | Matching | 100.00% | 716 |
| `func_00352500` | Matching | 100.00% | 516 |
| `func_00352708` | Matching | 100.00% | 116 |
| `func_00352780` | Matching | 100.00% | 140 |
| `func_00352A58` | Matching | 100.00% | 76 |

### `object/instancenode`

16 matching, 0 partial, 1 not started (17 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cInstanceNode_cInstanceNode` | Matching | 100.00% | 92 |
| `func_0034FBF0` | Matching | 100.00% | 136 |
| `func_0034FC78` | Matching | 100.00% | 8 |
| `func_0034FC80` | Matching | 100.00% | 28 |
| `func_0034FCA0` | Matching | 100.00% | 28 |
| `func_0034FCC0(void*)` | Matching | 100.00% | 28 |
| `func_0034FCE0(void*)` | Matching | 100.00% | 28 |
| `func_0034FD00` | Matching | 100.00% | 140 |
| `func_0034FD90` | Matching | 100.00% | 108 |
| `func_0034FE00(void*, int, int, int)` | Matching | 100.00% | 36 |
| `func_0034FE28` | Matching | 100.00% | 100 |
| `func_0034FE90` | Matching | 100.00% | 72 |
| `func_00350288` | Matching | 100.00% | 740 |
| `cInstanceNode_getBoundBoxInfo` | Matching | 100.00% | 296 |
| `func_00350698` | Matching | 100.00% | 64 |
| `func_003506D8` | Matching | 100.00% | 116 |

### `object/modifierblock`

37 matching, 0 partial, 0 not started (37 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `tModifierBlock_tModifierBlock(tModifierBlock*)` | Matching | 100.00% | 64 |
| `func_00352AE8` | Matching | 100.00% | 156 |
| `func_00352B88` | Matching | 100.00% | 56 |
| `tModifierBlock_setBoundBox(tModifierBlock*)` | Matching | 100.00% | 52 |
| `func_00352BF8` | Matching | 100.00% | 60 |
| `tModifierBlock_setRadius(tModifierBlock*)` | Matching | 100.00% | 52 |
| `func_00352C70` | Matching | 100.00% | 176 |
| `func_00352D20` | Matching | 100.00% | 172 |
| `func_00352DD0` | Matching | 100.00% | 124 |
| `func_00352E50` | Matching | 100.00% | 68 |
| `func_00352E98` | Matching | 100.00% | 52 |
| `func_00352ED0` | Matching | 100.00% | 56 |
| `func_00352F08` | Matching | 100.00% | 52 |
| `func_00352F40` | Matching | 100.00% | 224 |
| `func_00353020` | Matching | 100.00% | 116 |
| `func_00353098` | Matching | 100.00% | 52 |
| `func_003530D0` | Matching | 100.00% | 68 |
| `func_00353118` | Matching | 100.00% | 56 |
| `func_00353150` | Matching | 100.00% | 56 |
| `func_00353188` | Matching | 100.00% | 68 |
| `func_003531D0` | Matching | 100.00% | 88 |
| `func_00353228` | Matching | 100.00% | 80 |
| `func_00353278` | Matching | 100.00% | 132 |
| `func_00353300` | Matching | 100.00% | 148 |
| `func_00353398` | Matching | 100.00% | 128 |
| `func_00353418` | Matching | 100.00% | 48 |
| `func_00353448` | Matching | 100.00% | 652 |
| `tModifierBlock_readFromReplayFrame` | Matching | 100.00% | 996 |
| `func_00353AC0(void*)` | Matching | 100.00% | 40 |
| `func_00353AE8(void*)` | Matching | 100.00% | 40 |
| `func_00353B10` | Matching | 100.00% | 480 |
| `func_00353CF0` | Matching | 100.00% | 164 |
| `func_00353D98(void*)` | Matching | 100.00% | 16 |
| `func_00353DA8(void*)` | Matching | 100.00% | 12 |
| `func_00353DB8` | Matching | 100.00% | 80 |
| `func_00353E08` | Matching | 100.00% | 120 |
| `func_00353E80` | Matching | 100.00% | 124 |

### `object/movenode`

95 matching, 0 partial, 1 not started (96 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cMoveNode_cMoveNode` | Matching | 100.00% | 232 |
| `func_003553C0` | Matching | 100.00% | 92 |
| `func_00355420` | Matching | 100.00% | 72 |
| `cMoveNode_addModifierBlock(cMoveNode*)` | Matching | 100.00% | 68 |
| `func_003554B0` | Matching | 100.00% | 156 |
| `func_00355550` | Matching | 100.00% | 84 |
| `func_003555A8` | Matching | 100.00% | 84 |
| `func_00355600` | Matching | 100.00% | 84 |
| `cMoveNode_addEffectModifier(cMoveNode*, void*)` | Matching | 100.00% | 76 |
| `func_003556A8` | Matching | 100.00% | 76 |
| `func_003556F8` | Matching | 100.00% | 80 |
| `func_00355748` | Matching | 100.00% | 40 |
| `func_00355770` | Matching | 100.00% | 232 |
| `func_00355858` | Matching | 100.00% | 32 |
| `func_00355878(void *, void *)` | Matching | 100.00% | 12 |
| `func_00355888` | Matching | 100.00% | 44 |
| `func_003558B8` | Matching | 100.00% | 92 |
| `func_00355918` | Matching | 100.00% | 92 |
| `func_00355978` | Matching | 100.00% | 124 |
| `func_003559F8` | Matching | 100.00% | 128 |
| `func_00355A78` | Matching | 100.00% | 88 |
| `func_00355AD0` | Matching | 100.00% | 92 |
| `cMoveNode_addSpline` | Matching | 100.00% | 96 |
| `func_00355B90` | Matching | 100.00% | 92 |
| `func_00355BF0` | Matching | 100.00% | 96 |
| `func_00355C50` | Matching | 100.00% | 96 |
| `cMoveNode_addParticle` | Matching | 100.00% | 96 |
| `cMoveNode_addDynamicParticle` | Matching | 100.00% | 168 |
| `func_00355DB8` | Matching | 100.00% | 124 |
| `func_00355E38` | Matching | 100.00% | 120 |
| `cMoveNode_addHalo` | Matching | 100.00% | 96 |
| `func_00355F10` | Matching | 100.00% | 268 |
| `func_00356020` | Matching | 100.00% | 88 |
| `func_00356078` | Matching | 100.00% | 72 |
| `func_003560C0` | Matching | 100.00% | 104 |
| `func_00356128` | Matching | 100.00% | 112 |
| `func_00356198` | Matching | 100.00% | 252 |
| `func_00356298` | Matching | 100.00% | 876 |
| `func_00356608` | Matching | 100.00% | 372 |
| `cMoveNode_setupOverlapSystem` | Matching | 100.00% | 92 |
| `func_003567E0` | Matching | 100.00% | 204 |
| `func_003568B0` | Matching | 100.00% | 288 |
| `func_003569D0` | Matching | 100.00% | 44 |
| `func_00356A00` | Matching | 100.00% | 40 |
| `func_00356A28` | Matching | 100.00% | 72 |
| `func_00356A70` | Matching | 100.00% | 72 |
| `func_00356AB8` | Matching | 100.00% | 40 |
| `func_00356AE0` | Matching | 100.00% | 40 |
| `func_00356B08` | Matching | 100.00% | 40 |
| `func_00356B30` | Matching | 100.00% | 192 |
| `func_00356BF0` | Matching | 100.00% | 84 |
| `func_00356C48` | Matching | 100.00% | 124 |
| `func_00356CC8` | Matching | 100.00% | 124 |
| `func_00356D48` | Matching | 100.00% | 100 |
| `func_00356DB0` | Matching | 100.00% | 176 |
| `func_00356E60` | Matching | 100.00% | 52 |
| `func_00356E98(void*)` | Matching | 100.00% | 28 |
| `func_00356EB8` | Matching | 100.00% | 88 |
| `func_00356F10` | Matching | 100.00% | 84 |
| `func_00356F68` | Matching | 100.00% | 132 |
| `func_00356FF0` | Matching | 100.00% | 16 |
| `func_00357000` | Matching | 100.00% | 52 |
| `func_00357038` | Matching | 100.00% | 88 |
| `func_00357090` | Matching | 100.00% | 116 |
| `func_00357108` | Matching | 100.00% | 260 |
| `func_00357210` | Matching | 100.00% | 100 |
| `func_00357278` | Matching | 100.00% | 100 |
| `func_003572E0` | Matching | 100.00% | 120 |
| `func_00357358` | Matching | 100.00% | 160 |
| `func_003573F8` | Matching | 100.00% | 304 |
| `func_00357528` | Matching | 100.00% | 16 |
| `func_00357660` | Matching | 100.00% | 108 |
| `func_003576D0` | Matching | 100.00% | 124 |
| `func_00357750` | Matching | 100.00% | 72 |
| `func_00357798` | Matching | 100.00% | 136 |
| `func_00357820` | Matching | 100.00% | 36 |
| `func_00357848` | Matching | 100.00% | 96 |
| `func_003578A8` | Matching | 100.00% | 112 |
| `func_00357918` | Matching | 100.00% | 52 |
| `func_00357950` | Matching | 100.00% | 88 |
| `func_003579A8(void*)` | Matching | 100.00% | 28 |
| `func_003579C8` | Matching | 100.00% | 52 |
| `func_00357A00` | Matching | 100.00% | 120 |
| `func_00357A78` | Matching | 100.00% | 112 |
| `func_00357AE8(void*, int, int)` | Matching | 100.00% | 40 |
| `func_00357B10(void*, int, int)` | Matching | 100.00% | 40 |
| `func_00357B38` | Matching | 100.00% | 84 |
| `func_00357B90` | Matching | 100.00% | 100 |
| `func_00357BF8` | Matching | 100.00% | 84 |
| `func_00357C50` | Matching | 100.00% | 84 |
| `func_00357CA8` | Matching | 100.00% | 128 |
| `func_00357D28` | Matching | 100.00% | 172 |
| `func_00357DD8` | Matching | 100.00% | 164 |
| `func_00357E80` | Matching | 100.00% | 284 |
| `func_00357FA0` | Matching | 100.00% | 124 |

### `object/multiparticle`

32 matching, 0 partial, 1 not started (33 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cMultiParticle_setupMultiParticle` | Matching | 100.00% | 252 |
| `func_00358120` | Matching | 100.00% | 32 |
| `func_00358140` | Matching | 100.00% | 116 |
| `func_003581B8` | Matching | 100.00% | 52 |
| `func_003581F0` | Matching | 100.00% | 112 |
| `func_00358260` | Matching | 100.00% | 288 |
| `func_00358380` | Matching | 100.00% | 232 |
| `func_00358468` | Matching | 100.00% | 80 |
| `func_003584B8` | Matching | 100.00% | 52 |
| `func_003584F0` | Matching | 100.00% | 152 |
| `func_00358588` | Matching | 100.00% | 220 |
| `func_00358668` | Matching | 100.00% | 148 |
| `func_00358700` | Matching | 100.00% | 128 |
| `func_00358780` | Matching | 100.00% | 532 |
| `func_00358998` | Matching | 100.00% | 396 |
| `func_00358B28` | Matching | 100.00% | 260 |
| `func_00358C30` | Matching | 100.00% | 76 |
| `func_00358DB0` | Matching | 100.00% | 160 |
| `func_00358E50` | Matching | 100.00% | 104 |
| `func_00358F90` | Matching | 100.00% | 64 |
| `func_00358FD0` | Matching | 100.00% | 92 |
| `func_00359030` | Matching | 100.00% | 148 |
| `func_003590C8` | Matching | 100.00% | 40 |
| `func_003590F0` | Matching | 100.00% | 80 |
| `func_00359140` | Matching | 100.00% | 228 |
| `func_00359228` | Matching | 100.00% | 72 |
| `func_00359270` | Matching | 100.00% | 92 |
| `func_00359410` | Matching | 100.00% | 76 |
| `func_00359460` | Matching | 99.95% | 376 |
| `func_003592D0` | Matching | 99.92% | 252 |
| `func_00358EB8` | Matching | 99.91% | 212 |
| `func_003593D0` | Matching | 99.67% | 60 |

### `object/objnode`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cObjNode_cObjNode(cObjNode*, void*)` | Matching | 100.00% | 64 |
| `func_003546C8` | Matching | 100.00% | 88 |
| `func_00354720` | Matching | 100.00% | 104 |
| `cTypeObjNode_cTypeObjNode` | Matching | 100.00% | 124 |
| `func_00354808` | Matching | 100.00% | 68 |
| `func_00354850` | Matching | 100.00% | 112 |
| `cSortObjNode_cSortObjNode` | Matching | 100.00% | 92 |
| `func_00354920(void*)` | Matching | 100.00% | 40 |
| `func_00354948` | Matching | 100.00% | 52 |
| `func_00354980` | Matching | 100.00% | 76 |
| `func_003549D0(void*)` | Matching | 100.00% | 16 |

### `object/railmodifier`

354 matching, 0 partial, 15 not started (369 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cRailModifier_buildXform` | Matching | 100.00% | 1016 |
| `func_0035C4E0` | Matching | 100.00% | 96 |
| `func_0035C540` | Matching | 100.00% | 96 |
| `func_0035C5A0` | Matching | 100.00% | 244 |
| `func_0035CFE0(void*)` | Matching | 100.00% | 8 |
| `func_0035CFE8(void*)` | Matching | 100.00% | 8 |
| `func_0035CFF0` | Matching | 100.00% | 660 |
| `func_0035D288` | Matching | 100.00% | 184 |
| `func_0035DA00` | Matching | 100.00% | 52 |
| `func_0035DA38` | Matching | 100.00% | 52 |
| `func_0035E1E0` | Matching | 100.00% | 104 |
| `func_0035E770` | Matching | 100.00% | 220 |
| `func_0035ED88(void*)` | Matching | 100.00% | 8 |
| `func_0035ED90` | Matching | 100.00% | 56 |
| `func_0035F0B8` | Matching | 100.00% | 240 |
| `func_0035F1A8` | Matching | 100.00% | 108 |
| `func_0035F378` | Matching | 100.00% | 48 |
| `func_0035F3A8` | Matching | 100.00% | 104 |
| `func_0035F410` | Matching | 100.00% | 392 |
| `func_0035F598` | Matching | 100.00% | 236 |
| `func_0035F688` | Matching | 100.00% | 96 |
| `func_0035F6E8` | Matching | 100.00% | 160 |
| `func_0035F788` | Matching | 100.00% | 68 |
| `func_0035FB30` | Matching | 100.00% | 240 |
| `func_0035FC20` | Matching | 100.00% | 372 |
| `func_0035FD98` | Matching | 100.00% | 52 |
| `func_0035FDD0` | Matching | 100.00% | 60 |
| `func_00360700` | Matching | 100.00% | 28 |
| `func_00360720(void*)` | Matching | 100.00% | 8 |
| `func_00360728(void*)` | Matching | 100.00% | 8 |
| `func_00360730(void*)` | Matching | 100.00% | 8 |
| `func_00360738(void*)` | Matching | 100.00% | 8 |
| `func_00360740(void*)` | Matching | 100.00% | 8 |
| `func_00360748(void*)` | Matching | 100.00% | 8 |
| `func_00360750(void*)` | Matching | 100.00% | 8 |
| `func_00360758(void*)` | Matching | 100.00% | 8 |
| `func_00360760(void*)` | Matching | 100.00% | 8 |
| `func_00360768` | Matching | 100.00% | 12 |
| `func_00360778(void*)` | Matching | 100.00% | 8 |
| `func_00360780(void*)` | Matching | 100.00% | 8 |
| `func_00360788(void*)` | Matching | 100.00% | 8 |
| `func_00360790(void*)` | Matching | 100.00% | 8 |
| `func_00360798(void*)` | Matching | 100.00% | 8 |
| `func_003607A0` | Matching | 100.00% | 16 |
| `func_003607B0` | Matching | 100.00% | 8 |
| `func_003607B8` | Matching | 100.00% | 16 |
| `func_003607C8` | Matching | 100.00% | 12 |
| `func_003607D8` | Matching | 100.00% | 16 |
| `func_003607E8` | Matching | 100.00% | 24 |
| `func_00360800` | Matching | 100.00% | 64 |
| `func_00360840` | Matching | 100.00% | 64 |
| `func_00360880(void*)` | Matching | 100.00% | 8 |
| `func_00360888` | Matching | 100.00% | 16 |
| `func_00360898` | Matching | 100.00% | 20 |
| `func_003608B0` | Matching | 100.00% | 20 |
| `func_003608C8` | Matching | 100.00% | 8 |
| `func_003608D0` | Matching | 100.00% | 8 |
| `func_003608D8` | Matching | 100.00% | 8 |
| `func_003608E0` | Matching | 100.00% | 8 |
| `func_003608E8` | Matching | 100.00% | 40 |
| `func_00360910(void*)` | Matching | 100.00% | 8 |
| `func_00360918(void*)` | Matching | 100.00% | 8 |
| `func_00360920(void*)` | Matching | 100.00% | 12 |
| `func_00360930(void*)` | Matching | 100.00% | 8 |
| `func_00360938(void*)` | Matching | 100.00% | 8 |
| `func_00360940(void*)` | Matching | 100.00% | 8 |
| `func_00360948(void*)` | Matching | 100.00% | 8 |
| `func_00360950(void*)` | Matching | 100.00% | 8 |
| `func_00360958(void*)` | Matching | 100.00% | 8 |
| `func_00360960(void*)` | Matching | 100.00% | 8 |
| `func_00360968` | Matching | 100.00% | 8 |
| `func_00360970(void*)` | Matching | 100.00% | 12 |
| `func_00360980(void*)` | Matching | 100.00% | 12 |
| `func_00360990(void*)` | Matching | 100.00% | 8 |
| `func_00360998(void*)` | Matching | 100.00% | 8 |
| `func_003609A0(void*)` | Matching | 100.00% | 8 |
| `func_003609A8(void*)` | Matching | 100.00% | 8 |
| `func_003609B0(void*)` | Matching | 100.00% | 12 |
| `func_003609C0(void*)` | Matching | 100.00% | 8 |
| `func_003609C8(void*)` | Matching | 100.00% | 8 |
| `func_003609D0(void*)` | Matching | 100.00% | 8 |
| `func_003609D8(void*)` | Matching | 100.00% | 8 |
| `func_003609E0(void*)` | Matching | 100.00% | 8 |
| `func_003609E8(void*)` | Matching | 100.00% | 8 |
| `func_003609F0(void*)` | Matching | 100.00% | 8 |
| `func_003609F8(void*)` | Matching | 100.00% | 8 |
| `func_00360A00(void*)` | Matching | 100.00% | 8 |
| `func_00360A08(void*)` | Matching | 100.00% | 8 |
| `func_00360A10(void*)` | Matching | 100.00% | 8 |
| `func_00360A18(void*)` | Matching | 100.00% | 8 |
| `func_00360A20(void*)` | Matching | 100.00% | 8 |
| `func_00360A28(void*)` | Matching | 100.00% | 40 |
| `func_00360A50(void*)` | Matching | 100.00% | 8 |
| `func_00360A58(void*)` | Matching | 100.00% | 8 |
| `func_00360A60(void*)` | Matching | 100.00% | 8 |
| `func_00360A68(void*)` | Matching | 100.00% | 8 |
| `func_00360A70(void*)` | Matching | 100.00% | 40 |
| `func_00360A98(void*)` | Matching | 100.00% | 8 |
| `func_00360AA0(void*)` | Matching | 100.00% | 8 |
| `func_00360AA8(void*)` | Matching | 100.00% | 8 |
| `func_00360AB0(void*)` | Matching | 100.00% | 8 |
| `func_00360AB8(void*)` | Matching | 100.00% | 40 |
| `func_00360AE0(void*)` | Matching | 100.00% | 8 |
| `func_00360AE8(void*)` | Matching | 100.00% | 8 |
| `func_00360AF0(void*)` | Matching | 100.00% | 8 |
| `func_00360AF8(void*)` | Matching | 100.00% | 8 |
| `func_00360B00` | Matching | 100.00% | 48 |
| `func_00360B30(void*)` | Matching | 100.00% | 8 |
| `func_00360B38(void*)` | Matching | 100.00% | 8 |
| `func_00360B40(void*)` | Matching | 100.00% | 8 |
| `func_00360B48(void*)` | Matching | 100.00% | 8 |
| `func_00360B50(void*)` | Matching | 100.00% | 8 |
| `func_00360B58(void*)` | Matching | 100.00% | 8 |
| `func_00360B60(void*)` | Matching | 100.00% | 8 |
| `func_00360B68(void*)` | Matching | 100.00% | 8 |
| `func_00360B70(void*)` | Matching | 100.00% | 8 |
| `func_00360B78(void*)` | Matching | 100.00% | 8 |
| `func_00360B80(void*)` | Matching | 100.00% | 8 |
| `func_00360B88(void*)` | Matching | 100.00% | 8 |
| `func_00360B90(void*)` | Matching | 100.00% | 12 |
| `func_00360BA0(void*)` | Matching | 100.00% | 8 |
| `func_00360BA8(void*)` | Matching | 100.00% | 8 |
| `func_00360BB0(void*)` | Matching | 100.00% | 8 |
| `func_00360BB8(void*)` | Matching | 100.00% | 8 |
| `func_00360BC0(void*)` | Matching | 100.00% | 8 |
| `func_00360BC8(void*)` | Matching | 100.00% | 8 |
| `func_00360BD0(void*)` | Matching | 100.00% | 8 |
| `func_00360BD8(void*)` | Matching | 100.00% | 8 |
| `func_00360BE0(void*)` | Matching | 100.00% | 8 |
| `func_00360BE8(void*)` | Matching | 100.00% | 8 |
| `func_00360BF0(void*)` | Matching | 100.00% | 8 |
| `func_00360BF8(void*)` | Matching | 100.00% | 8 |
| `func_00360C00(void*)` | Matching | 100.00% | 8 |
| `func_00360C08` | Matching | 100.00% | 28 |
| `func_00360C28` | Matching | 100.00% | 48 |
| `func_00360C58(void*)` | Matching | 100.00% | 8 |
| `func_00360C60(void*)` | Matching | 100.00% | 8 |
| `func_00360C68(void*)` | Matching | 100.00% | 8 |
| `func_00360C70(void*)` | Matching | 100.00% | 8 |
| `func_00360C78(void*)` | Matching | 100.00% | 28 |
| `func_00360C98` | Matching | 100.00% | 80 |
| `func_00360CE8(void*)` | Matching | 100.00% | 8 |
| `func_00360CF0(void*)` | Matching | 100.00% | 8 |
| `func_00360CF8(void*)` | Matching | 100.00% | 8 |
| `func_00360D00(void*)` | Matching | 100.00% | 8 |
| `func_00360D08(void*)` | Matching | 100.00% | 8 |
| `func_00360D10(void*)` | Matching | 100.00% | 8 |
| `func_00360D18` | Matching | 100.00% | 8 |
| `func_00360D20(void*)` | Matching | 100.00% | 8 |
| `func_00360D28(void*)` | Matching | 100.00% | 8 |
| `func_00360D30` | Matching | 100.00% | 8 |
| `func_00360D38(void*)` | Matching | 100.00% | 8 |
| `func_00360D40` | Matching | 100.00% | 80 |
| `func_00360D90(void*)` | Matching | 100.00% | 8 |
| `func_00360D98` | Matching | 100.00% | 8 |
| `func_00360DA0` | Matching | 100.00% | 40 |
| `func_00360DC8(void*)` | Matching | 100.00% | 8 |
| `func_00360DD0(void*)` | Matching | 100.00% | 8 |
| `func_00360DD8` | Matching | 100.00% | 16 |
| `func_00360DE8` | Matching | 100.00% | 72 |
| `func_00360E30` | Matching | 100.00% | 28 |
| `func_00360E50` | Matching | 100.00% | 28 |
| `func_00360E70` | Matching | 100.00% | 28 |
| `func_00360E90` | Matching | 100.00% | 64 |
| `func_00360ED0` | Matching | 100.00% | 76 |
| `func_00360F20` | Matching | 100.00% | 40 |
| `func_00360F48` | Matching | 100.00% | 40 |
| `func_00360F70` | Matching | 100.00% | 40 |
| `func_00360F98` | Matching | 100.00% | 40 |
| `func_00360FC0` | Matching | 100.00% | 40 |
| `func_00360FE8` | Matching | 100.00% | 40 |
| `func_00361010` | Matching | 100.00% | 40 |
| `func_00361038(void*)` | Matching | 100.00% | 40 |
| `func_00361060(void*)` | Matching | 100.00% | 8 |
| `func_00361068` | Matching | 100.00% | 20 |
| `func_00361080(void*)` | Matching | 100.00% | 12 |
| `func_00361090(void*)` | Matching | 100.00% | 8 |
| `func_00361098` | Matching | 100.00% | 72 |
| `func_003610E0` | Matching | 100.00% | 92 |
| `func_00361150(void*)` | Matching | 100.00% | 8 |
| `func_00361158` | Matching | 100.00% | 24 |
| `func_00361170` | Matching | 100.00% | 36 |
| `func_00361198(void*)` | Matching | 100.00% | 8 |
| `func_003611A0` | Matching | 100.00% | 52 |
| `func_003611D8` | Matching | 100.00% | 48 |
| `func_00361208` | Matching | 100.00% | 60 |
| `func_00361248` | Matching | 100.00% | 72 |
| `func_00361290` | Matching | 100.00% | 48 |
| `func_003612C0` | Matching | 100.00% | 52 |
| `func_003612F8` | Matching | 100.00% | 8 |
| `func_00361300` | Matching | 100.00% | 64 |
| `func_00361340` | Matching | 100.00% | 48 |
| `func_00361370` | Matching | 100.00% | 8 |
| `func_00361378` | Matching | 100.00% | 56 |
| `func_003613B0` | Matching | 100.00% | 60 |
| `func_003613F0` | Matching | 100.00% | 12 |
| `func_00361400` | Matching | 100.00% | 88 |
| `func_00361458(void*)` | Matching | 100.00% | 8 |
| `func_00361460` | Matching | 100.00% | 36 |
| `func_00361488` | Matching | 100.00% | 48 |
| `func_003614B8(void*)` | Matching | 100.00% | 8 |
| `func_003614C0(void*)` | Matching | 100.00% | 8 |
| `func_003614C8(void*)` | Matching | 100.00% | 8 |
| `func_003614D0(void*)` | Matching | 100.00% | 40 |
| `func_003614F8(void*)` | Matching | 100.00% | 8 |
| `func_00361500(void*)` | Matching | 100.00% | 40 |
| `func_00361528(void*)` | Matching | 100.00% | 8 |
| `func_00361530(void*)` | Matching | 100.00% | 40 |
| `func_00361558(void*)` | Matching | 100.00% | 8 |
| `func_00361560(void*)` | Matching | 100.00% | 8 |
| `func_00361568(void*)` | Matching | 100.00% | 8 |
| `func_00361570(void*)` | Matching | 100.00% | 8 |
| `func_00361578(void*)` | Matching | 100.00% | 8 |
| `func_00361580(void*)` | Matching | 100.00% | 8 |
| `func_00361588(void*)` | Matching | 100.00% | 8 |
| `func_00361590(void*)` | Matching | 100.00% | 8 |
| `func_00361598(void*)` | Matching | 100.00% | 8 |
| `func_003615A0(void*)` | Matching | 100.00% | 8 |
| `func_003615A8` | Matching | 100.00% | 24 |
| `func_003615C0` | Matching | 100.00% | 24 |
| `func_003615D8` | Matching | 100.00% | 376 |
| `func_00361750` | Matching | 100.00% | 12 |
| `func_00361760` | Matching | 100.00% | 8 |
| `func_00361768(void*)` | Matching | 100.00% | 8 |
| `func_00361770(void*)` | Matching | 100.00% | 8 |
| `func_00361778` | Matching | 100.00% | 52 |
| `func_003617B0(void*)` | Matching | 100.00% | 8 |
| `func_003617B8` | Matching | 100.00% | 72 |
| `func_00361800` | Matching | 100.00% | 88 |
| `func_00361858` | Matching | 100.00% | 108 |
| `func_003618C8` | Matching | 100.00% | 48 |
| `func_003618F8(void*)` | Matching | 100.00% | 8 |
| `func_00361900(void*)` | Matching | 100.00% | 8 |
| `func_00361908(void*)` | Matching | 100.00% | 8 |
| `func_00361910(void*)` | Matching | 100.00% | 8 |
| `func_00361918` | Matching | 100.00% | 20 |
| `func_00361930(void*)` | Matching | 100.00% | 8 |
| `func_00361938(void*, float)` | Matching | 100.00% | 8 |
| `func_00361940` | Matching | 100.00% | 68 |
| `func_00361988` | Matching | 100.00% | 48 |
| `func_003619B8(void*)` | Matching | 100.00% | 12 |
| `func_003619C8(void*)` | Matching | 100.00% | 8 |
| `func_003619D0(void*)` | Matching | 100.00% | 8 |
| `func_003619D8` | Matching | 100.00% | 8 |
| `func_003619E0` | Matching | 100.00% | 48 |
| `func_00361A10(void*)` | Matching | 100.00% | 12 |
| `func_00361A20(void*)` | Matching | 100.00% | 8 |
| `func_00361A28(void*)` | Matching | 100.00% | 8 |
| `func_00361A30` | Matching | 100.00% | 20 |
| `func_00361A48(void*)` | Matching | 100.00% | 8 |
| `func_00361A50(void*)` | Matching | 100.00% | 8 |
| `func_00361A58(void*)` | Matching | 100.00% | 8 |
| `func_00361A60` | Matching | 100.00% | 68 |
| `func_00361AA8` | Matching | 100.00% | 48 |
| `func_00361AD8(void*)` | Matching | 100.00% | 8 |
| `func_00361AE0` | Matching | 100.00% | 20 |
| `func_00361AF8(void*)` | Matching | 100.00% | 8 |
| `func_00361B00(void*, float)` | Matching | 100.00% | 8 |
| `func_00361B08(void*)` | Matching | 100.00% | 8 |
| `func_00361B10(void*)` | Matching | 100.00% | 8 |
| `func_00361B18` | Matching | 100.00% | 48 |
| `func_00361B48(void*)` | Matching | 100.00% | 8 |
| `func_00361B50(void*)` | Matching | 100.00% | 8 |
| `func_00361B58(void*)` | Matching | 100.00% | 8 |
| `func_00361B60` | Matching | 100.00% | 20 |
| `func_00361B78(void*)` | Matching | 100.00% | 8 |
| `func_00361B80(void*, float)` | Matching | 100.00% | 8 |
| `func_00361B88(void*)` | Matching | 100.00% | 8 |
| `func_00361B90` | Matching | 100.00% | 68 |
| `func_00361BD8(void*)` | Matching | 100.00% | 8 |
| `func_00361BE0(void*)` | Matching | 100.00% | 12 |
| `func_00361BF0` | Matching | 100.00% | 24 |
| `func_00361C08` | Matching | 100.00% | 8 |
| `func_00361C10(void*)` | Matching | 100.00% | 8 |
| `func_00361C18(void*, float)` | Matching | 100.00% | 8 |
| `func_00361C20` | Matching | 100.00% | 76 |
| `func_00361C70(void*)` | Matching | 100.00% | 8 |
| `func_00361C78` | Matching | 100.00% | 48 |
| `func_00361CA8(void*)` | Matching | 100.00% | 8 |
| `func_00361CB0` | Matching | 100.00% | 40 |
| `func_00361CD8(void*)` | Matching | 100.00% | 32 |
| `func_00361CF8(void*)` | Matching | 100.00% | 8 |
| `func_00361D00` | Matching | 100.00% | 20 |
| `func_00361D18(void*)` | Matching | 100.00% | 8 |
| `func_00361D20(void*)` | Matching | 100.00% | 8 |
| `func_00361D28(void*, float)` | Matching | 100.00% | 8 |
| `func_00361D30(void*)` | Matching | 100.00% | 8 |
| `func_00361D38(void*)` | Matching | 100.00% | 8 |
| `func_00361D40(void*)` | Matching | 100.00% | 8 |
| `func_00361D48` | Matching | 100.00% | 8 |
| `func_00361D50(void*)` | Matching | 100.00% | 40 |
| `func_00361D78` | Matching | 100.00% | 12 |
| `func_00361D88(void*)` | Matching | 100.00% | 8 |
| `func_00361D90` | Matching | 100.00% | 76 |
| `func_00361DE0(void*)` | Matching | 100.00% | 40 |
| `func_00361E08(void*)` | Matching | 100.00% | 8 |
| `func_00361E10(void*)` | Matching | 100.00% | 32 |
| `func_00361E30` | Matching | 100.00% | 76 |
| `func_00361E80` | Matching | 100.00% | 52 |
| `func_00361EB8` | Matching | 100.00% | 132 |
| `func_00361F40(void*)` | Matching | 100.00% | 28 |
| `func_00361F60` | Matching | 100.00% | 44 |
| `func_00361F90(void*)` | Matching | 100.00% | 8 |
| `func_00361F98` | Matching | 100.00% | 112 |
| `func_00362008` | Matching | 100.00% | 80 |
| `func_00362058` | Matching | 100.00% | 112 |
| `func_003620C8` | Matching | 100.00% | 84 |
| `func_00362120` | Matching | 100.00% | 268 |
| `func_00362230` | Matching | 100.00% | 268 |
| `func_00362340` | Matching | 100.00% | 100 |
| `func_003623A8` | Matching | 100.00% | 48 |
| `func_003623D8` | Matching | 100.00% | 108 |
| `func_00362448` | Matching | 100.00% | 48 |
| `func_00362478` | Matching | 100.00% | 324 |
| `func_003625C0` | Matching | 100.00% | 160 |
| `func_00362660` | Matching | 100.00% | 120 |
| `func_003626D8` | Matching | 100.00% | 204 |
| `func_003627A8` | Matching | 100.00% | 460 |
| `func_00362978` | Matching | 100.00% | 64 |
| `func_003629B8` | Matching | 100.00% | 780 |
| `func_00362CC8` | Matching | 100.00% | 288 |
| `func_00364050` | Matching | 100.00% | 496 |
| `func_00364240` | Matching | 100.00% | 288 |
| `func_00364360` | Matching | 100.00% | 596 |
| `func_00364B88` | Matching | 100.00% | 260 |
| `func_00364C90` | Matching | 100.00% | 60 |
| `func_00365E40` | Matching | 100.00% | 296 |
| `func_00365F68` | Matching | 100.00% | 60 |
| `func_00365FA8` | Matching | 100.00% | 60 |
| `func_00365FE8` | Matching | 100.00% | 32 |
| `func_00366008` | Matching | 100.00% | 160 |
| `func_003660A8` | Matching | 100.00% | 396 |
| `func_00366238` | Matching | 100.00% | 148 |
| `func_003662D0` | Matching | 100.00% | 260 |
| `func_003663D8` | Matching | 100.00% | 368 |
| `func_00366548` | Matching | 100.00% | 204 |
| `func_00366618` | Matching | 100.00% | 220 |
| `func_003666F8` | Matching | 100.00% | 256 |
| `func_003667F8` | Matching | 100.00% | 140 |
| `func_00366888` | Matching | 100.00% | 108 |
| `func_003668F8` | Matching | 100.00% | 248 |
| `func_00366DD8` | Matching | 100.00% | 88 |
| `func_00366E30` | Matching | 100.00% | 96 |
| `func_00366E90` | Matching | 100.00% | 336 |
| `func_00366FE0(void*, int)` | Matching | 100.00% | 8 |
| `func_00366FE8` | Matching | 100.00% | 140 |
| `func_00367078` | Matching | 100.00% | 100 |
| `func_003670E0` | Matching | 100.00% | 108 |
| `func_0035D4A0` | Matching | 99.98% | 1124 |
| `func_0035F7D0` | Matching | 99.98% | 860 |
| `func_0035DA70` | Matching | 99.93% | 884 |
| `func_00366CE0` | Matching | 99.92% | 248 |
| `func_0035FE10` | Matching | 99.34% | 2288 |
| `func_00361140` | Matching | 98.75% | 16 |

### `object/spline3d`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSpline_calcLength(cSpline*)` | Matching | 100.00% | 76 |
| `func_00345538` | Matching | 100.00% | 52 |
| `cSpline_readFromReplayFrame` | Matching | 100.00% | 200 |
| `func_00345638` | Matching | 100.00% | 200 |

### `object/splinemodifier`

32 matching, 0 partial, 3 not started (35 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSplineModifier_cSplineModifier` | Matching | 100.00% | 176 |
| `func_00359688` | Matching | 100.00% | 16 |
| `func_00359698` | Matching | 100.00% | 404 |
| `func_00359EB8` | Matching | 100.00% | 116 |
| `func_00359F30` | Matching | 100.00% | 84 |
| `func_0035A118` | Matching | 100.00% | 308 |
| `func_0035A250` | Matching | 100.00% | 216 |
| `cMultiSplineModifier_allocNodes` | Matching | 100.00% | 196 |
| `func_0035A3F0` | Matching | 100.00% | 104 |
| `cMultiSplineModifier_setupNodes` | Matching | 100.00% | 244 |
| `func_0035A560` | Matching | 100.00% | 120 |
| `func_0035A5D8(void*)` | Matching | 100.00% | 28 |
| `cMultiSplineModifier_setupOverlapSystem` | Matching | 100.00% | 392 |
| `func_0035A780` | Matching | 100.00% | 404 |
| `func_0035A918` | Matching | 100.00% | 440 |
| `func_0035AAD0(void*)` | Matching | 100.00% | 16 |
| `func_0035AAE0(void*)` | Matching | 100.00% | 16 |
| `func_0035AAF0` | Matching | 100.00% | 108 |
| `func_0035AB60` | Matching | 100.00% | 144 |
| `func_0035ABF0` | Matching | 100.00% | 48 |
| `func_0035B418` | Matching | 100.00% | 396 |
| `func_0035B5A8` | Matching | 100.00% | 196 |
| `func_0035B670` | Matching | 100.00% | 32 |
| `func_0035B690` | Matching | 100.00% | 60 |
| `func_0035B6D0` | Matching | 100.00% | 52 |
| `func_0035B708` | Matching | 100.00% | 892 |
| `func_0035BA88` | Matching | 100.00% | 740 |
| `func_0035BD70` | Matching | 100.00% | 720 |
| `func_0035C040` | Matching | 100.00% | 168 |
| `func_00359CF8` | Matching | 99.95% | 444 |
| `func_00359F88` | Matching | 99.95% | 396 |
| `func_0035A550` | Matching | 98.75% | 16 |

### `object/spring`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSpring_setupNodes` | Matching | 100.00% | 192 |
| `func_00353FC0` | Matching | 100.00% | 1560 |
| `func_003545D8` | Matching | 100.00% | 112 |
| `func_00354648` | Matching | 100.00% | 64 |

### `path/pathsys`

24 matching, 0 partial, 0 not started (24 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPathSys_resolvePaths` | Matching | 100.00% | 252 |
| `func_0026B410` | Matching | 100.00% | 244 |
| `func_0026B508` | Matching | 100.00% | 68 |
| `func_0026B550` | Matching | 100.00% | 68 |
| `func_0026B598` | Matching | 100.00% | 68 |
| `func_0026B5E0` | Matching | 100.00% | 100 |
| `func_0026B648` | Matching | 100.00% | 52 |
| `func_0026B680` | Matching | 100.00% | 340 |
| `func_0026B7D8` | Matching | 100.00% | 164 |
| `func_0026B880` | Matching | 100.00% | 456 |
| `func_0026BA48` | Matching | 100.00% | 32 |
| `func_0026BA68` | Matching | 100.00% | 32 |
| `func_0026BA88` | Matching | 100.00% | 32 |
| `func_0026BAA8` | Matching | 100.00% | 60 |
| `func_0026C3D0` | Matching | 100.00% | 44 |
| `func_0026C400` | Matching | 100.00% | 8 |
| `func_0026C408` | Matching | 100.00% | 8 |
| `func_0026C410(void*)` | Matching | 100.00% | 8 |
| `func_0026C418(void*)` | Matching | 100.00% | 8 |
| `func_0026C420` | Matching | 100.00% | 8 |
| `func_0026C428` | Matching | 100.00% | 8 |
| `func_0026C430` | Matching | 100.00% | 8 |
| `func_0026C438(void*)` | Matching | 100.00% | 32 |
| `func_0026BAE8` | Matching | 99.98% | 2276 |

### `render/bezierman`

15 matching, 0 partial, 5 not started (20 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBezierMan_construct()` | Matching | 100.00% | 52 |
| `func_0038B0F8` | Matching | 100.00% | 96 |
| `func_0038B158(void*)` | Matching | 100.00% | 28 |
| `func_0038B178(void*)` | Matching | 100.00% | 20 |
| `func_0038B190` | Matching | 100.00% | 420 |
| `func_0038B338` | Matching | 100.00% | 56 |
| `func_0038C788` | Matching | 100.00% | 636 |
| `func_0038CA08` | Matching | 100.00% | 104 |
| `func_0038CA70` | Matching | 100.00% | 940 |
| `func_0038CE20` | Matching | 100.00% | 836 |
| `func_0038D638` | Matching | 100.00% | 40 |
| `func_0038D660(void*)` | Matching | 100.00% | 8 |
| `func_0038D668` | Matching | 100.00% | 36 |
| `func_0038D968` | Matching | 100.00% | 612 |
| `func_0038D690` | Matching | 99.97% | 724 |

### `render/font`

432 matching, 0 partial, 1 not started (433 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFont_linkFont` | Matching | 100.00% | 604 |
| `func_003919E8` | Matching | 100.00% | 92 |
| `cFont_downloadTexture` | Matching | 100.00% | 508 |
| `func_00391C48` | Matching | 100.00% | 100 |
| `func_00391CB0` | Matching | 100.00% | 384 |
| `func_00391E30` | Matching | 100.00% | 384 |
| `func_00391FB0` | Matching | 100.00% | 572 |
| `func_003921F0` | Matching | 100.00% | 572 |
| `func_00392430` | Matching | 100.00% | 592 |
| `func_00392680` | Matching | 100.00% | 644 |
| `func_00392908` | Matching | 100.00% | 120 |
| `func_00392980` | Matching | 100.00% | 120 |
| `func_003929F8` | Matching | 100.00% | 104 |
| `func_00392A60` | Matching | 100.00% | 108 |
| `func_00392AD0` | Matching | 100.00% | 108 |
| `func_00392B40` | Matching | 100.00% | 104 |
| `func_00392BA8` | Matching | 100.00% | 180 |
| `func_00392C60` | Matching | 100.00% | 180 |
| `func_00392D18` | Matching | 100.00% | 60 |
| `func_00392D58` | Matching | 100.00% | 52 |
| `func_00392D90` | Matching | 100.00% | 76 |
| `func_00392DE0` | Matching | 100.00% | 8 |
| `func_00392DE8(void*, int)` | Matching | 100.00% | 8 |
| `func_00392DF0` | Matching | 100.00% | 108 |
| `func_00392E60` | Matching | 100.00% | 52 |
| `func_00392E98` | Matching | 100.00% | 364 |
| `func_00393008` | Matching | 100.00% | 60 |
| `func_00393FA8(void*)` | Matching | 100.00% | 8 |
| `func_00393FB0(void*)` | Matching | 100.00% | 8 |
| `func_00393FB8` | Matching | 100.00% | 28 |
| `func_00393FD8` | Matching | 100.00% | 20 |
| `func_00393FF0` | Matching | 100.00% | 20 |
| `func_00394008(void*)` | Matching | 100.00% | 8 |
| `func_00394010(void*)` | Matching | 100.00% | 8 |
| `func_00394018(void*)` | Matching | 100.00% | 8 |
| `func_00394020` | Matching | 100.00% | 8 |
| `func_00394028` | Matching | 100.00% | 8 |
| `func_00394030` | Matching | 100.00% | 8 |
| `func_00394038` | Matching | 100.00% | 8 |
| `func_00394040` | Matching | 100.00% | 16 |
| `func_00394050` | Matching | 100.00% | 16 |
| `func_00394060` | Matching | 100.00% | 16 |
| `func_00394070` | Matching | 100.00% | 16 |
| `func_00394080` | Matching | 100.00% | 16 |
| `func_00394090` | Matching | 100.00% | 16 |
| `func_003940A0` | Matching | 100.00% | 16 |
| `func_003940B0` | Matching | 100.00% | 16 |
| `func_003940C0` | Matching | 100.00% | 16 |
| `func_003940D0` | Matching | 100.00% | 16 |
| `func_003940E0` | Matching | 100.00% | 16 |
| `func_003940F0` | Matching | 100.00% | 16 |
| `func_00394100` | Matching | 100.00% | 16 |
| `func_00394110` | Matching | 100.00% | 16 |
| `func_00394120` | Matching | 100.00% | 16 |
| `func_00394130` | Matching | 100.00% | 16 |
| `func_00394140` | Matching | 100.00% | 16 |
| `func_00394150` | Matching | 100.00% | 16 |
| `func_00394160` | Matching | 100.00% | 16 |
| `func_00394170` | Matching | 100.00% | 16 |
| `func_00394180` | Matching | 100.00% | 16 |
| `func_00394190` | Matching | 100.00% | 16 |
| `func_003941A0` | Matching | 100.00% | 16 |
| `func_003941B0` | Matching | 100.00% | 16 |
| `func_003941C0` | Matching | 100.00% | 16 |
| `func_003941D0` | Matching | 100.00% | 16 |
| `func_003941E0` | Matching | 100.00% | 16 |
| `func_003941F0` | Matching | 100.00% | 16 |
| `func_00394200` | Matching | 100.00% | 16 |
| `func_00394210` | Matching | 100.00% | 16 |
| `func_00394220` | Matching | 100.00% | 16 |
| `func_00394230` | Matching | 100.00% | 16 |
| `func_00394240` | Matching | 100.00% | 16 |
| `func_00394250` | Matching | 100.00% | 16 |
| `func_00394260` | Matching | 100.00% | 16 |
| `func_00394270` | Matching | 100.00% | 16 |
| `func_00394280` | Matching | 100.00% | 16 |
| `func_00394290` | Matching | 100.00% | 16 |
| `func_003942A0` | Matching | 100.00% | 32 |
| `func_003942C0(void*)` | Matching | 100.00% | 8 |
| `func_003942C8(void*)` | Matching | 100.00% | 8 |
| `func_003942D0(void*)` | Matching | 100.00% | 8 |
| `func_003942D8(void*)` | Matching | 100.00% | 8 |
| `func_003942E0(void*)` | Matching | 100.00% | 8 |
| `func_003942E8` | Matching | 100.00% | 60 |
| `func_00394328` | Matching | 100.00% | 48 |
| `func_00394358` | Matching | 100.00% | 8 |
| `func_00394360` | Matching | 100.00% | 8 |
| `func_00394368` | Matching | 100.00% | 44 |
| `func_00394398` | Matching | 100.00% | 36 |
| `func_003943C0` | Matching | 100.00% | 84 |
| `func_00394418` | Matching | 100.00% | 88 |
| `func_00394470` | Matching | 100.00% | 56 |
| `func_003944A8` | Matching | 100.00% | 76 |
| `func_003944F8` | Matching | 100.00% | 52 |
| `func_00394530` | Matching | 100.00% | 40 |
| `func_00394558` | Matching | 100.00% | 20 |
| `func_00394570` | Matching | 100.00% | 20 |
| `func_00394588` | Matching | 100.00% | 16 |
| `func_00394598` | Matching | 100.00% | 28 |
| `func_003945B8(void*)` | Matching | 100.00% | 8 |
| `func_003945C0(void*)` | Matching | 100.00% | 8 |
| `func_003945C8(void*)` | Matching | 100.00% | 8 |
| `func_003945D0(void*)` | Matching | 100.00% | 8 |
| `func_003945D8(void*)` | Matching | 100.00% | 8 |
| `func_003945E0(void*)` | Matching | 100.00% | 8 |
| `func_003945E8(void*)` | Matching | 100.00% | 8 |
| `func_003945F0` | Matching | 100.00% | 8 |
| `func_003945F8` | Matching | 100.00% | 20 |
| `func_00394610(void*)` | Matching | 100.00% | 8 |
| `func_00394618(void*)` | Matching | 100.00% | 8 |
| `func_00394620(void*)` | Matching | 100.00% | 8 |
| `func_00394628(void*)` | Matching | 100.00% | 8 |
| `func_00394630(void*)` | Matching | 100.00% | 8 |
| `func_00394638(void*)` | Matching | 100.00% | 8 |
| `func_00394640(void*)` | Matching | 100.00% | 8 |
| `func_00394648(void*)` | Matching | 100.00% | 8 |
| `func_00394650(void*)` | Matching | 100.00% | 8 |
| `func_00394658(void*)` | Matching | 100.00% | 8 |
| `func_00394660(void*)` | Matching | 100.00% | 8 |
| `func_00394668(void*)` | Matching | 100.00% | 8 |
| `func_00394670(void*)` | Matching | 100.00% | 8 |
| `func_00394678(void*)` | Matching | 100.00% | 8 |
| `func_00394680(void*)` | Matching | 100.00% | 8 |
| `func_00394688(void*)` | Matching | 100.00% | 8 |
| `func_00394690` | Matching | 100.00% | 8 |
| `func_00394698` | Matching | 100.00% | 8 |
| `func_003946A0` | Matching | 100.00% | 8 |
| `func_003946A8` | Matching | 100.00% | 16 |
| `func_003946B8` | Matching | 100.00% | 16 |
| `func_003946C8` | Matching | 100.00% | 8 |
| `func_003946D0` | Matching | 100.00% | 8 |
| `func_003946D8` | Matching | 100.00% | 12 |
| `func_003946E8(void*)` | Matching | 100.00% | 8 |
| `func_003946F0` | Matching | 100.00% | 128 |
| `func_00394770` | Matching | 100.00% | 20 |
| `func_00394788` | Matching | 100.00% | 60 |
| `func_003947C8` | Matching | 100.00% | 16 |
| `func_003947D8` | Matching | 100.00% | 212 |
| `func_003948B0` | Matching | 100.00% | 16 |
| `func_003948C0` | Matching | 100.00% | 16 |
| `func_003949A0` | Matching | 100.00% | 128 |
| `func_00394A20` | Matching | 100.00% | 184 |
| `func_00394B38` | Matching | 100.00% | 48 |
| `func_00394B68(void*)` | Matching | 100.00% | 8 |
| `func_00394B70` | Matching | 100.00% | 8 |
| `func_00394B78(void*)` | Matching | 100.00% | 8 |
| `func_00394B80(void*)` | Matching | 100.00% | 8 |
| `func_00394B88(void*, float)` | Matching | 100.00% | 8 |
| `func_00394B90(void*)` | Matching | 100.00% | 8 |
| `func_00394B98` | Matching | 100.00% | 40 |
| `func_00394BC0(void*, float)` | Matching | 100.00% | 8 |
| `func_00394BC8(void*, float)` | Matching | 100.00% | 8 |
| `func_00394BD0(void*)` | Matching | 100.00% | 8 |
| `func_00394BD8(void*)` | Matching | 100.00% | 8 |
| `func_00394BE0(void*, int)` | Matching | 100.00% | 8 |
| `func_00394BE8(void*, int)` | Matching | 100.00% | 8 |
| `func_00394BF0(void*, int)` | Matching | 100.00% | 8 |
| `func_00394BF8(void*, int)` | Matching | 100.00% | 8 |
| `func_00394C00(void*)` | Matching | 100.00% | 8 |
| `func_00394C08(void*)` | Matching | 100.00% | 8 |
| `func_00394C10(void*)` | Matching | 100.00% | 8 |
| `func_00394C18` | Matching | 100.00% | 24 |
| `func_00394C30` | Matching | 100.00% | 8 |
| `func_00394C38` | Matching | 100.00% | 8 |
| `func_00394C40` | Matching | 100.00% | 8 |
| `func_00394C48(void*)` | Matching | 100.00% | 8 |
| `func_00394C50(void*)` | Matching | 100.00% | 8 |
| `func_00394C58(void*)` | Matching | 100.00% | 8 |
| `func_00394C60(void*)` | Matching | 100.00% | 8 |
| `func_00394C68(void*)` | Matching | 100.00% | 28 |
| `func_00394C88(void*, int)` | Matching | 100.00% | 16 |
| `func_00394C98` | Matching | 100.00% | 80 |
| `func_00394CE8` | Matching | 100.00% | 40 |
| `func_00394D10(void*)` | Matching | 100.00% | 8 |
| `func_00394D18` | Matching | 100.00% | 24 |
| `func_00394D30(void*)` | Matching | 100.00% | 8 |
| `func_00394D38(void*)` | Matching | 100.00% | 8 |
| `func_00394D40(void*)` | Matching | 100.00% | 8 |
| `func_00394D48(void*)` | Matching | 100.00% | 8 |
| `func_00394D50` | Matching | 100.00% | 380 |
| `func_00394ED0` | Matching | 100.00% | 304 |
| `func_00395000` | Matching | 100.00% | 188 |
| `func_003950C0` | Matching | 100.00% | 424 |
| `func_00395268(void*)` | Matching | 100.00% | 28 |
| `func_00395288` | Matching | 100.00% | 140 |
| `func_00395318(void*)` | Matching | 100.00% | 8 |
| `func_00395320(void*)` | Matching | 100.00% | 8 |
| `func_00395328(void*)` | Matching | 100.00% | 8 |
| `func_00395330` | Matching | 100.00% | 28 |
| `func_00395350` | Matching | 100.00% | 28 |
| `func_00395370` | Matching | 100.00% | 64 |
| `func_003953B0(void*)` | Matching | 100.00% | 8 |
| `func_003953B8` | Matching | 100.00% | 92 |
| `func_00395418` | Matching | 100.00% | 8 |
| `func_00395420(void*)` | Matching | 100.00% | 8 |
| `func_00395428` | Matching | 100.00% | 8 |
| `func_00395430` | Matching | 100.00% | 20 |
| `func_00395448` | Matching | 100.00% | 36 |
| `func_00395470` | Matching | 100.00% | 36 |
| `func_00395498` | Matching | 100.00% | 56 |
| `func_003954D0` | Matching | 100.00% | 44 |
| `func_00395500(void*)` | Matching | 100.00% | 8 |
| `func_00395508(void*)` | Matching | 100.00% | 8 |
| `func_00395510(void*)` | Matching | 100.00% | 8 |
| `func_00395518` | Matching | 100.00% | 8 |
| `func_00395520` | Matching | 100.00% | 8 |
| `func_00395528` | Matching | 100.00% | 8 |
| `func_00395530` | Matching | 100.00% | 8 |
| `func_00395538` | Matching | 100.00% | 8 |
| `func_00395540` | Matching | 100.00% | 8 |
| `func_00395548` | Matching | 100.00% | 8 |
| `func_00395550` | Matching | 100.00% | 8 |
| `func_00395558` | Matching | 100.00% | 8 |
| `func_00395560` | Matching | 100.00% | 8 |
| `func_00395568` | Matching | 100.00% | 12 |
| `func_00395578` | Matching | 100.00% | 8 |
| `func_00395580` | Matching | 100.00% | 36 |
| `func_003955A8` | Matching | 100.00% | 8 |
| `func_003955B0` | Matching | 100.00% | 168 |
| `func_00395658` | Matching | 100.00% | 8 |
| `func_00395660` | Matching | 100.00% | 36 |
| `func_00395688` | Matching | 100.00% | 36 |
| `func_003956B0` | Matching | 100.00% | 40 |
| `func_003956D8` | Matching | 100.00% | 8 |
| `func_003956E0(void*, int)` | Matching | 100.00% | 8 |
| `func_003956E8` | Matching | 100.00% | 68 |
| `func_00395730(void*)` | Matching | 100.00% | 32 |
| `func_00395750` | Matching | 100.00% | 1252 |
| `func_00395C38` | Matching | 100.00% | 44 |
| `func_00395C68(void*)` | Matching | 100.00% | 8 |
| `func_00395C70` | Matching | 100.00% | 124 |
| `func_00395CF0` | Matching | 100.00% | 52 |
| `func_00395D28` | Matching | 100.00% | 52 |
| `func_00395D60` | Matching | 100.00% | 376 |
| `func_00395ED8` | Matching | 100.00% | 136 |
| `func_00395F60(void*)` | Matching | 100.00% | 28 |
| `func_00395F80(void*)` | Matching | 100.00% | 28 |
| `func_00395FA0(void*)` | Matching | 100.00% | 8 |
| `func_00395FA8` | Matching | 100.00% | 172 |
| `func_00396058` | Matching | 100.00% | 36 |
| `func_00396080` | Matching | 100.00% | 104 |
| `func_003960E8` | Matching | 100.00% | 28 |
| `func_00396108(void*)` | Matching | 100.00% | 8 |
| `func_00396128` | Matching | 100.00% | 56 |
| `func_00396160` | Matching | 100.00% | 48 |
| `func_00396190` | Matching | 100.00% | 8 |
| `func_00396198` | Matching | 100.00% | 8 |
| `func_003961A0` | Matching | 100.00% | 8 |
| `func_003961A8` | Matching | 100.00% | 48 |
| `func_003961D8` | Matching | 100.00% | 12 |
| `func_003961E8` | Matching | 100.00% | 12 |
| `func_003961F8` | Matching | 100.00% | 12 |
| `func_00396208` | Matching | 100.00% | 12 |
| `func_00396218` | Matching | 100.00% | 12 |
| `func_00396228` | Matching | 100.00% | 12 |
| `func_00396238` | Matching | 100.00% | 12 |
| `func_00396248` | Matching | 100.00% | 12 |
| `func_00396258` | Matching | 100.00% | 12 |
| `func_00396268` | Matching | 100.00% | 12 |
| `func_00396278` | Matching | 100.00% | 12 |
| `func_00396288` | Matching | 100.00% | 12 |
| `func_00396298` | Matching | 100.00% | 12 |
| `func_003962A8` | Matching | 100.00% | 12 |
| `func_003962B8` | Matching | 100.00% | 12 |
| `func_003962C8` | Matching | 100.00% | 12 |
| `func_003962D8` | Matching | 100.00% | 12 |
| `func_003962E8` | Matching | 100.00% | 12 |
| `func_003962F8` | Matching | 100.00% | 12 |
| `func_00396308` | Matching | 100.00% | 12 |
| `func_00396318` | Matching | 100.00% | 12 |
| `func_00396328` | Matching | 100.00% | 12 |
| `func_00396338` | Matching | 100.00% | 12 |
| `func_00396348` | Matching | 100.00% | 12 |
| `func_00396358` | Matching | 100.00% | 12 |
| `func_00396368` | Matching | 100.00% | 12 |
| `func_00396378` | Matching | 100.00% | 12 |
| `func_00396388` | Matching | 100.00% | 12 |
| `func_00396398` | Matching | 100.00% | 12 |
| `func_003963A8` | Matching | 100.00% | 12 |
| `func_003963B8` | Matching | 100.00% | 12 |
| `func_003963C8` | Matching | 100.00% | 12 |
| `func_003963D8` | Matching | 100.00% | 12 |
| `func_003963E8` | Matching | 100.00% | 12 |
| `func_003963F8` | Matching | 100.00% | 12 |
| `func_00396408` | Matching | 100.00% | 12 |
| `func_00396418` | Matching | 100.00% | 12 |
| `func_00396428` | Matching | 100.00% | 12 |
| `func_00396438` | Matching | 100.00% | 12 |
| `func_00396448` | Matching | 100.00% | 12 |
| `func_00396458` | Matching | 100.00% | 12 |
| `func_00396468` | Matching | 100.00% | 12 |
| `func_00396478` | Matching | 100.00% | 12 |
| `func_00396488` | Matching | 100.00% | 12 |
| `func_00396498` | Matching | 100.00% | 12 |
| `func_003964A8` | Matching | 100.00% | 12 |
| `func_003964B8` | Matching | 100.00% | 12 |
| `func_003964C8` | Matching | 100.00% | 48 |
| `func_003964F8` | Matching | 100.00% | 12 |
| `func_00396508` | Matching | 100.00% | 12 |
| `func_00396518` | Matching | 100.00% | 12 |
| `func_00396528` | Matching | 100.00% | 12 |
| `func_00396538` | Matching | 100.00% | 12 |
| `func_00396548` | Matching | 100.00% | 12 |
| `func_00396558` | Matching | 100.00% | 12 |
| `func_00396568` | Matching | 100.00% | 12 |
| `func_00396578` | Matching | 100.00% | 12 |
| `func_00396588` | Matching | 100.00% | 12 |
| `func_00396598` | Matching | 100.00% | 12 |
| `func_003965A8` | Matching | 100.00% | 12 |
| `func_003965B8` | Matching | 100.00% | 8 |
| `func_003965C0` | Matching | 100.00% | 8 |
| `func_003965C8` | Matching | 100.00% | 8 |
| `func_003965D0` | Matching | 100.00% | 12 |
| `func_003965E0` | Matching | 100.00% | 8 |
| `func_003965E8` | Matching | 100.00% | 8 |
| `func_003965F0` | Matching | 100.00% | 8 |
| `func_003965F8` | Matching | 100.00% | 8 |
| `func_00396600` | Matching | 100.00% | 8 |
| `func_00396608` | Matching | 100.00% | 8 |
| `func_00396610` | Matching | 100.00% | 8 |
| `func_00396618` | Matching | 100.00% | 60 |
| `func_00396658` | Matching | 100.00% | 60 |
| `func_00396698` | Matching | 100.00% | 64 |
| `func_003966D8` | Matching | 100.00% | 72 |
| `func_00396720` | Matching | 100.00% | 80 |
| `func_00396770` | Matching | 100.00% | 100 |
| `func_003967D8` | Matching | 100.00% | 68 |
| `func_00396820` | Matching | 100.00% | 20 |
| `func_00396838` | Matching | 100.00% | 48 |
| `func_00396868` | Matching | 100.00% | 12 |
| `func_00396878` | Matching | 100.00% | 12 |
| `func_00396888` | Matching | 100.00% | 12 |
| `func_00396898` | Matching | 100.00% | 12 |
| `func_003968A8` | Matching | 100.00% | 12 |
| `func_003968B8` | Matching | 100.00% | 12 |
| `func_003968C8(void*)` | Matching | 100.00% | 8 |
| `func_003968D0` | Matching | 100.00% | 24 |
| `func_003968E8` | Matching | 100.00% | 48 |
| `func_00396918(void*)` | Matching | 100.00% | 8 |
| `func_00396920(void*)` | Matching | 100.00% | 8 |
| `func_00396928` | Matching | 100.00% | 48 |
| `func_00396958(void*)` | Matching | 100.00% | 8 |
| `func_00396960` | Matching | 100.00% | 12 |
| `func_00396970` | Matching | 100.00% | 12 |
| `func_00396980` | Matching | 100.00% | 12 |
| `func_00396990` | Matching | 100.00% | 12 |
| `func_003969A0` | Matching | 100.00% | 12 |
| `func_003969B0` | Matching | 100.00% | 12 |
| `func_003969C0` | Matching | 100.00% | 12 |
| `func_003969D0` | Matching | 100.00% | 12 |
| `func_003969E0` | Matching | 100.00% | 12 |
| `func_003969F0` | Matching | 100.00% | 12 |
| `func_00396A00` | Matching | 100.00% | 48 |
| `func_00396A30` | Matching | 100.00% | 12 |
| `func_00396A40` | Matching | 100.00% | 12 |
| `func_00396A50` | Matching | 100.00% | 12 |
| `func_00396A60` | Matching | 100.00% | 12 |
| `func_00396A70` | Matching | 100.00% | 12 |
| `func_00396A80` | Matching | 100.00% | 12 |
| `func_00396A90` | Matching | 100.00% | 12 |
| `func_00396AA0` | Matching | 100.00% | 12 |
| `func_00396AB0` | Matching | 100.00% | 12 |
| `func_00396AC0` | Matching | 100.00% | 12 |
| `func_00396AD0` | Matching | 100.00% | 12 |
| `func_00396AE0` | Matching | 100.00% | 12 |
| `func_00396AF0` | Matching | 100.00% | 12 |
| `func_00396B00` | Matching | 100.00% | 12 |
| `func_00396B10` | Matching | 100.00% | 12 |
| `func_00396B20` | Matching | 100.00% | 12 |
| `func_00396B30` | Matching | 100.00% | 12 |
| `func_00396B40` | Matching | 100.00% | 236 |
| `func_00396C30` | Matching | 100.00% | 252 |
| `func_00396D30` | Matching | 100.00% | 48 |
| `func_00396D60` | Matching | 100.00% | 12 |
| `func_00396D70` | Matching | 100.00% | 12 |
| `func_00396D80` | Matching | 100.00% | 12 |
| `func_00396D90` | Matching | 100.00% | 12 |
| `func_00396DA0` | Matching | 100.00% | 12 |
| `func_00396DB0` | Matching | 100.00% | 12 |
| `func_00396DC0` | Matching | 100.00% | 12 |
| `func_00396DD0` | Matching | 100.00% | 12 |
| `func_00396DE0` | Matching | 100.00% | 12 |
| `func_00396DF0` | Matching | 100.00% | 12 |
| `func_00396E00` | Matching | 100.00% | 12 |
| `func_00396E10` | Matching | 100.00% | 12 |
| `func_00396E20` | Matching | 100.00% | 12 |
| `func_00396E30` | Matching | 100.00% | 12 |
| `func_00396E40` | Matching | 100.00% | 12 |
| `func_00396E50` | Matching | 100.00% | 12 |
| `func_00396E60` | Matching | 100.00% | 12 |
| `func_00396E70` | Matching | 100.00% | 12 |
| `func_00396E80` | Matching | 100.00% | 12 |
| `func_00396E90` | Matching | 100.00% | 12 |
| `func_00396EA0` | Matching | 100.00% | 12 |
| `func_00396EB0` | Matching | 100.00% | 12 |
| `func_00396EC0` | Matching | 100.00% | 12 |
| `func_00396ED0` | Matching | 100.00% | 12 |
| `func_00396EE0` | Matching | 100.00% | 12 |
| `func_00396EF0` | Matching | 100.00% | 12 |
| `func_00396F00` | Matching | 100.00% | 12 |
| `func_00396F10` | Matching | 100.00% | 12 |
| `func_00396F20` | Matching | 100.00% | 12 |
| `func_00396F30` | Matching | 100.00% | 12 |
| `func_00396F40` | Matching | 100.00% | 12 |
| `func_00396F50` | Matching | 100.00% | 12 |
| `func_00396F60` | Matching | 100.00% | 12 |
| `func_00396F70` | Matching | 100.00% | 12 |
| `func_00396F80` | Matching | 100.00% | 12 |
| `func_00396F90` | Matching | 100.00% | 12 |
| `func_00396FA0` | Matching | 100.00% | 12 |
| `func_00396FB0` | Matching | 100.00% | 12 |
| `func_00396FC0` | Matching | 100.00% | 12 |
| `func_00396FD0` | Matching | 100.00% | 12 |
| `func_00396FE0` | Matching | 100.00% | 84 |
| `func_00397038` | Matching | 100.00% | 16 |
| `func_00397048` | Matching | 100.00% | 16 |
| `func_00397058` | Matching | 100.00% | 16 |
| `func_00397068` | Matching | 100.00% | 16 |
| `func_00397078` | Matching | 100.00% | 12 |
| `func_00397088` | Matching | 100.00% | 12 |
| `func_00397098` | Matching | 100.00% | 12 |
| `func_003970A8` | Matching | 100.00% | 12 |
| `func_003970B8` | Matching | 100.00% | 12 |
| `func_003970C8` | Matching | 100.00% | 12 |
| `func_003970D8` | Matching | 100.00% | 12 |
| `func_003970E8` | Matching | 100.00% | 12 |
| `func_00397138(void*, int)` | Matching | 100.00% | 8 |
| `func_003948D0` | Matching | 99.80% | 204 |
| `func_003970F8(void*)` | Matching | 99.38% | 32 |
| `func_00397118(void*)` | Matching | 99.38% | 32 |
| `func_00394AD8` | Matching | 99.35% | 92 |
| `func_00396110` | Matching | 99.00% | 20 |

### `render/graphicsman`

46 matching, 0 partial, 13 not started (59 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cGraphicsMan_AddBlendedMatrix` | Matching | 100.00% | 404 |
| `func_00369A78` | Matching | 100.00% | 428 |
| `func_00369C28` | Matching | 100.00% | 136 |
| `func_00369CB0` | Matching | 100.00% | 68 |
| `func_00369FF0(void*)` | Matching | 100.00% | 8 |
| `func_00369FF8` | Matching | 100.00% | 40 |
| `func_0036A020` | Matching | 100.00% | 40 |
| `func_0036A190(void*, int)` | Matching | 100.00% | 28 |
| `func_0036A1B0(void *, void *)` | Matching | 100.00% | 16 |
| `func_0036A1C0` | Matching | 100.00% | 36 |
| `func_0036A1E8` | Matching | 100.00% | 168 |
| `func_0036A290` | Matching | 100.00% | 44 |
| `func_0036A2C0` | Matching | 100.00% | 236 |
| `func_0036A3B0` | Matching | 100.00% | 44 |
| `func_0036A3E0` | Matching | 100.00% | 68 |
| `func_0036AA60` | Matching | 100.00% | 316 |
| `func_0036ABA0` | Matching | 100.00% | 92 |
| `func_0036AE20` | Matching | 100.00% | 820 |
| `func_0036C740` | Matching | 100.00% | 76 |
| `func_0036CBF8` | Matching | 100.00% | 192 |
| `func_0036CCB8` | Matching | 100.00% | 328 |
| `func_0036CE00` | Matching | 100.00% | 36 |
| `func_0036CE28` | Matching | 100.00% | 32 |
| `func_0036CE58` | Matching | 100.00% | 36 |
| `func_0036CE80` | Matching | 100.00% | 120 |
| `func_0036CEF8` | Matching | 100.00% | 172 |
| `func_0036CFA8` | Matching | 100.00% | 92 |
| `func_0036D008` | Matching | 100.00% | 20 |
| `func_0036D1F0` | Matching | 100.00% | 296 |
| `func_0036D318` | Matching | 100.00% | 188 |
| `func_0036D3D8` | Matching | 100.00% | 16 |
| `func_0036D3E8` | Matching | 100.00% | 24 |
| `func_0036D400` | Matching | 100.00% | 36 |
| `func_00370018` | Matching | 100.00% | 64 |
| `func_00370708` | Matching | 100.00% | 80 |
| `func_00370758` | Matching | 100.00% | 48 |
| `func_00370888` | Matching | 100.00% | 52 |
| `func_003708C0` | Matching | 100.00% | 488 |
| `func_00370AA8` | Matching | 100.00% | 76 |
| `func_00370B60` | Matching | 100.00% | 164 |
| `func_00370C08` | Matching | 100.00% | 84 |
| `func_0036AC00` | Matching | 99.96% | 544 |
| `func_003705E0` | Matching | 99.93% | 292 |
| `func_00370788` | Matching | 99.92% | 256 |
| `func_00370AF8` | Matching | 99.80% | 100 |
| `func_0036CE48` | Matching | 98.75% | 16 |

### `render/irradiance`

2 matching, 0 partial, 0 not started (2 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cIrradianceDataBase_Load` | Matching | 100.00% | 220 |
| `func_0038ADB0` | Matching | 100.00% | 96 |

### `render/lightman`

61 matching, 0 partial, 2 not started (63 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cLightMan_construct()` | Matching | 100.00% | 80 |
| `func_0038DC20` | Matching | 100.00% | 8 |
| `func_0038DC28` | Matching | 100.00% | 28 |
| `func_0038DC48` | Matching | 100.00% | 8 |
| `func_0038DC50(void*)` | Matching | 100.00% | 8 |
| `func_0038DC58(void*)` | Matching | 100.00% | 8 |
| `func_0038DC60(void*)` | Matching | 100.00% | 8 |
| `func_0038DC68(void*)` | Matching | 100.00% | 8 |
| `func_0038DC70` | Matching | 100.00% | 632 |
| `func_0038DEE8` | Matching | 100.00% | 80 |
| `func_0038DF38` | Matching | 100.00% | 96 |
| `func_0038DF98` | Matching | 100.00% | 112 |
| `func_0038E008` | Matching | 100.00% | 160 |
| `func_0038E0A8` | Matching | 100.00% | 112 |
| `func_0038E118` | Matching | 100.00% | 232 |
| `func_0038E200` | Matching | 100.00% | 232 |
| `func_0038E2E8` | Matching | 100.00% | 384 |
| `func_0038E468` | Matching | 100.00% | 384 |
| `func_0038E5E8` | Matching | 100.00% | 332 |
| `func_0038E738` | Matching | 100.00% | 328 |
| `func_0038E880` | Matching | 100.00% | 480 |
| `func_0038EA60` | Matching | 100.00% | 476 |
| `func_0038EC40` | Matching | 100.00% | 332 |
| `func_0038ED90` | Matching | 100.00% | 232 |
| `func_0038EE78` | Matching | 100.00% | 1068 |
| `func_0038F2A8` | Matching | 100.00% | 88 |
| `func_0038F300` | Matching | 100.00% | 352 |
| `func_0038F460` | Matching | 100.00% | 152 |
| `func_0038F4F8` | Matching | 100.00% | 100 |
| `func_0038F560` | Matching | 100.00% | 52 |
| `func_0038F598` | Matching | 100.00% | 208 |
| `func_0038F668` | Matching | 100.00% | 60 |
| `func_0038F6A8` | Matching | 100.00% | 36 |
| `func_0038F6D0` | Matching | 100.00% | 56 |
| `func_0038F708` | Matching | 100.00% | 44 |
| `func_0038F738` | Matching | 100.00% | 44 |
| `func_0038F768` | Matching | 100.00% | 68 |
| `func_0038F7B0` | Matching | 100.00% | 68 |
| `func_0038F7F8(void*)` | Matching | 100.00% | 8 |
| `func_0038F800(void*)` | Matching | 100.00% | 28 |
| `func_0038F930` | Matching | 100.00% | 140 |
| `func_0038FC48` | Matching | 100.00% | 644 |
| `func_0038FED0` | Matching | 100.00% | 712 |
| `func_00390198` | Matching | 100.00% | 704 |
| `func_00390458` | Matching | 100.00% | 68 |
| `func_003904A0` | Matching | 100.00% | 328 |
| `func_00390C20` | Matching | 100.00% | 60 |
| `func_00390C60` | Matching | 100.00% | 616 |
| `func_00390EC8` | Matching | 100.00% | 48 |
| `func_00390EF8` | Matching | 100.00% | 40 |
| `func_00390F20` | Matching | 100.00% | 904 |
| `func_003912A8` | Matching | 100.00% | 184 |
| `func_00391360` | Matching | 100.00% | 184 |
| `func_00391418` | Matching | 100.00% | 100 |
| `func_00391480` | Matching | 100.00% | 120 |
| `func_003914F8` | Matching | 100.00% | 12 |
| `func_00391508` | Matching | 100.00% | 220 |
| `func_003915E8` | Matching | 100.00% | 216 |
| `func_003916C0` | Matching | 100.00% | 68 |
| `func_00391708` | Matching | 100.00% | 124 |
| `func_0038F9C0` | Matching | 99.97% | 644 |

### `render/particle`

171 matching, 0 partial, 44 not started (215 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBaseClass_DynamicEmitter_Allocate` | Matching | 100.00% | 148 |
| `func_00370CF8` | Matching | 100.00% | 104 |
| `cBaseClass_DynamicEmitter_reset` | Matching | 100.00% | 100 |
| `func_00370DC8` | Matching | 100.00% | 772 |
| `func_003710D0` | Matching | 100.00% | 404 |
| `func_00371268` | Matching | 100.00% | 80 |
| `func_003712B8` | Matching | 100.00% | 92 |
| `func_00371318` | Matching | 100.00% | 104 |
| `func_00371380` | Matching | 100.00% | 308 |
| `func_003714B8` | Matching | 100.00% | 60 |
| `func_003714F8` | Matching | 100.00% | 76 |
| `cDynamicColourEmitter_Allocate` | Matching | 100.00% | 100 |
| `func_003715B0` | Matching | 100.00% | 76 |
| `cDynamicColourEmitter_reset` | Matching | 100.00% | 136 |
| `func_00371688` | Matching | 100.00% | 308 |
| `func_003717C0` | Matching | 100.00% | 292 |
| `func_003718E8` | Matching | 100.00% | 84 |
| `func_00371940` | Matching | 100.00% | 276 |
| `func_00371A58` | Matching | 100.00% | 228 |
| `func_00371B40` | Matching | 100.00% | 228 |
| `func_00371C28` | Matching | 100.00% | 228 |
| `func_00371D10` | Matching | 100.00% | 196 |
| `func_00371DD8` | Matching | 100.00% | 196 |
| `func_00371EA0` | Matching | 100.00% | 244 |
| `func_00371F98` | Matching | 100.00% | 252 |
| `func_00372098` | Matching | 100.00% | 84 |
| `func_003720F0` | Matching | 100.00% | 168 |
| `func_00372348` | Matching | 100.00% | 436 |
| `func_00372500(void*)` | Matching | 100.00% | 28 |
| `func_00372520` | Matching | 100.00% | 144 |
| `func_003725B0` | Matching | 100.00% | 176 |
| `func_00372660` | Matching | 100.00% | 100 |
| `func_00372AA0` | Matching | 100.00% | 124 |
| `func_00372B20` | Matching | 100.00% | 16 |
| `func_00372B30` | Matching | 100.00% | 68 |
| `func_003737D0` | Matching | 100.00% | 512 |
| `func_003739D0` | Matching | 100.00% | 600 |
| `func_00373C28` | Matching | 100.00% | 640 |
| `func_00373EA8` | Matching | 100.00% | 724 |
| `func_00374180` | Matching | 100.00% | 280 |
| `func_00374298` | Matching | 100.00% | 424 |
| `func_00374440` | Matching | 100.00% | 216 |
| `func_00374518` | Matching | 100.00% | 648 |
| `func_003747A0` | Matching | 100.00% | 740 |
| `func_00374A88` | Matching | 100.00% | 84 |
| `func_00374AE0` | Matching | 100.00% | 84 |
| `func_00374B38` | Matching | 100.00% | 344 |
| `func_00374C90` | Matching | 100.00% | 24 |
| `func_00374CA8` | Matching | 100.00% | 52 |
| `func_00374CE0` | Matching | 100.00% | 28 |
| `func_00375890` | Matching | 100.00% | 104 |
| `func_003758F8(void*)` | Matching | 100.00% | 28 |
| `func_00375918` | Matching | 100.00% | 120 |
| `func_00375990` | Matching | 100.00% | 84 |
| `func_003759E8(void*)` | Matching | 100.00% | 20 |
| `func_00375A00(void*)` | Matching | 100.00% | 8 |
| `func_00375A08` | Matching | 100.00% | 52 |
| `func_00376268` | Matching | 100.00% | 140 |
| `func_003762F8` | Matching | 100.00% | 368 |
| `func_00376468` | Matching | 100.00% | 88 |
| `func_00376560` | Matching | 100.00% | 20 |
| `func_00376578` | Matching | 100.00% | 64 |
| `func_003765B8` | Matching | 100.00% | 432 |
| `func_00376768` | Matching | 100.00% | 460 |
| `func_00376938` | Matching | 100.00% | 312 |
| `func_00376A70` | Matching | 100.00% | 288 |
| `func_00376B90` | Matching | 100.00% | 124 |
| `func_00376C10` | Matching | 100.00% | 24 |
| `func_00376C28` | Matching | 100.00% | 48 |
| `func_00377950` | Matching | 100.00% | 144 |
| `func_003779E0` | Matching | 100.00% | 48 |
| `func_00377CF0` | Matching | 100.00% | 1196 |
| `func_0037A430` | Matching | 100.00% | 272 |
| `func_0037A540` | Matching | 100.00% | 204 |
| `func_0037BA50` | Matching | 100.00% | 188 |
| `func_0037BC40` | Matching | 100.00% | 244 |
| `func_0037BD38` | Matching | 100.00% | 92 |
| `func_0037BD98` | Matching | 100.00% | 1020 |
| `func_0037C198` | Matching | 100.00% | 984 |
| `func_0037C570` | Matching | 100.00% | 196 |
| `func_0037C638` | Matching | 100.00% | 228 |
| `func_0037C720` | Matching | 100.00% | 80 |
| `func_0037C770` | Matching | 100.00% | 76 |
| `func_0037C7C0` | Matching | 100.00% | 72 |
| `func_0037C808(void*)` | Matching | 100.00% | 36 |
| `func_0037C830` | Matching | 100.00% | 112 |
| `func_0037C8A0` | Matching | 100.00% | 28 |
| `func_0037CAF8` | Matching | 100.00% | 88 |
| `func_0037CB50` | Matching | 100.00% | 64 |
| `func_0037CB90` | Matching | 100.00% | 52 |
| `func_0037CBC8(void*)` | Matching | 100.00% | 28 |
| `func_0037CBE8` | Matching | 100.00% | 68 |
| `func_0037CC30` | Matching | 100.00% | 100 |
| `func_0037D090(void*)` | Matching | 100.00% | 28 |
| `func_0037D0B0` | Matching | 100.00% | 612 |
| `func_0037D318` | Matching | 100.00% | 44 |
| `func_0037D348` | Matching | 100.00% | 260 |
| `func_0037D450` | Matching | 100.00% | 532 |
| `func_0037D668` | Matching | 100.00% | 208 |
| `func_0037D738(void*)` | Matching | 100.00% | 28 |
| `func_0037D758` | Matching | 100.00% | 168 |
| `func_0037D800` | Matching | 100.00% | 260 |
| `func_0037D908` | Matching | 100.00% | 48 |
| `func_0037D938` | Matching | 100.00% | 48 |
| `func_0037D968` | Matching | 100.00% | 636 |
| `func_0037DBE8` | Matching | 100.00% | 308 |
| `func_0037DD20` | Matching | 100.00% | 360 |
| `func_0037DE88` | Matching | 100.00% | 88 |
| `func_0037DEE0` | Matching | 100.00% | 96 |
| `func_0037DF40` | Matching | 100.00% | 68 |
| `func_0037DF88` | Matching | 100.00% | 180 |
| `func_0037E040` | Matching | 100.00% | 88 |
| `func_0037E098` | Matching | 100.00% | 136 |
| `func_0037E120` | Matching | 100.00% | 280 |
| `func_00380518` | Matching | 100.00% | 644 |
| `func_003807A0` | Matching | 100.00% | 1344 |
| `func_00381310` | Matching | 100.00% | 992 |
| `func_003816F0` | Matching | 100.00% | 992 |
| `func_00381F10` | Matching | 100.00% | 604 |
| `func_003825C0` | Matching | 100.00% | 52 |
| `func_003825F8` | Matching | 100.00% | 84 |
| `func_00382650` | Matching | 100.00% | 52 |
| `func_00382688` | Matching | 100.00% | 88 |
| `func_003826E0` | Matching | 100.00% | 76 |
| `func_00382730` | Matching | 100.00% | 12 |
| `func_00382740(void*)` | Matching | 100.00% | 28 |
| `func_00383770` | Matching | 100.00% | 148 |
| `func_00384D98` | Matching | 100.00% | 36 |
| `func_00384DC0` | Matching | 100.00% | 140 |
| `func_00384E50` | Matching | 100.00% | 384 |
| `func_00384FD0` | Matching | 100.00% | 212 |
| `func_003850A8` | Matching | 100.00% | 140 |
| `func_00385260` | Matching | 100.00% | 48 |
| `func_00385290` | Matching | 100.00% | 84 |
| `func_00385A38` | Matching | 100.00% | 104 |
| `func_00385AA0` | Matching | 100.00% | 252 |
| `func_00385BA0` | Matching | 100.00% | 60 |
| `func_00385BE0` | Matching | 100.00% | 48 |
| `func_00385C10` | Matching | 100.00% | 672 |
| `func_003865D8` | Matching | 100.00% | 16 |
| `func_003865E8` | Matching | 100.00% | 84 |
| `func_00386640` | Matching | 100.00% | 72 |
| `func_00386688` | Matching | 100.00% | 84 |
| `func_003866E0(void*, int, int)` | Matching | 100.00% | 12 |
| `func_00386CF0` | Matching | 100.00% | 28 |
| `func_00386D10` | Matching | 100.00% | 188 |
| `func_00386DD0` | Matching | 100.00% | 164 |
| `func_003883B8` | Matching | 100.00% | 548 |
| `func_00389098` | Matching | 100.00% | 128 |
| `func_00389118` | Matching | 100.00% | 72 |
| `func_00389160` | Matching | 100.00% | 256 |
| `func_00389260` | Matching | 100.00% | 44 |
| `func_00389290` | Matching | 100.00% | 116 |
| `func_00389558` | Matching | 100.00% | 52 |
| `func_00389590` | Matching | 100.00% | 144 |
| `func_00389620` | Matching | 100.00% | 60 |
| `func_00389660` | Matching | 100.00% | 92 |
| `func_003896C0` | Matching | 100.00% | 108 |
| `func_00389730` | Matching | 100.00% | 112 |
| `func_003897A0` | Matching | 100.00% | 112 |
| `func_00389810` | Matching | 100.00% | 48 |
| `func_00389C38` | Matching | 100.00% | 128 |
| `func_0038A530` | Matching | 100.00% | 232 |
| `func_0038A618` | Matching | 100.00% | 144 |
| `func_0038ABF8` | Matching | 100.00% | 36 |
| `func_0038AC20` | Matching | 100.00% | 48 |
| `func_0038AC50` | Matching | 100.00% | 124 |
| `func_00377278` | Matching | 99.92% | 480 |
| `func_00380380` | Matching | 99.90% | 408 |
| `func_00382170` | Matching | 99.86% | 1104 |
| `func_00389520` | Matching | 99.62% | 52 |

### `render/ps2bezierman`

2 matching, 0 partial, 0 not started (2 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPSPBezierMan_cPSPBezierMan(void*)` | Matching | 100.00% | 76 |
| `func_0038AEB0` | Matching | 100.00% | 72 |

### `render/ps2graphicsman`

31 matching, 0 partial, 1 not started (32 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPSPGraphicsMan_NewNonBindTexID` | Matching | 100.00% | 116 |
| `func_003671C8` | Matching | 100.00% | 100 |
| `func_00367230` | Matching | 100.00% | 44 |
| `cPSPGraphicsMan_NewBindTexID` | Matching | 100.00% | 92 |
| `func_003672C0` | Matching | 100.00% | 76 |
| `func_00367310` | Matching | 100.00% | 44 |
| `func_00367340(void*, int, int)` | Matching | 100.00% | 32 |
| `func_00367360` | Matching | 100.00% | 108 |
| `func_003673D0(void*)` | Matching | 100.00% | 8 |
| `func_003673D8` | Matching | 100.00% | 100 |
| `func_00367440` | Matching | 100.00% | 1824 |
| `func_00367B60` | Matching | 100.00% | 92 |
| `func_00367BC0` | Matching | 100.00% | 272 |
| `func_00367CD0` | Matching | 100.00% | 80 |
| `func_00367D20` | Matching | 100.00% | 148 |
| `func_00367DB8` | Matching | 100.00% | 348 |
| `func_00367F18` | Matching | 100.00% | 544 |
| `func_00368138` | Matching | 100.00% | 56 |
| `func_003684F0` | Matching | 100.00% | 364 |
| `func_00368970` | Matching | 100.00% | 1832 |
| `func_00369098` | Matching | 100.00% | 148 |
| `func_00369130` | Matching | 100.00% | 124 |
| `func_003691B0` | Matching | 100.00% | 72 |
| `func_003691F8` | Matching | 100.00% | 988 |
| `func_003695D8` | Matching | 100.00% | 52 |
| `func_00369610` | Matching | 100.00% | 124 |
| `func_00369690` | Matching | 100.00% | 56 |
| `func_003696C8` | Matching | 100.00% | 456 |
| `func_00369890(void*, int, int)` | Matching | 100.00% | 16 |
| `func_003698A0` | Matching | 100.00% | 60 |
| `func_00368660` | Matching | 99.97% | 784 |

### `render/ps2lightman`

2 matching, 0 partial, 0 not started (2 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPSPLightMan_cPSPLightMan(cPSPLightMan*)` | Matching | 100.00% | 24 |
| `func_0038AE28` | Matching | 100.00% | 52 |

### `replay/frameptr`

37 matching, 0 partial, 2 not started (39 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cReplayFramePtr_initBlock` | Matching | 100.00% | 72 |
| `func_0026E950` | Matching | 100.00% | 24 |
| `func_0026E968` | Matching | 100.00% | 68 |
| `cReplayFramePtr_readRewind(cReplayFramePtr*)` | Matching | 100.00% | 12 |
| `func_0026E9C0(void*)` | Matching | 100.00% | 16 |
| `func_0026E9D0` | Matching | 100.00% | 76 |
| `func_0026EA20` | Matching | 100.00% | 68 |
| `func_0026EA68` | Matching | 100.00% | 80 |
| `func_0026EAB8` | Matching | 100.00% | 140 |
| `func_0026EB48` | Matching | 100.00% | 192 |
| `func_0026EC08` | Matching | 100.00% | 208 |
| `func_0026ECD8` | Matching | 100.00% | 76 |
| `func_0026ED28` | Matching | 100.00% | 96 |
| `func_0026ED88(void*)` | Matching | 100.00% | 8 |
| `cReplayFramePtr_getFrameBlock()` | Matching | 100.00% | 8 |
| `func_0026ED98` | Matching | 100.00% | 60 |
| `func_0026EDD8` | Matching | 100.00% | 140 |
| `func_0026EE68` | Matching | 100.00% | 52 |
| `func_0026EEA0` | Matching | 100.00% | 144 |
| `func_0026EF30` | Matching | 100.00% | 76 |
| `func_0026EF80` | Matching | 100.00% | 56 |
| `func_0026EFB8` | Matching | 100.00% | 208 |
| `func_0026F088` | Matching | 100.00% | 244 |
| `func_0026F180` | Matching | 100.00% | 164 |
| `func_0026F428` | Matching | 100.00% | 108 |
| `func_0026F498(void*)` | Matching | 100.00% | 8 |
| `func_0026F4A0(void*, int)` | Matching | 100.00% | 8 |
| `func_0026F4A8` | Matching | 100.00% | 784 |
| `func_0026F7B8` | Matching | 100.00% | 60 |
| `func_0026F7F8` | Matching | 100.00% | 84 |
| `func_0026F850` | Matching | 100.00% | 68 |
| `func_0026F898(void*, int)` | Matching | 100.00% | 8 |
| `func_0026F8A0` | Matching | 100.00% | 220 |
| `func_0026F980` | Matching | 100.00% | 204 |
| `func_0026FA50` | Matching | 100.00% | 36 |
| `func_0026FA78` | Matching | 100.00% | 272 |
| `func_0026FE50` | Matching | 100.00% | 544 |

### `replay/playbackman`

40 matching, 0 partial, 3 not started (43 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPlaybackMan_cPlaybackMan` | Matching | 100.00% | 300 |
| `func_0026C588` | Matching | 100.00% | 112 |
| `cPlaybackMan_update` | Matching | 100.00% | 240 |
| `cPlaybackMan_initLocation` | Matching | 100.00% | 432 |
| `func_0026C898` | Matching | 100.00% | 252 |
| `func_0026C998` | Matching | 100.00% | 88 |
| `func_0026C9F0` | Matching | 100.00% | 160 |
| `func_0026CA90` | Matching | 100.00% | 104 |
| `func_0026CAF8` | Matching | 100.00% | 184 |
| `func_0026CBB0(void*)` | Matching | 100.00% | 8 |
| `func_0026CBB8` | Matching | 100.00% | 92 |
| `func_0026CC18` | Matching | 100.00% | 44 |
| `func_0026CC48` | Matching | 100.00% | 216 |
| `func_0026CD20` | Matching | 100.00% | 116 |
| `func_0026CD98` | Matching | 100.00% | 52 |
| `func_0026CDD0(void*)` | Matching | 100.00% | 40 |
| `func_0026CDF8` | Matching | 100.00% | 88 |
| `func_0026CFE8` | Matching | 100.00% | 56 |
| `func_0026D020` | Matching | 100.00% | 128 |
| `func_0026D0A0` | Matching | 100.00% | 72 |
| `func_0026D0E8` | Matching | 100.00% | 68 |
| `func_0026D130` | Matching | 100.00% | 56 |
| `func_0026D168(void*)` | Matching | 100.00% | 16 |
| `func_0026D178` | Matching | 100.00% | 176 |
| `func_0026D228` | Matching | 100.00% | 132 |
| `func_0026D2B0` | Matching | 100.00% | 220 |
| `func_0026D390` | Matching | 100.00% | 144 |
| `func_0026D420` | Matching | 100.00% | 184 |
| `func_0026D4D8` | Matching | 100.00% | 124 |
| `func_0026D558` | Matching | 100.00% | 140 |
| `func_0026D5E8` | Matching | 100.00% | 60 |
| `func_0026D628` | Matching | 100.00% | 80 |
| `func_0026D678` | Matching | 100.00% | 184 |
| `func_0026D730(void*, int, int)` | Matching | 100.00% | 16 |
| `func_0026D740(void*)` | Matching | 100.00% | 28 |
| `func_0026D760` | Matching | 100.00% | 112 |
| `func_0026D7D0` | Matching | 100.00% | 72 |
| `func_0026D818` | Matching | 100.00% | 368 |
| `func_0026DB88` | Matching | 100.00% | 68 |
| `func_0026DBD0` | Matching | 100.00% | 28 |

### `replay/replay`

22 matching, 0 partial, 0 not started (22 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cReplay_restoreFrame` | Matching | 100.00% | 464 |
| `cReplay_restoreBucket` | Matching | 100.00% | 152 |
| `func_0026DE58` | Matching | 100.00% | 124 |
| `cReplay_restoreObject` | Matching | 100.00% | 1124 |
| `cReplay_restoreDeadBucket` | Matching | 100.00% | 260 |
| `func_0026E448(void*)` | Matching | 100.00% | 28 |
| `func_0026E468` | Matching | 100.00% | 36 |
| `func_0026E490` | Matching | 100.00% | 36 |
| `func_0026E4B8` | Matching | 100.00% | 112 |
| `func_0026E528` | Matching | 100.00% | 60 |
| `func_0026E568` | Matching | 100.00% | 60 |
| `func_0026E5A8(void*)` | Matching | 100.00% | 20 |
| `func_0026E5C0(void*)` | Matching | 100.00% | 16 |
| `func_0026E5D0` | Matching | 100.00% | 56 |
| `func_0026E608` | Matching | 100.00% | 104 |
| `func_0026E670` | Matching | 100.00% | 44 |
| `func_0026E6A0` | Matching | 100.00% | 64 |
| `func_0026E6E0` | Matching | 100.00% | 276 |
| `func_0026E7F8(void*)` | Matching | 100.00% | 8 |
| `func_0026E800` | Matching | 100.00% | 52 |
| `func_0026E838` | Matching | 100.00% | 168 |
| `func_0026E8E0(void*)` | Matching | 100.00% | 36 |

### `replay/replaycache`

192 matching, 0 partial, 6 not started (198 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cReplay_addCache` | Matching | 100.00% | 104 |
| `func_002700D8` | Matching | 100.00% | 88 |
| `func_00270130` | Matching | 100.00% | 108 |
| `func_002701A0` | Matching | 100.00% | 148 |
| `func_00270238` | Matching | 100.00% | 72 |
| `func_002702F8` | Matching | 100.00% | 128 |
| `func_00270378` | Matching | 100.00% | 120 |
| `func_002703F0` | Matching | 100.00% | 324 |
| `func_00270538` | Matching | 100.00% | 112 |
| `func_002705A8(void*)` | Matching | 100.00% | 8 |
| `func_002705B0` | Matching | 100.00% | 120 |
| `func_00270658` | Matching | 100.00% | 24 |
| `func_00270670` | Matching | 100.00% | 68 |
| `func_002706B8` | Matching | 100.00% | 56 |
| `cReplay_stopAutoReplay(void*)` | Matching | 100.00% | 64 |
| `func_00270730` | Matching | 100.00% | 172 |
| `func_002707E0` | Matching | 100.00% | 144 |
| `func_00270870` | Matching | 100.00% | 128 |
| `func_002708F0` | Matching | 100.00% | 128 |
| `func_002709D8` | Matching | 100.00% | 216 |
| `func_00270AB0` | Matching | 100.00% | 216 |
| `func_00270BD8` | Matching | 100.00% | 104 |
| `func_00270C40` | Matching | 100.00% | 24 |
| `func_00270C58` | Matching | 100.00% | 144 |
| `func_00270DE0` | Matching | 100.00% | 56 |
| `func_00270E18` | Matching | 100.00% | 80 |
| `func_00270E68` | Matching | 100.00% | 108 |
| `func_00270ED8(void*)` | Matching | 100.00% | 28 |
| `func_00270EF8(void*)` | Matching | 100.00% | 28 |
| `func_00270F18(void*)` | Matching | 100.00% | 8 |
| `func_00270F20` | Matching | 100.00% | 88 |
| `func_00270F78` | Matching | 100.00% | 68 |
| `func_00270FC0` | Matching | 100.00% | 152 |
| `func_00271058` | Matching | 100.00% | 76 |
| `func_002710A8` | Matching | 100.00% | 380 |
| `func_00271228` | Matching | 100.00% | 152 |
| `func_002712C0` | Matching | 100.00% | 56 |
| `func_002712F8` | Matching | 100.00% | 76 |
| `func_00271348` | Matching | 100.00% | 56 |
| `func_00271380` | Matching | 100.00% | 352 |
| `func_002714E0` | Matching | 100.00% | 48 |
| `func_00271510` | Matching | 100.00% | 268 |
| `func_00271620` | Matching | 100.00% | 100 |
| `func_00271688` | Matching | 100.00% | 100 |
| `func_002716F0(void*)` | Matching | 100.00% | 24 |
| `func_00271708` | Matching | 100.00% | 76 |
| `func_002718A8` | Matching | 100.00% | 60 |
| `func_002721D0` | Matching | 100.00% | 48 |
| `func_00272200` | Matching | 100.00% | 16 |
| `func_00272210` | Matching | 100.00% | 8 |
| `func_00272218` | Matching | 100.00% | 12 |
| `func_00272228` | Matching | 100.00% | 12 |
| `func_00272238` | Matching | 100.00% | 8 |
| `func_00272240` | Matching | 100.00% | 8 |
| `func_00272248` | Matching | 100.00% | 8 |
| `func_00272250` | Matching | 100.00% | 8 |
| `func_00272258` | Matching | 100.00% | 48 |
| `func_00272288` | Matching | 100.00% | 52 |
| `func_002722C0(void*)` | Matching | 100.00% | 32 |
| `func_002722E0(void *, void *, void *)` | Matching | 100.00% | 36 |
| `func_00272308` | Matching | 100.00% | 156 |
| `func_002723A8` | Matching | 100.00% | 224 |
| `func_00272488` | Matching | 100.00% | 60 |
| `func_002724C8(void*)` | Matching | 100.00% | 28 |
| `func_002724E8` | Matching | 100.00% | 36 |
| `func_00272510(void*)` | Matching | 100.00% | 28 |
| `func_00272530` | Matching | 100.00% | 28 |
| `func_00272550` | Matching | 100.00% | 28 |
| `func_00272570` | Matching | 100.00% | 68 |
| `func_002725B8` | Matching | 100.00% | 52 |
| `func_002725F0` | Matching | 100.00% | 140 |
| `func_00272680(void*)` | Matching | 100.00% | 36 |
| `func_002726A8` | Matching | 100.00% | 224 |
| `func_00272788` | Matching | 100.00% | 324 |
| `func_002728D0` | Matching | 100.00% | 36 |
| `func_002728F8` | Matching | 100.00% | 60 |
| `func_00272938` | Matching | 100.00% | 112 |
| `func_002729A8` | Matching | 100.00% | 168 |
| `func_00272A50` | Matching | 100.00% | 80 |
| `func_00272AA0` | Matching | 100.00% | 48 |
| `func_00272AD0` | Matching | 100.00% | 48 |
| `func_00272B00` | Matching | 100.00% | 88 |
| `func_00272B58` | Matching | 100.00% | 36 |
| `func_00272B80` | Matching | 100.00% | 80 |
| `func_00272BD0` | Matching | 100.00% | 36 |
| `func_00272BF8` | Matching | 100.00% | 80 |
| `func_00272C48` | Matching | 100.00% | 36 |
| `func_00272C70` | Matching | 100.00% | 80 |
| `func_00272CC0` | Matching | 100.00% | 32 |
| `func_00272CE0` | Matching | 100.00% | 28 |
| `func_00272D00` | Matching | 100.00% | 28 |
| `func_00272D20` | Matching | 100.00% | 28 |
| `func_00272D40` | Matching | 100.00% | 36 |
| `func_00272D68` | Matching | 100.00% | 52 |
| `func_00272DA0` | Matching | 100.00% | 80 |
| `func_00272DF0` | Matching | 100.00% | 204 |
| `func_00272EC0` | Matching | 100.00% | 104 |
| `func_00272F28` | Matching | 100.00% | 280 |
| `func_00273040` | Matching | 100.00% | 124 |
| `func_002730C0` | Matching | 100.00% | 128 |
| `func_00273140` | Matching | 100.00% | 60 |
| `func_00273180` | Matching | 100.00% | 52 |
| `func_002731B8` | Matching | 100.00% | 80 |
| `func_00273208` | Matching | 100.00% | 192 |
| `func_002732C8` | Matching | 100.00% | 104 |
| `func_00273330` | Matching | 100.00% | 172 |
| `func_002733E0` | Matching | 100.00% | 56 |
| `func_00273418` | Matching | 100.00% | 76 |
| `func_00273468` | Matching | 100.00% | 60 |
| `func_002734A8` | Matching | 100.00% | 52 |
| `func_002734E0` | Matching | 100.00% | 80 |
| `func_00273530` | Matching | 100.00% | 252 |
| `func_00273630` | Matching | 100.00% | 104 |
| `func_00273698` | Matching | 100.00% | 328 |
| `func_002737E0` | Matching | 100.00% | 124 |
| `func_00273860` | Matching | 100.00% | 148 |
| `func_002738F8` | Matching | 100.00% | 60 |
| `func_00273938` | Matching | 100.00% | 52 |
| `func_00273970` | Matching | 100.00% | 68 |
| `func_002739B8` | Matching | 100.00% | 72 |
| `func_00273A00` | Matching | 100.00% | 96 |
| `func_00273A60` | Matching | 100.00% | 68 |
| `func_00273AA8` | Matching | 100.00% | 632 |
| `func_00273D20` | Matching | 100.00% | 160 |
| `func_00273DC0` | Matching | 100.00% | 420 |
| `func_00273F68` | Matching | 100.00% | 404 |
| `func_00274100` | Matching | 100.00% | 304 |
| `func_00274230` | Matching | 100.00% | 12 |
| `func_00274240` | Matching | 100.00% | 136 |
| `func_002742C8(void*, int)` | Matching | 100.00% | 20 |
| `func_002742E0` | Matching | 100.00% | 56 |
| `func_00274318` | Matching | 100.00% | 48 |
| `func_00274348(void*)` | Matching | 100.00% | 12 |
| `func_00274358` | Matching | 100.00% | 36 |
| `func_00274380` | Matching | 100.00% | 8 |
| `func_00274388(void*)` | Matching | 100.00% | 12 |
| `func_00274398` | Matching | 100.00% | 8 |
| `func_002743A0` | Matching | 100.00% | 16 |
| `func_002743B0` | Matching | 100.00% | 12 |
| `func_002743C0` | Matching | 100.00% | 8 |
| `func_002743C8(void*)` | Matching | 100.00% | 12 |
| `func_002743D8` | Matching | 100.00% | 16 |
| `func_002743E8` | Matching | 100.00% | 304 |
| `func_00274518` | Matching | 100.00% | 92 |
| `func_00274578` | Matching | 100.00% | 68 |
| `func_002745C0` | Matching | 100.00% | 312 |
| `func_002746F8` | Matching | 100.00% | 268 |
| `func_00274808(void*, float)` | Matching | 100.00% | 8 |
| `func_00274810(void*)` | Matching | 100.00% | 28 |
| `func_00274830` | Matching | 100.00% | 48 |
| `func_00274860` | Matching | 100.00% | 8 |
| `func_00274868` | Matching | 100.00% | 140 |
| `func_002748F8` | Matching | 100.00% | 12 |
| `func_00274908` | Matching | 100.00% | 16 |
| `func_00274918` | Matching | 100.00% | 208 |
| `func_002749E8` | Matching | 100.00% | 32 |
| `func_00274A08` | Matching | 100.00% | 40 |
| `func_00274A30` | Matching | 100.00% | 480 |
| `func_00274C10(void*, int)` | Matching | 100.00% | 12 |
| `func_00274C20` | Matching | 100.00% | 20 |
| `func_00274C38` | Matching | 100.00% | 32 |
| `func_00274C58` | Matching | 100.00% | 8 |
| `func_00274C60` | Matching | 100.00% | 8 |
| `func_00274C68` | Matching | 100.00% | 8 |
| `func_00274C70` | Matching | 100.00% | 152 |
| `func_00274D08` | Matching | 100.00% | 100 |
| `func_00274D70` | Matching | 100.00% | 32 |
| `func_00274D90` | Matching | 100.00% | 76 |
| `func_002751A0` | Matching | 100.00% | 336 |
| `func_002752F0(void*)` | Matching | 100.00% | 8 |
| `func_002752F8(void*)` | Matching | 100.00% | 8 |
| `func_00275300(void*)` | Matching | 100.00% | 8 |
| `func_00275308(void*)` | Matching | 100.00% | 8 |
| `func_00275310(void*)` | Matching | 100.00% | 8 |
| `func_00275318(void*)` | Matching | 100.00% | 12 |
| `func_00275328(void*)` | Matching | 100.00% | 8 |
| `func_00275330(void*)` | Matching | 100.00% | 8 |
| `func_00275338(void*)` | Matching | 100.00% | 8 |
| `func_00275340(void*)` | Matching | 100.00% | 8 |
| `func_00275348(void*)` | Matching | 100.00% | 12 |
| `func_00275358(void*)` | Matching | 100.00% | 8 |
| `func_00275360(void*)` | Matching | 100.00% | 8 |
| `func_00275368(void*)` | Matching | 100.00% | 8 |
| `func_00275370(void*)` | Matching | 100.00% | 8 |
| `func_00275378(void*)` | Matching | 100.00% | 12 |
| `func_00275388(void*)` | Matching | 100.00% | 8 |
| `func_00275390(void*)` | Matching | 100.00% | 8 |
| `func_00275398(void*)` | Matching | 100.00% | 8 |
| `func_002753A0(void*)` | Matching | 100.00% | 8 |
| `func_002753A8(void*)` | Matching | 100.00% | 12 |
| `func_002718E8` | Matching | 99.98% | 2276 |
| `func_00270970` | Matching | 99.81% | 104 |

### `sce/crt0`

0 matching, 0 partial, 4 not started (4 total)

### `scripter/all_in_one_scripter`

70 matching, 0 partial, 0 not started (70 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_002847A8` | Matching | 100.00% | 8 |
| `func_002847B0` | Matching | 100.00% | 8 |
| `func_002847B8` | Matching | 100.00% | 8 |
| `func_002847C0` | Matching | 100.00% | 8 |
| `func_002847C8` | Matching | 100.00% | 8 |
| `func_002847D0` | Matching | 100.00% | 8 |
| `func_002847D8` | Matching | 100.00% | 12 |
| `func_002847E8` | Matching | 100.00% | 8 |
| `func_002847F0` | Matching | 100.00% | 8 |
| `func_002847F8` | Matching | 100.00% | 8 |
| `func_00284800` | Matching | 100.00% | 8 |
| `func_00284808` | Matching | 100.00% | 8 |
| `func_00284810` | Matching | 100.00% | 8 |
| `func_00284818` | Matching | 100.00% | 8 |
| `func_00284820` | Matching | 100.00% | 8 |
| `func_00284828` | Matching | 100.00% | 8 |
| `func_00284830` | Matching | 100.00% | 8 |
| `func_00284838` | Matching | 100.00% | 8 |
| `func_00284840` | Matching | 100.00% | 8 |
| `func_00284848` | Matching | 100.00% | 8 |
| `func_00284850` | Matching | 100.00% | 8 |
| `func_00284858` | Matching | 100.00% | 8 |
| `func_00284860` | Matching | 100.00% | 8 |
| `func_00284868` | Matching | 100.00% | 12 |
| `func_00284878` | Matching | 100.00% | 8 |
| `func_00284880` | Matching | 100.00% | 8 |
| `func_00284888` | Matching | 100.00% | 8 |
| `func_00284890` | Matching | 100.00% | 8 |
| `func_00284898` | Matching | 100.00% | 8 |
| `func_002848A0` | Matching | 100.00% | 48 |
| `func_002848D0` | Matching | 100.00% | 8 |
| `func_002848D8` | Matching | 100.00% | 100 |
| `func_00284940` | Matching | 100.00% | 8 |
| `func_00284948` | Matching | 100.00% | 8 |
| `func_00284950` | Matching | 100.00% | 100 |
| `func_002849B8` | Matching | 100.00% | 8 |
| `func_002849C0` | Matching | 100.00% | 8 |
| `func_002849C8` | Matching | 100.00% | 12 |
| `func_002849D8` | Matching | 100.00% | 8 |
| `func_002849E0` | Matching | 100.00% | 16 |
| `func_002849F0` | Matching | 100.00% | 8 |
| `func_002849F8` | Matching | 100.00% | 44 |
| `func_00284A28` | Matching | 100.00% | 28 |
| `func_00284A48` | Matching | 100.00% | 8 |
| `func_00284A50` | Matching | 100.00% | 8 |
| `func_00284A58` | Matching | 100.00% | 8 |
| `func_00284A60` | Matching | 100.00% | 8 |
| `func_00284A68` | Matching | 100.00% | 8 |
| `func_00284A70` | Matching | 100.00% | 8 |
| `func_00284A78` | Matching | 100.00% | 8 |
| `func_00284A80` | Matching | 100.00% | 8 |
| `func_00284A88` | Matching | 100.00% | 8 |
| `func_00284A90` | Matching | 100.00% | 8 |
| `func_00284A98` | Matching | 100.00% | 8 |
| `func_00284AA0` | Matching | 100.00% | 8 |
| `func_00284AA8` | Matching | 100.00% | 28 |
| `func_00284AC8` | Matching | 100.00% | 8 |
| `func_00284AD0` | Matching | 100.00% | 8 |
| `func_00284AD8` | Matching | 100.00% | 8 |
| `func_00284AE0` | Matching | 100.00% | 8 |
| `func_00284AE8` | Matching | 100.00% | 100 |
| `func_00284B50` | Matching | 100.00% | 8 |
| `func_00284B58` | Matching | 100.00% | 8 |
| `func_00284B60` | Matching | 100.00% | 8 |
| `func_00284B68` | Matching | 100.00% | 8 |
| `func_00284B70` | Matching | 100.00% | 8 |
| `func_00284B78` | Matching | 100.00% | 8 |
| `func_00284B80` | Matching | 100.00% | 32 |
| `func_00284BA0` | Matching | 100.00% | 12 |
| `__sti__all_in_one_scripter_cpp` | Matching | 99.98% | 2372 |

### `scripter/bxscriptengine`

65 matching, 0 partial, 0 not started (65 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBXScriptEngine_SetupBXEngine` | Matching | 100.00% | 240 |
| `func_00282020` | Matching | 100.00% | 144 |
| `func_002820B0` | Matching | 100.00% | 156 |
| `func_00282150` | Matching | 100.00% | 40 |
| `func_00282178` | Matching | 100.00% | 40 |
| `func_002821A0` | Matching | 100.00% | 252 |
| `func_002822A0` | Matching | 100.00% | 148 |
| `func_00282338` | Matching | 100.00% | 88 |
| `func_00282390` | Matching | 100.00% | 92 |
| `func_002823F0` | Matching | 100.00% | 92 |
| `func_00282450` | Matching | 100.00% | 72 |
| `func_00282498` | Matching | 100.00% | 104 |
| `func_00282500` | Matching | 100.00% | 16 |
| `func_00282510` | Matching | 100.00% | 48 |
| `func_00282540` | Matching | 100.00% | 344 |
| `func_00282698` | Matching | 100.00% | 28 |
| `func_002826B8` | Matching | 100.00% | 28 |
| `func_002826D8` | Matching | 100.00% | 72 |
| `func_00282720` | Matching | 100.00% | 112 |
| `func_00282790` | Matching | 100.00% | 8 |
| `func_00282798` | Matching | 100.00% | 92 |
| `func_002827F8` | Matching | 100.00% | 64 |
| `func_00282838` | Matching | 100.00% | 124 |
| `func_002828B8` | Matching | 100.00% | 80 |
| `func_00282908` | Matching | 100.00% | 196 |
| `func_002829D0` | Matching | 100.00% | 72 |
| `func_00282A18` | Matching | 100.00% | 100 |
| `func_00282A80` | Matching | 100.00% | 188 |
| `func_00282B40` | Matching | 100.00% | 72 |
| `func_00282B88` | Matching | 100.00% | 36 |
| `func_00282BB0(void *, void *)` | Matching | 100.00% | 12 |
| `func_00282BC0` | Matching | 100.00% | 32 |
| `func_00282BE0(void *, void *)` | Matching | 100.00% | 12 |
| `func_00282BF0` | Matching | 100.00% | 40 |
| `func_00282C18(void*)` | Matching | 100.00% | 28 |
| `func_00282C38` | Matching | 100.00% | 80 |
| `func_00282C88(void *, void *)` | Matching | 100.00% | 40 |
| `func_00282CB0` | Matching | 100.00% | 28 |
| `func_00282CD0` | Matching | 100.00% | 96 |
| `func_00282D30` | Matching | 100.00% | 116 |
| `func_00282DA8(void*, int)` | Matching | 100.00% | 8 |
| `func_00282DB0(void*, int, int)` | Matching | 100.00% | 28 |
| `func_00282DD0` | Matching | 100.00% | 284 |
| `func_00282EF0` | Matching | 100.00% | 16 |
| `func_00282F00` | Matching | 100.00% | 44 |
| `func_00282F30` | Matching | 100.00% | 44 |
| `func_00282F60(void*)` | Matching | 100.00% | 32 |
| `func_00282F80(void*)` | Matching | 100.00% | 12 |
| `func_00282F90` | Matching | 100.00% | 40 |
| `func_00282FB8` | Matching | 100.00% | 72 |
| `func_00283000` | Matching | 100.00% | 52 |
| `func_00283038` | Matching | 100.00% | 40 |
| `func_00283060` | Matching | 100.00% | 40 |
| `func_00283088` | Matching | 100.00% | 64 |
| `func_002830C8` | Matching | 100.00% | 184 |
| `func_00283180` | Matching | 100.00% | 44 |
| `func_002831B0` | Matching | 100.00% | 80 |
| `func_00283200(void*, int)` | Matching | 100.00% | 36 |
| `func_00283228` | Matching | 100.00% | 108 |
| `func_00283298` | Matching | 100.00% | 64 |
| `func_002832D8` | Matching | 100.00% | 68 |
| `func_00283320` | Matching | 100.00% | 132 |
| `func_002833A8` | Matching | 100.00% | 132 |
| `func_00283430(void*)` | Matching | 100.00% | 16 |
| `func_00283440(void*)` | Matching | 100.00% | 16 |

### `scripter/datamanager`

57 matching, 0 partial, 0 not started (57 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cDataManager_cDataManager` | Matching | 100.00% | 152 |
| `func_002758C0` | Matching | 100.00% | 92 |
| `func_00275920` | Matching | 100.00% | 252 |
| `func_00275A20` | Matching | 100.00% | 232 |
| `func_00275B08` | Matching | 100.00% | 112 |
| `func_00275B78` | Matching | 100.00% | 8 |
| `func_00275B80` | Matching | 100.00% | 20 |
| `func_00275B98` | Matching | 100.00% | 312 |
| `func_00275CD0(void *, void *)` | Matching | 100.00% | 36 |
| `func_00275CF8(void*)` | Matching | 100.00% | 24 |
| `func_00275D10` | Matching | 100.00% | 124 |
| `func_00275D90` | Matching | 100.00% | 72 |
| `func_00275DD8` | Matching | 100.00% | 244 |
| `func_00275ED0` | Matching | 100.00% | 376 |
| `func_00276048` | Matching | 100.00% | 332 |
| `func_00276198` | Matching | 100.00% | 212 |
| `func_00276270` | Matching | 100.00% | 280 |
| `func_00276388` | Matching | 100.00% | 808 |
| `func_002766B0(void*, int)` | Matching | 100.00% | 28 |
| `func_002766D0` | Matching | 100.00% | 408 |
| `func_00276868` | Matching | 100.00% | 304 |
| `func_00276998` | Matching | 100.00% | 108 |
| `func_00276A08` | Matching | 100.00% | 112 |
| `func_00276A78` | Matching | 100.00% | 144 |
| `func_00276B08` | Matching | 100.00% | 140 |
| `func_00276B98` | Matching | 100.00% | 60 |
| `func_00276BD8` | Matching | 100.00% | 208 |
| `func_00276CA8(void*)` | Matching | 100.00% | 28 |
| `func_00276CC8` | Matching | 100.00% | 640 |
| `func_00276F48` | Matching | 100.00% | 276 |
| `func_00277060` | Matching | 100.00% | 96 |
| `func_002770C0` | Matching | 100.00% | 60 |
| `func_00277100` | Matching | 100.00% | 164 |
| `func_002771A8` | Matching | 100.00% | 28 |
| `func_002771C8` | Matching | 100.00% | 128 |
| `func_00277248` | Matching | 100.00% | 80 |
| `func_00277298` | Matching | 100.00% | 32 |
| `func_002772B8(void*)` | Matching | 100.00% | 8 |
| `func_002772C0` | Matching | 100.00% | 80 |
| `func_00277310` | Matching | 100.00% | 140 |
| `func_002773A0` | Matching | 100.00% | 92 |
| `func_00277400` | Matching | 100.00% | 76 |
| `func_00277450` | Matching | 100.00% | 324 |
| `func_00277598` | Matching | 100.00% | 328 |
| `func_002776E0` | Matching | 100.00% | 152 |
| `func_00277778` | Matching | 100.00% | 132 |
| `func_00277800` | Matching | 100.00% | 56 |
| `func_00277838` | Matching | 100.00% | 324 |
| `func_00277980` | Matching | 100.00% | 648 |
| `func_00277C08` | Matching | 100.00% | 464 |
| `func_00277DD8` | Matching | 100.00% | 16 |
| `func_00277DE8` | Matching | 100.00% | 284 |
| `func_00277F08(void*)` | Matching | 100.00% | 24 |
| `func_00277F20` | Matching | 100.00% | 404 |
| `func_002780B8` | Matching | 100.00% | 344 |
| `func_00278210` | Matching | 100.00% | 244 |
| `func_00278308` | Matching | 100.00% | 80 |

### `scripter/scanimmgr`

8 matching, 0 partial, 0 not started (8 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cScriptAnimBankManager_cScriptAnimBankManager` | Matching | 100.00% | 220 |
| `func_00275498` | Matching | 100.00% | 100 |
| `cScriptAnimBankManager_LinkBank` | Matching | 100.00% | 336 |
| `func_00275650` | Matching | 100.00% | 68 |
| `func_00275698` | Matching | 100.00% | 124 |
| `func_00275718` | Matching | 100.00% | 68 |
| `func_00275760` | Matching | 100.00% | 140 |
| `func_002757F0` | Matching | 100.00% | 56 |

### `scripter/scsndmgr`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cScriptSoundBankManager_cScriptSoundBankManager` | Matching | 100.00% | 196 |
| `func_00283518` | Matching | 100.00% | 100 |
| `func_00283580` | Matching | 100.00% | 144 |
| `func_00283610` | Matching | 100.00% | 68 |
| `func_00283658` | Matching | 100.00% | 124 |
| `func_002836D8` | Matching | 100.00% | 68 |
| `func_00283720` | Matching | 100.00% | 64 |
| `func_00283760` | Matching | 100.00% | 56 |
| `func_00283798` | Matching | 100.00% | 44 |
| `func_002837C8` | Matching | 100.00% | 80 |
| `func_00283818` | Matching | 100.00% | 204 |

### `scripter/ssxscriptengine`

181 matching, 0 partial, 6 not started (187 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSSXScriptEngine_Load` | Matching | 100.00% | 568 |
| `func_00278590` | Matching | 100.00% | 384 |
| `func_00278710(void*)` | Matching | 100.00% | 8 |
| `func_00278718(void*)` | Matching | 100.00% | 8 |
| `func_00278720` | Matching | 100.00% | 500 |
| `func_00278918` | Matching | 100.00% | 164 |
| `func_002789C0(void*)` | Matching | 100.00% | 28 |
| `func_002789E0` | Matching | 100.00% | 44 |
| `func_00278A10` | Matching | 100.00% | 72 |
| `func_00278A58` | Matching | 100.00% | 60 |
| `func_00278A98` | Matching | 100.00% | 52 |
| `func_00278AD0` | Matching | 100.00% | 196 |
| `func_00278B98` | Matching | 100.00% | 320 |
| `func_00278CD8` | Matching | 100.00% | 124 |
| `func_00278D58` | Matching | 100.00% | 68 |
| `func_00278DA0` | Matching | 100.00% | 68 |
| `func_00278DE8(void*, int)` | Matching | 100.00% | 8 |
| `func_00278DF0` | Matching | 100.00% | 44 |
| `func_00278E20` | Matching | 100.00% | 48 |
| `func_00278E50` | Matching | 100.00% | 64 |
| `func_00278E90` | Matching | 100.00% | 60 |
| `func_00278ED0` | Matching | 100.00% | 100 |
| `func_00278F38` | Matching | 100.00% | 44 |
| `func_00278F68` | Matching | 100.00% | 140 |
| `func_00278FF8` | Matching | 100.00% | 68 |
| `func_00279040` | Matching | 100.00% | 44 |
| `func_00279070` | Matching | 100.00% | 48 |
| `func_002790A0` | Matching | 100.00% | 88 |
| `func_002790F8` | Matching | 100.00% | 76 |
| `func_00279148` | Matching | 100.00% | 44 |
| `func_00279178` | Matching | 100.00% | 44 |
| `func_002791A8` | Matching | 100.00% | 44 |
| `func_002791D8` | Matching | 100.00% | 68 |
| `func_00279220` | Matching | 100.00% | 40 |
| `func_00279248` | Matching | 100.00% | 40 |
| `func_00279270` | Matching | 100.00% | 40 |
| `func_00279298` | Matching | 100.00% | 68 |
| `func_002792E0` | Matching | 100.00% | 140 |
| `func_00279370` | Matching | 100.00% | 68 |
| `func_002793B8` | Matching | 100.00% | 60 |
| `func_002793F8` | Matching | 100.00% | 48 |
| `func_00279428` | Matching | 100.00% | 48 |
| `func_00279458` | Matching | 100.00% | 44 |
| `func_00279488` | Matching | 100.00% | 84 |
| `func_002794E0` | Matching | 100.00% | 68 |
| `func_00279528` | Matching | 100.00% | 168 |
| `func_002795D0` | Matching | 100.00% | 232 |
| `func_002796B8` | Matching | 100.00% | 104 |
| `func_00279720` | Matching | 100.00% | 124 |
| `func_002797A0` | Matching | 100.00% | 40 |
| `func_002797C8` | Matching | 100.00% | 116 |
| `func_00279840` | Matching | 100.00% | 68 |
| `func_00279888` | Matching | 100.00% | 56 |
| `func_002798C0` | Matching | 100.00% | 284 |
| `func_002799E0` | Matching | 100.00% | 144 |
| `func_00279A70` | Matching | 100.00% | 624 |
| `func_00279CE0` | Matching | 100.00% | 28 |
| `func_00279D00` | Matching | 100.00% | 168 |
| `func_00279DA8` | Matching | 100.00% | 164 |
| `func_00279E50` | Matching | 100.00% | 132 |
| `func_00279ED8(void*)` | Matching | 100.00% | 28 |
| `func_00279EF8(void*)` | Matching | 100.00% | 28 |
| `func_00279F18` | Matching | 100.00% | 444 |
| `func_0027A4A0` | Matching | 100.00% | 456 |
| `func_0027A668(void*)` | Matching | 100.00% | 28 |
| `func_0027A688` | Matching | 100.00% | 40 |
| `func_0027A6B0` | Matching | 100.00% | 112 |
| `func_0027A720` | Matching | 100.00% | 120 |
| `func_0027A798` | Matching | 100.00% | 88 |
| `func_0027A7F0` | Matching | 100.00% | 112 |
| `func_0027A860` | Matching | 100.00% | 400 |
| `func_0027A9F0` | Matching | 100.00% | 140 |
| `func_0027AA80` | Matching | 100.00% | 116 |
| `func_0027AAF8` | Matching | 100.00% | 360 |
| `func_0027AC60` | Matching | 100.00% | 1116 |
| `cSSXScriptEngine_GetScriptFromCategory` | Matching | 100.00% | 420 |
| `func_0027B268` | Matching | 100.00% | 260 |
| `func_0027B370` | Matching | 100.00% | 156 |
| `func_0027B410` | Matching | 100.00% | 164 |
| `func_0027B4B8` | Matching | 100.00% | 108 |
| `func_0027B528` | Matching | 100.00% | 76 |
| `func_0027B578` | Matching | 100.00% | 96 |
| `func_0027B5D8` | Matching | 100.00% | 216 |
| `func_0027B6B0` | Matching | 100.00% | 160 |
| `func_0027B750` | Matching | 100.00% | 500 |
| `func_0027B948` | Matching | 100.00% | 444 |
| `func_0027BB08` | Matching | 100.00% | 624 |
| `func_0027BD78(void*)` | Matching | 100.00% | 24 |
| `func_0027BD90(void *, void *)` | Matching | 100.00% | 36 |
| `func_0027BDB8` | Matching | 100.00% | 408 |
| `func_0027BF50` | Matching | 100.00% | 64 |
| `func_0027BF90` | Matching | 100.00% | 64 |
| `func_0027BFD0` | Matching | 100.00% | 76 |
| `func_0027C020` | Matching | 100.00% | 28 |
| `func_0027C040` | Matching | 100.00% | 12 |
| `func_0027C050` | Matching | 100.00% | 32 |
| `func_0027C070(void*)` | Matching | 100.00% | 8 |
| `func_0027C078(void*)` | Matching | 100.00% | 28 |
| `func_0027C098(void*)` | Matching | 100.00% | 8 |
| `func_0027C0A0` | Matching | 100.00% | 28 |
| `func_0027C0C0` | Matching | 100.00% | 48 |
| `func_0027C0F0` | Matching | 100.00% | 440 |
| `func_0027C2A8(void*)` | Matching | 100.00% | 8 |
| `func_0027C2B0` | Matching | 100.00% | 28 |
| `func_0027C2D0` | Matching | 100.00% | 48 |
| `func_0027C300` | Matching | 100.00% | 440 |
| `func_0027C4B8(void*)` | Matching | 100.00% | 8 |
| `func_0027C4C0` | Matching | 100.00% | 28 |
| `func_0027C4E0` | Matching | 100.00% | 48 |
| `func_0027C510` | Matching | 100.00% | 400 |
| `func_0027C6A0(void*)` | Matching | 100.00% | 8 |
| `func_0027C6A8` | Matching | 100.00% | 28 |
| `func_0027C6C8` | Matching | 100.00% | 48 |
| `func_0027C6F8` | Matching | 100.00% | 400 |
| `func_0027C888(void*)` | Matching | 100.00% | 8 |
| `func_0027C890` | Matching | 100.00% | 28 |
| `func_0027C8B0` | Matching | 100.00% | 48 |
| `func_0027C8E0` | Matching | 100.00% | 116 |
| `func_0027C958(void*)` | Matching | 100.00% | 8 |
| `func_0027C960(void*)` | Matching | 100.00% | 28 |
| `func_0027C980` | Matching | 100.00% | 48 |
| `func_0027C9B0` | Matching | 100.00% | 508 |
| `func_0027CBB0` | Matching | 100.00% | 116 |
| `func_0027CC28` | Matching | 100.00% | 420 |
| `func_0027CDD0` | Matching | 100.00% | 136 |
| `func_0027CE58` | Matching | 100.00% | 80 |
| `func_0027CEA8` | Matching | 100.00% | 224 |
| `func_0027CF88` | Matching | 100.00% | 196 |
| `func_0027D050` | Matching | 100.00% | 112 |
| `func_0027D0C0` | Matching | 100.00% | 172 |
| `func_0027D170` | Matching | 100.00% | 156 |
| `func_0027D210` | Matching | 100.00% | 184 |
| `func_0027D2C8` | Matching | 100.00% | 28 |
| `func_0027D2E8` | Matching | 100.00% | 8 |
| `func_0027D2F0` | Matching | 100.00% | 48 |
| `func_0027D320(void*, int)` | Matching | 100.00% | 16 |
| `func_0027D390` | Matching | 100.00% | 112 |
| `func_0027D400` | Matching | 100.00% | 156 |
| `func_0027D4A0` | Matching | 100.00% | 160 |
| `func_0027D540` | Matching | 100.00% | 24 |
| `func_0027D558` | Matching | 100.00% | 28 |
| `func_0027D578` | Matching | 100.00% | 112 |
| `func_0027D5E8` | Matching | 100.00% | 148 |
| `func_0027D680(void*, int)` | Matching | 100.00% | 8 |
| `func_0027D688` | Matching | 100.00% | 256 |
| `func_0027D788(void*, float)` | Matching | 100.00% | 8 |
| `func_0027D790` | Matching | 100.00% | 92 |
| `func_0027D7F0` | Matching | 100.00% | 44 |
| `func_0027D820` | Matching | 100.00% | 44 |
| `func_0027D850` | Matching | 100.00% | 136 |
| `func_0027D8D8` | Matching | 100.00% | 148 |
| `func_0027F968` | Matching | 100.00% | 140 |
| `func_002803F0` | Matching | 100.00% | 104 |
| `func_00280458` | Matching | 100.00% | 200 |
| `func_00280520(void *, int, void *, void *)` | Matching | 100.00% | 40 |
| `func_00280548(void *, int, void *, void *)` | Matching | 100.00% | 20 |
| `func_00280560` | Matching | 100.00% | 88 |
| `func_002805B8` | Matching | 100.00% | 136 |
| `func_00280640` | Matching | 100.00% | 236 |
| `func_00280730` | Matching | 100.00% | 124 |
| `func_002807B0` | Matching | 100.00% | 296 |
| `func_002808D8` | Matching | 100.00% | 12 |
| `func_00281000(void *, int, void *, void *)` | Matching | 100.00% | 20 |
| `func_00281100` | Matching | 100.00% | 92 |
| `func_00281160(void*, int)` | Matching | 100.00% | 8 |
| `func_00281168(void*)` | Matching | 100.00% | 8 |
| `func_00281170` | Matching | 100.00% | 32 |
| `func_00281190` | Matching | 100.00% | 84 |
| `func_002811E8` | Matching | 100.00% | 244 |
| `func_002812E0` | Matching | 100.00% | 140 |
| `func_00281370` | Matching | 100.00% | 144 |
| `func_00281400` | Matching | 100.00% | 244 |
| `func_002814F8` | Matching | 100.00% | 424 |
| `func_002816A0` | Matching | 100.00% | 864 |
| `func_00281A00` | Matching | 100.00% | 76 |
| `func_00281C40` | Matching | 100.00% | 40 |
| `func_00281C68` | Matching | 100.00% | 532 |
| `func_00281E80` | Matching | 100.00% | 84 |
| `func_00281ED8` | Matching | 100.00% | 88 |
| `func_0027A0D8` | Matching | 100.00% | 968 |
| `func_00281A50` | Matching | 99.83% | 116 |

### `scripter/videngine`

16 matching, 0 partial, 0 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cVidEngine_ReadyVideo` | Matching | 100.00% | 188 |
| `func_002839A8` | Matching | 100.00% | 244 |
| `func_00283AA0` | Matching | 100.00% | 84 |
| `func_00283AF8` | Matching | 100.00% | 128 |
| `func_00283B78` | Matching | 100.00% | 64 |
| `func_00283BB8` | Matching | 100.00% | 40 |
| `func_00283BE0` | Matching | 100.00% | 60 |
| `func_00283C20(void*)` | Matching | 100.00% | 16 |
| `func_00283C30` | Matching | 100.00% | 40 |
| `func_00283C58(void*)` | Matching | 100.00% | 8 |
| `func_00283C60` | Matching | 100.00% | 28 |
| `func_00283C80` | Matching | 100.00% | 164 |
| `func_00283D28` | Matching | 100.00% | 72 |
| `func_00283D70` | Matching | 100.00% | 44 |
| `func_00283DA0` | Matching | 100.00% | 32 |
| `func_00283DC0` | Matching | 100.00% | 156 |

### `seg/seg_1218`

97 matching, 0 partial, 13 not started (110 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00100250` | Matching | 100.00% | 248 |
| `func_00100348` | Matching | 100.00% | 708 |
| `func_00100610` | Matching | 100.00% | 108 |
| `func_00100680` | Matching | 100.00% | 864 |
| `func_001009E0` | Matching | 100.00% | 432 |
| `func_00101310` | Matching | 100.00% | 148 |
| `func_00101688` | Matching | 100.00% | 156 |
| `func_00101728` | Matching | 100.00% | 352 |
| `func_00101888` | Matching | 100.00% | 116 |
| `func_00101900` | Matching | 100.00% | 108 |
| `func_00101970` | Matching | 100.00% | 160 |
| `func_00101A10` | Matching | 100.00% | 20 |
| `func_00101A28` | Matching | 100.00% | 308 |
| `func_001032C0` | Matching | 100.00% | 68 |
| `func_00103308` | Matching | 100.00% | 80 |
| `func_00103358` | Matching | 100.00% | 84 |
| `func_001033B0` | Matching | 100.00% | 72 |
| `func_001033F8` | Matching | 100.00% | 132 |
| `func_00103480` | Matching | 100.00% | 248 |
| `func_00103578` | Matching | 100.00% | 292 |
| `func_001036A0` | Matching | 100.00% | 628 |
| `func_00103918` | Matching | 100.00% | 392 |
| `func_00103AA0` | Matching | 100.00% | 316 |
| `func_00104110` | Matching | 100.00% | 104 |
| `func_00104178` | Matching | 100.00% | 192 |
| `func_00104238` | Matching | 100.00% | 112 |
| `func_001042A8` | Matching | 100.00% | 56 |
| `func_001042E0` | Matching | 100.00% | 116 |
| `func_001045B8` | Matching | 100.00% | 32 |
| `func_00104660` | Matching | 100.00% | 80 |
| `func_001046B0` | Matching | 100.00% | 120 |
| `func_00104A40` | Matching | 100.00% | 28 |
| `func_00104A60` | Matching | 100.00% | 232 |
| `func_00104B48` | Matching | 100.00% | 44 |
| `func_00104B78` | Matching | 100.00% | 28 |
| `func_00104B98` | Matching | 100.00% | 28 |
| `func_00104BB8` | Matching | 100.00% | 28 |
| `func_00104BD8` | Matching | 100.00% | 64 |
| `func_00104C18` | Matching | 100.00% | 28 |
| `func_00104C38` | Matching | 100.00% | 72 |
| `func_00104C80` | Matching | 100.00% | 28 |
| `func_00104CA0` | Matching | 100.00% | 36 |
| `func_00104CC8` | Matching | 100.00% | 44 |
| `func_00104CF8` | Matching | 100.00% | 60 |
| `func_00104D38` | Matching | 100.00% | 20 |
| `func_00104D50` | Matching | 100.00% | 20 |
| `func_00104D68` | Matching | 100.00% | 120 |
| `func_00104DE0` | Matching | 100.00% | 144 |
| `func_00106538` | Matching | 100.00% | 116 |
| `func_00106828` | Matching | 100.00% | 28 |
| `func_00108C28` | Matching | 100.00% | 84 |
| `func_00108E88` | Matching | 100.00% | 256 |
| `func_00108F88` | Matching | 100.00% | 28 |
| `func_0010A768` | Matching | 100.00% | 300 |
| `func_0010A898` | Matching | 100.00% | 76 |
| `func_0010A8E8` | Matching | 100.00% | 116 |
| `func_0010A960` | Matching | 100.00% | 272 |
| `func_0010B590` | Matching | 100.00% | 444 |
| `func_0010B750` | Matching | 100.00% | 64 |
| `func_0010BBF8` | Matching | 100.00% | 160 |
| `func_0010BC98` | Matching | 100.00% | 120 |
| `func_0010BFA8` | Matching | 100.00% | 252 |
| `func_0010C1D0` | Matching | 100.00% | 136 |
| `func_0010C258` | Matching | 100.00% | 200 |
| `func_0010C320` | Matching | 100.00% | 148 |
| `func_0010C3B8` | Matching | 100.00% | 148 |
| `func_0010C450` | Matching | 100.00% | 164 |
| `func_001086B8` | Matching | 99.98% | 908 |
| `func_0010AA70` | Matching | 99.97% | 772 |
| `func_00105398` | Matching | 99.96% | 1056 |
| `func_0010B790` | Matching | 99.96% | 496 |
| `func_00103E28` | Matching | 99.96% | 464 |
| `func_001043F8` | Matching | 99.96% | 448 |
| `func_0010B980` | Matching | 99.95% | 408 |
| `func_00103CC8` | Matching | 99.94% | 352 |
| `func_0010AD78` | Matching | 99.94% | 352 |
| `func_00107E70` | Matching | 99.94% | 1304 |
| `func_0010AED8` | Matching | 99.92% | 528 |
| `func_00108A48` | Matching | 99.92% | 476 |
| `func_00103BE0` | Matching | 99.91% | 232 |
| `func_0010BB18` | Matching | 99.91% | 224 |
| `func_001047F0` | Matching | 99.90% | 208 |
| `func_00104728` | Matching | 99.90% | 200 |
| `func_00100F88` | Matching | 99.89% | 904 |
| `func_00104358` | Matching | 99.88% | 160 |
| `func_00106848` | Matching | 99.87% | 1836 |
| `func_001057B8` | Matching | 99.87% | 1504 |
| `func_001045D8` | Matching | 99.85% | 132 |
| `func_001048C0` | Matching | 99.84% | 124 |
| `func_00104940` | Matching | 99.84% | 124 |
| `func_001049C0` | Matching | 99.84% | 124 |
| `func_00108388` | Matching | 99.80% | 812 |
| `func_00103FF8` | Matching | 99.79% | 280 |
| `func_0010B0E8` | Matching | 99.78% | 360 |
| `func_0010C0A8` | Matching | 99.74% | 152 |
| `func_0010C140` | Matching | 99.72% | 144 |
| `func_00108C80` | Matching | 99.50% | 520 |

### `seg/seg_14B10`

50 matching, 0 partial, 6 not started (56 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAI_setAIState` | Matching | 100.00% | 52 |
| `cAI_forceAIState` | Matching | 100.00% | 212 |
| `func_00113C20` | Matching | 100.00% | 148 |
| `func_00113CB8` | Matching | 100.00% | 8 |
| `func_00113CC0` | Matching | 100.00% | 32 |
| `func_00113CE0` | Matching | 100.00% | 8 |
| `func_00113CE8` | Matching | 100.00% | 8 |
| `func_00113CF0` | Matching | 100.00% | 32 |
| `func_00113D10` | Matching | 100.00% | 8 |
| `func_00113D18` | Matching | 100.00% | 12 |
| `func_00113D28` | Matching | 100.00% | 8 |
| `func_00113D30` | Matching | 100.00% | 8 |
| `func_00113D38` | Matching | 100.00% | 12 |
| `func_00113D48` | Matching | 100.00% | 56 |
| `func_00113D80` | Matching | 100.00% | 8 |
| `func_00113D88` | Matching | 100.00% | 36 |
| `func_00113DB0` | Matching | 100.00% | 100 |
| `func_00113E18` | Matching | 100.00% | 36 |
| `func_00113E40` | Matching | 100.00% | 8 |
| `func_00113E48` | Matching | 100.00% | 8 |
| `func_00113E50` | Matching | 100.00% | 28 |
| `func_00113E70` | Matching | 100.00% | 8 |
| `func_00113E78` | Matching | 100.00% | 8 |
| `func_00113E80` | Matching | 100.00% | 180 |
| `func_00113F38` | Matching | 100.00% | 76 |
| `func_00115AB0` | Matching | 100.00% | 84 |
| `func_00115B08` | Matching | 100.00% | 76 |
| `func_00115B58` | Matching | 100.00% | 492 |
| `func_00116120` | Matching | 100.00% | 172 |
| `func_001161D0` | Matching | 100.00% | 248 |
| `func_001162C8` | Matching | 100.00% | 176 |
| `func_00116378` | Matching | 100.00% | 56 |
| `func_00116930` | Matching | 100.00% | 8 |
| `func_00116938` | Matching | 100.00% | 24 |
| `gGenTrickName` | Matching | 100.00% | 1204 |
| `gGenMonsterTrickReqName` | Matching | 100.00% | 412 |
| `func_00116FA8` | Matching | 100.00% | 16 |
| `func_00117008` | Matching | 100.00% | 60 |
| `func_00117048` | Matching | 100.00% | 96 |
| `func_001170A8` | Matching | 100.00% | 144 |
| `func_00117138` | Matching | 100.00% | 108 |
| `func_001171A8` | Matching | 100.00% | 156 |
| `func_00117248` | Matching | 100.00% | 68 |
| `func_00117290` | Matching | 100.00% | 80 |
| `func_00115640` | Matching | 99.94% | 628 |
| `func_00115168` | Matching | 99.92% | 496 |
| `func_00114CC0` | Matching | 99.92% | 244 |
| `func_00114130` | Matching | 99.83% | 360 |
| `func_001158B8` | Matching | 99.80% | 500 |
| `func_00116FB8` | Matching | 99.75% | 80 |

### `seg/seg_156860`

97 matching, 0 partial, 4 not started (101 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCommSystem_construct` | Matching | 100.00% | 56 |
| `func_00255898` | Matching | 100.00% | 40 |
| `cCommSystem__cCommSystem` | Matching | 100.00% | 96 |
| `cCommSystem_getSignature` | Matching | 100.00% | 12 |
| `func_00255A20` | Matching | 100.00% | 468 |
| `cCommSystem_openDSockChannel` | Matching | 100.00% | 204 |
| `func_00255CC8` | Matching | 100.00% | 108 |
| `func_00255D38` | Matching | 100.00% | 20 |
| `func_00255D50` | Matching | 100.00% | 52 |
| `func_00255D88` | Matching | 100.00% | 52 |
| `func_00255DC0` | Matching | 100.00% | 60 |
| `func_00255E00` | Matching | 100.00% | 60 |
| `func_00255E40` | Matching | 100.00% | 36 |
| `func_00255E68` | Matching | 100.00% | 88 |
| `func_00255EC0` | Matching | 100.00% | 92 |
| `func_00255F20` | Matching | 100.00% | 48 |
| `func_00255F50` | Matching | 100.00% | 80 |
| `func_00255FA0` | Matching | 100.00% | 68 |
| `func_00255FE8` | Matching | 100.00% | 80 |
| `func_00256038` | Matching | 100.00% | 80 |
| `func_00256088` | Matching | 100.00% | 40 |
| `func_002560B0` | Matching | 100.00% | 216 |
| `func_00256188` | Matching | 100.00% | 44 |
| `func_002561B8` | Matching | 100.00% | 40 |
| `func_002561E0` | Matching | 100.00% | 68 |
| `func_00256228` | Matching | 100.00% | 36 |
| `func_00256250` | Matching | 100.00% | 8 |
| `func_00256258` | Matching | 100.00% | 116 |
| `func_002563A8` | Matching | 100.00% | 80 |
| `func_002563F8` | Matching | 100.00% | 104 |
| `func_00256460` | Matching | 100.00% | 172 |
| `func_00256510` | Matching | 100.00% | 208 |
| `func_002565E0` | Matching | 100.00% | 184 |
| `func_00256698` | Matching | 100.00% | 76 |
| `func_002566E8` | Matching | 100.00% | 72 |
| `func_00256730` | Matching | 100.00% | 176 |
| `func_002567E0` | Matching | 100.00% | 124 |
| `func_00256860` | Matching | 100.00% | 152 |
| `func_002568F8` | Matching | 100.00% | 156 |
| `func_00256998` | Matching | 100.00% | 104 |
| `func_00256A00` | Matching | 100.00% | 88 |
| `func_00256A58` | Matching | 100.00% | 76 |
| `func_00256AA8` | Matching | 100.00% | 256 |
| `func_00256BA8` | Matching | 100.00% | 8 |
| `RpcAlloc` | Matching | 100.00% | 40 |
| `func_00256BD8` | Matching | 100.00% | 32 |
| `cGameComm_construct` | Matching | 100.00% | 88 |
| `func_00256C50` | Matching | 100.00% | 40 |
| `func_00256C78` | Matching | 100.00% | 612 |
| `func_00256EE0` | Matching | 100.00% | 344 |
| `func_00257038` | Matching | 100.00% | 156 |
| `func_002570D8` | Matching | 100.00% | 1336 |
| `func_00257610` | Matching | 100.00% | 104 |
| `func_00257678` | Matching | 100.00% | 212 |
| `func_00257750` | Matching | 100.00% | 116 |
| `func_002577C8` | Matching | 100.00% | 304 |
| `func_002578F8` | Matching | 100.00% | 204 |
| `func_002579C8` | Matching | 100.00% | 184 |
| `func_00257A80` | Matching | 100.00% | 344 |
| `func_00257BD8` | Matching | 100.00% | 252 |
| `func_00257DC0` | Matching | 100.00% | 216 |
| `func_00257E98` | Matching | 100.00% | 252 |
| `func_00257F98` | Matching | 100.00% | 452 |
| `func_00258160` | Matching | 100.00% | 40 |
| `func_00258188` | Matching | 100.00% | 44 |
| `func_002581B8` | Matching | 100.00% | 28 |
| `func_002581D8` | Matching | 100.00% | 12 |
| `func_002581E8` | Matching | 100.00% | 12 |
| `func_002581F8` | Matching | 100.00% | 132 |
| `func_00258280` | Matching | 100.00% | 12 |
| `func_00258290` | Matching | 100.00% | 12 |
| `func_002582A0` | Matching | 100.00% | 140 |
| `func_00258330` | Matching | 100.00% | 48 |
| `func_00258360` | Matching | 100.00% | 68 |
| `func_002583A8` | Matching | 100.00% | 156 |
| `cGameComm_syncGame` | Matching | 100.00% | 612 |
| `func_002586B0` | Matching | 100.00% | 224 |
| `func_00258790` | Matching | 100.00% | 220 |
| `func_00258870` | Matching | 100.00% | 52 |
| `func_002588A8` | Matching | 100.00% | 164 |
| `func_00258950` | Matching | 100.00% | 20 |
| `func_00258968` | Matching | 100.00% | 32 |
| `func_00258988` | Matching | 100.00% | 188 |
| `func_00258A48` | Matching | 100.00% | 148 |
| `func_00258AE0` | Matching | 100.00% | 228 |
| `func_00258BC8` | Matching | 100.00% | 56 |
| `func_00258C00` | Matching | 100.00% | 80 |
| `func_00258C50` | Matching | 100.00% | 92 |
| `func_00258F20` | Matching | 100.00% | 372 |
| `func_00259098` | Matching | 100.00% | 252 |
| `func_00259198` | Matching | 100.00% | 12 |
| `func_002591A8` | Matching | 100.00% | 12 |
| `func_002591B8` | Matching | 100.00% | 24 |
| `func_002591D0` | Matching | 100.00% | 24 |
| `func_002591E8` | Matching | 100.00% | 40 |
| `func_00259210` | Matching | 100.00% | 32 |
| `func_00259230` | Matching | 100.00% | 84 |

### `seg/seg_1C9348`

15 matching, 0 partial, 3 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `HUFF_about` | Matching | 100.00% | 288 |
| `func_002C8468` | Matching | 100.00% | 52 |
| `func_002C84A0` | Matching | 100.00% | 172 |
| `func_002C8550` | Matching | 100.00% | 80 |
| `func_002C85A0` | Matching | 100.00% | 28 |
| `func_002C85C0` | Matching | 100.00% | 64 |
| `func_002C8600` | Matching | 100.00% | 244 |
| `func_002C86F8` | Matching | 100.00% | 120 |
| `func_002C8970` | Matching | 100.00% | 264 |
| `func_002C8A78` | Matching | 100.00% | 436 |
| `func_002C8C30` | Matching | 100.00% | 120 |
| `func_002C8CA8` | Matching | 100.00% | 76 |
| `func_002C8CF8` | Matching | 100.00% | 332 |
| `HUFF_encode` | Matching | 100.00% | 340 |
| `func_002C9F60` | Matching | 99.90% | 416 |

### `seg/seg_1D3510`

112 matching, 0 partial, 1 not started (113 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `get_float` | Matching | 100.00% | 68 |
| `get_uint` | Matching | 100.00% | 68 |
| `get_t3Vector` | Matching | 100.00% | 136 |
| `func_002D2628` | Matching | 100.00% | 100 |
| `func_002D2690` | Matching | 100.00% | 100 |
| `func_002D26F8` | Matching | 100.00% | 152 |
| `func_002D2790` | Matching | 100.00% | 32 |
| `get_string` | Matching | 100.00% | 184 |
| `get_data` | Matching | 100.00% | 220 |
| `func_002D2948` | Matching | 100.00% | 60 |
| `func_002D3788` | Matching | 100.00% | 48 |
| `func_002D37B8` | Matching | 100.00% | 8 |
| `func_002D37C0` | Matching | 100.00% | 8 |
| `func_002D37C8` | Matching | 100.00% | 8 |
| `func_002D37D0` | Matching | 100.00% | 8 |
| `func_002D37D8` | Matching | 100.00% | 8 |
| `func_002D37E0` | Matching | 100.00% | 44 |
| `func_002D3810` | Matching | 100.00% | 44 |
| `func_002D3840` | Matching | 100.00% | 176 |
| `func_002D38F0` | Matching | 100.00% | 44 |
| `func_002D3920` | Matching | 100.00% | 8 |
| `func_002D3928` | Matching | 100.00% | 8 |
| `func_002D3930` | Matching | 100.00% | 28 |
| `func_002D3950` | Matching | 100.00% | 32 |
| `func_002D3970` | Matching | 100.00% | 8 |
| `func_002D3978` | Matching | 100.00% | 8 |
| `func_002D3980` | Matching | 100.00% | 40 |
| `func_002D39A8` | Matching | 100.00% | 8 |
| `func_002D39B0` | Matching | 100.00% | 8 |
| `func_002D39B8` | Matching | 100.00% | 28 |
| `func_002D39D8` | Matching | 100.00% | 8 |
| `func_002D39E0` | Matching | 100.00% | 8 |
| `func_002D39E8` | Matching | 100.00% | 8 |
| `func_002D39F0` | Matching | 100.00% | 8 |
| `func_002D39F8` | Matching | 100.00% | 8 |
| `func_002D3A00` | Matching | 100.00% | 8 |
| `func_002D3A08` | Matching | 100.00% | 8 |
| `func_002D3A10` | Matching | 100.00% | 8 |
| `func_002D3A18` | Matching | 100.00% | 8 |
| `func_002D3A20` | Matching | 100.00% | 8 |
| `func_002D3A28` | Matching | 100.00% | 16 |
| `func_002D3A38` | Matching | 100.00% | 8 |
| `func_002D3A40` | Matching | 100.00% | 8 |
| `func_002D3A48` | Matching | 100.00% | 12 |
| `func_002D3A58` | Matching | 100.00% | 16 |
| `func_002D3A68` | Matching | 100.00% | 28 |
| `func_002D3A88` | Matching | 100.00% | 8 |
| `func_002D3A90` | Matching | 100.00% | 8 |
| `func_002D3A98` | Matching | 100.00% | 28 |
| `func_002D3AB8` | Matching | 100.00% | 12 |
| `func_002D3AC8` | Matching | 100.00% | 8 |
| `func_002D3AD0` | Matching | 100.00% | 8 |
| `func_002D3AD8` | Matching | 100.00% | 8 |
| `func_002D3AE0` | Matching | 100.00% | 28 |
| `func_002D3B00` | Matching | 100.00% | 8 |
| `func_002D3B08` | Matching | 100.00% | 8 |
| `func_002D3B10` | Matching | 100.00% | 28 |
| `func_002D3B30` | Matching | 100.00% | 8 |
| `func_002D3B38` | Matching | 100.00% | 28 |
| `func_002D3B58` | Matching | 100.00% | 8 |
| `func_002D3B60` | Matching | 100.00% | 8 |
| `func_002D3B68` | Matching | 100.00% | 8 |
| `func_002D3B70` | Matching | 100.00% | 8 |
| `func_002D3B78` | Matching | 100.00% | 8 |
| `func_002D3B80` | Matching | 100.00% | 28 |
| `func_002D3BA0` | Matching | 100.00% | 8 |
| `func_002D3BA8` | Matching | 100.00% | 8 |
| `func_002D3BB0` | Matching | 100.00% | 28 |
| `func_002D3BD0` | Matching | 100.00% | 8 |
| `func_002D3BD8` | Matching | 100.00% | 8 |
| `func_002D3BE0` | Matching | 100.00% | 28 |
| `func_002D3C00` | Matching | 100.00% | 28 |
| `func_002D3C20` | Matching | 100.00% | 8 |
| `func_002D3C28` | Matching | 100.00% | 8 |
| `func_002D3C30` | Matching | 100.00% | 28 |
| `func_002D3C50` | Matching | 100.00% | 8 |
| `func_002D3C58` | Matching | 100.00% | 8 |
| `func_002D3C60` | Matching | 100.00% | 28 |
| `func_002D3C80` | Matching | 100.00% | 8 |
| `func_002D3C88` | Matching | 100.00% | 12 |
| `func_002D3C98` | Matching | 100.00% | 8 |
| `func_002D3CA0` | Matching | 100.00% | 12 |
| `func_002D3CB0` | Matching | 100.00% | 12 |
| `func_002D3CC0` | Matching | 100.00% | 28 |
| `func_002D3CE0` | Matching | 100.00% | 28 |
| `func_002D3D00` | Matching | 100.00% | 8 |
| `func_002D3D08` | Matching | 100.00% | 12 |
| `func_002D3D18` | Matching | 100.00% | 8 |
| `func_002D3D20` | Matching | 100.00% | 28 |
| `func_002D3D40` | Matching | 100.00% | 8 |
| `func_002D3D48` | Matching | 100.00% | 40 |
| `func_002D3D70` | Matching | 100.00% | 28 |
| `func_002D3D90` | Matching | 100.00% | 28 |
| `func_002D3DB0` | Matching | 100.00% | 68 |
| `func_002D3DF8` | Matching | 100.00% | 28 |
| `func_002D3E18` | Matching | 100.00% | 8 |
| `func_002D3E20` | Matching | 100.00% | 128 |
| `func_002D3EA0` | Matching | 100.00% | 8 |
| `func_002D3EA8` | Matching | 100.00% | 28 |
| `func_002D3EC8` | Matching | 100.00% | 8 |
| `func_002D3ED0` | Matching | 100.00% | 116 |
| `func_002D3F48` | Matching | 100.00% | 8 |
| `func_002D3F50` | Matching | 100.00% | 28 |
| `func_002D3F70` | Matching | 100.00% | 8 |
| `func_002D3F78` | Matching | 100.00% | 92 |
| `func_002D3FD8` | Matching | 100.00% | 48 |
| `func_002D4008` | Matching | 100.00% | 36 |
| `func_002D4030` | Matching | 100.00% | 48 |
| `func_002D4080` | Matching | 100.00% | 60 |
| `func_002D48D0` | Matching | 100.00% | 32 |
| `func_002D4060` | Matching | 99.38% | 32 |
| `func_002D40C0` | Matching | 99.30% | 2064 |

### `seg/seg_1DCD10`

4 matching, 0 partial, 3 not started (7 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_002DBEE0` | Matching | 100.00% | 160 |
| `func_002DBF80` | Matching | 100.00% | 24 |
| `func_002DBF98` | Matching | 100.00% | 460 |
| `func_002DC168` | Matching | 100.00% | 40 |

### `seg/seg_1F1548`

48 matching, 0 partial, 8 not started (56 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cPSPVisualEffectsMan_cPSPVisualEffectsMan` | Matching | 100.00% | 724 |
| `func_002F0820` | Matching | 100.00% | 628 |
| `func_002F0A98` | Matching | 100.00% | 568 |
| `func_002F0CD0` | Matching | 100.00% | 440 |
| `func_002F1148` | Matching | 100.00% | 8 |
| `func_002F1150` | Matching | 100.00% | 956 |
| `func_002F1510` | Matching | 100.00% | 596 |
| `func_002F1768` | Matching | 100.00% | 64 |
| `func_002F17A8` | Matching | 100.00% | 40 |
| `func_002F17D0` | Matching | 100.00% | 60 |
| `func_002F1810` | Matching | 100.00% | 60 |
| `func_002F1850` | Matching | 100.00% | 64 |
| `func_002F1890` | Matching | 100.00% | 72 |
| `func_002F18D8` | Matching | 100.00% | 100 |
| `func_002F1940` | Matching | 100.00% | 172 |
| `func_002F19F0` | Matching | 100.00% | 12 |
| `func_002F1A00` | Matching | 100.00% | 8 |
| `func_002F2088` | Matching | 100.00% | 164 |
| `func_002F2130` | Matching | 100.00% | 228 |
| `func_002F2218` | Matching | 100.00% | 76 |
| `func_002F2268` | Matching | 100.00% | 24 |
| `func_002F2280` | Matching | 100.00% | 20 |
| `func_002F2298` | Matching | 100.00% | 20 |
| `func_002F22B0` | Matching | 100.00% | 24 |
| `func_002F22C8` | Matching | 100.00% | 704 |
| `func_002F2588` | Matching | 100.00% | 12 |
| `func_002F2598` | Matching | 100.00% | 628 |
| `func_002F2D60` | Matching | 100.00% | 12 |
| `func_002F3550` | Matching | 100.00% | 200 |
| `func_002F3618` | Matching | 100.00% | 40 |
| `func_002F3640` | Matching | 100.00% | 360 |
| `func_002F37A8` | Matching | 100.00% | 104 |
| `func_002F3810` | Matching | 100.00% | 440 |
| `func_002F39C8` | Matching | 100.00% | 24 |
| `func_002F4118` | Matching | 100.00% | 140 |
| `func_002F41A8` | Matching | 100.00% | 180 |
| `func_002F4380` | Matching | 100.00% | 96 |
| `func_002F4690` | Matching | 100.00% | 888 |
| `func_002F4A08` | Matching | 100.00% | 944 |
| `func_002F5148` | Matching | 100.00% | 52 |
| `func_002F5180` | Matching | 100.00% | 176 |
| `func_002F5230` | Matching | 100.00% | 104 |
| `func_002F2D70` | Matching | 99.97% | 704 |
| `func_002F4260` | Matching | 99.90% | 208 |
| `func_002F4330` | Matching | 99.74% | 76 |
| `func_002F43E0` | Matching | 99.65% | 684 |
| `func_002F0E88` | Matching | 99.43% | 352 |
| `func_002F0FE8` | Matching | 99.43% | 348 |

### `seg/seg_1FBE38`

116 matching, 0 partial, 9 not started (125 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `checkActiveNode` | Matching | 100.00% | 552 |
| `func_002FB060` | Matching | 100.00% | 524 |
| `func_002FB270` | Matching | 100.00% | 548 |
| `func_002FB498` | Matching | 100.00% | 540 |
| `func_002FB6B8` | Matching | 100.00% | 532 |
| `func_002FB8D0` | Matching | 100.00% | 476 |
| `func_002FBAB0` | Matching | 100.00% | 516 |
| `func_002FBCB8` | Matching | 100.00% | 528 |
| `func_002FBEC8` | Matching | 100.00% | 520 |
| `func_002FC0D0` | Matching | 100.00% | 492 |
| `func_002FC2C0` | Matching | 100.00% | 348 |
| `func_002FC420` | Matching | 100.00% | 440 |
| `func_002FC5D8` | Matching | 100.00% | 504 |
| `func_002FC7D0` | Matching | 100.00% | 504 |
| `func_002FC9C8` | Matching | 100.00% | 596 |
| `func_002FCC20` | Matching | 100.00% | 424 |
| `func_002FCDC8` | Matching | 100.00% | 548 |
| `func_002FCFF0` | Matching | 100.00% | 608 |
| `func_002FD250` | Matching | 100.00% | 464 |
| `func_002FD420` | Matching | 100.00% | 824 |
| `func_002FD758` | Matching | 100.00% | 668 |
| `func_002FD9F8` | Matching | 100.00% | 612 |
| `func_002FDC60` | Matching | 100.00% | 620 |
| `func_002FDED0` | Matching | 100.00% | 496 |
| `func_002FE0C0` | Matching | 100.00% | 512 |
| `func_002FE2C0` | Matching | 100.00% | 484 |
| `func_002FE4A8` | Matching | 100.00% | 444 |
| `func_002FE668` | Matching | 100.00% | 468 |
| `cViewer_addParticle` | Matching | 100.00% | 1624 |
| `func_002FEE98` | Matching | 100.00% | 812 |
| `func_002FF1C8` | Matching | 100.00% | 456 |
| `func_002FF390` | Matching | 100.00% | 600 |
| `func_002FF5E8` | Matching | 100.00% | 616 |
| `func_002FF850` | Matching | 100.00% | 340 |
| `func_002FF9A8` | Matching | 100.00% | 420 |
| `func_002FFB50` | Matching | 100.00% | 516 |
| `func_002FFD58` | Matching | 100.00% | 424 |
| `func_002FFF00` | Matching | 100.00% | 420 |
| `func_003000A8` | Matching | 100.00% | 436 |
| `func_00300260` | Matching | 100.00% | 436 |
| `func_00300418` | Matching | 100.00% | 460 |
| `func_003005E8` | Matching | 100.00% | 388 |
| `func_00300770` | Matching | 100.00% | 468 |
| `func_00300948` | Matching | 100.00% | 468 |
| `func_00300B20` | Matching | 100.00% | 340 |
| `func_00300C78` | Matching | 100.00% | 432 |
| `func_00300E28` | Matching | 100.00% | 296 |
| `func_00300F50` | Matching | 100.00% | 464 |
| `func_00301120` | Matching | 100.00% | 464 |
| `func_003012F0` | Matching | 100.00% | 332 |
| `func_00301560` | Matching | 100.00% | 288 |
| `func_00301680` | Matching | 100.00% | 428 |
| `func_00301830` | Matching | 100.00% | 408 |
| `func_003019C8` | Matching | 100.00% | 448 |
| `func_00301B88` | Matching | 100.00% | 248 |
| `func_00301C80` | Matching | 100.00% | 248 |
| `func_00301D78` | Matching | 100.00% | 464 |
| `func_00301F48` | Matching | 100.00% | 256 |
| `func_00302048` | Matching | 100.00% | 452 |
| `func_00302210` | Matching | 100.00% | 640 |
| `func_00302490` | Matching | 100.00% | 496 |
| `func_00302968` | Matching | 100.00% | 344 |
| `func_00302AC0` | Matching | 100.00% | 280 |
| `func_00302BD8` | Matching | 100.00% | 268 |
| `func_00302CE8` | Matching | 100.00% | 264 |
| `func_00302DF0` | Matching | 100.00% | 264 |
| `func_00302EF8` | Matching | 100.00% | 564 |
| `func_00303130` | Matching | 100.00% | 400 |
| `func_003032C0` | Matching | 100.00% | 188 |
| `func_00303380` | Matching | 100.00% | 176 |
| `func_00303490` | Matching | 100.00% | 104 |
| `func_003034F8` | Matching | 100.00% | 156 |
| `func_00303598` | Matching | 100.00% | 280 |
| `func_003036B0` | Matching | 100.00% | 256 |
| `func_003037B0` | Matching | 100.00% | 572 |
| `func_003039F0` | Matching | 100.00% | 428 |
| `func_00303BA0` | Matching | 100.00% | 484 |
| `func_00303D88` | Matching | 100.00% | 8 |
| `func_00303D90` | Matching | 100.00% | 104 |
| `func_00303DF8` | Matching | 100.00% | 104 |
| `func_00303E60` | Matching | 100.00% | 104 |
| `func_00303EC8` | Matching | 100.00% | 184 |
| `func_00303F80` | Matching | 100.00% | 108 |
| `func_00303FF0` | Matching | 100.00% | 272 |
| `func_00304100` | Matching | 100.00% | 272 |
| `func_00304210` | Matching | 100.00% | 272 |
| `func_003044A8` | Matching | 100.00% | 272 |
| `func_003045B8` | Matching | 100.00% | 968 |
| `func_00304980` | Matching | 100.00% | 436 |
| `func_00304B38` | Matching | 100.00% | 276 |
| `func_00304C50` | Matching | 100.00% | 488 |
| `func_00304E38` | Matching | 100.00% | 436 |
| `func_00304FF0` | Matching | 100.00% | 256 |
| `func_00305478` | Matching | 100.00% | 484 |
| `func_00305660` | Matching | 100.00% | 352 |
| `func_003057C0` | Matching | 100.00% | 476 |
| `func_00305C88` | Matching | 100.00% | 260 |
| `func_00305D90` | Matching | 100.00% | 428 |
| `func_00305F40` | Matching | 100.00% | 620 |
| `func_00306300` | Matching | 100.00% | 308 |
| `func_00306438` | Matching | 100.00% | 432 |
| `func_003065E8` | Matching | 100.00% | 392 |
| `func_00306770` | Matching | 100.00% | 408 |
| `func_00306908` | Matching | 100.00% | 388 |
| `func_00306A90` | Matching | 100.00% | 540 |
| `func_00306CB0` | Matching | 100.00% | 436 |
| `func_00306E68` | Matching | 100.00% | 436 |
| `func_00307020` | Matching | 100.00% | 260 |
| `func_00307128` | Matching | 100.00% | 160 |
| `func_003071C8` | Matching | 100.00% | 40 |
| `func_003071F0` | Matching | 100.00% | 76 |
| `func_00307240` | Matching | 100.00% | 108 |
| `func_003072B0` | Matching | 100.00% | 84 |
| `func_00307308` | Matching | 100.00% | 440 |
| `func_003074C0` | Matching | 100.00% | 168 |
| `func_00307568` | Matching | 100.00% | 44 |

### `seg/seg_2125C8`

5 matching, 0 partial, 1 not started (6 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAIAnimEventMap_getBlendInTime` | Matching | 100.00% | 24 |
| `func_003115E0` | Matching | 100.00% | 300 |
| `func_00311860` | Matching | 100.00% | 12 |
| `func_00311870` | Matching | 100.00% | 56 |
| `func_003118A8` | Matching | 100.00% | 36 |

### `seg/seg_218AE8`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00317AE8` | Matching | 100.00% | 104 |
| `func_00317B50` | Matching | 100.00% | 248 |
| `func_00317C48` | Matching | 100.00% | 200 |
| `func_00317D10` | Matching | 100.00% | 8 |
| `func_00317D18` | Matching | 100.00% | 8 |

### `seg/seg_218F38`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `BXFILE_exists` | Matching | 100.00% | 40 |
| `func_00317F60` | Matching | 100.00% | 52 |
| `func_00317F98` | Matching | 100.00% | 40 |
| `func_00317FC0` | Matching | 100.00% | 8 |
| `func_00317FC8` | Matching | 100.00% | 28 |

### `seg/seg_21A1C0`

15 matching, 0 partial, 1 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003191C0` | Matching | 100.00% | 744 |
| `func_003194A8` | Matching | 100.00% | 68 |
| `func_003194F0` | Matching | 100.00% | 132 |
| `func_00319578` | Matching | 100.00% | 148 |
| `func_00319610` | Matching | 100.00% | 80 |
| `func_00319660` | Matching | 100.00% | 44 |
| `func_00319690` | Matching | 100.00% | 136 |
| `func_00319718` | Matching | 100.00% | 120 |
| `func_00319790` | Matching | 100.00% | 60 |
| `func_003197D0` | Matching | 100.00% | 48 |
| `func_00319800` | Matching | 100.00% | 28 |
| `func_00319820` | Matching | 100.00% | 128 |
| `func_003198A0` | Matching | 100.00% | 112 |
| `func_00319910` | Matching | 100.00% | 28 |
| `func_003199D0` | Matching | 100.00% | 92 |

### `seg/seg_21E5A8`

3 matching, 0 partial, 0 not started (3 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_0031D5A8` | Matching | 100.00% | 60 |
| `func_0031D5E8` | Matching | 100.00% | 48 |
| `func_0031D618` | Matching | 100.00% | 68 |

### `seg/seg_2EEF50`

51 matching, 0 partial, 6 not started (57 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003EE028` | Matching | 100.00% | 388 |
| `func_003EE1B0` | Matching | 100.00% | 52 |
| `func_003EE1E8` | Matching | 100.00% | 116 |
| `func_003EE260` | Matching | 100.00% | 88 |
| `func_003EE2B8` | Matching | 100.00% | 104 |
| `func_003EE320` | Matching | 100.00% | 192 |
| `func_003EE3E0` | Matching | 100.00% | 132 |
| `func_003EE468` | Matching | 100.00% | 20 |
| `func_003EE480` | Matching | 100.00% | 204 |
| `func_003EE550` | Matching | 100.00% | 8 |
| `func_003EE558` | Matching | 100.00% | 8 |
| `func_003EE560` | Matching | 100.00% | 60 |
| `func_003EE5A0` | Matching | 100.00% | 32 |
| `func_003EE5C0` | Matching | 100.00% | 32 |
| `func_003EE5E0` | Matching | 100.00% | 28 |
| `func_003EE600` | Matching | 100.00% | 28 |
| `func_003EE620` | Matching | 100.00% | 324 |
| `func_003EE768` | Matching | 100.00% | 8 |
| `func_003EE770` | Matching | 100.00% | 8 |
| `func_003EE778` | Matching | 100.00% | 168 |
| `func_003EE820` | Matching | 100.00% | 88 |
| `func_003EE878` | Matching | 100.00% | 8 |
| `func_003EE880` | Matching | 100.00% | 128 |
| `func_003EE900` | Matching | 100.00% | 160 |
| `func_003EE9A0` | Matching | 100.00% | 164 |
| `func_003EEAB8` | Matching | 100.00% | 120 |
| `func_003EEDA0` | Matching | 100.00% | 224 |
| `func_003EEE80` | Matching | 100.00% | 100 |
| `func_003EEEE8` | Matching | 100.00% | 88 |
| `func_003EEF40` | Matching | 100.00% | 120 |
| `func_003EEFB8` | Matching | 100.00% | 12 |
| `func_003EF088` | Matching | 100.00% | 8 |
| `func_003EF090` | Matching | 100.00% | 384 |
| `func_003EF600` | Matching | 100.00% | 60 |
| `func_003EF640` | Matching | 100.00% | 180 |
| `func_003EF770` | Matching | 100.00% | 148 |
| `func_003EF808` | Matching | 100.00% | 28 |
| `func_003EF828` | Matching | 100.00% | 276 |
| `func_003EF940` | Matching | 100.00% | 116 |
| `func_003EFA48` | Matching | 100.00% | 176 |
| `func_003EFBA0` | Matching | 100.00% | 200 |
| `func_003EFC68` | Matching | 100.00% | 112 |
| `func_003EFE20` | Matching | 100.00% | 172 |
| `func_003EFED0` | Matching | 100.00% | 108 |
| `func_003EFD30` | Matching | 99.92% | 236 |
| `func_003EEB30` | Matching | 99.90% | 200 |
| `func_003EFAF8` | Matching | 99.88% | 164 |
| `func_003EED08` | Matching | 99.87% | 152 |
| `func_003EEBF8` | Matching | 99.86% | 144 |
| `func_003EF9B8` | Matching | 99.86% | 140 |
| `func_003EEC88` | Matching | 99.84% | 128 |

### `seg/seg_2F0F40`

28 matching, 0 partial, 3 not started (31 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003EFF40` | Matching | 100.00% | 404 |
| `func_003F00D8` | Matching | 100.00% | 120 |
| `func_003F0150` | Matching | 100.00% | 68 |
| `func_003F0198` | Matching | 100.00% | 312 |
| `func_003F0568` | Matching | 100.00% | 164 |
| `func_003F0610` | Matching | 100.00% | 68 |
| `func_003F0658` | Matching | 100.00% | 184 |
| `func_003F0710` | Matching | 100.00% | 140 |
| `func_003F07A0` | Matching | 100.00% | 92 |
| `func_003F0800` | Matching | 100.00% | 8 |
| `func_003F0808` | Matching | 100.00% | 12 |
| `func_003F0818` | Matching | 100.00% | 204 |
| `func_003F08E8` | Matching | 100.00% | 616 |
| `func_003F0B50` | Matching | 100.00% | 144 |
| `func_003F0BE0` | Matching | 100.00% | 172 |
| `func_003F0C90` | Matching | 100.00% | 412 |
| `func_003F0E30` | Matching | 100.00% | 8 |
| `func_003F0E38` | Matching | 100.00% | 960 |
| `func_003F14D8` | Matching | 100.00% | 96 |
| `func_003F1538` | Matching | 100.00% | 12 |
| `func_003F1548` | Matching | 100.00% | 44 |
| `func_003F1578` | Matching | 100.00% | 76 |
| `func_003F15C8` | Matching | 100.00% | 268 |
| `func_003F16D8` | Matching | 100.00% | 240 |
| `func_003F17C8` | Matching | 100.00% | 12 |
| `func_003F2220` | Matching | 100.00% | 3788 |
| `func_003F30F0` | Matching | 100.00% | 56 |
| `func_003F3128` | Matching | 100.00% | 208 |

### `seg/seg_2F41F8`

219 matching, 0 partial, 34 not started (253 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003F31F8` | Matching | 100.00% | 440 |
| `func_003F33B0` | Matching | 100.00% | 384 |
| `func_003F3860` | Matching | 100.00% | 224 |
| `func_003F3940` | Matching | 100.00% | 136 |
| `func_003F39C8` | Matching | 100.00% | 204 |
| `func_003F3A98` | Matching | 100.00% | 28 |
| `func_003F3AB8` | Matching | 100.00% | 96 |
| `func_003F3B18` | Matching | 100.00% | 176 |
| `func_003F3BC8` | Matching | 100.00% | 136 |
| `func_003F3CC0` | Matching | 100.00% | 692 |
| `func_003F40B8` | Matching | 100.00% | 96 |
| `func_003F4118` | Matching | 100.00% | 124 |
| `func_003F4198` | Matching | 100.00% | 28 |
| `func_003F41B8` | Matching | 100.00% | 84 |
| `func_003F4210` | Matching | 100.00% | 64 |
| `func_003F4250` | Matching | 100.00% | 76 |
| `func_003F42A0` | Matching | 100.00% | 144 |
| `func_003F4330` | Matching | 100.00% | 28 |
| `func_003F4350` | Matching | 100.00% | 128 |
| `func_003F43D0` | Matching | 100.00% | 60 |
| `func_003F4410` | Matching | 100.00% | 52 |
| `func_003F4448` | Matching | 100.00% | 176 |
| `func_003F44F8` | Matching | 100.00% | 48 |
| `func_003F4D68` | Matching | 100.00% | 128 |
| `func_003F4DE8` | Matching | 100.00% | 148 |
| `func_003F4E80` | Matching | 100.00% | 28 |
| `func_003F4EA0` | Matching | 100.00% | 160 |
| `func_003F4F40` | Matching | 100.00% | 188 |
| `func_003F53F8` | Matching | 100.00% | 120 |
| `func_003F5470` | Matching | 100.00% | 8 |
| `func_003F55B8` | Matching | 100.00% | 128 |
| `func_003F5738` | Matching | 100.00% | 140 |
| `func_003F57C8` | Matching | 100.00% | 320 |
| `func_003F5908` | Matching | 100.00% | 8 |
| `func_003F5D88` | Matching | 100.00% | 28 |
| `func_003F5DA8` | Matching | 100.00% | 228 |
| `func_003F5E90` | Matching | 100.00% | 116 |
| `func_003F5F08` | Matching | 100.00% | 124 |
| `func_003F5F88` | Matching | 100.00% | 184 |
| `func_003F6040` | Matching | 100.00% | 116 |
| `func_003F60B8` | Matching | 100.00% | 128 |
| `func_003F6138` | Matching | 100.00% | 140 |
| `func_003F61C8` | Matching | 100.00% | 8 |
| `func_003F62F8` | Matching | 100.00% | 80 |
| `func_003F6348` | Matching | 100.00% | 12 |
| `func_003F6358` | Matching | 100.00% | 132 |
| `func_003F63E0` | Matching | 100.00% | 12 |
| `func_003F63F0` | Matching | 100.00% | 240 |
| `func_003F64E0` | Matching | 100.00% | 60 |
| `func_003F6520` | Matching | 100.00% | 24 |
| `func_003F6538` | Matching | 100.00% | 104 |
| `func_003F65A0` | Matching | 100.00% | 84 |
| `func_003F65F8` | Matching | 100.00% | 120 |
| `func_003F6670` | Matching | 100.00% | 140 |
| `func_003F6700` | Matching | 100.00% | 220 |
| `func_003F67E0` | Matching | 100.00% | 84 |
| `func_003F6838` | Matching | 100.00% | 184 |
| `func_003F68F0` | Matching | 100.00% | 108 |
| `func_003F6960` | Matching | 100.00% | 220 |
| `func_003F6A40` | Matching | 100.00% | 108 |
| `func_003F6AB0` | Matching | 100.00% | 8 |
| `func_003F6AB8` | Matching | 100.00% | 56 |
| `func_003F6AF0` | Matching | 100.00% | 48 |
| `func_003F6B20` | Matching | 100.00% | 48 |
| `func_003F6B50` | Matching | 100.00% | 48 |
| `func_003F6B80` | Matching | 100.00% | 32 |
| `func_003F6BA0` | Matching | 100.00% | 108 |
| `func_003F6C10` | Matching | 100.00% | 48 |
| `func_003F6C40` | Matching | 100.00% | 12 |
| `func_003F6C50` | Matching | 100.00% | 16 |
| `func_003F6C60` | Matching | 100.00% | 12 |
| `func_003F6D98` | Matching | 100.00% | 48 |
| `func_003F6DC8` | Matching | 100.00% | 164 |
| `func_003F6E70` | Matching | 100.00% | 36 |
| `func_003F6E98` | Matching | 100.00% | 72 |
| `func_003F6EE0` | Matching | 100.00% | 132 |
| `func_003F71F8` | Matching | 100.00% | 28 |
| `func_003F7218` | Matching | 100.00% | 172 |
| `func_003F72C8` | Matching | 100.00% | 44 |
| `func_003F72F8` | Matching | 100.00% | 44 |
| `func_003F73A8` | Matching | 100.00% | 68 |
| `func_003F73F0` | Matching | 100.00% | 68 |
| `func_003F7438` | Matching | 100.00% | 60 |
| `func_003F7478` | Matching | 100.00% | 172 |
| `func_003F7528` | Matching | 100.00% | 172 |
| `func_003F75D8` | Matching | 100.00% | 124 |
| `func_003F7658` | Matching | 100.00% | 124 |
| `func_003F76D8` | Matching | 100.00% | 48 |
| `func_003F7708` | Matching | 100.00% | 232 |
| `func_003F77F0` | Matching | 100.00% | 8 |
| `func_003F77F8` | Matching | 100.00% | 40 |
| `func_003F7820` | Matching | 100.00% | 28 |
| `func_003F7840` | Matching | 100.00% | 80 |
| `func_003F7890` | Matching | 100.00% | 80 |
| `func_003F78E0` | Matching | 100.00% | 28 |
| `func_003F7900` | Matching | 100.00% | 28 |
| `func_003F7920` | Matching | 100.00% | 52 |
| `func_003F7958` | Matching | 100.00% | 52 |
| `func_003F7A30` | Matching | 100.00% | 44 |
| `func_003F7BD0` | Matching | 100.00% | 48 |
| `func_003F7C00` | Matching | 100.00% | 408 |
| `func_003F7D98` | Matching | 100.00% | 72 |
| `func_003F7DE0` | Matching | 100.00% | 176 |
| `func_003F7E90` | Matching | 100.00% | 80 |
| `func_003F7F18` | Matching | 100.00% | 44 |
| `func_003F7F48` | Matching | 100.00% | 180 |
| `func_003F8000` | Matching | 100.00% | 68 |
| `func_003F8048` | Matching | 100.00% | 120 |
| `func_003F80C0` | Matching | 100.00% | 28 |
| `func_003F80E0` | Matching | 100.00% | 152 |
| `func_003F8178` | Matching | 100.00% | 132 |
| `func_003F8200` | Matching | 100.00% | 20 |
| `func_003F8218` | Matching | 100.00% | 20 |
| `func_003F8230` | Matching | 100.00% | 36 |
| `func_003F8550` | Matching | 100.00% | 56 |
| `func_003F8588` | Matching | 100.00% | 52 |
| `func_003F86F0` | Matching | 100.00% | 32 |
| `func_003F8710` | Matching | 100.00% | 12 |
| `func_003F8720` | Matching | 100.00% | 68 |
| `func_003F8768` | Matching | 100.00% | 68 |
| `func_003F87B0` | Matching | 100.00% | 68 |
| `func_003F87F8` | Matching | 100.00% | 8 |
| `func_003F8800` | Matching | 100.00% | 56 |
| `func_003F8838` | Matching | 100.00% | 72 |
| `func_003F8880` | Matching | 100.00% | 136 |
| `func_003F8908` | Matching | 100.00% | 96 |
| `func_003F8968` | Matching | 100.00% | 96 |
| `func_003F89C8` | Matching | 100.00% | 64 |
| `func_003F8A08` | Matching | 100.00% | 80 |
| `func_003F8A58` | Matching | 100.00% | 104 |
| `func_003F8AC0` | Matching | 100.00% | 100 |
| `func_003F8B28` | Matching | 100.00% | 80 |
| `func_003F8B78` | Matching | 100.00% | 56 |
| `func_003F8BB0` | Matching | 100.00% | 56 |
| `func_003F8BE8` | Matching | 100.00% | 72 |
| `func_003F8C30` | Matching | 100.00% | 8 |
| `func_003F9208` | Matching | 100.00% | 12 |
| `func_003F95E8` | Matching | 100.00% | 176 |
| `func_003F9C48` | Matching | 100.00% | 372 |
| `func_003F9DC0` | Matching | 100.00% | 316 |
| `func_003F9F00` | Matching | 100.00% | 316 |
| `func_003FA040` | Matching | 100.00% | 396 |
| `func_003FA1D0` | Matching | 100.00% | 108 |
| `func_003FA240` | Matching | 100.00% | 284 |
| `func_003FA360` | Matching | 100.00% | 28 |
| `func_003FA6A8` | Matching | 100.00% | 28 |
| `func_003FA6C8` | Matching | 100.00% | 28 |
| `func_003FA6E8` | Matching | 100.00% | 28 |
| `func_003FA708` | Matching | 100.00% | 148 |
| `func_003FA7A0` | Matching | 100.00% | 116 |
| `func_003FA818` | Matching | 100.00% | 224 |
| `func_003FB278` | Matching | 100.00% | 8 |
| `func_003FB280` | Matching | 100.00% | 72 |
| `func_003FB2C8` | Matching | 100.00% | 44 |
| `func_003FB2F8` | Matching | 100.00% | 8 |
| `func_003FB300` | Matching | 100.00% | 8 |
| `func_003FB308` | Matching | 100.00% | 12 |
| `func_003FB318` | Matching | 100.00% | 60 |
| `func_003FB358` | Matching | 100.00% | 72 |
| `func_003FB3A0` | Matching | 100.00% | 144 |
| `func_003FB430` | Matching | 100.00% | 76 |
| `func_003FB480` | Matching | 100.00% | 16 |
| `func_003FB490` | Matching | 100.00% | 44 |
| `func_003FB4C0` | Matching | 100.00% | 148 |
| `func_003FB558` | Matching | 100.00% | 84 |
| `func_003FB5B0` | Matching | 100.00% | 52 |
| `func_003FB5E8` | Matching | 100.00% | 12 |
| `func_003FB5F8` | Matching | 100.00% | 36 |
| `func_003FB620` | Matching | 100.00% | 28 |
| `func_003FB640` | Matching | 100.00% | 16 |
| `func_003FB650` | Matching | 100.00% | 76 |
| `func_003FB6A0` | Matching | 100.00% | 140 |
| `func_003FB730` | Matching | 100.00% | 140 |
| `func_003FB7C0` | Matching | 100.00% | 60 |
| `func_003FB800` | Matching | 100.00% | 12 |
| `func_003FB810` | Matching | 100.00% | 20 |
| `func_003FB828` | Matching | 100.00% | 20 |
| `func_003FB840` | Matching | 100.00% | 20 |
| `func_003FB858` | Matching | 100.00% | 64 |
| `func_003FB898` | Matching | 100.00% | 120 |
| `func_003FB910` | Matching | 100.00% | 68 |
| `func_003FB958` | Matching | 100.00% | 68 |
| `func_003FB9A0` | Matching | 100.00% | 48 |
| `func_003FB9D0` | Matching | 100.00% | 80 |
| `func_003FBA20` | Matching | 100.00% | 88 |
| `func_003FBA78` | Matching | 100.00% | 88 |
| `func_003FBB50` | Matching | 100.00% | 144 |
| `func_003FBBE0` | Matching | 100.00% | 92 |
| `func_003FBC40` | Matching | 100.00% | 152 |
| `func_003FBCD8` | Matching | 100.00% | 152 |
| `func_003FBD70` | Matching | 100.00% | 68 |
| `func_003FBDB8` | Matching | 100.00% | 56 |
| `func_003FBDF0` | Matching | 100.00% | 76 |
| `func_003FBED0` | Matching | 100.00% | 172 |
| `func_003FBF80` | Matching | 100.00% | 96 |
| `func_003FBFE0` | Matching | 100.00% | 244 |
| `func_003FC0D8` | Matching | 100.00% | 12 |
| `func_003FC390` | Matching | 100.00% | 48 |
| `func_003FC3C0` | Matching | 100.00% | 48 |
| `func_003FC3F0` | Matching | 100.00% | 212 |
| `func_003FC4C8` | Matching | 100.00% | 28 |
| `func_003FC708` | Matching | 100.00% | 328 |
| `func_003FC850` | Matching | 100.00% | 164 |
| `func_003FC8F8` | Matching | 100.00% | 148 |
| `func_003FC990` | Matching | 100.00% | 176 |
| `func_003FC548` | Matching | 99.96% | 448 |
| `func_003F9818` | Matching | 99.95% | 416 |
| `func_003F9698` | Matching | 99.95% | 380 |
| `func_003F99B8` | Matching | 99.95% | 380 |
| `func_003FC260` | Matching | 99.93% | 304 |
| `func_003F3748` | Matching | 99.93% | 280 |
| `func_003F5A70` | Matching | 99.91% | 456 |
| `func_003F35D0` | Matching | 99.89% | 376 |
| `func_003F5C38` | Matching | 99.88% | 332 |
| `func_003FBE40` | Matching | 99.86% | 140 |
| `func_003FC4E8` | Matching | 99.78% | 92 |
| `func_003F7990` | Matching | 99.74% | 156 |
| `func_003F7EE0` | Matching | 99.62% | 52 |
| `func_003F4C68` | Matching | 99.58% | 48 |

### `seg/seg_2FDDC8`

17 matching, 0 partial, 1 not started (18 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003FCDC8` | Matching | 100.00% | 68 |
| `func_003FCE10` | Matching | 100.00% | 236 |
| `func_003FCF00` | Matching | 100.00% | 148 |
| `func_003FCF98` | Matching | 100.00% | 60 |
| `func_003FCFD8` | Matching | 100.00% | 256 |
| `func_003FD0D8` | Matching | 100.00% | 36 |
| `func_003FD100` | Matching | 100.00% | 36 |
| `func_003FD128` | Matching | 100.00% | 36 |
| `func_003FD150` | Matching | 100.00% | 136 |
| `func_003FD1D8` | Matching | 100.00% | 24 |
| `func_003FD1F0` | Matching | 100.00% | 28 |
| `func_003FD210` | Matching | 100.00% | 168 |
| `func_003FD2B8` | Matching | 100.00% | 64 |
| `func_003FD558` | Matching | 100.00% | 260 |
| `func_003FD6E0` | Matching | 100.00% | 116 |
| `func_003FD758` | Matching | 100.00% | 180 |
| `func_003FD660` | Matching | 99.52% | 124 |

### `seg/seg_2FE810`

288 matching, 0 partial, 78 not started (366 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003FD810` | Matching | 100.00% | 244 |
| `func_003FD908` | Matching | 100.00% | 8 |
| `func_003FD910` | Matching | 100.00% | 400 |
| `func_003FDAA0` | Matching | 100.00% | 12 |
| `func_003FDEA0` | Matching | 100.00% | 132 |
| `func_003FDF28` | Matching | 100.00% | 40 |
| `func_003FDF50` | Matching | 100.00% | 52 |
| `func_003FDF88` | Matching | 100.00% | 40 |
| `func_003FDFB0` | Matching | 100.00% | 220 |
| `func_003FE268` | Matching | 100.00% | 56 |
| `func_003FE2A0` | Matching | 100.00% | 20 |
| `func_003FE590` | Matching | 100.00% | 52 |
| `func_003FE5C8` | Matching | 100.00% | 152 |
| `func_003FE660` | Matching | 100.00% | 20 |
| `func_003FE678` | Matching | 100.00% | 20 |
| `func_003FE690` | Matching | 100.00% | 20 |
| `func_003FE708` | Matching | 100.00% | 80 |
| `func_003FE758` | Matching | 100.00% | 48 |
| `func_003FE788` | Matching | 100.00% | 48 |
| `func_003FE7B8` | Matching | 100.00% | 16 |
| `func_003FE7C8` | Matching | 100.00% | 16 |
| `func_003FE7D8` | Matching | 100.00% | 64 |
| `func_003FE828` | Matching | 100.00% | 12 |
| `func_003FEBC0` | Matching | 100.00% | 20 |
| `func_003FEC38` | Matching | 100.00% | 80 |
| `func_003FEC88` | Matching | 100.00% | 48 |
| `func_003FECB8` | Matching | 100.00% | 48 |
| `func_003FECE8` | Matching | 100.00% | 16 |
| `func_003FECF8` | Matching | 100.00% | 16 |
| `func_003FED50` | Matching | 100.00% | 16 |
| `func_003FF088` | Matching | 100.00% | 104 |
| `func_003FF0F0` | Matching | 100.00% | 60 |
| `func_003FF160` | Matching | 100.00% | 80 |
| `func_003FF330` | Matching | 100.00% | 92 |
| `func_003FF4A8` | Matching | 100.00% | 320 |
| `func_003FF5E8` | Matching | 100.00% | 156 |
| `func_003FF688` | Matching | 100.00% | 128 |
| `func_003FF8F0` | Matching | 100.00% | 184 |
| `func_003FF9A8` | Matching | 100.00% | 96 |
| `func_003FFA08` | Matching | 100.00% | 80 |
| `func_003FFA58` | Matching | 100.00% | 356 |
| `func_003FFBC0` | Matching | 100.00% | 120 |
| `func_003FFC38` | Matching | 100.00% | 52 |
| `func_003FFC70` | Matching | 100.00% | 100 |
| `func_003FFCD8` | Matching | 100.00% | 80 |
| `func_003FFD28` | Matching | 100.00% | 52 |
| `func_003FFD60` | Matching | 100.00% | 288 |
| `func_003FFE80` | Matching | 100.00% | 284 |
| `func_003FFFA0` | Matching | 100.00% | 312 |
| `func_004000D8` | Matching | 100.00% | 180 |
| `func_00400250` | Matching | 100.00% | 216 |
| `func_00400328` | Matching | 100.00% | 180 |
| `func_004003E0` | Matching | 100.00% | 176 |
| `func_00400490` | Matching | 100.00% | 92 |
| `func_004004F0` | Matching | 100.00% | 84 |
| `func_00400548` | Matching | 100.00% | 84 |
| `func_004005A0` | Matching | 100.00% | 204 |
| `func_00400670` | Matching | 100.00% | 100 |
| `func_004006D8` | Matching | 100.00% | 104 |
| `func_00400740` | Matching | 100.00% | 100 |
| `func_004007A8` | Matching | 100.00% | 104 |
| `func_00400810` | Matching | 100.00% | 36 |
| `func_00400838` | Matching | 100.00% | 104 |
| `func_004008A0` | Matching | 100.00% | 104 |
| `func_00400908` | Matching | 100.00% | 160 |
| `func_00400B48` | Matching | 100.00% | 184 |
| `func_00400CB8` | Matching | 100.00% | 160 |
| `func_00400D58` | Matching | 100.00% | 128 |
| `func_00400DD8` | Matching | 100.00% | 84 |
| `func_00400E30` | Matching | 100.00% | 120 |
| `func_00401350` | Matching | 100.00% | 152 |
| `func_004013E8` | Matching | 100.00% | 160 |
| `func_00401488` | Matching | 100.00% | 108 |
| `func_00402268` | Matching | 100.00% | 152 |
| `func_00402300` | Matching | 100.00% | 152 |
| `func_00402398` | Matching | 100.00% | 180 |
| `func_00402450` | Matching | 100.00% | 208 |
| `func_00402520` | Matching | 100.00% | 248 |
| `func_00402618` | Matching | 100.00% | 236 |
| `func_004027B8` | Matching | 100.00% | 524 |
| `func_004029C8` | Matching | 100.00% | 8 |
| `func_004029D0` | Matching | 100.00% | 60 |
| `func_00402A10` | Matching | 100.00% | 72 |
| `func_00402A58` | Matching | 100.00% | 68 |
| `func_00402AA0` | Matching | 100.00% | 80 |
| `func_00402AF0` | Matching | 100.00% | 16 |
| `func_00402B00` | Matching | 100.00% | 20 |
| `func_00402B18` | Matching | 100.00% | 32 |
| `func_00402B38` | Matching | 100.00% | 12 |
| `func_00402B48` | Matching | 100.00% | 16 |
| `func_00402B58` | Matching | 100.00% | 88 |
| `func_00402BB0` | Matching | 100.00% | 84 |
| `func_00402C30` | Matching | 100.00% | 80 |
| `func_00402C80` | Matching | 100.00% | 40 |
| `func_00402CA8` | Matching | 100.00% | 24 |
| `func_00402CC0` | Matching | 100.00% | 20 |
| `func_00402CD8` | Matching | 100.00% | 16 |
| `func_00402CE8` | Matching | 100.00% | 12 |
| `func_00402CF8` | Matching | 100.00% | 12 |
| `func_00402D08` | Matching | 100.00% | 12 |
| `func_00402D18` | Matching | 100.00% | 12 |
| `func_00402D28` | Matching | 100.00% | 16 |
| `func_00402D38` | Matching | 100.00% | 24 |
| `func_00402D50` | Matching | 100.00% | 20 |
| `func_00402D68` | Matching | 100.00% | 12 |
| `func_00402D78` | Matching | 100.00% | 12 |
| `func_00402D88` | Matching | 100.00% | 108 |
| `func_00402DF8` | Matching | 100.00% | 24 |
| `func_00402F80` | Matching | 100.00% | 276 |
| `func_00403098` | Matching | 100.00% | 68 |
| `func_004030E0` | Matching | 100.00% | 348 |
| `func_00403240` | Matching | 100.00% | 104 |
| `func_004032A8` | Matching | 100.00% | 12 |
| `func_004032B8` | Matching | 100.00% | 124 |
| `func_00403338` | Matching | 100.00% | 96 |
| `func_00403398` | Matching | 100.00% | 200 |
| `func_00403460` | Matching | 100.00% | 16 |
| `func_00403470` | Matching | 100.00% | 52 |
| `func_004034A8` | Matching | 100.00% | 84 |
| `func_00403500` | Matching | 100.00% | 256 |
| `func_00403600` | Matching | 100.00% | 32 |
| `func_00403620` | Matching | 100.00% | 292 |
| `func_00403BB0` | Matching | 100.00% | 304 |
| `func_00403CE0` | Matching | 100.00% | 140 |
| `_sequenceScalableExtension` | Matching | 100.00% | 12 |
| `func_00403D80` | Matching | 100.00% | 12 |
| `func_00403D90` | Matching | 100.00% | 12 |
| `func_00403DA0` | Matching | 100.00% | 12 |
| `func_00403DB0` | Matching | 100.00% | 36 |
| `func_00403DD8` | Matching | 100.00% | 36 |
| `func_00404D98` | Matching | 100.00% | 116 |
| `func_00404E10` | Matching | 100.00% | 148 |
| `func_00404EA8` | Matching | 100.00% | 180 |
| `func_00404F60` | Matching | 100.00% | 204 |
| `func_00405030` | Matching | 100.00% | 172 |
| `func_004050E0` | Matching | 100.00% | 184 |
| `func_00405198` | Matching | 100.00% | 248 |
| `func_00405290` | Matching | 100.00% | 252 |
| `func_00405390` | Matching | 100.00% | 156 |
| `func_00405430` | Matching | 100.00% | 172 |
| `func_004054E0` | Matching | 100.00% | 220 |
| `func_004055C0` | Matching | 100.00% | 228 |
| `func_004056A8` | Matching | 100.00% | 212 |
| `func_00405780` | Matching | 100.00% | 208 |
| `func_00405850` | Matching | 100.00% | 288 |
| `func_00405970` | Matching | 100.00% | 276 |
| `func_00405A88` | Matching | 100.00% | 92 |
| `func_00405AE8` | Matching | 100.00% | 96 |
| `func_00405B48` | Matching | 100.00% | 40 |
| `func_00405E10` | Matching | 100.00% | 28 |
| `func_00405E30` | Matching | 100.00% | 388 |
| `func_00405FB8` | Matching | 100.00% | 272 |
| `_sliceA0` | Matching | 100.00% | 300 |
| `func_00406510` | Matching | 100.00% | 188 |
| `func_00406B00` | Matching | 100.00% | 412 |
| `func_00406DF0` | Matching | 100.00% | 44 |
| `func_00406E20` | Matching | 100.00% | 164 |
| `func_00406EC8` | Matching | 100.00% | 176 |
| `func_00406F78` | Matching | 100.00% | 376 |
| `func_004070F0` | Matching | 100.00% | 264 |
| `func_004071F8` | Matching | 100.00% | 240 |
| `func_004072E8` | Matching | 100.00% | 336 |
| `func_00407438` | Matching | 100.00% | 124 |
| `func_004074B8` | Matching | 100.00% | 100 |
| `func_00407520` | Matching | 100.00% | 268 |
| `func_00407630` | Matching | 100.00% | 196 |
| `func_004076F8` | Matching | 100.00% | 296 |
| `func_00407A10` | Matching | 100.00% | 72 |
| `func_00407A58` | Matching | 100.00% | 116 |
| `func_00407AD0` | Matching | 100.00% | 160 |
| `func_00407B70` | Matching | 100.00% | 196 |
| `func_00407C38` | Matching | 100.00% | 244 |
| `func_00407D30` | Matching | 100.00% | 144 |
| `func_00407DC0` | Matching | 100.00% | 204 |
| `func_00407E90` | Matching | 100.00% | 144 |
| `func_004081D8` | Matching | 100.00% | 160 |
| `func_00408508` | Matching | 100.00% | 40 |
| `func_00408530` | Matching | 100.00% | 396 |
| `func_00408988` | Matching | 100.00% | 364 |
| `func_00408AF8` | Matching | 100.00% | 132 |
| `func_00408B80` | Matching | 100.00% | 296 |
| `func_00409310` | Matching | 100.00% | 116 |
| `func_00409388` | Matching | 100.00% | 116 |
| `func_00409400` | Matching | 100.00% | 228 |
| `func_004094E8` | Matching | 100.00% | 336 |
| `func_00409638` | Matching | 100.00% | 104 |
| `func_004096A0` | Matching | 100.00% | 100 |
| `func_00409708` | Matching | 100.00% | 568 |
| `func_00409940` | Matching | 100.00% | 460 |
| `func_00409B10` | Matching | 100.00% | 76 |
| `func_00409B60` | Matching | 100.00% | 48 |
| `func_00409B90` | Matching | 100.00% | 184 |
| `func_00409C48` | Matching | 100.00% | 196 |
| `func_00409E38` | Matching | 100.00% | 52 |
| `func_00409E70` | Matching | 100.00% | 184 |
| `func_00409F28` | Matching | 100.00% | 216 |
| `func_0040A000` | Matching | 100.00% | 144 |
| `func_0040A090` | Matching | 100.00% | 276 |
| `func_0040A320` | Matching | 100.00% | 8 |
| `func_0040A328` | Matching | 100.00% | 56 |
| `func_0040A360` | Matching | 100.00% | 224 |
| `func_0040A440` | Matching | 100.00% | 84 |
| `func_0040A498` | Matching | 100.00% | 380 |
| `func_0040A618` | Matching | 100.00% | 108 |
| `func_0040A688` | Matching | 100.00% | 328 |
| `func_0040A7D0` | Matching | 100.00% | 132 |
| `func_0040A858` | Matching | 100.00% | 320 |
| `func_0040A998` | Matching | 100.00% | 204 |
| `func_0040AB80` | Matching | 100.00% | 184 |
| `func_0040AC38` | Matching | 100.00% | 456 |
| `func_0040AE00` | Matching | 100.00% | 344 |
| `func_0040AF58` | Matching | 100.00% | 204 |
| `func_0040B028` | Matching | 100.00% | 264 |
| `func_0040B1F8` | Matching | 100.00% | 12 |
| `func_0040B208` | Matching | 100.00% | 168 |
| `func_0040B2B0` | Matching | 100.00% | 28 |
| `func_0040B2D0` | Matching | 100.00% | 264 |
| `func_0040B3D8` | Matching | 100.00% | 36 |
| `func_0040B400` | Matching | 100.00% | 428 |
| `func_0040B938` | Matching | 100.00% | 112 |
| `func_0040B9A8` | Matching | 100.00% | 64 |
| `func_0040B9E8` | Matching | 100.00% | 96 |
| `func_0040BA68` | Matching | 100.00% | 64 |
| `func_0040BAA8` | Matching | 100.00% | 60 |
| `func_0040BAE8` | Matching | 100.00% | 76 |
| `func_0040BB38` | Matching | 100.00% | 100 |
| `func_0040BBA0` | Matching | 100.00% | 104 |
| `func_0040BC08` | Matching | 100.00% | 104 |
| `func_0040BC70` | Matching | 100.00% | 44 |
| `func_0040BD28` | Matching | 100.00% | 104 |
| `func_0040BF48` | Matching | 100.00% | 140 |
| `func_0040BFD8` | Matching | 100.00% | 8 |
| `func_0040BFE0` | Matching | 100.00% | 72 |
| `func_0040C220` | Matching | 100.00% | 200 |
| `sceUsbKbGetInfo` | Matching | 100.00% | 168 |
| `sceUsbKbRead` | Matching | 100.00% | 220 |
| `sceUsbKbGetLocation` | Matching | 100.00% | 220 |
| `sceUsbKbSetLEDStatus` | Matching | 100.00% | 216 |
| `sceUsbKbSetLEDMode` | Matching | 100.00% | 252 |
| `func_0040C770` | Matching | 100.00% | 76 |
| `func_0040C7C0` | Matching | 100.00% | 76 |
| `func_0040C8B0` | Matching | 100.00% | 12 |
| `func_0040C8C0` | Matching | 100.00% | 100 |
| `func_0040C928` | Matching | 100.00% | 88 |
| `func_0040CEF8` | Matching | 100.00% | 76 |
| `func_0040CF48` | Matching | 100.00% | 32 |
| `func_0040CF68` | Matching | 100.00% | 32 |
| `func_0040CF88` | Matching | 100.00% | 132 |
| `func_0040D010` | Matching | 100.00% | 48 |
| `func_0040D040` | Matching | 100.00% | 108 |
| `func_0040D0B0` | Matching | 100.00% | 104 |
| `func_0040D118` | Matching | 100.00% | 332 |
| `func_0040D268` | Matching | 100.00% | 344 |
| `func_0040D430` | Matching | 100.00% | 108 |
| `func_0040D4A0` | Matching | 100.00% | 232 |
| `func_0040D588` | Matching | 100.00% | 136 |
| `func_0040F878` | Matching | 100.00% | 36 |
| `func_0040F8A0` | Matching | 100.00% | 28 |
| `func_0040F9F8` | Matching | 100.00% | 352 |
| `func_0040FB58` | Matching | 100.00% | 48 |
| `func_0040FB88` | Matching | 100.00% | 84 |
| `func_0040FBE0` | Matching | 100.00% | 176 |
| `func_0040FC90` | Matching | 100.00% | 32 |
| `func_004011E0` | Matching | 99.95% | 368 |
| `func_004014F8` | Matching | 99.95% | 368 |
| `func_004086C0` | Matching | 99.93% | 272 |
| `func_00400190` | Matching | 99.90% | 192 |
| `func_00402E10` | Matching | 99.89% | 368 |
| `func_00406318` | Matching | 99.88% | 504 |
| `func_00406CA0` | Matching | 99.88% | 332 |
| `func_0040D610` | Matching | 99.88% | 328 |
| `func_00409D10` | Matching | 99.86% | 292 |
| `func_004060C8` | Matching | 99.86% | 288 |
| `func_0040AA68` | Matching | 99.86% | 280 |
| `func_003FE4D8` | Matching | 99.84% | 128 |
| `func_003FE458` | Matching | 99.84% | 124 |
| `func_003FE320` | Matching | 99.83% | 116 |
| `func_003FE398` | Matching | 99.83% | 116 |
| `func_003FE2B8` | Matching | 99.81% | 104 |
| `func_003FE410` | Matching | 99.72% | 72 |
| `func_003FE558` | Matching | 99.64% | 56 |
| `func_003FE6A8` | Matching | 99.58% | 96 |
| `func_003FEBD8` | Matching | 99.58% | 96 |
| `func_0040BEF0` | Matching | 99.58% | 48 |
| `func_003FED60` | Matching | 99.44% | 36 |
| `func_0040BF20` | Matching | 99.44% | 36 |
| `func_004011C0` | Matching | 99.29% | 28 |
| `func_0040BCC0` | Matching | 98.85% | 104 |

### `seg/seg_3113A0_eh`

24 matching, 0 partial, 5 not started (29 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_004103A0` | Matching | 100.00% | 16 |
| `func_004103B0` | Matching | 100.00% | 36 |
| `func_004103D8` | Matching | 100.00% | 44 |
| `func_00410408` | Matching | 100.00% | 8 |
| `func_00410410` | Matching | 100.00% | 84 |
| `func_00410468` | Matching | 100.00% | 36 |
| `func_00410490` | Matching | 100.00% | 40 |
| `func_004104B8` | Matching | 100.00% | 40 |
| `func_004104E0` | Matching | 100.00% | 104 |
| `func_00410548` | Matching | 100.00% | 40 |
| `func_00410570` | Matching | 100.00% | 376 |
| `func_004106E8` | Matching | 100.00% | 280 |
| `func_00410800` | Matching | 100.00% | 72 |
| `func_00410848` | Matching | 100.00% | 8 |
| `func_00410850` | Matching | 100.00% | 8 |
| `func_00410858` | Matching | 100.00% | 216 |
| `func_00410930` | Matching | 100.00% | 324 |
| `func_00410A78` | Matching | 100.00% | 136 |
| `func_00410B00` | Matching | 100.00% | 124 |
| `func_00410B80` | Matching | 100.00% | 140 |
| `func_00410C10` | Matching | 100.00% | 8 |
| `func_00410C18` | Matching | 100.00% | 816 |
| `func_00410F48` | Matching | 100.00% | 476 |
| `func_00411128` | Matching | 100.00% | 484 |

### `seg/seg_312310`

21 matching, 0 partial, 0 not started (21 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00411310` | Matching | 100.00% | 48 |
| `func_00411340` | Matching | 100.00% | 244 |
| `func_00411438` | Matching | 100.00% | 152 |
| `func_004114D0` | Matching | 100.00% | 96 |
| `func_00411530` | Matching | 100.00% | 8 |
| `func_00411538` | Matching | 100.00% | 1488 |
| `func_00411B08` | Matching | 100.00% | 300 |
| `func_00411C38` | Matching | 100.00% | 156 |
| `func_00411CD8` | Matching | 100.00% | 576 |
| `func_00411F18` | Matching | 100.00% | 88 |
| `func_00411F70` | Matching | 100.00% | 100 |
| `func_00411FD8` | Matching | 100.00% | 680 |
| `func_00412280` | Matching | 100.00% | 360 |
| `func_004123E8` | Matching | 100.00% | 276 |
| `func_00412500` | Matching | 100.00% | 76 |
| `func_00412550` | Matching | 100.00% | 184 |
| `func_00412608` | Matching | 100.00% | 148 |
| `func_004126A0` | Matching | 100.00% | 160 |
| `func_00412740` | Matching | 100.00% | 56 |
| `func_00412778` | Matching | 100.00% | 44 |
| `func_004127A8` | Matching | 100.00% | 84 |

### `seg/seg_313800_exception`

25 matching, 0 partial, 0 not started (25 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00412800` | Matching | 100.00% | 24 |
| `func_00412818` | Matching | 100.00% | 16 |
| `func_00412828` | Matching | 100.00% | 16 |
| `func_00412838` | Matching | 100.00% | 16 |
| `func_00412848` | Matching | 100.00% | 24 |
| `func_00412860` | Matching | 100.00% | 36 |
| `func_00412888` | Matching | 100.00% | 32 |
| `func_004128A8` | Matching | 100.00% | 56 |
| `func_004128E0` | Matching | 100.00% | 40 |
| `func_00412908` | Matching | 100.00% | 28 |
| `func_00412928` | Matching | 100.00% | 108 |
| `func_00412998` | Matching | 100.00% | 144 |
| `func_00412A28` | Matching | 100.00% | 196 |
| `func_00412AF0` | Matching | 100.00% | 48 |
| `func_00412B20` | Matching | 100.00% | 436 |
| `func_00412CD8` | Matching | 100.00% | 128 |
| `func_00412D58` | Matching | 100.00% | 128 |
| `func_00412DD8` | Matching | 100.00% | 52 |
| `func_00412E10` | Matching | 100.00% | 40 |
| `func_00412E38` | Matching | 100.00% | 48 |
| `func_00412E68` | Matching | 100.00% | 20 |
| `func_00412E80` | Matching | 100.00% | 80 |
| `func_00412ED0` | Matching | 100.00% | 48 |
| `func_00412F00` | Matching | 100.00% | 20 |
| `func_00412F18` | Matching | 100.00% | 64 |

### `seg/seg_313F58`

33 matching, 0 partial, 0 not started (33 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00412F58` | Matching | 100.00% | 268 |
| `func_00413068` | Matching | 100.00% | 144 |
| `func_004130F8` | Matching | 100.00% | 564 |
| `func_00413330` | Matching | 100.00% | 88 |
| `func_00413388` | Matching | 100.00% | 100 |
| `func_004133F0` | Matching | 100.00% | 500 |
| `func_004135E8` | Matching | 100.00% | 352 |
| `func_00413748` | Matching | 100.00% | 276 |
| `func_00413860` | Matching | 100.00% | 76 |
| `func_004138B0` | Matching | 100.00% | 184 |
| `func_00413968` | Matching | 100.00% | 140 |
| `func_004139F8` | Matching | 100.00% | 152 |
| `func_00413A90` | Matching | 100.00% | 56 |
| `func_00413AC8` | Matching | 100.00% | 44 |
| `func_00413AF8` | Matching | 100.00% | 64 |
| `func_00413B38` | Matching | 100.00% | 68 |
| `func_00413B80` | Matching | 100.00% | 80 |
| `func_00413BD0` | Matching | 100.00% | 252 |
| `func_00413CD0` | Matching | 100.00% | 612 |
| `func_00413F38` | Matching | 100.00% | 72 |
| `func_00413F80` | Matching | 100.00% | 136 |
| `func_00414008` | Matching | 100.00% | 316 |
| `func_00414148` | Matching | 100.00% | 228 |
| `func_00414230` | Matching | 100.00% | 260 |
| `func_00414338` | Matching | 100.00% | 920 |
| `func_004146D0` | Matching | 100.00% | 40 |
| `func_004146F8` | Matching | 100.00% | 48 |
| `func_00414728` | Matching | 100.00% | 40 |
| `func_00414750` | Matching | 100.00% | 48 |
| `func_00414780` | Matching | 100.00% | 120 |
| `func_004147F8` | Matching | 100.00% | 32 |
| `func_00414818` | Matching | 100.00% | 472 |
| `func_004149F0` | Matching | 100.00% | 372 |

### `seg/seg_315B68_tinfo`

68 matching, 0 partial, 0 not started (68 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00414B68` | Matching | 100.00% | 48 |
| `func_00414B98` | Matching | 100.00% | 64 |
| `func_00414BD8` | Matching | 100.00% | 36 |
| `func_00414C00` | Matching | 100.00% | 32 |
| `func_00414C20` | Matching | 100.00% | 28 |
| `func_00414C40` | Matching | 100.00% | 44 |
| `func_00414C70` | Matching | 100.00% | 148 |
| `func_00414D08` | Matching | 100.00% | 472 |
| `func_00414EE0` | Matching | 100.00% | 32 |
| `func_00414F00` | Matching | 100.00% | 80 |
| `func_00414F50` | Matching | 100.00% | 28 |
| `func_00414F70` | Matching | 100.00% | 28 |
| `func_00414F90` | Matching | 100.00% | 80 |
| `func_00414FE0` | Matching | 100.00% | 28 |
| `func_00415000` | Matching | 100.00% | 24 |
| `func_00415018` | Matching | 100.00% | 80 |
| `func_00415068` | Matching | 100.00% | 28 |
| `func_00415088` | Matching | 100.00% | 48 |
| `func_004150B8` | Matching | 100.00% | 20 |
| `func_004150D0` | Matching | 100.00% | 80 |
| `func_00415120` | Matching | 100.00% | 48 |
| `func_00415150` | Matching | 100.00% | 20 |
| `func_00415168` | Matching | 100.00% | 80 |
| `func_004151B8` | Matching | 100.00% | 32 |
| `func_004151D8` | Matching | 100.00% | 8 |
| `func_004151E0` | Matching | 100.00% | 24 |
| `func_004151F8` | Matching | 100.00% | 64 |
| `func_00415238` | Matching | 100.00% | 36 |
| `func_00415260` | Matching | 100.00% | 1224 |
| `func_00415728` | Matching | 100.00% | 80 |
| `func_00415778` | Matching | 100.00% | 32 |
| `func_00415798` | Matching | 100.00% | 36 |
| `func_004157C0` | Matching | 100.00% | 28 |
| `func_004157E0` | Matching | 100.00% | 28 |
| `func_00415800` | Matching | 100.00% | 28 |
| `func_00415820` | Matching | 100.00% | 28 |
| `func_00415840` | Matching | 100.00% | 172 |
| `func_004158F0` | Matching | 100.00% | 52 |
| `func_00415928` | Matching | 100.00% | 52 |
| `func_00415960` | Matching | 100.00% | 52 |
| `func_00415998` | Matching | 100.00% | 52 |
| `func_004159D0` | Matching | 100.00% | 52 |
| `func_00415A08` | Matching | 100.00% | 52 |
| `func_00415A40` | Matching | 100.00% | 52 |
| `func_00415A78` | Matching | 100.00% | 52 |
| `func_00415AB0` | Matching | 100.00% | 52 |
| `func_00415AE8` | Matching | 100.00% | 52 |
| `func_00415B20` | Matching | 100.00% | 52 |
| `func_00415B58` | Matching | 100.00% | 52 |
| `func_00415B90` | Matching | 100.00% | 52 |
| `func_00415BC8` | Matching | 100.00% | 52 |
| `func_00415C00` | Matching | 100.00% | 52 |
| `func_00415C38` | Matching | 100.00% | 52 |
| `func_00415C70` | Matching | 100.00% | 52 |
| `func_00415CA8` | Matching | 100.00% | 80 |
| `func_00415CF8` | Matching | 100.00% | 28 |
| `func_00415D18` | Matching | 100.00% | 80 |
| `func_00415D68` | Matching | 100.00% | 28 |
| `func_00415D88` | Matching | 100.00% | 80 |
| `func_00415DD8` | Matching | 100.00% | 28 |
| `func_00415DF8` | Matching | 100.00% | 80 |
| `func_00415E48` | Matching | 100.00% | 28 |
| `func_00415E68` | Matching | 100.00% | 80 |
| `func_00415EB8` | Matching | 100.00% | 28 |
| `func_00415ED8` | Matching | 100.00% | 80 |
| `func_00415F28` | Matching | 100.00% | 28 |
| `func_00415F48` | Matching | 100.00% | 80 |
| `func_00415F98` | Matching | 100.00% | 28 |

### `seg/seg_316FB8`

137 matching, 0 partial, 0 not started (137 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00415FB8` | Matching | 100.00% | 12 |
| `func_00415FC8` | Matching | 100.00% | 148 |
| `func_0041605C` | Matching | 100.00% | 176 |
| `func_0041610C` | Matching | 100.00% | 260 |
| `func_00416210` | Matching | 100.00% | 192 |
| `func_004162D0` | Matching | 100.00% | 308 |
| `strchr` | Matching | 100.00% | 420 |
| `func_004165A8` | Matching | 100.00% | 332 |
| `strcpy` | Matching | 100.00% | 284 |
| `strlen` | Matching | 100.00% | 328 |
| `func_00416958` | Matching | 100.00% | 444 |
| `func_00416B18` | Matching | 100.00% | 456 |
| `strncpy` | Matching | 100.00% | 460 |
| `func_00416EB0` | Matching | 100.00% | 220 |
| `func_00416F90` | Matching | 100.00% | 44 |
| `func_00416FC0` | Matching | 100.00% | 32 |
| `func_00416FE0` | Matching | 100.00% | 36 |
| `func_00417008` | Matching | 100.00% | 1036 |
| `func_00417418` | Matching | 100.00% | 148 |
| `func_004174B0` | Matching | 100.00% | 196 |
| `func_00417578` | Matching | 100.00% | 76 |
| `func_004175C8` | Matching | 100.00% | 96 |
| `func_00417628` | Matching | 100.00% | 28 |
| `func_00417648` | Matching | 100.00% | 360 |
| `func_004177B0` | Matching | 100.00% | 120 |
| `sprintf` | Matching | 100.00% | 128 |
| `func_004178A8` | Matching | 100.00% | 8 |
| `func_004178B0` | Matching | 100.00% | 152 |
| `func_00417948` | Matching | 100.00% | 100 |
| `func_004179B0` | Matching | 100.00% | 128 |
| `func_00417A30` | Matching | 100.00% | 104 |
| `func_00417A98` | Matching | 100.00% | 32 |
| `func_004185D0` | Matching | 100.00% | 244 |
| `func_004186C8` | Matching | 100.00% | 84 |
| `func_00418720` | Matching | 100.00% | 108 |
| `func_00418790` | Matching | 100.00% | 16 |
| `func_004187A0` | Matching | 100.00% | 28 |
| `func_004187C0` | Matching | 100.00% | 40 |
| `func_004187E8` | Matching | 100.00% | 212 |
| `func_004188C0` | Matching | 100.00% | 80 |
| `func_00418910` | Matching | 100.00% | 72 |
| `func_00418958` | Matching | 100.00% | 844 |
| `func_00418CA8` | Matching | 100.00% | 96 |
| `func_00418D08` | Matching | 100.00% | 64 |
| `func_00418D48` | Matching | 100.00% | 28 |
| `func_00418D68` | Matching | 100.00% | 80 |
| `func_00418DB8` | Matching | 100.00% | 64 |
| `func_00418DF8` | Matching | 100.00% | 28 |
| `func_00418E18` | Matching | 100.00% | 80 |
| `func_00418E68` | Matching | 100.00% | 140 |
| `func_00418EF8` | Matching | 100.00% | 2524 |
| `func_004198D8` | Matching | 100.00% | 3856 |
| `func_0041A7E8` | Matching | 100.00% | 44 |
| `func_0041A818` | Matching | 100.00% | 36 |
| `func_0041A840` | Matching | 100.00% | 528 |
| `func_0041AA50` | Matching | 100.00% | 52 |
| `func_0041AA88` | Matching | 100.00% | 124 |
| `func_0041AB08` | Matching | 100.00% | 112 |
| `func_0041AB78` | Matching | 100.00% | 196 |
| `func_0041AC40` | Matching | 100.00% | 128 |
| `func_0041ACC0` | Matching | 100.00% | 76 |
| `func_0041AD10` | Matching | 100.00% | 112 |
| `func_0041AD80` | Matching | 100.00% | 124 |
| `func_0041AE00` | Matching | 100.00% | 112 |
| `func_0041AE70` | Matching | 100.00% | 120 |
| `func_0041AEE8` | Matching | 100.00% | 156 |
| `func_0041AF88` | Matching | 100.00% | 1440 |
| `func_0041B528` | Matching | 100.00% | 40 |
| `func_0041B550` | Matching | 100.00% | 264 |
| `func_0041B658` | Matching | 100.00% | 204 |
| `func_0041B728` | Matching | 100.00% | 4192 |
| `func_0041C788` | Matching | 100.00% | 432 |
| `func_0041C938` | Matching | 100.00% | 264 |
| `func_0041CA40` | Matching | 100.00% | 48 |
| `func_0041CA70` | Matching | 100.00% | 3872 |
| `func_0041D990` | Matching | 100.00% | 612 |
| `func_0041DBF8` | Matching | 100.00% | 1860 |
| `func_0041E340` | Matching | 100.00% | 756 |
| `func_0041E638` | Matching | 100.00% | 364 |
| `func_0041E7A8` | Matching | 100.00% | 564 |
| `func_0041E9E0` | Matching | 100.00% | 52 |
| `func_0041EA18` | Matching | 100.00% | 32 |
| `func_0041EA38` | Matching | 100.00% | 464 |
| `func_0041EC08` | Matching | 100.00% | 12 |
| `func_0041EC18` | Matching | 100.00% | 44 |
| `func_0041EC48` | Matching | 100.00% | 36 |
| `func_0041EC70` | Matching | 100.00% | 240 |
| `func_0041ED60` | Matching | 100.00% | 492 |
| `func_0041EF50` | Matching | 100.00% | 1108 |
| `func_0041F3A8` | Matching | 100.00% | 1580 |
| `func_0041F9D8` | Matching | 100.00% | 448 |
| `func_0041FB98` | Matching | 100.00% | 88 |
| `func_0041FBF0` | Matching | 100.00% | 92 |
| `func_0041FC50` | Matching | 100.00% | 96 |
| `func_0041FCB0` | Matching | 100.00% | 96 |
| `func_0041FD10` | Matching | 100.00% | 96 |
| `func_0041FD70` | Matching | 100.00% | 92 |
| `func_0041FDD0` | Matching | 100.00% | 96 |
| `func_0041FE30` | Matching | 100.00% | 268 |
| `func_0041FF40` | Matching | 100.00% | 88 |
| `func_0041FF98` | Matching | 100.00% | 116 |
| `func_00420010` | Matching | 100.00% | 224 |
| `func_004200F0` | Matching | 100.00% | 140 |
| `func_00420180` | Matching | 100.00% | 168 |
| `func_00420228` | Matching | 100.00% | 52 |
| `func_00420260` | Matching | 100.00% | 276 |
| `ungetc` | Matching | 100.00% | 404 |
| `func_00420510` | Matching | 100.00% | 168 |
| `func_004205B8` | Matching | 100.00% | 52 |
| `func_004205F0` | Matching | 100.00% | 264 |
| `func_004206F8` | Matching | 100.00% | 308 |
| `func_00420830` | Matching | 100.00% | 132 |
| `func_004208B8` | Matching | 100.00% | 192 |
| `func_00420978` | Matching | 100.00% | 56 |
| `func_004209B0` | Matching | 100.00% | 532 |
| `func_00420BC8` | Matching | 100.00% | 256 |
| `func_00420CC8` | Matching | 100.00% | 352 |
| `func_00420E28` | Matching | 100.00% | 104 |
| `func_00420E90` | Matching | 100.00% | 400 |
| `func_00421020` | Matching | 100.00% | 200 |
| `func_004210E8` | Matching | 100.00% | 408 |
| `func_00421280` | Matching | 100.00% | 380 |
| `func_00421400` | Matching | 100.00% | 192 |
| `func_004214C0` | Matching | 100.00% | 112 |
| `func_00421530` | Matching | 100.00% | 440 |
| `func_004216E8` | Matching | 100.00% | 492 |
| `func_00421A50` | Matching | 100.00% | 328 |
| `func_00421B98` | Matching | 100.00% | 712 |
| `func_00421E60` | Matching | 100.00% | 188 |
| `func_00421F20` | Matching | 100.00% | 1404 |
| `func_004224A0` | Matching | 100.00% | 188 |
| `func_00422560` | Matching | 100.00% | 540 |
| `func_00422780` | Matching | 100.00% | 4580 |
| `func_00423980` | Matching | 100.00% | 16 |
| `func_00423990` | Matching | 100.00% | 16 |
| `func_00417AB8` | Matching | 99.99% | 2836 |
| `func_004218D8` | Matching | 99.89% | 376 |

### `seg/seg_3249A0`

136 matching, 0 partial, 0 not started (136 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_004239A0` | Matching | 100.00% | 16 |
| `func_004239B0` | Matching | 100.00% | 16 |
| `func_004239C0` | Matching | 100.00% | 16 |
| `func_004239D0` | Matching | 100.00% | 16 |
| `func_004239E0` | Matching | 100.00% | 16 |
| `func_004239F0` | Matching | 100.00% | 16 |
| `func_00423A00` | Matching | 100.00% | 16 |
| `func_00423A10` | Matching | 100.00% | 16 |
| `func_00423A20` | Matching | 100.00% | 16 |
| `func_00423A30` | Matching | 100.00% | 16 |
| `func_00423A40` | Matching | 100.00% | 16 |
| `func_00423A50` | Matching | 100.00% | 16 |
| `func_00423A60` | Matching | 100.00% | 16 |
| `func_00423A70` | Matching | 100.00% | 16 |
| `func_00423A80` | Matching | 100.00% | 16 |
| `func_00423A90` | Matching | 100.00% | 16 |
| `func_00423AA0` | Matching | 100.00% | 16 |
| `func_00423AB0` | Matching | 100.00% | 16 |
| `func_00423AC0` | Matching | 100.00% | 16 |
| `func_00423AD0` | Matching | 100.00% | 16 |
| `func_00423AE0` | Matching | 100.00% | 16 |
| `func_00423AF0` | Matching | 100.00% | 16 |
| `func_00423B00` | Matching | 100.00% | 16 |
| `func_00423B10` | Matching | 100.00% | 16 |
| `func_00423B20` | Matching | 100.00% | 16 |
| `func_00423B30` | Matching | 100.00% | 16 |
| `func_00423B40` | Matching | 100.00% | 16 |
| `func_00423B50` | Matching | 100.00% | 16 |
| `func_00423B60` | Matching | 100.00% | 16 |
| `func_00423B70` | Matching | 100.00% | 16 |
| `func_00423B80` | Matching | 100.00% | 16 |
| `func_00423B90` | Matching | 100.00% | 16 |
| `func_00423BA0` | Matching | 100.00% | 16 |
| `func_00423BB0` | Matching | 100.00% | 16 |
| `func_00423BC0` | Matching | 100.00% | 16 |
| `func_00423BD0` | Matching | 100.00% | 16 |
| `func_00423BE0` | Matching | 100.00% | 16 |
| `func_00423BF0` | Matching | 100.00% | 16 |
| `func_00423C00` | Matching | 100.00% | 16 |
| `func_00423C10` | Matching | 100.00% | 16 |
| `func_00423C20` | Matching | 100.00% | 16 |
| `func_00423C30` | Matching | 100.00% | 16 |
| `func_00423C40` | Matching | 100.00% | 16 |
| `func_00423C50` | Matching | 100.00% | 16 |
| `func_00423C60` | Matching | 100.00% | 16 |
| `func_00423C70` | Matching | 100.00% | 16 |
| `func_00423C80` | Matching | 100.00% | 16 |
| `func_00423C90` | Matching | 100.00% | 16 |
| `func_00423CA0` | Matching | 100.00% | 16 |
| `func_00423CB0` | Matching | 100.00% | 16 |
| `func_00423CC0` | Matching | 100.00% | 16 |
| `func_00423CD0` | Matching | 100.00% | 16 |
| `func_00423CE0` | Matching | 100.00% | 16 |
| `func_00423CF0` | Matching | 100.00% | 16 |
| `func_00423D00` | Matching | 100.00% | 16 |
| `func_00423D10` | Matching | 100.00% | 16 |
| `func_00423D20` | Matching | 100.00% | 16 |
| `func_00423D30` | Matching | 100.00% | 16 |
| `func_00423D40` | Matching | 100.00% | 16 |
| `func_00423D50` | Matching | 100.00% | 16 |
| `func_00423D60` | Matching | 100.00% | 16 |
| `func_00423D70` | Matching | 100.00% | 16 |
| `func_00423D80` | Matching | 100.00% | 16 |
| `func_00423D90` | Matching | 100.00% | 16 |
| `func_00423DA0` | Matching | 100.00% | 16 |
| `func_00423DB0` | Matching | 100.00% | 16 |
| `func_00423DC0` | Matching | 100.00% | 16 |
| `func_00423DD0` | Matching | 100.00% | 16 |
| `func_00423DE0` | Matching | 100.00% | 16 |
| `func_00423DF0` | Matching | 100.00% | 16 |
| `func_00423E00` | Matching | 100.00% | 16 |
| `func_00423E10` | Matching | 100.00% | 16 |
| `func_00423E20` | Matching | 100.00% | 16 |
| `func_00423E30` | Matching | 100.00% | 16 |
| `func_00423E40` | Matching | 100.00% | 16 |
| `func_00423E50` | Matching | 100.00% | 16 |
| `func_00423E60` | Matching | 100.00% | 16 |
| `func_00423E70` | Matching | 100.00% | 16 |
| `func_00423E80` | Matching | 100.00% | 16 |
| `func_00423E90` | Matching | 100.00% | 16 |
| `func_00423EA0` | Matching | 100.00% | 16 |
| `func_00423EB0` | Matching | 100.00% | 16 |
| `func_00423EC0` | Matching | 100.00% | 16 |
| `func_00423ED0` | Matching | 100.00% | 16 |
| `func_00423EE0` | Matching | 100.00% | 16 |
| `func_00423EF0` | Matching | 100.00% | 16 |
| `func_00423F00` | Matching | 100.00% | 16 |
| `func_00423F10` | Matching | 100.00% | 16 |
| `func_00423F20` | Matching | 100.00% | 16 |
| `func_00423F30` | Matching | 100.00% | 16 |
| `func_00423F40` | Matching | 100.00% | 16 |
| `func_00423F50` | Matching | 100.00% | 16 |
| `func_00423F60` | Matching | 100.00% | 16 |
| `func_00423F70` | Matching | 100.00% | 16 |
| `func_00423F80` | Matching | 100.00% | 16 |
| `func_00423F90` | Matching | 100.00% | 16 |
| `func_00423FA0` | Matching | 100.00% | 16 |
| `func_00423FB0` | Matching | 100.00% | 16 |
| `func_00423FC0` | Matching | 100.00% | 16 |
| `func_00423FD0` | Matching | 100.00% | 16 |
| `func_00423FE0` | Matching | 100.00% | 16 |
| `func_00423FF0` | Matching | 100.00% | 16 |
| `func_00424000` | Matching | 100.00% | 16 |
| `func_00424010` | Matching | 100.00% | 16 |
| `func_00424020` | Matching | 100.00% | 16 |
| `func_00424030` | Matching | 100.00% | 16 |
| `func_00424040` | Matching | 100.00% | 16 |
| `func_00424050` | Matching | 100.00% | 16 |
| `func_00424060` | Matching | 100.00% | 16 |
| `func_00424070` | Matching | 100.00% | 16 |
| `func_00424080` | Matching | 100.00% | 16 |
| `func_00424090` | Matching | 100.00% | 16 |
| `func_004240A0` | Matching | 100.00% | 16 |
| `func_004240B0` | Matching | 100.00% | 16 |
| `func_004240C0` | Matching | 100.00% | 16 |
| `func_004240D0` | Matching | 100.00% | 16 |
| `func_004240E0` | Matching | 100.00% | 16 |
| `func_004240F0` | Matching | 100.00% | 16 |
| `func_00424100` | Matching | 100.00% | 16 |
| `func_00424110` | Matching | 100.00% | 16 |
| `func_00424120` | Matching | 100.00% | 16 |
| `func_00424130` | Matching | 100.00% | 16 |
| `func_00424140` | Matching | 100.00% | 16 |
| `func_00424150` | Matching | 100.00% | 16 |
| `func_00424160` | Matching | 100.00% | 16 |
| `func_00424170` | Matching | 100.00% | 16 |
| `func_00424180` | Matching | 100.00% | 16 |
| `func_00424190` | Matching | 100.00% | 16 |
| `func_004241A0` | Matching | 100.00% | 16 |
| `func_004241B0` | Matching | 100.00% | 16 |
| `func_004241C0` | Matching | 100.00% | 16 |
| `func_004241D0` | Matching | 100.00% | 16 |
| `func_004241E0` | Matching | 100.00% | 16 |
| `func_004241F0` | Matching | 100.00% | 16 |
| `func_00424200` | Matching | 100.00% | 16 |
| `func_00424210` | Matching | 100.00% | 16 |

### `seg/seg_325220`

210 matching, 0 partial, 22 not started (232 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_00424220` | Matching | 100.00% | 12 |
| `func_00424368` | Matching | 100.00% | 124 |
| `func_004243E8` | Matching | 100.00% | 116 |
| `func_00424460` | Matching | 100.00% | 40 |
| `func_00424488` | Matching | 100.00% | 8 |
| `func_00424490` | Matching | 100.00% | 8 |
| `func_00424498` | Matching | 100.00% | 8 |
| `func_004244A0` | Matching | 100.00% | 172 |
| `func_00424550` | Matching | 100.00% | 8 |
| `func_00424558` | Matching | 100.00% | 20 |
| `func_00424570` | Matching | 100.00% | 8 |
| `func_00424578` | Matching | 100.00% | 40 |
| `func_004245A0` | Matching | 100.00% | 40 |
| `func_004245C8` | Matching | 100.00% | 40 |
| `func_004245F0` | Matching | 100.00% | 164 |
| `func_00424698` | Matching | 100.00% | 124 |
| `func_00424718` | Matching | 100.00% | 20 |
| `func_00424730` | Matching | 100.00% | 164 |
| `func_004247D8` | Matching | 100.00% | 124 |
| `func_00424858` | Matching | 100.00% | 20 |
| `func_00424870` | Matching | 100.00% | 16 |
| `func_00424880` | Matching | 100.00% | 104 |
| `func_004248E8` | Matching | 100.00% | 104 |
| `func_00424950` | Matching | 100.00% | 104 |
| `func_004249B8` | Matching | 100.00% | 104 |
| `func_00424A20` | Matching | 100.00% | 32 |
| `func_00424A40` | Matching | 100.00% | 32 |
| `func_00424A60` | Matching | 100.00% | 32 |
| `func_00424A80` | Matching | 100.00% | 32 |
| `func_00424AA0` | Matching | 100.00% | 216 |
| `func_00424B78` | Matching | 100.00% | 212 |
| `func_00424C50` | Matching | 100.00% | 148 |
| `func_00424CE8` | Matching | 100.00% | 124 |
| `func_00424D68` | Matching | 100.00% | 152 |
| `func_00424E00` | Matching | 100.00% | 36 |
| `func_00424E28` | Matching | 100.00% | 60 |
| `func_00424E68` | Matching | 100.00% | 60 |
| `func_00425190` | Matching | 100.00% | 208 |
| `func_00425358` | Matching | 100.00% | 176 |
| `func_00425CC0` | Matching | 100.00% | 28 |
| `func_00425CE0` | Matching | 100.00% | 12 |
| `func_00425CF0` | Matching | 100.00% | 24 |
| `func_00425D08` | Matching | 100.00% | 28 |
| `func_00425D28` | Matching | 100.00% | 12 |
| `func_00425FB8` | Matching | 100.00% | 52 |
| `func_00425FF0` | Matching | 100.00% | 24 |
| `func_00426008` | Matching | 100.00% | 24 |
| `func_00426020` | Matching | 100.00% | 44 |
| `func_00426050` | Matching | 100.00% | 40 |
| `func_00426078` | Matching | 100.00% | 308 |
| `func_004261B0` | Matching | 100.00% | 60 |
| `func_004261F0` | Matching | 100.00% | 60 |
| `func_00426358` | Matching | 100.00% | 172 |
| `func_004265A8` | Matching | 100.00% | 36 |
| `func_004265D0` | Matching | 100.00% | 168 |
| `func_00426678` | Matching | 100.00% | 28 |
| `func_00426698` | Matching | 100.00% | 48 |
| `func_004266C8` | Matching | 100.00% | 64 |
| `func_00426708` | Matching | 100.00% | 180 |
| `func_004267C0` | Matching | 100.00% | 96 |
| `func_00426820` | Matching | 100.00% | 208 |
| `func_004268F0` | Matching | 100.00% | 344 |
| `func_00426A48` | Matching | 100.00% | 76 |
| `func_00426A98` | Matching | 100.00% | 176 |
| `func_00426B48` | Matching | 100.00% | 320 |
| `func_00426C88` | Matching | 100.00% | 140 |
| `func_00426F08` | Matching | 100.00% | 60 |
| `func_00426F48` | Matching | 100.00% | 148 |
| `func_00426FE0` | Matching | 100.00% | 208 |
| `func_004270B0` | Matching | 100.00% | 148 |
| `func_00427148` | Matching | 100.00% | 144 |
| `func_004271D8` | Matching | 100.00% | 88 |
| `func_00427230` | Matching | 100.00% | 452 |
| `func_004273F8` | Matching | 100.00% | 64 |
| `func_00427438` | Matching | 100.00% | 92 |
| `func_00427498` | Matching | 100.00% | 136 |
| `func_00427520` | Matching | 100.00% | 108 |
| `func_00427938` | Matching | 100.00% | 76 |
| `func_00427988` | Matching | 100.00% | 44 |
| `func_004279B8` | Matching | 100.00% | 12 |
| `func_004279C8` | Matching | 100.00% | 152 |
| `func_00427A60` | Matching | 100.00% | 44 |
| `func_00427C98` | Matching | 100.00% | 140 |
| `func_00427D28` | Matching | 100.00% | 52 |
| `func_00428FC0` | Matching | 100.00% | 28 |
| `func_00429190` | Matching | 100.00% | 28 |
| `func_00429540` | Matching | 100.00% | 28 |
| `func_00429560` | Matching | 100.00% | 200 |
| `func_00429EB8` | Matching | 100.00% | 28 |
| `func_0042A2E0` | Matching | 100.00% | 28 |
| `func_0042AB18` | Matching | 100.00% | 136 |
| `func_0042AD08` | Matching | 100.00% | 28 |
| `func_0042B168` | Matching | 100.00% | 140 |
| `func_0042B1F8` | Matching | 100.00% | 56 |
| `func_0042B800` | Matching | 100.00% | 28 |
| `func_0042B820` | Matching | 100.00% | 28 |
| `func_0042BA68` | Matching | 100.00% | 32 |
| `func_0042BA88` | Matching | 100.00% | 28 |
| `func_0042BBB0` | Matching | 100.00% | 28 |
| `func_0042BBD0` | Matching | 100.00% | 40 |
| `func_0042BF08` | Matching | 100.00% | 40 |
| `func_0042BF30` | Matching | 100.00% | 56 |
| `func_0042C0C0` | Matching | 100.00% | 24 |
| `func_0042C0D8` | Matching | 100.00% | 72 |
| `func_0042C120` | Matching | 100.00% | 16 |
| `func_0042C130` | Matching | 100.00% | 56 |
| `func_0042C168` | Matching | 100.00% | 64 |
| `func_0042C1A8` | Matching | 100.00% | 16 |
| `func_0042C1B8` | Matching | 100.00% | 52 |
| `func_0042C1F0` | Matching | 100.00% | 252 |
| `func_0042C2F0` | Matching | 100.00% | 16 |
| `func_0042C300` | Matching | 100.00% | 60 |
| `func_0042C340` | Matching | 100.00% | 16 |
| `func_0042C350` | Matching | 100.00% | 16 |
| `func_0042C360` | Matching | 100.00% | 56 |
| `func_0042C398` | Matching | 100.00% | 16 |
| `func_0042C3A8` | Matching | 100.00% | 104 |
| `func_0042C410` | Matching | 100.00% | 172 |
| `func_0042C4C0` | Matching | 100.00% | 16 |
| `func_0042C4D0` | Matching | 100.00% | 48 |
| `func_0042C500` | Matching | 100.00% | 16 |
| `func_0042C510` | Matching | 100.00% | 280 |
| `func_0042C628` | Matching | 100.00% | 8 |
| `func_0042C630` | Matching | 100.00% | 112 |
| `func_0042C6A0` | Matching | 100.00% | 72 |
| `func_0042C6E8` | Matching | 100.00% | 40 |
| `func_0042C710` | Matching | 100.00% | 76 |
| `func_0042C760` | Matching | 100.00% | 16 |
| `func_0042C770` | Matching | 100.00% | 16 |
| `func_0042C780` | Matching | 100.00% | 56 |
| `func_0042C7B8` | Matching | 100.00% | 16 |
| `func_0042C7C8` | Matching | 100.00% | 212 |
| `func_0042C8A0` | Matching | 100.00% | 68 |
| `func_0042C8E8` | Matching | 100.00% | 36 |
| `func_0042C910` | Matching | 100.00% | 48 |
| `func_0042C940` | Matching | 100.00% | 36 |
| `func_0042C968` | Matching | 100.00% | 52 |
| `func_0042C9A0` | Matching | 100.00% | 52 |
| `func_0042C9D8` | Matching | 100.00% | 48 |
| `func_0042CA08` | Matching | 100.00% | 36 |
| `func_0042CA30` | Matching | 100.00% | 36 |
| `func_0042CA58` | Matching | 100.00% | 36 |
| `func_0042CA80` | Matching | 100.00% | 96 |
| `func_0042CAE0` | Matching | 100.00% | 132 |
| `func_0042CB68` | Matching | 100.00% | 16 |
| `func_0042CB78` | Matching | 100.00% | 56 |
| `func_0042CBB0` | Matching | 100.00% | 16 |
| `func_0042CBC0` | Matching | 100.00% | 16 |
| `func_0042CBD0` | Matching | 100.00% | 196 |
| `func_0042CC98` | Matching | 100.00% | 16 |
| `func_0042CCA8` | Matching | 100.00% | 16 |
| `func_0042CCB8` | Matching | 100.00% | 16 |
| `func_0042CCC8` | Matching | 100.00% | 48 |
| `func_0042CCF8` | Matching | 100.00% | 16 |
| `func_0042CD08` | Matching | 100.00% | 16 |
| `func_0042CD18` | Matching | 100.00% | 16 |
| `func_0042CD28` | Matching | 100.00% | 16 |
| `func_0042CD38` | Matching | 100.00% | 16 |
| `func_0042CD48` | Matching | 100.00% | 16 |
| `func_0042CD58` | Matching | 100.00% | 64 |
| `func_0042CD98` | Matching | 100.00% | 500 |
| `func_0042CFC0` | Matching | 100.00% | 860 |
| `func_0042D320` | Matching | 100.00% | 92 |
| `func_0042D470` | Matching | 100.00% | 1640 |
| `func_0042DAD8` | Matching | 100.00% | 1344 |
| `func_00427D60` | Matching | 99.97% | 644 |
| `func_004291B0` | Matching | 99.97% | 620 |
| `func_0042A070` | Matching | 99.97% | 620 |
| `func_004283A0` | Matching | 99.97% | 608 |
| `func_00429A88` | Matching | 99.97% | 572 |
| `func_0042A538` | Matching | 99.96% | 568 |
| `func_00428600` | Matching | 99.96% | 704 |
| `func_00429CC8` | Matching | 99.96% | 496 |
| `func_0042A770` | Matching | 99.96% | 480 |
| `func_00428C38` | Matching | 99.96% | 476 |
| `func_00428168` | Matching | 99.96% | 568 |
| `func_0042A300` | Matching | 99.96% | 568 |
| `func_0042A950` | Matching | 99.96% | 456 |
| `func_0042B230` | Matching | 99.95% | 520 |
| `func_0042B438` | Matching | 99.95% | 520 |
| `func_00428FE0` | Matching | 99.95% | 428 |
| `func_00428E18` | Matching | 99.95% | 420 |
| `func_004298E8` | Matching | 99.95% | 416 |
| `func_00429ED8` | Matching | 99.95% | 408 |
| `func_00427FE8` | Matching | 99.95% | 380 |
| `func_00429628` | Matching | 99.94% | 360 |
| `func_00429790` | Matching | 99.94% | 344 |
| `func_00429420` | Matching | 99.93% | 288 |
| `func_0042B068` | Matching | 99.92% | 256 |
| `func_0042AD28` | Matching | 99.92% | 240 |
| `func_0042BBF8` | Matching | 99.92% | 236 |
| `func_0042BCE8` | Matching | 99.91% | 220 |
| `func_0042B840` | Matching | 99.88% | 548 |
| `func_0042B640` | Matching | 99.86% | 144 |
| `func_0042B770` | Matching | 99.86% | 144 |
| `func_0042AC10` | Matching | 99.84% | 128 |
| `func_0042AF68` | Matching | 99.84% | 124 |
| `func_0042AFE8` | Matching | 99.84% | 124 |
| `func_0042AC90` | Matching | 99.83% | 120 |
| `func_0042ABA0` | Matching | 99.82% | 112 |
| `func_0042AE18` | Matching | 99.82% | 112 |
| `func_0042AE88` | Matching | 99.82% | 112 |
| `func_0042AEF8` | Matching | 99.82% | 112 |
| `func_00425C60` | Matching | 99.79% | 96 |
| `func_0042BAA8` | Matching | 99.77% | 260 |
| `func_00425C28` | Matching | 99.64% | 56 |
| `func_0042B6D0` | Matching | 99.62% | 160 |
| `func_004254D0` | Matching | 99.61% | 360 |
| `func_0042D380` | Matching | 99.07% | 236 |
| `func_00425408` | Matching | 98.85% | 52 |

### `seg/seg_32F020`

30 matching, 0 partial, 0 not started (30 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_0042E020` | Matching | 100.00% | 144 |
| `func_0042E0B0` | Matching | 100.00% | 8 |
| `func_0042E0B8` | Matching | 100.00% | 8 |
| `func_0042E0C0` | Matching | 100.00% | 8 |
| `func_0042E0C8` | Matching | 100.00% | 8 |
| `func_0042E0D0` | Matching | 100.00% | 36 |
| `func_0042E0F8` | Matching | 100.00% | 36 |
| `func_0042E120` | Matching | 100.00% | 44 |
| `func_0042E150` | Matching | 100.00% | 44 |
| `func_0042E180` | Matching | 100.00% | 60 |
| `func_0042E1C0` | Matching | 100.00% | 60 |
| `func_0042E200` | Matching | 100.00% | 120 |
| `func_0042E278` | Matching | 100.00% | 56 |
| `func_0042E2B0` | Matching | 100.00% | 64 |
| `func_0042E2F0` | Matching | 100.00% | 8 |
| `func_0042E2F8` | Matching | 100.00% | 12 |
| `func_0042E308` | Matching | 100.00% | 8 |
| `func_0042E310` | Matching | 100.00% | 8 |
| `func_0042E318` | Matching | 100.00% | 8 |
| `func_0042E320` | Matching | 100.00% | 8 |
| `func_0042E328` | Matching | 100.00% | 36 |
| `func_0042E350` | Matching | 100.00% | 36 |
| `func_0042E378` | Matching | 100.00% | 44 |
| `func_0042E3A8` | Matching | 100.00% | 44 |
| `func_0042E3D8` | Matching | 100.00% | 60 |
| `func_0042E418` | Matching | 100.00% | 60 |
| `func_0042E458` | Matching | 100.00% | 64 |
| `func_0042E498` | Matching | 100.00% | 48 |
| `func_0042E4C8` | Matching | 100.00% | 64 |
| `func_0042E508` | Matching | 100.00% | 128 |

### `seg/seg_6D428`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `readTrigger` | Matching | 100.00% | 156 |
| `readVolume` | Matching | 100.00% | 40 |
| `readBoundObj` | Matching | 100.00% | 40 |
| `readAction` | Matching | 100.00% | 140 |

### `seg/seg_CF758`

4 matching, 0 partial, 0 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `setChallengeName` | Matching | 100.00% | 648 |
| `setChallengeStats` | Matching | 100.00% | 940 |
| `func_001CED90` | Matching | 100.00% | 268 |
| `func_001CEEA0` | Matching | 100.00% | 528 |

### `sound/asyncsys`

21 matching, 0 partial, 2 not started (23 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cAsyncSys_ASYNCSYS_Init(cAsyncSys*, unsigned int)` | Matching | 100.00% | 68 |
| `func_0028A230` | Matching | 100.00% | 104 |
| `func_0028A298` | Matching | 100.00% | 700 |
| `func_0028A558` | Matching | 100.00% | 464 |
| `func_0028B0F0` | Matching | 100.00% | 144 |
| `func_0028B180` | Matching | 100.00% | 8 |
| `func_0028B188` | Matching | 100.00% | 40 |
| `func_0028B1B0` | Matching | 100.00% | 16 |
| `func_0028B1C0` | Matching | 100.00% | 8 |
| `func_0028B1C8` | Matching | 100.00% | 12 |
| `func_0028B1D8` | Matching | 100.00% | 16 |
| `func_0028B1E8` | Matching | 100.00% | 12 |
| `func_0028B1F8` | Matching | 100.00% | 20 |
| `func_0028B210` | Matching | 100.00% | 28 |
| `func_0028B230` | Matching | 100.00% | 16 |
| `func_0028B240(void*)` | Matching | 100.00% | 8 |
| `func_0028B248` | Matching | 100.00% | 48 |
| `func_0028B278` | Matching | 100.00% | 84 |
| `func_0028B2D0` | Matching | 100.00% | 80 |
| `func_0028B320` | Matching | 100.00% | 516 |
| `func_0028B528` | Matching | 100.00% | 92 |

### `sound/bankmanager`

68 matching, 0 partial, 5 not started (73 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBankInstance_AllocMem` | Matching | 100.00% | 196 |
| `func_0028B650` | Matching | 100.00% | 116 |
| `func_0028B6C8` | Matching | 100.00% | 100 |
| `func_0028B730` | Matching | 100.00% | 84 |
| `func_0028B788` | Matching | 100.00% | 88 |
| `func_0028B7E0` | Matching | 100.00% | 80 |
| `func_0028B830` | Matching | 100.00% | 72 |
| `func_0028B878` | Matching | 100.00% | 96 |
| `cBankInstance_OnAsyncMainMemAlloc` | Matching | 100.00% | 76 |
| `func_0028B928(void*)` | Matching | 100.00% | 8 |
| `func_0028B930` | Matching | 100.00% | 136 |
| `cBankManager_cBankManager` | Matching | 100.00% | 340 |
| `func_0028BB10` | Matching | 100.00% | 328 |
| `func_0028BC58` | Matching | 100.00% | 140 |
| `func_0028BCE8` | Matching | 100.00% | 40 |
| `func_0028BD10` | Matching | 100.00% | 152 |
| `func_0028BDA8` | Matching | 100.00% | 52 |
| `func_0028BDE0` | Matching | 100.00% | 40 |
| `func_0028BE08` | Matching | 100.00% | 48 |
| `func_0028BE38` | Matching | 100.00% | 40 |
| `func_0028BE60` | Matching | 100.00% | 48 |
| `func_0028BE90` | Matching | 100.00% | 40 |
| `func_0028BEB8` | Matching | 100.00% | 40 |
| `func_0028BEE0` | Matching | 100.00% | 48 |
| `func_0028BF10` | Matching | 100.00% | 40 |
| `func_0028BF38` | Matching | 100.00% | 60 |
| `func_0028BF78` | Matching | 100.00% | 856 |
| `func_0028C2D0` | Matching | 100.00% | 348 |
| `func_0028C430` | Matching | 100.00% | 1164 |
| `func_0028C8C0(void*, int)` | Matching | 100.00% | 8 |
| `func_0028C8C8` | Matching | 100.00% | 1152 |
| `func_0028CD48` | Matching | 100.00% | 176 |
| `func_0028CDF8` | Matching | 100.00% | 412 |
| `func_0028D488` | Matching | 100.00% | 276 |
| `func_0028D5A0` | Matching | 100.00% | 144 |
| `func_0028D630` | Matching | 100.00% | 268 |
| `func_0028D740` | Matching | 100.00% | 152 |
| `func_0028D7D8` | Matching | 100.00% | 188 |
| `func_0028D898(void*)` | Matching | 100.00% | 8 |
| `func_0028D8A0` | Matching | 100.00% | 188 |
| `func_0028D960` | Matching | 100.00% | 40 |
| `func_0028DEF0` | Matching | 100.00% | 20 |
| `func_0028DF08(void*)` | Matching | 100.00% | 12 |
| `func_0028DF18` | Matching | 100.00% | 336 |
| `func_0028E068` | Matching | 100.00% | 32 |
| `func_0028E088` | Matching | 100.00% | 116 |
| `func_0028E100` | Matching | 100.00% | 1036 |
| `func_0028E510` | Matching | 100.00% | 52 |
| `func_0028E888` | Matching | 100.00% | 56 |
| `func_0028EF90` | Matching | 100.00% | 108 |
| `func_0028F000` | Matching | 100.00% | 260 |
| `func_0028F140` | Matching | 100.00% | 192 |
| `func_0028F200` | Matching | 100.00% | 192 |
| `func_0028F2C0` | Matching | 100.00% | 100 |
| `func_0028F328` | Matching | 100.00% | 156 |
| `func_0028F3C8` | Matching | 100.00% | 172 |
| `func_0028F478` | Matching | 100.00% | 168 |
| `func_0028F520` | Matching | 100.00% | 52 |
| `func_0028F558` | Matching | 100.00% | 92 |
| `func_0028F5B8` | Matching | 100.00% | 188 |
| `func_0028F678` | Matching | 100.00% | 136 |
| `func_0028F700` | Matching | 100.00% | 44 |
| `func_0028F730` | Matching | 100.00% | 56 |
| `func_0028F768` | Matching | 100.00% | 812 |
| `func_0028FA98` | Matching | 100.00% | 68 |
| `func_0028FAE0` | Matching | 100.00% | 344 |
| `func_0028FC38(void*)` | Matching | 100.00% | 28 |
| `func_0028FC58` | Matching | 100.00% | 164 |

### `sound/bankmonitor`

206 matching, 0 partial, 7 not started (213 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBankMonitor_cBankMonitor` | Matching | 100.00% | 312 |
| `func_002ACE40` | Matching | 100.00% | 288 |
| `func_002ACF60` | Matching | 100.00% | 124 |
| `func_002AD2A8` | Matching | 100.00% | 88 |
| `func_002AD300` | Matching | 100.00% | 84 |
| `func_002AD358` | Matching | 100.00% | 60 |
| `func_002AD398` | Matching | 100.00% | 40 |
| `func_002AD3C0` | Matching | 100.00% | 76 |
| `func_002AD410` | Matching | 100.00% | 200 |
| `func_002AD4D8` | Matching | 100.00% | 116 |
| `func_002AD550` | Matching | 100.00% | 156 |
| `func_002AD5F0` | Matching | 100.00% | 96 |
| `func_002AD650` | Matching | 100.00% | 224 |
| `func_002AD730` | Matching | 100.00% | 120 |
| `func_002AD7A8` | Matching | 100.00% | 104 |
| `func_002AD810` | Matching | 100.00% | 52 |
| `func_002AD848(void*)` | Matching | 100.00% | 20 |
| `func_002AD860` | Matching | 100.00% | 36 |
| `func_002AD888` | Matching | 100.00% | 168 |
| `func_002AD930` | Matching | 100.00% | 16 |
| `func_002AD940` | Matching | 100.00% | 48 |
| `func_002AD970(void*, int)` | Matching | 100.00% | 12 |
| `func_002AD980(void*)` | Matching | 100.00% | 12 |
| `func_002AD990(void*)` | Matching | 100.00% | 8 |
| `func_002AD998` | Matching | 100.00% | 44 |
| `func_002AD9C8` | Matching | 100.00% | 256 |
| `func_002ADAC8` | Matching | 100.00% | 296 |
| `func_002ADBF0(void*)` | Matching | 100.00% | 32 |
| `func_002ADC10` | Matching | 100.00% | 32 |
| `func_002ADC30` | Matching | 100.00% | 108 |
| `func_002ADD78` | Matching | 100.00% | 40 |
| `func_002ADDA0` | Matching | 100.00% | 64 |
| `func_002ADDE0` | Matching | 100.00% | 164 |
| `func_002ADE88` | Matching | 100.00% | 96 |
| `func_002ADEE8` | Matching | 100.00% | 108 |
| `func_002ADF58` | Matching | 100.00% | 8 |
| `func_002ADF60` | Matching | 100.00% | 28 |
| `func_002ADF80` | Matching | 100.00% | 44 |
| `func_002ADFB0(int)` | Matching | 100.00% | 24 |
| `func_002ADFC8` | Matching | 100.00% | 52 |
| `func_002AE000(void*)` | Matching | 100.00% | 28 |
| `func_002AE020` | Matching | 100.00% | 40 |
| `func_002AE048` | Matching | 100.00% | 184 |
| `func_002AE100` | Matching | 100.00% | 56 |
| `func_002AE138` | Matching | 100.00% | 76 |
| `func_002AE188` | Matching | 100.00% | 48 |
| `func_002AE1B8` | Matching | 100.00% | 56 |
| `func_002AE1F0` | Matching | 100.00% | 60 |
| `func_002AE230` | Matching | 100.00% | 92 |
| `func_002AE290` | Matching | 100.00% | 8 |
| `func_002AE298` | Matching | 100.00% | 140 |
| `func_002AE328` | Matching | 100.00% | 128 |
| `func_002AE3A8` | Matching | 100.00% | 204 |
| `func_002AE478` | Matching | 100.00% | 68 |
| `func_002AE4C0` | Matching | 100.00% | 464 |
| `func_002AE690` | Matching | 100.00% | 216 |
| `func_002AE768` | Matching | 100.00% | 64 |
| `func_002AE9F8` | Matching | 100.00% | 64 |
| `func_002AEA38` | Matching | 100.00% | 112 |
| `func_002AEAA8` | Matching | 100.00% | 148 |
| `func_002AEB40` | Matching | 100.00% | 144 |
| `func_002AEBD0` | Matching | 100.00% | 84 |
| `func_002AEC28` | Matching | 100.00% | 48 |
| `func_002AEC58` | Matching | 100.00% | 844 |
| `func_002AEFA8` | Matching | 100.00% | 840 |
| `func_002AF2F0` | Matching | 100.00% | 128 |
| `func_002AF370` | Matching | 100.00% | 68 |
| `func_002AF3B8` | Matching | 100.00% | 56 |
| `func_002AF3F0` | Matching | 100.00% | 56 |
| `func_002AF428` | Matching | 100.00% | 84 |
| `func_002AF480` | Matching | 100.00% | 44 |
| `func_002AF4B0` | Matching | 100.00% | 44 |
| `func_002AF4E0` | Matching | 100.00% | 156 |
| `func_002AF580` | Matching | 100.00% | 136 |
| `func_002AF608` | Matching | 100.00% | 184 |
| `func_002AF6C0` | Matching | 100.00% | 224 |
| `func_002AF7A0` | Matching | 100.00% | 152 |
| `func_002AF838` | Matching | 100.00% | 112 |
| `func_002AF8A8` | Matching | 100.00% | 52 |
| `func_002AF8E0(void*)` | Matching | 100.00% | 28 |
| `func_002AF900` | Matching | 100.00% | 92 |
| `func_002AF960` | Matching | 100.00% | 244 |
| `func_002AFA58` | Matching | 100.00% | 16 |
| `func_002AFA68` | Matching | 100.00% | 208 |
| `func_002AFB38` | Matching | 100.00% | 336 |
| `func_002AFC88` | Matching | 100.00% | 136 |
| `func_002AFD10` | Matching | 100.00% | 48 |
| `func_002B0290` | Matching | 100.00% | 144 |
| `func_002B0320` | Matching | 100.00% | 36 |
| `func_002B0348` | Matching | 100.00% | 108 |
| `func_002B03B8` | Matching | 100.00% | 284 |
| `func_002B07C0` | Matching | 100.00% | 36 |
| `func_002B07E8` | Matching | 100.00% | 8 |
| `func_002B07F0` | Matching | 100.00% | 8 |
| `func_002B07F8` | Matching | 100.00% | 752 |
| `func_002B0AE8` | Matching | 100.00% | 400 |
| `func_002B0C78` | Matching | 100.00% | 104 |
| `SPCH_Init` | Matching | 100.00% | 188 |
| `func_002B0DA0` | Matching | 100.00% | 132 |
| `func_002B0E28` | Matching | 100.00% | 52 |
| `func_002B0E60` | Matching | 100.00% | 172 |
| `func_002B0F10` | Matching | 100.00% | 52 |
| `func_002B0F48` | Matching | 100.00% | 156 |
| `func_002B0FE8` | Matching | 100.00% | 52 |
| `func_002B1020` | Matching | 100.00% | 52 |
| `func_002B1058` | Matching | 100.00% | 208 |
| `func_002B1128` | Matching | 100.00% | 132 |
| `func_002B11B0` | Matching | 100.00% | 52 |
| `func_002B11E8` | Matching | 100.00% | 52 |
| `func_002B1220` | Matching | 100.00% | 40 |
| `func_002B1248` | Matching | 100.00% | 28 |
| `func_002B1428` | Matching | 100.00% | 44 |
| `func_002B1458` | Matching | 100.00% | 200 |
| `func_002B16A0` | Matching | 100.00% | 128 |
| `func_002B1720` | Matching | 100.00% | 56 |
| `func_002B1758(void*, int)` | Matching | 100.00% | 40 |
| `func_002B1A70` | Matching | 100.00% | 36 |
| `func_002B1A98` | Matching | 100.00% | 204 |
| `func_002B1B68` | Matching | 100.00% | 48 |
| `func_002B1B98` | Matching | 100.00% | 184 |
| `func_002B1C50` | Matching | 100.00% | 804 |
| `func_002B1F78` | Matching | 100.00% | 160 |
| `func_002B2018` | Matching | 100.00% | 88 |
| `func_002B2070` | Matching | 100.00% | 88 |
| `func_002B20C8` | Matching | 100.00% | 88 |
| `func_002B2120` | Matching | 100.00% | 32 |
| `func_002B2140` | Matching | 100.00% | 32 |
| `func_002B2160` | Matching | 100.00% | 124 |
| `func_002B21E0` | Matching | 100.00% | 516 |
| `func_002B23E8` | Matching | 100.00% | 48 |
| `func_002B2418` | Matching | 100.00% | 108 |
| `func_002B2488` | Matching | 100.00% | 52 |
| `func_002B24C0` | Matching | 100.00% | 64 |
| `func_002B2500` | Matching | 100.00% | 76 |
| `func_002B2550` | Matching | 100.00% | 40 |
| `func_002B2578` | Matching | 100.00% | 76 |
| `func_002B25C8` | Matching | 100.00% | 52 |
| `func_002B2600` | Matching | 100.00% | 64 |
| `func_002B2640` | Matching | 100.00% | 80 |
| `func_002B2690` | Matching | 100.00% | 36 |
| `func_002B26B8` | Matching | 100.00% | 64 |
| `func_002B26F8` | Matching | 100.00% | 28 |
| `func_002B2718` | Matching | 100.00% | 92 |
| `func_002B2778` | Matching | 100.00% | 68 |
| `func_002B27C0` | Matching | 100.00% | 144 |
| `func_002B2850` | Matching | 100.00% | 112 |
| `func_002B3398` | Matching | 100.00% | 516 |
| `func_002B35A0` | Matching | 100.00% | 660 |
| `func_002B3838` | Matching | 100.00% | 568 |
| `func_002B3A70` | Matching | 100.00% | 40 |
| `func_002B3A98` | Matching | 100.00% | 40 |
| `func_002B3AC0` | Matching | 100.00% | 196 |
| `func_002B3B88` | Matching | 100.00% | 52 |
| `func_002B3BC0` | Matching | 100.00% | 100 |
| `func_002B3C28` | Matching | 100.00% | 52 |
| `func_002B3C60` | Matching | 100.00% | 52 |
| `func_002B3C98` | Matching | 100.00% | 36 |
| `func_002B3CC0` | Matching | 100.00% | 20 |
| `func_002B3CD8` | Matching | 100.00% | 52 |
| `func_002B3D10` | Matching | 100.00% | 56 |
| `func_002B3D48` | Matching | 100.00% | 52 |
| `func_002B3E20` | Matching | 100.00% | 140 |
| `func_002B3EB0` | Matching | 100.00% | 52 |
| `func_002B3EE8` | Matching | 100.00% | 256 |
| `func_002B3FE8` | Matching | 100.00% | 120 |
| `func_002B4060(void*)` | Matching | 100.00% | 8 |
| `func_002B4068` | Matching | 100.00% | 8 |
| `func_002B4070` | Matching | 100.00% | 128 |
| `func_002B40F0` | Matching | 100.00% | 44 |
| `func_002B4120` | Matching | 100.00% | 44 |
| `func_002B4150` | Matching | 100.00% | 44 |
| `func_002B4180` | Matching | 100.00% | 100 |
| `func_002B41E8` | Matching | 100.00% | 204 |
| `func_002B42B8` | Matching | 100.00% | 208 |
| `func_002B4388` | Matching | 100.00% | 76 |
| `func_002B43D8` | Matching | 100.00% | 152 |
| `func_002B44D8` | Matching | 100.00% | 104 |
| `func_002B4540` | Matching | 100.00% | 40 |
| `func_002B4620` | Matching | 100.00% | 172 |
| `func_002B46D0` | Matching | 100.00% | 24 |
| `func_002B46E8` | Matching | 100.00% | 28 |
| `func_002B4708` | Matching | 100.00% | 20 |
| `func_002B4720` | Matching | 100.00% | 28 |
| `func_002B4740` | Matching | 100.00% | 124 |
| `func_002B47C0` | Matching | 100.00% | 164 |
| `func_002B4868(void*)` | Matching | 100.00% | 12 |
| `func_002B4878` | Matching | 100.00% | 60 |
| `func_002B48B8` | Matching | 100.00% | 12 |
| `func_002B48C8` | Matching | 100.00% | 60 |
| `func_002B4908(void*)` | Matching | 100.00% | 24 |
| `func_002B4920` | Matching | 100.00% | 88 |
| `func_002B4978` | Matching | 100.00% | 68 |
| `func_002B49C0` | Matching | 100.00% | 32 |
| `func_002B49E0` | Matching | 100.00% | 40 |
| `func_002B4A08` | Matching | 100.00% | 20 |
| `func_002B4A20` | Matching | 100.00% | 128 |
| `func_002B4AA0` | Matching | 100.00% | 72 |
| `func_002B4AE8(void*)` | Matching | 100.00% | 8 |
| `func_002B4AF0` | Matching | 100.00% | 20 |
| `func_002B04D8` | Matching | 99.97% | 744 |
| `func_002B0088` | Matching | 99.92% | 520 |
| `func_002B1268` | Matching | 99.91% | 224 |
| `func_002B1348` | Matching | 99.91% | 224 |
| `func_002B4568` | Matching | 99.89% | 180 |
| `func_002B3D80` | Matching | 99.87% | 156 |
| `func_002B4470` | Matching | 99.80% | 100 |

### `sound/icepick/worldtriggermanager`

55 matching, 0 partial, 5 not started (60 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `WORLDTRIGGERMANAGER_Init()` | Matching | 100.00% | 64 |
| `func_002B4B48` | Matching | 100.00% | 40 |
| `func_002B4B70` | Matching | 100.00% | 108 |
| `func_002B4BE0` | Matching | 100.00% | 36 |
| `func_002B4C08` | Matching | 100.00% | 48 |
| `func_002B5758` | Matching | 100.00% | 188 |
| `func_002B5818` | Matching | 100.00% | 32 |
| `func_002B5838` | Matching | 100.00% | 60 |
| `func_002B5878` | Matching | 100.00% | 32 |
| `func_002B5898` | Matching | 100.00% | 56 |
| `cWorldTriggerManager_cWorldTriggerManager` | Matching | 100.00% | 184 |
| `func_002B5988` | Matching | 100.00% | 144 |
| `cWorldTriggerManager_LoadTriggerInfo` | Matching | 100.00% | 296 |
| `func_002B5B40` | Matching | 100.00% | 76 |
| `func_002B5B90` | Matching | 100.00% | 48 |
| `func_002B5BC0` | Matching | 100.00% | 164 |
| `func_002B5C68` | Matching | 100.00% | 268 |
| `func_002B5E68` | Matching | 100.00% | 112 |
| `func_002B5ED8` | Matching | 100.00% | 136 |
| `func_002B5F60` | Matching | 100.00% | 1136 |
| `func_002B63D0` | Matching | 100.00% | 384 |
| `func_002B6550` | Matching | 100.00% | 96 |
| `func_002B6628(void*)` | Matching | 100.00% | 8 |
| `func_002B6630` | Matching | 100.00% | 180 |
| `func_002B66E8` | Matching | 100.00% | 88 |
| `func_002B6740` | Matching | 100.00% | 152 |
| `func_002B67D8` | Matching | 100.00% | 48 |
| `func_002B6808` | Matching | 100.00% | 96 |
| `func_002B6868` | Matching | 100.00% | 100 |
| `func_002B68D0` | Matching | 100.00% | 44 |
| `func_002B6900(void*)` | Matching | 100.00% | 24 |
| `func_002B6918` | Matching | 100.00% | 56 |
| `func_002B6950` | Matching | 100.00% | 56 |
| `func_002B6988` | Matching | 100.00% | 48 |
| `func_002B69B8` | Matching | 100.00% | 124 |
| `func_002B6A38` | Matching | 100.00% | 48 |
| `func_002B6A68` | Matching | 100.00% | 56 |
| `func_002B6AA0` | Matching | 100.00% | 60 |
| `func_002B6AE0` | Matching | 100.00% | 36 |
| `func_002B6B08` | Matching | 100.00% | 36 |
| `func_002B6B30` | Matching | 100.00% | 32 |
| `func_002B6C20` | Matching | 100.00% | 108 |
| `func_002B6C90` | Matching | 100.00% | 100 |
| `func_002B6F40` | Matching | 100.00% | 980 |
| `func_002B7318` | Matching | 100.00% | 244 |
| `func_002B7410` | Matching | 100.00% | 444 |
| `func_002B75D0` | Matching | 100.00% | 496 |
| `func_002B77C0` | Matching | 100.00% | 132 |
| `func_002B8190` | Matching | 100.00% | 296 |
| `func_002B83B8` | Matching | 100.00% | 60 |
| `func_002B83F8` | Matching | 99.98% | 1052 |
| `func_002B6CF8` | Matching | 99.93% | 580 |
| `func_002B5D78` | Matching | 99.92% | 240 |
| `func_002B82B8` | Matching | 99.84% | 252 |
| `func_002B8818` | Matching | 99.37% | 2276 |

### `sound/ps2soundman`

3 matching, 0 partial, 0 not started (3 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cSndPlayOpts_cSndPlayOpts` | Matching | 100.00% | 1136 |
| `func_002A97C0` | Matching | 100.00% | 452 |
| `func_002A9988` | Matching | 100.00% | 80 |

### `sound/soundsys`

292 matching, 0 partial, 13 not started (305 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBankSys_cBankSys` | Matching | 100.00% | 412 |
| `func_0028FEA0` | Matching | 100.00% | 372 |
| `func_00290018` | Matching | 100.00% | 828 |
| `func_00290358` | Matching | 100.00% | 860 |
| `func_00290B58` | Matching | 100.00% | 184 |
| `func_00290C10` | Matching | 100.00% | 44 |
| `func_00290C40` | Matching | 100.00% | 124 |
| `func_00290CC0` | Matching | 100.00% | 664 |
| `func_00290F58` | Matching | 100.00% | 120 |
| `func_00290FD0` | Matching | 100.00% | 272 |
| `func_002910E0` | Matching | 100.00% | 760 |
| `func_002913D8` | Matching | 100.00% | 84 |
| `func_00291430` | Matching | 100.00% | 8 |
| `func_00291438` | Matching | 100.00% | 724 |
| `func_00291710` | Matching | 100.00% | 168 |
| `func_002917B8` | Matching | 100.00% | 24 |
| `func_002917D0` | Matching | 100.00% | 1208 |
| `func_00291C88` | Matching | 100.00% | 2176 |
| `func_00292508` | Matching | 100.00% | 1228 |
| `func_002929D8` | Matching | 100.00% | 116 |
| `func_00292A50` | Matching | 100.00% | 148 |
| `func_00292AE8` | Matching | 100.00% | 92 |
| `func_00292B48` | Matching | 100.00% | 368 |
| `func_00292CB8` | Matching | 100.00% | 228 |
| `func_00292DA0` | Matching | 100.00% | 340 |
| `func_00292EF8` | Matching | 100.00% | 284 |
| `func_00293018` | Matching | 100.00% | 332 |
| `func_00293168` | Matching | 100.00% | 296 |
| `func_00293290` | Matching | 100.00% | 188 |
| `func_00293350` | Matching | 100.00% | 188 |
| `func_00293410` | Matching | 100.00% | 188 |
| `func_002934D0` | Matching | 100.00% | 104 |
| `func_00293538` | Matching | 100.00% | 516 |
| `func_00293740` | Matching | 100.00% | 516 |
| `func_00293948` | Matching | 100.00% | 516 |
| `func_00293B50` | Matching | 100.00% | 28 |
| `func_00293B70` | Matching | 100.00% | 28 |
| `func_00293B90` | Matching | 100.00% | 28 |
| `func_00294678` | Matching | 100.00% | 308 |
| `func_002947B0` | Matching | 100.00% | 172 |
| `func_00294860` | Matching | 100.00% | 32 |
| `func_00294880` | Matching | 100.00% | 28 |
| `func_002948A0` | Matching | 100.00% | 44 |
| `func_00294F48` | Matching | 100.00% | 48 |
| `func_00294F78` | Matching | 100.00% | 172 |
| `func_00295028` | Matching | 100.00% | 476 |
| `func_00295208` | Matching | 100.00% | 1056 |
| `func_00295628` | Matching | 100.00% | 808 |
| `func_00295950` | Matching | 100.00% | 884 |
| `func_00295CC8` | Matching | 100.00% | 956 |
| `func_00296088` | Matching | 100.00% | 360 |
| `func_00296308` | Matching | 100.00% | 8 |
| `func_00296868` | Matching | 100.00% | 1452 |
| `func_00296E18` | Matching | 100.00% | 8 |
| `func_00296E20` | Matching | 100.00% | 92 |
| `func_00296E80` | Matching | 100.00% | 1452 |
| `func_00297430` | Matching | 100.00% | 8 |
| `func_00297438` | Matching | 100.00% | 92 |
| `func_00297498` | Matching | 100.00% | 8 |
| `func_002974A0` | Matching | 100.00% | 1196 |
| `func_00297EB8` | Matching | 100.00% | 180 |
| `func_00297F70` | Matching | 100.00% | 44 |
| `func_00297FA0` | Matching | 100.00% | 268 |
| `func_002980B0` | Matching | 100.00% | 132 |
| `func_00298138` | Matching | 100.00% | 848 |
| `func_00298488` | Matching | 100.00% | 1308 |
| `func_002989A8` | Matching | 100.00% | 852 |
| `func_00298D00` | Matching | 100.00% | 132 |
| `func_00298D88` | Matching | 100.00% | 8 |
| `func_00298D90` | Matching | 100.00% | 1348 |
| `func_002992D8` | Matching | 100.00% | 140 |
| `func_00299368` | Matching | 100.00% | 720 |
| `func_00299638` | Matching | 100.00% | 380 |
| `func_002997B8` | Matching | 100.00% | 948 |
| `func_00299B70` | Matching | 100.00% | 692 |
| `func_00299E28` | Matching | 100.00% | 1012 |
| `func_0029A220` | Matching | 100.00% | 784 |
| `func_0029A530` | Matching | 100.00% | 676 |
| `func_0029A7D8` | Matching | 100.00% | 812 |
| `func_0029AB08` | Matching | 100.00% | 52 |
| `func_0029B0E0` | Matching | 100.00% | 732 |
| `func_0029B3C0` | Matching | 100.00% | 112 |
| `func_0029B430` | Matching | 100.00% | 772 |
| `func_0029B738` | Matching | 100.00% | 168 |
| `func_0029B7E0` | Matching | 100.00% | 56 |
| `func_0029B960(void*)` | Matching | 100.00% | 8 |
| `func_0029B968` | Matching | 100.00% | 912 |
| `func_0029BCF8` | Matching | 100.00% | 912 |
| `func_0029C088` | Matching | 100.00% | 912 |
| `func_0029C418(void*)` | Matching | 100.00% | 8 |
| `func_0029C420` | Matching | 100.00% | 908 |
| `func_0029C7B0` | Matching | 100.00% | 1272 |
| `func_0029CE28` | Matching | 100.00% | 72 |
| `func_0029CE70` | Matching | 100.00% | 100 |
| `func_0029CED8` | Matching | 100.00% | 948 |
| `func_0029D370` | Matching | 100.00% | 672 |
| `func_0029D610` | Matching | 100.00% | 104 |
| `func_0029D678` | Matching | 100.00% | 84 |
| `func_0029D6D0(void*)` | Matching | 100.00% | 12 |
| `func_0029D6E0` | Matching | 100.00% | 508 |
| `func_0029D8E0` | Matching | 100.00% | 720 |
| `func_0029DBB0` | Matching | 100.00% | 148 |
| `func_0029DC48` | Matching | 100.00% | 676 |
| `func_0029DEF0` | Matching | 100.00% | 1348 |
| `func_0029E4A0` | Matching | 100.00% | 192 |
| `func_0029E560(void*)` | Matching | 100.00% | 8 |
| `func_0029E568` | Matching | 100.00% | 8 |
| `func_0029E570` | Matching | 100.00% | 8 |
| `func_0029E578` | Matching | 100.00% | 20 |
| `func_0029E590` | Matching | 100.00% | 992 |
| `func_0029E970` | Matching | 100.00% | 932 |
| `func_0029ED18` | Matching | 100.00% | 120 |
| `func_0029ED90` | Matching | 100.00% | 336 |
| `func_0029EEE0` | Matching | 100.00% | 284 |
| `func_0029F088` | Matching | 100.00% | 24 |
| `func_0029F0A0` | Matching | 100.00% | 52 |
| `func_0029F0D8` | Matching | 100.00% | 80 |
| `func_0029F128` | Matching | 100.00% | 52 |
| `func_0029F160` | Matching | 100.00% | 52 |
| `func_0029F198` | Matching | 100.00% | 280 |
| `func_0029F2B0` | Matching | 100.00% | 128 |
| `func_0029F330` | Matching | 100.00% | 68 |
| `func_0029F378` | Matching | 100.00% | 124 |
| `func_0029F3F8` | Matching | 100.00% | 484 |
| `func_0029F5E0` | Matching | 100.00% | 64 |
| `func_0029F620` | Matching | 100.00% | 60 |
| `func_0029FF80` | Matching | 100.00% | 852 |
| `func_002A02D8` | Matching | 100.00% | 648 |
| `func_002A0A30` | Matching | 100.00% | 1088 |
| `func_002A0E70` | Matching | 100.00% | 436 |
| `func_002A1028` | Matching | 100.00% | 152 |
| `func_002A10C0` | Matching | 100.00% | 120 |
| `func_002A1138` | Matching | 100.00% | 324 |
| `func_002A1280` | Matching | 100.00% | 260 |
| `func_002A1388` | Matching | 100.00% | 116 |
| `func_002A1400` | Matching | 100.00% | 348 |
| `func_002A1560` | Matching | 100.00% | 332 |
| `func_002A16B0` | Matching | 100.00% | 200 |
| `func_002A1778` | Matching | 100.00% | 164 |
| `func_002A1820` | Matching | 100.00% | 440 |
| `func_002A19D8` | Matching | 100.00% | 380 |
| `func_002A1B58` | Matching | 100.00% | 48 |
| `func_002A1B88` | Matching | 100.00% | 72 |
| `func_002A1BD0(void*)` | Matching | 100.00% | 8 |
| `func_002A1BD8` | Matching | 100.00% | 368 |
| `func_002A1D48` | Matching | 100.00% | 88 |
| `func_002A1DA0` | Matching | 100.00% | 128 |
| `func_002A1E20` | Matching | 100.00% | 68 |
| `func_002A1FA0` | Matching | 100.00% | 116 |
| `func_002A2018` | Matching | 100.00% | 184 |
| `func_002A20D0` | Matching | 100.00% | 184 |
| `func_002A2188` | Matching | 100.00% | 216 |
| `func_002A2260` | Matching | 100.00% | 184 |
| `func_002A2318` | Matching | 100.00% | 184 |
| `func_002A23D0` | Matching | 100.00% | 224 |
| `func_002A24B0` | Matching | 100.00% | 180 |
| `func_002A2568` | Matching | 100.00% | 204 |
| `func_002A2638` | Matching | 100.00% | 184 |
| `func_002A26F0` | Matching | 100.00% | 232 |
| `func_002A27D8` | Matching | 100.00% | 132 |
| `func_002A2860` | Matching | 100.00% | 216 |
| `func_002A2938` | Matching | 100.00% | 216 |
| `func_002A2A10` | Matching | 100.00% | 188 |
| `func_002A2AD0` | Matching | 100.00% | 184 |
| `func_002A2B88` | Matching | 100.00% | 164 |
| `func_002A2C30` | Matching | 100.00% | 188 |
| `func_002A2CF0` | Matching | 100.00% | 176 |
| `func_002A2DA0` | Matching | 100.00% | 176 |
| `func_002A2E50` | Matching | 100.00% | 800 |
| `func_002A3170` | Matching | 100.00% | 76 |
| `func_002A31C0` | Matching | 100.00% | 236 |
| `func_002A32B0` | Matching | 100.00% | 164 |
| `func_002A3358` | Matching | 100.00% | 164 |
| `func_002A3400` | Matching | 100.00% | 208 |
| `func_002A34D0` | Matching | 100.00% | 568 |
| `func_002A3708` | Matching | 100.00% | 340 |
| `func_002A39E0` | Matching | 100.00% | 188 |
| `func_002A3AA0` | Matching | 100.00% | 116 |
| `func_002A3B18` | Matching | 100.00% | 232 |
| `func_002A3C00` | Matching | 100.00% | 232 |
| `func_002A3CE8` | Matching | 100.00% | 244 |
| `func_002A3DE0` | Matching | 100.00% | 212 |
| `func_002A3EB8` | Matching | 100.00% | 212 |
| `func_002A3F90` | Matching | 100.00% | 68 |
| `func_002A3FD8` | Matching | 100.00% | 12 |
| `func_002A3FE8` | Matching | 100.00% | 68 |
| `func_002A4030` | Matching | 100.00% | 12 |
| `func_002A4040` | Matching | 100.00% | 56 |
| `func_002A4078` | Matching | 100.00% | 104 |
| `func_002A40E0` | Matching | 100.00% | 8 |
| `func_002A40E8` | Matching | 100.00% | 112 |
| `func_002A4158` | Matching | 100.00% | 12 |
| `func_002A4168` | Matching | 100.00% | 92 |
| `func_002A41C8` | Matching | 100.00% | 12 |
| `func_002A41D8` | Matching | 100.00% | 92 |
| `func_002A4238` | Matching | 100.00% | 12 |
| `func_002A4248` | Matching | 100.00% | 72 |
| `func_002A4290` | Matching | 100.00% | 56 |
| `func_002A42C8` | Matching | 100.00% | 76 |
| `func_002A4318` | Matching | 100.00% | 76 |
| `func_002A4368` | Matching | 100.00% | 76 |
| `func_002A43B8` | Matching | 100.00% | 404 |
| `func_002A4550` | Matching | 100.00% | 60 |
| `func_002A4590` | Matching | 100.00% | 48 |
| `func_002A45C0` | Matching | 100.00% | 160 |
| `func_002A4660` | Matching | 100.00% | 180 |
| `func_002A4718` | Matching | 100.00% | 84 |
| `func_002A4770` | Matching | 100.00% | 628 |
| `func_002A49E8` | Matching | 100.00% | 80 |
| `func_002A4A38` | Matching | 100.00% | 44 |
| `func_002A4A68` | Matching | 100.00% | 12 |
| `func_002A4A78` | Matching | 100.00% | 236 |
| `func_002A4B68` | Matching | 100.00% | 64 |
| `func_002A4BA8` | Matching | 100.00% | 52 |
| `func_002A4BE0` | Matching | 100.00% | 68 |
| `func_002A4C28` | Matching | 100.00% | 120 |
| `func_002A4CA0` | Matching | 100.00% | 84 |
| `func_002A4CF8` | Matching | 100.00% | 112 |
| `func_002A4D68` | Matching | 100.00% | 208 |
| `func_002A4E38` | Matching | 100.00% | 80 |
| `func_002A5CD8` | Matching | 100.00% | 44 |
| `func_002A5D08` | Matching | 100.00% | 1508 |
| `func_002A62F0` | Matching | 100.00% | 316 |
| `func_002A6430` | Matching | 100.00% | 108 |
| `func_002A64A0` | Matching | 100.00% | 420 |
| `func_002A6648` | Matching | 100.00% | 420 |
| `func_002A67F0` | Matching | 100.00% | 24 |
| `func_002A6808` | Matching | 100.00% | 60 |
| `func_002A6848` | Matching | 100.00% | 104 |
| `func_002A68B0` | Matching | 100.00% | 240 |
| `func_002A69A0` | Matching | 100.00% | 432 |
| `func_002A6B50` | Matching | 100.00% | 452 |
| `func_002A6D78` | Matching | 100.00% | 444 |
| `func_002A6F38` | Matching | 100.00% | 260 |
| `func_002A7040` | Matching | 100.00% | 636 |
| `func_002A72C0` | Matching | 100.00% | 20 |
| `func_002A72D8` | Matching | 100.00% | 100 |
| `func_002A7340` | Matching | 100.00% | 100 |
| `func_002A73A8` | Matching | 100.00% | 48 |
| `func_002A73D8` | Matching | 100.00% | 48 |
| `func_002A7408` | Matching | 100.00% | 48 |
| `func_002A7438` | Matching | 100.00% | 48 |
| `func_002A7468` | Matching | 100.00% | 528 |
| `func_002A7678` | Matching | 100.00% | 156 |
| `func_002A7718` | Matching | 100.00% | 140 |
| `func_002A77A8` | Matching | 100.00% | 28 |
| `func_002A77C8` | Matching | 100.00% | 44 |
| `func_002A77F8` | Matching | 100.00% | 148 |
| `func_002A7890` | Matching | 100.00% | 80 |
| `func_002A78E0(void*)` | Matching | 100.00% | 20 |
| `func_002A78F8` | Matching | 100.00% | 204 |
| `func_002A79C8` | Matching | 100.00% | 88 |
| `func_002A7A20` | Matching | 100.00% | 108 |
| `func_002A7A90` | Matching | 100.00% | 120 |
| `func_002A7B08` | Matching | 100.00% | 236 |
| `func_002A7BF8` | Matching | 100.00% | 112 |
| `func_002A7C68` | Matching | 100.00% | 136 |
| `func_002A7CF0` | Matching | 100.00% | 176 |
| `func_002A7E60` | Matching | 100.00% | 68 |
| `func_002A7EA8` | Matching | 100.00% | 68 |
| `func_002A7EF0` | Matching | 100.00% | 160 |
| `func_002A7F90` | Matching | 100.00% | 104 |
| `func_002A7FF8` | Matching | 100.00% | 120 |
| `func_002A8070` | Matching | 100.00% | 100 |
| `func_002A80D8` | Matching | 100.00% | 100 |
| `func_002A8140` | Matching | 100.00% | 408 |
| `func_002A82D8` | Matching | 100.00% | 372 |
| `func_002A8450` | Matching | 100.00% | 612 |
| `func_002A8B28` | Matching | 100.00% | 248 |
| `func_002A8C20` | Matching | 100.00% | 48 |
| `func_002A8C50` | Matching | 100.00% | 92 |
| `func_002A8CB0` | Matching | 100.00% | 224 |
| `func_002A8D90` | Matching | 100.00% | 444 |
| `func_002A8F50` | Matching | 100.00% | 76 |
| `func_002A8FA0` | Matching | 100.00% | 52 |
| `func_002A8FD8` | Matching | 100.00% | 336 |
| `func_002A9250` | Matching | 100.00% | 56 |
| `func_002A9288` | Matching | 100.00% | 48 |
| `func_002A92B8` | Matching | 100.00% | 60 |
| `func_002A92F8` | Matching | 100.00% | 88 |
| `func_002948D0` | Matching | 99.99% | 1656 |
| `func_0029F660` | Matching | 99.99% | 1636 |
| `func_0029FCC8` | Matching | 99.97% | 692 |
| `func_00293DC0` | Matching | 99.96% | 516 |
| `func_002A0560` | Matching | 99.95% | 1228 |
| `func_002961F0` | Matching | 99.93% | 276 |
| `func_00293FC8` | Matching | 99.91% | 424 |
| `func_0029CCA8` | Matching | 99.89% | 380 |
| `func_002A6D18` | Matching | 99.79% | 96 |
| `func_0029D290` | Matching | 99.73% | 220 |
| `func_0029F000` | Matching | 99.70% | 132 |
| `func_0029E438` | Matching | 99.42% | 104 |

### `sound/ssxAudio`

85 matching, 0 partial, 3 not started (88 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `SSXAUDIO_Init` | Matching | 100.00% | 116 |
| `func_00284C28` | Matching | 100.00% | 64 |
| `func_00285210` | Matching | 100.00% | 660 |
| `func_002854A8` | Matching | 100.00% | 80 |
| `func_00285BE0` | Matching | 100.00% | 20 |
| `func_00285BF8` | Matching | 100.00% | 412 |
| `func_00285D98` | Matching | 100.00% | 432 |
| `func_00285F48` | Matching | 100.00% | 52 |
| `func_00285F80` | Matching | 100.00% | 44 |
| `func_00285FB0` | Matching | 100.00% | 540 |
| `func_002861D0` | Matching | 100.00% | 48 |
| `func_00286200` | Matching | 100.00% | 168 |
| `func_002867E8` | Matching | 100.00% | 664 |
| `func_00286A80` | Matching | 100.00% | 380 |
| `func_00286C00` | Matching | 100.00% | 164 |
| `func_00286CA8` | Matching | 100.00% | 108 |
| `func_00286D18` | Matching | 100.00% | 264 |
| `func_00286E20` | Matching | 100.00% | 128 |
| `func_00286EA0` | Matching | 100.00% | 508 |
| `func_002870A0` | Matching | 100.00% | 104 |
| `func_00287108` | Matching | 100.00% | 164 |
| `func_002871B0` | Matching | 100.00% | 244 |
| `func_002872A8` | Matching | 100.00% | 304 |
| `func_00287410` | Matching | 100.00% | 116 |
| `func_00287488` | Matching | 100.00% | 152 |
| `func_00287520` | Matching | 100.00% | 52 |
| `func_00287558` | Matching | 100.00% | 116 |
| `func_002875D0` | Matching | 100.00% | 156 |
| `func_00287670` | Matching | 100.00% | 48 |
| `func_002876A0` | Matching | 100.00% | 48 |
| `func_002876D0` | Matching | 100.00% | 48 |
| `func_00287700` | Matching | 100.00% | 544 |
| `func_00287920` | Matching | 100.00% | 16 |
| `func_00287930` | Matching | 100.00% | 52 |
| `func_00287968` | Matching | 100.00% | 52 |
| `func_002879A0` | Matching | 100.00% | 16 |
| `func_00287C48` | Matching | 100.00% | 692 |
| `func_00287F00` | Matching | 100.00% | 196 |
| `func_002883B0` | Matching | 100.00% | 1012 |
| `func_002887F8` | Matching | 100.00% | 324 |
| `func_00288A20` | Matching | 100.00% | 156 |
| `func_00288AC0(void*, int)` | Matching | 100.00% | 32 |
| `func_00288AE0` | Matching | 100.00% | 96 |
| `func_00288B40` | Matching | 100.00% | 196 |
| `func_00288C08` | Matching | 100.00% | 224 |
| `func_00288CE8` | Matching | 100.00% | 48 |
| `func_00289398` | Matching | 100.00% | 48 |
| `func_002893C8` | Matching | 100.00% | 52 |
| `func_00289400` | Matching | 100.00% | 72 |
| `func_00289448` | Matching | 100.00% | 40 |
| `func_00289470` | Matching | 100.00% | 172 |
| `func_00289520` | Matching | 100.00% | 304 |
| `func_00289650` | Matching | 100.00% | 48 |
| `func_00289680(void*)` | Matching | 100.00% | 8 |
| `func_00289688` | Matching | 100.00% | 420 |
| `func_00289830` | Matching | 100.00% | 80 |
| `func_00289880` | Matching | 100.00% | 36 |
| `func_002899E8` | Matching | 100.00% | 16 |
| `func_002899F8` | Matching | 100.00% | 244 |
| `func_00289AF0(void*)` | Matching | 100.00% | 8 |
| `func_00289AF8(void*)` | Matching | 100.00% | 28 |
| `func_00289B18` | Matching | 100.00% | 88 |
| `func_00289B70` | Matching | 100.00% | 68 |
| `func_00289BB8` | Matching | 100.00% | 96 |
| `func_00289C18` | Matching | 100.00% | 128 |
| `func_00289C98` | Matching | 100.00% | 112 |
| `func_00289D08` | Matching | 100.00% | 84 |
| `func_00289D60` | Matching | 100.00% | 96 |
| `func_00289DC0(void*)` | Matching | 100.00% | 28 |
| `func_00289DE0(void*)` | Matching | 100.00% | 12 |
| `func_0028A058` | Matching | 100.00% | 240 |
| `func_0028A148` | Matching | 100.00% | 160 |
| `func_002854F8` | Matching | 99.98% | 1080 |
| `func_00287FC8` | Matching | 99.98% | 936 |
| `func_00287A10` | Matching | 99.96% | 564 |
| `cSSXAudio_FrontEndLoad` | Matching | 99.96% | 1344 |
| `func_00288F60` | Matching | 99.91% | 1076 |
| `func_002898A8` | Matching | 99.87% | 316 |
| `func_00288D18` | Matching | 99.76% | 580 |
| `func_002887A8` | Matching | 99.75% | 80 |
| `func_00285930` | Matching | 99.68% | 688 |
| `func_00288370` | Matching | 99.67% | 60 |
| `func_002873D8` | Matching | 99.64% | 56 |
| `func_002879B0` | Matching | 99.55% | 44 |
| `func_002879E0` | Matching | 99.55% | 44 |

### `sound/streamsys`

87 matching, 0 partial, 0 not started (87 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cStreamInstance_cStreamInstance` | Matching | 100.00% | 552 |
| `func_002A9C00` | Matching | 100.00% | 468 |
| `func_002A9DD8` | Matching | 100.00% | 24 |
| `func_002A9DF0` | Matching | 100.00% | 132 |
| `func_002A9E78` | Matching | 100.00% | 96 |
| `func_002A9ED8` | Matching | 100.00% | 84 |
| `func_002A9F30(void*, int)` | Matching | 100.00% | 8 |
| `func_002A9F38` | Matching | 100.00% | 68 |
| `func_002A9F80` | Matching | 100.00% | 160 |
| `func_002AA020` | Matching | 100.00% | 72 |
| `func_002AA068` | Matching | 100.00% | 88 |
| `func_002AA0C0` | Matching | 100.00% | 68 |
| `func_002AA108` | Matching | 100.00% | 68 |
| `func_002AA150` | Matching | 100.00% | 52 |
| `func_002AA188` | Matching | 100.00% | 44 |
| `func_002AA1B8` | Matching | 100.00% | 44 |
| `func_002AA1E8` | Matching | 100.00% | 40 |
| `func_002AA210` | Matching | 100.00% | 44 |
| `func_002AA240` | Matching | 100.00% | 32 |
| `func_002AA260` | Matching | 100.00% | 76 |
| `func_002AA2B0` | Matching | 100.00% | 56 |
| `func_002AA2E8` | Matching | 100.00% | 56 |
| `func_002AA320` | Matching | 100.00% | 120 |
| `func_002AA398` | Matching | 100.00% | 112 |
| `func_002AA408(void*)` | Matching | 100.00% | 28 |
| `func_002AA428` | Matching | 100.00% | 32 |
| `func_002AA448` | Matching | 100.00% | 72 |
| `cStreamSys_cStreamSys` | Matching | 100.00% | 436 |
| `func_002AA648` | Matching | 100.00% | 420 |
| `func_002AA7F0` | Matching | 100.00% | 124 |
| `func_002AA870` | Matching | 100.00% | 156 |
| `func_002AA910` | Matching | 100.00% | 648 |
| `func_002AAB98` | Matching | 100.00% | 52 |
| `func_002AABD0` | Matching | 100.00% | 84 |
| `func_002AAC28` | Matching | 100.00% | 108 |
| `func_002AAC98` | Matching | 100.00% | 108 |
| `func_002AAD08` | Matching | 100.00% | 108 |
| `func_002AAD78` | Matching | 100.00% | 68 |
| `func_002AADC0` | Matching | 100.00% | 68 |
| `func_002AAE08` | Matching | 100.00% | 52 |
| `func_002AAE40` | Matching | 100.00% | 52 |
| `func_002AAE78` | Matching | 100.00% | 68 |
| `func_002AAEC0` | Matching | 100.00% | 68 |
| `func_002AAF08` | Matching | 100.00% | 52 |
| `func_002AAF40` | Matching | 100.00% | 52 |
| `func_002AAF78` | Matching | 100.00% | 88 |
| `func_002AAFD0` | Matching | 100.00% | 84 |
| `func_002AB028` | Matching | 100.00% | 52 |
| `func_002AB060` | Matching | 100.00% | 52 |
| `func_002AB098` | Matching | 100.00% | 52 |
| `func_002AB0D0` | Matching | 100.00% | 32 |
| `func_002AB0F0` | Matching | 100.00% | 52 |
| `func_002AB128` | Matching | 100.00% | 40 |
| `func_002AB150` | Matching | 100.00% | 52 |
| `func_002AB188(void*, int)` | Matching | 100.00% | 20 |
| `func_002AB1A0` | Matching | 100.00% | 36 |
| `func_002AB1C8` | Matching | 100.00% | 52 |
| `func_002AB200` | Matching | 100.00% | 632 |
| `func_002AB478` | Matching | 100.00% | 564 |
| `func_002AB6B0` | Matching | 100.00% | 236 |
| `func_002AB7A0` | Matching | 100.00% | 132 |
| `func_002AB828` | Matching | 100.00% | 192 |
| `func_002AB8E8` | Matching | 100.00% | 112 |
| `func_002AB958` | Matching | 100.00% | 136 |
| `func_002AB9E0` | Matching | 100.00% | 56 |
| `func_002ABA18` | Matching | 100.00% | 36 |
| `func_002ABA40` | Matching | 100.00% | 248 |
| `func_002ABB38` | Matching | 100.00% | 72 |
| `func_002ABB80` | Matching | 100.00% | 88 |
| `func_002ABBD8` | Matching | 100.00% | 60 |
| `func_002ABC18` | Matching | 100.00% | 100 |
| `func_002ABC80(void*, int)` | Matching | 100.00% | 28 |
| `func_002ABCA0` | Matching | 100.00% | 68 |
| `func_002ABCE8(void*, int, int)` | Matching | 100.00% | 12 |
| `func_002ABCF8` | Matching | 100.00% | 64 |
| `func_002ABD38(void*, int, int)` | Matching | 100.00% | 12 |
| `func_002ABD48` | Matching | 100.00% | 72 |
| `func_002ABD90` | Matching | 100.00% | 228 |
| `func_002ABE78` | Matching | 100.00% | 232 |
| `func_002ABF60` | Matching | 100.00% | 544 |
| `func_002AC180` | Matching | 100.00% | 156 |
| `func_002AC220` | Matching | 100.00% | 1488 |
| `func_002AC7F0` | Matching | 100.00% | 116 |
| `func_002AC868` | Matching | 100.00% | 608 |
| `func_002ACAC8` | Matching | 100.00% | 104 |
| `func_002ACB30` | Matching | 100.00% | 80 |
| `func_002ACB80` | Matching | 100.00% | 392 |

### `ui/uianimation`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIAnimationBank_getAnimationByHashName` | Matching | 100.00% | 136 |
| `func_003971C8` | Matching | 100.00% | 172 |
| `func_00397278` | Matching | 100.00% | 28 |
| `func_00397298(void*, int)` | Matching | 100.00% | 8 |
| `cUIAnimation_cUIAnimation` | Matching | 100.00% | 260 |
| `func_003973A8` | Matching | 100.00% | 148 |
| `func_00397440` | Matching | 100.00% | 24 |
| `func_00397458` | Matching | 100.00% | 12 |
| `func_00397468` | Matching | 100.00% | 68 |
| `func_003974B0` | Matching | 100.00% | 304 |
| `func_003975E0` | Matching | 100.00% | 312 |

### `ui/uiengine`

33 matching, 0 partial, 3 not started (36 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `UIAsciiToUnicode(unsigned short*, const char*)` | Matching | 100.00% | 48 |
| `func_00397B08` | Matching | 100.00% | 104 |
| `func_00397B70` | Matching | 100.00% | 204 |
| `cUIEngine_loadFile` | Matching | 100.00% | 124 |
| `cUIEngine_addScreenByHashName` | Matching | 100.00% | 308 |
| `func_00397DF8` | Matching | 100.00% | 540 |
| `func_00398018` | Matching | 100.00% | 28 |
| `func_00398038` | Matching | 100.00% | 64 |
| `func_00398078` | Matching | 100.00% | 188 |
| `cUITextureBank_setData` | Matching | 100.00% | 580 |
| `func_00398380` | Matching | 100.00% | 56 |
| `func_003983B8` | Matching | 100.00% | 56 |
| `func_003983F0` | Matching | 100.00% | 72 |
| `func_00398438` | Matching | 100.00% | 116 |
| `cUIFontInterface_loadFonts` | Matching | 100.00% | 176 |
| `func_00398618(void*)` | Matching | 100.00% | 28 |
| `func_00398638` | Matching | 100.00% | 120 |
| `func_003986B0` | Matching | 100.00% | 136 |
| `func_00398738` | Matching | 100.00% | 92 |
| `func_00398798` | Matching | 100.00% | 92 |
| `func_003987F8` | Matching | 100.00% | 108 |
| `func_00398868` | Matching | 100.00% | 164 |
| `func_00398910` | Matching | 100.00% | 132 |
| `func_00398998` | Matching | 100.00% | 196 |
| `func_00398A60(void *, void *)` | Matching | 100.00% | 20 |
| `func_00399730` | Matching | 100.00% | 56 |
| `func_00399768` | Matching | 100.00% | 180 |
| `func_00399820` | Matching | 100.00% | 252 |
| `func_00399920` | Matching | 100.00% | 80 |
| `func_00399D80` | Matching | 100.00% | 168 |
| `func_00399E28` | Matching | 100.00% | 216 |
| `func_00399F00` | Matching | 100.00% | 1272 |
| `func_003984E8` | Matching | 99.84% | 124 |

### `ui/uilistbox`

16 matching, 0 partial, 0 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIListBox_addEntryByAsciiString` | Matching | 100.00% | 184 |
| `func_0039A4B0` | Matching | 100.00% | 184 |
| `cUIListBox_addEntryByStringID` | Matching | 100.00% | 260 |
| `func_0039A670` | Matching | 100.00% | 152 |
| `func_0039A708` | Matching | 100.00% | 48 |
| `func_0039A738` | Matching | 100.00% | 48 |
| `func_0039A768` | Matching | 100.00% | 64 |
| `func_0039A7A8` | Matching | 100.00% | 28 |
| `func_0039A7C8` | Matching | 100.00% | 40 |
| `cUIListBox_setEntryByAsciiString` | Matching | 100.00% | 228 |
| `func_0039A8D8` | Matching | 100.00% | 76 |
| `func_0039A928` | Matching | 100.00% | 408 |
| `func_0039AAC0` | Matching | 100.00% | 64 |
| `func_0039AB00` | Matching | 100.00% | 80 |
| `func_0039AB50` | Matching | 100.00% | 248 |
| `func_0039AC48` | Matching | 100.00% | 240 |

### `ui/uimenu`

23 matching, 0 partial, 2 not started (25 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIMenu_setSelected` | Matching | 100.00% | 348 |
| `func_0039B6A0` | Matching | 100.00% | 188 |
| `func_0039B760` | Matching | 100.00% | 68 |
| `func_0039B7A8` | Matching | 100.00% | 8 |
| `func_0039B7B0` | Matching | 100.00% | 200 |
| `func_0039B878` | Matching | 100.00% | 228 |
| `cUIMenu_setSelectedByIndex` | Matching | 100.00% | 332 |
| `func_0039BAB0(void*)` | Matching | 100.00% | 28 |
| `func_0039BAD0` | Matching | 100.00% | 128 |
| `func_0039BB50` | Matching | 100.00% | 132 |
| `func_0039BBD8` | Matching | 100.00% | 352 |
| `func_0039BD38` | Matching | 100.00% | 48 |
| `func_0039BD68` | Matching | 100.00% | 164 |
| `func_0039BE10` | Matching | 100.00% | 96 |
| `func_0039BE70` | Matching | 100.00% | 104 |
| `func_0039BED8` | Matching | 100.00% | 600 |
| `func_0039C130` | Matching | 100.00% | 148 |
| `func_0039C1C8` | Matching | 100.00% | 116 |
| `func_0039C240` | Matching | 100.00% | 132 |
| `func_0039C2C8` | Matching | 100.00% | 52 |
| `func_0039C300` | Matching | 100.00% | 148 |
| `func_0039C398` | Matching | 100.00% | 144 |
| `func_0039C428` | Matching | 100.00% | 236 |

### `ui/uiscreen`

50 matching, 0 partial, 2 not started (52 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIThread_deleteThread(void*)` | Matching | 100.00% | 64 |
| `func_0039C558` | Matching | 100.00% | 300 |
| `cUIScreen_setData` | Matching | 100.00% | 160 |
| `func_0039C728` | Matching | 100.00% | 76 |
| `cUIScreen_getFrameByLabel(cUIScreen*, int)` | Matching | 100.00% | 68 |
| `cUIScreen_getPrimaryThread` | Matching | 100.00% | 96 |
| `cUIScreen_jumpToFrame(void*, unsigned short)` | Matching | 100.00% | 80 |
| `func_0039CBC8` | Matching | 100.00% | 24 |
| `func_0039CBE0` | Matching | 100.00% | 84 |
| `func_0039CC38` | Matching | 100.00% | 108 |
| `func_0039CCA8` | Matching | 100.00% | 132 |
| `func_0039CD30` | Matching | 100.00% | 96 |
| `func_0039CD90(void*)` | Matching | 100.00% | 8 |
| `func_0039CD98(void*)` | Matching | 100.00% | 8 |
| `func_0039CDA0` | Matching | 100.00% | 128 |
| `func_0039CE20` | Matching | 100.00% | 36 |
| `func_0039CE48` | Matching | 100.00% | 72 |
| `func_0039CE90(void*)` | Matching | 100.00% | 8 |
| `func_0039CE98` | Matching | 100.00% | 56 |
| `cUIScreen_createAllObjects` | Matching | 100.00% | 312 |
| `func_0039D008` | Matching | 100.00% | 112 |
| `cUIScreen_createObjectByStruct` | Matching | 100.00% | 1760 |
| `func_0039D758(void*)` | Matching | 100.00% | 28 |
| `cUIScreen_getObjectByHashName` | Matching | 100.00% | 92 |
| `func_0039D8C0` | Matching | 100.00% | 132 |
| `func_0039D948(void*)` | Matching | 100.00% | 28 |
| `func_0039D968` | Matching | 100.00% | 180 |
| `func_0039DA20` | Matching | 100.00% | 1096 |
| `func_0039DE68` | Matching | 100.00% | 192 |
| `func_0039DF28` | Matching | 100.00% | 132 |
| `func_0039DFB0` | Matching | 100.00% | 52 |
| `func_0039DFE8` | Matching | 100.00% | 328 |
| `func_0039E130` | Matching | 100.00% | 340 |
| `func_0039E288(void*)` | Matching | 100.00% | 20 |
| `func_0039E2A0` | Matching | 100.00% | 116 |
| `func_0039E318` | Matching | 100.00% | 116 |
| `func_0039E390` | Matching | 100.00% | 168 |
| `func_0039E438` | Matching | 100.00% | 52 |
| `func_0039E470` | Matching | 100.00% | 44 |
| `func_0039E4A0(void*)` | Matching | 100.00% | 28 |
| `func_0039E4C0` | Matching | 100.00% | 72 |
| `func_0039E508(void*)` | Matching | 100.00% | 8 |
| `func_0039E510` | Matching | 100.00% | 372 |
| `func_0039E688` | Matching | 100.00% | 48 |
| `func_0039E6B8` | Matching | 100.00% | 160 |
| `func_0039E758` | Matching | 100.00% | 28 |
| `func_0039E778` | Matching | 100.00% | 116 |
| `func_0039E7F0` | Matching | 100.00% | 116 |
| `func_0039E868` | Matching | 100.00% | 76 |
| `func_0039D778` | Matching | 99.91% | 228 |

### `ui/uistate`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIState_hideObjSafe` | Matching | 100.00% | 140 |
| `cUIState_showObjSafe` | Matching | 100.00% | 140 |
| `func_0039E9D8` | Matching | 100.00% | 184 |
| `func_0039EA90` | Matching | 100.00% | 204 |
| `func_0039EB60` | Matching | 100.00% | 128 |
| `func_0039EBE0` | Matching | 100.00% | 196 |
| `func_0039ECA8(void*)` | Matching | 100.00% | 8 |
| `func_0039F100` | Matching | 100.00% | 144 |
| `func_0039F190` | Matching | 100.00% | 108 |
| `func_0039F200` | Matching | 100.00% | 56 |
| `func_0039ECB0` | Matching | 99.96% | 1100 |

### `ui/uistatestack`

24 matching, 0 partial, 1 not started (25 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIStateStack_pushExplicit` | Matching | 100.00% | 88 |
| `cUIStateStack_pushSpecial` | Matching | 100.00% | 220 |
| `func_0039F400` | Matching | 100.00% | 192 |
| `func_0039F4C0` | Matching | 100.00% | 316 |
| `func_0039F600` | Matching | 100.00% | 152 |
| `func_0039F698` | Matching | 100.00% | 128 |
| `func_0039F718` | Matching | 100.00% | 160 |
| `func_0039F7B8` | Matching | 100.00% | 136 |
| `func_0039F840` | Matching | 100.00% | 136 |
| `func_0039F8C8` | Matching | 100.00% | 268 |
| `func_0039F9D8` | Matching | 100.00% | 172 |
| `cUIStateStack_getCurrentState` | Matching | 100.00% | 96 |
| `func_0039FAE8` | Matching | 100.00% | 28 |
| `func_0039FB08` | Matching | 100.00% | 36 |
| `func_0039FB30` | Matching | 100.00% | 276 |
| `func_0039FC48` | Matching | 100.00% | 128 |
| `func_0039FCC8` | Matching | 100.00% | 108 |
| `func_0039FD38` | Matching | 100.00% | 68 |
| `func_0039FD80` | Matching | 100.00% | 88 |
| `func_0039FDD8` | Matching | 100.00% | 40 |
| `func_0039FE00` | Matching | 100.00% | 184 |
| `func_0039FEB8` | Matching | 100.00% | 152 |
| `func_0039FF50(void*)` | Matching | 100.00% | 16 |
| `func_0039FF60` | Matching | 100.00% | 20 |

### `ui/uitext`

35 matching, 0 partial, 3 not started (38 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIText_deleteText` | Matching | 100.00% | 84 |
| `cUIText_getNumTextLines` | Matching | 100.00% | 108 |
| `func_003A0C00` | Matching | 100.00% | 36 |
| `func_003A0C28` | Matching | 100.00% | 36 |
| `cUIText_setAsciiString(cUIText*, const char*)` | Matching | 100.00% | 32 |
| `cUIText_setAsciiStringPrivate` | Matching | 100.00% | 140 |
| `func_003A0D00` | Matching | 100.00% | 400 |
| `func_003A0E90` | Matching | 100.00% | 32 |
| `cUIText_setUnicodeStringPrivate` | Matching | 100.00% | 336 |
| `cUIText_setUnicodeStringByID(cUIText*, int)` | Matching | 100.00% | 48 |
| `func_003A1030` | Matching | 100.00% | 192 |
| `func_003A10F0` | Matching | 100.00% | 88 |
| `func_003A1148` | Matching | 100.00% | 112 |
| `func_003A11B8` | Matching | 100.00% | 276 |
| `func_003A12D0` | Matching | 100.00% | 60 |
| `func_003A1310` | Matching | 100.00% | 80 |
| `func_003A1360` | Matching | 100.00% | 128 |
| `func_003A13E0` | Matching | 100.00% | 424 |
| `func_003A1588` | Matching | 100.00% | 824 |
| `func_003A18C0` | Matching | 100.00% | 152 |
| `func_003A1958` | Matching | 100.00% | 156 |
| `func_003A19F8` | Matching | 100.00% | 508 |
| `cUITextScroll_addUnicodeString` | Matching | 100.00% | 136 |
| `func_003A1CF0` | Matching | 100.00% | 60 |
| `func_003A1D30` | Matching | 100.00% | 484 |
| `func_003A1F18` | Matching | 100.00% | 120 |
| `func_003A1F90` | Matching | 100.00% | 212 |
| `func_003A2068` | Matching | 100.00% | 56 |
| `func_003A20A0` | Matching | 100.00% | 384 |
| `func_003A2220` | Matching | 100.00% | 408 |
| `func_003A2A00` | Matching | 100.00% | 456 |
| `func_003A3280` | Matching | 100.00% | 112 |
| `func_003A32F0` | Matching | 100.00% | 164 |
| `func_003A3398` | Matching | 100.00% | 296 |
| `cUIText_render2D` | Matching | 99.99% | 1356 |

### `ui/uithing`

11 matching, 0 partial, 1 not started (12 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cUIThing_getKeyframerEvent(cUIThing*, int)` | Matching | 100.00% | 40 |
| `func_003A0000` | Matching | 100.00% | 68 |
| `func_003A0048` | Matching | 100.00% | 268 |
| `func_003A0158` | Matching | 100.00% | 308 |
| `func_003A0290` | Matching | 100.00% | 132 |
| `func_003A0318` | Matching | 100.00% | 20 |
| `func_003A0330` | Matching | 100.00% | 20 |
| `func_003A0348` | Matching | 100.00% | 168 |
| `func_003A03F0` | Matching | 100.00% | 252 |
| `func_003A04F0` | Matching | 100.00% | 56 |
| `func_003A0528` | Matching | 100.00% | 188 |

### `ui/uivector`

288 matching, 0 partial, 1 not started (289 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_003A36D0` | Matching | 100.00% | 308 |
| `func_003A3808` | Matching | 100.00% | 496 |
| `func_003A39F8` | Matching | 100.00% | 816 |
| `func_003A3D28` | Matching | 100.00% | 68 |
| `func_003A3D70` | Matching | 100.00% | 200 |
| `func_003A3E38` | Matching | 100.00% | 208 |
| `func_003A3F08` | Matching | 100.00% | 60 |
| `func_003A4778` | Matching | 100.00% | 20 |
| `func_003A4790` | Matching | 100.00% | 12 |
| `func_003A47A0` | Matching | 100.00% | 8 |
| `func_003A47A8` | Matching | 100.00% | 48 |
| `func_003A47D8` | Matching | 100.00% | 28 |
| `func_003A47F8` | Matching | 100.00% | 80 |
| `func_003A4848` | Matching | 100.00% | 8 |
| `func_003A4850` | Matching | 100.00% | 8 |
| `func_003A4858` | Matching | 100.00% | 8 |
| `func_003A4860` | Matching | 100.00% | 8 |
| `func_003A4868` | Matching | 100.00% | 28 |
| `func_003A4888` | Matching | 100.00% | 120 |
| `func_003A4900` | Matching | 100.00% | 64 |
| `func_003A4940` | Matching | 100.00% | 12 |
| `func_003A4950` | Matching | 100.00% | 8 |
| `func_003A4958` | Matching | 100.00% | 16 |
| `func_003A4968` | Matching | 100.00% | 12 |
| `func_003A4978` | Matching | 100.00% | 16 |
| `func_003A4988` | Matching | 100.00% | 16 |
| `func_003A4998` | Matching | 100.00% | 16 |
| `func_003A49A8` | Matching | 100.00% | 16 |
| `func_003A49B8` | Matching | 100.00% | 16 |
| `func_003A49C8` | Matching | 100.00% | 16 |
| `func_003A49D8` | Matching | 100.00% | 16 |
| `func_003A49E8` | Matching | 100.00% | 32 |
| `func_003A4A08` | Matching | 100.00% | 32 |
| `func_003A4A28` | Matching | 100.00% | 32 |
| `func_003A4A48` | Matching | 100.00% | 32 |
| `func_003A4A68` | Matching | 100.00% | 32 |
| `func_003A4A88` | Matching | 100.00% | 32 |
| `func_003A4AA8` | Matching | 100.00% | 32 |
| `func_003A4AC8` | Matching | 100.00% | 8 |
| `func_003A4AD0` | Matching | 100.00% | 8 |
| `func_003A4AD8` | Matching | 100.00% | 28 |
| `func_003A4AF8` | Matching | 100.00% | 40 |
| `func_003A4B20` | Matching | 100.00% | 8 |
| `func_003A4B28` | Matching | 100.00% | 40 |
| `func_003A4B50` | Matching | 100.00% | 8 |
| `func_003A4B58` | Matching | 100.00% | 8 |
| `func_003A4B60` | Matching | 100.00% | 16 |
| `func_003A4B70` | Matching | 100.00% | 32 |
| `func_003A4B90` | Matching | 100.00% | 36 |
| `func_003A4BB8` | Matching | 100.00% | 16 |
| `func_003A4BC8` | Matching | 100.00% | 8 |
| `func_003A4BD0` | Matching | 100.00% | 8 |
| `func_003A4BD8(void*)` | Matching | 100.00% | 8 |
| `func_003A4BE0(void*)` | Matching | 100.00% | 8 |
| `func_003A4BE8(void*)` | Matching | 100.00% | 8 |
| `func_003A4BF0(void*)` | Matching | 100.00% | 8 |
| `func_003A4BF8` | Matching | 100.00% | 8 |
| `func_003A4C00` | Matching | 100.00% | 8 |
| `func_003A4C08` | Matching | 100.00% | 32 |
| `func_003A4C28` | Matching | 100.00% | 32 |
| `func_003A4C48` | Matching | 100.00% | 32 |
| `func_003A4C68` | Matching | 100.00% | 32 |
| `func_003A4C88` | Matching | 100.00% | 8 |
| `func_003A4C90` | Matching | 100.00% | 32 |
| `func_003A4CB0` | Matching | 100.00% | 32 |
| `func_003A4CD0` | Matching | 100.00% | 48 |
| `func_003A4D00` | Matching | 100.00% | 64 |
| `func_003A4D40` | Matching | 100.00% | 48 |
| `func_003A4D70` | Matching | 100.00% | 52 |
| `func_003A4DA8` | Matching | 100.00% | 48 |
| `func_003A4DD8` | Matching | 100.00% | 8 |
| `func_003A4DE0` | Matching | 100.00% | 8 |
| `func_003A4DE8` | Matching | 100.00% | 8 |
| `func_003A4DF0` | Matching | 100.00% | 68 |
| `func_003A4E38` | Matching | 100.00% | 72 |
| `func_003A4E80(void*)` | Matching | 100.00% | 40 |
| `func_003A4EA8(void*)` | Matching | 100.00% | 8 |
| `func_003A4EB0` | Matching | 100.00% | 20 |
| `func_003A4EC8` | Matching | 100.00% | 12 |
| `func_003A4ED8` | Matching | 100.00% | 28 |
| `func_003A4EF8` | Matching | 100.00% | 16 |
| `func_003A4F08` | Matching | 100.00% | 32 |
| `func_003A4F28` | Matching | 100.00% | 16 |
| `func_003A4F38` | Matching | 100.00% | 32 |
| `func_003A4F58` | Matching | 100.00% | 8 |
| `func_003A4F60` | Matching | 100.00% | 16 |
| `func_003A4F70` | Matching | 100.00% | 8 |
| `func_003A4F78` | Matching | 100.00% | 12 |
| `func_003A4F88` | Matching | 100.00% | 24 |
| `func_003A4FA0` | Matching | 100.00% | 24 |
| `func_003A4FB8` | Matching | 100.00% | 36 |
| `func_003A4FE0` | Matching | 100.00% | 68 |
| `func_003A5028` | Matching | 100.00% | 60 |
| `func_003A5068` | Matching | 100.00% | 140 |
| `func_003A50F8(void*)` | Matching | 100.00% | 8 |
| `func_003A5100` | Matching | 100.00% | 28 |
| `func_003A5120` | Matching | 100.00% | 28 |
| `func_003A5140` | Matching | 100.00% | 28 |
| `func_003A5160` | Matching | 100.00% | 28 |
| `func_003A5180` | Matching | 100.00% | 28 |
| `func_003A51A0` | Matching | 100.00% | 48 |
| `func_003A51D0` | Matching | 100.00% | 96 |
| `func_003A5230` | Matching | 100.00% | 112 |
| `func_003A52A0` | Matching | 100.00% | 140 |
| `func_003A5330(void*)` | Matching | 100.00% | 8 |
| `func_003A5338` | Matching | 100.00% | 20 |
| `func_003A5350` | Matching | 100.00% | 16 |
| `func_003A5360` | Matching | 100.00% | 32 |
| `func_003A5380` | Matching | 100.00% | 16 |
| `func_003A5390` | Matching | 100.00% | 32 |
| `func_003A53B0` | Matching | 100.00% | 12 |
| `func_003A53C0` | Matching | 100.00% | 28 |
| `func_003A53E0` | Matching | 100.00% | 8 |
| `func_003A53E8` | Matching | 100.00% | 8 |
| `func_003A53F0` | Matching | 100.00% | 8 |
| `func_003A53F8` | Matching | 100.00% | 8 |
| `func_003A5400` | Matching | 100.00% | 8 |
| `func_003A5408` | Matching | 100.00% | 8 |
| `func_003A5410` | Matching | 100.00% | 8 |
| `func_003A5418` | Matching | 100.00% | 8 |
| `func_003A5420` | Matching | 100.00% | 68 |
| `func_003A5468` | Matching | 100.00% | 80 |
| `func_003A54B8` | Matching | 100.00% | 72 |
| `func_003A5500(void*)` | Matching | 100.00% | 8 |
| `func_003A5508` | Matching | 100.00% | 32 |
| `func_003A5528` | Matching | 100.00% | 8 |
| `func_003A5530` | Matching | 100.00% | 80 |
| `func_003A5580` | Matching | 100.00% | 8 |
| `func_003A5588` | Matching | 100.00% | 80 |
| `func_003A55D8` | Matching | 100.00% | 124 |
| `func_003A5658` | Matching | 100.00% | 72 |
| `func_003A56A0(void*)` | Matching | 100.00% | 8 |
| `func_003A56A8` | Matching | 100.00% | 28 |
| `func_003A56C8` | Matching | 100.00% | 16 |
| `func_003A56D8` | Matching | 100.00% | 32 |
| `func_003A56F8` | Matching | 100.00% | 16 |
| `func_003A5708` | Matching | 100.00% | 32 |
| `func_003A5728` | Matching | 100.00% | 16 |
| `func_003A5738` | Matching | 100.00% | 32 |
| `func_003A5758` | Matching | 100.00% | 40 |
| `func_003A5780` | Matching | 100.00% | 40 |
| `func_003A57A8` | Matching | 100.00% | 8 |
| `func_003A57B0` | Matching | 100.00% | 8 |
| `func_003A57B8` | Matching | 100.00% | 72 |
| `func_003A5800` | Matching | 100.00% | 8 |
| `func_003A5808` | Matching | 100.00% | 8 |
| `func_003A5810` | Matching | 100.00% | 8 |
| `func_003A5818` | Matching | 100.00% | 8 |
| `func_003A5820` | Matching | 100.00% | 8 |
| `func_003A5828` | Matching | 100.00% | 8 |
| `func_003A5830` | Matching | 100.00% | 8 |
| `func_003A5838` | Matching | 100.00% | 8 |
| `func_003A5840` | Matching | 100.00% | 8 |
| `func_003A5848` | Matching | 100.00% | 12 |
| `func_003A5858` | Matching | 100.00% | 32 |
| `func_003A5878` | Matching | 100.00% | 16 |
| `func_003A5888` | Matching | 100.00% | 32 |
| `func_003A58A8` | Matching | 100.00% | 16 |
| `func_003A58B8` | Matching | 100.00% | 32 |
| `func_003A58D8` | Matching | 100.00% | 16 |
| `func_003A58E8` | Matching | 100.00% | 32 |
| `func_003A5908` | Matching | 100.00% | 16 |
| `func_003A5918` | Matching | 100.00% | 36 |
| `func_003A5940` | Matching | 100.00% | 16 |
| `func_003A5950` | Matching | 100.00% | 32 |
| `func_003A5970` | Matching | 100.00% | 16 |
| `func_003A5980` | Matching | 100.00% | 32 |
| `func_003A59A0` | Matching | 100.00% | 16 |
| `func_003A59B0` | Matching | 100.00% | 16 |
| `func_003A59C0` | Matching | 100.00% | 32 |
| `func_003A59E0` | Matching | 100.00% | 44 |
| `func_003A5A10` | Matching | 100.00% | 56 |
| `func_003A5A48` | Matching | 100.00% | 12 |
| `func_003A5A58` | Matching | 100.00% | 28 |
| `func_003A5A78` | Matching | 100.00% | 16 |
| `func_003A5A88` | Matching | 100.00% | 32 |
| `func_003A5AA8(void*)` | Matching | 100.00% | 8 |
| `func_003A5AB0(void*)` | Matching | 100.00% | 8 |
| `func_003A5AB8(void*)` | Matching | 100.00% | 8 |
| `func_003A5AC0(void*)` | Matching | 100.00% | 8 |
| `func_003A5AC8(void*)` | Matching | 100.00% | 8 |
| `func_003A5AD0(void*)` | Matching | 100.00% | 8 |
| `func_003A5AD8(void*)` | Matching | 100.00% | 8 |
| `func_003A5AE0` | Matching | 100.00% | 8 |
| `func_003A5AE8` | Matching | 100.00% | 8 |
| `func_003A5AF0` | Matching | 100.00% | 8 |
| `func_003A5AF8` | Matching | 100.00% | 8 |
| `func_003A5B00` | Matching | 100.00% | 8 |
| `func_003A5B08(void*)` | Matching | 100.00% | 8 |
| `func_003A5B10(void*)` | Matching | 100.00% | 8 |
| `func_003A5B18(void*)` | Matching | 100.00% | 8 |
| `func_003A5B20(void*)` | Matching | 100.00% | 8 |
| `func_003A5B28(void*)` | Matching | 100.00% | 8 |
| `func_003A5B30(void*)` | Matching | 100.00% | 8 |
| `func_003A5B38(void*)` | Matching | 100.00% | 8 |
| `func_003A5B40(void*)` | Matching | 100.00% | 8 |
| `func_003A5B48` | Matching | 100.00% | 80 |
| `func_003A5B98` | Matching | 100.00% | 108 |
| `func_003A5C08` | Matching | 100.00% | 144 |
| `func_003A5C98` | Matching | 100.00% | 12 |
| `func_003A5CA8` | Matching | 100.00% | 24 |
| `func_003A5CC0` | Matching | 100.00% | 12 |
| `func_003A5CD0` | Matching | 100.00% | 28 |
| `func_003A5CF0` | Matching | 100.00% | 28 |
| `func_003A5D10` | Matching | 100.00% | 8 |
| `func_003A5D18` | Matching | 100.00% | 32 |
| `func_003A5D38` | Matching | 100.00% | 16 |
| `func_003A5D48` | Matching | 100.00% | 12 |
| `func_003A5D58` | Matching | 100.00% | 8 |
| `func_003A5D60` | Matching | 100.00% | 68 |
| `func_003A5DA8` | Matching | 100.00% | 72 |
| `func_003A5DF0(void*)` | Matching | 100.00% | 8 |
| `func_003A5DF8` | Matching | 100.00% | 28 |
| `func_003A5E18` | Matching | 100.00% | 16 |
| `func_003A5E28` | Matching | 100.00% | 16 |
| `func_003A5E38` | Matching | 100.00% | 16 |
| `func_003A5E48` | Matching | 100.00% | 16 |
| `func_003A5E58` | Matching | 100.00% | 16 |
| `func_003A5E68` | Matching | 100.00% | 32 |
| `func_003A5E88` | Matching | 100.00% | 32 |
| `func_003A5EA8` | Matching | 100.00% | 32 |
| `func_003A5EC8` | Matching | 100.00% | 32 |
| `func_003A5EE8` | Matching | 100.00% | 32 |
| `func_003A5F08` | Matching | 100.00% | 40 |
| `func_003A5F30` | Matching | 100.00% | 40 |
| `func_003A5F58` | Matching | 100.00% | 8 |
| `func_003A5F60` | Matching | 100.00% | 60 |
| `func_003A5FA0` | Matching | 100.00% | 96 |
| `func_003A6000(void*)` | Matching | 100.00% | 8 |
| `func_003A6008` | Matching | 100.00% | 8 |
| `func_003A6010` | Matching | 100.00% | 8 |
| `func_003A6018` | Matching | 100.00% | 8 |
| `func_003A6020` | Matching | 100.00% | 8 |
| `func_003A6028` | Matching | 100.00% | 8 |
| `func_003A6030` | Matching | 100.00% | 8 |
| `func_003A6038` | Matching | 100.00% | 80 |
| `func_003A6088` | Matching | 100.00% | 80 |
| `func_003A60D8` | Matching | 100.00% | 8 |
| `func_003A60E0` | Matching | 100.00% | 60 |
| `func_003A6120` | Matching | 100.00% | 72 |
| `func_003A6168(void*)` | Matching | 100.00% | 8 |
| `func_003A6170` | Matching | 100.00% | 8 |
| `func_003A6178` | Matching | 100.00% | 8 |
| `func_003A6180` | Matching | 100.00% | 8 |
| `func_003A6188` | Matching | 100.00% | 8 |
| `func_003A6190` | Matching | 100.00% | 60 |
| `func_003A61D0` | Matching | 100.00% | 76 |
| `func_003A6220(void*)` | Matching | 100.00% | 8 |
| `func_003A6228` | Matching | 100.00% | 8 |
| `func_003A6230` | Matching | 100.00% | 8 |
| `func_003A6238` | Matching | 100.00% | 8 |
| `func_003A6240` | Matching | 100.00% | 8 |
| `func_003A6248` | Matching | 100.00% | 8 |
| `func_003A6250` | Matching | 100.00% | 76 |
| `func_003A62A0` | Matching | 100.00% | 144 |
| `func_003A6330(void*)` | Matching | 100.00% | 8 |
| `func_003A6338` | Matching | 100.00% | 32 |
| `func_003A6358` | Matching | 100.00% | 16 |
| `func_003A6368` | Matching | 100.00% | 16 |
| `func_003A6378` | Matching | 100.00% | 32 |
| `func_003A6398` | Matching | 100.00% | 32 |
| `func_003A63B8` | Matching | 100.00% | 40 |
| `func_003A63E0` | Matching | 100.00% | 28 |
| `func_003A6400` | Matching | 100.00% | 28 |
| `func_003A6420` | Matching | 100.00% | 28 |
| `func_003A6440` | Matching | 100.00% | 28 |
| `func_003A6460` | Matching | 100.00% | 28 |
| `func_003A6480` | Matching | 100.00% | 16 |
| `func_003A6490` | Matching | 100.00% | 12 |
| `func_003A64A0` | Matching | 100.00% | 40 |
| `func_003A64C8` | Matching | 100.00% | 8 |
| `func_003A64D0` | Matching | 100.00% | 8 |
| `func_003A64D8` | Matching | 100.00% | 8 |
| `func_003A64E0` | Matching | 100.00% | 8 |
| `func_003A64E8` | Matching | 100.00% | 8 |
| `func_003A64F0` | Matching | 100.00% | 8 |
| `func_003A64F8` | Matching | 100.00% | 68 |
| `func_003A6540(void*)` | Matching | 100.00% | 8 |
| `func_003A6548` | Matching | 100.00% | 88 |
| `func_003A65A0` | Matching | 100.00% | 24 |
| `func_003A65B8` | Matching | 100.00% | 28 |
| `func_003A65D8` | Matching | 100.00% | 16 |
| `func_003A65E8` | Matching | 100.00% | 24 |
| `func_003A6600` | Matching | 100.00% | 20 |
| `func_003A6618` | Matching | 100.00% | 44 |
| `func_003A6648(void*)` | Matching | 100.00% | 32 |
| `func_003A6668(void*)` | Matching | 100.00% | 32 |
| `func_003A3F48` | Matching | 99.98% | 2092 |

### `util/list`

16 matching, 0 partial, 0 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cListNode_isSentinel(cListNode*)` | Matching | 100.00% | 36 |
| `cListNode_removeFromList` | Matching | 100.00% | 72 |
| `func_00397788` | Matching | 100.00% | 48 |
| `func_003977B8` | Matching | 100.00% | 48 |
| `func_003977E8` | Matching | 100.00% | 88 |
| `cList_first(cList*)` | Matching | 100.00% | 20 |
| `func_00397858` | Matching | 100.00% | 20 |
| `func_00397870` | Matching | 100.00% | 120 |
| `func_003978E8` | Matching | 100.00% | 8 |
| `cList_addToFront(cList*, cListNode*)` | Matching | 100.00% | 28 |
| `cList_addToEnd(cList*, cListNode*)` | Matching | 100.00% | 28 |
| `func_00397930(void*)` | Matching | 100.00% | 24 |
| `func_00397948` | Matching | 100.00% | 116 |
| `func_003979C0` | Matching | 100.00% | 52 |
| `func_003979F8` | Matching | 100.00% | 112 |
| `func_00397A68` | Matching | 100.00% | 112 |

### `util/locale`

16 matching, 0 partial, 0 not started (16 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cFELocale_addFile` | Matching | 100.00% | 164 |
| `func_00195A50` | Matching | 100.00% | 68 |
| `func_00195A98` | Matching | 100.00% | 8 |
| `func_00195AA0` | Matching | 100.00% | 208 |
| `func_00195B70` | Matching | 100.00% | 108 |
| `func_00195BE0` | Matching | 100.00% | 368 |
| `func_00195D50` | Matching | 100.00% | 140 |
| `func_00195DE0` | Matching | 100.00% | 116 |
| `func_00195E58` | Matching | 100.00% | 92 |
| `func_00195EB8` | Matching | 100.00% | 180 |
| `func_00195F70` | Matching | 100.00% | 124 |
| `func_00195FF0` | Matching | 100.00% | 340 |
| `func_00196148` | Matching | 100.00% | 224 |
| `func_00196228` | Matching | 100.00% | 128 |
| `func_001962A8` | Matching | 100.00% | 204 |
| `func_00196378` | Matching | 100.00% | 456 |

### `util/menu`

193 matching, 0 partial, 4 not started (197 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cMenuItem_cMenuItem(cMenuItem*, void*)` | Matching | 100.00% | 36 |
| `func_002CA280` | Matching | 100.00% | 48 |
| `func_002CA2B0` | Matching | 100.00% | 112 |
| `func_002CA320` | Matching | 100.00% | 72 |
| `func_002CA368(void*)` | Matching | 100.00% | 8 |
| `func_002CA370(void*)` | Matching | 100.00% | 8 |
| `func_002CA378` | Matching | 100.00% | 12 |
| `func_002CA388` | Matching | 100.00% | 36 |
| `func_002CA3B0` | Matching | 100.00% | 12 |
| `func_002CA3C0` | Matching | 100.00% | 36 |
| `func_002CA3E8` | Matching | 100.00% | 32 |
| `func_002CA408(void*)` | Matching | 100.00% | 32 |
| `func_002CA428(void*)` | Matching | 100.00% | 32 |
| `func_002CA448(void*)` | Matching | 100.00% | 32 |
| `func_002CA468(void*)` | Matching | 100.00% | 32 |
| `func_002CA488(void*)` | Matching | 100.00% | 32 |
| `func_002CA4A8(void*)` | Matching | 100.00% | 32 |
| `func_002CA768` | Matching | 100.00% | 544 |
| `func_002CA988` | Matching | 100.00% | 208 |
| `func_002CAA58(void*)` | Matching | 100.00% | 36 |
| `func_002CAA80` | Matching | 100.00% | 48 |
| `func_002CAAB0` | Matching | 100.00% | 84 |
| `func_002CAB08` | Matching | 100.00% | 216 |
| `func_002CABE0` | Matching | 100.00% | 220 |
| `func_002CACC0` | Matching | 100.00% | 132 |
| `func_002CAD48(void*)` | Matching | 100.00% | 8 |
| `func_002CAD50(void*)` | Matching | 100.00% | 8 |
| `func_002CB180` | Matching | 100.00% | 376 |
| `func_002CB2F8` | Matching | 100.00% | 84 |
| `func_002CB350` | Matching | 100.00% | 328 |
| `func_002CB498` | Matching | 100.00% | 996 |
| `func_002CB880` | Matching | 100.00% | 72 |
| `func_002CB8C8` | Matching | 100.00% | 508 |
| `func_002CBAC8` | Matching | 100.00% | 508 |
| `cMenu_addItem` | Matching | 100.00% | 132 |
| `func_002CBD50` | Matching | 100.00% | 188 |
| `func_002CBE10` | Matching | 100.00% | 12 |
| `func_002CBE20` | Matching | 100.00% | 72 |
| `func_002CBE68` | Matching | 100.00% | 156 |
| `func_002CBF08` | Matching | 100.00% | 40 |
| `func_002CBF30` | Matching | 100.00% | 48 |
| `func_002CBF60` | Matching | 100.00% | 112 |
| `func_002CBFD0` | Matching | 100.00% | 72 |
| `func_002CC018` | Matching | 100.00% | 44 |
| `func_002CC048` | Matching | 100.00% | 36 |
| `func_002CC070(void*)` | Matching | 100.00% | 40 |
| `func_002CC098` | Matching | 100.00% | 28 |
| `func_002CC0B8(void*, int)` | Matching | 100.00% | 8 |
| `func_002CC0C0` | Matching | 100.00% | 392 |
| `func_002CC248(void*)` | Matching | 100.00% | 8 |
| `func_002CC250(void*)` | Matching | 100.00% | 8 |
| `func_002CC258(void*)` | Matching | 100.00% | 8 |
| `func_002CC260(void*)` | Matching | 100.00% | 32 |
| `func_002CC280(void*)` | Matching | 100.00% | 32 |
| `func_002CC2A0(void*)` | Matching | 100.00% | 32 |
| `func_002CC2C0(void*)` | Matching | 100.00% | 32 |
| `func_002CC2E0` | Matching | 100.00% | 56 |
| `func_002CC318` | Matching | 100.00% | 56 |
| `func_002CC3B8` | Matching | 100.00% | 168 |
| `func_002CC460` | Matching | 100.00% | 160 |
| `func_002CC500` | Matching | 100.00% | 116 |
| `func_002CC578` | Matching | 100.00% | 204 |
| `func_002CC758` | Matching | 100.00% | 88 |
| `func_002CC7B0` | Matching | 100.00% | 68 |
| `func_002CC7F8` | Matching | 100.00% | 64 |
| `func_002CC838` | Matching | 100.00% | 116 |
| `func_002CC8B0` | Matching | 100.00% | 60 |
| `func_002CC8F0` | Matching | 100.00% | 548 |
| `func_002CCC38` | Matching | 100.00% | 140 |
| `cSubMenuItem_cSubMenuItem` | Matching | 100.00% | 88 |
| `func_002CCD20` | Matching | 100.00% | 112 |
| `func_002CCDC8(void*, int)` | Matching | 100.00% | 36 |
| `func_002CCDF0` | Matching | 100.00% | 72 |
| `func_002CCE38` | Matching | 100.00% | 108 |
| `func_002CCEE0(void*, int)` | Matching | 100.00% | 36 |
| `func_002CCF08` | Matching | 100.00% | 72 |
| `func_002CCF50` | Matching | 100.00% | 68 |
| `func_002CCF98` | Matching | 100.00% | 92 |
| `func_002CCFF8` | Matching | 100.00% | 16 |
| `func_002CD008` | Matching | 100.00% | 132 |
| `func_002CD0E8` | Matching | 100.00% | 64 |
| `func_002CD128` | Matching | 100.00% | 64 |
| `func_002CD168` | Matching | 100.00% | 84 |
| `func_002CD1C0` | Matching | 100.00% | 12 |
| `func_002CD1D0` | Matching | 100.00% | 108 |
| `func_002CD278(void*, int)` | Matching | 100.00% | 40 |
| `cNullMenuItem_cNullMenuItem(cNullMenuItem*, void*)` | Matching | 100.00% | 72 |
| `func_002CD2E8(void*)` | Matching | 100.00% | 8 |
| `func_002CD328(void*, int)` | Matching | 100.00% | 36 |
| `cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem*, void*)` | Matching | 100.00% | 72 |
| `func_002CD398(void*)` | Matching | 100.00% | 8 |
| `func_002CD3A0` | Matching | 100.00% | 76 |
| `func_002CD3F0(void*)` | Matching | 100.00% | 8 |
| `func_002CD3F8` | Matching | 100.00% | 84 |
| `func_002CD450` | Matching | 100.00% | 80 |
| `func_002CD4A0` | Matching | 100.00% | 136 |
| `func_002CD528` | Matching | 100.00% | 76 |
| `func_002CD578` | Matching | 100.00% | 36 |
| `func_002CD7F0` | Matching | 100.00% | 92 |
| `func_002CD850` | Matching | 100.00% | 84 |
| `func_002CD8A8` | Matching | 100.00% | 80 |
| `cIntMenuItem_cIntMenuItem` | Matching | 100.00% | 128 |
| `func_002CD978` | Matching | 100.00% | 64 |
| `func_002CD9B8` | Matching | 100.00% | 28 |
| `func_002CDC28` | Matching | 100.00% | 92 |
| `func_002CDC88` | Matching | 100.00% | 96 |
| `cFloatMenuItem_cFloatMenuItem` | Matching | 100.00% | 140 |
| `func_002CDF78` | Matching | 100.00% | 40 |
| `func_002CE100` | Matching | 100.00% | 112 |
| `func_002CE170` | Matching | 100.00% | 124 |
| `func_002CE418` | Matching | 100.00% | 108 |
| `func_002CE488` | Matching | 100.00% | 916 |
| `func_002CE910` | Matching | 100.00% | 1040 |
| `cColorMenuItem__cColorMenuItem` | Matching | 100.00% | 88 |
| `func_002CEEE8` | Matching | 100.00% | 736 |
| `func_002CF788` | Matching | 100.00% | 44 |
| `func_002CF7B8` | Matching | 100.00% | 44 |
| `func_002CF7E8` | Matching | 100.00% | 120 |
| `func_002CF860` | Matching | 100.00% | 120 |
| `func_002CF8D8` | Matching | 100.00% | 48 |
| `cExpandMenuItem_addItem(void *, void *)` | Matching | 100.00% | 28 |
| `func_002CF928` | Matching | 100.00% | 28 |
| `func_002CF948` | Matching | 100.00% | 60 |
| `func_002CF988` | Matching | 100.00% | 124 |
| `func_002CFA08` | Matching | 100.00% | 236 |
| `func_002CFAF8` | Matching | 100.00% | 44 |
| `func_002CFB28` | Matching | 100.00% | 48 |
| `func_002CFB58` | Matching | 100.00% | 464 |
| `func_002CFD28` | Matching | 100.00% | 332 |
| `func_002CFE78` | Matching | 100.00% | 124 |
| `func_002CFEF8` | Matching | 100.00% | 44 |
| `cRGBTitleMenuItem_cRGBTitleMenuItem` | Matching | 100.00% | 88 |
| `func_002CFF80(void*)` | Matching | 100.00% | 8 |
| `func_002D0008` | Matching | 100.00% | 676 |
| `cARGBMenuItem_cARGBMenuItem` | Matching | 100.00% | 288 |
| `func_002D03D0(void*)` | Matching | 100.00% | 28 |
| `func_002D03F0` | Matching | 100.00% | 88 |
| `func_002D0448(void*)` | Matching | 100.00% | 8 |
| `func_002D0500` | Matching | 100.00% | 168 |
| `func_002D05A8` | Matching | 100.00% | 320 |
| `func_002D06E8` | Matching | 100.00% | 288 |
| `func_002D0808` | Matching | 100.00% | 212 |
| `func_002D08E0` | Matching | 100.00% | 40 |
| `func_002D0D48` | Matching | 100.00% | 428 |
| `func_002D1740` | Matching | 100.00% | 172 |
| `func_002D17F0` | Matching | 100.00% | 188 |
| `func_002D18B0` | Matching | 100.00% | 116 |
| `func_002D1928` | Matching | 100.00% | 144 |
| `func_002D19B8` | Matching | 100.00% | 48 |
| `func_002D19E8` | Matching | 100.00% | 72 |
| `func_002D1A30` | Matching | 100.00% | 72 |
| `func_002D1A78` | Matching | 100.00% | 36 |
| `func_002D1AA0` | Matching | 100.00% | 40 |
| `func_002D1AC8` | Matching | 100.00% | 36 |
| `func_002D1AF0` | Matching | 100.00% | 20 |
| `func_002D1B08` | Matching | 100.00% | 36 |
| `func_002D1B30` | Matching | 100.00% | 40 |
| `func_002D1B58` | Matching | 100.00% | 68 |
| `func_002D1BA0` | Matching | 100.00% | 52 |
| `func_002D1BD8` | Matching | 100.00% | 8 |
| `func_002D1BE0` | Matching | 100.00% | 16 |
| `func_002D1BF0` | Matching | 100.00% | 44 |
| `func_002D1C20` | Matching | 100.00% | 32 |
| `func_002D1C40` | Matching | 100.00% | 20 |
| `func_002D1C58` | Matching | 100.00% | 20 |
| `func_002D1C70` | Matching | 100.00% | 12 |
| `func_002D1C80` | Matching | 100.00% | 20 |
| `func_002D1C98` | Matching | 100.00% | 20 |
| `func_002D1CB0` | Matching | 100.00% | 16 |
| `func_002D1CC0(void*)` | Matching | 100.00% | 28 |
| `func_002CF1C8` | Matching | 99.99% | 1472 |
| `func_002D0908` | Matching | 99.96% | 1088 |
| `func_002CDFD8` | Matching | 99.93% | 296 |
| `func_002CE820` | Matching | 99.92% | 236 |
| `func_002CD5A0` | Matching | 99.89% | 536 |
| `func_002CD9D8` | Matching | 99.89% | 536 |
| `func_002D0450` | Matching | 99.88% | 172 |
| `func_002CCB18` | Matching | 99.86% | 284 |
| `func_002CFF88` | Matching | 99.84% | 128 |
| `func_002CED78` | Matching | 99.84% | 368 |
| `cAngleMenuItem_render` | Matching | 99.83% | 120 |
| `func_002CC350` | Matching | 99.81% | 104 |
| `func_002CE1F0` | Matching | 99.78% | 372 |
| `func_002CC648` | Matching | 99.78% | 268 |
| `func_002CD240` | Matching | 99.64% | 56 |
| `func_002CD7B8` | Matching | 99.64% | 56 |
| `func_002CDBF0` | Matching | 99.64% | 56 |
| `func_002CDFA0` | Matching | 99.64% | 56 |
| `func_002CE368` | Matching | 99.64% | 56 |
| `func_002CCD90` | Matching | 99.62% | 52 |
| `func_002CCEA8` | Matching | 99.62% | 52 |
| `func_002CD2F0` | Matching | 99.62% | 52 |
| `func_002CD090` | Matching | 99.52% | 84 |

### `util/objectinterface`

24 matching, 0 partial, 1 not started (25 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cObjectInterface_getInstanceMan()` | Matching | 100.00% | 16 |
| `func_002D1CF0(void*)` | Matching | 100.00% | 28 |
| `func_002D2058` | Matching | 100.00% | 156 |
| `func_002D20F8` | Matching | 100.00% | 8 |
| `func_002D2100` | Matching | 100.00% | 52 |
| `func_002D2138` | Matching | 100.00% | 8 |
| `func_002D2140` | Matching | 100.00% | 8 |
| `func_002D2148` | Matching | 100.00% | 24 |
| `func_002D2160` | Matching | 100.00% | 24 |
| `func_002D2178` | Matching | 100.00% | 24 |
| `func_002D2190` | Matching | 100.00% | 12 |
| `func_002D21A0` | Matching | 100.00% | 12 |
| `func_002D21B0(void*)` | Matching | 100.00% | 8 |
| `func_002D21B8(void*)` | Matching | 100.00% | 8 |
| `func_002D21C0` | Matching | 100.00% | 12 |
| `func_002D21D0` | Matching | 100.00% | 60 |
| `func_002D2210` | Matching | 100.00% | 52 |
| `func_002D2248` | Matching | 100.00% | 92 |
| `func_002D22A8` | Matching | 100.00% | 92 |
| `func_002D2308` | Matching | 100.00% | 92 |
| `func_002D2368` | Matching | 100.00% | 92 |
| `func_002D23C8` | Matching | 100.00% | 28 |
| `func_002D23E8` | Matching | 100.00% | 144 |
| `func_002D2478` | Matching | 100.00% | 148 |

### `util/statemachine`

10 matching, 0 partial, 2 not started (12 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cConsoleConfig_setTimeString` | Matching | 100.00% | 192 |
| `func_002C7038` | Matching | 100.00% | 196 |
| `func_002C7100` | Matching | 100.00% | 96 |
| `func_002C7160` | Matching | 100.00% | 96 |
| `func_002C71C0` | Matching | 100.00% | 72 |
| `func_002C7208` | Matching | 100.00% | 84 |
| `func_002C7260` | Matching | 100.00% | 196 |
| `func_002C7328` | Matching | 100.00% | 148 |
| `func_002C73C0` | Matching | 100.00% | 124 |
| `func_002C7440` | Matching | 100.00% | 52 |

### `visualfx/angerfx`

10 matching, 0 partial, 1 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_002D4BE0` | Matching | 100.00% | 36 |
| `func_002D4C08` | Matching | 100.00% | 1084 |
| `func_002D5598` | Matching | 100.00% | 40 |
| `func_002D55C0` | Matching | 100.00% | 148 |
| `func_002D5658` | Matching | 100.00% | 84 |
| `func_002D56B0` | Matching | 100.00% | 100 |
| `func_002D5718` | Matching | 100.00% | 56 |
| `func_002D5750` | Matching | 100.00% | 36 |
| `cAngerFX_cAngerFX` | Matching | 99.48% | 384 |
| `func_002D4A70` | Matching | 99.46% | 368 |

### `visualfx/avalanche`

27 matching, 0 partial, 8 not started (35 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_002D6290` | Matching | 100.00% | 232 |
| `func_002D6378` | Matching | 100.00% | 152 |
| `func_002D6410` | Matching | 100.00% | 200 |
| `func_002D64D8` | Matching | 100.00% | 452 |
| `tActiveAvalancheNode_calculateScale` | Matching | 100.00% | 164 |
| `func_002D7DD8` | Matching | 100.00% | 132 |
| `tActiveAvalanche_buildArray` | Matching | 100.00% | 148 |
| `func_002D81B0` | Matching | 100.00% | 164 |
| `func_002D8258` | Matching | 100.00% | 68 |
| `func_002D82A0` | Matching | 100.00% | 280 |
| `func_002D83B8` | Matching | 100.00% | 1048 |
| `func_002D87D0` | Matching | 100.00% | 376 |
| `func_002D9130` | Matching | 100.00% | 412 |
| `func_002D9538` | Matching | 100.00% | 292 |
| `func_002D96B0` | Matching | 100.00% | 48 |
| `func_002D96E0` | Matching | 100.00% | 84 |
| `func_002D9738` | Matching | 100.00% | 112 |
| `cAvalanche_triggerAvalanche` | Matching | 100.00% | 724 |
| `func_002D9A80` | Matching | 100.00% | 192 |
| `func_002D9B40` | Matching | 100.00% | 192 |
| `func_002D9C00` | Matching | 100.00% | 172 |
| `func_002D9FB8` | Matching | 100.00% | 112 |
| `cAvalanche_resolveDataPointers` | Matching | 100.00% | 404 |
| `func_002DA1C0` | Matching | 99.91% | 460 |
| `func_002D8EA8` | Matching | 99.91% | 648 |
| `func_002D8948` | Matching | 99.89% | 180 |
| `func_002D9660` | Matching | 99.75% | 80 |

### `visualfx/boardsparkfx`

4 matching, 0 partial, 1 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBoardSparkFX_cBoardSparkFX` | Matching | 100.00% | 1368 |
| `func_002DAA78` | Matching | 100.00% | 332 |
| `func_002DB478` | Matching | 100.00% | 604 |
| `func_002DA8E8` | Matching | 99.49% | 396 |

### `visualfx/boardtrailfx`

24 matching, 0 partial, 6 not started (30 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBoardTrailFX_initialize` | Matching | 100.00% | 516 |
| `func_002E8560` | Matching | 100.00% | 400 |
| `func_002E87E8` | Matching | 100.00% | 332 |
| `func_002EA480` | Matching | 100.00% | 180 |
| `func_002EA538` | Matching | 100.00% | 308 |
| `func_002EA670` | Matching | 100.00% | 68 |
| `func_002EA6B8` | Matching | 100.00% | 196 |
| `func_002EA780` | Matching | 100.00% | 156 |
| `func_002EA820` | Matching | 100.00% | 60 |
| `func_002EA860` | Matching | 100.00% | 88 |
| `func_002EA8B8` | Matching | 100.00% | 68 |
| `func_002EA900` | Matching | 100.00% | 292 |
| `func_002EADC0(void*)` | Matching | 100.00% | 12 |
| `func_002EADD0` | Matching | 100.00% | 968 |
| `func_002EB8F0` | Matching | 100.00% | 72 |
| `func_002EBBA8` | Matching | 100.00% | 148 |
| `func_002EBD88` | Matching | 100.00% | 148 |
| `func_002EAA28` | Matching | 99.89% | 184 |
| `func_002EBB10` | Matching | 99.87% | 152 |
| `func_002EBE20` | Matching | 99.86% | 292 |
| `func_002EBF48` | Matching | 99.86% | 276 |
| `func_002EBC40` | Matching | 99.70% | 328 |
| `func_002E83F0` | Matching | 99.46% | 368 |
| `func_002EAC60` | Matching | 99.43% | 348 |

### `visualfx/boardwakefx`

69 matching, 0 partial, 15 not started (84 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cBoardWakeFX_cBoardWakeFX` | Matching | 100.00% | 536 |
| `func_002DCF28` | Matching | 100.00% | 400 |
| `func_002DE368` | Matching | 100.00% | 44 |
| `func_002DE398` | Matching | 100.00% | 272 |
| `func_002DF3B0` | Matching | 100.00% | 152 |
| `func_002DF448` | Matching | 100.00% | 136 |
| `func_002DF4D0` | Matching | 100.00% | 1100 |
| `func_002E23E0` | Matching | 100.00% | 236 |
| `func_002E24D0` | Matching | 100.00% | 124 |
| `func_002E2550` | Matching | 100.00% | 360 |
| `func_002E26B8` | Matching | 100.00% | 304 |
| `func_002E27E8` | Matching | 100.00% | 116 |
| `func_002E2860(void*)` | Matching | 100.00% | 8 |
| `func_002E2868` | Matching | 100.00% | 664 |
| `func_002E2E18` | Matching | 100.00% | 380 |
| `func_002E2F98(void*, int)` | Matching | 100.00% | 16 |
| `func_002E2FA8` | Matching | 100.00% | 80 |
| `func_002E2FF8` | Matching | 100.00% | 104 |
| `func_002E3060` | Matching | 100.00% | 108 |
| `func_002E30D0` | Matching | 100.00% | 60 |
| `func_002E3110(void*)` | Matching | 100.00% | 28 |
| `func_002E3578` | Matching | 100.00% | 240 |
| `func_002E3668` | Matching | 100.00% | 20 |
| `func_002E3680` | Matching | 100.00% | 336 |
| `func_002E4228` | Matching | 100.00% | 164 |
| `func_002E42D0` | Matching | 100.00% | 156 |
| `func_002E4370` | Matching | 100.00% | 344 |
| `func_002E44C8` | Matching | 100.00% | 40 |
| `func_002E44F0` | Matching | 100.00% | 76 |
| `func_002E4540` | Matching | 100.00% | 56 |
| `func_002E4578` | Matching | 100.00% | 188 |
| `func_002E4638` | Matching | 100.00% | 60 |
| `func_002E4678` | Matching | 100.00% | 80 |
| `func_002E46C8` | Matching | 100.00% | 284 |
| `func_002E4B98` | Matching | 100.00% | 196 |
| `func_002E4C60` | Matching | 100.00% | 48 |
| `func_002E4C90` | Matching | 100.00% | 28 |
| `func_002E4CB0` | Matching | 100.00% | 52 |
| `func_002E4CE8` | Matching | 100.00% | 72 |
| `func_002E4D30` | Matching | 100.00% | 64 |
| `func_002E4D70(void*)` | Matching | 100.00% | 20 |
| `func_002E4D88` | Matching | 100.00% | 392 |
| `func_002E4F10(void*)` | Matching | 100.00% | 20 |
| `func_002E4F28` | Matching | 100.00% | 36 |
| `func_002E5430` | Matching | 100.00% | 420 |
| `func_002E55D8` | Matching | 100.00% | 836 |
| `func_002E5D18` | Matching | 100.00% | 136 |
| `func_002E62C8` | Matching | 100.00% | 84 |
| `func_002E6320` | Matching | 100.00% | 416 |
| `func_002E6640` | Matching | 100.00% | 116 |
| `func_002E47E8` | Matching | 99.98% | 940 |
| `func_002DE058` | Matching | 99.97% | 784 |
| `func_002E6008` | Matching | 99.97% | 700 |
| `func_002DDAB8` | Matching | 99.97% | 632 |
| `func_002E5DA0` | Matching | 99.97% | 616 |
| `func_002DF920` | Matching | 99.96% | 1380 |
| `func_002DDD30` | Matching | 99.95% | 808 |
| `func_002E5920` | Matching | 99.94% | 1012 |
| `func_002E3930` | Matching | 99.88% | 164 |
| `func_002E0EE8` | Matching | 99.87% | 464 |
| `func_002E2260` | Matching | 99.84% | 380 |
| `func_002E1598` | Matching | 99.82% | 1256 |
| `func_002E39D8` | Matching | 99.79% | 284 |
| `func_002E1F70` | Matching | 99.79% | 752 |
| `func_002E10B8` | Matching | 99.62% | 104 |
| `func_002DF1C8` | Matching | 99.59% | 488 |
| `func_002DCDA0` | Matching | 99.48% | 388 |
| `func_002E64C0` | Matching | 99.47% | 380 |
| `func_002E37D0` | Matching | 99.43% | 348 |

### `visualfx/crowdrender2d`

8 matching, 0 partial, 0 not started (8 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cCrowdRender2D_cCrowdRender2D(int)` | Matching | 100.00% | 40 |
| `cCrowdRender2D__cCrowdRender2D(int *, int)` | Matching | 100.00% | 68 |
| `cCrowdRender2D_constructCrowdAnim2D(void*)` | Matching | 100.00% | 68 |
| `cCrowdAnim2D_cCrowdAnim2D(void *, void *)` | Matching | 100.00% | 64 |
| `cCrowdAnim2D_advanceFrame` | Matching | 100.00% | 184 |
| `cCrowdAnim2D_update` | Matching | 100.00% | 588 |
| `cCrowdRender2D_purge(int*)` | Matching | 99.83% | 236 |
| `cCrowdRender2D_init()` | Matching | 99.76% | 328 |

### `visualfx/lensfx`

46 matching, 0 partial, 4 not started (50 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cLensFxMan_construct()` | Matching | 100.00% | 52 |
| `func_002EC418` | Matching | 100.00% | 52 |
| `func_002EC450(void*)` | Matching | 100.00% | 40 |
| `func_002EC9D0(void*)` | Matching | 100.00% | 16 |
| `func_002EC9E0` | Matching | 100.00% | 132 |
| `func_002ECA68` | Matching | 100.00% | 132 |
| `func_002ECAF0` | Matching | 100.00% | 52 |
| `func_002ECB28` | Matching | 100.00% | 152 |
| `func_002ECBC0` | Matching | 100.00% | 100 |
| `func_002ECC28` | Matching | 100.00% | 140 |
| `func_002ECCB8` | Matching | 100.00% | 704 |
| `func_002ECF78` | Matching | 100.00% | 36 |
| `func_002ECFA0` | Matching | 100.00% | 168 |
| `func_002ED1D0` | Matching | 100.00% | 360 |
| `func_002ED338` | Matching | 100.00% | 344 |
| `func_002EDFB8` | Matching | 100.00% | 24 |
| `func_002EDFD0` | Matching | 100.00% | 64 |
| `func_002EE010` | Matching | 100.00% | 96 |
| `func_002EE070` | Matching | 100.00% | 72 |
| `func_002EE0B8` | Matching | 100.00% | 72 |
| `func_002EE100` | Matching | 100.00% | 72 |
| `func_002EE148` | Matching | 100.00% | 72 |
| `func_002EE190` | Matching | 100.00% | 72 |
| `func_002EE1D8` | Matching | 100.00% | 72 |
| `func_002EE220` | Matching | 100.00% | 72 |
| `func_002EE268` | Matching | 100.00% | 72 |
| `func_002EE2B0` | Matching | 100.00% | 72 |
| `func_002EE2F8` | Matching | 100.00% | 32 |
| `func_002EE318` | Matching | 100.00% | 36 |
| `func_002EE340` | Matching | 100.00% | 36 |
| `func_002EE368` | Matching | 100.00% | 36 |
| `func_002EE390` | Matching | 100.00% | 36 |
| `func_002EE3B8` | Matching | 100.00% | 72 |
| `func_002EE400` | Matching | 100.00% | 72 |
| `func_002EE448` | Matching | 100.00% | 120 |
| `func_002EE4C0` | Matching | 100.00% | 72 |
| `func_002EE508` | Matching | 100.00% | 100 |
| `func_002EE570` | Matching | 100.00% | 72 |
| `func_002EE5B8` | Matching | 100.00% | 72 |
| `func_002EE600` | Matching | 100.00% | 92 |
| `func_002EE660` | Matching | 100.00% | 72 |
| `func_002EE6A8` | Matching | 100.00% | 72 |
| `func_002EE6F0` | Matching | 100.00% | 72 |
| `func_002EE738` | Matching | 100.00% | 72 |
| `func_002EE780` | Matching | 100.00% | 72 |
| `func_002EDF00` | Matching | 99.24% | 184 |

### `visualfx/renderstateman`

55 matching, 0 partial, 0 not started (55 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cRenderStateMan_SnowFlakeColourR` | Matching | 100.00% | 72 |
| `cRenderStateMan_SnowFlakeColourG` | Matching | 100.00% | 72 |
| `cRenderStateMan_SnowFlakeColourB` | Matching | 100.00% | 72 |
| `func_002EE8A0` | Matching | 100.00% | 72 |
| `func_002EE8E8` | Matching | 100.00% | 72 |
| `func_002EE930` | Matching | 100.00% | 72 |
| `func_002EE978` | Matching | 100.00% | 72 |
| `func_002EE9C0` | Matching | 100.00% | 72 |
| `func_002EEA08` | Matching | 100.00% | 72 |
| `func_002EEA50` | Matching | 100.00% | 72 |
| `func_002EEA98` | Matching | 100.00% | 72 |
| `func_002EEAE0` | Matching | 100.00% | 72 |
| `func_002EEB28` | Matching | 100.00% | 72 |
| `func_002EEB70` | Matching | 100.00% | 96 |
| `func_002EEBD0` | Matching | 100.00% | 96 |
| `func_002EEC30` | Matching | 100.00% | 96 |
| `func_002EEC90` | Matching | 100.00% | 92 |
| `func_002EECF0` | Matching | 100.00% | 92 |
| `func_002EED50` | Matching | 100.00% | 92 |
| `func_002EEDB0` | Matching | 100.00% | 72 |
| `func_002EEDF8` | Matching | 100.00% | 72 |
| `func_002EEE40` | Matching | 100.00% | 72 |
| `func_002EEE88` | Matching | 100.00% | 72 |
| `func_002EEED0` | Matching | 100.00% | 72 |
| `func_002EEF18` | Matching | 100.00% | 72 |
| `func_002EEF60` | Matching | 100.00% | 72 |
| `func_002EEFA8` | Matching | 100.00% | 72 |
| `func_002EEFF0` | Matching | 100.00% | 72 |
| `func_002EF038` | Matching | 100.00% | 100 |
| `func_002EF0A0` | Matching | 100.00% | 72 |
| `func_002EF0E8` | Matching | 100.00% | 88 |
| `func_002EF140` | Matching | 100.00% | 88 |
| `func_002EF198` | Matching | 100.00% | 88 |
| `func_002EF1F0` | Matching | 100.00% | 88 |
| `func_002EF248` | Matching | 100.00% | 140 |
| `cRenderStateMan_readFromReplayFrame` | Matching | 100.00% | 140 |
| `func_002EF368` | Matching | 100.00% | 16 |
| `func_002EF378` | Matching | 100.00% | 56 |
| `func_002EF6A0` | Matching | 100.00% | 44 |
| `func_002EF6D0` | Matching | 100.00% | 636 |
| `func_002EF950` | Matching | 100.00% | 1596 |
| `func_002EFF90` | Matching | 100.00% | 8 |
| `func_002EFF98` | Matching | 100.00% | 264 |
| `func_002F00A0` | Matching | 100.00% | 704 |
| `func_002F0360` | Matching | 100.00% | 8 |
| `func_002F0368` | Matching | 100.00% | 28 |
| `func_002F0388` | Matching | 100.00% | 8 |
| `func_002F0390` | Matching | 100.00% | 52 |
| `func_002F03C8` | Matching | 100.00% | 112 |
| `func_002F0438` | Matching | 100.00% | 116 |
| `func_002F04B0` | Matching | 100.00% | 44 |
| `func_002F04E0` | Matching | 100.00% | 44 |
| `func_002F0510` | Matching | 100.00% | 52 |
| `func_002EF3B0` | Matching | 99.48% | 384 |
| `func_002EF530` | Matching | 99.46% | 368 |

### `visualfx/worldlightman`

133 matching, 0 partial, 4 not started (137 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldLightMan_initLightCache` | Matching | 100.00% | 276 |
| `func_002F53B0` | Matching | 100.00% | 76 |
| `func_002F5998` | Matching | 100.00% | 52 |
| `func_002F59D0` | Matching | 100.00% | 156 |
| `func_002F5AF0` | Matching | 100.00% | 116 |
| `func_002F5B68` | Matching | 100.00% | 452 |
| `func_002F6168` | Matching | 100.00% | 208 |
| `func_002F6238` | Matching | 100.00% | 336 |
| `func_002F64E8(void*)` | Matching | 100.00% | 8 |
| `func_002F64F0(void*)` | Matching | 100.00% | 36 |
| `func_002F6908(void*)` | Matching | 100.00% | 8 |
| `func_002F6910` | Matching | 100.00% | 328 |
| `func_002F6A58` | Matching | 100.00% | 52 |
| `func_002F6A90` | Matching | 100.00% | 52 |
| `func_002F6AC8` | Matching | 100.00% | 92 |
| `func_002F6B28` | Matching | 100.00% | 16 |
| `func_002F6B38` | Matching | 100.00% | 12 |
| `func_002F6B48` | Matching | 100.00% | 60 |
| `func_002F7A50` | Matching | 100.00% | 12 |
| `func_002F7A60` | Matching | 100.00% | 8 |
| `func_002F7A68(void*)` | Matching | 100.00% | 8 |
| `func_002F7A70` | Matching | 100.00% | 12 |
| `func_002F7A80` | Matching | 100.00% | 48 |
| `func_002F7AB0` | Matching | 100.00% | 8 |
| `func_002F7AB8` | Matching | 100.00% | 28 |
| `func_002F7AD8` | Matching | 100.00% | 8 |
| `func_002F7AE0` | Matching | 100.00% | 28 |
| `func_002F7B00` | Matching | 100.00% | 8 |
| `func_002F7B08` | Matching | 100.00% | 28 |
| `func_002F7B28` | Matching | 100.00% | 8 |
| `func_002F7B30` | Matching | 100.00% | 28 |
| `func_002F7B50` | Matching | 100.00% | 8 |
| `func_002F7B58` | Matching | 100.00% | 28 |
| `func_002F7B78` | Matching | 100.00% | 8 |
| `func_002F7B80` | Matching | 100.00% | 28 |
| `func_002F7BA0` | Matching | 100.00% | 8 |
| `func_002F7BA8` | Matching | 100.00% | 28 |
| `func_002F7BC8` | Matching | 100.00% | 8 |
| `func_002F7BD0` | Matching | 100.00% | 8 |
| `func_002F7BD8` | Matching | 100.00% | 8 |
| `func_002F7BE0` | Matching | 100.00% | 12 |
| `func_002F7BF0` | Matching | 100.00% | 48 |
| `func_002F7C20(void*)` | Matching | 100.00% | 8 |
| `func_002F7C28(void*)` | Matching | 100.00% | 8 |
| `func_002F7C30(void*)` | Matching | 100.00% | 8 |
| `func_002F7C38` | Matching | 100.00% | 52 |
| `func_002F7C70` | Matching | 100.00% | 12 |
| `func_002F7C80` | Matching | 100.00% | 12 |
| `func_002F7C90` | Matching | 100.00% | 12 |
| `func_002F7CA0` | Matching | 100.00% | 12 |
| `func_002F7CB0` | Matching | 100.00% | 12 |
| `func_002F7CC0` | Matching | 100.00% | 12 |
| `func_002F7CD0` | Matching | 100.00% | 12 |
| `func_002F7CE0` | Matching | 100.00% | 12 |
| `func_002F7CF0` | Matching | 100.00% | 12 |
| `func_002F7D00` | Matching | 100.00% | 12 |
| `func_002F7D10` | Matching | 100.00% | 12 |
| `func_002F7D20` | Matching | 100.00% | 12 |
| `func_002F7D30` | Matching | 100.00% | 12 |
| `func_002F7D40` | Matching | 100.00% | 12 |
| `func_002F7D50` | Matching | 100.00% | 12 |
| `func_002F7D60` | Matching | 100.00% | 12 |
| `func_002F7D70` | Matching | 100.00% | 12 |
| `func_002F7D80` | Matching | 100.00% | 12 |
| `func_002F7D90` | Matching | 100.00% | 12 |
| `func_002F7DA0` | Matching | 100.00% | 12 |
| `func_002F7DB0` | Matching | 100.00% | 12 |
| `func_002F7DC0` | Matching | 100.00% | 12 |
| `func_002F7DD0` | Matching | 100.00% | 12 |
| `func_002F7DE0` | Matching | 100.00% | 12 |
| `func_002F7DF0` | Matching | 100.00% | 12 |
| `func_002F7E00` | Matching | 100.00% | 12 |
| `func_002F7E10` | Matching | 100.00% | 12 |
| `func_002F7E20` | Matching | 100.00% | 12 |
| `func_002F7E30` | Matching | 100.00% | 12 |
| `func_002F7E40` | Matching | 100.00% | 12 |
| `func_002F7E50` | Matching | 100.00% | 12 |
| `func_002F7E60` | Matching | 100.00% | 12 |
| `func_002F7E70` | Matching | 100.00% | 28 |
| `func_002F7E90` | Matching | 100.00% | 8 |
| `func_002F7E98` | Matching | 100.00% | 8 |
| `func_002F7EA0` | Matching | 100.00% | 8 |
| `func_002F7EA8` | Matching | 100.00% | 28 |
| `func_002F7EC8` | Matching | 100.00% | 8 |
| `func_002F7ED0` | Matching | 100.00% | 28 |
| `func_002F7EF0` | Matching | 100.00% | 8 |
| `func_002F7EF8` | Matching | 100.00% | 8 |
| `func_002F7F00` | Matching | 100.00% | 48 |
| `func_002F7F30` | Matching | 100.00% | 48 |
| `func_002F7F60` | Matching | 100.00% | 48 |
| `func_002F7F90` | Matching | 100.00% | 48 |
| `func_002F7FC0` | Matching | 100.00% | 8 |
| `func_002F7FC8` | Matching | 100.00% | 8 |
| `func_002F7FD0` | Matching | 100.00% | 8 |
| `func_002F7FD8` | Matching | 100.00% | 8 |
| `func_002F7FE0` | Matching | 100.00% | 8 |
| `func_002F7FE8` | Matching | 100.00% | 8 |
| `func_002F7FF0(void*)` | Matching | 100.00% | 8 |
| `func_002F7FF8` | Matching | 100.00% | 8 |
| `func_002F8000` | Matching | 100.00% | 48 |
| `func_002F8030` | Matching | 100.00% | 48 |
| `func_002F8060` | Matching | 100.00% | 120 |
| `func_002F80D8` | Matching | 100.00% | 48 |
| `func_002F8108` | Matching | 100.00% | 48 |
| `func_002F8138` | Matching | 100.00% | 48 |
| `func_002F8168(void*)` | Matching | 100.00% | 8 |
| `func_002F8170` | Matching | 100.00% | 24 |
| `func_002F8188` | Matching | 100.00% | 48 |
| `func_002F81B8(void*)` | Matching | 100.00% | 28 |
| `func_002F81D8` | Matching | 100.00% | 8 |
| `func_002F81E0` | Matching | 100.00% | 12 |
| `func_002F81F0` | Matching | 100.00% | 48 |
| `func_002F8220` | Matching | 100.00% | 48 |
| `func_002F8250` | Matching | 100.00% | 48 |
| `func_002F8280` | Matching | 100.00% | 48 |
| `func_002F82B0` | Matching | 100.00% | 48 |
| `func_002F82E0` | Matching | 100.00% | 48 |
| `func_002F8310` | Matching | 100.00% | 48 |
| `func_002F8340` | Matching | 100.00% | 48 |
| `func_002F8FF8(void*)` | Matching | 100.00% | 8 |
| `func_002F9000` | Matching | 100.00% | 60 |
| `func_002F9818(void*)` | Matching | 100.00% | 32 |
| `func_002FA5F8(void*)` | Matching | 100.00% | 8 |
| `func_002FA600` | Matching | 100.00% | 60 |
| `func_002FAE18(void*)` | Matching | 100.00% | 32 |
| `func_002F6518` | Matching | 99.96% | 1004 |
| `func_002F83B0` | Matching | 99.83% | 3144 |
| `func_002F9838` | Matching | 99.54% | 3516 |
| `func_002F6388` | Matching | 99.43% | 348 |
| `func_002F8370(void*)` | Matching | 99.38% | 32 |
| `func_002F8390(void*)` | Matching | 99.38% | 32 |
| `func_002F9040` | Matching | 99.29% | 2008 |
| `func_002FA640` | Matching | 99.29% | 2008 |

### `world/streamman`

11 matching, 0 partial, 0 not started (11 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cStreamMan_cStreamMan` | Matching | 100.00% | 208 |
| `func_003A6E20` | Matching | 100.00% | 120 |
| `func_003A6E98` | Matching | 100.00% | 60 |
| `func_003A6ED8` | Matching | 100.00% | 96 |
| `func_003A6F38` | Matching | 100.00% | 80 |
| `func_003A6F88` | Matching | 100.00% | 136 |
| `func_003A7010` | Matching | 100.00% | 68 |
| `func_003A7058` | Matching | 100.00% | 64 |
| `func_003A7098` | Matching | 100.00% | 380 |
| `func_003A7218(void*, int, int, int)` | Matching | 100.00% | 28 |
| `func_003A7238` | Matching | 100.00% | 860 |

### `world/world`

19 matching, 0 partial, 0 not started (19 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorld_cWorld` | Matching | 100.00% | 180 |
| `func_003A6740` | Matching | 100.00% | 156 |
| `func_003A67E0` | Matching | 100.00% | 28 |
| `cWorld_resetMap` | Matching | 100.00% | 296 |
| `func_003A6928(void*)` | Matching | 100.00% | 28 |
| `func_003A6948` | Matching | 100.00% | 404 |
| `func_003A6AE0` | Matching | 100.00% | 148 |
| `func_003A6B78` | Matching | 100.00% | 48 |
| `func_003A6BA8` | Matching | 100.00% | 44 |
| `func_003A6BD8` | Matching | 100.00% | 44 |
| `func_003A6C08` | Matching | 100.00% | 44 |
| `func_003A6C38` | Matching | 100.00% | 44 |
| `func_003A6C68` | Matching | 100.00% | 44 |
| `func_003A6C98` | Matching | 100.00% | 44 |
| `func_003A6CC8(void *, void *)` | Matching | 100.00% | 16 |
| `func_003A6CD8(void *, void *)` | Matching | 100.00% | 16 |
| `func_003A6CE8` | Matching | 100.00% | 20 |
| `func_003A6D00(void*, int)` | Matching | 100.00% | 20 |
| `func_003A6D18` | Matching | 100.00% | 56 |

### `world/worldcache`

49 matching, 0 partial, 3 not started (52 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldBlockAllocator_init` | Matching | 100.00% | 296 |
| `func_003A76C0` | Matching | 100.00% | 164 |
| `func_003A7768(void*)` | Matching | 100.00% | 40 |
| `func_003A7790(void *, void *)` | Matching | 100.00% | 32 |
| `func_003A77B0(void*, int, int)` | Matching | 100.00% | 28 |
| `func_003A77D0` | Matching | 100.00% | 68 |
| `func_003A7818` | Matching | 100.00% | 92 |
| `func_003A7878` | Matching | 100.00% | 424 |
| `func_003A7A20` | Matching | 100.00% | 132 |
| `func_003A7AA8` | Matching | 100.00% | 112 |
| `cWorldMemoryMan_activateSectionMem` | Matching | 100.00% | 128 |
| `func_003A7B98` | Matching | 100.00% | 64 |
| `cHullPage_cHullPage` | Matching | 100.00% | 84 |
| `func_003A7C30` | Matching | 100.00% | 84 |
| `cWorldCacheTable_cWorldCacheTable` | Matching | 100.00% | 248 |
| `func_003A7D80` | Matching | 100.00% | 80 |
| `func_003A7DD0` | Matching | 100.00% | 104 |
| `func_003A7E38` | Matching | 100.00% | 92 |
| `func_003A7E98` | Matching | 100.00% | 244 |
| `func_003A7F90` | Matching | 100.00% | 48 |
| `cWorldCache_init` | Matching | 100.00% | 488 |
| `cWorldCache_activateSectionMem` | Matching | 100.00% | 132 |
| `func_003A8230` | Matching | 100.00% | 92 |
| `func_003A8290` | Matching | 100.00% | 56 |
| `func_003A82C8` | Matching | 100.00% | 100 |
| `func_003A8330` | Matching | 100.00% | 276 |
| `func_003A8448` | Matching | 100.00% | 124 |
| `func_003A84C8` | Matching | 100.00% | 44 |
| `func_003A84F8` | Matching | 100.00% | 20 |
| `func_003A8510` | Matching | 100.00% | 20 |
| `func_003A8528` | Matching | 100.00% | 240 |
| `func_003A8618` | Matching | 100.00% | 28 |
| `func_003A8638` | Matching | 100.00% | 24 |
| `func_003A8650` | Matching | 100.00% | 24 |
| `cWorldCache_updatePages` | Matching | 100.00% | 576 |
| `func_003A89C8` | Matching | 100.00% | 196 |
| `cWorldCache_addBxStreamDataTest` | Matching | 100.00% | 576 |
| `func_003A8CD0` | Matching | 100.00% | 332 |
| `func_003A8F10` | Matching | 100.00% | 112 |
| `func_003A8F80` | Matching | 100.00% | 52 |
| `func_003A8FB8` | Matching | 100.00% | 68 |
| `func_003A9000` | Matching | 100.00% | 384 |
| `func_003A9180(void*)` | Matching | 100.00% | 8 |
| `func_003A9188` | Matching | 100.00% | 204 |
| `func_003A9258` | Matching | 100.00% | 768 |
| `func_003A9558` | Matching | 100.00% | 104 |
| `func_003A95C0` | Matching | 100.00% | 152 |
| `func_003A96E0` | Matching | 100.00% | 144 |
| `func_003A9770` | Matching | 100.00% | 144 |

### `world/worldview`

47 matching, 0 partial, 5 not started (52 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldView_getNumSections(cWorldView*)` | Matching | 100.00% | 28 |
| `func_003A9820` | Matching | 100.00% | 52 |
| `cWorldView_isSectionLoaded(cWorldView*, int)` | Matching | 100.00% | 56 |
| `func_003A9890` | Matching | 100.00% | 52 |
| `func_003A98C8` | Matching | 100.00% | 144 |
| `func_003A9958` | Matching | 100.00% | 124 |
| `func_003A99D8` | Matching | 100.00% | 112 |
| `func_003A9A48` | Matching | 100.00% | 72 |
| `func_003A9A90` | Matching | 100.00% | 8 |
| `func_003A9A98` | Matching | 100.00% | 20 |
| `func_003A9AB0(void*)` | Matching | 100.00% | 12 |
| `func_003A9BB8` | Matching | 100.00% | 420 |
| `func_003A9D60` | Matching | 100.00% | 236 |
| `func_003AA2D8` | Matching | 100.00% | 20 |
| `func_003AA2F0` | Matching | 100.00% | 252 |
| `func_003AA3F0` | Matching | 100.00% | 72 |
| `func_003AA438` | Matching | 100.00% | 228 |
| `func_003AA520` | Matching | 100.00% | 164 |
| `func_003AA5C8` | Matching | 100.00% | 60 |
| `func_003AA608` | Matching | 100.00% | 224 |
| `func_003AA6E8` | Matching | 100.00% | 20 |
| `func_003AA700` | Matching | 100.00% | 88 |
| `func_003AA758` | Matching | 100.00% | 36 |
| `func_003AA780` | Matching | 100.00% | 172 |
| `func_003AA830` | Matching | 100.00% | 164 |
| `func_003AA8D8` | Matching | 100.00% | 20 |
| `func_003AA8F0` | Matching | 100.00% | 108 |
| `func_003AA960` | Matching | 100.00% | 168 |
| `func_003AAA08` | Matching | 100.00% | 464 |
| `func_003AABD8` | Matching | 100.00% | 116 |
| `func_003AAC50` | Matching | 100.00% | 84 |
| `func_003AACA8` | Matching | 100.00% | 56 |
| `func_003AACE0` | Matching | 100.00% | 180 |
| `func_003AAD98` | Matching | 100.00% | 80 |
| `func_003AADE8` | Matching | 100.00% | 88 |
| `func_003AAE40` | Matching | 100.00% | 32 |
| `func_003AAE60(void*)` | Matching | 100.00% | 8 |
| `func_003AB498` | Matching | 100.00% | 2472 |
| `func_003ABE40` | Matching | 100.00% | 220 |
| `func_003ABF20` | Matching | 100.00% | 44 |
| `func_003ABF50` | Matching | 100.00% | 112 |
| `func_003ABFC0` | Matching | 100.00% | 132 |
| `func_003AC2A8` | Matching | 100.00% | 172 |
| `func_003AC358` | Matching | 100.00% | 220 |
| `func_003AC438` | Matching | 100.00% | 208 |
| `func_003AC7C8` | Matching | 100.00% | 52 |
| `func_003AA028` | Matching | 99.97% | 688 |

### `world/wscriptcache`

145 matching, 0 partial, 9 not started (154 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWScriptCache_init` | Matching | 100.00% | 240 |
| `func_003AC8F0` | Matching | 100.00% | 144 |
| `func_003AC980` | Matching | 100.00% | 96 |
| `func_003AC9E0` | Matching | 100.00% | 44 |
| `func_003ACA10` | Matching | 100.00% | 40 |
| `func_003ACA38` | Matching | 100.00% | 24 |
| `func_003ACA50(void*)` | Matching | 100.00% | 28 |
| `func_003ACA70` | Matching | 100.00% | 92 |
| `func_003ACAD0` | Matching | 100.00% | 232 |
| `func_003ACBB8` | Matching | 100.00% | 148 |
| `func_003ACC50` | Matching | 100.00% | 60 |
| `func_003ACC90` | Matching | 100.00% | 72 |
| `func_003ACCD8` | Matching | 100.00% | 1092 |
| `func_003AD188` | Matching | 100.00% | 12 |
| `func_003AD198` | Matching | 100.00% | 16 |
| `func_003AD1A8` | Matching | 100.00% | 132 |
| `func_003AD230(void*)` | Matching | 100.00% | 28 |
| `func_003AD250` | Matching | 100.00% | 60 |
| `func_003ADC18` | Matching | 100.00% | 48 |
| `func_003ADC48(void*)` | Matching | 100.00% | 8 |
| `func_003ADC50` | Matching | 100.00% | 44 |
| `func_003ADC80` | Matching | 100.00% | 44 |
| `func_003ADCB0` | Matching | 100.00% | 44 |
| `func_003ADCE0` | Matching | 100.00% | 44 |
| `func_003ADD10` | Matching | 100.00% | 44 |
| `func_003ADD40` | Matching | 100.00% | 44 |
| `func_003ADD70` | Matching | 100.00% | 44 |
| `func_003ADDA0(void*)` | Matching | 100.00% | 32 |
| `func_003ADDC0` | Matching | 100.00% | 72 |
| `func_003ADE08` | Matching | 100.00% | 80 |
| `func_003ADE58` | Matching | 100.00% | 52 |
| `func_003ADE90` | Matching | 100.00% | 52 |
| `func_003ADEC8` | Matching | 100.00% | 1068 |
| `func_003AE2F8` | Matching | 100.00% | 8 |
| `func_003AE300` | Matching | 100.00% | 332 |
| `func_003AE450` | Matching | 100.00% | 628 |
| `func_003AE6C8` | Matching | 100.00% | 76 |
| `func_003AE718` | Matching | 100.00% | 100 |
| `func_003AE860` | Matching | 100.00% | 40 |
| `func_003AE888` | Matching | 100.00% | 176 |
| `func_003AE938(void*)` | Matching | 100.00% | 28 |
| `func_003AE958(void*)` | Matching | 100.00% | 28 |
| `func_003AE978` | Matching | 100.00% | 40 |
| `func_003AE9A0` | Matching | 100.00% | 304 |
| `func_003AEAD0` | Matching | 100.00% | 484 |
| `func_003AECB8(void *, void *)` | Matching | 100.00% | 36 |
| `func_003AECE0` | Matching | 100.00% | 64 |
| `func_003AED20(void *, void *, int)` | Matching | 100.00% | 32 |
| `func_003AED40` | Matching | 100.00% | 240 |
| `func_003AEE30` | Matching | 100.00% | 104 |
| `func_003AEE98` | Matching | 100.00% | 96 |
| `func_003AEEF8` | Matching | 100.00% | 80 |
| `func_003AEF48` | Matching | 100.00% | 96 |
| `func_003AEFA8` | Matching | 100.00% | 104 |
| `func_003AF010` | Matching | 100.00% | 16 |
| `func_003AF0C8` | Matching | 100.00% | 356 |
| `func_003AF230` | Matching | 100.00% | 40 |
| `func_003AF2F8` | Matching | 100.00% | 8 |
| `func_003AF300` | Matching | 100.00% | 116 |
| `func_003AF378` | Matching | 100.00% | 172 |
| `func_003AF428` | Matching | 100.00% | 312 |
| `func_003AF560` | Matching | 100.00% | 272 |
| `func_003B0340` | Matching | 100.00% | 104 |
| `func_003B03A8` | Matching | 100.00% | 8 |
| `func_003B03B0` | Matching | 100.00% | 8 |
| `func_003B03B8` | Matching | 100.00% | 8 |
| `func_003B03C0` | Matching | 100.00% | 8 |
| `func_003B03C8` | Matching | 100.00% | 8 |
| `func_003B03D0` | Matching | 100.00% | 8 |
| `func_003B03D8` | Matching | 100.00% | 8 |
| `func_003B03E0` | Matching | 100.00% | 8 |
| `func_003B03E8` | Matching | 100.00% | 8 |
| `func_003B03F0` | Matching | 100.00% | 8 |
| `func_003B03F8` | Matching | 100.00% | 8 |
| `func_003B0400` | Matching | 100.00% | 8 |
| `func_003B0408` | Matching | 100.00% | 8 |
| `func_003B0410(void*)` | Matching | 100.00% | 28 |
| `func_003B0430` | Matching | 100.00% | 108 |
| `func_003B04A0` | Matching | 100.00% | 84 |
| `func_003B04F8` | Matching | 100.00% | 60 |
| `func_003B0538` | Matching | 100.00% | 68 |
| `func_003B0580` | Matching | 100.00% | 60 |
| `func_003B05C0` | Matching | 100.00% | 60 |
| `func_003B0600` | Matching | 100.00% | 128 |
| `func_003B0680` | Matching | 100.00% | 44 |
| `func_003B06B0` | Matching | 100.00% | 68 |
| `func_003B06F8` | Matching | 100.00% | 40 |
| `func_003B0720(void*)` | Matching | 100.00% | 20 |
| `func_003B0738(void*)` | Matching | 100.00% | 28 |
| `func_003B0758` | Matching | 100.00% | 24 |
| `func_003B0770` | Matching | 100.00% | 68 |
| `func_003B07B8(void*)` | Matching | 100.00% | 32 |
| `func_003B07D8(void*)` | Matching | 100.00% | 32 |
| `func_003B07F8` | Matching | 100.00% | 228 |
| `func_003B08E0` | Matching | 100.00% | 100 |
| `func_003B0948` | Matching | 100.00% | 88 |
| `func_003B0B10` | Matching | 100.00% | 48 |
| `func_003B0B40` | Matching | 100.00% | 276 |
| `func_003B0C58` | Matching | 100.00% | 840 |
| `func_003B0FA0(void*)` | Matching | 100.00% | 8 |
| `func_003B0FA8` | Matching | 100.00% | 12 |
| `func_003B0FB8` | Matching | 100.00% | 148 |
| `func_003B1050` | Matching | 100.00% | 128 |
| `func_003B10D0` | Matching | 100.00% | 108 |
| `func_003B1140` | Matching | 100.00% | 92 |
| `func_003B11A0` | Matching | 100.00% | 68 |
| `func_003B11E8(void*)` | Matching | 100.00% | 8 |
| `func_003B11F0` | Matching | 100.00% | 56 |
| `func_003B1228` | Matching | 100.00% | 48 |
| `func_003B1258` | Matching | 100.00% | 24 |
| `func_003B1270(void*)` | Matching | 100.00% | 28 |
| `func_003B1290` | Matching | 100.00% | 108 |
| `func_003B1300` | Matching | 100.00% | 60 |
| `func_003B1340` | Matching | 100.00% | 100 |
| `func_003B13A8` | Matching | 100.00% | 48 |
| `func_003B13D8` | Matching | 100.00% | 188 |
| `func_003B1498` | Matching | 100.00% | 88 |
| `group_of_pictures_header` | Matching | 100.00% | 200 |
| `func_003B17A8` | Matching | 100.00% | 208 |
| `func_003B1878` | Matching | 100.00% | 268 |
| `func_003B1988` | Matching | 100.00% | 292 |
| `func_003B1AB0` | Matching | 100.00% | 524 |
| `func_003B1CC0` | Matching | 100.00% | 148 |
| `func_003B1D58` | Matching | 100.00% | 388 |
| `func_003B1FC8` | Matching | 100.00% | 240 |
| `func_003B20B8` | Matching | 100.00% | 372 |
| `picture_spatial_scalable_extension` | Matching | 100.00% | 196 |
| `func_003B22F8` | Matching | 100.00% | 32 |
| `func_003B2318` | Matching | 100.00% | 68 |
| `func_003B2360(void*)` | Matching | 100.00% | 28 |
| `func_003B2380(void*)` | Matching | 100.00% | 28 |
| `copyright_extension` | Matching | 100.00% | 160 |
| `func_003B2440` | Matching | 100.00% | 232 |
| `func_003B2528` | Matching | 100.00% | 44 |
| `func_003B2558` | Matching | 100.00% | 300 |
| `func_003B2688` | Matching | 100.00% | 44 |
| `func_003B26B8` | Matching | 100.00% | 272 |
| `func_003B27C8` | Matching | 100.00% | 668 |
| `func_003B2A68` | Matching | 100.00% | 256 |
| `func_003B2B68` | Matching | 100.00% | 40 |
| `func_003B2B90` | Matching | 100.00% | 740 |
| `func_003B2E78` | Matching | 100.00% | 1168 |
| `func_003B3308` | Matching | 100.00% | 164 |
| `func_003B33B0` | Matching | 100.00% | 452 |
| `func_003AD290` | Matching | 99.98% | 2436 |

### `worldpainter/quadtree`

145 matching, 0 partial, 6 not started (151 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `func_002C18E8` | Matching | 100.00% | 100 |
| `func_002C1950` | Matching | 100.00% | 172 |
| `func_002C1CD8` | Matching | 100.00% | 208 |
| `cQuadTree_exportTree` | Matching | 100.00% | 736 |
| `func_002C2088` | Matching | 100.00% | 240 |
| `func_002C2178` | Matching | 100.00% | 132 |
| `func_002C2200` | Matching | 100.00% | 8 |
| `func_002C2208` | Matching | 100.00% | 8 |
| `func_002C2210` | Matching | 100.00% | 84 |
| `func_002C2268` | Matching | 100.00% | 92 |
| `func_002C22C8` | Matching | 100.00% | 52 |
| `func_002C2300` | Matching | 100.00% | 52 |
| `func_002C2338` | Matching | 100.00% | 248 |
| `func_002C2430` | Matching | 100.00% | 160 |
| `func_002C24D0` | Matching | 100.00% | 52 |
| `func_002C2508` | Matching | 100.00% | 52 |
| `func_002C2540` | Matching | 100.00% | 60 |
| `func_002C2580` | Matching | 100.00% | 56 |
| `func_002C25B8` | Matching | 100.00% | 60 |
| `func_002C25F8` | Matching | 100.00% | 68 |
| `func_002C2640` | Matching | 100.00% | 68 |
| `func_002C2688` | Matching | 100.00% | 72 |
| `func_002C26D0` | Matching | 100.00% | 68 |
| `func_002C2718` | Matching | 100.00% | 168 |
| `func_002C27C0` | Matching | 100.00% | 168 |
| `func_002C2868` | Matching | 100.00% | 52 |
| `func_002C28A0` | Matching | 100.00% | 28 |
| `func_002C28C0` | Matching | 100.00% | 52 |
| `func_002C28F8` | Matching | 100.00% | 32 |
| `func_002C2918` | Matching | 100.00% | 40 |
| `func_002C2940` | Matching | 100.00% | 144 |
| `func_002C29D0` | Matching | 100.00% | 212 |
| `func_002C2AA8` | Matching | 100.00% | 92 |
| `func_002C2B08` | Matching | 100.00% | 28 |
| `func_002C2B28` | Matching | 100.00% | 64 |
| `func_002C2B68` | Matching | 100.00% | 44 |
| `func_002C2B98` | Matching | 100.00% | 28 |
| `func_002C2BB8` | Matching | 100.00% | 28 |
| `func_002C2BD8` | Matching | 100.00% | 340 |
| `func_002C2D30` | Matching | 100.00% | 52 |
| `func_002C2D68` | Matching | 100.00% | 32 |
| `func_002C2D88` | Matching | 100.00% | 40 |
| `func_002C2DB0` | Matching | 100.00% | 144 |
| `func_002C2E40` | Matching | 100.00% | 52 |
| `func_002C2E78` | Matching | 100.00% | 160 |
| `func_002C3FA0(void*)` | Matching | 100.00% | 8 |
| `func_002C3FA8` | Matching | 100.00% | 52 |
| `func_002C3FE0` | Matching | 100.00% | 108 |
| `func_002C4198` | Matching | 100.00% | 64 |
| `func_002C41D8` | Matching | 100.00% | 52 |
| `func_002C4210` | Matching | 100.00% | 128 |
| `func_002C4290(void*, int)` | Matching | 100.00% | 32 |
| `func_002C42B0` | Matching | 100.00% | 180 |
| `func_002C4368(void*)` | Matching | 100.00% | 28 |
| `func_002C4388` | Matching | 100.00% | 84 |
| `func_002C43E0(void*, int)` | Matching | 100.00% | 32 |
| `func_002C4400(void*)` | Matching | 100.00% | 8 |
| `func_002C4408(void*, int)` | Matching | 100.00% | 8 |
| `func_002C4410` | Matching | 100.00% | 112 |
| `func_002C4480` | Matching | 100.00% | 92 |
| `func_002C44E0` | Matching | 100.00% | 60 |
| `func_002C4520` | Matching | 100.00% | 84 |
| `func_002C4578` | Matching | 100.00% | 84 |
| `func_002C45D0` | Matching | 100.00% | 120 |
| `func_002C4648` | Matching | 100.00% | 120 |
| `func_002C46C0` | Matching | 100.00% | 96 |
| `func_002C4720(void*, int, int)` | Matching | 100.00% | 40 |
| `func_002C4748` | Matching | 100.00% | 16 |
| `func_002C4758(void*)` | Matching | 100.00% | 12 |
| `func_002C4768(void*)` | Matching | 100.00% | 28 |
| `func_002C4788` | Matching | 100.00% | 120 |
| `func_002C4800` | Matching | 100.00% | 84 |
| `func_002C4858(void*, int, int)` | Matching | 100.00% | 40 |
| `func_002C4880` | Matching | 100.00% | 16 |
| `func_002C4890(void*)` | Matching | 100.00% | 12 |
| `func_002C48A0(void*)` | Matching | 100.00% | 28 |
| `func_002C48C0` | Matching | 100.00% | 2080 |
| `func_002C50E0` | Matching | 100.00% | 92 |
| `func_002C5140` | Matching | 100.00% | 40 |
| `func_002C5168` | Matching | 100.00% | 104 |
| `func_002C51D0` | Matching | 100.00% | 96 |
| `func_002C5230(void*)` | Matching | 100.00% | 32 |
| `func_002C5250` | Matching | 100.00% | 40 |
| `func_002C5278` | Matching | 100.00% | 96 |
| `func_002C52D8` | Matching | 100.00% | 36 |
| `func_002C5300` | Matching | 100.00% | 32 |
| `func_002C5320` | Matching | 100.00% | 20 |
| `func_002C5338(void*)` | Matching | 100.00% | 28 |
| `func_002C5358` | Matching | 100.00% | 88 |
| `func_002C53B0` | Matching | 100.00% | 24 |
| `func_002C53C8` | Matching | 100.00% | 24 |
| `func_002C53E0` | Matching | 100.00% | 240 |
| `func_002C54D0` | Matching | 100.00% | 44 |
| `func_002C5500(void*)` | Matching | 100.00% | 28 |
| `func_002C5520(void*)` | Matching | 100.00% | 8 |
| `func_002C5528` | Matching | 100.00% | 44 |
| `func_002C5558` | Matching | 100.00% | 24 |
| `func_002C5570` | Matching | 100.00% | 24 |
| `func_002C5588` | Matching | 100.00% | 56 |
| `func_002C55C0` | Matching | 100.00% | 24 |
| `func_002C6128` | Matching | 100.00% | 340 |
| `func_002C6280` | Matching | 100.00% | 220 |
| `func_002C6360` | Matching | 100.00% | 136 |
| `func_002C63E8` | Matching | 100.00% | 12 |
| `func_002C63F8` | Matching | 100.00% | 176 |
| `func_002C64A8` | Matching | 100.00% | 36 |
| `func_002C64D0` | Matching | 100.00% | 36 |
| `func_002C64F8` | Matching | 100.00% | 448 |
| `func_002C66B8` | Matching | 100.00% | 32 |
| `func_002C66D8` | Matching | 100.00% | 36 |
| `func_002C6700(void*)` | Matching | 100.00% | 8 |
| `func_002C6708(void*)` | Matching | 100.00% | 8 |
| `func_002C6710(void*)` | Matching | 100.00% | 8 |
| `func_002C6718` | Matching | 100.00% | 44 |
| `func_002C6748(void*)` | Matching | 100.00% | 8 |
| `func_002C6750(void*)` | Matching | 100.00% | 8 |
| `func_002C6758` | Matching | 100.00% | 32 |
| `func_002C6778` | Matching | 100.00% | 44 |
| `func_002C67A8(void*)` | Matching | 100.00% | 8 |
| `func_002C67B0` | Matching | 100.00% | 44 |
| `func_002C67E0(void*)` | Matching | 100.00% | 8 |
| `func_002C67E8(void*, int)` | Matching | 100.00% | 40 |
| `func_002C6810` | Matching | 100.00% | 56 |
| `func_002C6848` | Matching | 100.00% | 128 |
| `func_002C68C8` | Matching | 100.00% | 40 |
| `func_002C68F0` | Matching | 100.00% | 116 |
| `func_002C6968` | Matching | 100.00% | 56 |
| `func_002C69A0` | Matching | 100.00% | 100 |
| `func_002C6A08(void*)` | Matching | 100.00% | 28 |
| `func_002C6A28` | Matching | 100.00% | 56 |
| `func_002C6A60(void*, int, int)` | Matching | 100.00% | 40 |
| `func_002C6A88` | Matching | 100.00% | 88 |
| `func_002C6AE0(void*)` | Matching | 100.00% | 28 |
| `func_002C6B00` | Matching | 100.00% | 80 |
| `func_002C6B50(void*, int, int)` | Matching | 100.00% | 40 |
| `func_002C6B78` | Matching | 100.00% | 88 |
| `func_002C6BD0(void*, int, int)` | Matching | 100.00% | 40 |
| `func_002C6BF8` | Matching | 100.00% | 88 |
| `func_002C6C50` | Matching | 100.00% | 56 |
| `func_002C6C88` | Matching | 100.00% | 88 |
| `func_002C6CE0` | Matching | 100.00% | 52 |
| `func_002C6D18` | Matching | 100.00% | 88 |
| `func_002C6D70` | Matching | 100.00% | 80 |
| `func_002C6DC0(void*)` | Matching | 100.00% | 28 |
| `func_002C6DE0` | Matching | 100.00% | 180 |

### `worldpainter/worldpainterman`

1 matching, 0 partial, 0 not started (1 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldPainterMan_reset(void*)` | Matching | 100.00% | 28 |

### `worldpainter/worldpaintermanquery`

76 matching, 0 partial, 0 not started (76 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldPainterMan_getQuery(void*, cWorldPainterManArg*)` | Matching | 100.00% | 68 |
| `func_002C0AA0` | Matching | 100.00% | 80 |
| `func_002C0AF0` | Matching | 100.00% | 64 |
| `func_002C0B30` | Matching | 100.00% | 60 |
| `func_002C1458(void*)` | Matching | 100.00% | 8 |
| `func_002C1460` | Matching | 100.00% | 48 |
| `func_002C1490(void*)` | Matching | 100.00% | 8 |
| `func_002C1498(void*)` | Matching | 100.00% | 8 |
| `func_002C14A0(void*)` | Matching | 100.00% | 8 |
| `func_002C14A8(void*)` | Matching | 100.00% | 8 |
| `func_002C14B0(void*)` | Matching | 100.00% | 8 |
| `func_002C14B8(void*)` | Matching | 100.00% | 8 |
| `func_002C14C0(void*)` | Matching | 100.00% | 8 |
| `func_002C14C8(void*)` | Matching | 100.00% | 8 |
| `func_002C14D0(void*)` | Matching | 100.00% | 8 |
| `func_002C14D8(void*)` | Matching | 100.00% | 8 |
| `func_002C14E0(void*)` | Matching | 100.00% | 8 |
| `func_002C14E8(void*)` | Matching | 100.00% | 8 |
| `func_002C14F0(void*)` | Matching | 100.00% | 8 |
| `func_002C14F8(void*)` | Matching | 100.00% | 8 |
| `func_002C1500(void*)` | Matching | 100.00% | 8 |
| `func_002C1508(void*)` | Matching | 100.00% | 8 |
| `func_002C1510(void*)` | Matching | 100.00% | 8 |
| `func_002C1518(void*)` | Matching | 100.00% | 8 |
| `func_002C1520(void*)` | Matching | 100.00% | 8 |
| `func_002C1528(void*)` | Matching | 100.00% | 8 |
| `func_002C1530(void*)` | Matching | 100.00% | 8 |
| `func_002C1538(void*)` | Matching | 100.00% | 8 |
| `func_002C1540(void*)` | Matching | 100.00% | 8 |
| `func_002C1548(void*)` | Matching | 100.00% | 8 |
| `func_002C1550(void*)` | Matching | 100.00% | 8 |
| `func_002C1558(void*)` | Matching | 100.00% | 8 |
| `func_002C1560(void*)` | Matching | 100.00% | 8 |
| `func_002C1568(void*)` | Matching | 100.00% | 8 |
| `func_002C1570(void*)` | Matching | 100.00% | 8 |
| `func_002C1578(void*)` | Matching | 100.00% | 8 |
| `func_002C1580(void*)` | Matching | 100.00% | 8 |
| `func_002C1588(void*)` | Matching | 100.00% | 8 |
| `func_002C1590(void*)` | Matching | 100.00% | 8 |
| `func_002C1598(void*)` | Matching | 100.00% | 8 |
| `func_002C15A0(void*)` | Matching | 100.00% | 8 |
| `func_002C15A8(void*)` | Matching | 100.00% | 8 |
| `func_002C15B0(void*)` | Matching | 100.00% | 8 |
| `func_002C15B8(void*)` | Matching | 100.00% | 8 |
| `func_002C15C0(void*)` | Matching | 100.00% | 8 |
| `func_002C15C8(void*)` | Matching | 100.00% | 8 |
| `func_002C15D0(void*)` | Matching | 100.00% | 8 |
| `func_002C15D8(void*)` | Matching | 100.00% | 8 |
| `func_002C15E0(void*)` | Matching | 100.00% | 8 |
| `func_002C15E8(void*)` | Matching | 100.00% | 8 |
| `func_002C15F0(void*)` | Matching | 100.00% | 8 |
| `func_002C15F8(void*)` | Matching | 100.00% | 8 |
| `func_002C1600(void*)` | Matching | 100.00% | 8 |
| `func_002C1608(void*)` | Matching | 100.00% | 8 |
| `func_002C1610(void*)` | Matching | 100.00% | 8 |
| `func_002C1618(void*)` | Matching | 100.00% | 8 |
| `func_002C1620(void*)` | Matching | 100.00% | 8 |
| `func_002C1628(void*)` | Matching | 100.00% | 8 |
| `func_002C1630(void*)` | Matching | 100.00% | 8 |
| `func_002C1638(void*)` | Matching | 100.00% | 8 |
| `func_002C1640(void*)` | Matching | 100.00% | 8 |
| `func_002C1648(void*)` | Matching | 100.00% | 8 |
| `func_002C1650(void*)` | Matching | 100.00% | 8 |
| `func_002C1658(void*)` | Matching | 100.00% | 8 |
| `func_002C1660(void*)` | Matching | 100.00% | 8 |
| `func_002C1668(void*)` | Matching | 100.00% | 8 |
| `func_002C1670(void*)` | Matching | 100.00% | 8 |
| `func_002C1678(void*)` | Matching | 100.00% | 8 |
| `func_002C1680(void*)` | Matching | 100.00% | 8 |
| `func_002C1688(void*)` | Matching | 100.00% | 32 |
| `func_002C16A8` | Matching | 100.00% | 12 |
| `func_002C16B8` | Matching | 100.00% | 92 |
| `func_002C1718` | Matching | 100.00% | 12 |
| `func_002C1728` | Matching | 100.00% | 148 |
| `func_002C17C0(void*)` | Matching | 100.00% | 16 |
| `func_002C0B70` | Matching | 99.98% | 2276 |

### `worldpainter/worldpainterquery`

1 matching, 0 partial, 0 not started (1 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldPainterQuery_reset` | Matching | 100.00% | 60 |

### `worldpainter/worldpainterqueryctor`

3 matching, 0 partial, 1 not started (4 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWorldPainterQuery_cWorldPainterQuery` | Matching | 100.00% | 692 |
| `func_002C06C0` | Matching | 100.00% | 180 |
| `func_002C0A10` | Matching | 100.00% | 72 |

### `wscript/wscriptcompile`

5 matching, 0 partial, 0 not started (5 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWScriptCompile_parseKeywords` | Matching | 100.00% | 236 |
| `func_00351120` | Matching | 100.00% | 80 |
| `func_00351170` | Matching | 100.00% | 92 |
| `func_003511D0` | Matching | 100.00% | 140 |
| `func_00351260(void *, void *)` | Matching | 100.00% | 16 |

### `wscript/wscriptman`

149 matching, 0 partial, 3 not started (152 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWScriptMan_addProcess` | Matching | 100.00% | 156 |
| `cWScriptMan_addProcess1` | Matching | 100.00% | 172 |
| `func_00309618` | Matching | 100.00% | 216 |
| `func_003096F0` | Matching | 100.00% | 92 |
| `func_00309750` | Matching | 100.00% | 72 |
| `func_00309798` | Matching | 100.00% | 72 |
| `func_003097E0` | Matching | 100.00% | 100 |
| `func_00309848` | Matching | 100.00% | 100 |
| `func_003098B0` | Matching | 100.00% | 100 |
| `func_00309918` | Matching | 100.00% | 116 |
| `func_00309990` | Matching | 100.00% | 100 |
| `func_003099F8` | Matching | 100.00% | 100 |
| `func_00309A60` | Matching | 100.00% | 64 |
| `func_00309AA0` | Matching | 100.00% | 92 |
| `func_00309B00` | Matching | 100.00% | 108 |
| `func_00309B70` | Matching | 100.00% | 52 |
| `func_00309BA8` | Matching | 100.00% | 224 |
| `func_00309C88` | Matching | 100.00% | 148 |
| `func_00309D20` | Matching | 100.00% | 176 |
| `func_00309DD0` | Matching | 100.00% | 128 |
| `func_00309E50` | Matching | 100.00% | 196 |
| `func_00309F18` | Matching | 100.00% | 328 |
| `func_0030A270` | Matching | 100.00% | 40 |
| `func_0030A298` | Matching | 100.00% | 80 |
| `func_0030A2E8` | Matching | 100.00% | 40 |
| `func_0030A310` | Matching | 100.00% | 140 |
| `func_0030A3A0` | Matching | 100.00% | 188 |
| `func_0030A460` | Matching | 100.00% | 228 |
| `func_0030A548` | Matching | 100.00% | 80 |
| `func_0030A598` | Matching | 100.00% | 40 |
| `func_0030A5C0` | Matching | 100.00% | 80 |
| `func_0030A610` | Matching | 100.00% | 80 |
| `func_0030A660` | Matching | 100.00% | 40 |
| `func_0030A688` | Matching | 100.00% | 80 |
| `func_0030A6D8` | Matching | 100.00% | 40 |
| `func_0030A700` | Matching | 100.00% | 40 |
| `func_0030A728` | Matching | 100.00% | 316 |
| `func_0030A868` | Matching | 100.00% | 1072 |
| `func_0030AC98` | Matching | 100.00% | 268 |
| `func_0030ADA8` | Matching | 100.00% | 272 |
| `func_0030AEB8` | Matching | 100.00% | 76 |
| `func_0030AF08` | Matching | 100.00% | 336 |
| `func_0030B058(void*)` | Matching | 100.00% | 12 |
| `func_0030B068` | Matching | 100.00% | 124 |
| `func_0030B0E8` | Matching | 100.00% | 204 |
| `func_0030B1B8` | Matching | 100.00% | 80 |
| `func_0030B208` | Matching | 100.00% | 28 |
| `func_0030B228` | Matching | 100.00% | 52 |
| `func_0030B260(void *, void *)` | Matching | 100.00% | 16 |
| `func_0030B270` | Matching | 100.00% | 76 |
| `func_0030B2C0(void *, void *)` | Matching | 100.00% | 16 |
| `func_0030B2D0` | Matching | 100.00% | 76 |
| `func_0030B320` | Matching | 100.00% | 48 |
| `func_0030B350` | Matching | 100.00% | 52 |
| `func_0030B388` | Matching | 100.00% | 100 |
| `func_0030B3F0` | Matching | 100.00% | 52 |
| `func_0030B428` | Matching | 100.00% | 48 |
| `func_0030B458` | Matching | 100.00% | 92 |
| `func_0030B4B8(void*)` | Matching | 100.00% | 8 |
| `func_0030B4C0(void*, int, int)` | Matching | 100.00% | 20 |
| `func_0030B4D8(void*, int, int)` | Matching | 100.00% | 20 |
| `func_0030B4F0(void*, int, int)` | Matching | 100.00% | 20 |
| `func_0030B508(void *, int, void *)` | Matching | 100.00% | 24 |
| `func_0030B520` | Matching | 100.00% | 32 |
| `func_0030B540` | Matching | 100.00% | 80 |
| `func_0030B590` | Matching | 100.00% | 116 |
| `func_0030B608` | Matching | 100.00% | 80 |
| `func_0030B658` | Matching | 100.00% | 156 |
| `func_0030B6F8` | Matching | 100.00% | 96 |
| `func_0030B758` | Matching | 100.00% | 156 |
| `func_0030B7F8` | Matching | 100.00% | 156 |
| `func_0030B898(void *, void *)` | Matching | 100.00% | 36 |
| `func_0030B8C0` | Matching | 100.00% | 104 |
| `func_0030B928` | Matching | 100.00% | 120 |
| `func_0030B9A0` | Matching | 100.00% | 224 |
| `func_0030BA80` | Matching | 100.00% | 68 |
| `func_0030BAC8` | Matching | 100.00% | 68 |
| `func_0030BB10` | Matching | 100.00% | 364 |
| `func_0030BC80` | Matching | 100.00% | 156 |
| `func_0030BD20` | Matching | 100.00% | 456 |
| `func_0030BEE8` | Matching | 100.00% | 216 |
| `func_0030C390` | Matching | 100.00% | 76 |
| `func_0030C3E0` | Matching | 100.00% | 136 |
| `func_0030C468` | Matching | 100.00% | 64 |
| `func_0030C4A8` | Matching | 100.00% | 544 |
| `func_0030C6C8` | Matching | 100.00% | 52 |
| `func_0030C700` | Matching | 100.00% | 52 |
| `func_0030C738` | Matching | 100.00% | 40 |
| `func_0030C760` | Matching | 100.00% | 48 |
| `func_0030C790` | Matching | 100.00% | 48 |
| `func_0030C7C0` | Matching | 100.00% | 96 |
| `func_0030C820` | Matching | 100.00% | 80 |
| `func_0030C870` | Matching | 100.00% | 40 |
| `func_0030C898` | Matching | 100.00% | 60 |
| `func_0030D238` | Matching | 100.00% | 12 |
| `func_0030D248` | Matching | 100.00% | 8 |
| `func_0030D250` | Matching | 100.00% | 8 |
| `func_0030D258` | Matching | 100.00% | 8 |
| `func_0030D260` | Matching | 100.00% | 8 |
| `func_0030D268` | Matching | 100.00% | 8 |
| `func_0030D270` | Matching | 100.00% | 8 |
| `func_0030D278` | Matching | 100.00% | 8 |
| `func_0030D280` | Matching | 100.00% | 8 |
| `func_0030D288` | Matching | 100.00% | 8 |
| `func_0030D290` | Matching | 100.00% | 8 |
| `func_0030D298` | Matching | 100.00% | 8 |
| `func_0030D2A0` | Matching | 100.00% | 8 |
| `func_0030D2A8` | Matching | 100.00% | 8 |
| `func_0030D2B0` | Matching | 100.00% | 8 |
| `func_0030D2B8` | Matching | 100.00% | 8 |
| `func_0030D2C0` | Matching | 100.00% | 8 |
| `func_0030D2C8` | Matching | 100.00% | 8 |
| `func_0030D2D0` | Matching | 100.00% | 8 |
| `func_0030D2D8` | Matching | 100.00% | 8 |
| `func_0030D2E0` | Matching | 100.00% | 8 |
| `func_0030D2E8` | Matching | 100.00% | 8 |
| `func_0030D2F0` | Matching | 100.00% | 8 |
| `func_0030D2F8` | Matching | 100.00% | 8 |
| `func_0030D300` | Matching | 100.00% | 8 |
| `func_0030D308` | Matching | 100.00% | 16 |
| `func_0030D318` | Matching | 100.00% | 8 |
| `func_0030D320` | Matching | 100.00% | 8 |
| `func_0030D328` | Matching | 100.00% | 8 |
| `func_0030D330` | Matching | 100.00% | 20 |
| `func_0030D348` | Matching | 100.00% | 28 |
| `func_0030D368` | Matching | 100.00% | 28 |
| `func_0030D388` | Matching | 100.00% | 8 |
| `func_0030D390` | Matching | 100.00% | 8 |
| `func_0030D398` | Matching | 100.00% | 8 |
| `func_0030D3A0` | Matching | 100.00% | 8 |
| `func_0030D3A8` | Matching | 100.00% | 8 |
| `func_0030D3B0` | Matching | 100.00% | 8 |
| `func_0030D3B8` | Matching | 100.00% | 12 |
| `func_0030D3C8` | Matching | 100.00% | 8 |
| `func_0030D3D0` | Matching | 100.00% | 8 |
| `func_0030D3D8(void*)` | Matching | 100.00% | 8 |
| `func_0030D3E0` | Matching | 100.00% | 28 |
| `func_0030D400` | Matching | 100.00% | 28 |
| `func_0030D420` | Matching | 100.00% | 48 |
| `func_0030D450` | Matching | 100.00% | 12 |
| `func_0030D460` | Matching | 100.00% | 8 |
| `func_0030D468` | Matching | 100.00% | 12 |
| `func_0030D478` | Matching | 100.00% | 8 |
| `func_0030D480(void*)` | Matching | 100.00% | 8 |
| `func_0030D488` | Matching | 100.00% | 16 |
| `func_0030D498(void*)` | Matching | 100.00% | 32 |
| `func_0030D4B8` | Matching | 100.00% | 136 |
| `func_0030D840` | Matching | 100.00% | 120 |
| `func_0030C8D8` | Matching | 99.39% | 2396 |

### `wscript/wscriptmission`

2 matching, 0 partial, 0 not started (2 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWScriptMan_checkGate` | Matching | 100.00% | 1856 |
| `func_00184520` | Matching | 100.00% | 328 |

### `wscript/wscriptprocess`

62 matching, 0 partial, 0 not started (62 total)

| Function | Status | Match % | Size |
|---|---|---|---|
| `cWScriptProcess_cWScriptProcess` | Matching | 100.00% | 416 |
| `func_00307738` | Matching | 100.00% | 192 |
| `func_003077F8` | Matching | 100.00% | 196 |
| `func_003078C0` | Matching | 100.00% | 276 |
| `func_003079D8` | Matching | 100.00% | 52 |
| `func_00307A10` | Matching | 100.00% | 80 |
| `func_00307A60` | Matching | 100.00% | 44 |
| `func_00307A90` | Matching | 100.00% | 44 |
| `func_00307AC0` | Matching | 100.00% | 44 |
| `func_00307AF0` | Matching | 100.00% | 44 |
| `func_00307B20` | Matching | 100.00% | 44 |
| `func_00307B50` | Matching | 100.00% | 44 |
| `func_00307B80` | Matching | 100.00% | 44 |
| `func_00307BB0` | Matching | 100.00% | 44 |
| `func_00307BE0` | Matching | 100.00% | 44 |
| `func_00307C10` | Matching | 100.00% | 44 |
| `func_00307C40` | Matching | 100.00% | 192 |
| `func_00307D00` | Matching | 100.00% | 44 |
| `func_00307D30` | Matching | 100.00% | 72 |
| `func_00307D78` | Matching | 100.00% | 76 |
| `func_00307DC8` | Matching | 100.00% | 72 |
| `func_00307E10` | Matching | 100.00% | 176 |
| `func_00307EC0` | Matching | 100.00% | 152 |
| `func_00307F58` | Matching | 100.00% | 188 |
| `func_00308018(void*)` | Matching | 100.00% | 28 |
| `func_00308038` | Matching | 100.00% | 224 |
| `func_00308118` | Matching | 100.00% | 272 |
| `func_00308228` | Matching | 100.00% | 76 |
| `func_00308278` | Matching | 100.00% | 176 |
| `func_00308328` | Matching | 100.00% | 120 |
| `func_003083A0` | Matching | 100.00% | 300 |
| `func_003084D0` | Matching | 100.00% | 44 |
| `func_00308500` | Matching | 100.00% | 44 |
| `func_00308530` | Matching | 100.00% | 44 |
| `func_00308560` | Matching | 100.00% | 44 |
| `func_00308590` | Matching | 100.00% | 44 |
| `func_003085C0` | Matching | 100.00% | 44 |
| `func_003085F0` | Matching | 100.00% | 44 |
| `func_00308620` | Matching | 100.00% | 44 |
| `func_00308650` | Matching | 100.00% | 44 |
| `func_00308680` | Matching | 100.00% | 44 |
| `func_003086B0` | Matching | 100.00% | 64 |
| `func_003086F0` | Matching | 100.00% | 44 |
| `func_00308720` | Matching | 100.00% | 64 |
| `func_00308760` | Matching | 100.00% | 52 |
| `func_00308798` | Matching | 100.00% | 52 |
| `func_003087D0` | Matching | 100.00% | 260 |
| `func_003088D8` | Matching | 100.00% | 176 |
| `func_00308988` | Matching | 100.00% | 188 |
| `func_00308A48` | Matching | 100.00% | 84 |
| `func_00308AA0` | Matching | 100.00% | 180 |
| `func_00308B58(void*)` | Matching | 100.00% | 28 |
| `func_00308B78` | Matching | 100.00% | 100 |
| `func_00308BE0` | Matching | 100.00% | 124 |
| `func_00308C60` | Matching | 100.00% | 344 |
| `func_00308DB8` | Matching | 100.00% | 384 |
| `func_00308F38` | Matching | 100.00% | 56 |
| `func_00308F70` | Matching | 100.00% | 112 |
| `func_00308FE0` | Matching | 100.00% | 76 |
| `func_00309030` | Matching | 100.00% | 228 |
| `func_00309118` | Matching | 100.00% | 340 |
| `func_00309270` | Matching | 100.00% | 600 |

