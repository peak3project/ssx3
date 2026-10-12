#include "common.h"

//100%
INCLUDE_ASM("input/inputparse", cInputMapParser_lookupModifierName);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);
extern char D_004A3EF8[];
extern char D_004A3F00[];
extern char D_004A3F08[];
extern char D_0048DDD8[];
extern char D_004A3F10[];

extern "C" int cInputMapParser_lookupModifierName(void* self, const char* name)
{
    if (func_0041AA88(name, D_004A3EF8) == 0) {
        return 0;
    }
    if (func_0041AA88(name, D_004A3F00) == 0) {
        return 1;
    }
    if (func_0041AA88(name, D_004A3F08) == 0) {
        return 2;
    }
    if (func_0041AA88(name, D_0048DDD8) == 0) {
        return 3;
    }
    int c = func_0041AA88(name, D_004A3F10);
    int r = 4;
    if (c != 0) {
        r = 6;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", cInputMapParser_lookupConfigName);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" int func_0041AB78(const char* a, const char* b, int n);
extern char D_004A3F18[];
extern char D_004A3F20[];
extern char D_004A3F28[];

extern "C" int cInputMapParser_lookupConfigName(void* self, char* name)
{
    if (func_0041AA88(name, D_004A3F18) == 0)
        return 0;
    if (func_0041AB78(name, D_004A3F20, 3) == 0) {
        int d = name[3] - '0';
        if ((unsigned char)d < 10) {
            int n = d;
            char* p = name + 4;
            while ((unsigned)(*p - '0') < 10) {
                n = n * 10 + (*p++ - '0');
            }
            int alpha = 0;
            if ((unsigned)(*p - 'a') < 26 || (unsigned)(*p - 'A') < 26) {
                alpha = 1;
            }
            if (!alpha) {
                if (*p != '_' && n < 8) {
                    return n + 1;
                }
            }
        }
    }
    if (func_0041AB78(name, D_004A3F28, 6) != 0) {
        return -1;
    }
    int d = name[6] - '0';
    if ((unsigned char)d >= 10) {
        return -1;
    }
    int n = d;
    char* p = name + 7;
    while ((unsigned)(*p - '0') < 10) {
        n = n * 10 + (*p++ - '0');
    }
    int alpha = 0;
    if ((unsigned)(*p - 'a') < 26 || (unsigned)(*p - 'A') < 26) {
        alpha = 1;
    }
    if (alpha) {
        return -1;
    }
    if (*p != '_' && n < 23) {
        return n + 9;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00321A40);
#ifdef SKIP_ASM
struct sEntry_321A40 {
    char name[0x40];
    int value;
};
struct sTable_321A40 {
    char pad[0x80E4];
    int count;
    sEntry_321A40 entries[1];
};
extern "C" int func_0041AA88(const char* a, const char* b);

extern "C" sEntry_321A40* func_00321A40(sTable_321A40* self, const char* name)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (func_0041AA88(name, self->entries[i].name) == 0) {
            return &self->entries[i];
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00321AD0);
#ifdef SKIP_ASM
extern "C" void* func_00321AD0(void* self, void* a1)
{
    return (char*)a1 + 0x40;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00321AD8);
#ifdef SKIP_ASM
extern "C" int func_00321AD8(void* self, int a1, int a2)
{
    return a1 * 6 + a2 + 0x60;
}
#endif

INCLUDE_ASM("input/inputparse", cInputMapParser_readToken);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", func_00323098);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void cInputMapParser_parseStatement(void* self);

extern "C" void func_00323098(void* self)
{
    cInputMapParser_readToken(self);
    while (*(int*)((char*)self + 0x98) != 0) {
        cInputMapParser_parseStatement(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", cInputMapParser_parseStatement);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_00321500(void* self, const char* fmt, ...);
extern "C" void func_00321590(void* self);
extern "C" int func_003216E8(void* self, char* name);
extern "C" int cInputMapParser_lookupConfigName(void* self, char* name);
extern "C" void* cInputMapParser_parseExpression(void* self);
extern char D_0048DED0[];
extern char D_0048DEF8[];
extern char D_0048DF20[];
extern char D_0048DF48[];
extern char D_0048DF68[];
extern char D_0048DF88[];

struct sMapEntry_003230E0 {
    char name[0x40];
    void* expr;         // 0x40
};
struct sMapParser_003230E0 {
    char pad0[0x98];
    int tok;                            // 0x98
    char name[0x8048];                  // 0x9C
    int count;                          // 0x80E4
    sMapEntry_003230E0 entries[512];    // 0x80E8
    sMapEntry_003230E0* cur;            // 0x108E8
};

extern "C" void cInputMapParser_parseStatement(void* p)
{
    sMapParser_003230E0* self = (sMapParser_003230E0*)p;
    if (self->tok != 2) {
        func_00321500(self, D_0048DED0);
        func_00321590(self);
        return;
    }
    char* name = self->name;
    if (func_003216E8(self, name) >= 0) {
        func_00321500(self, D_0048DEF8, name);
        func_00321590(self);
        return;
    }
    if (cInputMapParser_lookupConfigName(self, name) >= 0) {
        func_00321500(self, D_0048DF20, name);
        func_00321590(self);
        return;
    }
    if (func_00321A40((sTable_321A40*)self, name) != 0) {
        func_00321500(self, D_0048DF48, name);
        func_00321590(self);
        return;
    }
    sMapEntry_003230E0* e = &self->entries[self->count];
    self->cur = e;
    strcpy(e->name, name);
    cInputMapParser_readToken(self);
    if (self->tok != 3) {
        func_00321500(self, D_0048DF68);
        func_00321590(self);
        return;
    }
    cInputMapParser_readToken(self);
    if ((e->expr = cInputMapParser_parseExpression(self)) == 0) {
        func_00321590(self);
        return;
    }
    if (self->tok != 5) {
        func_00321500(self, D_0048DF88);
        func_00321590(self);
        return;
    }
    cInputMapParser_readToken(self);
    self->count++;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", cInputMapParser_parseExpression);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void func_00321500(void* self, const char* fmt, ...);
extern "C" void func_00321638(void* self, void* node);
extern "C" void* func_003215F8(void* self);
extern "C" void* func_003233B8(void* self);
extern char D_0048DFA8[];

struct sExprNode_00323268 {
    int type;
    union {
        float value;
        sExprNode_00323268* cond;
    };
    sExprNode_00323268* a;
    sExprNode_00323268* b;
};

extern "C" void* cInputMapParser_parseExpression(void* self)
{
    sExprNode_00323268* cond = (sExprNode_00323268*)func_003233B8(self);
    if (cond == 0) {
        return 0;
    }
    if (*(int*)((char*)self + 0x98) != 6) {
        return cond;
    }
    cInputMapParser_readToken(self);
    sExprNode_00323268* a = (sExprNode_00323268*)cInputMapParser_parseExpression(self);
    if (a == 0) {
        func_00321638(self, cond);
        return 0;
    }
    if (*(int*)((char*)self + 0x98) != 7) {
        func_00321500(self, D_0048DFA8);
        func_00321638(self, cond);
        func_00321638(self, a);
        return 0;
    }
    cInputMapParser_readToken(self);
    sExprNode_00323268* b = (sExprNode_00323268*)cInputMapParser_parseExpression(self);
    if (b == 0) {
        func_00321638(self, cond);
        func_00321638(self, a);
        return 0;
    }
    if (cond->type == 4) {
        if (cond->value != 0.0f) {
            func_00321638(self, b);
            return a;
        }
        func_00321638(self, a);
        return b;
    }
    sExprNode_00323268* n = (sExprNode_00323268*)func_003215F8(self);
    n->type = 5;
    n->cond = cond;
    n->a = a;
    n->b = b;
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", func_003233B8);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void func_00321638(void* self, void* node);
extern "C" void* func_003215F8(void* self);
extern "C" void* func_00323540(void* self);

struct sOrNode_003233B8 {
    int type;
    union {
        float value;
        sOrNode_003233B8* a;
    };
    sOrNode_003233B8* b;
};

extern "C" void* func_003233B8(void* self)
{
    sOrNode_003233B8* left = (sOrNode_003233B8*)func_00323540(self);
    if (left == 0) {
        return 0;
    }
    int isTrue = 0;
    if (left->type == 4 && left->value != 0.0f) {
        isTrue = 1;
    }
    while (*(int*)((char*)self + 0x98) == 0xC) {
        cInputMapParser_readToken(self);
        sOrNode_003233B8* right = (sOrNode_003233B8*)func_00323540(self);
        if (right == 0) {
            func_00321638(self, left);
            return 0;
        }
        if (isTrue) {
            left->value = 1.0f;
            func_00321638(self, right);
        } else if (right->type == 4) {
            if (right->value != 0.0f) {
                right->value = 1.0f;
                func_00321638(self, left);
                left = right;
                isTrue = 1;
            } else {
                func_00321638(self, right);
            }
        } else if (left->type == 4) {
            func_00321638(self, left);
            left = right;
        } else {
            sOrNode_003233B8* n = (sOrNode_003233B8*)func_003215F8(self);
            n->a = left;
            n->b = right;
            n->type = 6;
            left = n;
        }
    }
    return left;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", func_00323540);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void func_00321638(void* self, void* node);
extern "C" void* func_003215F8(void* self);
extern "C" void* func_003236D8(void* self);

struct sAndNode_00323540 {
    int type;
    union {
        float value;
        sAndNode_00323540* a;
    };
    sAndNode_00323540* b;
};

extern "C" void* func_00323540(void* self)
{
    sAndNode_00323540* left = (sAndNode_00323540*)func_003236D8(self);
    if (left == 0) {
        return 0;
    }
    int isFalse = 0;
    if (left->type == 4 && left->value == 0.0f) {
        isFalse = 1;
    }
    while (*(int*)((char*)self + 0x98) == 0xD) {
        cInputMapParser_readToken(self);
        sAndNode_00323540* right = (sAndNode_00323540*)func_003236D8(self);
        if (right == 0) {
            func_00321638(self, left);
            return 0;
        }
        if (isFalse) {
            func_00321638(self, right);
        } else if (right->type == 4) {
            if (right->value == 0.0f) {
                func_00321638(self, left);
                left = right;
                isFalse = 1;
            } else {
                func_00321638(self, right);
                if (left->type == 4)
                    left->value = 1.0f;
            }
        } else if (left->type == 4) {
            func_00321638(self, left);
            left = right;
        } else {
            sAndNode_00323540* n = (sAndNode_00323540*)func_003215F8(self);
            n->a = left;
            n->b = right;
            n->type = 7;
            left = n;
        }
    }
    return left;
}
#endif

INCLUDE_ASM("input/inputparse", func_003236D8);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", func_00323900);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void func_00321638(void* self, void* node);
extern "C" void* func_003215F8(void* self);
extern "C" void* func_00323A68(void* self);

struct sAddNode_00323900 {
    int type;
    union {
        float value;
        sAddNode_00323900* a;
    };
    sAddNode_00323900* b;
};

extern "C" void* func_00323900(void* self)
{
    sAddNode_00323900* left = (sAddNode_00323900*)func_00323A68(self);
    if (left == 0) {
        return 0;
    }
    sAddNode_00323900* konst = 0;
    if (left->type == 4) {
        konst = left;
    }
    for (;;) {
        int op;
        switch (*(int*)((char*)self + 0x98)) {
        case 0x14:
            op = 0xE;
            break;
        case 0x15:
            op = 0xF;
            break;
        default:
            return left;
        }
        cInputMapParser_readToken(self);
        sAddNode_00323900* right = (sAddNode_00323900*)func_00323A68(self);
        if (right == 0) {
            func_00321638(self, left);
            return 0;
        }
        if (right->type == 4) {
            if (konst != 0) {
                switch (op) {
                case 0xE:
                    konst->value = konst->value + right->value;
                    break;
                case 0xF:
                    konst->value = konst->value - right->value;
                    break;
                }
                func_00321638(self, right);
            } else {
                konst = right;
                if (op == 0xF) {
                    right->value = -right->value;
                }
                sAddNode_00323900* n = (sAddNode_00323900*)func_003215F8(self);
                n->a = left;
                n->type = 0xE;
                n->b = right;
                left = n;
            }
        } else {
            sAddNode_00323900* n = (sAddNode_00323900*)func_003215F8(self);
            n->a = left;
            n->type = op;
            n->b = right;
            left = n;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", func_00323A68);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void func_00321638(void* self, void* node);
extern "C" void* func_003215F8(void* self);
extern "C" void* cInputMapParser_parseTerm(void* self);

struct sMulNode_00323A68 {
    int type;
    union {
        float value;
        sMulNode_00323A68* a;
    };
    sMulNode_00323A68* b;
};

extern "C" void* func_00323A68(void* self)
{
    sMulNode_00323A68* left = (sMulNode_00323A68*)cInputMapParser_parseTerm(self);
    if (left == 0) {
        return 0;
    }
    sMulNode_00323A68* konst = 0;
    if (left->type == 4) {
        konst = left;
    }
    for (;;) {
        int op;
        switch (*(int*)((char*)self + 0x98)) {
        case 0x16:
            op = 0x10;
            break;
        case 0x17:
            op = 0x11;
            break;
        default:
            return left;
        }
        cInputMapParser_readToken(self);
        sMulNode_00323A68* right = (sMulNode_00323A68*)cInputMapParser_parseTerm(self);
        if (right == 0) {
            func_00321638(self, left);
            return 0;
        }
        if (right->type == 4) {
            if (konst != 0) {
                switch (op) {
                case 0x10:
                    konst->value = konst->value * right->value;
                    break;
                case 0x11:
                    konst->value = konst->value / right->value;
                    break;
                }
                func_00321638(self, right);
            } else {
                konst = right;
                if (op == 0x11) {
                    right->value = 1.0f / right->value;
                }
                sMulNode_00323A68* n = (sMulNode_00323A68*)func_003215F8(self);
                n->a = left;
                n->type = 0x10;
                n->b = right;
                left = n;
            }
        } else {
            sMulNode_00323A68* n = (sMulNode_00323A68*)func_003215F8(self);
            n->a = left;
            n->type = op;
            n->b = right;
            left = n;
        }
    }
}
#endif

INCLUDE_ASM("input/inputparse", cInputMapParser_parseTerm);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", cInputMapParser_parseBinaryFunc);
#ifdef SKIP_ASM
extern "C" void cInputMapParser_readToken(void* self);
extern "C" void* cInputMapParser_parseExpression(void* self);
extern "C" void func_00321500(void* self, const char* fmt, ...);
extern "C" void* func_003215F8(void* self);
extern "C" void func_00321638(void* self, void* node);
extern "C" float func_0031C228(float x);
extern "C" float func_0040DA10(float x);
extern "C" float func_0040D758(float x);
extern char D_0048E198[];
extern char D_0048E1B8[];
extern char D_0048E0B8[];

struct sBinNode_4138 {
    int type;
    union {
        float value;
        sBinNode_4138* a;
    };
    sBinNode_4138* b;
};

static inline float pow_4138(float x, float y)
{
    return func_0040D758(func_0040DA10(x) * y);
}

static inline float atan2_4138(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f) {
            return y;
        }
        if (y >= 0.0f) {
            return 1.5707963705062866f;
        }
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f) {
            a += 3.1415927410125732f;
        } else {
            a -= 3.1415927410125732f;
        }
    }
    return a;
}

// PORT: uses g++ min/max operators (<? >?).
extern "C" void* cInputMapParser_parseBinaryFunc(void* self, int op)
{
    if (*(int*)((char*)self + 0x98) != 9) {
        func_00321500(self, D_0048E198);
        return 0;
    }
    cInputMapParser_readToken(self);
    sBinNode_4138* a = (sBinNode_4138*)cInputMapParser_parseExpression(self);
    if (a == 0) {
        return 0;
    }
    if (*(int*)((char*)self + 0x98) != 8) {
        func_00321500(self, D_0048E1B8);
        func_00321638(self, a);
        return 0;
    }
    cInputMapParser_readToken(self);
    sBinNode_4138* b = (sBinNode_4138*)cInputMapParser_parseExpression(self);
    if (b == 0) {
        return 0;
    }
    if (*(int*)((char*)self + 0x98) != 0xA) {
        func_00321500(self, D_0048E0B8);
        func_00321638(self, a);
        func_00321638(self, b);
        return 0;
    }
    cInputMapParser_readToken(self);
    if (a->type == 4 && b->type == 4) {
        switch (op) {
        case 0x15:
            a->value = b->value <? a->value;
            break;
        case 0x14:
            a->value = b->value >? a->value;
            break;
        case 0x16:
            a->value = pow_4138(a->value, b->value);
            break;
        case 0x17:
            a->value = atan2_4138(a->value, b->value);
            break;
        }
        func_00321638(self, b);
        return a;
    }
    sBinNode_4138* n = (sBinNode_4138*)func_003215F8(self);
    n->type = op;
    n->a = a;
    n->b = b;
    return n;
}
#endif

INCLUDE_ASM("input/inputparse", cInputMapParser_parseUnaryFunc);

INCLUDE_ASM("input/inputparse", cInputMapParser_compileStatement);

INCLUDE_ASM("input/inputparse", func_00324678);

//100%
INCLUDE_ASM("input/inputparse", func_00324EC8);
#ifdef SKIP_ASM
extern "C" void func_00321500(void* self, const char* fmt, ...);
extern "C" int func_00324678(void* self, void* node, int* src, void* code, int cap, int a5);
extern char D_0048E240[];
extern char D_0048E228[];

struct sInsn_00324EC8 {
    unsigned int op : 6;
    unsigned int dst : 6;
    unsigned int src : 10;
    unsigned int arg : 10;
};
struct sCodeGen_00324EC8 {
    char pad0[0x108EC];
    int freeRegs[63];  // 0x108EC
    int numFree;                // 0x109E8
};

extern "C" int func_00324EC8(sCodeGen_00324EC8* self, void* node, int* dst, sInsn_00324EC8* code, int cap, int op, int a6)
{
    int src = -1;
    int n1 = func_00324678(self, *(void**)((char*)node + 4), &src, code, cap, a6);
    if (n1 < 0) {
        return -1;
    }
    code += n1;
    cap -= n1;
    int arg = -1;
    int n2 = func_00324678(self, *(void**)((char*)node + 8), &arg, code, cap, a6);
    if (n2 < 0) {
        return -1;
    }
    code += n2;
    cap -= n2;
    if ((unsigned int)arg < 0x40) {
        self->freeRegs[self->numFree++] = arg;
    }
    if ((unsigned int)src < 0x40) {
        self->freeRegs[self->numFree++] = src;
    }
    if (*dst < 0) {
        if (self->numFree > 0) {
            *dst = self->freeRegs[--self->numFree];
        }
        if (*dst < 0) {
            func_00321500(self, D_0048E240);
            return -1;
        }
    }
    if (cap <= 0) {
        func_00321500(self, D_0048E228);
        return -1;
    }
    code->op = op;
    code->dst = *dst;
    code->src = src;
    code->arg = arg;
    return n1 + n2 + 1;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_003250D8);
#ifdef SKIP_ASM
extern "C" void func_00321500(void* self, const char* fmt, ...);
extern "C" int func_00324678(void* self, void* node, int* src, void* code, int cap, int a5);
extern char D_0048E240[];
extern char D_0048E228[];

struct sInsn_003250D8 {
    unsigned int op : 6;
    unsigned int dst : 6;
    unsigned int src : 10;
    unsigned int arg : 10;
};
struct sCodeGen_003250D8 {
    char pad0[0x108EC];
    int freeRegs[63];  // 0x108EC
    int numFree;                // 0x109E8
};

extern "C" int func_003250D8(sCodeGen_003250D8* self, void* node, int* dst, sInsn_003250D8* code, int cap, int op, int a6)
{
    void* arg = *(void**)((char*)node + 4);
    int src = -1;
    int n = func_00324678(self, arg, &src, code, cap, a6);
    if (n < 0) {
        return -1;
    }
    code += n;
    cap -= n;
    if ((unsigned int)src < 0x40) {
        self->freeRegs[self->numFree++] = src;
    }
    if (*dst < 0) {
        if (self->numFree > 0) {
            *dst = self->freeRegs[--self->numFree];
        }
        if (*dst < 0) {
            func_00321500(self, D_0048E240);
            return -1;
        }
    }
    if (cap <= 0) {
        func_00321500(self, D_0048E228);
        return -1;
    }
    code->op = op;
    code->dst = *dst;
    code->src = src;
    code->arg = 0;
    return n + 1;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00325250__FPv);
#ifdef SKIP_ASM
void* func_00325250(void* self)
{
    *(int*)self = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00325260);
#ifdef SKIP_ASM
struct sInputParse_325260 {
    int pad[2];
    float v[0x40];
};
extern "C" float func_003252F8(void* self, int idx, int sel);
extern "C" float func_00325430(void* self, int a1);

extern "C" float func_00325260(sInputParse_325260* self, unsigned int id)
{
    if (id < 0x40) {
        return self->v[id];
    }
    if (id - 0x40 < 0x20) {
        return func_00325430(self, id - 0x40);
    }
    id -= 0x60;
    if (id < 0x39C) {
        return func_003252F8(self, (int)id / 6, (int)id % 6);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_003252E8);
#ifdef SKIP_ASM
struct sInputParse_003252E8 {
    int pad[2];
    int a[1];
};

extern "C" void* func_003252E8(void* self, int i)
{
    return &((sInputParse_003252E8*)self)->a[i];
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_003252F8);
#ifdef SKIP_ASM
struct sInputEntry3252F8 {
    float value;        // 0x0
    unsigned int a;     // 0x4
    unsigned int b;     // 0x8
    unsigned int c;     // 0xC
    unsigned int d;     // 0x10
    int pad[2];
};

struct sInputList3252F8 {
    int count;
    sInputEntry3252F8 entries[1];
};

struct sInputParse3252F8 {
    int defKind;
    sInputList3252F8* list;
};

static inline unsigned int GetA3252F8(sInputList3252F8* l, int idx)
{
    if (idx < l->count) {
        return l->entries[idx].a;
    }
    return 0;
}

static inline unsigned int GetB3252F8(sInputList3252F8* l, int idx)
{
    if (idx < l->count) {
        return l->entries[idx].b;
    }
    return 0;
}

static inline unsigned int GetC3252F8(sInputList3252F8* l, int idx)
{
    if (idx < l->count) {
        return l->entries[idx].c;
    }
    return 0;
}

static inline unsigned int GetD3252F8(sInputList3252F8* l, int idx)
{
    if (idx < l->count) {
        return l->entries[idx].d;
    }
    return 0;
}

// PORT: the unit declares func_003252F8 as (void*, int, int); the definition takes an unsigned kind.
float func_003252F8_impl(sInputParse3252F8* self, int idx, unsigned int kind) __asm__("func_003252F8");

// Reads one input value (axis, or a button counter as float) for entry idx; kind 5 uses the default kind.
float func_003252F8_impl(sInputParse3252F8* self, int idx, unsigned int kind)
{
    switch (kind) {
    case 0:
        if (idx < self->list->count) {
            return self->list->entries[idx].value;
        }
        break;
    case 1:
        return (float)GetC3252F8(self->list, idx);
    case 2:
        return (float)GetA3252F8(self->list, idx);
    case 3:
        return (float)GetB3252F8(self->list, idx);
    case 4:
        return (float)GetD3252F8(self->list, idx);
    case 5:
        return func_003252F8_impl(self, idx, self->defKind);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00325430);
#ifdef SKIP_ASM
extern "C" float func_00325430(void* self, int a1)
{
    if (a1 == 0) {
        return 0.0f;
    }
    char* p = (char*)self + a1 * 4;
    return *(float*)(p + 0x108);
}
#endif

INCLUDE_ASM("input/inputparse", func_00325450);

//100%
INCLUDE_ASM("input/inputparse", func_00325F48);
#ifdef SKIP_ASM
void cMemMan_free(void* ptr);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_0041605C(void* dst, const void* src, int n);
extern "C" char* func_0041ACC0(const char* s, int c);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);
// PORT: func_00326078 is declared (void*, int, int) later in the unit; this caller passes two strings.
void func_00326078_s(void* self, char* dir, char* file) __asm__("func_00326078");
extern char D_0048E3B8[];

struct sParseBuf_5F48 {
    int size;
    int cap;
    char* data;
};

extern "C" void* func_00325F48(sParseBuf_5F48* self, char* path, int* outSize)
{
    char dir[128];
    char file[32];
    self->size = 0;
    self->cap = 0x800;
    self->data = (char*)operator_new_tag(0x800, D_0048E3B8, 0, 0);
    char* p = func_0041ACC0(path, '/');
    if (p != 0) {
        p++;
        int n = p - path;
        strncpy(dir, path, n);
        dir[n] = 0;
        strcpy(file, p);
    } else {
        dir[0] = 0;
        strcpy(file, path);
    }
    func_00326078_s(self, dir, file);
    void* out = operator_new_tag(self->size, path, 0x100, 0);
    func_0041605C(out, self->data, self->size);
    if (self->data != 0) {
        cMemMan_free(self->data);
    }
    *outSize = self->size;
    return out;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326078);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
void cMemMan_free(void* ptr);
struct sParseStream;
extern "C" void func_00326478(void* self, sParseStream* s);
extern "C" void func_00326430(void* self, int a1, int a2);
extern "C" int func_00326150(void* self, sParseStream* s, int a2, int a3);
extern "C" unsigned char* func_003E1A10(const char* name, int* size, int flags);
extern char D_004A3FA0[];

struct sParseStream_326078 {
    unsigned char* base;
    int size;
    unsigned char* cur;
    int line;
};

extern "C" void func_00326078(void* self, int a1, int a2)
{
    char name[0xA0];
    sParseStream_326078 st;
    sprintf(name, D_004A3FA0, a1, a2);
    unsigned char* p = func_003E1A10(name, &st.size, 0);
    st.cur = st.base = p;
    st.line = 1;
    func_00326478(self, (sParseStream*)&st);
    // PORT: the unit declares func_00326430's third parameter as int; it receives a char*.
    func_00326430(self, st.line, (int)name);
    while (func_00326150(self, (sParseStream*)&st, a1, a2)) {
    }
    if (st.base) {
        cMemMan_free(st.base);
    }
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326150);
#ifdef SKIP_ASM
struct sParseStream;
extern "C" void func_00326360(void* self, char c);
extern "C" void func_00326478(void* self, sParseStream* s);
extern "C" void cInputPreProcessor_readCmdLine(void* self, sParseStream* s, int a2, int a3);
extern "C" void func_003264B0(void* self, sParseStream* s, int a2, int a3);
extern "C" void func_003265C0(void* self, sParseStream* s, int a2, int a3);

static inline int isWS_326150(int c)
{
    return c == ' ' || c == '\t' || c == '\r';
}

extern "C" int func_00326150(void* self, sParseStream* s, int a2, int a3)
{
    int ch;
    for (;;) {
        ch = *(int*)((char*)self + 0xC);
        if (!isWS_326150(ch))
            break;
        func_00326360(self, (char)*(int*)((char*)self + 0xC));
        func_00326478(self, s);
        if (*(int*)((char*)self + 0xC) < 0)
            return 0;
    }
    if (ch == '#') {
        func_00326478(self, s);
        cInputPreProcessor_readCmdLine(self, s, a2, a3);
        return *(int*)((char*)self + 0xC) >= 0;
    }
    if (ch == '/') {
        func_00326478(self, s);
        int c = *(int*)((char*)self + 0xC);
        if (c == '/') {
            func_003265C0(self, s, a2, a3);
            return *(int*)((char*)self + 0xC) >= 0;
        }
        if (c == '*') {
            func_00326478(self, s);
            func_003264B0(self, s, a2, a3);
            return *(int*)((char*)self + 0xC) >= 0;
        }
        func_00326360(self, '/');
    }
    while (*(int*)((char*)self + 0xC) >= 0) {
        func_00326360(self, (char)*(int*)((char*)self + 0xC));
        if (*(int*)((char*)self + 0xC) == '\n') {
            *(int*)((char*)s + 0xC) += 1;
            func_00326478(self, s);
            break;
        }
        func_00326478(self, s);
    }
    return *(int*)((char*)self + 0xC) >= 0;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326308);
#ifdef SKIP_ASM
extern "C" void func_00326360(void* self, char c);

extern "C" void func_00326308(void* self, char* s)
{
    while (*s != 0) {
        func_00326360(self, *s++);
    }
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326360);
#ifdef SKIP_ASM
void cMemMan_free(void* ptr);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_0041605C(void* dst, const void* src, int n);
extern char D_0048E3B8[];

struct sCharBuf_326360 {
    int count;
    int cap;
    char* data;
};

extern "C" void func_00326360(void* self, char c)
{
    sCharBuf_326360* b = (sCharBuf_326360*)self;
    if (b->count == b->cap) {
        int newCap = b->count + 0x400;
        int grow = b->count * 3 / 2;
        if (newCap < grow) {
            newCap = grow;
        }
        char* p = (char*)operator_new_tag(newCap, D_0048E3B8, 0, 0);
        func_0041605C(p, b->data, b->cap);
        if (b->data) {
            cMemMan_free(b->data);
        }
        b->data = p;
        b->cap = newCap;
    }
    b->data[b->count++] = c;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("input/inputparse", func_00326430);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00326308(void* self, char* msg);
extern char D_0048E3C8[];

extern "C" void func_00326430(void* self, int a1, int a2)
{
    char buf[0xB0];
    sprintf(buf, D_0048E3C8, a1, a2);
    func_00326308(self, buf);
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326478);
#ifdef SKIP_ASM
struct sParseStream {
    unsigned char* base;
    int size;
    unsigned char* cur;
};

extern "C" void func_00326478(void* self, sParseStream* s)
{
    if (s->cur == s->base + s->size) {
        *(int*)((char*)self + 0xc) = -1;
    } else {
        *(int*)((char*)self + 0xc) = *s->cur++;
    }
}
#endif

INCLUDE_ASM("input/inputparse", func_003264B0);

//100%
INCLUDE_ASM("input/inputparse", func_003265C0);
#ifdef SKIP_ASM
struct sParseStream;
extern "C" void func_00326478(void* self, sParseStream* s);
// PORT: func_00326A20__FPv is called with (self, s, a2, a3, msg) here; bind the 5-arg form to that symbol.
void func_00326A20_5(void* self, sParseStream* s, int a2, int a3, const char* msg) __asm__("func_00326A20__FPv");
extern char D_0048E3D8[];

extern "C" void func_003265C0(void* self, sParseStream* s, int a2, int a3)
{
    for (;;) {
        int ch = *(int*)((char*)self + 0xC);
        if (ch == '\n') {
            *(int*)((char*)s + 0xC) += 1;
            func_00326360(self, (char)*(int*)((char*)self + 0xC));
            func_00326478(self, s);
            return;
        }
        if (ch < 0) {
            goto error;
        }
        func_00326478(self, s);
    }
error:
    func_00326A20_5(self, s, a2, a3, D_0048E3D8);
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326678);
#ifdef SKIP_ASM
extern "C" void func_00326678(void* self, sParseStream* s)
{
    while (*(int*)((char*)self + 0xC) >= 0) {
        func_00326478(self, s);
        if (*(int*)((char*)self + 0xC) == 10) {
            func_00326478(self, s);
            *(int*)((char*)s + 0xC) += 1;
            break;
        }
    }
}
#endif

INCLUDE_ASM("input/inputparse", cInputPreProcessor_readCmdLine);

//100%
INCLUDE_ASM("input/inputparse", func_00326A20__FPv);
#ifdef SKIP_ASM
void func_00326A20(void* self)
{
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326A28);
#ifdef SKIP_ASM
extern "C" int func_00326D60(void* p, int n);

extern "C" void func_00326A28(void* self)
{
    *(int*)((char*)self + 0x2EE8) = func_00326D60((char*)self + 0x2EEC, 4);
    *(int*)((char*)self + 0x2EE0) = 0x1D;
    *(int*)((char*)self + 0x2EE4) = 0;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326A68);
#ifdef SKIP_ASM
struct sVEntry00326A68 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj00326A68 {
    sVEntry00326A68* vt;
};

struct sOwner00326A68 {
    char pad[0x2EE8];
    int count;
    sObj00326A68* objs[1];
};

extern "C" void func_00326A68(sOwner00326A68* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        sObj00326A68* o = self->objs[i];
        if (o != 0) {
            o->vt[1].fn((char*)o + o->vt[1].delta, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326AE0);
#ifdef SKIP_ASM
extern "C" void func_00326CF0(void* p);

extern "C" void func_00326AE0(void* self)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x2EE8); i++) {
        func_00326CF0(((void**)((char*)self + 0x2EEC))[i]);
    }
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326B48);
#ifdef SKIP_ASM
struct sInputSlot_00326B48 {
    int value;
    char data[0x60];
};

struct sInputParse_00326B48 {
    sInputSlot_00326B48 slots[30][4];
    unsigned int head;
    unsigned int tail;
};

extern "C" int func_00326B48(sInputParse_00326B48* s)
{
    unsigned int next = (s->head + 1) % 30;
    if (next == s->tail) {
        return 0;
    }
    s->head = next;
    return 1;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326B88);
#ifdef SKIP_ASM
class cInputDevice_326B88 {
public:
    virtual void v01();
    virtual int read(char* buf, int size);
};

struct sInputSlot_00326B88 {
    int value;
    char data[0x60];
};

struct sInputParse_00326B88 {
    sInputSlot_00326B88 slots[30][4];
    unsigned int head;
    unsigned int tail;
    int count;
    cInputDevice_326B88* devices[4];
};

extern "C" void func_00326B88(sInputParse_00326B88* s)
{
    int i;
    for (i = 0; i < s->count; i++) {
        s->slots[s->tail][i].value = s->devices[i]->read(s->slots[s->tail][i].data, 0x18);
    }
    s->tail = (s->tail + 1) % 30;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326C60);
#ifdef SKIP_ASM
struct sInputSlot_00326C60 {
    int value;
    char data[0x60];
};

struct sInputParse_00326C60 {
    sInputSlot_00326C60 slots[30][4];
    int head;
    int tail;
};

extern "C" int func_00326C60(sInputParse_00326C60* s)
{
    int tail = s->tail;
    int head = s->head;
    s->head = (tail + 29) % 30;
    return (tail - head + 30) % 30;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326CA0);
#ifdef SKIP_ASM
struct sInputSlot_00326CA0 {
    int value;
    char pad[0x60];
};

struct sInputParse_00326CA0 {
    sInputSlot_00326CA0 slots[30][4];
    int bank;
};

extern "C" int func_00326CA0(void* self, int i)
{
    sInputParse_00326CA0* s = (sInputParse_00326CA0*)self;
    return s->slots[s->bank][i].value;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326CC8);
#ifdef SKIP_ASM
struct sInputSlot_00326CC8 {
    int value;
    char data[0x60];
};

struct sInputParse_00326CC8 {
    sInputSlot_00326CC8 slots[30][4];
    int bank;
};

extern "C" void* func_00326CC8(void* self, int i)
{
    sInputParse_00326CC8* s = (sInputParse_00326CC8*)self;
    return s->slots[s->bank][i].data;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326CF0);
#ifdef SKIP_ASM
struct sVEntry00326CF0 {
    short delta;
    short index;
    void* fn;
};

typedef int (*CountFn00326CF0)(void*);
typedef void (*SetFn00326CF0)(void*, int, float);

extern "C" void func_00326CF0(void* p)
{
    sVEntry00326CF0** self = (sVEntry00326CF0**)p;
    int i;
    for (i = 0; i < ((CountFn00326CF0)(*self)[3].fn)((char*)self + (*self)[3].delta); i++) {
        ((SetFn00326CF0)(*self)[4].fn)((char*)self + (*self)[4].delta, i, 0.0f);
    }
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326D60);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00326DF0(void* self, int a1, int a2);
extern char D_004A3FB0[];

extern "C" int func_00326D60(void* p, int n)
{
    void** arr = (void**)p;
    int i;
    if (n > 2) {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        arr[i] = func_00326DF0(cMemMan_alloc(0x180, D_004A3FB0, 0x4000000, 0), i, 0);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326DF0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern void* D_0048E488[];

extern "C" void* func_00326DF0(void* self, int a1, int a2)
{
    *(void***)self = D_0048E488;
    *(int*)((char*)self + 0x4) = a1;
    *(int*)((char*)self + 0x8) = a2;
    func_00416210((char*)self + 0xC, 0, 0x24);
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x58) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x5C) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00326E50);
#ifdef SKIP_ASM
extern "C" int func_003FF8F0(int a, int b);
void operator_delete(int* ptr);
extern void* D_0048E488[];
extern char D_0048E4B8[];

extern "C" void func_00326E50(void* self, int flags)
{
    *(void***)self = D_0048E488;
    func_003FF8F0(*(int*)((char*)self + 0x4), *(int*)((char*)self + 0x8));
    *(void**)self = D_0048E4B8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("input/inputparse", func_00326EB0);

//100%
INCLUDE_ASM("input/inputparse", func_00327738__FPv);
#ifdef SKIP_ASM
int func_00327738(void* self)
{
    return 0x2;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00327740);
#ifdef SKIP_ASM
static inline int clamp_327740(int v, int lo, int hi)
{
    if (v >= lo) {
        if (v > hi) {
            v = hi;
        }
    } else {
        v = lo;
    }
    return v;
}

extern "C" void func_00327740(void* self, int mode, float v)
{
    if (mode == 1) {
        *(int*)((char*)self + 0x30) = v != 0.0f;
        return;
    }
    int* p = (int*)((char*)self + 0x38);
    int r;
    if (v != 0.0f) {
        int t = (int)(v * 205.0f + 50.0f);
        r = clamp_327740(t, 50, 255);
    } else {
        r = 0;
    }
    *p = r;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_003277D0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0048E4B8[];

extern "C" void func_003277D0(void* self, int flags)
{
    *(void**)self = D_0048E4B8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00327800__FPv);
#ifdef SKIP_ASM
int func_00327800(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00327808__FPv);
#ifdef SKIP_ASM
void func_00327808(void* self)
{
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00327810__FPv);
#ifdef SKIP_ASM
void* func_00327810(void* self)
{
    int t0 = 0;
    *(int*)self = t0;
    *(int*)((char*)self + 0x4) = t0;
    *(int*)((char*)self + 0x8) = t0;
    *(int*)((char*)self + 0xc) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("input/inputparse", func_00327828);
#ifdef SKIP_ASM
void cMemMan_free(void* ptr);
void operator_delete(int* ptr);

extern "C" void func_00327828(void* self, int flags)
{
    if (*(void**)self != 0) {
        cMemMan_free(*(void**)self);
    }
    if (*(void**)((char*)self + 0x8) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x8));
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

