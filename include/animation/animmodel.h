#ifndef ANIMATION_ANIMMODEL_H
#define ANIMATION_ANIMMODEL_H

// cAnimModel: a skinned model made of parts, each with up to 4 LOD slots, plus a bone array and bone
// matrices. cRider::mAnimModel points to one.
//
// This is a FLAT layout built from how the matched methods in animation/animmodel use each offset
// (2026-10-17). It replaces 43 per-function overlay structs. Unlike ai/rider.h there is no preview evidence:
// the July preview has no accessors for this class. Only "cAnimModel", "ModelPart" and "LOD" are EA's own
// words (cAnimModel_addModelPartLOD, cAnimModel_compile). Every other name is ours, from usage, and the
// comment says which function shows it. Unknown size; only the fields below are known.

#include "layout.h"
#include "bx/math3d.h"

// One LOD's entry for one ref index: the source part block and its data (addModelPartLOD).
struct sAnimModelLodRef {
    char* part;     // 0x0 source part block (non-null = drawable, func_00310640)
    char* data;     // 0x4 part + 0x60
    int unk_08;     // 0x8 passed to the renderer's set-matrices call (func_00310640)
    int unk_0C;     // 0xC same
};

// A part's LOD slot. The 4 slots double as the part's "channels": enabling a part sets used on all 4
// (func_0030E9E0), drawing checks the slot of the requested LOD (func_00310640).
struct sAnimModelLod {
    int used;                   // 0x0
    sAnimModelLodRef* refs;     // 0x4 numLodRefs entries (cAnimModel_addModelPartLOD)
};

// 0x58 bytes, one per model part (cAnimModel::parts).
struct sAnimModelPart {
    int id;                     // 0x00 = the source part's signed byte at +0x52; 2 (or 1..2) picks the draw argument
    int firstBone;              // 0x04 first bone of this part (func_00310530 start + j; func_00310C48 returns firstBone + i)
    int unk_08;
    int unk_0C;                 // 0x0C a channel bit; >= 0 when the part has one (func_00310CE8)
    unsigned long mask;         // 0x10 64-bit bone/channel mask OR'd into cAnimModel::mask (func_0030E9E0)
    sAnimModelLod lods[4];      // 0x18
    char* boneNames;            // 0x38 numBones names of 0x50 bytes (func_00310C48, func_00310CE8)
    char* unk_3C;               // 0x3C data + src[0x1C] (addModelPartLOD)
    char* unk_40;               // 0x40 data + src[0x2C]
    int numBones;               // 0x44 = (short)src[0x4A]; loop bound over this part's bones and names
    int unk_48;                 // 0x48 = (short)src[0x4E]
    int unk_4C;                 // 0x4C = (short)src[0x50]
    int refIndex;               // 0x50 which lods[].refs entry is current (addModelPartLOD, func_0030EC18)
    int unk_54;
};

// 0x20 bytes per bone (cAnimModel::bones).
struct sAnimModelBone {
    t4Vector pos;               // 0x00 translated with the model (func_00310530)
    t4Vector rot;               // 0x10 a quaternion x, y, z, w (func_00106848)
};

struct sAnimModelLodInfo {
    int unk_00;                 // passed with unk_04 to the renderer when the model isn't per-part LOD'd (func_00310640)
    int unk_04;
};

struct cAnimModel {
    /* 0x000 */ int unk_000;
    /* 0x004 */ int numLodRefs;             // refs per LOD slot (addModelPartLOD allocates this many)
    /* 0x008 */ int numParts;               // loop bound over parts everywhere
    /* 0x00C */ sAnimModelPart* parts;
    /* 0x010 */ int numBones;               // bones/matrices count; also the first channel bit (func_00310CE8)
    /* 0x014 */ int maxPartIndex;           // i > this -> no such part (func_0030E9E0, func_00310CE8)
    /* 0x018 */ int unk_018;                // nonzero: draw per-part LOD refs, else one call with lodInfo (func_00310640)
    /* 0x01C */ int* partIndex;             // part number -> index into parts, < 0 = none
    /* 0x020 */ int* boneChannelIndex;      // per-bone first-component index into the channel data (func_0030ECD8: first = arr[k] - arr[firstBone])
    /* 0x024 */ t4Vector* localPos;         // numBones local bone positions, scaled componentwise by unk_140 (func_00310200)
    /* 0x028 */ t4Vector* localRot;         // numBones local bone rotation quaternions (func_00310200)
    /* 0x02C */ sAnimModelBone* bones;      // numBones of them; streamed as numBones << 5 bytes (func_00310EA8)
    /* 0x030 */ t4Matrix* unk_030;          // numBones bone matrices, row 3 = position (rider bone lookups); translated with the model
    /* 0x034 */ t4Matrix* unk_034;          // numBones, translated with the model (func_00310530)
    /* 0x038 */ t4Matrix* unk_038;          // numBones; palette[i] = unk_030[i] or unk_034[i] times this (func_00310948, func_00310640)
    /* 0x03C */ int unk_03C;
    /* 0x040 */ sAnimModelLodInfo lodInfo[4];
    /* 0x060 */ char unk_060[0xE0];
    /* 0x140 */ t4Vector unk_140;           // = (a, b, b, 1) (func_0030DBA0); .y is the draw call's float (func_00310640); .x scales rider lean (ai/rider)
    /* 0x150 */ unsigned long mask;         // 64-bit mask of enabled parts (func_0030E9E0, func_0030EB60)
    /* 0x158 */ unsigned long unk_158;      // another such mask (func_0030ECA0)
};

CHECK_OFFSET(sAnimModelPart, mask, 0x10);
CHECK_OFFSET(sAnimModelPart, lods, 0x18);
CHECK_OFFSET(sAnimModelPart, boneNames, 0x38);
CHECK_OFFSET(sAnimModelPart, numBones, 0x44);
CHECK_OFFSET(sAnimModelPart, refIndex, 0x50);
CHECK_OFFSET(cAnimModel, numParts, 0x8);
CHECK_OFFSET(cAnimModel, parts, 0xC);
CHECK_OFFSET(cAnimModel, numBones, 0x10);
CHECK_OFFSET(cAnimModel, maxPartIndex, 0x14);
CHECK_OFFSET(cAnimModel, unk_018, 0x18);
CHECK_OFFSET(cAnimModel, partIndex, 0x1C);
CHECK_OFFSET(cAnimModel, boneChannelIndex, 0x20);
CHECK_OFFSET(cAnimModel, localPos, 0x24);
CHECK_OFFSET(cAnimModel, localRot, 0x28);
CHECK_OFFSET(cAnimModel, bones, 0x2C);
CHECK_OFFSET(cAnimModel, unk_030, 0x30);
CHECK_OFFSET(cAnimModel, unk_034, 0x34);
CHECK_OFFSET(cAnimModel, unk_038, 0x38);
CHECK_OFFSET(cAnimModel, lodInfo, 0x40);
CHECK_OFFSET(cAnimModel, unk_140, 0x140);
CHECK_OFFSET(cAnimModel, mask, 0x150);
CHECK_OFFSET(cAnimModel, unk_158, 0x158);
typedef char check_sAnimModelPart_size[(sizeof(sAnimModelPart) == 0x58) ? 1 : -1];
typedef char check_sAnimModelBone_size[(sizeof(sAnimModelBone) == 0x20) ? 1 : -1];
typedef char check_sAnimModelLodRef_size[(sizeof(sAnimModelLodRef) == 0x10) ? 1 : -1];

#endif
