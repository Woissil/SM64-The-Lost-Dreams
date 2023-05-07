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

#include "levels/wmotr/header.h"
#include "levels/castle_inside/header.h"

extern u8 _wmotr_segment_ESegmentRomStart[];
extern u8 _wmotr_segment_ESegmentRomEnd[];

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _castle_insideSegmentRomStart, _castle_insideSegmentRomEnd),
	LOAD_RAW(0x0E, _wmotr_segment_ESegmentRomStart, _wmotr_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
	LOAD_RAW(12, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd),
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
	JUMP_LINK(script_func_global_16),
	JUMP_LINK(local_area_wmotr_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 90, 0, 100, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_wmotr_1_[] = {
	AREA(1, Geo_wmotr_1_0x3721700),
	TERRAIN(col_wmotr_1_0xe01d150),
	SET_BACKGROUND_MUSIC(0, 38),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_wmotr_1_),
	JUMP_LINK(local_warps_wmotr_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_wmotr_1_[] = {
	OBJECT_WITH_ACTS(0, -5010, 1199, 0, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 615, 520, -1450, 0, 0, 0, 0x100000,  bhvInstantActiveWarp, 31),
	OBJECT_WITH_ACTS(0, 1600, 520, -1450, 0, 0, 0, 0x200000,  bhvInstantActiveWarp, 31),
	OBJECT_WITH_ACTS(0, 615, 520, 1450, 0, 0, 0, 0x300000,  bhvInstantActiveWarp, 31),
	OBJECT_WITH_ACTS(0, 1600, 580, 1450, 0, 0, 0, 0x400000,  bhvInstantActiveWarp, 31),
	OBJECT_WITH_ACTS(122, 615, 520, -1450, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 1600, 520, -1450, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 615, 520, 1450, 0, 180, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 1600, 520, 1450, 0, 180, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, 2000, 284, 0, 0, 0, 0, 0x0,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(34, -9609, 0, -2, 0, 90, 0, 0xa000000,  bhvDoor, 31),
	OBJECT_WITH_ACTS(34, -3000, -2, -3745, 0, 330, 0, 0xf000000,  bhvDoor, 31),
	OBJECT_WITH_ACTS(34, -3064, -2, 3779, 0, 210, 0, 0x14000000,  bhvDoor, 31),
	OBJECT_WITH_ACTS(29, -10968, -3, -2, 0, 270, 0, 0x0,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, -2303, -3, -4912, 0, 150, 0, 0x10000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(29, -2382, -3, 4959, 0, 30, 0, 0x20000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(0, 8085, 112, 0, 0, 270, 0, 0x30000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(187, -405, 22, -1225, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, -5669, 9, 689, 0, 0, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(221, 1139, 0, -50, 0, 243, 0, 0x52000000,  bhvToadMessage, 31),
	OBJECT_WITH_ACTS(124, 615, 0, -1134, 0, 0, 0, 0x7c0000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(124, 1600, 0, -1134, 0, 0, 0, 0x7d0000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(124, 615, 0, 1134, 0, 180, 0, 0x7e0000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(124, 1600, 0, 1134, 0, 180, 0, 0x7f0000,  bhvSunkenShipPart2, 31),
	OBJECT_WITH_ACTS(0, 7300, 31, -12, 0, 0, 0, 0x40000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 2075, 368, 753, 0, 236, 0, 0x50000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(24, -479, 0, -940, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, -5371, 0, -613, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 2092, 0, -817, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(24, 7756, 0, -466, 0, 0, 0, 0x0,  bhvTree, 31),
	OBJECT_WITH_ACTS(0, -5200, 64, 0, 0, 90, 0, 0x910000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -5200, 64, 0, 0, 90, 0, 0x900000,  bhvAirborneStarCollectWarp, 31),
	//OBJECT_WITH_ACTS(0, 2, 4, 72, 12, 0, 0, 0,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 180, 6, 0, 0, 1,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 2, 4, 96, 6, 0, 0, 2,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 2, 4, 96, 6, 0, 0, 3,  editor_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 2, 4, 96, 9, 0, 0, 4,  editor_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_wmotr_1_[] = {
	WARP_NODE(10, 31, 1, 10, 0),
	WARP_NODE(144, 31, 1, 144, 0),
	WARP_NODE(145, 31, 1, 145, 0),
	WARP_NODE(48, 31, 1, 10, 0),
	WARP_NODE(64, 31, 1, 10, 0),
	WARP_NODE(240, 16, 1, 4, 0),
	WARP_NODE(241, 26, 1, 3, 0),
	WARP_NODE(0, 18, 1, 10, 0),
	WARP_NODE(1, 28, 1, 10, 0),
	WARP_NODE(2, 29, 1, 10, 0),
	WARP_NODE(3, 36, 1, 10, 0),
	WARP_NODE(4, 31, 1, 5, 0),
	WARP_NODE(5, 31, 1, 4, 0),
	WARP_NODE(16, 31, 1, 16, 0),
	WARP_NODE(32, 31, 1, 32, 0),
	WARP_NODE(6, 9, 1, 10, 0),
	WARP_NODE(6, 9, 1, 10, 0),
	RETURN()
};