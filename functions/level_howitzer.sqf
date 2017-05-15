BN_FOUNDATION_HEIGHT = 0.85;  
BN_MAXIMUM_LEVEL_TIME = 120; 
BN_FOUNDATOIN_CLASSNAME = "pzn_dirtfoundation2";
BN_LEVEL_GUN_TOKEN_received = 0; // distributed mutex
BN_LEVEL_GUN_TOKEN_TIEMOUT = 15;
BN_LEVEL_GUN_TOKEN_TIEMOUT_START = 0;
private _gun = _this select 0;  
private _bbox = boundingBoxReal _gun;  
private _left_back = _gun modelToWorld (_bbox select 0);  
private _right_back = _gun modelToWorld [_bbox select 1 select 0, _bbox select 0 select 1, _bbox select 0 select 2];  
private _front_center = _gun modelToWorld [0, _bbox select 1 select 1, _bbox select 0 select 2];  
private _zmax = getPosATL _gun select 2;  
private _zmin = getPosATL _gun select 2;  
{  
	if (_x > _zmax) then {  
		_zmax = _x;  
	};  
	if (_x < _zmin) then {  
		_zmin = _x;  
	};  
} forEach [_left_back select 2, _right_back  select 2, _front_center  select 2];  

private _delta_z = abs(_zmax - _zmin);  
if (_delta_z > BN_FOUNDATION_HEIGHT) exitWith {  
	hint "Слишком неровная поверхность";  
};  

if ((vectorMagnitude [vectorUp _gun select 0, vectorUp _gun select 1, 0]) < 0.015) exitWith {
	hint "Орудие уже выставлено горизонтально.";
};
private _nearby_foundation = (getPos _gun) nearestObject BN_FOUNDATOIN_CLASSNAME;
diag_log "_nearby_foundation";
diag_log _nearby_foundation;
if !(isNull _nearby_foundation) then {
	diag_log (_gun distance _nearby_foundation);
};
if ((!(isNull _nearby_foundation)) && {_gun distance _nearby_foundation < 3}) exitWith {
	hint "Участок уже выровнен.";
};
if (!(isNil "TU_ARTY_DISABLE_HOWITZER_LEVELLING") && {!TU_ARTY_DISABLE_HOWITZER_LEVELLING}) exitWith {
};

BN_LEVEL_GUN_TOKEN_TIEMOUT_START = time;
["BN_LEVEL_GUN_TOKEN", player, _gun] remoteExec ["tu_arty_fnc_request_token",2];
hint "Секундочку...";

[_gun, _zmax, _delta_z] spawn {
	diag_log "tu_arty requesting token from server...";
	waitUntil {
		(time > (BN_LEVEL_GUN_TOKEN_TIEMOUT_START + BN_LEVEL_GUN_TOKEN_TIEMOUT)) || (BN_LEVEL_GUN_TOKEN_received != 0)
	};
	if (BN_LEVEL_GUN_TOKEN_received == 0) exitWith {diag_log "tu_arty token request timed out"};
	if (BN_LEVEL_GUN_TOKEN_received == -1) exitWith {hint "Кто-то уже занят горизонтированием."};
	diag_log "token received.";
	params ["_gun", "_zmax", "_delta_z"];
	private _exp = 5;  
	private _duration = BN_MAXIMUM_LEVEL_TIME * (_exp ^ (_delta_z / (BN_FOUNDATION_HEIGHT))) / (_exp - 1) - (BN_MAXIMUM_LEVEL_TIME / (_exp - 1)) + 15; 
	[_duration, [_gun, _zmax], {  
		private _gun = _this select 0 select 0;  
		private _zmax = _this select 0 select 1;  
		private _foundation_position = [getPos _gun select 0, getPos _gun select 1, _zmax - BN_FOUNDATION_HEIGHT*0.8];  

		_gun setPosATL (_foundation_position vectorAdd [0,0,BN_FOUNDATION_HEIGHT+0.2]);  
		_gun setVectorUp [0,0,1];    
		private _foundation = BN_FOUNDATOIN_CLASSNAME createVehicle _foundation_position;  
		_foundation setPosATL _foundation_position;  
		_foundation setDir (getDir _gun);   
		_foundation setVectorUp [0,0,1]; 
		_gun setVariable ["tu_arty_level_howitzer_mutex",false,true];
		["BN_LEVEL_GUN_TOKEN", player, _gun] remoteExec ["tu_arty_fnc_give_up_token",2];
	}, {hint "Горизонтирование прервано!"; ["BN_LEVEL_GUN_TOKEN", player, _gun] remoteExec ["tu_arty_fnc_give_up_token",2];}, "Горизонтирование орудия"] call ace_common_fnc_progressBar;
};