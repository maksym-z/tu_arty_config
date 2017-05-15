private ["_gun","_shell","_vel","_speed","_disperse","_newDier","_n","_elevation","_distance"];
_gun = _this select 0;
_shell = _this select 5;
_vel = velocity _shell;
_speed = vectorMagnitude _vel;
_disperse = [random 0.01, random 0.01, 0]; // todo: read dispersion from config
_newDir = ((_gun weaponDirection (weapons _gun select 0)) vectorMultiply _speed) vectorAdd _disperse;
// hint str ([_vel, _newDir, _speed]); 
_shell setVelocity _newDir;
[_gun] call tu_arty_fnc_recoil;
_elevation = floor ((asin ((_gun weaponDirection (weapons _gun select 0)) select 2)) / 360 * 6000);
// hint str (_shell);

if (!local _gun) exitWith {};

_n = 0;
_distance = 0;

[_shell] spawn {
	_n = [];
	while {
		(alive (_this select 0)) && ((getPosATL (_this select 0)) select 2 > 0)
	} do {
		_n = getPos (_this select 0);
	}; 
	if (getText (configFile >> "CfgAmmo" >> typeOf (_this select 0) >> "tu_arty_effect") == "Smoke") then {_smoke = "rhs_ammo_rdg2_white" createVehicle (_n); _smoke setPos _n};
	[_n,"tu_arty_fnc_exlposion_marker",false,false] call BIS_fnc_MP;
	if (!isNil "tu_arty_debug_mode") then {hint (str (_gun distance _n))};
};