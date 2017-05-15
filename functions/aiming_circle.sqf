private ["_layer","_keyDownHandlerId","_sight_orientation","_weapon_dir","_x0","_y0","_xdash","_ydash", "_handler_id", "_tu_arty_gun_sight_cam"];
_tu_arty_gun_sight_cam = "camera" camCreate (position (vehicle player));
_tu_arty_gun_sight_cam cameraEffect ["internal", "back", "bngunsightsurface"];
_tu_arty_gun_sight_cam setDir (getDir (vehicle player));
_tu_arty_gun_sight_cam attachTo [vehicle player,[0,0,0.3], "gunnerView"];
_tu_arty_gun_sight_cam camSetFov 0.14;//;0.0718;
_tu_arty_gun_sight_cam camCommit 0;
uiNamespace setVariable ["tu_arty_gun_sight_cam",_tu_arty_gun_sight_cam];


/*_layer = ["BN_GUN_SIGHT"] call BIS_fnc_rscLayer;
_layer cutRsc ["BN_GUN_SIGHT", "PLAIN", 0, false];*/
_keyDownHandlerId = (findDisplay 46) displayAddEventHandler ["KeyDown", {(_this + [vehicle player, _tu_arty_gun_sight_cam]) call bn_te_fnc_gun_sight_keydown_EH}];
	
_handler_id = addMissionEventHandler ["Draw3D", {
	_tu_arty_gun_sight_cam = uiNamespace getVariable "tu_arty_gun_sight_cam";
	if (isNil "_tu_arty_gun_sight_cam") exitWith {hint "прицел сломалсо";};
	_sight_orientation = (((vehicle player) getVariable ["bn_sight_orientation",0]) + (getDir (vehicle player))) mod 360;
	_sight_elevation = ((vehicle player) getVariable ["bn_sight_elevation",0]);
	_weapon_dir = ((vehicle player) weaponDirection ((weapons (vehicle player)) select 0));
	_x0 = _weapon_dir select 0;
	_y0 = _weapon_dir select 1;
	_weapon_dir_atan = _x0 atan2 _y0;
	_xdash = _x0 * (cos _sight_orientation) - _y0 * (sin _sight_orientation);
	_ydash = _x0 * (sin _sight_orientation) + _y0 * (cos _sight_orientation); // не зря я про матрицу поворота учил, блеать
	_tu_arty_gun_sight_cam setVectorDirAndUp [
		[_xdash, _ydash, 0], 
		[0,0,1]]; // todo: подъём окуляра
//	[_tu_arty_gun_sight_cam,[_sight_elevation,0,getDir _tu_arty_gun_sight_cam]] call bn_te_fnc_SetPitch; 
//	hint (str [_weapon_dir, _xdash, _ydash, _sight_orientation]);
}];

uiNamespace setVariable ["BN_TE_CamViewChanged", true];
uiNamespace setVariable ["BN_TE_CamView", 1];

[_handler_id, _keyDownHandlerId]