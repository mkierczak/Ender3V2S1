/**
 * DWIN general defines and data structs for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 3.13.3
 * Date: 2022/05/18
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#pragma once

// #define DEBUG_DWIN 1

#if MB(CREALITY_V24S1_301, CREALITY_V24S1_301F4)
  #define DASH_REDRAW 1
#endif

#if DISABLED(PROBE_MANUALLY) && ANY(AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_3POINT, AUTO_BED_LEVELING_UBL)
  #define HAS_ONESTEP_LEVELING 1
#endif

#if !HAS_BED_PROBE && ENABLED(BABYSTEPPING)
  #define JUST_BABYSTEP 1
#endif

#if ANY(BABYSTEPPING, HAS_BED_PROBE)
  #define HAS_ZOFFSET_ITEM 1
#endif

#define Def_Background_Color  RGB( 1, 12,  8)
#define Def_Cursor_Color      RGB(20, 49, 31)
#define Def_TitleBg_Color     RGB( 0, 23, 16)
#define Def_TitleTxt_Color    Color_White
#define Def_Text_Color        Color_White
#define Def_Selected_Color    Select_Color
#define Def_SplitLine_Color   RGB( 0, 23, 16)
#define Def_Highlight_Color   Color_White
#define Def_StatusBg_Color    RGB( 0, 23, 16)
#define Def_StatusTxt_Color   Color_Yellow
#define Def_PopupBg_Color     Color_Bg_Window
#define Def_PopupTxt_Color    Popup_Text_Color
#define Def_AlertBg_Color     Color_Bg_Red
#define Def_AlertTxt_Color    Color_Yellow
#define Def_PercentTxt_Color  Percent_Color
#define Def_Barfill_Color     BarFill_Color
#define Def_Indicator_Color   Color_White
#define Def_Coordinate_Color  Color_White
#define Def_Button_Color      RGB( 0, 23, 16)
#define Def_Leds_Color        0xFFFFFFFF
#define Def_CaseLight_Brightness 255
#ifdef Z_AFTER_HOMING
  #define DEF_Z_AFTER_HOMING Z_AFTER_HOMING
#else
  #define DEF_Z_AFTER_HOMING 0
#endif
#define DEF_HOTENDPIDT PREHEAT_1_TEMP_HOTEND
#define DEF_BEDPIDT PREHEAT_1_TEMP_BED
#define DEF_PIDCYCLES 5

//=============================================================================
// Only for Professional Firmware UI extensions
//=============================================================================

#if ENABLED(HAS_GCODE_PREVIEW) && DISABLED(PROUI_EX)
  #error "HAS_GCODE_PREVIEW requires PROUI_EX."
#endif
#if ENABLED(HAS_TOOLBAR) && DISABLED(PROUI_EX)
  #error "HAS_TOOLBAR requires PROUI_EX."
#endif
#if ENABLED(CV_LASER_MODULE) && DISABLED(PROUI_EX)
  #error "CV_LASER_MODULE requires PROUI_EX."
#endif
#if ENABLED(PROUI_EX) && (PROBING_MARGIN!=10)
  #error "PROUI_EX requires a PROBING_MARGIN of 10."
#endif

#if PROUI_EX

  #include <stddef.h>
  #include "../../../core/types.h"

  #define TBMaxOpt 5                    // Amount of shortcuts on screen
  #if HAS_BED_PROBE
    #define DEF_TBOPT {1, 2, 3, 4, 5}   // Default shorcuts for ALB/UBL
  #else
    #define DEF_TBOPT {1, 2, 5, 6, 7};  // Default shortcuts for MM
  #endif

  #include "proui.h"

  #undef X_BED_SIZE
  #undef Y_BED_SIZE
  #undef X_MIN_POS
  #undef Y_MIN_POS
  #undef X_MAX_POS
  #undef Y_MAX_POS
  #undef Z_MAX_POS
  #undef NOZZLE_PARK_POINT
  #if HAS_MESH
    #undef GRID_MAX_POINTS_X
    #undef GRID_MAX_POINTS_Y
    #undef GRID_MAX_POINTS
    #undef MESH_MIN_X
    #undef MESH_MAX_X
    #undef MESH_MIN_Y
    #undef MESH_MAX_Y
  #endif
  #if HAS_BED_PROBE
    #undef Z_PROBE_FEEDRATE_SLOW
  #endif
  #undef INVERT_E0_DIR

  #define X_BED_SIZE (float)PRO_data.x_bed_size
  #define Y_BED_SIZE (float)PRO_data.y_bed_size
  #define X_MIN_POS  (float)PRO_data.x_min_pos
  #define Y_MIN_POS  (float)PRO_data.y_min_pos
  #define X_MAX_POS  (float)PRO_data.x_max_pos
  #define Y_MAX_POS  (float)PRO_data.y_max_pos
  #define Z_MAX_POS  (float)PRO_data.z_max_pos
  #define NOZZLE_PARK_POINT {(float)PRO_data.Park_point.x, (float)PRO_data.Park_point.y, (float)PRO_data.Park_point.z}
  #if HAS_MESH
    #define GRID_MAX_POINTS_X PRO_data.grid_max_points
    #define GRID_MAX_POINTS_Y PRO_data.grid_max_points
    #define GRID_MAX_POINTS (PRO_data.grid_max_points * PRO_data.grid_max_points)
    #define MESH_MIN_X PRO_data.mesh_min_x
    #define MESH_MAX_X PRO_data.mesh_max_x
    #define MESH_MIN_Y PRO_data.mesh_min_y
    #define MESH_MAX_Y PRO_data.mesh_max_y
  #endif
  #if HAS_BED_PROBE
    #define Z_PROBE_FEEDRATE_SLOW PRO_data.zprobefeedslow
  #endif
  #define INVERT_E0_DIR PRO_data.Invert_E0

#endif  // PROUI_EX
