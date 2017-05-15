//[box]
if ((isNil 'tu_arty_enable_cookoff') || {!tu_arty_enable_cookoff}) exitWith {}; // нужно включить принудительно
private ['_box','_ammo','_mags'];
_probability = 7;
_box = _this select 0;
_source = _this select 1;
hint (str _source); //debug
_box setVariable ["tu_arty_cookoff_in_progress",true];
if (!(alive _box) || !(local _box)) exitWith {};
_mags = [];
_mags = (magazineCargo _box);
if (count _mags < 1) exitWith {};
_location = position _box;
_ammo = [];
{
	if (count (getText(configFile >> "CfgMagazines" >> _x >> "tu_arty_chargeName")) > 1) then {
		_ammo pushBack (getText(configFile >> "CfgMagazines" >> _x >> "ammo"));
	};
} forEach (_mags);
if (count _ammo < 1) exitWith {};
_detonated = [];
{
	if ((random 100) < _probability) then {
		_badabum = _x createVehicle (_location);
		_badabum setPosATL ((_location) vectorAdd [(random 1)-0.5,(random 1)-0.5,0.1]);
		_badabum setVelocity [(random _probability)-(_probability/2),(random _probability)-(_probability/2),random _probability];
		_badabum setVectorDir (velocity _badabum);
		_detonated pushBack _badabum;
		sleep (random 1);
		_probability = (_probability + 10) mod 58; // упырил мел, а то можно и сервер положить
	};
} forEach _ammo;
if (count _detonated > 0) then {
	deleteVehicle _box;
	sleep 15;
	{
		deleteVehicle _x;
	} forEach _detonated; // garbage collection
	_location remoteExec ["tu_arty_fnc_exlposion_marker", 2, false];
};