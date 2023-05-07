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

#include "levels/castle_inside/header.h"
extern u8 _castle_inside_segment_ESegmentRomStart[];
extern u8 _castle_inside_segment_ESegmentRomEnd[];

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _castle_insideSegmentRomStart, _castle_insideSegmentRomEnd),
	LOAD_RAW(0x0E, _castle_inside_segment_ESegmentRomStart, _castle_inside_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom23068352_skybox_mio0SegmentRomStart, _SkyboxCustom23068352_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd),
	LOAD_RAW(12, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd),
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
	JUMP_LINK(script_func_global_8),
	JUMP_LINK(script_func_global_16),
	JUMP_LINK(local_area_castle_inside_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 135, 0, 100, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_castle_inside_1_[] = {
	AREA(1, Geo_castle_inside_1_0x14c1700),
	TERRAIN(col_castle_inside_1_0xe00dfd0),
	SET_BACKGROUND_MUSIC(0, 0),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_inside_1_),
	JUMP_LINK(local_warps_castle_inside_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_castle_inside_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 4096, 0, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(37, -73, 2, -3838, 0, 0, 0, 0x10000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(37, 79, 2, -3838, 0, 180, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(31, -74, 3, 3813, 0, 0, 0, 0xe0000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(31, 71, 3, 3813, 0, 180, 0, 0xe0000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(22, -17, 74, 944, 0, 180, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 563, 74, 2627, 0, 180, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -462, 74, 1519, 0, 180, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 12, 74, 2181, 0, 180, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -14, 111, 170, 0, 180, 0, 0x0,  bhvBooInCastle, 31),
	OBJECT_WITH_ACTS(54, 0, 0, 0, 0, 0, 90, 0x230000,  bhvClockHourHand, 31),
	OBJECT_WITH_ACTS(54, 0, 0, 500, 0, 0, 90, 0x230000,  Bhv_Custom_0x13001c78, 31),
	OBJECT_WITH_ACTS(54, 0, 0, 1000, 0, 0, 0, 0x230000,  Bhv_Custom_0x13001c64, 31),
	OBJECT_WITH_ACTS(221, 100, 0, -1949, 0, 180, 0, 0x86000000,  bhvToadMessage, 31),
	//OBJECT_WITH_ACTS(46, 0, 0, -3776, 0, 0, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(0, 0, 30, 3122, 0, 0, 0, 0x420000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(54, 0, 12, 2465, 90, 0, 0, 0x32000000,  bhvRacingPenguin, 31),
	OBJECT_WITH_ACTS(0, 0, -292, 2465, 0, 0, 0, 0x32000000,  Bhv_Custom_0x1300539c, 31),
	OBJECT_WITH_ACTS(0, 0, 170, 2465, 0, 0, 0, 0x450000,  bhvFadingWarp, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 174, 0, 0, 0, 0,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 381, 9, 0, 0, 1,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 381, 3, 0, 0, 2,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 174, 12, 0, 0, 3,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 381, 6, 0, 0, 4,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 381, 0, 0, 0, 5,  editor_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_castle_inside_1_[] = {
	WARP_NODE(10, 9, 1, 10, 0),
	WARP_NODE(69, 34, 1, 10, 0),
	WARP_NODE(12, 9, 1, 11, 0),
	WARP_NODE(13, 9, 1, 14, 0),
	WARP_NODE(14, 21, 1, 10, 0),
	WARP_NODE(240, 16, 1, 4, 0),
	WARP_NODE(241, 16, 1, 3, 0),
	WARP_NODE(0, 16, 1, 0, 0),
	WARP_NODE(1, 16, 1, 1, 0),
	WARP_NODE(2, 9, 1, 10, 0),
	WARP_NODE(3, 9, 1, 10, 0),
	WARP_NODE(66, 6, 1, 66, 0),
	WARP_NODE(5, 9, 1, 10, 0),
	WARP_NODE(6, 10, 1, 10, 0),
	RETURN()
};