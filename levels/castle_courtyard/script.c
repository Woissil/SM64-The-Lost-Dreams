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

#include "levels/castle_courtyard/header.h"
#include "levels/rr/header.h"

extern u8 _castle_courtyard_segment_ESegmentRomStart[];
extern u8 _castle_courtyard_segment_ESegmentRomEnd[];

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _rr_segment_7SegmentRomStart, _rr_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _rrSegmentRomStart, _rrSegmentRomEnd),
	LOAD_RAW(0x0E, _castle_courtyard_segment_ESegmentRomStart, _castle_courtyard_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd),
	LOAD_RAW(12, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd),
	LOAD_MIO0(6, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd),
	LOAD_RAW(13, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,           rr_geo_000660),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04,           rr_geo_000678),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05,           rr_geo_000690),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06,           rr_geo_0006A8),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07,           rr_geo_0006C0),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08,           rr_geo_0006D8),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09,           rr_geo_0006F0),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A,           rr_geo_000708),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B,           rr_geo_000720),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C,           rr_geo_000738),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D,           rr_geo_000758),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E,           rr_geo_000770),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F,           rr_geo_000788),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10,           rr_geo_0007A0),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11,           rr_geo_0007B8),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12,           rr_geo_0007D0),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13,           rr_geo_0007E8),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14,           rr_geo_000800),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_15,           rr_geo_000818),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_16,           rr_geo_000830),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_SLIDING_PLATFORM,         rr_geo_0008C0),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_FLYING_CARPET,            rr_geo_000848),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_OCTAGONAL_PLATFORM,       rr_geo_0008A8),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_ROTATING_BRIDGE_PLATFORM, rr_geo_000878),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_TRIANGLE_PLATFORM,        rr_geo_0008D8),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_CRUISER_WING,             rr_geo_000890),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_SEESAW_PLATFORM,          rr_geo_000908),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_L_SHAPED_PLATFORM,        rr_geo_000940),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_SWINGING_PLATFORM,        rr_geo_000860),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_DONUT_PLATFORM,           rr_geo_000920),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_ELEVATOR_PLATFORM,        rr_geo_0008F0),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES,         rr_geo_000958),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME1,  rr_geo_000970),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME2,  rr_geo_000988),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME3,  rr_geo_0009A0),
	    LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME4,  rr_geo_0009B8),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
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
	JUMP_LINK(script_func_global_16),
	JUMP_LINK(local_area_castle_courtyard_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 135, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_castle_courtyard_1_[] = {
	AREA(1, Geo_castle_courtyard_1_0x3041700),
	TERRAIN(col_castle_courtyard_1_0xe02f1d0),
	SET_BACKGROUND_MUSIC(0, 37),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_courtyard_1_),
	JUMP_LINK(local_warps_castle_courtyard_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_castle_courtyard_1_[] = {
	OBJECT_WITH_ACTS(37, -1117, 0, -76, 0, 270, 0, 0x2000000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(37, -1117, 0, 73, 0, 90, 0, 0x2010000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(145, -105, 643, 3297, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(145, -105, 643, 4205, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(137, 4743, 878, -3197, 0, 253, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 4238, 1750, 5108, 0, 0, 0, 0x0,  bhvWaterfallSoundLoop, 31),
	OBJECT_WITH_ACTS(142, 3850, 0, 4697, 0, 0, 0, 0x10000,  bhvWaterMist2, 31),
	OBJECT_WITH_ACTS(142, 4196, 0, 4671, 0, 0, 0, 0x20000,  bhvWaterMist2, 31),
	OBJECT_WITH_ACTS(142, 4509, 0, 4707, 0, 0, 0, 0x30000,  bhvWaterMist2, 31),
	OBJECT_WITH_ACTS(187, 464, 78, 1149, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 1389, 75, 1069, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 2335, 72, 1022, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 956, 69, -1290, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 2425, 76, -1333, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 6779, 83, 1120, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(212, 2835, 586, -3968, 0, 90, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 4170, 9, 3439, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 319, 310, 3756, 0, 90, 0, 0x30000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, 3838, 708, -5853, 0, 0, 0, 0x20000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(24, 4601, 544, -3401, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 8628, 163, 340, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 8779, 76, 2812, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 2979, 3, 688, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 1637, 6, -1289, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 6493, 115, 4164, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 2289, 91, 4376, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 6099, 40, -1275, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(123, 7447, 87, 4268, 0, 0, 0, 0x31000000,  Bhv_Custom_0x13000d24, 31),
	OBJECT_WITH_ACTS(0, 7447, 247, 4268, 0, 0, 0, 0x450000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 3850, 544, -4394, 0, 0, 0, 0x1a0000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 7447, 83, 3696, 0, 180, 0, 0x1b0000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 1630, 610, -79, 0, 270, 0, 0x1c0000,  bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(124, 7823, 87, 3784, 0, 197, 0, 0x360000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(124, 7250, 43, -1342, 0, 339, 0, 0x240000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(124, 4253, 544, -4853, 0, 0, 0, 0x210000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(124, 9102, 95, 2150, 0, 266, 0, 0x9f0000,  bhvSunkenShipPart2, 31),
	//OBJECT_WITH_ACTS(46, 319, 310, 3756, 0, 0, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	//OBJECT_WITH_ACTS(0, 64, 5, 21, 12, 0, 0, 51,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 8, 5, 24, 6, 0, 0, 52,  editor_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_castle_courtyard_1_[] = {
	WARP_NODE(1, 16, 1, 112, 0),
	WARP_NODE(11, 9, 1, 12, 0),
	WARP_NODE(12, 9, 1, 11, 0),
	WARP_NODE(13, 9, 1, 14, 0),
	WARP_NODE(14, 9, 1, 13, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 16, 1, 3, 0),
	WARP_NODE(0, 16, 1, 105, 0),
	WARP_NODE(28, 26, 1, 28, 0),
	WARP_NODE(2, 20, 1, 10, 0),
	WARP_NODE(3, 31, 1, 10, 0),
	WARP_NODE(69, 8, 1, 10, 0),
	WARP_NODE(26, 26, 1, 26, 0),
	WARP_NODE(27, 26, 1, 27, 0),
	RETURN()
};