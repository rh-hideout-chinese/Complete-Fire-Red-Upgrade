#include "defines.h"
#include "../include/item_menu.h"
#include "../include/list_menu.h"
#include "../include/menu.h"
#include "../include/menu_helpers.h"
#include "../include/money.h"
#include "../include/script.h"
#include "../include/shop.h"
#include "../include/string_util.h"
#include "../include/window.h"
#include "../include/constants/hold_effects.h"
#include "../include/constants/items.h"
#include "../include/constants/moves.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/songs.h"
#include "../include/constants/tutors.h"

#include "../include/new/util.h"
#include "../include/new/item.h"
#include "../include/new/set_z_effect.h"

static const u8 item114[] = { 0x0f, 0xe6, 0x01, 0x63, 0x07, 0xd7, 0x09, 0x66, 0x07, 0xca, 0x04, 0x8d, 0x0e, 0x90, 0x0b, 0xad, 0x03, 0xca, 0x02, 0x25, 0x04, 0xbb, 0x10, 0xa9, 0x03, 0x0b, 0x04, 0x8f, 0x0d, 0x1f, 0x37, 0xfe, 0x07, 0xd7, 0x0f, 0x24, 0x0f, 0xe6, 0x0b, 0xaa, 0x03, 0x31, 0x04, 0x49, 0x05, 0xc6, 0x02, 0x78, 0x0c, 0x20, 0x37, 0xFF};
const struct Item sItem_data[] =
    {
        [0] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,             	 //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [1] =
            {

                .name = { 0x10, 0x39, 0x09, 0x5d, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 1,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D4ECC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [2] =
            {

                .name = { 0x04, 0x49, 0x05, 0xa1, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 2,                      //道具编号
                .price = 1200,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D4F26, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x1,
            },
        [3] =
            {

                .name = { 0x02, 0x2e, 0x05, 0xa1, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 3,                      //道具编号
                .price = 600,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D4F78, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x2,
            },
        [4] =
            {

                .name = { 0x07, 0x5b, 0x08, 0xbc, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 4,                      //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D4FD0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 3,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x3,
            },
        [5] =
            {

                .name = { 0x0f, 0xb9, 0x0f, 0x00, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 5,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D501A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x4,
            },
        [6] =
            {

                .name = { 0x0d, 0x60, 0x0d, 0x8c, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 6,                      //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5077, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 5,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x5,
            },
        [7] =
            {

                .name = { 0x0a, 0xca, 0x0c, 0x51, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 7,                      //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D50CC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 6,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x6,
            },
        [8] =
            {

                .name = { 0x02, 0x34, 0x0e, 0x91, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 8,                      //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D511D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 7,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 0x7,
            },
        [9] =
            {

                .name = { 0x10, 0xa9, 0x04, 0x1e, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 9,                      //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5165, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 8,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 8,
            },
        [10] =
            {

                .name = { 0x0b, 0xed, 0x05, 0xcf, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 10,                     //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D51B4, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 9,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 9,
            },
        [11] =
            {

                .name = { 0x05, 0x37, 0x08, 0x6b, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 11,                     //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5216, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 10,                      //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 10,
            },
        [12] =
            {

                .name = { 0x0c, 0x1c, 0x0d, 0xd3, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 12,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5263, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 3,                     //道具口袋
                .type = 11,                      //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E1D,       //战斗使用程序
                .secondaryId = 11,
            },
        [13] =
            {

                .name = { 0x0e, 0xf0, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 13,                     //道具编号
                .price = 300,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 20,           //携带参数
                .description = (u8*)0x083D52B2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [14] =
            {

                .name = { 0x07, 0x34, 0x03, 0x63, 0x0e, 0xf0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 14,                     //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D52FF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [15] =
            {

                .name = { 0x10, 0xf5, 0x0b, 0xa9, 0x0e, 0xf0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 15,                     //道具编号
                .price = 250,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D533D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [16] =
            {

                .name = { 0x07, 0x34, 0x03, 0x58, 0x0e, 0xf0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 16,                     //道具编号
                .price = 250,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5374, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [17] =
            {

                .name = { 0x07, 0x34, 0x09, 0x77, 0x0e, 0xf0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 17,                     //道具编号
                .price = 250,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D53A9, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [18] =
            {

                .name = { 0x07, 0x34, 0x09, 0x23, 0x0e, 0xf0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 18,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D53DF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [19] =
            {

                .name = { 0x05, 0x65, 0x04, 0x1e, 0x0e, 0xf0, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 19,                     //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 255,          //携带参数
                .description = (u8*)0x083D541B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [20] =
            {

                .name = { 0x0b, 0x2b, 0x09, 0x34, 0x0e, 0xf0, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 20,                     //道具编号
                .price = 2500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 255,          //携带参数
                .description = (u8*)0x083D546F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [21] =
            {

                .name = { 0x02, 0x2e, 0x04, 0x49, 0x05, 0xa1, 0x0e, 0xf0, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 21,                     //道具编号
                .price = 1200,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 200,          //携带参数
                .description = (u8*)0x083D54B5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [22] =
            {

                .name = { 0x02, 0x2e, 0x05, 0xa1, 0x0e, 0xf0, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 22,                     //道具编号
                .price = 700,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 50,           //携带参数
                .description = (u8*)0x083D5503, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [23] =
            {

                .name = { 0x0d, 0x5a, 0x09, 0xd2, 0x0e, 0xf0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 23,                     //道具编号
                .price = 600,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5550, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [24] =
            {

                .name = { 0x04, 0x66, 0x0b, 0xd8, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 24,                     //道具编号
                .price = 1500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5598, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [25] =
            {

                .name = { 0x0c, 0xd9, 0x05, 0xa1, 0x04, 0x66, 0x0b, 0xd8, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 25,                     //道具编号
                .price = 4000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D55EC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [26] =
            {

                .name = { 0x09, 0x58, 0x0d, 0x7c, 0x10, 0x7f, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 26,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 50,           //携带参数
                .description = (u8*)0x083D562B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [27] =
            {

                .name = { 0x0b, 0x7b, 0x07, 0xd7, 0x0a, 0xb6, 0x0c, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 27,                     //道具编号
                .price = 300,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 60,           //携带参数
                .description = (u8*)0x083D567E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [28] =
            {

                .name = { 0x11, 0x13, 0x04, 0xf5, 0x03, 0x3e, 0x0d, 0x7c, 0x0b, 0x69, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 28,                     //道具编号
                .price = 350,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 80,           //携带参数
                .description = (u8*)0x083D56C2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [29] =
            {

                .name = { 0x09, 0x9c, 0x09, 0x9c, 0x0a, 0x00, 0x09, 0xc2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 29,                     //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 100,          //携带参数
                .description = (u8*)0x083D5706, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [30] =
            {

                .name = { 0x08, 0x79, 0x10, 0x7f, 0x03, 0xde, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 30,                     //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D574F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [31] =
            {

                .name = { 0x08, 0x79, 0x10, 0x7f, 0x04, 0x63, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 31,                     //道具编号
                .price = 800,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D579E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [32] =
            {

                .name = { 0x0d, 0x5a, 0x09, 0xd2, 0x10, 0x7f, 0x03, 0xde, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 32,                     //道具编号
                .price = 450,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D57E3, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [33] =
            {

                .name = { 0x04, 0x1e, 0x05, 0x7b, 0x10, 0x7f, 0x02, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 33,                     //道具编号
                .price = 2800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5833, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [34] =
            {

                .name = { 0xca, 0xca, 0x0e, 0x2c, 0x01, 0xd4, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 34,                     //道具编号
                .price = 1200,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D5883, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16FD,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FF5,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [35] =
            {

                .name = { 0xca, 0xca, 0x02, 0xe3, 0x01, 0xd4, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 35,                     //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 255,          //携带参数
                .description = (u8*)0x083D58BF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16FD,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FF5,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [36] =
            {

                .name = { 0xca, 0xca, 0x02, 0xd3, 0x01, 0xd4, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 36,                     //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D58F4, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16FD,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FF5,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [37] =
            {

                .name = { 0xca, 0xca, 0x0b, 0x2b, 0x01, 0xd4, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 37,                     //道具编号
                .price = 4500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 255,          //携带参数
                .description = (u8*)0x083D5934, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16FD,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FF5,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [38] =
            {

                .name = { 0x04, 0x14, 0x0e, 0xc0, 0x0d, 0xed, 0x01, 0x71, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 38,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5968, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [39] =
            {

                .name = { 0x08, 0x2b, 0x0b, 0x89, 0x0b, 0xb8, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 39,                     //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D59BB, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [40] =
            {

                .name = { 0x05, 0x53, 0x0b, 0x89, 0x0b, 0xb8, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 40,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D59EF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [41] =
            {

                .name = { 0x05, 0x1b, 0x0b, 0x89, 0x0b, 0xb8, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 41,                     //道具编号
                .price = 300,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5A2D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [42] =
            {

                .name = { 0x05, 0x09, 0x0b, 0x89, 0x0b, 0xb8, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 42,                     //道具编号
                .price = 400,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 50,           //携带参数
                .description = (u8*)0x083D5A6A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1A95,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [43] =
            {

                .name = { 0x01, 0x36, 0x0b, 0x89, 0x0b, 0xb8, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 43,                     //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 150,          //携带参数
                .description = (u8*)0x083D5AB8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1A95,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [44] =
            {

                .name = { 0x0c, 0x3c, 0x04, 0xc3, 0x10, 0x7e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 44,                     //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 1,                 //携带效果
                .holdEffectParam = 20,           //携带参数
                .description = (u8*)0x083D5B06, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [45] =
            {

                .name = { 0x0b, 0xe1, 0x05, 0x5f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 45,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5B49, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A176D,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [46] =
            {

                .name = { 0x0a, 0xcc, 0x0c, 0xb3, 0x04, 0xc9, 0x0e, 0xb7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 46,                     //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5B7A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [47] =
            {

                .name = { 0x0a, 0xcc, 0x0c, 0xb3, 0x01, 0x71, 0x07, 0xd5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 47,                     //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5BC5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [48] =
            {

                .name = { 0x05, 0x1b, 0x0b, 0x89, 0x0c, 0x8c, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 48,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5C1A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [49] =
            {

                .name = { 0x08, 0x2b, 0x0b, 0x89, 0x0c, 0x8c, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 49,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5C66, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [50] =
            {

                .name = { 0x05, 0x53, 0x0b, 0x89, 0x0c, 0x8c, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 50,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5CB3, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [51] =
            {

                .name = { 0x09, 0x06, 0x0b, 0x89, 0x0c, 0x8c, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 51,                     //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5D02, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [52] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [53] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [54] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [55] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [56] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [57] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [58] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [59] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [60] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [61] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [62] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [63] =
            {

                .name = { 0xc2, 0xca, 0x0c, 0xe2, 0x0b, 0xdb, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 63,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5D50, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [64] =
            {

                .name = { 0x02, 0xee, 0x01, 0x36, 0x0e, 0xf0, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 64,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5D96, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [65] =
            {

                .name = { 0x01, 0xd4, 0x0d, 0x04, 0x0e, 0xf0, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 65,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5DE5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [66] =
            {

                .name = { 0x01, 0xd4, 0x0c, 0xbd, 0x0e, 0xf0, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 66,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5E35, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [67] =
            {

                .name = { 0x01, 0xd4, 0x04, 0x30, 0x0e, 0xf0, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 67,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5E83, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [68] =
            {

                .name = { 0x0b, 0xcf, 0x0a, 0xa1, 0x0c, 0xc8, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 68,                     //道具编号
                .price = 4800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5ED3, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1735,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [69] =
            {

                .name = { 0xca, 0xca, 0x0c, 0xe2, 0x0b, 0xdb, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 69,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5F20, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1719,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [70] =
            {

                .name = { 0x01, 0xd4, 0x0e, 0x4a, 0x0e, 0xf0, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 70,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5F63, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [71] =
            {

                .name = { 0xca, 0xca, 0x11, 0x26, 0x02, 0xd3, 0x05, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 71,                     //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5FB3, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1719,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [72] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [73] =
            {

                .name = { 0x0c, 0xd9, 0x0e, 0x32, 0x03, 0xc3, 0x0f, 0xa7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 73,                     //道具编号
                .price = 700,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D5FFA, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [74] =
            {

                .name = { 0x10, 0x93, 0x09, 0x94, 0x04, 0x6d, 0x05, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 74,                     //道具编号
                .price = 650,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D604D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [75] =
            {

                .name = { 0x04, 0x6d, 0x05, 0x84, 0x0c, 0xe2, 0x0b, 0xdb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 75,                     //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D60A8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [76] =
            {

                .name = { 0x03, 0xc3, 0x0f, 0xa7, 0x0c, 0xe2, 0x0b, 0xdb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 76,                     //道具编号
                .price = 550,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D60FC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [77] =
            {

                .name = { 0x0c, 0x7c, 0x03, 0x6d, 0x0c, 0xe2, 0x0b, 0xdb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 77,                     //道具编号
                .price = 350,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6151, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [78] =
            {

                .name = { 0x09, 0x94, 0x10, 0xa1, 0x0c, 0xe2, 0x0b, 0xdb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 78,                     //道具编号
                .price = 950,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D61A4, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [79] =
            {

                .name = { 0x0c, 0xd9, 0x04, 0x6d, 0x0c, 0xe2, 0x0b, 0xdb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 79,                     //道具编号
                .price = 350,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D61FA, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E7D,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [80] =
            {

                .name = { 0x0a, 0x5f, 0x0a, 0x5f, 0x0d, 0x4e, 0x0a, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 80,                     //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D624F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A2011,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [81] =
            {

                .name = { 0x0e, 0x1f, 0x0d, 0x78, 0x14, 0x35, 0x0d, 0x78, 0x01, 0x2c, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 81,                     //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6297, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A2011,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [82] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [83] =
            {

                .name = { 0x01, 0x36, 0x0f, 0x48, 0x0a, 0x44, 0x0d, 0xb3, 0x0a, 0xb2, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 83,                     //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 200,          //携带参数
                .description = (u8*)0x083D62DF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1999,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [84] =
            {

                .name = { 0x05, 0x53, 0x07, 0x42, 0x0a, 0x44, 0x0d, 0xb3, 0x0a, 0xb2, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 84,                     //道具编号
                .price = 700,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 250,          //携带参数
                .description = (u8*)0x083D6318, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1999,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [85] =
            {

                .name = { 0x02, 0x89, 0x03, 0x59, 0x0b, 0xdc, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 85,                     //道具编号
                .price = 550,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6351, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1BAD,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [86] =
            {

                .name = { 0x02, 0x7f, 0x02, 0x68, 0x0a, 0x44, 0x0d, 0xb3, 0x0a, 0xb2, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 86,                     //道具编号
                .price = 350,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 100,          //携带参数
                .description = (u8*)0x083D639C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1999,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [87] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [88] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [89] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [90] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [91] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [92] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [93] =
            {

                .name = { 0x0c, 0xac, 0x0e, 0xdd, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 93,                     //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D63D5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1751,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [94] =
            {

                .name = { 0x0f, 0xce, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 94,                     //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D642D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1751,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [95] =
            {

                .name = { 0x05, 0x7d, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 95,                     //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D648D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1751,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [96] =
            {

                .name = { 0x08, 0x4c, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 96,                     //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D64E2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1751,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [97] =
            {

                .name = { 0x0c, 0x51, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 97,                     //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D653F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1751,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [98] =
            {

                .name = { 0x0f, 0x06, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 98,                     //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6598, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1751,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [99] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [100] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [101] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [102] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [103] =
            {

                .name = { 0x0e, 0x2c, 0x09, 0x98, 0x04, 0x85, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 103,                    //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D65EE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [104] =
            {

                .name = { 0x02, 0xd3, 0x09, 0x98, 0x04, 0x85, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 104,                    //道具编号
                .price = 5000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6633, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [105] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [106] =
            {

                .name = { 0x10, 0x57, 0x10, 0xba, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 106,                    //道具编号
                .price = 1400,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6677, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [107] =
            {

                .name = { 0x02, 0xd3, 0x10, 0x57, 0x10, 0xba, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 107,                    //道具编号
                .price = 7500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D66D0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [108] =
            {

                .name = { 0x0e, 0x52, 0x0b, 0x14, 0x10, 0x7f, 0x0b, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 108,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D672C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [109] =
            {

                .name = { 0x0e, 0x52, 0x0b, 0x14, 0x10, 0x7f, 0x0c, 0x8c, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 109,                    //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6778, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [110] =
            {

                .name = { 0x07, 0x42, 0x0b, 0x89, 0x10, 0xba, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 110,                    //道具编号
                .price = 10000,                  //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D67CE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [111] =
            {

                .name = { 0x0e, 0x4f, 0x10, 0x7f, 0x08, 0xae, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 111,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6825, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [112] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [113] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [114] =
            {

                .name = { 0x04, 0xbb, 0x10, 0xa9, 0x04, 0x8f, 0x0d, 0x1f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 114,                      //道具编号
                .price = 10000,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = item114, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [115] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [116] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [117] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [118] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [119] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [120] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [121] =
            {

                .name = { 0x02, 0x4a, 0x0b, 0x89, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 121,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6887, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [122] =
            {

                .name = { 0x04, 0x45, 0x07, 0xe8, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 122,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D68D8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x1,
            },
        [123] =
            {

                .name = { 0x0b, 0x9f, 0x08, 0x94, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 123,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6927, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x2,
            },
        [124] =
            {

                .name = { 0x05, 0x87, 0x0e, 0x40, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 124,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6976, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x3,
            },
        [125] =
            {

                .name = { 0x0c, 0x3c, 0x09, 0xb4, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 125,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D69C7, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x4,
            },
        [126] =
            {

                .name = { 0x01, 0xc3, 0x08, 0x40, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 126,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6A16, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x5,
            },
        [127] =
            {

                .name = { 0x0c, 0x51, 0x10, 0xba, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 127,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6A65, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x6,
            },
        [128] =
            {

                .name = { 0x0f, 0x5e, 0x11, 0x0b, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 128,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6AC0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x7,
            },
        [129] =
            {

                .name = { 0x0b, 0x48, 0x02, 0xd8, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 129,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6B0F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 8,
            },
        [130] =
            {

                .name = { 0x09, 0x66, 0x05, 0x50, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 130,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6B60, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 9,
            },
        [131] =
            {

                .name = { 0x0a, 0xa1, 0x05, 0x8e, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 131,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6BBB, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 10,
            },
        [132] =
            {

                .name = { 0x05, 0x40, 0x07, 0x79, 0x0e, 0x50, 0x10, 0x8e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 132,                    //道具编号
                .price = 50,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6C13, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 0,                       //道具类型
                .fieldUseFunc = (void*) 0x80A11E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 11,
            },
        [133] =
            {

                .name = { 0x08, 0x26, 0x0f, 0x51, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 133,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 2,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6C6B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [134] =
            {

                .name = { 0x0b, 0x8a, 0x08, 0x6a, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 134,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 3,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6CB0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [135] =
            {

                .name = { 0x0c, 0xf1, 0x0c, 0xd3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 135,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 4,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6CEE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [136] =
            {

                .name = { 0x07, 0xee, 0x13, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 136,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 5,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6D30, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [137] =
            {

                .name = { 0x0c, 0x84, 0x08, 0x5b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 137,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 6,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6D72, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [138] =
            {

                .name = { 0x05, 0x1b, 0x0a, 0x76, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 138,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 7,                 //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D6DB4, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16FD,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FF5,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [139] =
            {

                .name = { 0x08, 0x2b, 0x17, 0xde, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 139,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 1,                 //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D6DF8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [140] =
            {

                .name = { 0x0c, 0xf1, 0x0c, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 140,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 8,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6E3C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [141] =
            {

                .name = { 0x09, 0x06, 0x09, 0xad, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 141,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 9,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D6E81, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [142] =
            {

                .name = { 0x0e, 0x10, 0x17, 0x7d, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 142,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 1,                 //携带效果
                .holdEffectParam = 30,           //携带参数
                .description = (u8*)0x083D6EC8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 0x80A16E1,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A1FBD,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [143] =
            {

                .name = { 0x08, 0x26, 0x0e, 0xf3, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 143,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 10,                //携带效果
                .holdEffectParam = 8,            //携带参数
                .description = (u8*)0x083D6F0C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [144] =
            {

                .name = { 0x08, 0x2b, 0x0f, 0x3c, 0x0a, 0xa1, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 144,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 11,                //携带效果
                .holdEffectParam = 8,            //携带参数
                .description = (u8*)0x083D6F4C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [145] =
            {

                .name = { 0x04, 0x34, 0x09, 0x3a, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 145,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 12,                //携带效果
                .holdEffectParam = 8,            //携带参数
                .description = (u8*)0x083D6F8C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [146] =
            {

                .name = { 0x09, 0x06, 0x08, 0x4b, 0x01, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 146,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 13,                //携带效果
                .holdEffectParam = 8,            //携带参数
                .description = (u8*)0x083D6FCC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [147] =
            {

                .name = { 0x0c, 0x84, 0x09, 0xb4, 0x04, 0x97, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 147,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 14,                //携带效果
                .holdEffectParam = 8,            //携带参数
                .description = (u8*)0x083D700C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [148] =
            {

                .name = { 0x05, 0x1b, 0x09, 0x35, 0x13, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 148,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D704C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [149] =
            {

                .name = { 0x08, 0x2b, 0x13, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 149,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D708A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [150] =
            {

                .name = { 0x03, 0xde, 0x07, 0x08, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 150,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D70C8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [151] =
            {

                .name = { 0x0b, 0x02, 0x08, 0x5b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 151,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7106, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [152] =
            {

                .name = { 0x05, 0x53, 0x0d, 0x62, 0x08, 0x5b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 152,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7144, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [153] =
            {

                .name = { 0x05, 0x1b, 0x08, 0xc4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 153,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7182, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [154] =
            {

                .name = { 0x08, 0x2b, 0x04, 0x63, 0x0f, 0xf1, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 154,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D71C0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [155] =
            {

                .name = { 0x03, 0xde, 0x17, 0x68, 0x17, 0x72, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 155,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D71FE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [156] =
            {

                .name = { 0x05, 0x53, 0x01, 0x3e, 0x09, 0x73, 0x04, 0x97, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 156,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D723C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [157] =
            {

                .name = { 0x05, 0x53, 0x07, 0x42, 0x0a, 0x8a, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 157,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D727A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [158] =
            {

                .name = { 0x08, 0x26, 0x0a, 0xea, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 158,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D72B8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [159] =
            {

                .name = { 0x11, 0x07, 0x0c, 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 159,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D72F6, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [160] =
            {

                .name = { 0x0c, 0xf1, 0x0b, 0x9b, 0x10, 0xc2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 160,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7334, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [161] =
            {

                .name = { 0x09, 0x06, 0x09, 0x43, 0x02, 0xe2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 161,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7372, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [162] =
            {

                .name = { 0x0c, 0x84, 0x09, 0xf1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 162,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D73B0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [163] =
            {

                .name = { 0x08, 0x26, 0x08, 0x4b, 0x0a, 0xa1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 163,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D73EE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [164] =
            {

                .name = { 0x11, 0x07, 0x0e, 0xf3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 164,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D742C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [165] =
            {

                .name = { 0x0c, 0xf1, 0x04, 0x97, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 165,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D746A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [166] =
            {

                .name = { 0x07, 0xee, 0x17, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 166,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D74A8, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [167] =
            {

                .name = { 0x03, 0x2c, 0x13, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 167,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D74E6, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [168] =
            {

                .name = { 0x0a, 0xa1, 0x08, 0x22, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 168,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 15,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D7524, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [169] =
            {

                .name = { 0x08, 0xcd, 0x05, 0xbc, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 169,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 16,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D7562, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [170] =
            {

                .name = { 0x0c, 0xed, 0x0c, 0x7c, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 170,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 17,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D75A1, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [171] =
            {

                .name = { 0x05, 0x1b, 0x08, 0xcd, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 171,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 18,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D75DE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [172] =
            {

                .name = { 0x0b, 0x02, 0x0e, 0x5e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 172,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 19,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D761D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [173] =
            {

                .name = { 0x05, 0x1b, 0x0e, 0xdd, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 173,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 20,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D765C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [174] =
            {

                .name = { 0x09, 0x06, 0x0e, 0x52, 0x0c, 0xd3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 174,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 21,                //携带效果
                .holdEffectParam = 4,            //携带参数
                .description = (u8*)0x083D76A1, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [175] =
            {

                .name = { 0x09, 0x6d, 0x10, 0x7f, 0x04, 0xc3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 175,                    //道具编号
                .price = 20,                     //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D76E0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 5,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2069,        //野外使用程序
                .battleUsage = 0x1,         //战斗使用
                .battleUseFunc = (void*) 0x80A2195,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [176] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [177] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [178] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [179] =
            {

                .name = { 0x08, 0x94, 0x04, 0xaa, 0x10, 0x7f, 0x03, 0xde, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 179,                    //道具编号
                .price = 10,                     //道具价格
                .holdEffect = 22,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D771E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [180] =
            {

                .name = { 0x01, 0x36, 0x0b, 0x89, 0x0e, 0xf0, 0x02, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 180,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 23,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D777C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [181] =
            {

                .name = { 0x03, 0x3e, 0x10, 0x6e, 0x01, 0x70, 0x0e, 0x4f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 181,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 24,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D77DF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [182] =
            {

                .name = { 0x0e, 0x90, 0x0d, 0xd4, 0x10, 0xdf, 0x10, 0x94, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 182,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 25,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D783D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [183] =
            {

                .name = { 0x0d, 0xec, 0x04, 0x6d, 0x10, 0x7f, 0x10, 0xd5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 183,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 26,                //携带效果
                .holdEffectParam = 20,           //携带参数
                .description = (u8*)0x083D789F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [184] =
            {

                .name = { 0x01, 0x11, 0x04, 0x11, 0x10, 0x7f, 0x08, 0xb8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 184,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 27,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7900, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [185] =
            {

                .name = { 0x0e, 0x4f, 0x08, 0xbc, 0x0e, 0xf0, 0x02, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 185,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 28,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7969, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [186] =
            {

                .name = { 0x10, 0xd7, 0x01, 0x0d, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 186,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 29,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D79C7, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [187] =
            {

                .name = { 0x0d, 0x5d, 0x10, 0x52, 0x10, 0x7f, 0x10, 0x75, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 187,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 30,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7A22, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [188] =
            {

                .name = { 0x0f, 0x48, 0x0b, 0x89, 0x03, 0x0b, 0x03, 0xde, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 188,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 31,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7A76, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [189] =
            {

                .name = { 0x05, 0x31, 0x0b, 0xcb, 0x07, 0x42, 0x01, 0x8f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 189,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 32,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7AD6, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [190] =
            {

                .name = { 0x07, 0x6b, 0x05, 0x3c, 0x10, 0x7f, 0x04, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 190,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 33,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7B36, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [191] =
            {

                .name = { 0x0e, 0x4f, 0x10, 0x7f, 0x0c, 0x51, 0x03, 0x15, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 191,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 34,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7B93, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [192] =
            {

                .name = { 0x0b, 0xcc, 0x04, 0xc9, 0x10, 0x7f, 0x0e, 0xa9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 192,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 35,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7BE5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [193] =
            {

                .name = { 0x0b, 0xcc, 0x04, 0xc9, 0x10, 0x7f, 0x08, 0xae, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 193,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 36,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7C45, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [194] =
            {

                .name = { 0x0e, 0xb5, 0x0d, 0xb3, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 194,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 37,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7CA4, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [195] =
            {

                .name = { 0x01, 0xd6, 0x01, 0xa1, 0x10, 0x7f, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 195,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 38,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7D02, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [196] =
            {

                .name = { 0x0a, 0xb3, 0x0d, 0xc6, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 196,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 39,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7D53, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [197] =
            {

                .name = { 0x0e, 0x5d, 0x0f, 0xd7, 0x02, 0xee, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 197,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 40,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7DB1, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [198] =
            {

                .name = { 0x07, 0x0b, 0x03, 0x2a, 0x07, 0x65, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 198,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 41,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7E17, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [199] =
            {

                .name = { 0x07, 0x42, 0x0c, 0x39, 0x0d, 0x27, 0x02, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 199,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 42,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7E7A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [200] =
            {

                .name = { 0x0b, 0xdf, 0x03, 0xbc, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 200,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 43,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7EDE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [201] =
            {

                .name = { 0x08, 0xcd, 0x10, 0x7f, 0x08, 0xae, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 201,                    //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 44,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7F37, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [202] =
            {

                .name = { 0x03, 0x2e, 0x0a, 0xb3, 0x0b, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 202,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 45,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D7F79, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [203] =
            {

                .name = { 0x0b, 0x61, 0x0b, 0x6d, 0x0b, 0x91, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 203,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 46,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D7FD5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [204] =
            {

                .name = { 0x0f, 0x60, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 204,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 47,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D8036, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [205] =
            {

                .name = { 0x0a, 0xa1, 0x05, 0x8e, 0x10, 0xa7, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 205,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 48,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D8096, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [206] =
            {

                .name = { 0x05, 0x09, 0x0b, 0x89, 0x0e, 0xc4, 0x07, 0x65, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 206,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 49,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D80FA, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [207] =
            {

                .name = { 0x05, 0x09, 0x0b, 0x89, 0x02, 0xd8, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 207,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 50,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D8158, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [208] =
            {

                .name = { 0x02, 0xa5, 0x0d, 0x04, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 208,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 51,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D81B3, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [209] =
            {

                .name = { 0x0b, 0xcf, 0x09, 0x70, 0x0c, 0x51, 0x03, 0x15, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 209,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 52,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D8214, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [210] =
            {

                .name = { 0x05, 0xcd, 0x0b, 0x71, 0x09, 0xe7, 0x11, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 210,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 53,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D8276, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [211] =
            {

                .name = { 0x03, 0x63, 0x10, 0x5e, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 211,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 54,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D82D6, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [212] =
            {

                .name = { 0x01, 0xd6, 0x0b, 0x5c, 0x01, 0xb6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 212,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 55,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D833B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [213] =
            {

                .name = { 0x11, 0x1f, 0x10, 0xb5, 0x05, 0x31, 0x0b, 0xcb, 0x04, 0x07, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 213,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 56,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D8397, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [214] =
            {

                .name = { 0x0d, 0x4c, 0x0b, 0x1c, 0x03, 0x0b, 0x0c, 0xc1, 0x02, 0x59, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 214,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 57,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D83EC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [215] =
            {

                .name = { 0x09, 0xb4, 0x0c, 0xc0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 215,                    //道具编号
                .price = 9800,                   //道具价格
                .holdEffect = 58,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D844E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [216] =
            {

                .name = { 0x08, 0xcd, 0x10, 0x7f, 0x0e, 0xa9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 216,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 59,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D84AC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [217] =
            {

                .name = { 0x0c, 0x62, 0x02, 0x73, 0x0d, 0x6d, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 217,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 60,                //携带效果
                .holdEffectParam = 10,           //携带参数
                .description = (u8*)0x083D850F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [218] =
            {

                .name = { 0x0b, 0xdb, 0x05, 0xa1, 0x07, 0xb6, 0x0a, 0x67, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 218,                    //道具编号
                .price = 2100,                   //道具价格
                .holdEffect = 61,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D856E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [219] =
            {

                .name = { 0x01, 0x71, 0x07, 0xd5, 0x10, 0x7f, 0x08, 0xb8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 219,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 62,                //携带效果
                .holdEffectParam = 8,            //携带参数
                .description = (u8*)0x083D85BA, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [220] =
            {

                .name = { 0x04, 0xc9, 0x02, 0x33, 0x0e, 0x95, 0x0e, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 220,                    //道具编号
                .price = 9600,                   //道具价格
                .holdEffect = 52,                //携带效果
                .holdEffectParam = 5,            //携带参数
                .description = (u8*)0x083D8616, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [221] =
            {

                .name = { 0x0f, 0x74, 0x0d, 0xf4, 0x0e, 0x95, 0x0e, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 221,                    //道具编号
                .price = 9600,                   //道具价格
                .holdEffect = 22,                //携带效果
                .holdEffectParam = 5,            //携带参数
                .description = (u8*)0x083D8669, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [222] =
            {

                .name = { 0x0e, 0x5d, 0x0f, 0xd7, 0x0b, 0x2d, 0x0c, 0xd8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 222,                    //道具编号
                .price = 10,                     //道具价格
                .holdEffect = 63,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D86C0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [223] =
            {

                .name = { 0x07, 0x42, 0x0c, 0x39, 0x03, 0xde, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 223,                    //道具编号
                .price = 10,                     //道具价格
                .holdEffect = 64,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8709, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [224] =
            {

                .name = { 0x02, 0xb6, 0x04, 0x8f, 0x01, 0x53, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 224,                    //道具编号
                .price = 500,                    //道具价格
                .holdEffect = 65,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8754, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [225] =
            {

                .name = { 0x02, 0x26, 0x02, 0xb0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 225,                    //道具编号
                .price = 200,                    //道具价格
                .holdEffect = 66,                //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D87AB, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [226] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [227] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [228] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [229] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [230] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [231] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [232] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [233] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [234] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [235] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [236] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [237] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [238] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [239] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [240] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [241] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [242] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [243] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [244] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [245] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [246] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [247] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [248] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [249] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [250] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [251] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [252] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [253] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [254] =
            {

                .name = { 0x05, 0x1b, 0x0b, 0x89, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 254,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8802, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [255] =
            {

                .name = { 0x08, 0x2b, 0x0b, 0x89, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 255,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D885F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [256] =
            {

                .name = { 0x03, 0xde, 0x05, 0x1b, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 256,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D88BE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [257] =
            {

                .name = { 0x09, 0x06, 0x0b, 0x89, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 257,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D891B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [258] =
            {

                .name = { 0x05, 0x53, 0x0b, 0x89, 0x0d, 0x1f, 0x07, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 258,                    //道具编号
                .price = 100,                    //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8979, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [259] =
            {

                .name = { 0x09, 0x27, 0x05, 0x04, 0x11, 0x0c, 0x0e, 0x5b, 0x02, 0x37, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 259,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D89D7, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A122D,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [260] =
            {

                .name = { 0x02, 0xda, 0x01, 0x8f, 0x04, 0xf6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 260,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8A14, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1461,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [261] =
            {

                .name = { 0x0e, 0x99, 0x01, 0x63, 0x05, 0x87, 0x0a, 0xb2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 261,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8A66, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1439,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [262] =
            {

                .name = { 0x0a, 0x81, 0x03, 0x3d, 0x04, 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 262,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8ACC, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1339,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [263] =
            {

                .name = { 0x04, 0xe9, 0x03, 0x3d, 0x04, 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 263,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8B23, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1339,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x1,
            },
        [264] =
            {

                .name = { 0x02, 0x2e, 0x05, 0xa1, 0x03, 0x3d, 0x04, 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 264,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8B7B, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1339,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x2,
            },
        [265] =
            {

                .name = { 0x02, 0x8c, 0x0a, 0x6c, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 265,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8BD4, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [266] =
            {

                .name = { 0x05, 0x37, 0x08, 0x6b, 0x0b, 0x7c, 0x0d, 0x10, 0x0e, 0x5b, 0x10, 0x75, 0xFF, 0xFF},        //道具名字
                .itemId = 266,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8C2E, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [267] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [268] =
            {

                .name = { 0x05, 0x1f, 0x05, 0x1f, 0x07, 0x58, 0x0b, 0x77, 0x0c, 0x51, 0x05, 0x27, 0xFF, 0xFF},        //道具名字
                .itemId = 268,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8C8A, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [269] =
            {

                .name = { 0x03, 0x0a, 0x0d, 0x8a, 0x03, 0x0b, 0x0e, 0x5b, 0x08, 0x63, 0x0e, 0x11, 0xFF, 0xFF},        //道具名字
                .itemId = 269,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8CE2, //道具介绍
                .importance = 2,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [270] =
            {

                .name = { 0x05, 0x7d, 0x0b, 0x9b, 0x05, 0x5f, 0x0c, 0x1a, 0x05, 0x9a, 0x02, 0xdc, 0xFF, 0xFF},        //道具名字
                .itemId = 270,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8D37, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [271] =
            {

                .name = { 0x03, 0x1f, 0x0d, 0xe6, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 271,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8D85, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [272] =
            {

                .name = { 0x03, 0xcc, 0x0f, 0xca, 0x11, 0x0c, 0x0e, 0x5b, 0x02, 0x37, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 272,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8DCB, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A122D,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x1,
            },
        [273] =
            {

                .name = { 0x09, 0xd2, 0x08, 0x92, 0x03, 0xc0, 0x08, 0x00, 0x04, 0xf6, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 273,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8E10, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [274] =
            {

                .name = { 0x04, 0x62, 0x02, 0xd3, 0x0d, 0xa7, 0x03, 0x0b, 0x0e, 0x50, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 274,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8E68, //道具介绍
                .importance = 2,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [275] =
            {

                .name = { 0x09, 0x66, 0x05, 0x50, 0x02, 0x8c, 0x0a, 0x6c, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 275,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8EBD, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x1,
            },
        [276] =
            {

                .name = { 0x05, 0x1b, 0x0b, 0x89, 0x01, 0x63, 0x10, 0xba, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 276,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8F2A, //道具介绍
                .importance = 2,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [277] =
            {

                .name = { 0x08, 0x2b, 0x0b, 0x89, 0x01, 0x63, 0x10, 0xba, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 277,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8F7F, //道具介绍
                .importance = 2,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [278] =
            {

                .name = { 0x0c, 0xbe, 0x10, 0x7b, 0x05, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 278,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D8FD5, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [279] =
            {

                .name = { 0xc1, 0xe3, 0xae, 0xc1, 0xe3, 0x05, 0x31, 0x0e, 0xc4, 0x10, 0x49, 0xFF, 0xFF, 0xFF},         //道具名字
                .itemId = 279,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D9025, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [280] =
            {

                .name = { 0x0f, 0xd5, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                //道具名字
                .itemId = 280,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D9083, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [281] =
            {

                .name = { 0xa2, 0x04, 0xeb, 0x03, 0xc2, 0x03, 0x0b, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF},         //道具名字
                .itemId = 281,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D90D7, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [282] =
            {

                .name = { 0xa3, 0x04, 0xeb, 0x03, 0xc2, 0x03, 0x0b, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF},         //道具名字
                .itemId = 282,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D9139, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [283] =
            {

                .name = { 0xa5, 0x04, 0xeb, 0x03, 0xc2, 0x03, 0x0b, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF},         //道具名字
                .itemId = 283,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D919B, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [284] =
            {

                .name = { 0xa7, 0x04, 0xeb, 0x03, 0xc2, 0x03, 0x0b, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF},         //道具名字
                .itemId = 284,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D91FD, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [285] =
            {

                .name = { 0x01, 0xf1, 0x07, 0xf0, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 285,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D925F, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [286] =
            {

                .name = { 0x0c, 0x3c, 0x04, 0x63, 0x05, 0x3c, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 286,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D92BF, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [287] =
            {

                .name = { 0x05, 0xcd, 0x10, 0xd5, 0x05, 0x3c, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 287,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D931A, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [288] =
            {

                .name = { 0x03, 0x0a, 0x0d, 0x8a, 0x04, 0xa3, 0x02, 0x06, 0x07, 0x65, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 288,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083D936F, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [289] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa2, 0xFF, 0xFF},        //道具名字
                .itemId = 289,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486EBE, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [290] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa3, 0xFF, 0xFF},        //道具名字
                .itemId = 290,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848821F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [291] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa4, 0xFF, 0xFF},        //道具名字
                .itemId = 291,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08488614, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [292] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa5, 0xFF, 0xFF},        //道具名字
                .itemId = 292,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084884C5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [293] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa6, 0xFF, 0xFF},        //道具名字
                .itemId = 293,                    //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084833DC, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [294] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa7, 0xFF, 0xFF},        //道具名字
                .itemId = 294,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848400F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [295] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa8, 0xFF, 0xFF},        //道具名字
                .itemId = 295,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486D1C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [296] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa9, 0xFF, 0xFF},        //道具名字
                .itemId = 296,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084882B4, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [297] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xaa, 0xFF, 0xFF},        //道具名字
                .itemId = 297,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848808A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [298] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa1, 0xFF, 0xFF},        //道具名字
                .itemId = 298,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486774, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [299] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa2, 0xFF, 0xFF},        //道具名字
                .itemId = 299,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848687C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [300] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa3, 0xFF, 0xFF},        //道具名字
                .itemId = 300,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08487014, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [301] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa4, 0xFF, 0xFF},        //道具名字
                .itemId = 301,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848371F, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [302] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa5, 0xFF, 0xFF},        //道具名字
                .itemId = 302,                    //道具编号
                .price = 5500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483760, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [303] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa6, 0xFF, 0xFF},        //道具名字
                .itemId = 303,                    //道具编号
                .price = 7500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848386D, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [304] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa7, 0xFF, 0xFF},        //道具名字
                .itemId = 304,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084845C5, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [305] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa8, 0xFF, 0xFF},        //道具名字
                .itemId = 305,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08485857, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [306] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xa9, 0xFF, 0xFF},        //道具名字
                .itemId = 306,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848683A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [307] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa2, 0xaa, 0xFF, 0xFF},        //道具名字
                .itemId = 307,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08485DC1, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [308] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa1, 0xFF, 0xFF},        //道具名字
                .itemId = 308,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486265, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [309] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa2, 0xFF, 0xFF},        //道具名字
                .itemId = 309,                    //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848621B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [310] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa3, 0xFF, 0xFF},        //道具名字
                .itemId = 310,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483BDA, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [311] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa4, 0xFF, 0xFF},        //道具名字
                .itemId = 311,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084865BF, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [312] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa5, 0xFF, 0xFF},        //道具名字
                .itemId = 312,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483E3E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [313] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa6, 0xFF, 0xFF},        //道具名字
                .itemId = 313,                    //道具编号
                .price = 5500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483EC2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [314] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa7, 0xFF, 0xFF},        //道具名字
                .itemId = 314,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483F44, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [315] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa8, 0xFF, 0xFF},        //道具名字
                .itemId = 315,                    //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486187, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [316] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xa9, 0xFF, 0xFF},        //道具名字
                .itemId = 316,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483FC7, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [317] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa3, 0xaa, 0xFF, 0xFF},        //道具名字
                .itemId = 317,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08484098, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [318] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa1, 0xFF, 0xFF},        //道具名字
                .itemId = 318,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486A1B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [319] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa2, 0xFF, 0xFF},        //道具名字
                .itemId = 319,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084872F2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [320] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa3, 0xFF, 0xFF},        //道具名字
                .itemId = 320,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08484353, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [321] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa4, 0xFF, 0xFF},        //道具名字
                .itemId = 321,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08484647, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [322] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa5, 0xFF, 0xFF},        //道具名字
                .itemId = 322,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084885D3, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [323] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa6, 0xFF, 0xFF},        //道具名字
                .itemId = 323,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084835C2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [324] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa7, 0xFF, 0xFF},        //道具名字
                .itemId = 324,                    //道具编号
                .price = 1000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084859F2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [325] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa8, 0xFF, 0xFF},        //道具名字
                .itemId = 325,                    //道具编号
                .price = 2000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08485D77, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [326] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xa9, 0xFF, 0xFF},        //道具名字
                .itemId = 326,                    //道具编号
                .price = 5500,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848493B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [327] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa4, 0xaa, 0xFF, 0xFF},        //道具名字
                .itemId = 327,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08487CD2, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [328] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa1, 0xFF, 0xFF},        //道具名字
                .itemId = 328,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084880D0, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [329] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa2, 0xFF, 0xFF},        //道具名字
                .itemId = 329,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486D64, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [330] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa3, 0xFF, 0xFF},        //道具名字
                .itemId = 330,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486E79, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [331] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa4, 0xFF, 0xFF},        //道具名字
                .itemId = 331,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848759A, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [332] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa5, 0xFF, 0xFF},        //道具名字
                .itemId = 332,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848515E, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [333] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa6, 0xFF, 0xFF},        //道具名字
                .itemId = 333,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084860B7, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [334] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa7, 0xFF, 0xFF},        //道具名字
                .itemId = 334,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848548B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [335] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa8, 0xFF, 0xFF},        //道具名字
                .itemId = 335,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848602B, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [336] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xa9, 0xFF, 0xFF},        //道具名字
                .itemId = 336,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x0848743C, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [337] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa5, 0xaa, 0xFF, 0xFF},        //道具名字
                .itemId = 337,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08487558, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [338] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa6, 0xa1, 0xFF, 0xFF},        //道具名字
                .itemId = 338,                    //道具编号
                .price = 3000,                   //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08487C46, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [339] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa2, 0xFF, 0xFF},        //道具名字
                .itemId = 339,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08482BD5, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [340] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa3, 0xFF, 0xFF},        //道具名字
                .itemId = 340,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08482CD3, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [341] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa4, 0xFF, 0xFF},        //道具名字
                .itemId = 341,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084836D6, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [342] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa5, 0xFF, 0xFF},        //道具名字
                .itemId = 342,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08483A3A, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [343] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa6, 0xFF, 0xFF},        //道具名字
                .itemId = 343,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08484F20, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [344] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa7, 0xFF, 0xFF},        //道具名字
                .itemId = 344,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08486AA6, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [345] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa8, 0xFF, 0xFF},        //道具名字
                .itemId = 345,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x08484986, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [346] =
            {

                .name = { 0x09, 0x70, 0x02, 0x8b, 0x0e, 0x90, 0x0d, 0xd4, 0x05, 0x87, 0xa1, 0xa9, 0xFF, 0xFF},        //道具名字
                .itemId = 346,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x084875E5, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 4,                     //道具口袋
                .type = 1,                       //道具类型
                .fieldUseFunc = (void*) 00000000,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [347] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [348] =
            {

                .name = { 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 0,                      //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DB020, //道具介绍
                .importance = 0,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 1,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [349] =
            {

                .name = { 0x02, 0xd3, 0x09, 0xb4, 0x03, 0x0b, 0x01, 0x5b, 0x04, 0xc4, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 349,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA7D1, //道具介绍
                .importance = 2,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [350] =
            {

                .name = { 0x01, 0x63, 0x07, 0xd7, 0x09, 0x66, 0x03, 0x18, 0x11, 0x0b, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 350,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA81A, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A156D,        //野外使用程序
                .battleUsage = 0x2,         //战斗使用
                .battleUseFunc = (void*) 0x80A1E65,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [351] =
            {

                .name = { 0x09, 0x70, 0x09, 0x74, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 351,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA866, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [352] =
            {

                .name = { 0x11, 0x0c, 0x0e, 0x5b, 0x02, 0x37, 0x03, 0x77, 0x05, 0x48, 0x0b, 0x2f, 0xFF, 0xFF},        //道具名字
                .itemId = 352,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA8B4, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [353] =
            {

                .name = { 0x07, 0x42, 0x05, 0xc4, 0x0e, 0xa9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 353,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA907, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [354] =
            {

                .name = { 0x09, 0x70, 0x09, 0x74, 0x17, 0x43, 0x17, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 354,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA95A, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [355] =
            {

                .name = { 0x07, 0xb6, 0x0a, 0x67, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 355,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DA9BB, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [356] =
            {

                .name = { 0x03, 0x2e, 0x0c, 0xde, 0x03, 0x0b, 0x0f, 0xcb, 0x02, 0x59, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 356,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAA0A, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [357] =
            {

                .name = { 0x01, 0x71, 0x10, 0x7f, 0x05, 0x3c, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 357,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAA64, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [358] =
            {

                .name = { 0x04, 0xb2, 0x07, 0xd5, 0x05, 0x3c, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 358,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAABD, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [359] =
            {

                .name = { 0x0d, 0xc7, 0x08, 0xe4, 0x03, 0xf5, 0x04, 0xa3, 0x02, 0x06, 0x07, 0x65, 0xFF, 0xFF},        //道具名字
                .itemId = 359,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAB13, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 0,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [360] =
            {

                .name = { 0x11, 0x0c, 0x0e, 0x5b, 0x02, 0x37, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 360,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAB59, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A122D,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [361] =
            {

                .name = { 0x02, 0x49, 0x10, 0x65, 0x03, 0x1f, 0x0d, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 361,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAB9F, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1C61,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [362] =
            {

                .name = { 0x10, 0x30, 0x03, 0x5c, 0x0c, 0xbe, 0x02, 0x06, 0x0a, 0xb2, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 362,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DABF7, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1D9D,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [363] =
            {

                .name = { 0x0f, 0x9d, 0x0f, 0x44, 0x05, 0xd7, 0x02, 0x06, 0x0f, 0x17, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 363,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAC51, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1CF9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [364] =
            {

                .name = { 0x05, 0xa7, 0x09, 0xd2, 0x04, 0xf6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 364,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DACA5, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1789,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [365] =
            {

                .name = { 0x0c, 0x3c, 0x04, 0xc3, 0x02, 0xdc, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 365,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAD01, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A1821,        //野外使用程序
                .battleUsage = 0x3,         //战斗使用
                .battleUseFunc = (void*) 0x80A18B9,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [366] =
            {

                .name = { 0x07, 0x1e, 0x0e, 0x90, 0x03, 0x2e, 0x0c, 0x18, 0x05, 0x87, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 366,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAD5C, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 2,                       //道具类型
                .fieldUseFunc = (void*) 0x80A18ED,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [367] =
            {

                .name = { 0x0b, 0x7d, 0x03, 0x01, 0x0d, 0x10, 0x0e, 0x5b, 0x10, 0x75, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 367,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DADAE, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [368] =
            {

                .name = { 0x01, 0xe5, 0x05, 0x16, 0x0d, 0x10, 0x0e, 0x5b, 0x10, 0x75, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 368,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAE08, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [369] =
            {

                .name = { 0x02, 0x0c, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},                  //道具名字
                .itemId = 369,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAE68, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [370] =
            {

                .name = { 0x0b, 0xcf, 0x09, 0x70, 0x03, 0x0b, 0x02, 0x8c, 0x0a, 0x6c, 0xFF, 0xFF, 0xFF, 0xFF},          //道具名字
                .itemId = 370,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAEB6, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [371] =
            {

                .name = { 0x02, 0xec, 0x0b, 0xd8, 0x10, 0x7f, 0x03, 0x01, 0x02, 0x8c, 0x0a, 0x6c, 0xFF, 0xFF},        //道具名字
                .itemId = 371,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAF07, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [372] =
            {

                .name = { 0x0c, 0x3c, 0x04, 0xc3, 0x03, 0xde, 0x0a, 0x7a, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},            //道具名字
                .itemId = 372,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAF52, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A14E9,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [373] =
            {

                .name = { 0x05, 0x1b, 0x01, 0x63, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 373,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAF8D, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
        [374] =
            {

                .name = { 0x08, 0x2b, 0x01, 0x63, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 374,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAFD6, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
		[376] =
            {

                .name = { 0x08, 0x2b, 0x01, 0x63, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 374,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAFD6, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
		[377] =
            {

                .name = { 0x08, 0x2b, 0x01, 0x63, 0x0b, 0xeb, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},              //道具名字
                .itemId = 374,                    //道具编号
                .price = 0,                      //道具价格
                .holdEffect = 0,                 //携带效果
                .holdEffectParam = 0,            //携带参数
                .description = (u8*)0x083DAFD6, //道具介绍
                .importance = 1,                 //重要道具
                .unk19 = 1,              //unk2
                .pocket = 2,                     //道具口袋
                .type = 4,                       //道具类型
                .fieldUseFunc = (void*) 0x80A2239,        //野外使用程序
                .battleUsage = 0x0,         //战斗使用
                .battleUseFunc = (void*) 00000000,       //战斗使用程序
                .secondaryId = 0x0,
            },
};