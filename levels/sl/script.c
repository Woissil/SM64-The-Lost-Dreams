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

#include "levels/sl/header.h"
#include "levels/castle_inside/header.h"

extern u8 _sl_segment_ESegmentRomStart[];
extern u8 _sl_segment_ESegmentRomEnd[];

const LevelScript level_sl_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _castle_insideSegmentRomStart, _castle_insideSegmentRomEnd),
	LOAD_RAW(0x0E, _sl_segment_ESegmentRomStart, _sl_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd),
	LOAD_RAW(12, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd),
	LOAD_MIO0(6, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd),
	LOAD_RAW(13, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP,        castle_geo_000F18),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND,  castle_geo_001530),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND,    castle_geo_001548),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM,     castle_geo_001518),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR,        castle_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR,        wooden_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR,         metal_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS,       castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR,        castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS,       castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR,           key_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS,  castle_geo_000F00),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(28,  castle_door_geo),
	LOAD_MODEL_FROM_GEO(29,  wooden_door_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	LOAD_MODEL_FROM_GEO(39,  wooden_door_geo),
	LOAD_MODEL_FROM_GEO(41,  metal_door_geo),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_11),
	JUMP_LINK(script_func_global_16),
	JUMP_LINK(local_area_sl_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 135, 0, 100, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_sl_1_[] = {
	AREA(1, Geo_sl_1_0x1a41700),
	TERRAIN(col_sl_1_0xe039e28),
	SET_BACKGROUND_MUSIC(0, 32),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_sl_1_),
	JUMP_LINK(local_warps_sl_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_sl_1_[] = {
	OBJECT_WITH_ACTS(0, 399, 0, -239, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(221, 331, 0, 155, 0, -154, 0, 0x87000000,  bhvToadMessage, 31),
	OBJECT_WITH_ACTS(0, 1680, 3835, -5523, 0, -153, 0, 0xc0000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 1980, -2938, 6618, 0, -151, 0, 0xe0000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(34, -298, 3, -794, 0, 0, 0, 0x0,  bhvDoor, 31),
	OBJECT_WITH_ACTS(27, 651, -1524, 6665, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 186, -1510, 5843, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 1731, -1671, 7154, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 1852, -1280, 5869, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 4116, -1229, 7730, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 4656, -1357, 7200, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 5389, -1864, 7446, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 5620, -1820, 5751, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 6382, -1920, 4688, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, 6977, -1803, 4154, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, -2044, -1726, 3775, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, -3139, -1795, 4036, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, -3523, -1737, 1861, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, -3426, -1710, 836, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(27, -4043, -1716, -93, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(0, -6142, 1923, -5686, 0, 0, 0, 0x0,  bhvWaterfallSoundLoop, 31),
	OBJECT_WITH_ACTS(0, 1280, -397, 5994, 0, 0, 0, 0x0,  bhvBirdsSoundLoop, 31),
	OBJECT_WITH_ACTS(0, -786, 284, -4, 0, 0, 0, 0x60000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, -786, 284, -50, 0, 0, 0, 0x60000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, -786, 284, 50, 0, 0, 0, 0x60000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(100, 992, 171, -2468, 0, 312, 0, 0x540000,  Bhv_Custom_0x13003b78, 31),
	OBJECT_WITH_ACTS(195, 692, 0, -1301, 0, 81, 0, 0x20000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(195, 605, 100, -2470, 0, 114, 0, 0x30000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(85, -186, 0, -2479, 0, 22, 0, 0xa10000,  bhvPyramidElevator, 31),
	OBJECT_WITH_ACTS(102, 977, 167, -1388, 0, 0, 0, 0x8c0000,  Bhv_Custom_0x13003b90, 31),
	OBJECT_WITH_ACTS(0, 700, 0, -190, 0, 270, 0, 0x700000,  bhvSignOnWall, 31),
	OBJECT_WITH_ACTS(0, 702, 0, 126, 0, 270, 0, 0x710000,  bhvSignOnWall, 31),
	OBJECT_WITH_ACTS(0, -626, 0, -1183, 0, 90, 0, 0x6f0000,  bhvSignOnWall, 31),
	OBJECT_WITH_ACTS(0, 1299, 0, -1748, 0, 270, 0, 0x6d0000,  bhvSignOnWall, 31),
	OBJECT_WITH_ACTS(0, 1297, 36, -2030, 0, 270, 0, 0x6e0000,  bhvSignOnWall, 31),
	OBJECT_WITH_ACTS(222, 276, 0, -1959, 0, 340, 0, 0x7000000,  Bhv_Custom_0x13003ba8, 31),
	//OBJECT_WITH_ACTS(0, 64, 5, 120, 9, 0, 0, 30,  editor_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_sl_1_[] = {
	WARP_NODE(10, 9, 1, 10, 0),
	WARP_NODE(11, 9, 1, 12, 0),
	WARP_NODE(12, 9, 1, 11, 0),
	WARP_NODE(13, 9, 1, 14, 0),
	WARP_NODE(14, 9, 1, 13, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	WARP_NODE(0, 9, 1, 10, 0),
	WARP_NODE(1, 9, 1, 10, 0),
	WARP_NODE(2, 9, 1, 10, 0),
	WARP_NODE(3, 9, 1, 10, 0),
	WARP_NODE(4, 9, 1, 10, 0),
	WARP_NODE(5, 9, 1, 10, 0),
	WARP_NODE(6, 16, 1, 141, 0),
	RETURN()
};