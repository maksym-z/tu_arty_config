class CfgPatches
{
	class tu_arty_config
	{
		units[]={};
		weapons[]={"tu_arty_tables_2b14","tu_arty_tables_m224","tu_arty_tables_120mm","tu_arty_tables_D30","tu_arty_tables_M119","tu_arty_tables_2s3","bn_rhs_weap_D30","bn_rhs_weap_grad"};
		requiredVersion=1.0;
		requiredAddons[]={"A3_Static_F_Gamma", "A3_Weapons_F", "rhs_c_heavyweapons", "bn_csw_load", "bn_te", "ace_maptools", "ace_interaction", "Extended_Eventhandlers", "ace_mk6mortar", "rhs_c_2s3", "ace_spottingscope", "tu_arty"};
	};
};


class CfgFunctions
{
	class tu_arty {
		class myCategory { // отсортировал по алфавиту
			class add_observable {file = "\tu_arty_config\functions\add_observable.sqf";};
			class add_subscriber {file = "\tu_arty_config\functions\add_subscriber.sqf";};
			class add_trackable {file = "\tu_arty_config\functions\add_trackable.sqf";};
			class ammo_cookoff {file = "\tu_arty_config\functions\ammo_cookoff.sqf";};
			class ammo_explode {file = "\tu_arty_config\functions\ammo_explode.sqf";};
			class assign_marker_color {file = "\tu_arty_config\functions\assign_marker_color.sqf";};
			class collapse_aiming_circle {file = "\tu_arty_config\functions\collapse_aiming_circle.sqf";};
			class collective_action {file = "\tu_arty_config\functions\collective_action.sqf";};
			class def_change {file = "\tu_arty_config\functions\def_change.sqf";};
			class deploy_aiming_circle {file = "\tu_arty_config\functions\deploy_aiming_circle.sqf";};
			class el_dial_change {file = "\tu_arty_config\functions\el_dial_change.sqf";};
			class elevate {file = "\tu_arty_config\functions\elevate.sqf";};
			class endShift {file = "\tu_arty_config\functions\end_shift.sqf";};
			class explosion_marker {file = "\tu_arty_config\functions\explosion_marker.sqf";};
			class fired_EH {file = "\tu_arty_config\functions\fired.sqf";};
			class fired_EH_gun {file = "\tu_arty_config\functions\fired_gun.sqf";};
			class firefinder_detection {file = "\tu_arty_config\functions\firefinder_detection.sqf";};
			class firefinder_update_markers {file = "\tu_arty_config\functions\firefinder_update_markers.sqf";};
			class fold_gun {file = "\tu_arty_config\functions\fold_gun.sqf";};
			class give_up_token {file = "\tu_arty_config\functions\give_up_token.sqf";};
			class getIn_EH {file = "\tu_arty_config\functions\GetIn.sqf";};
			class getOut_EH {file = "\tu_arty_config\functions\GetOut.sqf";};
			class handleKeydown {file = "\tu_arty_config\functions\handleKeydown.sqf";};
			class is_shell_detected {file = "\tu_arty_config\functions\is_shell_detected.sqf";};
			class keydown_EH {file = "\tu_arty_config\functions\keydown.sqf";};
			class level_gun {file = "\tu_arty_config\functions\level_gun.sqf";};
			class level_howitzer {file = "\tu_arty_config\functions\level_howitzer.sqf";};
			class optic_change {file = "\tu_arty_config\functions\optic_change.sqf";};
			class proximity_burst {file = "\tu_arty_config\functions\proximity_burst.sqf";};
			class prep_diag_init {file = "\tu_arty_config\functions\prep_diag_init.sqf";};
			class raise_pole {file = "\tu_arty_config\functions\raise_pole.sqf";};
			class request_token {file = "\tu_arty_config\functions\request_token.sqf";};
			class recoil {file = "\tu_arty_config\functions\recoil.sqf";};
			class select_helpers {file = "\tu_arty_config\functions\select_helpers.sqf";};
			class shift {file = "\tu_arty_config\functions\shift.sqf";};
			class tow_stuff {file = "\tu_arty_config\functions\tow_stuff.sqf";};
			class towing_enabled {file = "\tu_arty_config\functions\towing_enabled.sqf";};
			class traverse {file = "\tu_arty_config\functions\traverse.sqf";};
			class unfold_gun {file = "\tu_arty_config\functions\unfold_gun.sqf";};
			class unlevel_gun {file = "\tu_arty_config\functions\unlevel_gun.sqf";};
			class untow_stuff {file = "\tu_arty_config\functions\untow_stuff.sqf";};
			class uav_cam_create {file = "\tu_arty_config\functions\uav_cam_create.sqf";};
			class use_aiming_circle {file = "\tu_arty_config\functions\use_aiming_circle.sqf";};
			class weapon_assembled_EH {file = "\tu_arty_config\functions\weapon_assembled_eh.sqf";};
			class init {
				file = "\tu_arty_config\functions\init.sqf";
				preInit = 1;
				};
//			class prep_init_charge_list {file = "\tu_arty_config\functions\prep_init_charge_list.sqf";};
		};
	};
	
	class ace_mk6mortar {
		class ace_mk6mortar {
			class rangeTablePreCalculatedValues {
				file = "\tu_arty_config\functions\range_table_values.sqf";
				recompile = 1;
			};
		};
	};
};

class Mode_SemiAuto;
class DefaultEventhandlers;

class CfgAmmo
{
	class Sh_82mm_AMOS;
	class bn_82mm_shell: Sh_82mm_AMOS {
		airFriction = -0.00015;
		hit = 100;
		indirectHit = 35;
		indirectHitRange = 18;
		audibleFire = 15;
		ace_frag_metal = 2646;     // metal in grams
		ace_frag_charge = 454;    // explosive in grams
		ace_frag_gurney_c = 2440; // Gurney velocity constant for explosive type. See: http://en.wikipedia.org/wiki/Gurney_equations
		//не знаю константы для ТД, пусть будет тротил
		ace_frag_gurney_k = 1/2;  // Gurney shape factor
		ace_frag_classes[]={"ACE_frag_small","ACE_frag_small_HD","ACE_frag_medium","ACE_frag_medium_HD","ACE_frag_large","ACE_frag_large_HD","ACE_frag_huge"};
		ace_frag_force=1;
		soundFly[] = {"\tu_arty\sound\sound_fly_mortar",0.3,1,200};
		tu_arty_explosion_marker_size = 1;
		tu_arty_explosion_marker_alpha = 1;
		soundHit1[] = {"\tu_arty\sound\explosions\1",2.51189,1,1900};
		soundHit2[] = {"\tu_arty\sound\explosions\2",2.51189,1,1900};
		soundHit3[] = {"\tu_arty\sound\explosions\3",2.51189,1,1900};
		soundHit4[] = {"\tu_arty\sound\explosions\4",2.51189,1,1900};
		soundHit5[] = {"\tu_arty\sound\explosions\5",2.51189,1,1900};
		soundHit6[] = {"\tu_arty\sound\explosions\6",2.51189,1,1900};
		soundHit7[] = {"\tu_arty\sound\explosions\7",2.51189,1,1900};
		soundHit8[] = {"\tu_arty\sound\explosions\8",2.51189,1,1900};
		multiSoundHit[] = {"soundHit1",0.125,"soundHit2",0.125,"soundHit3",0.125,"soundHit4",0.125,"soundHit5",0.125,"soundHit6",0.125,"soundHit7",0.125,"soundHit8",0.125};
		whistleOnFire = 0;
	};
	
	class bn_82mm_smoke: bn_82mm_shell {
//		simulation = "shotSmoke";
		effectsSmoke = "SmokeShellWhiteSmall";
		hit = 5;
		indirectHit = 1;
		indirectHitRange = 1;
		tu_arty_effect = "Smoke";
		ace_frag_metal = 3080;    
		ace_frag_charge = 20;    
		ace_frag_gurney_c = 2440; 
		ace_frag_gurney_k = 1/2;  
		ace_frag_classes[]={"ACE_frag_tiny","ACE_frag_tiny_HD"};
		submunitionAmmo = "SmokeShellArty";
		submunitionConeType[] = {"poissondisc",3};
		submunitionConeAngle = 5;
		triggerDistance = 100;
		simulation = "shotSubmunitions";
		simulationStep = 0.05;
		timeToLive = 180;
		tu_arty_explosion_marker_size = 1;
		tu_arty_explosion_marker_alpha = 0.5;
	};
	
	class bn_82mm_illum: bn_82mm_shell {
		ace_frag_skip = 1;    
		aimAboveDefault = 4;
		aimAboveTarget[] = {30,60,120,180,240,300,360};
		cost = 100;
		effectFlare = "CounterMeasureFlare";
		flareSize = 12;
		hit = 5;
		indirectHit = 1;
		indirectHitRange = 1;
		intensity = 80000;
		lightColor[] = {0.95,0.95,1,0.5};
		model = "\A3\weapons_f\ammo\shell";
		simulation = "shotIlluminating";
		simulationStep = 0.05;
		smokeColor[] = {1,1,1,0.5};
		timeToLive = 120;
		triggerDistance = 100;
		triggerSpeedCoef = 1;
		triggerTime = -1;
		brightness = 2;
		size = 1;
		tu_arty_explosion_marker_size = 1;
		tu_arty_explosion_marker_alpha = 0.2;
		soundFly[] = {""};
	};
	
	class bn_60mm_illum: bn_82mm_illum {
		timeToLive = 100;
		intensity = 60000;
		brightness = 1;
		size = 1;
	};
	
	class bn_120mm_illum: bn_82mm_illum {
		timeToLive = 140;
		intensity = 100000;
		brightness = 3;
		size = 2;
	};
	

	
	class bn_82mm_frag: bn_82mm_shell {
//		simulation = "shotSmoke";
		effectsSmoke = "SmokeShellWhiteSmall";
		hit = 25;
		indirectHit = 5;
		indirectHitRange = 1;
		ace_frag_metal = 2646;   
		ace_frag_charge = 454;   
		ace_frag_gurney_c = 2440;
		ace_frag_gurney_k = 1/2; 
		ace_frag_classes[]={"ACE_frag_small","ACE_frag_small_HD","ACE_frag_medium","ACE_frag_medium_HD","ACE_frag_large","ACE_frag_large_HD","ACE_frag_huge"};
		ace_frag_force=1;
	};
	
	class bn_60mm_shell_frag: bn_82mm_shell {
		hit = 25;
		indirectHit = 5;
		indirectHitRange = 1;
		ace_frag_metal = 1450;   
		ace_frag_charge = 250;   
		ace_frag_gurney_c = 2440;
		ace_frag_gurney_k = 1/2; 
		ace_frag_classes[]={"ACE_frag_small","ACE_frag_small_HD","ACE_frag_medium","ACE_frag_medium_HD","ACE_frag_large","ACE_frag_large_HD"};
		ace_frag_force=1;
		tu_arty_explosion_marker_size = 0.75;
		tu_arty_explosion_marker_alpha = 1;
		soundFly[] = {"\tu_arty\sound\sound_fly_mortar",0.25,1.1,200};
	};
	
	class bn_60mm_frag_prx: bn_60mm_shell_frag {
		tu_arty_explosion_marker_size = 0.8;
		tu_arty_explosion_marker_alpha = 0.9;
	};
	
	class bn_60mm_smoke: bn_60mm_shell_frag {
		hit = 5;
		indirectHit = 1;
		indirectHitRange = 1;
		ace_frag_metal = 15800;   
		ace_frag_charge = 100;   
		ace_frag_gurney_c = 2440; 
		ace_frag_gurney_k = 1/2;  
		ace_frag_classes[]={"ACE_frag_tiny_HD"};
		ace_frag_force=0;
		submunitionAmmo = "SmokeShellArty";
		submunitionConeType[] = {"poissondisc",2};
		submunitionConeAngle = 5;
		triggerDistance = 100;
		simulation = "shotSubmunitions";
		simulationStep = 0.05;
		timeToLive = 180;
		tu_arty_explosion_marker_size = 0.75;
		tu_arty_explosion_marker_alpha = 0.5;
	};
	
	class bn_120mm_shell: bn_82mm_shell {
		hit = 125;
		indirectHit = 50;
		indirectHitRange = 21;
		ace_frag_metal = 13230;   
		ace_frag_charge = 2670;   
		ace_frag_gurney_c = 2440; 
		ace_frag_gurney_k = 1/2;  
		ace_frag_classes[]={"ACE_frag_medium","ACE_frag_medium_HD","ACE_frag_large","ACE_frag_large_HD","ACE_frag_huge","ACE_frag_huge"};
		ace_frag_force=1;
		tu_arty_explosion_marker_size = 1.4;
		tu_arty_explosion_marker_alpha = 1;
		
		soundHit1[] = {"\tu_arty\sound\explosions\1",3.51189,1,1900};
		soundHit2[] = {"\tu_arty\sound\explosions\2",3.51189,1,1900};
		soundHit3[] = {"\tu_arty\sound\explosions\3",3.51189,1,1900};
		soundHit4[] = {"\tu_arty\sound\explosions\4",3.51189,1,1900};
		soundHit5[] = {"\tu_arty\sound\explosions\5",3.51189,1,1900};
		soundHit6[] = {"\tu_arty\sound\explosions\6",3.51189,1,1900};
		soundHit7[] = {"\tu_arty\sound\explosions\7",3.51189,1,1900};
		soundHit8[] = {"\tu_arty\sound\explosions\8",3.51189,1,1900};
		multiSoundHit[] = {"soundHit1",0.125,"soundHit2",0.125,"soundHit3",0.125,"soundHit4",0.125,"soundHit5",0.125,"soundHit6",0.125,"soundHit7",0.125,"soundHit8",0.125};
	};
	
	class bn_120mm_smoke: bn_120mm_shell {
		hit = 5;
		indirectHit = 1;
		indirectHitRange = 1;
		ace_frag_metal = 15800;   
		ace_frag_charge = 100;   
		ace_frag_gurney_c = 2440; 
		ace_frag_gurney_k = 1/2;  
		ace_frag_classes[]={"ACE_frag_medium","ACE_frag_medium_HD"};
		ace_frag_force=0;
		submunitionAmmo = "SmokeShellArty";
		submunitionConeType[] = {"poissondisc",5};
		submunitionConeAngle = 5;
		triggerDistance = 100;
		simulation = "shotSubmunitions";
		simulationStep = 0.05;
		timeToLive = 180;
		tu_arty_explosion_marker_size = 1.4;
		tu_arty_explosion_marker_alpha = 0.5;
	};
	
	class bn_122mm_D4: bn_120mm_smoke {
		hit = 5;
		indirectHit = 1;
		indirectHitRange = 1;
		ace_frag_metal = 15800;   
		ace_frag_charge = 100;   
		ace_frag_gurney_c = 2440; 
		ace_frag_gurney_k = 1/2;  
		ace_frag_classes[]={"ACE_frag_medium","ACE_frag_medium_HD"};
		ace_frag_force=0;
		submunitionAmmo = "SmokeShellArty";
		submunitionConeType[] = {"poissondisc",10};
		submunitionConeAngle = 5;
		triggerDistance = 100;
		simulation = "shotSubmunitions";
		simulationStep = 0.05;
		timeToLive = 180;
		tu_arty_explosion_marker_size = 1.4;
		tu_arty_explosion_marker_alpha = 0.5;
		soundFly[] = {"\tu_arty\sound\sound_fly",0.3,1.6,500};
	};
	
	class bn_122mm_OF_462: bn_120mm_shell {
		hit = 145;
		indirectHit = 45;
		indirectHitRange = 18;
		ace_frag_metal = 18090;   
		ace_frag_charge = 3670;   
		ace_frag_gurney_c = 2440; 
		ace_frag_gurney_k = 1/2;  
		ace_frag_classes[]={"ACE_frag_medium","ACE_frag_medium_HD","ACE_frag_large","ACE_frag_large_HD","ACE_frag_huge","ACE_frag_huge"};
		ace_frag_force=1;
		tu_arty_explosion_marker_size = 1.4;
		tu_arty_explosion_marker_alpha = 1;
		soundFly[] = {"\tu_arty\sound\sound_fly",0.3,1.6,500};
	};
	
	class rhs_ammo_3bk18;
	class bn_122mm_BP1: rhs_ammo_3bk18 {
		hit = 200;
		timeToLive = 45;
		soundFly[] = {"\tu_arty\sound\sound_fly_mortar",0.5,1.6,700};
	};
	
	class bn_122mm_S_463Zh: bn_120mm_illum {
		timeToLive = 160;
		intensity = 120000;
		brightness = 3;
		size = 3;
	};
	
	class SmallSecondary;
	class bn_60mm_proximity_burst: SmallSecondary {
		hit = 25;
		indirectHit = 5;
		indirectHitRange = 1;
		ace_frag_metal = 1450;   
		ace_frag_charge = 250;   
		ace_frag_gurney_c = 2440;
		ace_frag_gurney_k = 1/2; 
		ace_frag_classes[]={"ACE_frag_small","ACE_frag_small_HD","ACE_frag_medium","ACE_frag_medium_HD","ACE_frag_large","ACE_frag_large_HD"};
		ace_frag_force=1;
	};
};

class CfgMagazines
{
	class 8Rnd_82mm_Mo_shells;
	class bn_82mm_shell_0: 8Rnd_82mm_Mo_shells {
		count = 1;
		ammo = "bn_82mm_shell";
		initSpeed = 70;
		model = "\tu_arty\data\ace_arty_82mm_he_shell"; //"\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_0";
		displayName = "82-мм ОФ мина, заряд основной";
		tu_arty_availableCharges[] = {"bn_82mm_shell_1","bn_82mm_shell_2","bn_82mm_shell_3","bn_82mm_shell_4"};
		tu_arty_chargeName = "основной";
		allowedslots[] = {901};
		mass = 40;
	};
	class bn_82mm_shell_1: bn_82mm_shell_0 {
		initSpeed = 120;
		displayName = "82-мм ОФ мина, заряд 1-й";
		picture = "\tu_arty\data\equip\82mm_shell_1";
		tu_arty_base_charge = "bn_82mm_shell_0";
		tu_arty_chargeName = "1-й";
		tu_arty_availableCharges[] = {"bn_82mm_shell_0","bn_82mm_shell_2","bn_82mm_shell_3","bn_82mm_shell_4"};
	};
	class bn_82mm_shell_2: bn_82mm_shell_0 {
		initSpeed = 154;
		displayName = "82-мм ОФ мина, заряд 2-й";
		picture = "\tu_arty\data\equip\82mm_shell_2";
		tu_arty_base_charge = "bn_82mm_shell_0";
		tu_arty_chargeName = "2-й";
		tu_arty_availableCharges[] = {"bn_82mm_shell_0","bn_82mm_shell_1","bn_82mm_shell_3","bn_82mm_shell_4"};
	};
	class bn_82mm_shell_3: bn_82mm_shell_0 {
		initSpeed = 175;
		displayName = "82-мм ОФ мина, заряд 3-й";
		picture = "\tu_arty\data\equip\82mm_shell_3";
		tu_arty_base_charge = "bn_82mm_shell_0";
		tu_arty_chargeName = "3-й";
		tu_arty_availableCharges[] = {"bn_82mm_shell_0","bn_82mm_shell_1","bn_82mm_shell_2","bn_82mm_shell_4"};
	};
	class bn_82mm_shell_4: bn_82mm_shell_0 {
		initSpeed = 196;
		displayName = "82-мм ОФ мина, заряд дальнобойный";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		tu_arty_base_charge = "bn_82mm_shell_0";
		tu_arty_chargeName = "дальнобойный";
		tu_arty_availableCharges[] = {"bn_82mm_shell_1","bn_82mm_shell_2","bn_82mm_shell_3","bn_82mm_shell_0"};
	};
// дым 82 мм	
	class bn_82mm_smoke_0: bn_82mm_shell_0 {
		ammo = "bn_82mm_smoke";
		displayName = "82-мм дымовая мина, заряд основной";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_0";
		tu_arty_effect = "Smoke";
		tu_arty_availableCharges[] = {"bn_82mm_smoke_1","bn_82mm_smoke_2","bn_82mm_smoke_3","bn_82mm_smoke_4"};
	};
	class bn_82mm_smoke_1: bn_82mm_shell_1 {
		ammo = "bn_82mm_smoke";
		displayName = "82-мм дымовая мина, заряд 1-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_1";
		tu_arty_effect = "Smoke";
		tu_arty_base_charge = "bn_82mm_smoke_0";
		tu_arty_availableCharges[] = {"bn_82mm_smoke_0","bn_82mm_smoke_2","bn_82mm_smoke_3","bn_82mm_smoke_4"};
	};
	class bn_82mm_smoke_2: bn_82mm_shell_2 {
		ammo = "bn_82mm_smoke";
		displayName = "82-мм дымовая мина, заряд 2-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_2";
		tu_arty_effect = "Smoke";
		tu_arty_base_charge = "bn_82mm_smoke_0";
		tu_arty_availableCharges[] = {"bn_82mm_smoke_0","bn_82mm_smoke_1","bn_82mm_smoke_3","bn_82mm_smoke_4"};
	};
	class bn_82mm_smoke_3: bn_82mm_shell_3 {
		ammo = "bn_82mm_smoke";
		displayName = "82-мм дымовая мина, заряд 3-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_3";
		tu_arty_effect = "Smoke";
		tu_arty_base_charge = "bn_82mm_smoke_0";
		tu_arty_availableCharges[] = {"bn_82mm_smoke_0","bn_82mm_smoke_1","bn_82mm_smoke_2","bn_82mm_smoke_4"};
	};
	class bn_82mm_smoke_4: bn_82mm_shell_4 {
		ammo = "bn_82mm_smoke";
		displayName = "82-мм дымовая мина, заряд дальнобойный";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		tu_arty_effect = "Smoke";
		tu_arty_base_charge = "bn_82mm_smoke_0";
		tu_arty_availableCharges[] = {"bn_82mm_smoke_1","bn_82mm_smoke_2","bn_82mm_smoke_3","bn_82mm_smoke_0"};
	};

	// 60 мм	
	
	class bn_60mm_shell_0: bn_82mm_shell_0 {
		count = 1;
		ammo = "bn_60mm_shell_frag";
		initSpeed = 62;
		model = "\tu_arty\data\ace_arty_82mm_he_shell"; //"\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_0";
		displayName = "60-мм оск. мина, заряд 0, IMP";
		tu_arty_availableCharges[] = {"bn_60mm_shell_prx_0","bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_4","bn_60mm_shell_prx_4"};
		tu_arty_chargeName = "#0, IMP";
		allowedslots[] = {901};
		mass = 30;
	};
	class bn_60mm_shell_1: bn_60mm_shell_0 {
		initSpeed = 107;
		displayName = "60-мм оск. мина, заряд 1, IMP";
		picture = "\tu_arty\data\equip\82mm_shell_1";
		tu_arty_base_charge = "bn_60mm_shell_0";
		tu_arty_chargeName = "#1, IMP";
		tu_arty_availableCharges[] = {"bn_60mm_shell_0","bn_60mm_shell_prx_0","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_4","bn_60mm_shell_prx_4"};
	};
	class bn_60mm_shell_2: bn_60mm_shell_0 {
		initSpeed = 135;
		displayName = "60-мм оск. мина, заряд 2, IMP";
		picture = "\tu_arty\data\equip\82mm_shell_2";
		tu_arty_base_charge = "bn_60mm_shell_0";
		tu_arty_chargeName = "#2, IMP";
		tu_arty_availableCharges[] = {"bn_60mm_shell_0","bn_60mm_shell_prx_0","bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_4","bn_60mm_shell_prx_4"};
	};
	class bn_60mm_shell_3: bn_60mm_shell_0 {
		initSpeed = 157;
		displayName = "60-мм оск. мина, заряд 3, IMP";
		picture = "\tu_arty\data\equip\82mm_shell_3";
		tu_arty_base_charge = "bn_60mm_shell_0";
		tu_arty_chargeName = "#3, IMP";
		tu_arty_availableCharges[] = {"bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_4","bn_60mm_shell_prx_4","bn_60mm_shell_0","bn_60mm_shell_prx_0"};
	};
	class bn_60mm_shell_4: bn_60mm_shell_0 {
		initSpeed = 174;
		displayName = "60-мм оск. мина, заряд 4, IMP";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		tu_arty_base_charge = "bn_60mm_shell_0";
		tu_arty_chargeName = "#4, IMP";
		tu_arty_availableCharges[] = {"bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_0","bn_60mm_shell_prx_0"};
	};
	
	// PROXIMITY BURST
	
	class bn_60mm_shell_prx_0: bn_60mm_shell_0 {
		ammo = "bn_60mm_frag_prx";
		displayName = "60-мм оск. мина, заряд 0, PRX";
		tu_arty_availableCharges[] = {"bn_60mm_shell_0","bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_4","bn_60mm_shell_prx_4"};
		tu_arty_chargeName = "#0 PRX";
	};
	class bn_60mm_shell_prx_1: bn_60mm_shell_1 {
		displayName = "60-мм оск. мина, заряд 1, PRX";
		ammo = "bn_60mm_frag_prx";
		tu_arty_base_charge = "bn_60mm_shell_prx_0";
		tu_arty_chargeName = "#1 PRX";
		tu_arty_availableCharges[] = {"bn_60mm_shell_0","bn_60mm_shell_prx_0","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_4","bn_60mm_shell_prx_4"};
	};
	class bn_60mm_shell_prx_2: bn_60mm_shell_2 {
		ammo = "bn_60mm_frag_prx";
		displayName = "60-мм оск. мина, заряд 2, PRX";
		tu_arty_base_charge = "bn_60mm_shell_prx_0";
		tu_arty_chargeName = "#2 PRX";
		tu_arty_availableCharges[] = {"bn_60mm_shell_0","bn_60mm_shell_prx_0","bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_4","bn_60mm_shell_prx_4"};
	};
	class bn_60mm_shell_prx_3: bn_60mm_shell_3 {
		ammo = "bn_60mm_frag_prx";
		displayName = "60-мм оск. мина, заряд 3, PRX";
		tu_arty_base_charge = "bn_60mm_shell_prx_0";
		tu_arty_chargeName = "#3 PRX";
		tu_arty_availableCharges[] = {"bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_4","bn_60mm_shell_prx_4","bn_60mm_shell_0","bn_60mm_shell_prx_0"};
	};
	class bn_60mm_shell_prx_4: bn_60mm_shell_4 {
		ammo = "bn_60mm_frag_prx";
		displayName = "60-мм оск. мина, заряд 4, PRX";
		tu_arty_base_charge = "bn_60mm_shell_prx_0";
		tu_arty_chargeName = "#4 PRX";
		tu_arty_availableCharges[] = {"bn_60mm_shell_1","bn_60mm_shell_prx_1","bn_60mm_shell_2","bn_60mm_shell_prx_2","bn_60mm_shell_3","bn_60mm_shell_prx_3","bn_60mm_shell_0","bn_60mm_shell_prx_0"};
	};
	
	// SMOKE
	
	class bn_60mm_smoke_0: bn_60mm_shell_0 {
		count = 1;
		displayName = "60-мм дымовая мина, заряд 0";
		ammo = "bn_60mm_smoke";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_availableCharges[] = {"bn_60mm_smoke_1","bn_60mm_smoke_2","bn_60mm_smoke_3","bn_60mm_smoke_4"};
		tu_arty_chargeName = "#0";
	};

	class bn_60mm_smoke_1: bn_60mm_shell_1 {
		ammo = "bn_60mm_smoke";
		displayName = "60-мм дымовая мина, заряд 1";
		picture = "\tu_arty\data\equip\82mm_shell_1";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_60mm_smoke_0";
		tu_arty_chargeName = "#1";
		tu_arty_availableCharges[] = {"bn_60mm_smoke_0","bn_60mm_smoke_2","bn_60mm_smoke_3","bn_60mm_smoke_4"};
	};
	class bn_60mm_smoke_2: bn_60mm_shell_2 {
		ammo = "bn_60mm_smoke";
		displayName = "60-мм дымовая мина, заряд 2";
		picture = "\tu_arty\data\equip\82mm_shell_2";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_60mm_smoke_0";
		tu_arty_chargeName = "#2";
		tu_arty_availableCharges[] = {"bn_60mm_smoke_0","bn_60mm_smoke_1","bn_60mm_smoke_3","bn_60mm_smoke_4"};
	};
	class bn_60mm_smoke_3: bn_60mm_shell_3 {
		ammo = "bn_60mm_smoke";
		displayName = "60-мм дымовая мина, заряд 3";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_3";
		tu_arty_base_charge = "bn_60mm_smoke_0";
		tu_arty_chargeName = "#3";
		tu_arty_availableCharges[] = {"bn_60mm_smoke_0","bn_60mm_smoke_1","bn_60mm_smoke_2","bn_60mm_smoke_4"};
	};
	class bn_60mm_smoke_4: bn_60mm_shell_4 {
		ammo = "bn_60mm_smoke";
		displayName = "60-мм дымовая мина, заряд 4";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		tu_arty_base_charge = "bn_60mm_smoke_0";
		tu_arty_chargeName = "#4";
		tu_arty_availableCharges[] = {"bn_60mm_smoke_0","bn_60mm_smoke_1","bn_60mm_smoke_2","bn_60mm_smoke_3"};
	};
	
// 120 мм

	class bn_120mm_shell_0: bn_82mm_shell_0 {
		count = 1;
		ammo = "bn_120mm_shell";
		initSpeed = 122;
		model = "\tu_arty\data\ace_arty_82mm_he_shell"; //"\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_0";
		displayName = "120-мм ОФ мина, заряд 1-й";
		tu_arty_availableCharges[] = {"bn_120mm_shell_1","bn_120mm_shell_2","bn_120mm_shell_3","bn_120mm_shell_4","bn_120mm_shell_5"};
		tu_arty_chargeName = "№1";
		allowedslots[] = {901};
		mass = 80;
	};
	class bn_120mm_shell_1: bn_120mm_shell_0 {
		initSpeed = 156;
		displayName = "120-мм ОФ мина, заряд 2-й";
		picture = "\tu_arty\data\equip\80mm_shell_1";
		tu_arty_base_charge = "bn_120mm_shell_0";
		tu_arty_chargeName = "№2";
		tu_arty_availableCharges[] = {"bn_120mm_shell_0","bn_120mm_shell_2","bn_120mm_shell_3","bn_120mm_shell_4","bn_120mm_shell_5"};
	};
	class bn_120mm_shell_2: bn_120mm_shell_0 {
		initSpeed = 191;
		displayName = "120-мм ОФ мина, заряд 3-й";
		picture = "\tu_arty\data\equip\80mm_shell_2";
		tu_arty_base_charge = "bn_120mm_shell_0";
		tu_arty_chargeName = "№3";
		tu_arty_availableCharges[] = {"bn_120mm_shell_0","bn_120mm_shell_1","bn_120mm_shell_3","bn_120mm_shell_4","bn_120mm_shell_5"};
	};
	class bn_120mm_shell_3: bn_120mm_shell_0 {
		initSpeed = 221;
		displayName = "120-мм ОФ мина, заряд 4-й";
		picture = "\tu_arty\data\equip\80mm_shell_3";
		tu_arty_base_charge = "bn_120mm_shell_0";
		tu_arty_chargeName = "№4";
		tu_arty_availableCharges[] = {"bn_120mm_shell_0","bn_120mm_shell_1","bn_120mm_shell_2","bn_120mm_shell_4","bn_120mm_shell_5"};
	};
	class bn_120mm_shell_4: bn_120mm_shell_0 {
		initSpeed = 247;
		displayName = "120-мм ОФ мина, заряд 5-й";
		picture = "\tu_arty\data\equip\80mm_shell_4";
		tu_arty_base_charge = "bn_120mm_shell_0";
		tu_arty_chargeName = "№5";
		tu_arty_availableCharges[] = {"bn_120mm_shell_0","bn_120mm_shell_1","bn_120mm_shell_2","bn_120mm_shell_3","bn_120mm_shell_5"};
	};
	class bn_120mm_shell_5: bn_120mm_shell_0 {
		initSpeed = 276;
		displayName = "120-мм ОФ мина, заряд 6-й";
		picture = "\tu_arty\data\equip\80mm_shell_4";
		tu_arty_base_charge = "bn_120mm_shell_0";
		tu_arty_chargeName = "№6";
		tu_arty_availableCharges[] = {"bn_120mm_shell_0","bn_120mm_shell_1","bn_120mm_shell_2","bn_120mm_shell_3","bn_120mm_shell_4"};
	};
	
	//120 mm smoke
	
	class bn_120mm_smoke_0: bn_120mm_shell_0 {
		count = 1;
		ammo = "bn_120mm_smoke";
		displayName = "120-мм дымовая мина, заряд 1-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_availableCharges[] = {"bn_120mm_smoke_1","bn_120mm_smoke_2","bn_120mm_smoke_3","bn_120mm_smoke_4","bn_120mm_smoke_5"};
		tu_arty_chargeName = "№1";
	};

	class bn_120mm_smoke_1: bn_120mm_shell_1 {
		ammo = "bn_120mm_smoke";
		displayName = "120-мм дымовая мина, заряд 2-й";
		picture = "\tu_arty\data\equip\82mm_shell_1";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_120mm_smoke_0";
		tu_arty_chargeName = "№2";
		tu_arty_availableCharges[] = {"bn_120mm_smoke_0","bn_120mm_smoke_2","bn_120mm_smoke_3","bn_120mm_smoke_4","bn_120mm_smoke_5"};
	};
	class bn_120mm_smoke_2: bn_120mm_shell_2 {
		ammo = "bn_120mm_smoke";
		displayName = "120-мм дымовая мина, заряд 3-й";
		picture = "\tu_arty\data\equip\82mm_shell_2";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_120mm_smoke_0";
		tu_arty_chargeName = "№3";
		tu_arty_availableCharges[] = {"bn_120mm_smoke_1","bn_120mm_smoke_0","bn_120mm_smoke_3","bn_120mm_smoke_4","bn_120mm_smoke_5"};
	};
	class bn_120mm_smoke_3: bn_120mm_shell_3 {
		ammo = "bn_120mm_smoke";
		displayName = "120-мм дымовая мина, заряд 4-й";
		picture = "\tu_arty\data\equip\82mm_shell_3";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_120mm_smoke_0";
		tu_arty_chargeName = "№4";
		tu_arty_availableCharges[] = {"bn_120mm_smoke_1","bn_120mm_smoke_2","bn_120mm_smoke_0","bn_120mm_smoke_4","bn_120mm_smoke_5"};
	};
	class bn_120mm_smoke_4: bn_120mm_shell_4 {
		ammo = "bn_120mm_smoke";
		displayName = "120-мм дымовая мина, заряд 5-й";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_120mm_smoke_0";
		tu_arty_chargeName = "№5";
		tu_arty_availableCharges[] = {"bn_120mm_smoke_1","bn_120mm_smoke_2","bn_120mm_smoke_3","bn_120mm_smoke_0","bn_120mm_smoke_5"};
	};
	class bn_120mm_smoke_5: bn_120mm_shell_5 {
		ammo = "bn_120mm_smoke";
		displayName = "120-мм дымовая мина, заряд 6-й";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";
		tu_arty_base_charge = "bn_120mm_smoke_0";
		tu_arty_chargeName = "№6";
		tu_arty_availableCharges[] = {"bn_120mm_smoke_1","bn_120mm_smoke_2","bn_120mm_smoke_3","bn_120mm_smoke_0","bn_120mm_smoke_4"};
	};
	
	
	class bn_82mm_frag_0: bn_82mm_shell_0 {
		count = 1;
		ammo = "bn_82mm_shell";
		initSpeed = 70;
		model = "\tu_arty\data\ace_arty_82mm_he_shell"; //"\tu_arty\data\ace_arty_82mm_smoke_shell";
		picture = "\tu_arty\data\equip\82mm_shell_0";
		displayName = "82-мм оск. мина, заряд основной";
		tu_arty_availableCharges[] = {"bn_82mm_frag_1","bn_82mm_frag_2","bn_82mm_frag_3","bn_82mm_frag_4"};
		tu_arty_chargeName = "основной";
		allowedslots[] = {901};
		mass = 40;
	};
	class bn_82mm_frag_1: bn_82mm_frag_0 {
		initSpeed = 120;
		displayName = "82-мм оск. мина, заряд 1-й";
		picture = "\tu_arty\data\equip\82mm_shell_1";
		tu_arty_base_charge = "bn_82mm_frag_0";
		tu_arty_chargeName = "1-й";
		tu_arty_availableCharges[] = {"bn_82mm_frag_0","bn_82mm_frag_2","bn_82mm_frag_3","bn_82mm_frag_4"};
	};
	class bn_82mm_frag_2: bn_82mm_frag_0 {
		initSpeed = 154;
		displayName = "82-мм оск. мина, заряд 2-й";
		picture = "\tu_arty\data\equip\82mm_shell_2";
		tu_arty_base_charge = "bn_82mm_frag_0";
		tu_arty_chargeName = "2-й";
		tu_arty_availableCharges[] = {"bn_82mm_frag_1","bn_82mm_frag_0","bn_82mm_frag_3","bn_82mm_frag_4"};
	};
	class bn_82mm_frag_3: bn_82mm_frag_0 {
		initSpeed = 175;
		displayName = "82-мм оск. мина, заряд 3-й";
		picture = "\tu_arty\data\equip\82mm_shell_3";
		tu_arty_base_charge = "bn_82mm_frag_0";
		tu_arty_chargeName = "3-й";
		tu_arty_availableCharges[] = {"bn_82mm_frag_1","bn_82mm_frag_2","bn_82mm_frag_0","bn_82mm_frag_4"};
	};
	class bn_82mm_frag_4: bn_82mm_frag_0 {
		initSpeed = 196;
		displayName = "82-мм оск. мина, заряд дальнобойный";
		picture = "\tu_arty\data\equip\82mm_shell_4";
		tu_arty_base_charge = "bn_82mm_frag_0";
		tu_arty_chargeName = "дальнобойный";
		tu_arty_availableCharges[] = {"bn_82mm_frag_1","bn_82mm_frag_2","bn_82mm_frag_3","bn_82mm_frag_0"};
	};
	
// illumination
	class bn_82mm_illum_0: bn_82mm_shell_0 {
		ammo = "bn_82mm_illum";
		displayName = "82-мм осветительная мина, заряд основной";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_0.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_82mm_illum_1","bn_82mm_illum_3","bn_82mm_illum_2","bn_82mm_illum_4"};
	};
	
	class bn_82mm_illum_1: bn_82mm_shell_1 {
		ammo = "bn_82mm_illum";
		displayName = "82-мм осветительная мина, заряд 1-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_1.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_82mm_illum_0","bn_82mm_illum_2","bn_82mm_illum_4","bn_82mm_illum_3"};
		tu_arty_base_charge = "bn_82mm_illum_0";
	};
	
	class bn_82mm_illum_2: bn_82mm_shell_2 {
		ammo = "bn_82mm_illum";
		displayName = "82-мм осветительная мина, заряд 2-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_2.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_82mm_illum_0","bn_82mm_illum_1","bn_82mm_illum_4","bn_82mm_illum_3"};
		tu_arty_base_charge = "bn_82mm_illum_0";
	};
	
	class bn_82mm_illum_3: bn_82mm_shell_3 {
		ammo = "bn_82mm_illum";
		displayName = "82-мм осветительная мина, заряд 3-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_3.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_82mm_illum_0","bn_82mm_illum_1","bn_82mm_illum_2","bn_82mm_illum_4"};
		tu_arty_base_charge = "bn_82mm_illum_0";
	};
	
	class bn_82mm_illum_4: bn_82mm_shell_4 {
		ammo = "bn_82mm_illum";
		displayName = "82-мм осветительная мина, заряд дальнобойный";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_4.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_82mm_illum_0","bn_82mm_illum_1","bn_82mm_illum_2","bn_82mm_illum_3"};
		tu_arty_base_charge = "bn_82mm_illum_0";
	};
	
	class bn_60mm_illum_0: bn_60mm_shell_0 {
		ammo = "bn_60mm_illum";
		displayName = "60-мм осветительная мина, заряд 0-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_0.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_60mm_illum_1","bn_60mm_illum_2","bn_60mm_illum_3","bn_60mm_illum_4"};
	};
	
	class bn_60mm_illum_1: bn_60mm_shell_1 {
		ammo = "bn_60mm_illum";
		displayName = "60-мм осветительная мина, заряд 1-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_0.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_60mm_illum_0","bn_60mm_illum_2","bn_60mm_illum_4","bn_60mm_illum_3"};
		tu_arty_base_charge = "bn_60mm_illum_0";
	};
	
	class bn_60mm_illum_2: bn_60mm_shell_2 {
		ammo = "bn_60mm_illum";
		displayName = "60-мм осветительная мина, заряд 2-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_0.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_60mm_illum_0","bn_60mm_illum_1","bn_60mm_illum_3","bn_60mm_illum_4"};
		tu_arty_base_charge = "bn_60mm_illum_0";
	};
	
	class bn_60mm_illum_3: bn_60mm_shell_3 {
		ammo = "bn_60mm_illum";
		displayName = "60-мм осветительная мина, заряд 3-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_0.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_60mm_illum_0","bn_60mm_illum_1","bn_60mm_illum_2","bn_60mm_illum_4"};
		tu_arty_base_charge = "bn_60mm_illum_0";
	};
	
	class bn_60mm_illum_4: bn_60mm_shell_4 {
		ammo = "bn_60mm_illum";
		displayName = "60-мм осветительная мина, заряд 4-й";
		model = "\tu_arty\data\ace_arty_82mm_smoke_shell";//"\A3\Weapons_F\Ammo\UGL_Flare";
		picture = "\tu_arty\data\equip\82mm_shell_0.paa";
		tu_arty_effect = "Illumination";
		tu_arty_availableCharges[] = {"bn_60mm_illum_0","bn_60mm_illum_1","bn_60mm_illum_2","bn_60mm_illum_3"};
		tu_arty_base_charge = "bn_60mm_illum_0";
	};
	
	// Д-30
	class rhs_mag_3vo18_10;
	class bn_122mm_OF_462_0: rhs_mag_3vo18_10 {
		ammo = "bn_122mm_OF_462";
		initSpeed = 154.56;
		tu_arty_chargeName = "4-й";
		tu_arty_availableCharges[] = {"bn_122mm_OF_462_1","bn_122mm_OF_462_2","bn_122mm_OF_462_3","bn_122mm_OF_462_4","bn_122mm_OF_462_5"};
		displayName = "122-мм ОФ-462, заряд 4-й";
		count=1;
		model = "\tu_arty\data\bn_122mm";
		picture = "\tu_arty\data\equip\bn_122mm.paa";
		allowedslots[] = {901};
		mass = 160;
	};

	class bn_122mm_OF_462_1: bn_122mm_OF_462_0 {
		initSpeed = 187.6;
		tu_arty_chargeName = "3-й";
		tu_arty_availableCharges[] = {"bn_122mm_OF_462_0","bn_122mm_OF_462_2","bn_122mm_OF_462_3","bn_122mm_OF_462_4","bn_122mm_OF_462_5"};
		displayName = "122-мм ОФ-462, заряд 3-й";
	};

	class bn_122mm_OF_462_2: bn_122mm_OF_462_0 {
		initSpeed = 233.52;
		tu_arty_chargeName = "2-й";
		tu_arty_availableCharges[] = {"bn_122mm_OF_462_0","bn_122mm_OF_462_1","bn_122mm_OF_462_3","bn_122mm_OF_462_4","bn_122mm_OF_462_5"};
		displayName = "122-мм ОФ-462, заряд 2-й";
	};

	class bn_122mm_OF_462_3: bn_122mm_OF_462_0 {
		initSpeed = 276.08;
		tu_arty_chargeName = "1-й";
		tu_arty_availableCharges[] = {"bn_122mm_OF_462_0","bn_122mm_OF_462_1","bn_122mm_OF_462_2","bn_122mm_OF_462_4","bn_122mm_OF_462_5"};
		displayName = "122-мм ОФ-462, заряд 1-й";
	};

	class bn_122mm_OF_462_4: bn_122mm_OF_462_0 {
		initSpeed = 316.4;
		tu_arty_chargeName = "уменьш.";
		tu_arty_availableCharges[] = {"bn_122mm_OF_462_0","bn_122mm_OF_462_1","bn_122mm_OF_462_2","bn_122mm_OF_462_3","bn_122mm_OF_462_5"};
		displayName = "122-мм ОФ-462, заряд уменьш.";
	};

	class bn_122mm_OF_462_5: bn_122mm_OF_462_0 {
		initSpeed = 386.4;
		tu_arty_chargeName = "полный";
		tu_arty_availableCharges[] = {"bn_122mm_OF_462_0","bn_122mm_OF_462_1","bn_122mm_OF_462_2","bn_122mm_OF_462_3","bn_122mm_OF_462_4"};
		displayName = "122-мм ОФ-462, заряд полный";
	};

	class bn_122mm_D4_0: bn_120mm_smoke_0 {
		ammo = "bn_122mm_D4";
		initSpeed = 154.56;
		tu_arty_chargeName = "4-й";
		tu_arty_availableCharges[] = {"bn_122mm_D4_1","bn_122mm_D4_2","bn_122mm_D4_3","bn_122mm_D4_4","bn_122mm_D4_5"};
		displayName = "122-мм дымовой снаряд, заряд 4-й";
		count=1;
		model = "\tu_arty\data\bn_122mm"; //"\A3\Structures_F\Items\Food\BottlePlastic_V1_F";//
		picture = "\tu_arty\data\equip\bn_122mm.paa";
		allowedslots[] = {901};
		mass = 160;
	};

	class bn_122mm_D4_1: bn_122mm_D4_0 {
		initSpeed = 187.6;
		tu_arty_chargeName = "3-й";
		tu_arty_availableCharges[] = {"bn_122mm_D4_0","bn_122mm_D4_2","bn_122mm_D4_3","bn_122mm_D4_4","bn_122mm_D4_5"};
		displayName = "122-мм дымовой снаряд, заряд 3-й";
	};

	class bn_122mm_D4_2: bn_122mm_D4_0 {
		initSpeed = 233.52;
		tu_arty_chargeName = "2-й";
		tu_arty_availableCharges[] = {"bn_122mm_D4_0","bn_122mm_D4_1","bn_122mm_D4_3","bn_122mm_D4_4","bn_122mm_D4_5"};
		displayName = "122-мм дымовой снаряд, заряд 2-й";
	};

	class bn_122mm_D4_3: bn_122mm_D4_0 {
		initSpeed = 276.08;
		tu_arty_chargeName = "1-й";
		tu_arty_availableCharges[] = {"bn_122mm_D4_0","bn_122mm_D4_1","bn_122mm_D4_2","bn_122mm_D4_4","bn_122mm_D4_5"};
		displayName = "122-мм дымовой снаряд, заряд 1-й";
	};

	class bn_122mm_D4_4: bn_122mm_D4_0 {
		initSpeed = 316.4;
		tu_arty_chargeName = "уменьш.";
		tu_arty_availableCharges[] = {"bn_122mm_D4_0","bn_122mm_D4_1","bn_122mm_D4_2","bn_122mm_D4_3","bn_122mm_D4_5"};
		displayName = "122-мм дымовой снаряд, заряд уменьш.";
	};

	class bn_122mm_D4_5: bn_122mm_D4_0 {
		initSpeed = 386.4;
		tu_arty_chargeName = "полный";
		tu_arty_availableCharges[] = {"bn_122mm_D4_0","bn_122mm_D4_1","bn_122mm_D4_2","bn_122mm_D4_3","bn_122mm_D4_4"};
		displayName = "122-мм дымовой снаряд, заряд полный";
	};
	
	class bn_122mm_BP1_0: bn_122mm_OF_462_0 {
		ammo = "bn_122mm_BP1";
		initSpeed = 740.0;
		tu_arty_chargeName = "специальный";
		tu_arty_availableCharges[] = {};
		displayName = "122-мм кумулятивный снаряд, заряд специальный";
		count=1;
		model = "\tu_arty\data\bn_122mm";
		picture = "\tu_arty\data\equip\bn_122mm.paa";
		allowedslots[] = {901};
		mass = 160;
	};
	
	class bn_122mm_S_463Zh_0: bn_122mm_OF_462_0 {
		ammo = "bn_122mm_S_463Zh";
		initSpeed = 187.6;
		tu_arty_chargeName = "3-й";
		tu_arty_availableCharges[] = {"bn_122mm_S_463Zh_1","bn_122mm_S_463Zh_2","bn_122mm_S_463Zh_3","bn_122mm_S_463Zh_4"};
		displayName = "122-мм осветительный, заряд 3-й";
		count=1;
		model = "\tu_arty\data\bn_122mm";
		picture = "\tu_arty\data\equip\bn_122mm.paa";
		allowedslots[] = {901};
		mass = 80;
	};

	class bn_122mm_S_463Zh_1: bn_122mm_S_463Zh_0 {
		initSpeed = 233.52;
		tu_arty_chargeName = "2-й";
		tu_arty_availableCharges[] = {"bn_122mm_S_463Zh_0","bn_122mm_S_463Zh_2","bn_122mm_S_463Zh_3","bn_122mm_S_463Zh_4"};
		displayName = "122-мм осветительный, заряд 2-й";
	};

	class bn_122mm_S_463Zh_2: bn_122mm_S_463Zh_0 {
		initSpeed = 276.08;
		tu_arty_chargeName = "1-й";
		tu_arty_availableCharges[] = {"bn_122mm_S_463Zh_0","bn_122mm_S_463Zh_1","bn_122mm_S_463Zh_3","bn_122mm_S_463Zh_4"};
		displayName = "122-мм осветительный, заряд 1-й";
	};

	class bn_122mm_S_463Zh_3: bn_122mm_S_463Zh_0 {
		initSpeed = 316.4;
		tu_arty_chargeName = "уменьш.";
		tu_arty_availableCharges[] = {"bn_122mm_S_463Zh_0","bn_122mm_S_463Zh_1","bn_122mm_S_463Zh_2","bn_122mm_S_463Zh_4"};
		displayName = "122-мм осветительный, заряд уменьш.";
	};

	class bn_122mm_S_463Zh_4: bn_122mm_S_463Zh_0 {
		initSpeed = 386.4;
		tu_arty_chargeName = "полный";
		tu_arty_availableCharges[] = {"bn_122mm_S_463Zh_0","bn_122mm_S_463Zh_1","bn_122mm_S_463Zh_2","bn_122mm_S_463Zh_3"};
		displayName = "122-мм осветительный, заряд полный";
	};
};

class CfgWeapons
{
	class mortar_82mm;
/* 	class Mode_SemiAuto;*/
	class bn_mortar_82mm: mortar_82mm {
		dispersion = 0.008;
		ballisticsComputer = 0;
		magazines[] = {"bn_82mm_shell_0","bn_82mm_shell_1","bn_82mm_shell_2","bn_82mm_shell_3","bn_82mm_shell_4", "bn_82mm_smoke_0","bn_82mm_smoke_1","bn_82mm_smoke_2","bn_82mm_smoke_3","bn_82mm_smoke_4", "bn_82mm_frag_0","bn_82mm_frag_1","bn_82mm_frag_2","bn_82mm_frag_3","bn_82mm_frag_4","bn_82mm_illum_0","bn_82mm_illum_1","bn_82mm_illum_2","bn_82mm_illum_3","bn_82mm_illum_4"};
		modes[] = {"Single3"};
		magazineReloadTime = 0;
		bn_csw_extra_capacity = 0;
		bn_csw_ReloadTime = 2.7;
		autoReload = 1;
		backgroundReload=1;
		shotFromTurret = 1;
		reloadSound[] = {"\tu_arty\sound\mortar_load_long",1,1,20};
/* 		class Single1: Mode_SemiAuto {
			artillerycharge = 1;
			artillerydispersion = 3.7;
			displayname = "Semi (close)";
			maxrange = 0;
			midrange = 0;
			minrange = 0;
			reloadsound[] = {"A3\Sounds_F\weapons\Mortar\mortar_reload_01", 1, 1, 40};
			reloadtime = 1.8;
			sound[] = {"A3\Sounds_F\weapons\Mortar\mortar_03", 1.25893, 1, 250};
			soundservo[] = {"", 0.0001, 1};
			weaponsoundeffect = "DefaultRifle";
		}; 
		class Single3: Single1 {
		};*/
	};
	
	class bn_mortar_60mm: bn_mortar_82mm {
		ballisticsComputer = 0;
		magazines[] = {"bn_60mm_shell_0","bn_60mm_shell_1","bn_60mm_shell_2","bn_60mm_shell_3","bn_60mm_shell_4","bn_60mm_shell_prx_0","bn_60mm_shell_prx_1","bn_60mm_shell_prx_2","bn_60mm_shell_prx_3","bn_60mm_shell_prx_4","bn_60mm_smoke_0","bn_60mm_smoke_1","bn_60mm_smoke_2","bn_60mm_smoke_3","bn_60mm_smoke_4","bn_60mm_illum_0","bn_60mm_illum_1","bn_60mm_illum_2","bn_60mm_illum_3","bn_60mm_illum_4"};
		modes[] = {"Single3"};
		magazineReloadTime = 0;
		bn_csw_extra_capacity = 0;
		bn_csw_ReloadTime = 2;
		autoReload = 1;
		backgroundReload=1;
		shotFromTurret = 1;
		
		sounds[] = {"StandardSound"};
		class StandardSound {
			weaponSoundEffect = "DefaultRifle";
			begin1[] = {"\tu_arty\sound\60mm", 1, 1, 1400};
			soundBegin[] = {"begin1", 1};
		};
	};
	
	class bn_mortar_120mm: bn_mortar_82mm {
		ballisticsComputer = 0;
		magazines[] = {"bn_120mm_shell_0","bn_120mm_shell_1","bn_120mm_shell_2","bn_120mm_shell_3","bn_120mm_shell_4","bn_120mm_shell_5","bn_120mm_smoke_0","bn_120mm_smoke_1","bn_120mm_smoke_2","bn_120mm_smoke_3","bn_120mm_smoke_4","bn_120mm_smoke_5"};
		modes[] = {"Single3"};
		magazineReloadTime = 0;
		bn_csw_extra_capacity = 0;
		bn_csw_ReloadTime = 4;
		autoReload = 1;
		backgroundReload=1;
		shotFromTurret = 1;
	};
	
	class ACE_ItemCore;
	class InventoryItem_Base_F;
	class tu_arty_tables_2b14: ACE_ItemCore {
		scope = 2;
		displayName = "Таблицы стрельбы (2Б14)";
		model = "\A3\Structures_F\Items\Documents\File1_F.p3d";
		picture = "\tu_arty\data\equip\tables_co";
		mass = 0.2;
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (2Б14)";
		};
	};
	
	class tu_arty_tables_m224: tu_arty_tables_2b14 {
		scope = 2;
		displayName = "Таблицы стрельбы (M224)";
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (M224)";
		};
	};
	
	class tu_arty_tables_120mm: tu_arty_tables_2b14 {
		scope = 2;
		displayName = "Таблицы стрельбы (120 мм)";
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (120 мм)";
		};
	};
	
	class tu_arty_tables_D30: tu_arty_tables_2b14 {
		scope = 2;
		displayName = "Таблицы стрельбы (Д-30)";
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (Д-30)";
		};
};
	
	class tu_arty_tables_M119: tu_arty_tables_2b14 {
		scope = 2;
		displayName = "Таблицы стрельбы (M119)";
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (M119)";
		};
	};
	
	class tu_arty_tables_2s3: tu_arty_tables_2b14 {
		scope = 2;
		displayName = "Таблицы стрельбы (2С3)";
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (2С3)";
		};
	};
	
	class tu_arty_tables_grad: tu_arty_tables_2b14 {
		scope = 2;
		displayName = "Таблицы стрельбы (БМ-21)";
		class ItemInfo: InventoryItem_Base_F {
			mass = 2;
			displayName = "Таблицы стрельбы (БМ-21)";
		};
	};
	
	class Default;
	class Binocular: Default {
		modeloptics = "\tu_arty\data\NWD_M22_4x";
		opticszoommax = 0.0718; //0.0708
		opticszoommin = 0.0718;
	};
	
	class rhs_weap_D30;
	class bn_rhs_weap_D30: rhs_weap_D30 {
		magazines[] = {"bn_122mm_BP1_0","bn_122mm_OF_462_0","bn_122mm_OF_462_1","bn_122mm_OF_462_2","bn_122mm_OF_462_3","bn_122mm_OF_462_4","bn_122mm_OF_462_5","bn_122mm_D4_0","bn_122mm_D4_1","bn_122mm_D4_2","bn_122mm_D4_3","bn_122mm_D4_4","bn_122mm_D4_5","bn_122mm_S_463Zh_0","bn_122mm_S_463Zh_1","bn_122mm_S_463Zh_2","bn_122mm_S_463Zh_3","bn_122mm_S_463Zh_4"};
		dispersion = 0.00020;
		magazineReloadTime = 0;
		bn_csw_ReloadTime = 10;
		modes[] = {"Single1"};	
		
		ace_overpressure_angle = 60;  // Cone in which the damage is applied (in degrees from the muzzle of the cannon)
        ace_overpressure_range = 30;  // Range in meters in which the damage is applied
        ace_overpressure_damage = 0.75;  // Damage multiplier
		
		class Single1: Mode_SemiAuto
		{
			displayName = "Semi";
			sounds[] = {"StandardSound"};
			class StandardSound
			{
				weaponSoundEffect = "DefaultRifle";
				begin1[] = {"A3\Sounds_F\weapons\Cannons\cannon_2",2.51189,1,1500};
				soundBegin[] = {"begin1",1};
			};
			reloadSound[] = {"\tu_arty\sound\load_gun",1,1,20};
			weaponSoundEffect = "DefaultRifle";
			minRange = 0;
			midRange = 0;
			maxRange = 0;
			reloadTime = 0;
			artilleryDispersion = 2;
			artilleryCharge = 1;
		};
	};
	class RocketPods;
	class rhs_weap_grad;
	class bn_rhs_weap_grad: rhs_weap_grad {
		tu_arty_extra_dispersion_w = 0.05;// дополнительное рассеивание по фронту, в радианах
		dispersion = 0.005;
		modes[] = {"Close","Close_salvo"};
		class Close: RocketPods
		{
			displayname = "РС";
			reloadtime = 0.5;
			soundBurst = 0;
			sounds[] = {"StandardSound"};
			artillerycharge = 0.65;
			artillerydispersion = 3;
			maxrange = 22400;
			maxrangeprobab = 0.05;
			midrange = 18000;
			midrangeprobab = 0.55;
			minrange = 3100;
			minrangeprobab = 0.15;
			class StandardSound
			{
				begin1[] = {"A3\Sounds_F\weapons\Rockets\Titan_2",1.77828,1,1500};
				soundBegin[] = {"begin1",1};
				weaponSoundEffect = "DefaultRifle";
			};
		};
		class Close_salvo: Close
		{
			burst = 40;
			displayname = "Пакет";
		};
	};
};

class Extended_FiredBIS_Eventhandlers
{
    class BN_2b14_82mm_Base
    {
        class tu_arty_mortar_fired
        {
			clientFiredBis = "_this call tu_arty_fnc_fired_EH";
        };
    };
	class rhs_2s3tank_base
    {
        class tu_arty_gun_fired
        {
			clientFiredBis = "_this call tu_arty_fnc_fired_EH_gun";
        };
    };
	
	class rhs_D30_base
	    {
        class tu_arty_gun_fired
        {
			clientFiredBis = "_this call tu_arty_fnc_fired_EH_gun";
        };
    };
	
	class TU_ARTY_RHS_BM21
	    {
        class tu_arty_gun_fired
        {
			clientFiredBis = "_this call tu_arty_fnc_fired_EH_gun";
        };
    };
};

class Extended_WeaponAssembled_Eventhandlers
{
    class CAManBase
    {
        class tu_arty_reassemble
        {
			WeaponAssembled = "_this call tu_arty_fnc_weapon_assembled_EH;";
        };
		
/*		class tu_arty_aiming_stake
        {
			WeaponAssembled = "if ((_this select 1) isKindOf 'tu_arty_aiming_stake') then {(_this select 1) enableSimulationGlobal false};";
        };*/
    };
};

class Extended_GetIn_Eventhandlers
{
    class BN_2b14_82mm_Base
    {
        class tu_arty_mortar_getin
        {
			GetIn = "if (local (_this select 2)) then {_this call compile preprocessFileLineNumbers '\bn_te\scripts\hideCompass.sqf'; _this call tu_arty_fnc_getIn_EH}";
        };
    };
	
	class TU_ARTY_HMMWV_Artillery_Radar {
		class tu_arty_an_pvq37_getIn
			{
				GetIn = "if (local (_this select 2)) then {[] spawn tu_arty_fnc_firefinder_update_markers}";
			};
	};
	
	class TU_gaz66_radar {
		class TU_gaz66_radar_getIn
			{
				GetIn = "if (local (_this select 2)) then {[] spawn tu_arty_fnc_firefinder_update_markers; {[_x] call tu_arty_fnc_add_observable} forEach allMissionObjects 'Air'}";
			};
	};
	
	class bn_rhs_zsu234_aa {
		class bn_rhs_zsu234_aa_getIn
			{
				GetIn = "if (local (_this select 2)) then {{[_x] call tu_arty_fnc_add_observable} forEach allMissionObjects 'Air'}";
			};
	};
	
	class rhs_D30_base
	    {
        class tu_arty_gun_get_in
        {
			GetIn = "if (local (_this select 2)) then {[] call tu_arty_fnc_assign_marker_color};";
        };
    };
	
	class TU_ARTY_RHS_BM21
	    {
        class tu_arty_grad_get_in
        {
			GetIn = "if (local (_this select 2)) then {[] call tu_arty_fnc_assign_marker_color};";
        };
    };
	
	
};

class Extended_Init_Eventhandlers
{
    class BN_2b14_82mm_Base
    {
        class tu_arty_mortar_init
        {
			init = "(_this select 0) setVariable ['tu_arty_elevation_dial',1000]";
        };
    };
	
	class TU_ARTY_HMMWV_Artillery_Radar {
		class tu_arty_an_pvq37_init
			{
				init = "(_this select 0) setVariable ['tu_arty_firefinder',1,true]; [(_this select 0)] remoteExecCall ['tu_arty_fnc_add_subscriber',0,true];";
			};
	};
	
	class TU_gaz66_radar {
		class tu_arty_an_pvq37_init
			{
				init = "(_this select 0) setVariable ['tu_arty_firefinder',1,true]; [(_this select 0)] remoteExecCall ['tu_arty_fnc_add_subscriber',0,true];";
			};
	};
	
	class bn_rhs_zsu234_aa {
		class bn_rhs_zsu234_aa_init
			{
				init = "(_this select 0) setVariable ['tu_arty_firefinder',1,true]; [(_this select 0)] remoteExecCall ['tu_arty_fnc_add_subscriber',0,true];";
			};
	};
};

class Extended_GetOut_Eventhandlers
{
    class BN_2b14_82mm_Base
    {
        class tu_arty_mortar_getout
        {
			GetOut = "if (local (_this select 2)) then {_this execVM '\bn_te\scripts\hideCompass.sqf'; _this call tu_arty_fnc_getOut_EH}";
        };
    };
};

class Extended_Explosion_Eventhandlers
{
    class ACE_Box_Misc
    {
        class tu_arty_cookoff
        {
			Hit = "if ((getDammage (_this select 0) > 0.1) && {!((_this select 0) getVariable ['tu_arty_cookoff_in_progress', false])}) then {[_this select 0] spawn tu_arty_fnc_ammo_cookoff};";
        };
    };
};

class CfgVehicles
{
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
		 	class TU_ARTY_Open_Table_2B14 {
			  displayName = "Таблицы стрельбы (2Б14)";
			  condition = "'tu_arty_tables_2b14' in (items _player)";
			  statement = "['bn_mortar_82mm'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};
			class TU_ARTY_Open_Table_M224 {
			  displayName = "Таблицы стрельбы (M224)";
			  condition = "'tu_arty_tables_m224' in (items _player)";
			  statement = "['bn_mortar_60mm'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};
			class TU_ARTY_Open_Table_120mm {
			  displayName = "Таблицы стрельбы (120 мм)";
			  condition = "'tu_arty_tables_120mm' in (items _player)";
			  statement = "['bn_mortar_120mm'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};
			class TU_ARTY_Open_Table_D30 {
			  displayName = "Таблицы стрельбы (Д-30)";
			  condition = "'tu_arty_tables_D30' in (items _player)";
			  statement = "['bn_rhs_weap_D30'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};
			class TU_ARTY_Open_Table_M119 {
			  displayName = "Таблицы стрельбы (M119)";
			  condition = "'tu_arty_tables_M119' in (items _player)";
			  statement = "['rhs_weap_M119'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};
			class TU_ARTY_Open_Table_2s3 {
			  displayName = "Таблицы стрельбы (2С3)";
			  condition = "'tu_arty_tables_2s3' in (items _player)";
			  statement = "['bn_rhs_weap_2a33'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};
			class TU_ARTY_Open_Table_grad {
			  displayName = "Таблицы стрельбы (БМ-21)";
			  condition = "'tu_arty_tables_grad' in (items _player)";
			  statement = "['bn_rhs_weap_grad'] call tu_arty_fnc_open_table";
			  showDisabled = 0;
			  priority = 2.4;
			  enableInside = 1;
			  exceptions[] = {"isNotInside"};
			};			

			class TU_ARTY_self_prep_shells {
				displayName = "Подготовить мины";
				condition = "({'bn_82mm_shell_0' in ([(configFile >> 'CfgMagazines' >> _x),true] call BIS_fnc_returnParents)} count (magazines  player)) > 0";
				statement = "uiNamespace setVariable ['TU_ARTY_prep_source', (backpackContainer player)]; createDialog 'TU_ARTY_PREP_D'";
				showDisabled = 0;
				priority = 1;
				hotkey = "P";
				enableInside = 1;
			};
			
			class TU_ARTY_deploy_aiming_circle {
				displayName = "Установить буссоль";
				condition = "(backpack player) == 'BN_Aiming_Circle_Bag'";
				statement = "[] call tu_arty_fnc_deploy_aiming_circle";
				showDisabled = 0;
				priority = 1;
				enableInside = 0;
			};
		};
	};
	
	/*extern*/ class LandVehicle;

	class StaticWeapon: LandVehicle {
		/*extern*/ class Turrets;
		/*extern*/ class MainTurret;
		/*extern*/ class ViewGunner;
		class ACE_Actions;
		class ACE_MainActions;
	};

	class StaticCannon: StaticWeapon {
		/*extern*/ class ViewOptics;
		/*extern*/ class ViewGunner;
		class ACE_Actions;
		class ACE_MainActions;
	};

	class StaticGrenadeLauncher: StaticWeapon {
		/*extern*/ class ViewOptics;
		/*extern*/ class ViewGunner;
		/*extern*/ class Turrets;// 
		/*extern*/ class MainTurret;// 
	};

	class StaticMortar: StaticWeapon {
		/*extern*/ class ViewOptics;
		/*extern*/ class Turrets;
		/*extern*/ class MainTurret;
	};
	class rhs_2b14_82mm_Base;
	class rhs_2b14_82mm_msv: rhs_2b14_82mm_Base
	{
		scope = 1;
	};
	class rhs_2b14_82mm_vdv: rhs_2b14_82mm_Base
	{
		scope = 1;
	};
	class rhs_2b14_82mm_ins: rhs_2b14_82mm_Base
	{
		scope = 1;
	};
	class BN_2b14_82mm_Base: StaticGrenadeLauncher {// StaticMortar {
		bn_arty_milSys = 6000;
		bn_arty_rounding_T = 1;
		bn_arty_show_traverse = 0;
		bn_arty_show_firemode = 2;
		
		ace_dragging_canDrag = 0;
		ace_dragging_canCarry = 0;
		
		availableForSupportTypes[] = {"Artillery"};
		displayname = "$STR_rhs_DN_2B14";
		vehicleClass = "rhs_vehclass_artillery";

		class Library {
			libTextDesc = "$STR_rhs_LIB_2B14";
		};
		model = "\tu_arty\ACE_2B14";
		transportSoldier = 1;
		cargoAction[] = {"rhs_D30_Cargo"};
		icon = "rhsafrf\addons\rhs_heavyweapons\data\mapico\icomap_podnos_2b14_CA.paa";
		picture = "\rhsafrf\addons\rhs_heavyweapons\data\ico\podnos_2b14_ca.paa";
		UiPicture = "\rhsafrf\addons\rhs_heavyweapons\data\ico\podnos_2b14_ca.paa";
		mapSize = 1.500000;

		class Turrets: Turrets {
//			/*extern*/ class ViewOptics;
//			/*extern*/ class ViewGunner;
			class MainTurret: MainTurret {
//				/*extern*/ class ViewOptics;
				animationSourceElevation = "MainGun";
				gunnerAction = "rhs_D30_Cargo";
				weapons[] = {"bn_mortar_82mm"};
				gunnerOpticsModel = "\tu_arty\SightUnit";
				turretinfotype = "RscWeaponRangeZeroing";
//				discreteDistance[] = {1};
//				discreteDistanceInitIndex = 0;
				// "RscWeaponRangefinder"; //возможно, здесь собака порылась 
				//RscWeaponRangeZeroing
				gunEnd = "gun_chamber";
				gunBeg = "gun_muzzle";
				selectionFireAnim = "gun_muzzle";
				magazines[] = {};
				initElev = 45;
				initTurn = 0;
				minElev = 45;
				maxElev = 45;
				minTurn = -4;
				maxTurn = 4;
				class ViewOptics:ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.12;
					minFov = 0.12;
					maxFov = 0.12;
				};
				class ViewGunner:ViewGunner {
				   initAngleX = 30;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.75;
					minFov = 0.75;
					maxFov = 0.75;
				};
			};
		};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		artilleryScanner = 1;
		
		class ACE_Actions {
			class BN_CSW_Load_New {
				displayName = "Зарядить...";
				distance = 3;
				condition = "count ([_target] call bn_csw_fnc_add_subactions) > 0";
				icon = "\bn_csw_load\data\ui\load.paa";
				statement = "";
				showDisabled = 0;
				priority = 5;
				hotkey = "L";
				enableInside = 0;
				insertChildren = "[_target] call bn_csw_fnc_add_subactions";
				selection = "gun_muzzle";
			};
			class BN_CSW_Unload {
				displayName = "Разрядить";
				distance = 2;
				condition = "true";
				icon = "\bn_csw_load\data\ui\unload.paa";
				statement = "0 = [_target, _player] execVM '\bn_csw_load\scripts\bn_csw_unload.sqf';";
				showDisabled = 1;
				priority = 1;
				hotkey = "U";
				enableInside = 0;
				selection = "gun_chamber";
			};
			class TU_ARTY_Move_Tripod {
				displayName = "Переставить двуногу";
				distance = 2;
				condition = "true"; //"isNil (_target getVariable ['bn_drag_handle',nil]);";
				statement = "[_target] call tu_arty_fnc_shift;";
				showDisabled = 0;
				priority = 1;
				hotkey = "M";
				enableInside = 0;
				selection = "aimpoint";
			};
			class TU_ARTY_Level_Gun {
				displayName = "Горизонтировать";
				distance = 2;
				condition = "isNull attachedTo _target"; //"isNil (_target getVariable ['bn_drag_handle',nil]);";
				statement = "[5, [_target], {[_this select 0] call tu_arty_fnc_level_gun;}, {}, 'Горизонтирование орудия'] call ace_common_fnc_progressBar;"; 
				showDisabled = 0;
				priority = 1;
				enableInside = 0;
				selection = "osahlavne";
			};
		};
		class assembleInfo
		{
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {"rhs_Podnos_Gun_Bag","rhs_Podnos_Bipod_Bag"};
			displayName = "";
		};
		class UserActions
		{
		  class tu_arty_show_mpm44m
			  {
				displayName = "<t color='#CCCCCC'>Прицел МПМ-44М</t>";
				displayNameDefault = "";
				priority = 3;
				radius = 20;
				position = "camera";
				showWindow = 0;
				onlyForPlayer = 1;
				condition = "(player == gunner this) && {(isNull (uiNamespace getVariable ['TU_ARTY_Display', displayNull]))};";
				statement = "createDialog 'tu_arty_d';";
			  };
		 };
		class AnimationSources {

			class MainTurret {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};

			class MainTurret_RotateFast: MainTurret {
				animPeriod = 0.001000;
			};

			class MainGun {
				source = "user";
				weapon = "bn_mortar_82mm";
				animPeriod = 0.010000;
				initPhase = 1030;
				minValue = 750;
				maxValue = 1467;
			};

			class OpticElevate {
				source = "user";
				animPeriod = 0.001000;
				initPhase = 1030;
				minValue = 750;
				maxValue = 1467;
			};

			class OpticRevolve {
				source = "user";
				animPeriod = 0.002000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};

			class MainTurretTraverse {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -200;
				maxValue = 200;
			};
		};
	};	
	class BN_2b14_82mm_MSV: BN_2b14_82mm_Base
	{
		scope = 2;
		side = 0;
		author = "Red Hammer Studios";
		faction = "rhs_faction_msv";
		crew = "rhs_msv_rifleman";
		typicalCargo[] = {"rhs_msv_rifleman"};
	};
	
	class TU_ARTY_M224_mortar: BN_2b14_82mm_Base {
		model = "\tu_arty\ACE_m224";
		bn_arty_milSys = 6400;
		displayName = "60-мм миномет M224";
		
		ace_dragging_canDrag = 1;
		
		class Turrets: Turrets {

			class MainTurret: MainTurret {
				/*extern*/ class ViewOptics;
				
				gunnerAction = "rhs_D30_Cargo";
				weapons[] = {"bn_mortar_60mm"};
				magazines[] = {};
				gunEnd = "gun_chamber";
				gunBeg = "gun_muzzle";
				selectionFireAnim = "gun_muzzle";
				initElev = 45;
				initTurn = 0;
				minElev = 45;
				maxElev = 45;
				minTurn = -4;
				maxTurn = 4;
			};
		};
		
		class assembleInfo: assembleInfo {
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {"BN_M224_Gun_Bag", "BN_M224_Bipod_Bag"};
		};
		
		class ACE_Actions;
		
		class AnimationSources {

			class MainTurret {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};

			class MainTurret_RotateFast: MainTurret {
				animPeriod = 0.001000;
			};

			class MainGun {
				source = "user";
				weapon = "bn_mortar_60mm";
				animPeriod = 0.010000;
				initPhase = 1030;
				minValue = 750;
				maxValue = 1467;
			};

			class OpticElevate {
				source = "user";
				animPeriod = 0.001000;
				initPhase = 1030;
				minValue = 750;
				maxValue = 1467;
			};

			class OpticRevolve {
				source = "user";
				animPeriod = 0.002000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};

			class MainTurretTraverse {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -200;
				maxValue = 200;
			};
		};
	};
	
	class TU_ARTY_M224_mortar_WD: TU_ARTY_M224_mortar
	{
		scope = 2;
		side = 1;
		author = "RHS (A2 port)";
		faction = "rhs_faction_usarmy_wd";
		crew = "rhsusf_army_ucp_rifleman";
		typicalCargo[] = {"rhsusf_army_ucp_rifleman"};
	};
	class TU_ARTY_120mm_mortar: BN_2b14_82mm_Base {
		model = "\tu_arty\ACE_120_TAMPELLA";
		bn_arty_milSys = 6000;
		displayName = "120-мм миномет";
		
		class Turrets: Turrets {

			class MainTurret: MainTurret {
				animationSourceElevation = "MainGun";
				/*extern*/ class ViewOptics;
				gunnerAction = "rhs_D30_Cargo";
				weapons[] = {"bn_mortar_120mm"};
				magazines[] = {};
				gunEnd = "gun_chamber";
				gunBeg = "gun_muzzle";
				selectionFireAnim = "gun_muzzle";
				initElev = 45;
				initTurn = 0;
				minElev = 45;
				maxElev = 45;
				minTurn = -4;
				maxTurn = 4;
			};
		};
		
		class assembleInfo: assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {""};
			displayName="120-мм миномет";
		};
		
		class ACE_Actions;
		
		class AnimationSources {

			class MainTurret {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};

			class MainTurret_RotateFast: MainTurret {
				animPeriod = 0.001000;
			};

			class MainGun {
				source = "user";
				weapon = "bn_mortar_120mm";
				animPeriod = 0.010000;
				initPhase = 1030;
				minValue = 750;
				maxValue = 1467;
			};

			class OpticElevate {
				source = "user";
				animPeriod = 0.001000;
				initPhase = 1030;
				minValue = 750;
				maxValue = 1467;
			};
			
			class OpticLens {
				source = "user";
				animPeriod = 0.001000;
				initPhase = 0;
				minValue = -100;
				maxValue = 100;
			};

			class OpticRevolve {
				source = "user";
				animPeriod = 0.002000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};

			class MainTurretTraverse {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -200;
				maxValue = 200;
			};
		};
	};
	
	class TU_ARTY_120mm_mortar_WD: TU_ARTY_120mm_mortar
	{
		scope = 2;
		side = 1;
		author = "RHS (A2 port)";
		faction = "rhs_faction_usarmy_wd";
		crew = "rhsusf_army_ucp_rifleman";
		typicalCargo[] = {"rhsusf_army_ucp_rifleman"};
	};
	
	class StaticATWeapon: StaticWeapon {
        class Turrets: Turrets {
            class MainTurret: MainTurret
			{
				class ViewOptics;
			};
        };
    };
	class ACE_SpottingScopeObject: StaticATWeapon {
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
    };
	
	class Box_NATO_Support_F;
	class rhs_weapon_crate;
	class ACE_Box_Misc: Box_NATO_Support_F {
		class ACE_Actions;
		class ACE_MainActions;
	};
	class bn_mortar_box_large: rhs_weapon_crate {
		class ACE_Actions;
		class ACE_MainActions;
	};
	
	class BN_82mm_shells_box: ACE_Box_Misc {
		scope = 1; // deprecated
		// решение принято в пользу осколочных 82-мм мин
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		displayName = "Ящик 82 мм ОФ мин";
		maximumload = 400;
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_82mm_shell_0";
				count = 8;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
		class ACE_Actions: ACE_Actions { //: ACE_Actions
			class ACE_MainActions: ACE_MainActions
			{
				selection = "";
				distance = 5;
				condition = 1;
				class bn_prep_shells {
					displayName = "Подготовить мины";
					distance = 2;
					condition = "({count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0} count (magazineCargo _target)) > 0";
					statement = "uiNamespace setVariable ['TU_ARTY_prep_source', _target]; createDialog 'TU_ARTY_PREP_D'";
					showDisabled = 0;
					priority = 1.1;
					hotkey = "P";
					enableInside = 0;
				};
			};
		};
	};
	
	class bn_ace2_aiming_circle: ACE_SpottingScopeObject 
	{
		scope = 2;
		model = "\tu_arty\ace_arty_m2a2_aiming_circle";
		icon = "\rhsafrf\addons\rhs_heavyweapons\mg\bis_kord\icomap_kord_CA.paa";
		picture = "\rhsafrf\addons\rhs_heavyweapons\mg\bis_kord\kord_CA.paa";
		UiPicture = "\rhsafrf\addons\rhs_heavyweapons\mg\bis_kord\kord_CA.paa";
		mapSize = 3;
		displayName = "Буссоль";

		/*
		class assembleInfo
		{
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {"bn_aiming_circle_bag"};
			displayName = "";
		};*/
		
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		class TransportBackpacks {};
		
		class ACE_Actions {
			class TU_ARTY_Pickup_Aiming_Point {
				displayName = "Сложить";
				distance = 2;
				condition = "true"; //"isNil (_target getVariable ['bn_drag_handle',nil]);";
				statement = "[_target] call tu_arty_fnc_collapse_aiming_circle;"; 
				showDisabled = 0;
				priority = 1;
				enableInside = 0;
				selection = "centerpoint";
			};
		};
		
		class UserActions
		{
		  class bn_use_te
			{
				displayName = "<t color='#CCCC88'>Буссоль</t>";
				displayNameDefault = "";
				priority = 3;
				radius = 5;
				position = "camera";
				showWindow = 0;
				onlyForPlayer = 1;
				condition = "(isNull (uiNamespace getVariable ['bn_te_Display', displayNull]));";
				statement = "[this] spawn tu_arty_fnc_use_aiming_circle;";
			};
		};
		
		init = "(_this select 0) enableSimulation false; this setVariable ['tu_arty_deflection_reset',0];";
			
		bn_arty_milSys = 6000;
		bn_arty_rounding_T = 1;
		bn_arty_show_traverse = 0;
		bn_arty_show_firemode = 0;
		bn_arty_show_deflection = 1;
		bn_arty_show_azimuth = 1;
		bn_arty_elevation_style = -1;
		
		class AnimationSources
		{
			class MainGun
			{
				source = "user";
				animPeriod = 0.02;
				initPhase = 0;
				minValue = "-400";
				maxValue = "800";
			};
			class MainTurret
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-6400";
				maxValue = "6400";
			};
			class upper_motion
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.002;
				minValue = "-6400";
				maxValue = "6400";
			};
			class deflection_knob
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-100";
				maxValue = "100";
			};
			class deflection_knob_coarse
			{
				type = "rotation";
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-64";
				maxValue = "64";
			};
			class elevation_knob
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-100";
				maxValue = "100";
			};
			class elevation_knob_coarse
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-4";
				maxValue = "8";
			};
			class orienting_knobs
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-6400";
				maxValue = "6400";
			};
			class left_cover
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				minValue = "0";
				maxValue = "1";
			};
			class right_cover
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				minValue = "0";
				maxValue = "1";
			};
			class compass_needle
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-360";
				maxValue = "360";
			};
		};
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {};
				magazines[] = {};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				gunnerOpticsModel = "\rhsafrf\addons\rhs_weapons2\misc\tr8\rhs_tr8_reticle.p3d";
				gunnerAction = "KORD_Gunner";
				gunBeg = "gunBegin";
				gunEnd = "gunEnd";
				proxyIndex = 1;
				maxHorizontalRotSpeed = 4;
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
	};
	
	class BN_60mm_shells_box: BN_82mm_shells_box {
		scope = 2;
		displayName = "Ящик 60-мм осколочных мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_60mm_shell_0";
				count = 12;
			};
		};
	};
	
	class BN_60mm_smoke_box: BN_82mm_shells_box {
		scope = 2;
		displayName = "Ящик 60-мм дымовых мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_60mm_smoke_0";
				count = 8;
			};
		};
		
		class BN_60mm_illum_box: BN_82mm_shells_box {
		scope = 2;
		displayName = "Ящик 60-мм осветительных мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_60mm_illum_0";
				count = 8;
			};
		};
	};
	};
	
	class BN_82mm_shells_box_large: BN_82mm_shells_box {
		scope = 2;
		displayName = "Ящик 82 мм осколочных мин (большой)";
		model = "rhsafrf\addons\rhs_weapons\crates\rhs_3Ya40_1";
		maximumload = 1281;
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_82mm_frag_0";
				count = 32;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
/*		class ACE_Actions : ACE_Actions { //
			class ACE_MainActions
			{
				selection = "";
				distance = 5;
				condition = 1;
				class bn_prep_shells {
					displayName = "Подготовить мины";
					distance = 2;
					condition = "({count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0} count (magazineCargo _target)) > 0";
					statement = "uiNamespace setVariable ['TU_ARTY_prep_source', _target]; createDialog 'TU_ARTY_PREP_D'";
					showDisabled = 0;
					priority = 1.1;
					hotkey = "P";
					enableInside = 0;
				};
			};
		};*/
	};
	
	class BN_122mm_shells_box_large: BN_82mm_shells_box_large {
		displayName = "Ящик 122-мм снарядов ОФ-462";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		hiddenSelectionsTextures[] = {"\tu_arty\data\ammo\d30_shell_ca.paa","A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
		maximumload = 1281;
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_122mm_OF_462_5";
				count = 8;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
		class ACE_Actions;
		class ACE_MainActions;
			
/*		class ACE_Actions : ACE_Actions { //
			class ACE_MainActions
			{
				selection = "";
				distance = 5;
				condition = 1;
				class bn_prep_shells {
					displayName = "Подготовить заряды";
					distance = 2;
					condition = "({count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0} count (magazineCargo _target)) > 0";
					statement = "uiNamespace setVariable ['TU_ARTY_prep_source', _target]; createDialog 'TU_ARTY_PREP_D'";
					showDisabled = 0;
					priority = 1.1;
					hotkey = "P";
					enableInside = 0;
				};
			};
		};*/
	};
	
	class BN_122mm_smoke_box_large: BN_122mm_shells_box_large {
		displayName = "Ящик 122-мм дымовых снарядов Д-4";
		hiddenSelectionsTextures[] = {"\tu_arty\data\ammo\d30_smoke_ca.paa","A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_122mm_D4_5";
				count = 8;
			};
		};
	};
	
	class BN_122mm_illum_box_large: BN_122mm_shells_box_large {
		displayName = "Ящик 122-мм осветительных снарядов С-463Ж";
		hiddenSelectionsTextures[] = {"\tu_arty\data\ammo\d30_illum_ca.paa","A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_122mm_S_463Zh_4";
				count = 8;
			};
		};
	};
	
	class BN_122mm_AT_box_large: BN_122mm_shells_box_large {
		displayName = "Ящик 122-мм кумулятивных снарядов БП1";
		hiddenSelectionsTextures[] = {"\tu_arty\data\ammo\d30_ap_ca.paa","A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_122mm_BP1_0";
				count = 8;
			};
		};
		class ACE_Actions : ACE_Actions { //
			class ACE_MainActions: ACE_MainActions
			{
				class bn_prep_shells {
				};
			};
		};
	};
		
	class BN_120mm_shells_box_large: BN_82mm_shells_box_large {
		displayName = "Ящик 120 мм ОФ мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_120mm_mag
			{
				magazine = "bn_120mm_shell_0";
				count = 16;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
/*		class ACE_Actions: ACE_Actions { //
			class ACE_MainActions
			{
				selection = "";
				distance = 5;
				condition = 1;
				class bn_prep_shells {
					displayName = "Подготовить мины";
					distance = 2;
					condition = "({count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0} count (magazineCargo _target)) > 0";
					statement = "uiNamespace setVariable ['TU_ARTY_prep_source', _target]; createDialog 'TU_ARTY_PREP_D'";
					showDisabled = 0;
					priority = 1.1;
					hotkey = "P";
					enableInside = 0;
				};
			};
		};*/
	};
	
	class BN_120mm_smoke_box_large: BN_82mm_shells_box_large {
		scope = 2;
		displayName = "Ящик 120 мм дымовых мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_120mm_mag
			{
				magazine = "bn_120mm_smoke_0";
				count = 16;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
/*		class ACE_Actions: ACE_Actions { //
			class ACE_MainActions
			{
				selection = "";
				distance = 5;
				condition = 1;
				class bn_prep_shells {
					displayName = "Подготовить мины";
					distance = 2;
					condition = "({count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0} count (magazineCargo _target)) > 0";
					statement = "uiNamespace setVariable ['TU_ARTY_prep_source', _target]; createDialog 'TU_ARTY_PREP_D'";
					showDisabled = 0;
					priority = 1.1;
					hotkey = "P";
					enableInside = 0;
				};
			};
		};*/
	};
	
	class BN_82mm_smoke_box: BN_82mm_shells_box {
		scope = 2;
		displayName = "Ящик 82 мм дымовых мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_82mm_smoke_0";
				count = 8;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
	};
	
	class BN_82mm_illum_box: BN_82mm_shells_box {
		scope = 2;
		displayName = "Ящик 82-мм осветительных мин";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_82mm_illum_0";
				count = 8;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
	};
	
	class BN_82mm_smoke_box_large: BN_82mm_shells_box_large {
		displayName = "Ящик 82 мм дымовых мин (большой)";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_82mm_mag
			{
				magazine = "bn_82mm_smoke_0";
				count = 32;
			};
		};
/*		class ACE_Actions: ACE_Actions {
			class ACE_MainActions {
				class bn_prep_shells {
					displayName = "Подготовить мины";
					distance = 2;
					condition = "({count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0} count (magazineCargo _target)) > 0";
					statement = "uiNamespace setVariable ['TU_ARTY_prep_source', _target]; createDialog 'TU_ARTY_PREP_D'";
					showDisabled = 0;
					priority = 1.1;
					hotkey = "P";
					enableInside = 0;
				};
			};
		};*/
		class TransportItems {};
		class TransportBackpacks {};
	};
	
	class BN_2b14_box: ACE_Box_Misc {
		displayName = "Ящик с минометом 2Б14";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		class TransportWeapons {};
		class TransportItems {
			class _xx_tab_mag
				{
					name = "tu_arty_tables_2b14";
					count = 2;
				};
			class _xx_maptools
				{
					name = "ACE_MapTools";
					count = 1;
				};
			};
		class TransportBackpacks {
			class _xx_gunbag
				{
					backpack = "RHS_Podnos_Gun_Bag";
					count = 1;
				};
			class _xx_tripodbag
				{
					backpack = "RHS_Podnos_Bipod_Bag";
					count = 1;
				};
			class _xx_sidor
				{
					backpack = "rhs_sidor";
					count = 1;
				};	
				class _xx_stake
				{
					backpack = "tu_arty_aiming_stake_bag";
					count = 2;
				};
		};
		class TransportMagazines {};
	};
	
	class BN_m224_box: ACE_Box_Misc {
		displayName = "Ящик с минометом M224";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		class TransportWeapons {};
		class TransportItems {
			class _xx_tab_mag
				{
					name = "tu_arty_tables_m224";
					count = 2;
				};
			class _xx_maptools
				{
					name = "ACE_MapTools";
					count = 1;
				};
			};
		class TransportBackpacks {
			class _xx_gunbag
				{
					backpack = "BN_M224_Gun_Bag";
					count = 1;
				};
			class _xx_tripodbag
				{
					backpack = "BN_M224_Bipod_Bag";
					count = 1;
				};
			class _xx_sidor
				{
					backpack = "rhsusf_assault_eagleaiii_coy";
					count = 1;
				};	
			class _xx_stake
				{
					backpack = "tu_arty_aiming_stake_bag";
					count = 2;
				};	
		};
		class TransportMagazines {};
	};
	
	class BN_artillery_box: ACE_Box_Misc {
		displayName = "Контейнер с буссолью";
//		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		maximumload = 180;
		class TransportWeapons {};
		class TransportItems {
			class _xx_maptools
				{
					name = "ACE_MapTools";
					count = 1;
				};
			class _xx_log	{
					name  = "tu_decoration_log";
					count = 1;
				};
			};
		class TransportBackpacks {
			class _xx_gunbag
				{
					backpack = "BN_Aiming_Circle_Bag";
					count = 1;
				};
			class _xx_stake
				{
					backpack = "tu_arty_aiming_stake_bag";
					count = 2;
				};
		};
		class TransportMagazines {};
	};
	
//	class assembleInfo;
	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo;
	};
	class RHS_NSV_Gun_Bag: Weapon_Bag_Base
	{
		class assembleInfo;
	};
	class RHS_NSV_Tripod_Bag: Weapon_Bag_Base
	{
		class assembleInfo;
	};
	
	class BN_M224_Gun_Bag: RHS_NSV_Gun_Bag
	{
		displayName = "Вьюк со стволом М224";
		_generalMacro = "TU_ARTY_M224_mortar_WD";
		mass = 120;
		class assembleInfo: assembleInfo
		{
			assembleTo = "TU_ARTY_M224_mortar_WD";
			dissasembleTo[] = {};
			base[] = {"BN_M224_Bipod_Bag"};
			primary = 1;
			displayName = "миномет М224";
		};
	};
	class BN_M224_Bipod_Bag: RHS_NSV_Tripod_Bag
	{
		mass = 160;
		displayName = "Вьюк с плитой М224";
		_generalMacro = "TU_ARTY_M224_mortar_WD";
		class assembleInfo: assembleInfo
		{
			primary = 0;
			displayName = "миномет М224";
			assembleTo = "";
			dissasembleTo[] = {};
			base[] = {};
		};
	};
	
	class BN_Aiming_Circle_Bag: RHS_NSV_Tripod_Bag
	{
		mass = 160;
//		model = "\tu_arty\ace_arty_m2a2_aiming_circle_wep";
// 		модель не работает пока
		displayName = "Буссоль (сложена)";
		// сборка-разборка реализована через скрипты
		/*
		_generalMacro = "bn_ace2_aiming_circle";
		class assembleInfo: assembleInfo
		{
			primary = 1;
			displayName = "буссоль";
			assembleTo = "bn_ace2_aiming_circle";
			dissasembleTo[] = {};
			base[] = {};
		};*/
	};
	
	class Land_RedWhitePole_F;
	class TU_Arty_Aiming_Stake: Land_RedWhitePole_F {
		displayName = "Прицельная вешка";
		simulation = "house";
		class assembleInfo
		{
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {"tu_arty_aiming_stake_bag"};
			displayName = "прицельную вешку";
		};
		
		init = "(_this select 0) enableSimulation false;";
	};
	
	class tu_arty_aiming_stake_bag: RHS_NSV_Tripod_Bag {
		displayName = "Прицельная вешка";
		mass = 15;
		picture = "\tu_arty\data\equip\stake.paa";
		class assembleInfo: assembleInfo
		{
			primary = 1;
			displayName = "прицельную вешку";
			assembleTo = "TU_Arty_Aiming_Stake";
			dissasembleTo[] = {};
			base = "";
		};
	};
	
	class rhs_D30_base: StaticCannon
	{
		dlc = "RHS_AFRF";
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3"};
		accuracy = 0.12;
		cost = 10000;
		availableForSupportTypes[] = {"Artillery"};
		artilleryScanner = 1;
		displayName = "$STR_rhs_DN_D30";
		vehicleClass = "rhs_vehclass_artillery";
		model = "\rhsafrf\addons\rhs_heavyweapons\D30\D30";
		icon = "rhsafrf\addons\rhs_heavyweapons\data\mapico\icomap_d30_CA.paa";
		picture = "\rhsafrf\addons\rhs_heavyweapons\data\ico\d30_CA.paa";
		UiPicture = "\rhsafrf\addons\rhs_heavyweapons\data\ico\d30_CA.paa";
		mapSize = 4.5;
		cargoAction[] = {"rhs_D30_Cargo","rhs_D30_Commander"};
		typicalCargo[] = {};
		transportSoldier = 2;
		gunnerHasFlares = 1;
		driveOnComponent[] = {"leftw","slide"};
		memoryPointsGetInCargo = "pos_cargo_dir";
		memoryPointsGetInCargoDir = "pos_cargo";
		ace_cargo_canLoad = 0;
		armor = 40;
		
		bn_arty_milSys = 6000;
		bn_arty_rounding_T = 1;
		bn_arty_show_firemode = 0;
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunBeg = "Usti hlavne";
				gunEnd = "Konec hlavne";
				weapons[] = {"bn_rhs_weap_D30"};
				magazines[] = {};
				gunnerAction = "rhs_D30_Gunner";
				gunnerOpticsModel = "\rhsafrf\addons\rhs_heavyweapons\data\2Dscope_D30";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				elevationMode = 1;
				turretInfoType = "rhs_gui_optic_mortar";
				minElev = -9;
				maxelev = 80;
				minTurn = -180;
				maxTurn = 180;
				class ViewOptics: ViewOptics
				{
					initFov = 0.096;
					minFov = 0.096;
					maxFov = 0.096;
				};
			};
		};
		class HitPoints {
		class HitBody
		   {
			armor = 0.8;
			material = -1;
			name = "telo";
			visual = "zbytek";
			passThrough = 1;
			minimalHit = 0.44;
			explosionShielding = 1;
			radius = 0.25;
		   };
		};
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "bn_rhs_weap_D30";
			};
			class muzzle_hide_arty: recoil_source{};
			class leftT_source
			{
				source = "user";
				animPeriod = 1;
				initPhase = -2.3;
			};
			class rightT_source: leftT_source
			{
				initPhase = 0;
			};
			class leftW_source: leftT_source
			{
				initPhase = -1.7;
			};
			class rightW_source: leftW_source{};
			class maingunT_source
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class mainTurretT_source: maingunT_source{};
			class szpilki_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class body_source
			{
				source = "user";
				animPeriod = 0.6;
				initPhase = 0;
			};
			class d30_kolo
			{
				source = "user";
				animPeriod = 0.6;
				initPhase = 0;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"rhsafrf\addons\rhs_heavyweapons\D30\data\d30.rvmat","rhsafrf\addons\rhs_heavyweapons\D30\data\d30_damage.rvmat","rhsafrf\addons\rhs_heavyweapons\data\static_destroyed.rvmat"};
		};
		class Library
		{
			libTextDesc = "$STR_rhs_LIB_D30";
		};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 450;
		class EventHandlers: DefaultEventhandlers
		{
			class RHS_EventHandlers
			{
				fired = "_this spawn rhs_fnc_fired_d30";
			};
		};
		class UserActions
		{
			class raise_pole
			{
				displayName = "Поднять/опустить вешку";
				position = "aimpoint";
				radius = 2.51;
				onlyForplayer = 0;
				condition = "(alive this)";
				statement = "[this] call tu_arty_fnc_raise_pole;";
			};
			
			delete Fold;
			delete Unfold;
		};
				
		class TransportItems {
			class _xx_tab_mag
			{
				name = "tu_arty_tables_d30";
				count = 1;
			};
		};

		class ACE_Actions: ACE_Actions {
			class ACE_MainActions: ACE_MainActions {
				class bn_fold_gun {
					displayName = "В походное положение";
					distance = 3;
					condition = "([] call tu_arty_fnc_towing_enabled) && !(_target getVariable ['tu_arty_folded',false])";
					statement = "[_target] call tu_arty_fnc_fold_gun";
					showDisabled = 0;
					priority = 1.1;
					enableInside = 0;
				};
				class bn_unfold_gun {
					displayName = "В боевое положение";
					distance = 3;
					condition = "(_target getVariable ['tu_arty_folded',false])";
					statement = "[_target] call tu_arty_fnc_unfold_gun";
					showDisabled = 0;
					priority = 1.1;
					enableInside = 0;
				};
			};
			class bn_tow_gun {
					displayName = "Прицепить";
					distance = 3;
					condition = "([] call tu_arty_fnc_towing_enabled) && (_target getVariable ['tu_arty_folded',false]) && (isNull (attachedTo _target))";
					statement = "[_target] call tu_arty_fnc_tow_stuff";
					showDisabled = 0;
					priority = 1.1;
					enableInside = 0;
					position = "[0,3.2,-0.9]";
				};
			class bn_untow_gun {
				displayName = "Отцепить";
				distance = 3;
				condition = "(_target getVariable ['tu_arty_folded',false]) && !(isNull (attachedTo _target))";
				statement = "[_target] call tu_arty_fnc_untow_stuff";
				showDisabled = 0;
				priority = 1.1;
				enableInside = 0;
				position = "[0,3.2,-0.9]";
			};
			class bn_level_howitzer {
				displayName = "Горизонтировать";
				distance = 4;
				condition = "!(_target getVariable ['tu_arty_folded',false]) && (isNull (attachedTo _target))";
				statement = "[_target] call tu_arty_fnc_level_howitzer";
				showDisabled = 0;
				priority = 1.1;
				enableInside = 0;
				position = "[0,0,-1]";
			};
		};
	};
	
	class rhs_D30_ins: rhs_D30_base
	{
		scope=2;
		side = 2;
		faction = "rhs_faction_insurgents";
		crew="rhs_g_Soldier_F";
		typicalCargo[]= {"rhs_g_Soldier_F"};

		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[] = {};
			};
		};
	};
	
	class Truck_F;
	class RHS_Ural_BaseTurret: Truck_F {
		/*extern*/ class Turrets;
		/*extern*/ class MainTurret;
		/*extern*/ class ViewOptics;
	};
	class RHS_BM21_MSV_01: RHS_Ural_BaseTurret {
		/*extern*/ class Turrets;
		/*extern*/ class MainTurret;
		/*extern*/ class ViewOptics;
		/*extern*/ class GunnerOptics;
		class ACE_Actions;
		class ACE_MainActions;
	};
	
	class rhs_gaz66_vmf {
		tu_arty_gun_attachment_point[] = {0,-2.75,0.1};
		tu_arty_gun_rotation[] = {0,-0.2,1};
	};
	
	class RHS_Ural_Base  {
		tu_arty_gun_attachment_point[] = {0,-3.5,-0.05};
		tu_arty_gun_rotation[] = {0,-0.2,1};
	};
	
	class CUP_HMMWV_Base {
		tu_arty_gun_attachment_point[] = {0,-2.6,-0.8};
		tu_arty_gun_rotation[] = {0,-0.1,1};
	};
	
	class TU_ARTY_RHS_BM21: RHS_BM21_MSV_01 {
		displayName = "BM-21 (усложн.)";
		class UserActions
			{
			  class bn_use_te
				{
					displayName = "<t color='#CCCC88'>Угломер/прицел</t>";
					displayNameDefault = "";
					priority = 3;
					radius = 20;
					position = "camera";
					showWindow = 0;
					onlyForPlayer = 1;
					condition = "(player == gunner this) && (isNull (uiNamespace getVariable ['bn_te_Display', displayNull]));";
					statement = "bn_te_handle = [_this] execVM '\bn_te\scripts\t-e.sqf';";
				};
			};
				
		bn_arty_milSys = 6000;
		bn_arty_rounding_T = 1;
		bn_arty_show_traverse = 0;
		bn_arty_show_firemode = 1;
		bn_arty_show_deflection = 1;
		tu_arty_use_offset = 1;
		tu_arty_sight_offset[] = {-1.35,-0.95,0.15};
		tu_arty_sight_offset_selection = "OsaVeze";
		gunnerCanSee = 2+4+8;
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				commanding = 1;
				body = "mainTurret";
				gun = "mainGun";
				minElev = 0;
				maxElev = 65;
				initElev = 11.5;
				weapons[] = {"bn_rhs_weap_grad"};
				magazines[] = {"RHS_mag_40Rnd_122mm_rockets"};
				gunnerAction = "passenger_apc_narrow_generic03still";
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_empty";
				gunnergetInAction = "GetInHigh";
				gunnergetOutAction = "GetOutHigh";
				stabilizedInAxes = "StabilizedInAxesNone";
				outGunnerMayFire = 1;
				usePiP = 1;
				inGunnerMayFire = 1;
				gunnerForceOptics = 0;
				gunnerOutForceOptics = 0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.093;
					minFov = 0.093;
					maxFov = 0.093;
				};
				lockWhenVehicleSpeed = 1;
				elevationMode = 3;
			};
		};
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {
			class _xx_tables_mag
			{
				name = "tu_arty_tables_grad";
				count = 1;
			};
			class _xx_ace_maptools
			{
				name = "ACE_MapTools";
				count = 1;
			};
		};
		class ACE_Actions: ACE_Actions {
			class ACE_MainActions: ACE_MainActions {
				class bn_level_howitzer {
					displayName = "Горизонтировать";
					distance = 3;
					condition = "(isNull (attachedTo _target))";
					statement = "[_target] call tu_arty_fnc_level_howitzer";
					showDisabled = 0;
					priority = 1.1;
					enableInside = 0;
				};
			};
		};
	};

	class CUP_B_HMMWV_Terminal_USA;
	class TU_ARTY_HMMWV_Artillery_Radar: CUP_B_HMMWV_Terminal_USA {
		displayName = "HMMWV AN/TPQ-36";
		tu_arty_radar_detection_range = 18000;
		tu_arty_radar_detection_angle = 90;
		tu_arty_radar_error = 200;
		tu_arty_radar_type = "ARTILLERY";
		tu_radar_tracking_time_required = 5;
		tu_radar_show_once = 1;
		tu_arty_radar_pos = "getPos _this";
		tu_arty_radar_alpha = "_this getVariable ['tu_arty_fnc_firefinder_angle',0]";
		tu_arty_detectable = "_this isKindOf 'ShellBase'";
		class UserActions
		{
		  class tu_arty_adjust_angle
			{
				displayName = "<t color='#CCCC88'>Ориентировать антенну</t>";
				displayNameDefault = "";
				priority = 3;
				radius = 20;
				position = "camera";
				showWindow = 0;
				onlyForPlayer = 1;
				condition = "(player in this);";
				statement = "tu_arty_firefinder_handle = createDialog 'TU_ARTY_FIREFINDER_D';  sliderSetRange [5900, 0, 359]; sliderSetPosition [5900, ((vehicle player) getVariable ['tu_arty_fnc_firefinder_angle',0])]; ctrlSetText [5003, 'Азимут: ' + str(floor(sliderPosition 5900))];";
			};
		};
	};
	
	class rhs_gaz66_r142_msv;
	class TU_gaz66_radar: rhs_gaz66_r142_msv {
		displayName = "Индикаторная машина РЛС П-37";
		tu_arty_radar_type = "LONG RANGE AIR";
		tu_arty_radar_detection_range = 35000; // меньше реальной, но мы и так далеко не летаем
		tu_arty_radar_detection_angle = 6; //существенно больше реального, потому что у РХСного радара слишком большая частота вращения
		tu_radar_tracking_time_required = 0;
		tu_arty_radar_error = 10;
		tu_radar_show_once = 0;
		tu_arty_radar_pos = "_near_radars = nearestObjects [_this, ['rhs_p37'], 100]; if (count _near_radars > 0 && {alive (_near_radars select 0)}) exitWith {(getPos (_near_radars select 0)) vectorAdd [0,0,4]}; [0,0,0]";
		tu_arty_radar_alpha = "_near_radars = nearestObjects [_this, ['rhs_p37'], 100]; if (count _near_radars > 0) exitWith {(_near_radars select 0) getDir ((_near_radars select 0) modelToWorld ((_near_radars select 0) selectionPosition 'track_radar'))}; 0";
		tu_arty_detectable = "_this isKindOf 'Air'";
	};
	
	class Tank;
	class Tank_F: Tank {
		class ACE_Actions;
		class ACE_MainActions;
	};
	
	class rhs_2s3tank_base: Tank_F {
		class ACE_Actions: ACE_Actions {
			class ACE_MainActions: ACE_MainActions {
				class bn_level_howitzer {
					displayName = "Горизонтировать";
					distance = 3;
					condition = "(isNull (attachedTo _target))";
					statement = "[_target] call tu_arty_fnc_level_howitzer";
					showDisabled = 0;
					priority = 1.1;
					enableInside = 0;
				};
			};
		};
	};
	
	class UAV_01_base_F;
	class O_UAV_01_F: UAV_01_base_F {
		class ViewPilot;
		class Viewoptics;
		class Turrets;
		class MainTurret;
		class ACE_Actions;
		class ACE_MainActions;
	};
	
	class TU_Cheap_UAV_Red: O_UAV_01_F  {
		scope = 2;
		displayName = "Лёгкий БПЛА";
		altFullForce = 200;
		altNoForce = 400;
		side = 0;
		faction = "OPF_F";
		crew = "O_UAV_AI";
		typicalCargo[] = {"O_UAV_AI"};
		fuelCapacity = 15;
		class Turrets: Turrets { 
			class MainTurret: MainTurret {
				weapons[] = {};
				magazines[] = {};
				class ViewOptics: Viewoptics
				{
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					minFov = 0.6;
					maxFov = 1;
					initFov = 0.75;
					visionMode[] = {"Normal"};
				};
				class ViewGunner: Viewoptics {
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					minFov = 0.6;
					maxFov = 1;
					initFov = 0.75;
					visionMode[] = {"Normal"};
				};
				class OpticsIn {
					class Wide {
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.6;
						minFov = 0.6;
						maxFov = 0.6;
						directionStabilized = 1;
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					};

					class Medium : Wide {
						opticsDisplayName = "M";
						initFov = 0.5;
						minFov = 0.5;
						maxFov = 0.5;
						gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
					};

					class Narrow : Wide {
						opticsDisplayName = "N";
						initFov = 0.25;
						minFov = 0.25;
						maxFov = 0.25;
						gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					};
					
				};
			};
		};
		
		class ViewOptics
		{
			initAngleX = 0;
			minAngleX = 0;
			maxAngleX = 0;
			initAngleY = -90;
			minAngleY = -90;
			maxAngleY = -90;
			minFov = 0.6;
			maxFov = 1;
			initFov = 0.75;
			visionMode[] = {"Normal"};
		};
		
		class ViewGunner: Viewoptics {
			initAngleX = 0;
			minAngleX = 0;
			maxAngleX = 0;
			initAngleY = 0;
			minAngleY = 0;
			maxAngleY = 0;
			minFov = 0.6;
			maxFov = 1;
			initFov = 0.75;
			visionMode[] = {"Normal"};
		};
		
		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			displayName = "";
			dissasembleTo[] = {"TU_cheap_UAV_backpack_Red"};
		};
		
		class ACE_Actions: ACE_Actions {
			class ACE_MainActions: ACE_MainActions {
				class bn_attach_grenade {
					displayName = "Прицепить гранату";
					distance = 3;
					condition = "(({!(isNull _x)} count (attachedObjects _target)) == 0) && (count ([player] call tu_arty_fnc_grenade_subactions) > 0) && (_target == (getConnectedUAV player))";
					statement = "";
					showDisabled = 0;
					priority = 1.1;
					enableInside = 0;
					icon = "\bn_csw_load\data\ui\load.paa";
					position = [0,0,-0.1];
					insertChildren = "[_target] call tu_arty_fnc_grenade_subactions";
				};
			};
		};
		
		class UserActions {
			class tu_arty_uav_extra_cam
			  {
				displayName = "<t color='#CCCCCC'>Доп. камера</t>";
				displayNameDefault = "";
				priority = 3;
				radius = 2;
				position = "camera";
				showWindow = 0;
				onlyForPlayer = 1;
				condition = "(isNil 'bn_uav_cam') && {((uavControl this select 0) == player) && {(uavControl this select 1) != ''}}";
				statement = "[this] spawn tu_arty_fnc_uav_cam_create";
			  };
		};
	};
	
	class TU_Cheap_UAV_Blue: TU_Cheap_UAV_Red {
		side = 1;
		faction = "BLU_F";
		crew = "B_UAV_AI";
		typicalCargo[] = {"B_UAV_AI"};
		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			displayName = "";
			dissasembleTo[] = {"TU_cheap_UAV_backpack_Blue"};
		};
	};
	
	class TU_Cheap_UAV_Green: TU_Cheap_UAV_Red {
		crew = "I_UAV_AI";
		typicalCargo[] = {"I_Soldier_lite_F"};
		side = 2;
		faction = "IND_F";
		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			displayName = "";
			dissasembleTo[] = {"TU_cheap_UAV_backpack_Green"};
		};
	};
	
	class O_UAV_01_backpack_F;
	class B_UAV_01_backpack_F;
	class I_UAV_01_backpack_F;
	class TU_cheap_UAV_backpack_Red: O_UAV_01_backpack_F {
		displayName = "Рюкзак с легким БПЛА";
		class assembleInfo {
			assembleTo = "TU_Cheap_UAV_Red";
			displayName = "лёгкий БПЛА";
			base = "";
			primary = 1;
			dissasembleTo[] = {};
		};
	};
	class TU_cheap_UAV_backpack_Blue: B_UAV_01_backpack_F {
		displayName = "Рюкзак с легким БПЛА";
		class assembleInfo {
			assembleTo = "TU_Cheap_UAV_Blue";
			displayName = "лёгкий БПЛА";
			base = "";
			primary = 1;
			dissasembleTo[] = {};
		};
	};
	
	class TU_cheap_UAV_backpack_Green: I_UAV_01_backpack_F {
		displayName = "Рюкзак с легким БПЛА";
		class assembleInfo {
			assembleTo = "TU_Cheap_UAV_Green";
			displayName = "лёгкий БПЛА";
			base = "";
			primary = 1;
			dissasembleTo[] = {};
		};
	};
	// на будущее

/*	class rhs_zsu234_aa;
	class bn_rhs_zsu234_aa: rhs_zsu234_aa {
		displayName = "ЗСУ-23-4 (усложн.)";
		tu_arty_radar_type = "SHORT RANGE AIR";
		tu_arty_radar_detection_range = 20000;
		tu_arty_radar_detection_angle = 6;
		tu_radar_tracking_time_required = 0;
		tu_arty_radar_error = 10;
		tu_radar_show_once = 0;
		tu_arty_radar_pos = "(getPos _this) vectorAdd [0,0,2]";
		tu_arty_radar_alpha = "_this getVariable ['tu_arty_fnc_firefinder_angle',0]";
		tu_arty_detectable = "_this isKindOf 'Air'";
		commanderCanSee = 4+8+16;
		gunnerCanSee = 4+8+16;
		driverCanSee = 2+8+16;
		allowTabLock = 0;
	};*/
};

// #include "interface.cpp";

#include "common.hpp"
#define TU_ARTY_GUI_GRID_X	(0)
#define TU_ARTY_GUI_GRID_Y	(0)
#define TU_ARTY_GUI_GRID_W	(0.015)
#define TU_ARTY_GUI_GRID_H	(0.02)

#define TU_ARTY_PREP_GUI_GRID_X	(0)
#define TU_ARTY_PREP_GUI_GRID_Y	(0)
#define TU_ARTY_PREP_GUI_GRID_W	(0.03)
#define TU_ARTY_PREP_GUI_GRID_H	(0.04)

class CfgMarkers {
	class ACE_MapToolFixed {
		name = "MapToolFixed";
		icon = "\tu_arty\data\mapToolFixed.paa";
		scope = 0;
		color[] = {1, 1, 1, 1};
		size = 32;
	};
	class TU_ARTY_Explosion {
		name = "TU_ARTY_Explosion";
		icon = "\tu_arty\data\explosion.paa";
		scope = 0;
		color[] = {0, 0, 0, 1};
		size = 32;
		shadow = false;
	};
};

class TU_ARTY_D {
	
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "uiNamespace setVariable ['TU_ARTY_Display', _this select 0]; if (scriptDone tu_arty_dials_handle) then {tu_arty_dials_handle = [vehicle player] execVM '\tu_arty_config\scripts\dials.sqf'}; ctrlEnable [1900, false];";
	onKeyDown = "_this call tu_arty_fnc_keydown_EH;";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "TU_ARTY_D";
    class controls {
		class Tu_Arty_RscPicture_1200: Tu_Arty_RscPicture
			{
				idc = 1200;
				type = 0;
				style = 48;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "\tu_arty\data\sight_unit.paa";
				x = 0.83 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 1 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 23.3333 * TU_ARTY_GUI_GRID_W;
				h = 49 * TU_ARTY_GUI_GRID_H;
				
				colorText[] = {1,1,1,1};
				colorBackground[] = {1,1,1,1};
				colorActive[] = {1,1,1,1};
			};

			class Tu_Arty_RscButton_1600: Tu_Arty_RscButton
			{
				idc = 1600;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "  +"; //--- ToDo: Localize;
				x = 13 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 39 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 4 * TU_ARTY_GUI_GRID_W;
				h = 10.5 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_increase_elevation; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [-1]) call tu_arty_fnc_el_dial_change;";
				class Attributes
				{
					align = "center";
				};				
			};
		class Tu_Arty_RscButton_1601: Tu_Arty_RscButton
			{
				idc = 1601;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "-"; //--- ToDo: Localize;
				x = 8.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 39 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 3.5 * TU_ARTY_GUI_GRID_W;
				h = 10.5 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_decrease_elevation; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [1]) call tu_arty_fnc_el_dial_change;";
			};
		class Tu_Arty_RscButton_1602: Tu_Arty_RscButton
			{
				idc = 1602;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "+"; //--- ToDo: Localize;
				x = 3.33 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 23 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 4 * TU_ARTY_GUI_GRID_W;
				h = 3 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_increase_deflection; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [1]) call tu_arty_fnc_def_change;";
			};
		class Tu_Arty_RscButton_1603: Tu_Arty_RscButton
			{
				idc = 1603;
				type = 1;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "-"; //--- ToDo: Localize;
				x = 3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 27 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 3.5 * TU_ARTY_GUI_GRID_W;
				h = 3 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_decrease_deflection; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [-1]) call tu_arty_fnc_def_change;";
			};
		class Tu_Arty_RscButton_1604: Tu_Arty_RscButton_1603
			{
				idc = 1604;
				text = "^"; //--- ToDo: Localize;
				x = 22.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 17 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2 * TU_ARTY_GUI_GRID_W;
				h = 2 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_increase_optic_level; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [-1]) call tu_arty_fnc_optic_change;";
			};		
		
		class Tu_Arty_RscButton_1605: Tu_Arty_RscButton_1604
			{
				idc = 1605;
				text = "v"; //--- ToDo: Localize;
				x = 22.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 21 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2 * TU_ARTY_GUI_GRID_W;
				h = 2 * TU_ARTY_GUI_GRID_H;
				tooltip = $STR_tu_arty_decrease_optic_level; //--- ToDo: Localize;
				onMouseButtonClick = "(_this + [1]) call tu_arty_fnc_optic_change;";
			};
			
			// "3.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X","6.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y"
		class Tu_Arty_RscSlider_1900: Tu_Arty_RscSlider
			{
				idc = 1900;
				type = 3;
				style = 0;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				x = 5.83 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 35 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				//w = 2 * TU_ARTY_GUI_GRID_W;
				w = 1.5 * TU_ARTY_GUI_GRID_W;
				h = 5 * TU_ARTY_GUI_GRID_H;
				colorBackground[] = {-1,-1,-1,0};
				color[] = {0,0,0,1}; //{0.5,0.5,0.7,1};
				colorActive[] ={0,0,0,1}; // {0.6,0.6,0.8,1};
				tooltip = $STR_tu_arty_bubble_level; //--- ToDo: Localize;
			};
		class Tu_Arty_RscText_Def_Small: Tu_Arty_RscText
			{
				idc = 1000;
				type = 0;
				style = 0;
				sizeEx = 0.03;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "0"; //--- ToDo: Localize;
				x = 5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 25 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 3.33333 * TU_ARTY_GUI_GRID_W;
				h = 2 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_deflection_value_small; //--- ToDo: Localize;
			};
		class Tu_Arty_RscText_Def_Large: Tu_Arty_RscText
			{
				idc = 1001;
				type = 0;
				style = 0;
				sizeEx = 0.03;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "30"; //--- ToDo: Localize;
				x = 11.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 22.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 2.5 * TU_ARTY_GUI_GRID_W;
				h = 2 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_deflection_value_large; //--- ToDo: Localize;
			};
		class Tu_Arty_RscText_1002: Tu_Arty_RscText
			{
				idc = 1002;
				type = 0;
				style = 0;
				sizeEx = 0.03;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "10"; //--- ToDo: Localize;
				x = 16.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 32 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 3.33333 * TU_ARTY_GUI_GRID_W;
				h = 2 * TU_ARTY_GUI_GRID_H;
				colorText[] = {-1,-1,-1,1};
				colorBackground[] = {-1,-1,-1,0};
				tooltip = $STR_tu_arty_elevation_value_large; //--- ToDo: Localize;
			};
		class Tu_Arty_RscText_1003: Tu_Arty_RscText
			{
				idc = 1003;
				type = 0;
				style = 0;
				sizeEx = 0.03;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "00"; //--- ToDo: Localize;
				x = 11.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
				y = 38.5 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
				w = 3.33333 * TU_ARTY_GUI_GRID_W;
				h = 2 * TU_ARTY_GUI_GRID_H;
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
    onLoad = "uiNamespace setVariable ['TU_ARTY_PREP_display', _this select 0]; [_this select 0] call tu_arty_fnc_prep_diag_init";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "TU_ARTY_PREP_D";
	class controls {
		class Tu_Arty_Background {    
			idc = -1;
			type = 0;
			style = 2; //centre text
			x = 8 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 1 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 25 * TU_ARTY_PREP_GUI_GRID_W;
			h = 15 * TU_ARTY_PREP_GUI_GRID_H;
			font = "EtelkaNarrowMediumPro";
			sizeEx = 0.03;
			colorBackground[] = {0.5,0.5,0.5,0.5};
			colorText[] = {0,0,1,1};
			text = "";
		};  
	
		class Tu_Arty_RscCombo_2100: Tu_Arty_RscCombo
		{
			idc = 2100;
			x = 15.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 4 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 16 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
			onLBSelChanged = "[] call tu_arty_prep_init_charge_list;";
		};
		class Tu_Arty_RscText_1000: Tu_Arty_RscText
		{
			idc = 3000;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1000;
			x = 15.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 1.5 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 12 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
		};
		class Tu_Arty_RscText_1001: Tu_Arty_RscText
		{
			idc = 3001;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1001;
			x = 8.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 4 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 6 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
		};
		class Tu_Arty_RscText_1002: Tu_Arty_RscText
		{
			idc = 3002;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1002;
			x = 8.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 8 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 6 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
		};
		class Tu_Arty_RscCombo_2101: Tu_Arty_RscCombo
		{
			idc = 3101;
			x = 15.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 6 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 16 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
		};
		class Tu_Arty_RscSlider_1900: Tu_Arty_RscSlider
		{
			idc = 3900;
			x = 15.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 8 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 16 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
			color[] = {0,0,0,1};
			colorActive[] = {0,0,0,1};
			onSliderPosChanged = "[] call tu_arty_prep_update;";
		};
		class Tu_Arty_RscText_1003: Tu_Arty_RscText
		{
			idc = 3003;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscText_1003;
			x = 8.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 6 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 6 * TU_ARTY_PREP_GUI_GRID_W;
			h = 1 * TU_ARTY_PREP_GUI_GRID_H;
		};
		class Tu_Arty_RscButton_1600: Tu_Arty_RscButton
		{
			idc = 3600;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscButton_1600;
			x = 18.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 10 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 6 * TU_ARTY_PREP_GUI_GRID_W;
			h = 2 * TU_ARTY_PREP_GUI_GRID_H;
			soundClick[] = 
			{
				"\bn_te\sound\agm_scopes_click",
				0.07,
				1
			};
			onMouseButtonClick = "[] call tu_arty_prep_start;";
		};
		class Tu_Arty_RscButton_1601: Tu_Arty_RscButton_1600
		{
			idc = 3601;
			text = $STR_A3_tu_arty_prep_shells_dialog_RscButton_1601;
			x = 25.5 * TU_ARTY_PREP_GUI_GRID_W + TU_ARTY_PREP_GUI_GRID_X;
			y = 10 * TU_ARTY_PREP_GUI_GRID_H + TU_ARTY_PREP_GUI_GRID_Y;
			w = 6 * TU_ARTY_PREP_GUI_GRID_W;
			h = 2 * TU_ARTY_PREP_GUI_GRID_H;
			onMouseButtonClick = "closeDialog 2;";
		};
	};
};

class TU_ARTY_FIREFINDER_D {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "uiNamespace setVariable ['TU_ARTY_FIREFINDER_display', _this select 0];";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "TU_ARTY_FIREFINDER_D";
	class controls {
		class Tu_Arty_FF_Background {    
			idc = -1;
			type = 0;
			style = 2; //centre text
			x = 8 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 1 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 25 * TU_ARTY_GUI_GRID_W;
			h = 15 * TU_ARTY_GUI_GRID_H;
			font = "EtelkaNarrowMediumPro";
			sizeEx = 0.03;
			colorBackground[] = {0.5,0.5,0.5,0.5};
			colorText[] = {0,0,1,1};
			text = "";
		};  
		class Tu_Arty_RscSlider_5900: Tu_Arty_RscSlider
		{
			idc = 5900;
			x = 15.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 8 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 16 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
			color[] = {0,0,0,1};
			colorActive[] = {0,0,0,1};
			onSliderPosChanged = "sliderSetRange [5900, 0, 359]; ctrlSetText [5003, 'Азимут: ' + str(floor(sliderPosition 5900))];";
		};
		class Tu_Arty_RscText_5003: Tu_Arty_RscText
		{
			idc = 5003;
			text = "0";
			x = 8.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 6 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 16 * TU_ARTY_GUI_GRID_W;
			h = 1 * TU_ARTY_GUI_GRID_H;
		};
		class Tu_Arty_RscButton_1600: Tu_Arty_RscButton
		{
			idc = 5600;
			text = "Ок";
			x = 18.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 10 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 2 * TU_ARTY_GUI_GRID_H;
			soundClick[] = 
			{
				"\bn_te\sound\agm_scopes_click",
				0.07,
				1
			};
			onMouseButtonClick = "(vehicle player) setVariable ['tu_arty_fnc_firefinder_angle',floor(sliderPosition 5900), true]; closeDialog 1;";
	
		};
		class Tu_Arty_RscButton_1601: Tu_Arty_RscButton_1600
		{
			idc = 5601;
			text = "Отмена";
			x = 25.5 * TU_ARTY_GUI_GRID_W + TU_ARTY_GUI_GRID_X;
			y = 10 * TU_ARTY_GUI_GRID_H + TU_ARTY_GUI_GRID_Y;
			w = 6 * TU_ARTY_GUI_GRID_W;
			h = 2 * TU_ARTY_GUI_GRID_H;
			onMouseButtonClick = "closeDialog 2;";
		};
	};
};

class RscTitles {
	class bn_uav_sight {
		idd = -1;
		movingEnable = 0;
		enableSimulation = 1;
		enableDisplay = 1;
		onLoad = "";
		onUnload = "";
		duration = 1e+011;
		fadein = 0;
		fadeout = 0;
		name = "bn_uav_sight";
		class RscPicture;
		class controls {
			class BN_UAV_SIGHT_PIP: RscPicture {
				idc = 932009;
				type = 0;
				style = 48;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "#(argb,256,256,1)r2t(bnuavsight,1.0);";
				colorText[] = {1,1,1, 0.98};
				colorBackground[] = {1,0,0, 0};
				shadow = 1;

				x = -0.3;//(0.5-0.4/2 + 0.45*0.4) * safezoneW + safezoneX;
				y = -0.25; //(0 + 0.19*0.3) * safezoneH + safezoneY;
				w = 0.4 * safezoneW / (4/3);
				h = 0.4 * safezoneH;
			};
			class BN_UAV_SIGHT_LINES: RscPicture {
				idc = 932009;
				type = 0;
				style = 48;
				sizeEx = 0.04;
				lineSpacing = 1;
				font = "PuristaMedium";
				text = "\tu_arty\data\4x_m22.paa";
				colorText[] = {1,1,1, 0.98};
				colorBackground[] = {1,0,0, 0};
				shadow = 0;

				x = -0.3;//(0.5-0.4/2 + 0.45*0.4) * safezoneW + safezoneX;
				y = -0.25; //(0 + 0.19*0.3) * safezoneH + safezoneY;
				w = 0.4 * safezoneW / (4/3);
				h = 0.4 * safezoneH;
			};
		};
	};
};