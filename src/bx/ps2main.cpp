#include "common.h"

//100%
INCLUDE_ASM("bx/ps2main", systemInit);
#ifdef SKIP_ASM
extern void* D_004A3E94;
extern char D_0048DA88[];
extern char D_0048DA98[];
extern char D_0048DAA8[];
extern char D_0048DAB8[];
extern char D_0048DAC8[];
extern char D_0048DAD8[];
extern char D_004A3ED8[];
extern "C" void func_00319610(void* io);
extern "C" void func_00319718(void* io, const char* module, int a, int b, int c);
extern "C" void func_00409940(void);
extern "C" void func_003FF4A8(int a);
extern "C" void func_00402520(int* clock);
void BXsrand(unsigned int seed);
extern "C" void func_003E5018(void);
extern "C" void* func_004188C0(int size);
extern "C" void func_00418910(void* p);
extern "C" char* func_00423D80(void);
extern "C" void cMemMan_initialize(char* heap, int size);
extern "C" void func_003E6690(int a);
extern "C" void func_003E4AF0(int hz);
extern "C" int func_003DE928(void* cfg);
extern "C" int func_003DE9B8(void* cfg);
extern "C" void func_003DCBD8(int a, int b, int c);
extern "C" void func_003DF488(int a, int b);
extern "C" void func_003E4000(void);
extern "C" void func_0031AD20(void);
extern "C" void SYNCTASK_del(void (*fn)(void));
extern "C" void SYNCTASK_add(void (*fn)(void), int a, int b);
extern "C" void func_003DDE78(void* p);
extern "C" void func_00252FA0(void);
extern "C" void func_002523A8(void);

struct sIoCfg_SysInit {
    int size;               // 0x0
    void (*fnA)(void);      // 0x4
    void (*fnB)(void);      // 0x8
    int mode;               // 0xC
    char pad_0x10[0x14];
};

// Boot-time setup: IOP modules, timers, random seed, heap, file system and the per-frame sync task.
extern "C" void systemInit(void)
{
    func_00319610(D_004A3E94);
    func_00319718(D_004A3E94, D_0048DA88, 1, 0, 0);
    func_00319718(D_004A3E94, D_0048DA98, 1, 0, 0);
    func_00319718(D_004A3E94, D_0048DAA8, 1, 0, 0);
    func_00319718(D_004A3E94, D_0048DAB8, 1, 0, 0);
    func_00319718(D_004A3E94, D_0048DAC8, 1, 0, 0);
    func_00319718(D_004A3E94, D_0048DAD8, 1, 0, 0);
    func_00409940();
    func_003FF4A8(0);
    int clock[2];
    func_00402520(clock);
    BXsrand(clock[0] ^ (clock[1] << 3));
    func_003E5018();
    char* p = (char*)func_004188C0(0x400);
    func_00418910(p);
    char* heap = (char*)(((int)p + 0x3F) & ~0x3F) + 0x800;
    cMemMan_initialize(heap, func_00423D80() - heap);
    func_003E6690(1);
    func_003E4AF0(0x3C);
    sIoCfg_SysInit cfg;
    cfg.size = 0x24;
    func_003DE928(&cfg);
    cfg.fnA = func_00252FA0;
    cfg.fnB = func_002523A8;
    cfg.mode = 2;
    func_003DE9B8(&cfg);
    func_003DCBD8(0x30, 500, 0x20);
    func_003DF488(0x10, 0);
    SYNCTASK_del(func_003E4000);
    SYNCTASK_add(func_0031AD20, 0, 0);
    func_003DDE78(D_004A3ED8);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/ps2main", main);
#ifdef SKIP_ASM
struct cExecutionMan;
struct cExecutionManMainK {
    int field_0x0;
    int field_0x4;
    void* field_0x8; // vtable
};
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
cExecutionMan* cExecutionMan_halt(cExecutionMan* self);
extern "C" void func_0040FC90(void); // __main
extern "C" void systemInit(void);
extern "C" int cAppMan_run(void* self, cExecutionMan* exec, int argc, char** argv);
extern void* D_004A5B64;
extern const char D_0048DAE8[];
extern void* D_0048DB68[];

// PORT: bound to "main" by asm label so gcc doesn't emit its own __main call;
// the target calls func_0040FC90 (__main) explicitly. Off-PS2 this is plain main().
int main_impl(int argc, char** argv) __asm__("main");

int main_impl(int argc, char** argv)
{
    func_0040FC90();
    systemInit();
    cExecutionManMainK* exec = (cExecutionManMainK*)cMemMan_alloc(0x142C0, D_0048DAE8, 0, 0);
    cExecutionMan_halt((cExecutionMan*)exec);
    exec->field_0x8 = D_0048DB68;
    return cAppMan_run(D_004A5B64, (cExecutionMan*)exec, argc, argv);
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B008);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cAppManB008 {
public:
    char pad_0x00[0x5C];
    virtual void v01();
    virtual void v02();
};
// Typed view of D_004A5B64 (main() in this unit declares it as void*).
extern cAppManB008* D_004A5B64_B008 __asm__("D_004A5B64");
extern "C" void func_00402450(int);
extern "C" void func_00401718(int);
extern "C" void func_00425FB8(void);
extern "C" void func_0042C6A0(int, int, int);

extern "C" void func_0031B008(int a0, int a1, int a2)
{
    D_004A5B64_B008->v02();
    func_00402450(2);
    func_00401718(0);
    func_00401718(5);
    func_00425FB8();
    func_0042C6A0(a0, a1, a2);
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B088);
#ifdef SKIP_ASM
extern "C" float func_0031B088(float a, float b, float c, float d)
{
    return a * d - b * c;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/ps2main", func_0031B098);
#ifdef SKIP_ASM
extern "C" float func_0031B088(float a, float b, float c, float d);

// 3x3 determinant by cofactor expansion along the first column.
extern "C" float func_0031B098(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
    return a * func_0031B088(e, f, h, i) - d * func_0031B088(b, c, h, i) + g * func_0031B088(b, c, e, f);
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B178);
#ifdef SKIP_ASM
extern "C" float func_0031B098(float a, float b, float c, float d, float e, float f, float g, float h, float i);

// 4x4 determinant by cofactor expansion along the first row.
extern "C" float func_0031B178(void* vm)
{
    float (*m)[4] = (float (*)[4])vm;
    float ans;
    float a1, a2, a3, a4, b1, b2, b3, b4;
    float c1, c2, c3, c4, d1, d2, d3, d4;

    a1 = m[0][0]; b1 = m[0][1];
    c1 = m[0][2]; d1 = m[0][3];

    a2 = m[1][0]; b2 = m[1][1];
    c2 = m[1][2]; d2 = m[1][3];

    a3 = m[2][0]; b3 = m[2][1];
    c3 = m[2][2]; d3 = m[2][3];

    a4 = m[3][0]; b4 = m[3][1];
    c4 = m[3][2]; d4 = m[3][3];

    ans = a1 * func_0031B098(b2, b3, b4, c2, c3, c4, d2, d3, d4)
        - b1 * func_0031B098(a2, a3, a4, c2, c3, c4, d2, d3, d4)
        + c1 * func_0031B098(a2, a3, a4, b2, b3, b4, d2, d3, d4)
        - d1 * func_0031B098(a2, a3, a4, b2, b3, b4, c2, c3, c4);
    return ans;
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B310);
#ifdef SKIP_ASM
extern "C" float func_0031B098(float a, float b, float c, float d, float e, float f, float g, float h, float i);

// 4x4 adjoint (transposed cofactor matrix), in place.
extern "C" void func_0031B310(void* vm)
{
    float (*m)[4] = (float (*)[4])vm;
    float a1, a2, a3, a4, b1, b2, b3, b4;
    float c1, c2, c3, c4, d1, d2, d3, d4;

    a1 = m[0][0]; b1 = m[0][1];
    c1 = m[0][2]; d1 = m[0][3];

    a2 = m[1][0]; b2 = m[1][1];
    c2 = m[1][2]; d2 = m[1][3];

    a3 = m[2][0]; b3 = m[2][1];
    c3 = m[2][2]; d3 = m[2][3];

    a4 = m[3][0]; b4 = m[3][1];
    c4 = m[3][2]; d4 = m[3][3];

    m[0][0] =  func_0031B098(b2, b3, b4, c2, c3, c4, d2, d3, d4);
    m[1][0] = -func_0031B098(a2, a3, a4, c2, c3, c4, d2, d3, d4);
    m[2][0] =  func_0031B098(a2, a3, a4, b2, b3, b4, d2, d3, d4);
    m[3][0] = -func_0031B098(a2, a3, a4, b2, b3, b4, c2, c3, c4);

    m[0][1] = -func_0031B098(b1, b3, b4, c1, c3, c4, d1, d3, d4);
    m[1][1] =  func_0031B098(a1, a3, a4, c1, c3, c4, d1, d3, d4);
    m[2][1] = -func_0031B098(a1, a3, a4, b1, b3, b4, d1, d3, d4);
    m[3][1] =  func_0031B098(a1, a3, a4, b1, b3, b4, c1, c3, c4);

    m[0][2] =  func_0031B098(b1, b2, b4, c1, c2, c4, d1, d2, d4);
    m[1][2] = -func_0031B098(a1, a2, a4, c1, c2, c4, d1, d2, d4);
    m[2][2] =  func_0031B098(a1, a2, a4, b1, b2, b4, d1, d2, d4);
    m[3][2] = -func_0031B098(a1, a2, a4, b1, b2, b4, c1, c2, c4);

    m[0][3] = -func_0031B098(b1, b2, b3, c1, c2, c3, d1, d2, d3);
    m[1][3] =  func_0031B098(a1, a2, a3, c1, c2, c3, d1, d2, d3);
    m[2][3] = -func_0031B098(a1, a2, a3, b1, b2, b3, d1, d2, d3);
    m[3][3] =  func_0031B098(a1, a2, a3, b1, b2, b3, c1, c2, c3);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/ps2main", func_0031B6C8);
#ifdef SKIP_ASM
extern "C" float func_0031B178(void* m);
extern "C" void func_0031B310(void* m);

// Matrix inverse: adjoint (func_0031B310) scaled by 1/determinant (func_0031B178).
// PORT: PS2-only VU0 inline asm (4x4 matrix times scalar, in place).
extern "C" void func_0031B6C8(void* m)
{
    float det = func_0031B178(m);
    func_0031B310(m);
    float s = 1.0f / det;
    int t;
    __asm__ __volatile__(
        "mfc1      %0, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "qmtc2.ni  %0, $vf3\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulx.xyzw $vf8, $vf4, $vf3x\n"
        "vmulx.xyzw $vf9, $vf5, $vf3x\n"
        "vmulx.xyzw $vf10, $vf6, $vf3x\n"
        "vmulx.xyzw $vf11, $vf7, $vf3x\n"
        "sqc2      $vf8, 0x0(%1)\n"
        "sqc2      $vf9, 0x10(%1)\n"
        "sqc2      $vf10, 0x20(%1)\n"
        "sqc2      $vf11, 0x30(%1)\n"
        : "=&r"(t)
        : "r"(m), "f"(s)
        : "memory");
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B748);
#ifdef SKIP_ASM
struct sVec4_B748 {
    float x, y, z, w;

    sVec4_B748() {}
    sVec4_B748(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sMtx_B748 {
    float m[4][4];
};

struct sXform_B748 {
    sVec4_B748 pos;     // 0x0
    sVec4_B748 rot;     // 0x10, quaternion
};

// PORT: func_0031B7A8 returns the quaternion by value (hidden result pointer).
extern "C" sVec4_B748 func_0031B7A8_v(sMtx_B748* mat) __asm__("func_0031B7A8");

// Splits a rigid transform matrix into its translation row and rotation quaternion.
extern "C" sXform_B748* func_0031B748(sXform_B748* out, sMtx_B748* mat)
{
    out->pos = sVec4_B748(mat->m[3][0], mat->m[3][1], mat->m[3][2], mat->m[3][3]);
    out->rot = func_0031B7A8_v(mat);
    return out;
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B7A8);
#ifdef SKIP_ASM
struct sMtx_B7A8 {
    float m[4][4];
};

struct sQuat_B7A8 {
    float x, y, z, w;
};

// PORT: sqrt.s (sqrtf without errno check)
static inline float sqrtB7A8(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

// Rotation matrix to quaternion (Shoemake): from the trace when positive, else from the largest diagonal term.
extern "C" sQuat_B7A8* func_0031B7A8(sQuat_B7A8* qu, sMtx_B7A8* mat)
{
    float tr = mat->m[0][0] + mat->m[1][1] + mat->m[2][2];
    if (0.0f < tr) {
        float s = sqrtB7A8(tr + 1.0f);
        qu->w = s * 0.5f;
        s = 0.5f / s;
        qu->x = (mat->m[1][2] - mat->m[2][1]) * s;
        qu->y = (mat->m[2][0] - mat->m[0][2]) * s;
        qu->z = (mat->m[0][1] - mat->m[1][0]) * s;
    } else {
        float q[4];
        int i = 0;
        if (mat->m[0][0] < mat->m[1][1]) {
            i = 1;
        }
        if (mat->m[i][i] < mat->m[2][2]) {
            i = 2;
        }
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        float s = sqrtB7A8(mat->m[i][i] - mat->m[j][j] - mat->m[k][k] + 1.0f);
        q[i] = s * 0.5f;
        if (s != 0.0f) {
            s = 0.5f / s;
        }
        q[3] = (mat->m[j][k] - mat->m[k][j]) * s;
        q[j] = (mat->m[i][j] + mat->m[j][i]) * s;
        q[k] = (mat->m[i][k] + mat->m[k][i]) * s;
        qu->x = q[0];
        qu->y = q[1];
        qu->z = q[2];
        qu->w = q[3];
    }
    return qu;
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031B9B0);
#ifdef SKIP_ASM
extern "C" float func_0031C128(float x);
extern "C" void func_0031BE50(float* sout, float* cout, float x);

struct sV4_B9B0 {
    float x, y, z, w;
    sV4_B9B0() {}
    // PORT: this store order (w, x, y, z) reproduces the target float-register allocation
    sV4_B9B0(float ax, float ay, float az, float aw) { w = aw; x = ax; y = ay; z = az; }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (cross product, w cleared).
static inline sV4_B9B0 vu0Cross_B9B0(const sV4_B9B0& a, const sV4_B9B0& b)
{
    sV4_B9B0 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vsub.w     $vf6, $vf6, $vf6\n"
        "sqc2       $vf6, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector length via vsqrt).
static inline float vu0Length_B9B0(const sV4_B9B0& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

// PORT: PS2-only VU0 inline asm (vector divided by scalar, in place).
static inline void vu0DivEq_B9B0(sV4_B9B0& v, float s)
{
    int t;
    __asm__(
        "mfc1      %1, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %0\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf4, Q\n"
        "sqc2      $vf5, %0\n"
        : "+m"(v), "=&r"(t)
        : "f"(s)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4-component dot product).
static inline float vu0Dot_B9B0(const sV4_B9B0& a, const sV4_B9B0& b)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "lqc2      $vf5, %3\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf5\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "qmfc2.ni  %1, $vf4\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(a), "m"(b));
    return r;
}

// PORT: PS2-only VU0 macro-mode asm (quaternion product a * b).
static inline sV4_B9B0 vu0QuatMul_B9B0(const sV4_B9B0& a, const sV4_B9B0& b)
{
    sV4_B9B0 r;
    __asm__(
        "lqc2       $vf4, %1\n"
        "lqc2       $vf5, %2\n"
        "vmul.xyzw  $vf7, $vf4, $vf5\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vmulaw.xyz ACC, $vf4, $vf5w\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vsubax.w   ACC, $vf7, $vf7x\n"
        "vmsubay.w  ACC, $vf0, $vf7y\n"
        "vmsubz.w   $vf8, $vf0, $vf7z\n"
        "vmaddw.xyz $vf8, $vf6, $vf0w\n"
        "sqc2       $vf8, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline sV4_B9B0 axisAngle_B9B0(const sV4_B9B0& axis, float angle)
{
    float s, c;
    func_0031BE50(&s, &c, angle * 0.5f);
    return sV4_B9B0(s * axis.x, s * axis.y, s * axis.z, c);
}

static inline void rotate_B9B0(sV4_B9B0& q, const sV4_B9B0& axis, float angle)
{
    q = vu0QuatMul_B9B0(q, axisAngle_B9B0(axis, angle));
}

extern "C" void func_0031B9B0(sV4_B9B0* q, const sV4_B9B0* a, const sV4_B9B0* b)
{
    sV4_B9B0 axis = vu0Cross_B9B0(*a, *b);
    float len = vu0Length_B9B0(axis);
    if (len != 0.0f) {
        vu0DivEq_B9B0(axis, len);
        if (0.9999899864196777f < len) {
            len = 0.9999899864196777f;
        }
        float angle;
        if (vu0Dot_B9B0(*a, *b) < 0.0f) {
            angle = 3.1415927410125732f - func_0031C128(len);
        } else {
            angle = func_0031C128(len);
        }
        rotate_B9B0(*q, axis, angle);
    }
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031BB30);
#ifdef SKIP_ASM
static inline void premul_B9B0(sV4_B9B0& q, const sV4_B9B0& axis, float angle)
{
    q = vu0QuatMul_B9B0(axisAngle_B9B0(axis, angle), q);
}

// Same as func_0031B9B0, but the rotation is applied on the other side (rot * *q).
extern "C" void func_0031BB30(sV4_B9B0* q, const sV4_B9B0* a, const sV4_B9B0* b)
{
    sV4_B9B0 axis = vu0Cross_B9B0(*a, *b);
    float len = vu0Length_B9B0(axis);
    if (len != 0.0f) {
        vu0DivEq_B9B0(axis, len);
        if (0.9999899864196777f < len) {
            len = 0.9999899864196777f;
        }
        float angle;
        if (vu0Dot_B9B0(*a, *b) < 0.0f) {
            angle = 3.1415927410125732f - func_0031C128(len);
        } else {
            angle = func_0031C128(len);
        }
        premul_B9B0(*q, axis, angle);
    }
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031BCB0);
#ifdef SKIP_ASM
extern "C" float func_0031C128(float x);
extern "C" float func_0031BF60(float x);

struct sQuat_31BCB0 {
    float x, y, z, w;
    sQuat_31BCB0() {}
    sQuat_31BCB0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

// Quaternion slerp.
extern "C" sQuat_31BCB0 func_0031BCB0(const sQuat_31BCB0* a, const sQuat_31BCB0* b, float t)
{
    float cosom = a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
    sQuat_31BCB0 to;
    if (cosom < 0.0f) {
        cosom = -cosom;
        to.x = -b->x;
        to.y = -b->y;
        to.z = -b->z;
        to.w = -b->w;
    } else {
        to.x = b->x;
        to.y = b->y;
        to.z = b->z;
        to.w = b->w;
    }
    float s0, s1;
    if (1.0f - cosom > 0.0010000000474974513f) {
        float omega = 1.5707963705062866f - func_0031C128(cosom);
        float sinom = func_0031BF60(omega);
        s0 = func_0031BF60((1.0f - t) * omega) / sinom;
        s1 = func_0031BF60(t * omega) / sinom;
    } else {
        s0 = 1.0f - t;
        s1 = t;
    }
    sQuat_31BCB0 r(s0 * a->x + s1 * to.x, s0 * a->y + s1 * to.y, s0 * a->z + s1 * to.z, s0 * a->w + s1 * to.w);
    return r;
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031BE50);
#ifdef SKIP_ASM
// sincos(x): quadrant reduction by pi/2, sin polynomial, cos = sqrt(1 - sin^2).
extern "C" void func_0031BE50(float* sout, float* cout, float x)
{
    float t = x * 0.6366197466850281f;
    if (x < 0.0f)
        t -= 0.5f;
    else
        t += 0.5f;
    int q;
    float fq;
    // PORT: PS2 float->int->float round trip kept in the FPU (cvt.w.s / mfc1 / cvt.s.w).
    __asm__("cvt.w.s %0, %0\n\tmfc1 %1, %0\n\tcvt.s.w %0, %0" : "+f"(t), "=r"(q));
    fq = t;
    x = x - fq * 1.5707963705062866f;
    float x2 = x * x;
    float r;
    r = x2 * 2.755732339210226e-06f;
    r = (r + -0.0001984127302421257f) * x2;
    r = (r + 0.008333333767950535f) * x2;
    r = (r + -0.1666666716337204f) * x2;
    r = (r + 1.0f) * x;
    float c2 = 1.0f - r * r;
    float c;
    // PORT: sqrt.s (sqrtf without errno check)
    __asm__("sqrt.s %0, %1" : "=f"(c) : "f"(c2));
    switch (q & 3)
    {
    case 0:
        *sout = r;
        *cout = c;
        break;
    case 1:
        *sout = c;
        *cout = -r;
        break;
    case 2:
        *sout = -r;
        *cout = -c;
        break;
    case 3:
        *sout = -c;
        *cout = r;
        break;
    }
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031BF60);
#ifdef SKIP_ASM
// sin(x): quadrant reduction by pi/2, then a cos or sin polynomial (Horner form).
extern "C" float func_0031BF60(float x)
{
    float t = x * 0.6366197466850281f;
    if (x < 0.0f)
        t -= 0.5f;
    else
        t += 0.5f;
    int q;
    float fq;
    // PORT: PS2 float->int->float round trip kept in the FPU (cvt.w.s / mfc1 / cvt.s.w).
    __asm__("cvt.w.s %0, %0\n\tmfc1 %1, %0\n\tcvt.s.w %0, %0" : "+f"(t), "=r"(q));
    fq = t;
    x = x - fq * 1.5707963705062866f;
    float x2 = x * x;
    float r;
    if (q & 1)
    {
        r = x2 * 2.480159128026571e-05f;
        r = (r + -0.0013888890389353037f) * x2;
        r = (r + 0.0416666679084301f) * x2;
        r = (r + -0.5f) * x2;
        r = r + 1.0f;
    }
    else
    {
        r = x2 * 2.755732339210226e-06f;
        r = (r + -0.0001984127302421257f) * x2;
        r = (r + 0.008333333767950535f) * x2;
        r = (r + -0.1666666716337204f) * x2;
        r = r * x + x;
    }
    if (q & 2)
        r = -r;
    return r;
}
#endif

//100%
INCLUDE_ASM("bx/ps2main", func_0031C040);
#ifdef SKIP_ASM
// cos(x): quadrant reduction by pi/2, then a sin or cos polynomial (Horner form).
extern "C" float func_0031C040(float x)
{
    float t = x * 0.6366197466850281f;
    if (x < 0.0f)
        t -= 0.5f;
    else
        t += 0.5f;
    int q;
    float fq;
    // PORT: PS2 float->int->float round trip kept in the FPU (cvt.w.s / mfc1 / cvt.s.w).
    __asm__("cvt.w.s %0, %0\n\tmfc1 %1, %0\n\tcvt.s.w %0, %0" : "+f"(t), "=r"(q));
    fq = t;
    x = x - fq * 1.5707963705062866f;
    float x2 = x * x;
    float r;
    if (q & 1)
    {
        r = x2 * 2.755732339210226e-06f;
        r = (r + -0.0001984127302421257f) * x2;
        r = (r + 0.008333333767950535f) * x2;
        r = (r + -0.1666666716337204f) * x2;
        r = r * x + x;
    }
    else
    {
        r = x2 * 2.480159128026571e-05f;
        r = (r + -0.0013888890389353037f) * x2;
        r = (r + 0.0416666679084301f) * x2;
        r = (r + -0.5f) * x2;
        r = r + 1.0f;
    }
    if ((q + 1) & 2)
        r = -r;
    return r;
}
#endif

INCLUDE_ASM("bx/ps2main", func_0031C128);

INCLUDE_ASM("bx/ps2main", func_0031C228);

