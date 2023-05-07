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

#include "levels/bowser_2/header.h"
extern u8 _bowser_2_segment_ESegmentRomStart[];
extern u8 _bowser_2_segment_ESegmentRomEnd[];

const LevelScript level_bowser_2_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bowser_2_segment_7SegmentRomStart, _bowser_2_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bowser_2SegmentRomStart, _bowser_2SegmentRomEnd),
	LOAD_RAW(0x0E, _bowser_2_segment_ESegmentRomStart, _bowser_2_segment_ESegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd),
	LOAD_RAW(12, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd),
	LOAD_MIO0(6, _group12_mio0SegmentRomStart, _group12_mio0SegmentRomEnd),
	LOAD_RAW(13, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_2_TILTING_ARENA, bowser_2_geo_000170),
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
	JUMP_LINK(script_func_global_2),
	JUMP_LINK(script_func_global_13),
	JUMP_LINK(local_area_bowser_2_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 100, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bowser_2_1_[] = {
	AREA(1, Geo_bowser_2_1_0x3881700),
	TERRAIN(col_bowser_2_1_0xe00ab28),
	SET_BACKGROUND_MUSIC(0, 42),
	TERRAIN_TYPE(1),
	JUMP_LINK(local_objects_bowser_2_1_),
	JUMP_LINK(local_warps_bowser_2_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bowser_2_1_[] = {
	OBJECT_WITH_ACTS(0, 1250, -278, -1250, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(155, 0, -714, 0, 0, 0, 0, 0x0,  bhvTiltingBowserLavaPlatform, 31),
	OBJECT_WITH_ACTS(100, -971, -714, 1084, 0, 136, 0, 0x0,  bhvBowser, 31),
	OBJECT_WITH_ACTS(179, 2525, -714, 2515, 0, 359, 0, 0x0,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(22, 1855, -474, -472, 0, 287, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 1855, -474, -472, 0, 287, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 1855, -474, -472, 0, 287, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 1855, -474, -472, 0, 287, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -1635, -234, 6, 0, 95, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 1603, -144, 759, 0, 239, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, 451, -384, 1677, 0, 185, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -151, -324, -2003, 0, 0, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(22, -1399, -564, -978, 0, 61, 0, 0x0,  bhvBoo, 31),
	OBJECT_WITH_ACTS(194, -1057, -655, 1053, 0, 315, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 1443, -655, 391, 0, 75, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -394, -655, -1462, 0, 195, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(144, -6345, 1080, 6453, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, -6341, 1080, -6394, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, 8726, 1080, -2264, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, 8713, 1080, 2286, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, -2384, 1080, 8704, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(144, -2381, 1080, -8678, 0, 0, 0, 0x0,  bhvFlame, 31),
	OBJECT_WITH_ACTS(179, -2453, -714, -2551, 0, 0, 0, 0x0,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(179, 2483, -714, -2505, 0, 0, 0, 0x10000,  bhvBowserBomb, 31),
	OBJECT_WITH_ACTS(179, -2571, -714, 2486, 0, 0, 0, 0x10000,  bhvBowserBomb, 31),
	//OBJECT_WITH_ACTS(46, 1250, -278, -1250, 0, 0, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	//OBJECT_WITH_ACTS(0, 4, 5, 36, 0, 0, 0, 0,  editor_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_bowser_2_1_[] = {
	WARP_NODE(10, 9, 1, 10, 0),
	WARP_NODE(11, 9, 1, 12, 0),
	WARP_NODE(12, 9, 1, 11, 0),
	WARP_NODE(13, 9, 1, 14, 0),
	WARP_NODE(14, 9, 1, 13, 0),
	WARP_NODE(240, 36, 1, 14, 0),
	WARP_NODE(241, 19, 1, 69, 0),
	WARP_NODE(0, 9, 1, 10, 0),
	WARP_NODE(1, 9, 1, 10, 0),
	WARP_NODE(2, 9, 1, 10, 0),
	WARP_NODE(3, 9, 1, 10, 0),
	WARP_NODE(4, 9, 1, 10, 0),
	WARP_NODE(5, 9, 1, 10, 0),
	WARP_NODE(6, 9, 1, 10, 0),
	RETURN()
};