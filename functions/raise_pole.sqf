private ['_gun'];
_gun = _this select 0;
if (!(_gun getVariable ["tu_arty_pole_raised", false])) then {
	_gun setVariable ["tu_arty_pole_raised", true, true];
	_pole = "Land_RedWhitePole_F" createVehicle (position _gun); 
	_pole attachTo [_gun,[0,0,0],"gunnerView"];
	_gun setVariable ["tu_arty_pole_object", _pole, true];
} else {
	deleteVehicle (_gun getVariable "tu_arty_pole_object");
	_gun setVariable ["tu_arty_pole_raised", false, true];
};