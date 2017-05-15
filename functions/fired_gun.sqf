private ["_gun","_shell","_vel","_speed","_disperse","_extraDispersionW"];
_gun = _this select 0;
_shell = _this select 6; // 5 >> 6 (firedbis)
if (_shell isKindOf "BulletBase") exitWith {};
_selectedWeapon = (weapons _gun) select 0;
_extraDispersionW = (getNumber (configFile >> "CfgWeapons" >> _selectedWeapon >> "tu_arty_extra_dispersion_w"))*360/6000; // дополнительное рассеивание по фронту - главным образом для "Града"
if (_extraDispersionW > 0) then {
	[_shell, (random (floor ((deg _extraDispersionW)*1000)))/500 - _extraDispersionW, 0, 0] call ace_common_fnc_changeProjectileDirection;
};
//diag_log ["tu arty locality check",local _gun, local _shell, _gun turretLocal [0]];
if (_gun turretLocal [0]) then {
	[_shell] call tu_arty_fnc_add_observable;
} else {
};