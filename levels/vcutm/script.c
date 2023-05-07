#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"

#include "levels/vcutm/header.h"
#include "levels/bbh/header.h"

extern u8 _vcutm_segment_ESegmentRomStart[];
extern u8 _vcutm_segment_ESegmentRomEnd[];

const LevelScript level_vcutm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _vcutm_segment_ESegmentRomStart, _vcutm_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
	LOAD_RAW(12, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd),
	LOAD_MIO0(6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd),
	LOAD_RAW(13, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR,           haunted_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP,         geo_bbh_0005B0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM,      geo_bbh_0005E0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF,       geo_bbh_000610),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR,          geo_bbh_000628),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND,         geo_bbh_000640),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB,            geo_bbh_000658),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(29,  haunted_door_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_DL(84, 0x05002e00, 4),
	// LOAD_MODEL_FROM_DL(86, 0x05003120, 4),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_9),
	JUMP_LINK(script_func_global_18),
	JUMP_LINK(local_area_vcutm_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 135, -3901, 679, 5662),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_vcutm_1_[] = {
	AREA(1, Geo_vcutm_1_0x2541700),
	TERRAIN(col_vcutm_1_0xe02d240),
	SET_BACKGROUND_MUSIC(0, 49),
	TERRAIN_TYPE(4),
	JUMP_LINK(local_objects_vcutm_1_),
	JUMP_LINK(local_warps_vcutm_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_vcutm_1_[] = {
	OBJECT_WITH_ACTS(0, -3901, 679, 5662, 0, 135, 0, 0xa0000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(59, -3531, -67, 5236, 0, 0, 0, 0x0,  bhvMerryGoRound, 31),
	OBJECT_WITH_ACTS(29, -3522, 0, 3482, 0, 0, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, 6, 0, -38, 0, 0, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, -1750, 0, 1700, 0, 90, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, -5274, 0, 5228, 0, 90, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, -3526, 0, 6971, 0, 180, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, -1761, 0, 5232, 0, 90, 0, 0x0,  bhvDoor, 31),
	OBJECT_WITH_ACTS(29, 3, 0, 3462, 0, 180, 0, 0x0,  bhvDoor, 31),
	OBJECT_WITH_ACTS(29, 1769, 0, 1700, 0, 90, 0, 0x0,  bhvDoor, 31),
	OBJECT_WITH_ACTS(29, 5280, 0, 1705, 0, 270, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, 3527, 0, 3456, 0, 180, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, 3530, 0, -58, 0, 180, 0, 0x0,  bhvDoor, 31),
	OBJECT_WITH_ACTS(29, 1, 0, 6987, 0, 180, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, 1766, 0, 5232, 0, 270, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(54, 6, 0, 1703, 0, 180, 0, 0x0,  bhvBbhTiltingTrapPlatform, 31),
	OBJECT_WITH_ACTS(55, -865, -2, 5236, 0, 90, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(55, 0, -2, 6061, 0, 0, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(55, -7, -2, 4319, 0, 0, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(55, 818, -2, 5236, 0, 90, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(180, 3534, 50, 1705, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(55, 3531, -1, -1678, 0, 0, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(0, 3534, 50, 1705, 0, 0, 0, 0x1000000,  bhvLllRotatingBlockWithFireBars, 31),
	OBJECT_WITH_ACTS(55, 3531, -1, -3520, 0, 0, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(55, 3531, -1, -4441, 0, 0, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(55, 3531, -1, -2599, 0, 0, 0, 0x0,  bhvBbhTumblingBridge, 31),
	OBJECT_WITH_ACTS(0, -43, -188, -4815, 0, 0, 0, 0x0,  bhvBowserCourseRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, 0, 332, 5236, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 6, 0, 1703, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -3531, 391, 5236, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 3534, 143, 1705, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 3528, 0, -2969, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 181, -623, -2076, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -984, -623, -5411, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 1106, -633, -5204, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -989, -623, -1828, 0, 0, 0, 0x0,  bhvUnagi, 31),
	OBJECT_WITH_ACTS(215, 1144, -623, -2029, 0, 0, 0, 0x0,  bhvUnagi, 31),
	OBJECT_WITH_ACTS(215, 149, -623, -5103, 0, 0, 0, 0x0,  bhvUnagi, 31),
	OBJECT_WITH_ACTS(215, 3531, 0, -3729, 0, 0, 0, 0x0,  bhvMovingBlueCoin, 31),
	OBJECT_WITH_ACTS(215, 3528, 0, -2353, 0, 0, 0, 0x0,  bhvMovingBlueCoin, 31),
	OBJECT_WITH_ACTS(215, 2957, 196, -3226, 0, 0, 0, 0x0,  bhvMovingBlueCoin, 31),
	OBJECT_WITH_ACTS(215, 3037, 317, -1782, 0, 0, 0, 0x0,  bhvMovingBlueCoin, 31),
	OBJECT_WITH_ACTS(215, 4124, -45, -3930, 0, 0, 0, 0x0,  bhvMovingBlueCoin, 31),
	OBJECT_WITH_ACTS(215, 3905, 196, -2721, 0, 0, 0, 0x0,  bhvMovingBlueCoin, 31),
	OBJECT_WITH_ACTS(0, 0, 0, 5236, 0, 0, 0, 0x0,  bhvMrI, 31),
	OBJECT_WITH_ACTS(54, 4289, 316, -5740, 0, 0, 0, 0x0,  bhvBbhTiltingTrapPlatform, 31),
	OBJECT_WITH_ACTS(54, 4544, 649, -5501, 0, 90, 0, 0x0,  bhvBbhTiltingTrapPlatform, 31),
	OBJECT_WITH_ACTS(54, 4289, 982, -5740, 0, 0, 0, 0x0,  bhvBbhTiltingTrapPlatform, 31),
	OBJECT_WITH_ACTS(85, 2901, 28, -4743, 0, 0, 0, 0x20000,  bhvCapSwitch, 31),
	OBJECT_WITH_ACTS(137, 3530, 160, -5522, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -1599, -300, -2925, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -1599, -300, -4325, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 3541, 1219, -7027, 0, 0, 0, 0xb0000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -61, 427, -1653, 0, 180, 0, 0xc0000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(122, 3005, 396, -6300, 0, 0, 0, 0x1000000,  bhvStar, 31),
	RETURN()
};

const LevelScript local_warps_vcutm_1_[] = {
	WARP_NODE(10, 18, 1, 10, 0),
	WARP_NODE(11, 18, 1, 12, 0),
	WARP_NODE(12, 18, 1, 11, 0),
	WARP_NODE(13, 18, 1, 14, 0),
	WARP_NODE(14, 18, 1, 13, 0),
	WARP_NODE(240, 31, 1, 144, 0),
	WARP_NODE(241, 31, 1, 145, 0),
	WARP_NODE(0, 18, 1, 10, 0),
	WARP_NODE(1, 18, 1, 10, 0),
	WARP_NODE(2, 18, 1, 10, 0),
	WARP_NODE(3, 18, 1, 10, 0),
	WARP_NODE(4, 18, 1, 10, 0),
	WARP_NODE(5, 18, 1, 10, 0),
	WARP_NODE(6, 18, 1, 10, 0),
	RETURN()
};