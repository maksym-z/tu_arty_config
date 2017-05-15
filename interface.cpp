#include "common.hpp"
#define TU_ARTY_GUI_GRID_X	(0)
#define TU_ARTY_GUI_GRID_Y	(0)
#define TU_ARTY_GUI_GRID_W	(0.025)
#define TU_ARTY_GUI_GRID_H	(0.04)

class TU_ARTY_D {
	
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "uiNamespace setVariable ['TU_ARTY_Display', _this select 0]; if (scriptDone tu_arty_dials_handle) then {tu_arty_dials_handle = [vehicle player] execVM 'dials.sqf'}; ctrlEnable [1900, false];";
	onKeyDown = "_this call tu_arty_fnc_keydown_EH;";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "TU_ARTY_D";
/*  	class RscText;
	class RscPicture;
	class RscButton;
	class RscSlider;  */
    class controls {
		class RscPicture_1200: RscPicture
			{
				idc = 1200;
				type = 0;
				style = 48;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "\tu_arty\data\sight_unit.paa";
				x = -13 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 0 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 20 * TU_ARTY_GUI_GRID_W;
				h = 25 * TU_ARTY_GUI_GRID_H;
				colorText[] = {1,1,1,0.7};
				colorBackground[] = {1,1,1,0.7};
				colorActive[] = {1,1,1,0.7};
			};

			class RscButton_1600: RscButton
			{
				idc = 1600;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "+"; //--- ToDo: Localize;
				x = -1 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 20 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 1.2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_increase_elevation; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [-1]) call tu_arty_fnc_el_dial_change;";
			};
		class RscButton_1601: RscButton
			{
				idc = 1601;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "-"; //--- ToDo: Localize;
				x = -5.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 20 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 1.2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_decrease_elevation; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [1]) call tu_arty_fnc_el_dial_change;";
			};
		class RscButton_1602: RscButton
			{
				idc = 1602;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "+"; //--- ToDo: Localize;
				x = -9.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 12 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 1.2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_increase_deflection; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [1]) call tu_arty_fnc_def_change;";
			};
		class RscButton_1603: RscButton
			{
				idc = 1603;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "-"; //--- ToDo: Localize;
				x = -9.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 15 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 1.2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_decrease_deflection; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [-1]) call tu_arty_fnc_def_change;";
			};
		class RscButton_1604: RscButton_1603
			{
				idc = 1604;
				text = "^"; //--- ToDo: Localize;
				x = 3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 6.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				tooltip = $STR_tu_arty_increase_optic_level; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [-1]) call tu_arty_fnc_optic_change;";
			};		
		
		class RscButton_1605: RscButton_1604
			{
				idc = 1605;
				text = "v"; //--- ToDo: Localize;
				x = 3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 7.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 1.2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_decrease_optic_level; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [1]) call tu_arty_fnc_optic_change;";
			};
			
			// "3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X","6.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y"
		class RscSlider_1900: RscSlider
			{
				idc = 1900;
				type = 3;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				x = -0.21;
				y = 0.7;
				w = 0.03;
				h = 0.1;
				colorBackground[] = {-1,-1,-1,0};
				color[] = {0.5,0.5,0.7,1};
				tooltip = $STR_tu_arty_bubble_level; //--- ToDo: Localize;
			};
		class RscText_Def_Small: RscText
			{
				idc = 1000;
				type = 0;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "10"; //--- ToDo: Localize;
				x = -10 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 13.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_deflection_value_small; //--- ToDo: Localize;
			};
		class RscText_Def_Large: RscText
			{
				idc = 1001;
				type = 0;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "30"; //--- ToDo: Localize;
				x = -3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 11 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_deflection_value_large; //--- ToDo: Localize;
			};
		class RscText_1002: RscText
			{
				idc = 1002;
				type = 0;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "8"; //--- ToDo: Localize;
				x = 1.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 16 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_elevation_value_large; //--- ToDo: Localize;
			};
		class RscText_1003: RscText
			{
				idc = 1003;
				type = 0;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "35"; //--- ToDo: Localize;
				x = -3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 19 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2 * TU_ARTY_GUI_GRID_W;
				h = 1 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_elevation_value_small; //--- ToDo: Localize;
			};
	};
 };
 
 ////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by [ODK]Bn_, v1.063, #Luwulu)
////////////////////////////////////////////////////////

class TU_ARTY_PREP_D {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "uiNamespace setVariable ['TU_ARTY_PREP_display', _this select 0]; 0 = [_this select 0] execVM 'prep_diag_init.sqf'";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "TU_ARTY_PREP_D";
	class controls {
		class RscCombo_2100: RscCombo
		{
			idc = 2100;
			x = 15.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 4 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 16 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
			onLBSelChanged = "[] call tu_arty_prep_init_charge_list;";
		};
		class RscText_1000: RscText
		{
			idc = 3000;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1000;
			x = 15.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 1.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 12 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
		};
		class RscText_1001: RscText
		{
			idc = 3001;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1001;
			x = 8.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 4 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
		};
		class RscText_1002: RscText
		{
			idc = 3002;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1002;
			x = 8.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 8 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
		};
		class RscCombo_2101: RscCombo
		{
			idc = 3101;
			x = 15.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 6 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 16 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
		};
		class RscSlider_1900: RscSlider
		{
			idc = 3900;
			x = 15.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 8 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 16 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
			onSliderPosChanged = "[] call tu_arty_prep_update;";
		};
		class RscText_1003: RscText
		{
			idc = 3003;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1003;
			x = 8.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 6 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
		};
		class RscButton_1600: RscButton
		{
			idc = 3600;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscButton_1600;
			x = 18.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 10 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 2 * TU_ARTY_GUI_GRID_H;
			onMouseButtonClick = "[] call tu_arty_prep_start;";
		};
		class RscButton_1601: RscButton
		{
			idc = 3601;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscButton_1601;
			x = 25.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 10 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 2 * TU_ARTY_GUI_GRID_H;
			onMouseButtonClick = "closeDialog 2;";
		};
	};
};