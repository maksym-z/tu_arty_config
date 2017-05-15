// ивентхендлер, в основном для миномётов
private ["_gun","_shell","_vel","_speed","_disperse","_newDir","_n","_elevation","_distance", "_distanceFactor","_selectedWeapon","_disperseDegrees"];
_gun = _this select 0;
_shell = _this select 6; // 5 >> 6 (firedbis)
_vel = velocity _shell;
_speed = vectorMagnitude _vel;
_selectedWeapon = (weapons _gun) select 0; // magic optimisation
_disperseDegrees = deg (getNumber (configFile >> "CfgWeapons" >> _selectedWeapon >> "dispersion"));
_newDir = (_gun weaponDirection _selectedWeapon) vectorMultiply _speed; 

_mag = _this select 5 ;// _mag = currentMagazine _gun; (firedbis)

//hint (str [_gun, _shell, _selectedWeapon, _disperseDegrees, _newDir, _mag]); 
// debug - remove if ok

//аццкий костыль, без него мина летит хрен знает куда:
_shell setVelocity _newDir;
[_shell, (random (floor (_disperseDegrees*1000)))/500 - _disperseDegrees,(random (floor (_disperseDegrees*1000)))/500 - _disperseDegrees, 0] call ace_common_fnc_changeProjectileDirection;
[_gun] call tu_arty_fnc_recoil;


if (_gun turretLocal [0]) then {
	[_shell] call tu_arty_fnc_add_observable;
} else {
//	diag_log "tu_arty observable server exec";
//	[_shell] remoteExecCall ["tu_arty_fnc_add_observable", 0, false];
};