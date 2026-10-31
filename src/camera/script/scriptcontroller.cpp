#include "common.h"

//100%
INCLUDE_ASM("camera/script/scriptcontroller", cScriptCameraController_cScriptCameraController);
#ifdef SKIP_ASM
extern "C" void* cCameraController_cCameraController(void* self, void* arg);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0027D5E8(void* mem, void* script);
extern "C" void func_00283298(void* p);
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);
extern void* D_0045C428[];
extern char D_0045BE88[];
extern char D_0045BEA0[];

extern "C" void* cScriptCameraController_cScriptCameraController(void* self, void* script, void* arg)
{
    int i;
    cCameraController_cCameraController(self, arg);
    *(void***)((char*)self + 0x14) = D_0045C428;
    *(int*)self = 3;
    *(void***)((char*)self + 0x1C) = (void**)operator_new__FUi(8, D_0045BE88, 0, 0);
    for (i = 0; i < 2; i++) {
        void** slot = (void**)((i << 2) + *(int*)((char*)self + 0x1C));
        *slot = func_0027D5E8(cMemMan_alloc(0x80, D_0045BEA0, 0, 0), script);
        func_00283298((*(void***)((char*)self + 0x1C))[i]);
    }
    *(int*)((char*)self + 0x18) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_001690D0);
#ifdef SKIP_ASM
extern "C" void func_002832D8(void* p);
extern "C" void func_0015CC10(void* self, int flags);
void cMemMan_free(void* p);
extern void* D_0045C428[];

class cScrCamScriptK2 {
public:
    char pad_0x00[0xC];
    // vptr at 0xC
    virtual ~cScrCamScriptK2();
};

extern "C" void func_001690D0(void* self, int flags)
{
    int i;
    *(void***)((char*)self + 0x14) = D_0045C428;
    for (i = 0; i < 2; i++) {
        func_002832D8((*(cScrCamScriptK2***)((char*)self + 0x1C))[i]);
        delete (*(cScrCamScriptK2***)((char*)self + 0x1C))[i];
    }
    if (*(void**)((char*)self + 0x1C) != 0)
        cMemMan_free(*(void**)((char*)self + 0x1C));
    func_0015CC10(self, flags);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", cScriptCameraController_addCamera);
#ifdef SKIP_ASM
unsigned char func_002743C8(void* self);
void func_001694A8(void* self, int val);
extern "C" void* func_001694B8(void* self);
extern "C" void* func_00169CF8(void* self);
extern "C" void* func_0016A458(void* self);
extern "C" void* func_0016AD38(void* self);
// PORT: func_00169340 is defined with (self, algo); this caller passes a third int argument.
extern "C" void func_00169340_3(void* self, void* algo, int a) __asm__("func_00169340");
extern char D_0045BEB0[];
extern char D_0045BED0[];
extern char D_0045BEF0[];
extern char D_0045BF10[];

extern "C" void cScriptCameraController_addCamera(char* self, char* cam)
{
    void* ctl;
    switch (func_002743C8(*(void**)(*(char**)(cam + 0x14) + 8)))
    {
    case 0:
        ctl = func_001694B8(cMemMan_alloc(0xB0, D_0045BEB0, 0x20000000, 0));
        break;
    case 1:
        ctl = func_00169CF8(cMemMan_alloc(0xB0, D_0045BED0, 0x20000000, 0));
        break;
    case 2:
        ctl = func_0016A458(cMemMan_alloc(0xA0, D_0045BEF0, 0x20000000, 0));
        break;
    case 3:
        ctl = func_0016AD38(cMemMan_alloc(0xA0, D_0045BF10, 0x20000000, 0));
        break;
    default:
        return;
    }
    // PORT: the camera pointer is passed through an int parameter.
    func_001694A8(ctl, (int)cam);
    *(void**)(cam + 0x1C) = ctl;
    func_00169340_3(self, ctl, 1);
    *(int*)(self + 0x18) = 1;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_001692D8);
#ifdef SKIP_ASM
struct sScrAlgoNode {
    int key;              // 0x0
    char pad_0x04[0x10];
    sScrAlgoNode* next;   // 0x14
};

struct sScrAlgoList {
    sScrAlgoNode* head;   // 0x0
    int count;            // 0x4
};

extern "C" void func_0015CA50(sScrAlgoList* list, sScrAlgoNode* node);

extern "C" void func_001692D8(void* self, void* algo)
{
    if (*(int*)((char*)self + 0x18) != 0) {
        sScrAlgoList* list = *(sScrAlgoList**)((char*)self + 0x8);
        for (sScrAlgoNode* n = list->head; n != 0; n = n->next) {
            int k = *(int*)((char*)algo + 0x1C);
            if (n->key == k) {
                func_0015CA50(list, n);
                break;
            }
        }
        if (list->count <= 0)
            *(int*)((char*)self + 0x18) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169340);
#ifdef SKIP_ASM
extern "C" void cCameraAlgoList_insert(void*, void*, float);

extern "C" void func_00169340(void* self, void* algo)
{
    cCameraAlgoList_insert(*(void**)((char*)self + 0x8), algo, 1.0f);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169368);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_001694B0 returns a pointer (the unit declares it int); bind a pointer-returning alias.
char* func_001694B0_K2(void* self) __asm__("func_001694B0__FPv");

class cScrCamAlgoK2 {
public:
    char pad_0x00[0x10];
    // vptr at 0x10
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

struct sScrAlgoNodeK2 {
    cScrCamAlgoK2* algo;    // 0x0
    float t;                // 0x4
    float pad_0x08;
    float weight;           // 0xC
    int pad_0x10;
    sScrAlgoNodeK2* next;   // 0x14
};

extern "C" void func_00169368(void* self)
{
    sScrAlgoNodeK2* n = **(sScrAlgoNodeK2***)((char*)self + 0x8);
    while (n != 0) {
        float t = *(float*)(func_001694B0_K2(n->algo) + 0x18);
        float t2 = t * t;
        float s = t2 * 3.0f - t2 * 2.0f * t;
        n->t = t;
        if (s > 1.0f)
            s = 1.0f;
        n->weight = s;
        n->algo->v05();
        n = n->next;
    }
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169418);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_0045BDE0[];
extern void* D_0045C8B8[];
extern void* D_004A28A8;
struct sVec4K9418 { float x, y, z, w; } __attribute__((aligned(16)));
// Same object as the unit's later `extern func_001694B8_sVec4 D_004FF130;` (that type is defined below this point).
extern sVec4K9418 D_004FF130_K9418 __asm__("D_004FF130");
extern "C" float func_00167E30(void* self);

struct sCamCtlK9418 {
    float fov;      // 0x0
    float nearZ;    // 0x4
    float farZ;     // 0x8
    int type;       // 0xC
    void** vtbl;    // 0x10
    int f14;        // 0x14
    int f18;        // 0x18
    int pad_1C;
    sVec4K9418 v20; // 0x20
};

extern "C" void* func_00169418(void* p)
{
    sCamCtlK9418* self = (sCamCtlK9418*)p;
    self->vtbl = D_0045BDE0;
    float fov = func_00167E30(self);
    self->type = 0x55;
    self->vtbl = D_0045C8B8;
    self->fov = fov;
    self->nearZ = 10.0f;
    self->farZ = 30000.0f;
    self->f14 = 0;
    void* cam = *(void**)((char*)D_004A28A8 + 0x84);
    void* chase = *(void**)((char*)cam + 0x84);
    void* ctrl = *(void**)((char*)chase + 0x4);
    self->f18 = *(int*)((char*)ctrl + 0xAC);
    self->v20 = D_004FF130_K9418;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_001694A8__FPvi);
#ifdef SKIP_ASM
void func_001694A8(void* self, int val)
{
    *(int*)((char*)self + 0x14) = val;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_001694B0__FPv);
#ifdef SKIP_ASM
int func_001694B0(void* self)
{
    return *(int*)((char*)self + 0x14);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/script/scriptcontroller", func_001694B8);
#ifdef SKIP_ASM
struct func_001694B8_sVec4 { float x, y, z, w; } __attribute__((aligned(16)));

extern void* D_0045C850[];
extern func_001694B8_sVec4 D_004FF130;
extern "C" void* func_00169418(void* self);
extern "C" void* func_0015FFF0(void* self);

extern "C" void* func_001694B8(void* self)
{
    func_00169418(self);
    *(void***)((char*)self + 0x10) = D_0045C850;
    func_0015FFF0((char*)self + 0x74);
    *(func_001694B8_sVec4*)((char*)self + 0x30) = D_004FF130;
    *(int*)((char*)self + 0xC) = 0x56;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x40) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169518);
#ifdef SKIP_ASM
class cScriptCtlVirt {
public:
    char pad[0x10];
    // vptr lands at 0x10 (g++ 2.95 places it after the class's own data);
    // slot N lives at vtable offset N*8 (delta at +0, function at +4)
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
};

extern "C" void func_00169518(cScriptCtlVirt* self)
{
    self->v05();
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169540);
#ifdef SKIP_ASM
class cScriptCtlVirt2 {
public:
    char pad[0x10];
    // vptr at 0x10; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03(int);
};

extern "C" void func_00169540(cScriptCtlVirt2* self)
{
    self->v03(0);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169570);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; needs a C fallback off-PS2.
float* func_0027C098(void* cam);
extern "C" void func_0027C0F0(void* cam, void* out);
extern "C" float func_0031C228(float x);
extern "C" void func_00160028(void* self, float v);
extern "C" void func_00160130(void* self, float v);

struct sVec4_169570 {
    float x, y, z, w;
    sVec4_169570() {}
    sVec4_169570(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

static inline sVec4_169570 mtxMulVec_169570(char* m, const sVec4_169570& v)
{
    sVec4_169570 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(v), "r"(m)
        : "memory");
    return r;
}

static inline sVec4_169570 Sub_169570(const sVec4_169570& a, const sVec4_169570& b)
{
    sVec4_169570 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_169570(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

static inline float Atan2_169570(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

struct sVec2_169570 {
    float x, y;
    sVec2_169570(float ax, float ay) : x(ax), y(ay) {}
};

static inline float Length_169570(const sVec2_169570& v)
{
    return Sqrt_169570(v.x * v.x + v.y * v.y);
}

struct sScrCam_169570 {
    float roll;             // 0x0
    float x4;               // 0x4
    float x8;               // 0x8
    char padC[0x14];
    sVec4_169570 pos;       // 0x20
    sVec4_169570 target;    // 0x30
    float pitch;            // 0x40
    float yaw;              // 0x44
    float x48;              // 0x48
    float ox, oy, oz;       // 0x4C
    float dist;             // 0x58
    float r5C;              // 0x5C
    float r60;              // 0x60
    float r64;              // 0x64
    float r68;              // 0x68
    float r6C;              // 0x6C
    float r70;              // 0x70
};

extern "C" void func_00169570(char* p)
{
    sScrCam_169570* self = (sScrCam_169570*)p;
    char* cam = *(char**)(*(char**)(*(char**)(p + 0x14) + 0x14) + 0x8);
    float* f = func_0027C098(cam);
    char* m = *(char**)(p + 0x14) + 0x30;
    self->x4 = f[0];
    self->x8 = f[1];
    func_0027C0F0(cam, &self->ox);
    self->roll = self->r68 * 0.01745329424738884f;
    self->target = sVec4_169570(self->ox, self->oy, self->oz, 1.0f);
    self->target = mtxMulVec_169570(m, self->target);
    self->pitch = self->r64 * 0.01745329424738884f + *(float*)(*(char**)(p + 0x14) + 0x70);
    self->pos = mtxMulVec_169570(m, sVec4_169570(self->dist, self->r5C, self->r60, 1.0f));
    sVec4_169570 d = Sub_169570(self->pos, self->target);
    self->yaw = Atan2_169570(d.y, d.x);
    float h = Length_169570(sVec2_169570(d.x, d.y));
    self->x48 = Atan2_169570(d.z, h);
    func_00160028(p + 0x74, self->r6C);
    func_00160130(p + 0x74, self->r70);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169828);
#ifdef SKIP_ASM
struct sV_9828 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_9828 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPair_9828 {
    sV_9828 a;
    sV_9828 b;
};

extern sM_9828 D_004FF1A0_9828 __asm__("D_004FF1A0");
extern sV_9828 D_004FF140_9828 __asm__("D_004FF140");
extern sV_9828 D_004FF150_9828 __asm__("D_004FF150");
extern sV_9828 D_004FF160_9828 __asm__("D_004FF160");
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" sPair_9828 func_0031B748_9828(sM_9828* m) __asm__("func_0031B748");
extern "C" sV_9828 func_00160228_9828(char* p, float a, float b) __asm__("func_00160228");
extern "C" float func_001603F0(void* self);

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_9828(sM_9828* dst, const sM_9828* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_9828(sM_9828* dst, const sM_9828* a, const sM_9828* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_9828(sM_9828* m, const sV_9828& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV_9828 Add_9828(const sV_9828& a, const sV_9828& b)
{
    sV_9828 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline void SinCos_9828(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void RotAxis_9828(sM_9828* m, const sV_9828& axis, float angle)
{
    sM_9828 r;
    float s;
    float c;
    float one = 1.0f;
    SinCos_9828(&s, &c, angle);
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    r.m[3][3] = one;
    vu0MulMtx_9828(m, m, &r);
}

extern "C" sPair_9828 func_00169828(char* p)
{
    sM_9828 m;
    vu0CopyMtx_9828(&m, &D_004FF1A0_9828);
    vu0TransMtx_9828(&m, Add_9828(*(sV_9828*)(p + 0x30), func_00160228_9828(p + 0x74, *(float*)(p + 0x44), *(float*)(p + 0x48))));
    RotAxis_9828(&m, D_004FF140_9828, *(float*)(p + 0x40) + func_001603F0(p + 0x74));
    RotAxis_9828(&m, D_004FF150_9828, -*(float*)(p + 0x48));
    RotAxis_9828(&m, D_004FF160_9828, *(float*)(p + 0x44));
    return func_0031B748_9828(&m);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/script/scriptcontroller", func_00169CF8);
#ifdef SKIP_ASM
extern void* D_0045C7E8[];
extern func_001694B8_sVec4 D_004FF130;
extern "C" void* func_00169418(void* self);
extern "C" void* func_0015FFF0(void* self);

extern "C" void* func_00169CF8(void* self)
{
    func_00169418(self);
    *(void***)((char*)self + 0x10) = D_0045C7E8;
    func_0015FFF0((char*)self + 0x74);
    *(func_001694B8_sVec4*)((char*)self + 0x30) = D_004FF130;
    *(int*)((char*)self + 0xC) = 0x57;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x48) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169D58);
#ifdef SKIP_ASM
extern "C" void func_00169D58(cScriptCtlVirt* self)
{
    self->v05();
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169D80);
#ifdef SKIP_ASM
extern "C" void func_00169D80(cScriptCtlVirt2* self)
{
    self->v03(0);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169DB0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; needs a C fallback off-PS2.
float* func_0027C2A8(void* cam);
extern "C" void func_0027C300(void* cam, void* out);
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" void func_00160028(void* self, float v);
extern "C" void func_00160130(void* self, float v);

struct sVec4_169DB0 {
    float x, y, z, w;
    sVec4_169DB0() {}
    sVec4_169DB0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

static inline sVec4_169DB0 mtxMulVec_169DB0(char* m, const sVec4_169DB0& v)
{
    sVec4_169DB0 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(v), "r"(m)
        : "memory");
    return r;
}

static inline sVec4_169DB0 Scale_169DB0(const sVec4_169DB0& v, float s)
{
    sVec4_169DB0 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sVec4_169DB0 Sub_169DB0(const sVec4_169DB0& a, const sVec4_169DB0& b)
{
    sVec4_169DB0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

struct sScrCam_169DB0 {
    float roll;             // 0x0
    float x4;               // 0x4
    float x8;               // 0x8
    char padC[0x14];
    sVec4_169DB0 pos;       // 0x20
    sVec4_169DB0 target;    // 0x30
    float pitch;            // 0x40
    float yaw;              // 0x44
    float x48;              // 0x48
    float ox, oy, oz;       // 0x4C
    float dist;             // 0x58
    float r5C;              // 0x5C
    float r60;              // 0x60
    float r64;              // 0x64
    float r68;              // 0x68
    float r6C;              // 0x6C
    float r70;              // 0x70
};

extern "C" void func_00169DB0(char* p)
{
    sScrCam_169DB0* self = (sScrCam_169DB0*)p;
    char* cam = *(char**)(*(char**)(*(char**)(p + 0x14) + 0x14) + 0x8);
    float* f = func_0027C2A8(cam);
    char* m = *(char**)(p + 0x14) + 0x30;
    self->x4 = f[0];
    self->x8 = f[1];
    func_0027C300(cam, &self->ox);
    self->x4 = f[0];
    self->x8 = f[1];
    self->roll = self->r68 * 0.01745329424738884f;
    char* g = *(char**)(p + 0x14);
    self->yaw = self->r60 * 0.01745329424738884f + *(float*)(g + 0x78);
    self->x48 = self->r5C * 0.01745329424738884f + *(float*)(g + 0x74);
    self->pitch = self->r64 * 0.01745329424738884f + *(float*)(g + 0x70);
    self->pos = mtxMulVec_169DB0(m, sVec4_169DB0(self->ox, self->oy, self->oz, 1.0f));
    float s0, c0, s1, c1;
    func_0031BE50(&s0, &c0, self->yaw);
    func_0031BE50(&s1, &c1, self->x48);
    sVec4_169DB0 d(c1 * c0, c1 * s0, s1, 0.0f);
    self->target = Sub_169DB0(self->pos, Scale_169DB0(d, self->dist));
    func_00160028(p + 0x74, self->r6C);
    func_00160130(p + 0x74, self->r70);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_00169F88);
#ifdef SKIP_ASM
struct sV_9F88 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_9F88 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPair_9F88 {
    sV_9F88 a;
    sV_9F88 b;
};

extern sM_9F88 D_004FF1A0_9F88 __asm__("D_004FF1A0");
extern sV_9F88 D_004FF140_9F88 __asm__("D_004FF140");
extern sV_9F88 D_004FF150_9F88 __asm__("D_004FF150");
extern sV_9F88 D_004FF160_9F88 __asm__("D_004FF160");
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" sPair_9F88 func_0031B748_9F88(sM_9F88* m) __asm__("func_0031B748");
extern "C" sV_9F88 func_00160228_9F88(char* p, float a, float b) __asm__("func_00160228");
extern "C" float func_001603F0(void* self);

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_9F88(sM_9F88* dst, const sM_9F88* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_9F88(sM_9F88* dst, const sM_9F88* a, const sM_9F88* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_9F88(sM_9F88* m, const sV_9F88& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV_9F88 Add_9F88(const sV_9F88& a, const sV_9F88& b)
{
    sV_9F88 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline void SinCos_9F88(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void RotAxis_9F88(sM_9F88* m, const sV_9F88& axis, float angle)
{
    sM_9F88 r;
    float s;
    float c;
    float one = 1.0f;
    SinCos_9F88(&s, &c, angle);
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    r.m[3][3] = one;
    vu0MulMtx_9F88(m, m, &r);
}

extern "C" sPair_9F88 func_00169F88(char* p)
{
    sM_9F88 m;
    vu0CopyMtx_9F88(&m, &D_004FF1A0_9F88);
    vu0TransMtx_9F88(&m, Add_9F88(*(sV_9F88*)(p + 0x30), func_00160228_9F88(p + 0x74, *(float*)(p + 0x44), *(float*)(p + 0x48))));
    RotAxis_9F88(&m, D_004FF140_9F88, *(float*)(p + 0x40) + func_001603F0(p + 0x74));
    RotAxis_9F88(&m, D_004FF150_9F88, -*(float*)(p + 0x48));
    RotAxis_9F88(&m, D_004FF160_9F88, *(float*)(p + 0x44));
    return func_0031B748_9F88(&m);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/script/scriptcontroller", func_0016A458);
#ifdef SKIP_ASM
extern void* D_0045C780[];
extern func_001694B8_sVec4 D_004FF130;
extern "C" void* func_00169418(void* self);
extern "C" void* func_0015FFF0(void* self);

extern "C" void* func_0016A458(void* self)
{
    func_00169418(self);
    *(void***)((char*)self + 0x10) = D_0045C780;
    func_0015FFF0((char*)self + 0x70);
    *(func_001694B8_sVec4*)((char*)self + 0x30) = D_004FF130;
    *(int*)((char*)self + 0xC) = 0x58;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x48) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016A4B8);
#ifdef SKIP_ASM
extern "C" void func_0016A4B8(cScriptCtlVirt* self)
{
    self->v05();
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016A4E0);
#ifdef SKIP_ASM
extern "C" void func_0016A4E0(cScriptCtlVirt2* self)
{
    self->v03(0);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016A510);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; needs a C fallback off-PS2.
float* func_0027C4B8(void* cam);
extern "C" char* func_00279F18(void* self, int a1, int a2);
extern "C" void func_0027C510(void* cam, void* out);
extern "C" float func_0031C228(float x);
extern "C" void func_00160028(void* self, float v);
extern "C" void func_00160130(void* self, float v);
extern void* D_004A28A4;
extern void* D_004A28A8;

struct sVec4_16A510 {
    float x, y, z, w;
    sVec4_16A510() {}
    sVec4_16A510(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

static inline sVec4_16A510 mtxMulVec_16A510(char* m, const sVec4_16A510& v)
{
    sVec4_16A510 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(v), "r"(m)
        : "memory");
    return r;
}

static inline sVec4_16A510 Scale_16A510(const sVec4_16A510& v, float s)
{
    sVec4_16A510 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sVec4_16A510 Add_16A510(const sVec4_16A510& a, const sVec4_16A510& b)
{
    sVec4_16A510 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline sVec4_16A510 Sub_16A510(const sVec4_16A510& a, const sVec4_16A510& b)
{
    sVec4_16A510 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_16A510(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

static inline float Atan2_16A510(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

static inline sVec4_16A510 vec_16A510(char* p)
{
    return *(sVec4_16A510*)p;
}

struct sVec2_16A510 {
    float x, y;
    sVec2_16A510(float ax, float ay) : x(ax), y(ay) {}
};

static inline float Length_16A510(const sVec2_16A510& v)
{
    return Sqrt_16A510(v.x * v.x + v.y * v.y);
}

struct sScrCam_16A510 {
    float roll;             // 0x0
    float x4;               // 0x4
    float x8;               // 0x8
    char padC[0x14];
    sVec4_16A510 pos;       // 0x20
    sVec4_16A510 target;    // 0x30
    float pitch;            // 0x40
    float yaw;              // 0x44
    float x48;              // 0x48
    float ox, oy, oz;       // 0x4C
    float dist;             // 0x58
    float r5C;              // 0x5C
    float r60;              // 0x60
    float r64;              // 0x64
    float r68;              // 0x68
    float r6C;              // 0x6C
};

struct sVEp_16A510 {
    short delta;
    short index;
    sVec4_16A510* (*fn)(void*);
};

extern "C" void func_0016A510(char* p)
{
    sScrCam_16A510* self = (sScrCam_16A510*)p;
    char* cam = *(char**)(*(char**)(*(char**)(p + 0x14) + 0x14) + 0x8);
    float* f = func_0027C4B8(cam);
    char* m = *(char**)(p + 0x14) + 0x30;
    char* rider = func_00279F18(D_004A28A4, ((signed char*)f)[0x22], *(int*)(cam + 8));
    if (rider == 0) {
        rider = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x28);
    }
    self->x4 = f[0];
    self->x8 = f[1];
    func_0027C510(cam, &self->ox);
    char* obj = rider + 0x6C0;
    sVec4_16A510 rot = *(sVec4_16A510*)(*(char**)(rider + 0x780) + 0x140);
    self->roll = self->r64 * 0.01745329424738884f;
    self->pitch = self->r60 * 0.01745329424738884f + *(float*)(*(char**)(p + 0x14) + 0x70);
    self->target = sVec4_16A510(self->ox, self->oy, self->oz, self->target.w);
    self->target = mtxMulVec_16A510(m, self->target);
    sVEp_16A510* vt = *(sVEp_16A510**)obj;
    sVec4_16A510* rp = vt[5].fn(obj + vt[5].delta);
    self->pos = Add_16A510(Add_16A510(*rp, Scale_16A510(vec_16A510(rider + 0x1B0), self->dist * rot.y)),
                               Scale_16A510(vec_16A510(rider + 0x1C0), self->r5C * rot.x));
    sVec4_16A510 t = Sub_16A510(self->pos, self->target);
    self->yaw = Atan2_16A510(t.y, t.x);
    float h = Length_16A510(sVec2_16A510(t.x, t.y));
    self->x48 = Atan2_16A510(t.z, h);
    func_00160028(p + 0x70, self->r68);
    func_00160130(p + 0x70, self->r6C);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016A868);
#ifdef SKIP_ASM
struct sV_A868 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_A868 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPair_A868 {
    sV_A868 a;
    sV_A868 b;
};

extern sM_A868 D_004FF1A0_A868 __asm__("D_004FF1A0");
extern sV_A868 D_004FF140_A868 __asm__("D_004FF140");
extern sV_A868 D_004FF150_A868 __asm__("D_004FF150");
extern sV_A868 D_004FF160_A868 __asm__("D_004FF160");
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" sPair_A868 func_0031B748_A868(sM_A868* m) __asm__("func_0031B748");
extern "C" sV_A868 func_00160228_A868(char* p, float a, float b) __asm__("func_00160228");
extern "C" float func_001603F0(void* self);

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_A868(sM_A868* dst, const sM_A868* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_A868(sM_A868* dst, const sM_A868* a, const sM_A868* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_A868(sM_A868* m, const sV_A868& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV_A868 Add_A868(const sV_A868& a, const sV_A868& b)
{
    sV_A868 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline void SinCos_A868(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void RotAxis_A868(sM_A868* m, const sV_A868& axis, float angle)
{
    sM_A868 r;
    float s;
    float c;
    float one = 1.0f;
    SinCos_A868(&s, &c, angle);
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    r.m[3][3] = one;
    vu0MulMtx_A868(m, m, &r);
}

extern "C" sPair_A868 func_0016A868(char* p)
{
    sM_A868 m;
    vu0CopyMtx_A868(&m, &D_004FF1A0_A868);
    vu0TransMtx_A868(&m, Add_A868(*(sV_A868*)(p + 0x30), func_00160228_A868(p + 0x70, *(float*)(p + 0x44), *(float*)(p + 0x48))));
    RotAxis_A868(&m, D_004FF140_A868, *(float*)(p + 0x40) + func_001603F0(p + 0x70));
    RotAxis_A868(&m, D_004FF150_A868, -*(float*)(p + 0x48));
    RotAxis_A868(&m, D_004FF160_A868, *(float*)(p + 0x44));
    return func_0031B748_A868(&m);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/script/scriptcontroller", func_0016AD38);
#ifdef SKIP_ASM
extern void* D_0045C718[];
extern func_001694B8_sVec4 D_004FF130;
extern "C" void* func_00169418(void* self);
extern "C" void* func_0015FFF0(void* self);

extern "C" void* func_0016AD38(void* self)
{
    func_00169418(self);
    *(void***)((char*)self + 0x10) = D_0045C718;
    func_0015FFF0((char*)self + 0x70);
    *(func_001694B8_sVec4*)((char*)self + 0x30) = D_004FF130;
    *(int*)((char*)self + 0xC) = 0x59;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x48) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016AD98);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm; needs a C fallback off-PS2.
float* func_0027C6A0(void* cam);
extern "C" char* func_00279F18(void* self, int a1, int a2);
extern "C" void func_0027C6F8(void* cam, void* out);
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" float func_0031C228(float x);
extern "C" void func_00160028(void* self, float v);
extern "C" void func_00160130(void* self, float v);
extern void* D_004A28A4;
extern void* D_004A28A8;

struct sVec4_16AD98 {
    float x, y, z, w;
    sVec4_16AD98() {}
    sVec4_16AD98(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

static inline sVec4_16AD98 mtxMulVec_16AD98(char* m, const sVec4_16AD98& v)
{
    sVec4_16AD98 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(v), "r"(m)
        : "memory");
    return r;
}

static inline sVec4_16AD98 Scale_16AD98(const sVec4_16AD98& v, float s)
{
    sVec4_16AD98 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sVec4_16AD98 Add_16AD98(const sVec4_16AD98& a, const sVec4_16AD98& b)
{
    sVec4_16AD98 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline sVec4_16AD98 Sub_16AD98(const sVec4_16AD98& a, const sVec4_16AD98& b)
{
    sVec4_16AD98 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_16AD98(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

static inline float Atan2_16AD98(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

static inline sVec4_16AD98 vec_16AD98(char* p)
{
    return *(sVec4_16AD98*)p;
}

struct sVec2_16AD98 {
    float x, y;
    sVec2_16AD98(float ax, float ay) : x(ax), y(ay) {}
};

static inline float Length_16AD98(const sVec2_16AD98& v)
{
    return Sqrt_16AD98(v.x * v.x + v.y * v.y);
}

struct sScrCam_16AD98 {
    float roll;             // 0x0
    float x4;               // 0x4
    float x8;               // 0x8
    char padC[0x14];
    sVec4_16AD98 pos;       // 0x20
    sVec4_16AD98 target;    // 0x30
    float pitch;            // 0x40
    float yaw;              // 0x44
    float x48;              // 0x48
    float ox, oy, oz;       // 0x4C
    float dist;             // 0x58
    float r5C;              // 0x5C
    float r60;              // 0x60
    float r64;              // 0x64
    float r68;              // 0x68
    float r6C;              // 0x6C
};

struct sVEp_16AD98 {
    short delta;
    short index;
    sVec4_16AD98* (*fn)(void*);
};

extern "C" void func_0016AD98(char* p)
{
    sScrCam_16AD98* self = (sScrCam_16AD98*)p;
    char* cam = *(char**)(*(char**)(*(char**)(p + 0x14) + 0x14) + 0x8);
    float* f = func_0027C6A0(cam);
    func_0027C6F8(cam, &self->ox);
    self->x4 = f[0];
    self->x8 = f[1];
    self->roll = self->r64 * 0.01745329424738884f;
    self->pitch = self->r60 * 0.01745329424738884f + *(float*)(*(char**)(p + 0x14) + 0x70);
    char* rider = func_00279F18(D_004A28A4, ((signed char*)f)[0x1D], *(int*)(cam + 8));
    if (rider == 0) {
        rider = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x28);
    }
    char* obj = rider + 0x6C0;
    sVec4_16AD98 rot = *(sVec4_16AD98*)(*(char**)(rider + 0x780) + 0x140);
    sVEp_16AD98* vt = *(sVEp_16AD98**)obj;
    sVec4_16AD98* rp = vt[5].fn(obj + vt[5].delta);
    self->pos = Add_16AD98(Add_16AD98(*rp, Scale_16AD98(vec_16AD98(rider + 0x1B0), self->ox * rot.y)),
                           Scale_16AD98(vec_16AD98(rider + 0x1C0), self->oy * rot.x));
    float yaw;
    float pit;
    float k;
    if (((signed char*)f)[0x1E] == 0) {
        sVec4_16AD98 v = vec_16AD98(rider + 0x1B0);
        sVec4_16AD98* pv = &v;
        float a = self->dist * 0.01745329424738884f;
        yaw = Atan2_16AD98(v.z, Length_16AD98(sVec2_16AD98(v.x, v.y))) - a;
        float b = self->r5C * 0.01745329424738884f;
        pit = b + Atan2_16AD98(pv->y, pv->x);
        k = self->oz;
    } else {
        yaw = self->dist * 0.01745329424738884f;
        pit = self->r5C * 0.01745329424738884f;
        k = self->oz;
    }
    float s0, c0, s1, c1;
    char* g = *(char**)(p + 0x14);
    pit += *(float*)(g + 0x78);
    yaw += *(float*)(g + 0x74);
    func_0031BE50(&s0, &c0, pit);
    func_0031BE50(&s1, &c1, yaw);
    sVec4_16AD98 d(c1 * c0, c1 * s0, -s1, 0.0f);
    self->target = Sub_16AD98(self->pos, Scale_16AD98(d, k));
    func_00160028(p + 0x70, self->r68);
    func_00160130(p + 0x70, self->r6C);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016B150);
#ifdef SKIP_ASM
extern "C" void func_0016B150(cScriptCtlVirt2* self)
{
    self->v03(0);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016B180);
#ifdef SKIP_ASM
struct sVec4_B180 {
    float x, y, z, w;
    sVec4_B180() {}
    sVec4_B180(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

static inline sVec4_B180 mtxMulVec_B180(char* m, const sVec4_B180& v)
{
    sVec4_B180 r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lqc2         $vf8, %1\n"
        "lqc2         $vf4, 0x0(%2)\n"
        "lqc2         $vf5, 0x10(%2)\n"
        "lqc2         $vf6, 0x20(%2)\n"
        "lqc2         $vf7, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, %0\n"
        ".set pop\n"
        : "=m"(r)
        : "m"(v), "r"(m)
        : "memory");
    return r;
}

static inline sVec4_B180 Scale_B180(const sVec4_B180& v, float s)
{
    sVec4_B180 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

static inline sVec4_B180 Add_B180(const sVec4_B180& a, const sVec4_B180& b)
{
    sVec4_B180 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline sVec4_B180 Sub_B180(const sVec4_B180& a, const sVec4_B180& b)
{
    sVec4_B180 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: sqrt.s (sqrtf without errno check)
static inline float Sqrt_B180(float v)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

static inline float Atan2_B180(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f) return y;
        if (y >= 0.0f) return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f) r += 3.1415927410125732f;
        else r -= 3.1415927410125732f;
    }
    return r;
}

static inline sVec4_B180 vec_B180(char* p)
{
    return *(sVec4_B180*)p;
}

struct sVec2_B180 {
    float x, y;
    sVec2_B180(float ax, float ay) : x(ax), y(ay) {}
};

static inline float Length_B180(const sVec2_B180& v)
{
    return Sqrt_B180(v.x * v.x + v.y * v.y);
}

struct sScrCam_B180 {
    float roll;             // 0x0
    float x4;               // 0x4
    float x8;               // 0x8
    char padC[0x14];
    sVec4_B180 pos;       // 0x20
    sVec4_B180 target;    // 0x30
    float pitch;            // 0x40
    float yaw;              // 0x44
    float x48;              // 0x48
    float ox, oy, oz;       // 0x4C
    float dist;             // 0x58
    float r5C;              // 0x5C
    float r60;              // 0x60
    float r64;              // 0x64
    float r68;              // 0x68
    float r6C;              // 0x6C
};

struct sVEp_B180 {
    short delta;
    short index;
    sVec4_B180* (*fn)(void*);
};

// PORT: PS2-only VU0 inline asm (normalize via rsqrt).
static inline sVec4_B180 Normalize_B180(const sVec4_B180& v)
{
    sVec4_B180 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vrsqrt    Q, $vf0w, $vf4x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf5, $vf3, Q\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length4_B180(const sVec4_B180& v)
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

extern "C" void func_0016B180(char* p)
{
    sScrCam_B180* self = (sScrCam_B180*)p;
    char* cam = *(char**)(*(char**)(*(char**)(p + 0x14) + 0x14) + 0x8);
    float* f = func_0027C6A0(cam);
    char* rider = func_00279F18(D_004A28A4, ((signed char*)f)[0x1D], *(int*)(cam + 8));
    if (rider == 0) {
        rider = *(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x28);
    }
    self->x4 = f[0];
    self->x8 = f[1];
    func_0027C6F8(cam, &self->ox);
    self->roll = self->r64 * 0.01745329424738884f;
    self->pitch = self->r60 * 0.01745329424738884f + *(float*)(*(char**)(p + 0x14) + 0x70);
    float yaw;
    float pit;
    float k;
    if (((signed char*)f)[0x1E] == 0) {
        sVec4_B180 v = vec_B180(rider + 0x1B0);
        sVec4_B180* pv = &v;
        float a = self->dist * 0.01745329424738884f;
        yaw = Atan2_B180(v.z, Length_B180(sVec2_B180(v.x, v.y))) - a;
        float b = self->r5C * 0.01745329424738884f;
        pit = b + Atan2_B180(pv->y, pv->x);
        k = self->oz;
    } else {
        yaw = self->dist * 0.01745329424738884f;
        pit = self->r5C * 0.01745329424738884f;
        k = self->oz;
    }
    char* obj = rider + 0x6C0;
    char* g = *(char**)(p + 0x14);
    yaw += *(float*)(g + 0x74);
    pit += *(float*)(g + 0x78);
    sVec4_B180 rot = *(sVec4_B180*)(*(char**)(rider + 0x780) + 0x140);
    sVEp_B180* vt = *(sVEp_B180**)obj;
    sVec4_B180* rp = vt[5].fn(obj + vt[5].delta);
    self->pos = Add_B180(Add_B180(*rp, Scale_B180(vec_B180(rider + 0x1B0), self->ox * rot.y)),
                         Scale_B180(vec_B180(rider + 0x1C0), self->oy * rot.x));
    float s0, c0, s1, c1;
    func_0031BE50(&s0, &c0, pit);
    func_0031BE50(&s1, &c1, yaw);
    sVec4_B180 d(c1 * c0, c1 * s0, -s1, 0.0f);
    sVec4_B180 t = Sub_B180(self->pos, Scale_B180(d, k));
    sVec4_B180 nt = Add_B180(Scale_B180(t, f[5]), Scale_B180(self->target, 1.0f - f[5]));
    nt.w = 1.0f;
    sVec4_B180 dv = Sub_B180(nt, self->target);
    float maxd = f[6];
    if (maxd < Length4_B180(dv) * 59.999996185302734f) {
        self->target = Add_B180(self->target, Scale_B180(Normalize_B180(dv), maxd * 0.01666666753590107f));
        self->target.w = 1.0f;
    } else {
        self->target = nt;
    }
    sVec4_B180 t2 = Sub_B180(self->pos, self->target);
    self->yaw = Atan2_B180(t2.y, t2.x);
    float h = Length_B180(sVec2_B180(t2.x, t2.y));
    self->x48 = Atan2_B180(t2.z, h);
    func_00160028(p + 0x70, self->r68);
    func_00160130(p + 0x70, self->r6C);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016B7B8);
#ifdef SKIP_ASM
struct sV_B7B8 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sM_B7B8 {
    float m[4][4];
} __attribute__((aligned(16)));

struct sPair_B7B8 {
    sV_B7B8 a;
    sV_B7B8 b;
};

extern sM_B7B8 D_004FF1A0_B7B8 __asm__("D_004FF1A0");
extern sV_B7B8 D_004FF140_B7B8 __asm__("D_004FF140");
extern sV_B7B8 D_004FF150_B7B8 __asm__("D_004FF150");
extern sV_B7B8 D_004FF160_B7B8 __asm__("D_004FF160");
extern "C" void func_0031BE50(float* s, float* c, float angle);
extern "C" sPair_B7B8 func_0031B748_B7B8(sM_B7B8* m) __asm__("func_0031B748");
extern "C" sV_B7B8 func_00160228_B7B8(char* p, float a, float b) __asm__("func_00160228");
extern "C" float func_001603F0(void* self);

// PORT: PS2-only VU0 inline asm (64-byte matrix copy).
static inline void vu0CopyMtx_B7B8(sM_B7B8* dst, const sM_B7B8* src)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(src)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (4x4 matrix multiply, dst = a * b).
static inline void vu0MulMtx_B7B8(sM_B7B8* dst, const sM_B7B8* a, const sM_B7B8* b)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "lqc2      $vf8, 0x0(%2)\n"
        "lqc2      $vf9, 0x10(%2)\n"
        "lqc2      $vf10, 0x20(%2)\n"
        "lqc2      $vf11, 0x30(%2)\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw  ACC, $vf4, $vf9x\n"
        "vmadday.xyzw ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw  $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw  ACC, $vf4, $vf10x\n"
        "vmadday.xyzw ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw  $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw  ACC, $vf4, $vf11x\n"
        "vmadday.xyzw ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw  $vf15, $vf7, $vf11w\n"
        "sqc2      $vf12, 0x0(%0)\n"
        "sqc2      $vf13, 0x10(%0)\n"
        "sqc2      $vf14, 0x20(%0)\n"
        "sqc2      $vf15, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(dst), "r"(a), "r"(b)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (row 3 of m = m * v).
static inline void vu0TransMtx_B7B8(sM_B7B8* m, const sV_B7B8& v)
{
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2         $vf4, 0x0(%0)\n"
        "lqc2         $vf5, 0x10(%0)\n"
        "lqc2         $vf6, 0x20(%0)\n"
        "lqc2         $vf7, 0x30(%0)\n"
        "lqc2         $vf8, %1\n"
        "vmulax.xyzw  ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw  $vf12, $vf7, $vf8w\n"
        "sqc2         $vf12, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"(m), "m"(v)
        : "memory");
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sV_B7B8 Add_B7B8(const sV_B7B8& a, const sV_B7B8& b)
{
    sV_B7B8 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline void SinCos_B7B8(float* s, float* c, float angle)
{
    func_0031BE50(s, c, angle);
}

static inline void RotAxis_B7B8(sM_B7B8* m, const sV_B7B8& axis, float angle)
{
    sM_B7B8 r;
    float s;
    float c;
    float one = 1.0f;
    SinCos_B7B8(&s, &c, angle);
    float t = one - c;
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    r.m[0][0] = tx * x + c;
    r.m[1][0] = tx * y + sz;
    r.m[2][0] = tx * z - sy;
    r.m[0][1] = ty * x - sz;
    r.m[1][1] = ty * y + c;
    r.m[2][1] = ty * z + sx;
    r.m[0][2] = tz * x + sy;
    r.m[1][2] = tz * y - sx;
    r.m[2][2] = tz * z + c;
    r.m[3][0] = 0.0f;
    r.m[3][1] = 0.0f;
    r.m[3][2] = 0.0f;
    r.m[0][3] = 0.0f;
    r.m[1][3] = 0.0f;
    r.m[2][3] = 0.0f;
    r.m[3][3] = one;
    vu0MulMtx_B7B8(m, m, &r);
}

extern "C" sPair_B7B8 func_0016B7B8(char* p)
{
    sM_B7B8 m;
    vu0CopyMtx_B7B8(&m, &D_004FF1A0_B7B8);
    vu0TransMtx_B7B8(&m, Add_B7B8(*(sV_B7B8*)(p + 0x30), func_00160228_B7B8(p + 0x70, *(float*)(p + 0x44), *(float*)(p + 0x48))));
    RotAxis_B7B8(&m, D_004FF140_B7B8, *(float*)(p + 0x40) + func_001603F0(p + 0x70));
    RotAxis_B7B8(&m, D_004FF150_B7B8, -*(float*)(p + 0x48));
    RotAxis_B7B8(&m, D_004FF160_B7B8, *(float*)(p + 0x44));
    return func_0031B748_B7B8(&m);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BC88);
#ifdef SKIP_ASM
// PORT: `<?` (GNU min operator) gives the target's min.s
static inline float ClampF_BC88b(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

extern "C" void func_0016BC88(float* p)
{
    *p = ClampF_BC88b(*p, 5.0f, 80.0f);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BCB8);
#ifdef SKIP_ASM
// PORT: `<?` (GNU min operator) gives the target's min.s
static inline float ClampF_BC88(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

extern "C" void func_0016BCB8(float* p)
{
    *p = ClampF_BC88(*p, -3000.0f, 3000.0f);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BCE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_BCE0(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

extern "C" void func_0016BCE0(float* p)
{
    float a = *p;
    float n = ffloor_BCE0(a * 0.15915493667125702f + 0.5f);
    *p = a - n * 6.2831854820251465f;
}
#endif
//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BD30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm (EE cvt.w.s truncates in the FPU; the C cast goes through a GPR).
static inline float ffloor_BD30(float x)
{
    float t;
    __asm__("cvt.w.s %0,%1\n\tcvt.s.w %0,%0" : "=f"(t) : "f"(x));
    if (x < t) {
        t -= 1.0f;
    }
    return t;
}

// PORT: `<?` (GNU min operator) gives the target's min.s
static inline float Clamp_BD30(float v, float lo, float hi)
{
    if (v >= lo) {
        return v <? hi;
    }
    return lo;
}

static inline float Wrap_BD30(float a)
{
    float n = ffloor_BD30(a * 0.15915493667125702f + 0.5f);
    return a - n * 6.2831854820251465f;
}

extern "C" void func_0016BD30(float* p)
{
    float w = Wrap_BD30(*p);
    *p = w;
    *p = Clamp_BD30(w, -1.5707963705062866f, 1.5707963705062866f);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BDA0);
#ifdef SKIP_ASM
extern "C" void func_0016BCE0(float* p);

extern "C" void func_0016BDA0(float* p)
{
    float r = *p * 0.01745329424738884f;
    func_0016BCE0(&r);
    *p = r * 57.2957763671875f;
}
#endif
//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BDE8);
#ifdef SKIP_ASM
extern "C" void func_0016BD30(float* p);

extern "C" void func_0016BDE8(float* p)
{
    float r = *p * 0.01745329424738884f;
    func_0016BD30(&r);
    *p = r * 57.2957763671875f;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BE30);
#ifdef SKIP_ASM
extern "C" void func_0016BE30(float* p)
{
    *p = ClampF_BC88(*p, -180.0f, 180.0f);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BE60);
#ifdef SKIP_ASM
extern "C" void func_0016BE60(float* p)
{
    *p = ClampF_BC88(*p, 0.0f, 10.0f);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BE90);
#ifdef SKIP_ASM
extern "C" void func_0016BE90(float* p)
{
    *p = ClampF_BC88(*p, 0.0f, 30.0f);
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BEC0);
#ifdef SKIP_ASM
extern "C" void func_0016BEC0(float* p)
{
    *p = ClampF_BC88(*p, -10000.0f, 10000.0f);
}
#endif
//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BEE8__FPv);
#ifdef SKIP_ASM
void* func_0016BEE8(void* self)
{
    *(int*)self = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("camera/script/scriptcontroller", func_0016BEF8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_0016BEF8(void* self, int flags)
{
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

