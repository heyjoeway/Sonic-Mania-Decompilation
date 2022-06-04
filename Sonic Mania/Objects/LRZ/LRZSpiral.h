#ifndef OBJ_LRZSPIRAL_H
#define OBJ_LRZSPIRAL_H

#include "SonicMania.h"

typedef enum {
    LRZSPIRAL_CYLINDER,
    LRZSPIRAL_J_CURVE,
    LRZSPIRAL_C_CURVE,
} LRZSpiralTypes;

// Object Class
struct ObjectLRZSpiral {
    RSDK_OBJECT
    TABLE(int32 cylinderSpiralYOffsetTable[128],
          { 0,        0x10000,  0x20000,  0x30000,  0x40000,  0x50000,  0x60000,  0x70000,  0x80000,  0x90000,  0xA0000,  0xC0000,  0xD0000,
            0xF0000,  0x100000, 0x120000, 0x130000, 0x130000, 0x140000, 0x140000, 0x160000, 0x170000, 0x170000, 0x170000, 0x170000, 0x170000,
            0x170000, 0x170000, 0x170000, 0x170000, 0x170000, 0x170000, 0x180000, 0x180000, 0x180000, 0x180000, 0x190000, 0x1B0000, 0x1C0000,
            0x1E0000, 0x1F0000, 0x210000, 0x220000, 0x240000, 0x250000, 0x270000, 0x280000, 0x2A0000, 0x2B0000, 0x2D0000, 0x2E0000, 0x300000,
            0x310000, 0x330000, 0x340000, 0x360000, 0x370000, 0x390000, 0x3A0000, 0x3C0000, 0x3D0000, 0x3F0000, 0x400000, 0x420000, 0x430000,
            0x450000, 0x460000, 0x480000, 0x490000, 0x4B0000, 0x4C0000, 0x4E0000, 0x4F0000, 0x510000, 0x520000, 0x540000, 0x550000, 0x570000,
            0x580000, 0x5A0000, 0x5B0000, 0x5D0000, 0x5E0000, 0x600000, 0x600000, 0x600000, 0x600000, 0x600000, 0x600000, 0x600000, 0x600000,
            0x600000, 0x600000, 0x600000, 0x600000, 0x600000, 0x600000, 0x610000, 0x620000, 0x630000, 0x640000, 0x650000, 0x660000, 0x670000,
            0x680000, 0x690000, 0x6A0000, 0x6B0000, 0x6C0000, 0x6D0000, 0x6E0000, 0x6F0000, 0x700000, 0x710000, 0x720000, 0x730000, 0x740000,
            0x750000, 0x760000, 0x770000, 0x780000, 0x790000, 0x7A0000, 0x7B0000, 0x7C0000, 0x7D0000, 0x7E0000, 0x7F0000 });
    TABLE(int32 cylinderExitYOffsetTable[64],
          { 0,        0x10000,  0x20000,  0x30000,  0x40000,  0x50000,  0x60000,  0x70000,  0x80000,  0x90000,  0xA0000,  0xC0000,  0xD0000,
            0xF0000,  0x100000, 0x120000, 0x130000, 0x130000, 0x140000, 0x140000, 0x160000, 0x170000, 0x170000, 0x170000, 0x170000, 0x170000,
            0x170000, 0x170000, 0x170000, 0x170000, 0x170000, 0x170000, 0x180000, 0x180000, 0x180000, 0x180000, 0x190000, 0x190000, 0x190000,
            0x1A0000, 0x1A0000, 0x1A0000, 0x1B0000, 0x1B0000, 0x1B0000, 0x1C0000, 0x1C0000, 0x1C0000, 0x1D0000, 0x1D0000, 0x1D0000, 0x1D0000,
            0x1E0000, 0x1E0000, 0x1E0000, 0x1F0000, 0x1F0000, 0x1F0000, 0x200000, 0x200000, 0x200000, 0x210000, 0x210000, 0x210000 });
    Animator animator;
    uint16 aniFrames;
};

// Entity Class
struct EntityLRZSpiral {
    RSDK_ENTITY
    StateMachine(state);
    uint8 type;
    int32 height;
    int32 radius;
    uint8 activePlayers;
    int32 playerSpiralPos[PLAYER_MAX];
    Hitbox hitboxTrigger;
};

// Object Struct
extern ObjectLRZSpiral *LRZSpiral;

// Standard Entity Events
void LRZSpiral_Update(void);
void LRZSpiral_LateUpdate(void);
void LRZSpiral_StaticUpdate(void);
void LRZSpiral_Draw(void);
void LRZSpiral_Create(void *data);
void LRZSpiral_StageLoad(void);
#if RETRO_INCLUDE_EDITOR
void LRZSpiral_EditorDraw(void);
void LRZSpiral_EditorLoad(void);
#endif
void LRZSpiral_Serialize(void);

// Extra Entity Functions
void LRZSpiral_HandlePlayerExit(EntityPlayer *player);
void LRZSpiral_State_Cylinder(void);
void LRZSpiral_State_J_Curve(void);
void LRZSpiral_State_C_Curve(void);

#endif //! OBJ_LRZSPIRAL_H
