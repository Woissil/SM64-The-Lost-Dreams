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

#include "levels/bowser_1/header.h"
#include "levels/bbh/header.h"

extern u8 _bowser_1_segment_ESegmentRomStart[];
extern u8 _bowser_1_segment_ESegmentRomEnd[];

const LevelScript level_bowser_1_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _bowser_1_segment_ESegmentRomStart, _bowser_1_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd),
	LOAD_RAW(12, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd),
	LOAD_MIO0(6, _group12_mio0SegmentRomStart, _group12_mio0SegmentRomEnd),
	LOAD_RAW(13, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd),
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
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_10),
	JUMP_LINK(script_func_global_13),
	JUMP_LINK(local_area_bowser_1_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 135, 0, 40, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bowser_1_1_[] = {
	AREA(1, Geo_bowser_1_1_0x35c1700),
	TERRAIN(col_bowser_1_1_0xe0095e0),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(4),
	JUMP_LINK(local_objects_bowser_1_1_),
	JUMP_LINK(local_warps_bowser_1_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bowser_1_1_[] = {
	OBJECT_WITH_ACTS(0, 0, -2226, 0, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(100, 0, -2783, -1700, 0, 0, 0, 0x0,  bhvBowser, 31),
	OBJECT_WITH_ACTS(101, -33, -2550, -3726, 0, 0, 0, 0x0,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(101, 3127, -2550, -175, 0, 0, 0, 0x0,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(101, -3268, -2550, -175, 0, 0, 0, 0x0,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(101, -33, -2550, 2957, 0, 0, 0, 0x0,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(180, -1256, -2651, -2318, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -2149, -2651, -1384, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -2147, -2651, 978, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -1235, -2651, 1907, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 1134, -2651, 1923, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 2111, -2651, 1052, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 2068, -2651, -1366, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 1125, -2651, -2317, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(22, -782, -2667, -1627, 0, 0, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 812, -2667, -1630, 0, 0, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -2033, -2667, 406, 0, 103, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 2059, -2667, 488, 0, 252, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -560, -2667, 1947, 0, 180, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 615, -2667, 1911, 0, 180, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(86, -1157, -2783, -1336, 0, 48, 0, 0x0,  bhvHauntedChair, 31),
	OBJECT_WITH_ACTS(86, -1259, -2783, 889, 0, 131, 0, 0x0,  bhvHauntedChair, 31),
	OBJECT_WITH_ACTS(86, 1140, -2783, 1041, 0, 226, 0, 0x0,  bhvHauntedChair, 31),
	OBJECT_WITH_ACTS(86, 1108, -2783, -1367, 0, 144, 0, 0x0,  bhvHauntedChair, 31),
	RETURN()
};

const LevelScript local_warps_bowser_1_1_[] = {
	WARP_NODE(10, 9, 1, 10, 0),
	WARP_NODE(11, 9, 1, 12, 0),
	WARP_NODE(12, 9, 1, 11, 0),
	WARP_NODE(13, 9, 1, 14, 0),
	WARP_NODE(14, 9, 1, 13, 0),
	WARP_NODE(240, 16, 1, 90, 0),
	WARP_NODE(241, 17, 1, 69, 0),
	WARP_NODE(0, 9, 1, 10, 0),
	WARP_NODE(1, 9, 1, 10, 0),
	WARP_NODE(2, 9, 1, 10, 0),
	WARP_NODE(3, 9, 1, 10, 0),
	WARP_NODE(4, 9, 1, 10, 0),
	WARP_NODE(5, 9, 1, 10, 0),
	WARP_NODE(6, 9, 1, 10, 0),
	RETURN()
};