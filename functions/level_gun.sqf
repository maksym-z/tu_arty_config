private ["_gun", "_pad"];
// diag_log "level_gun";
// diag_log _this;
_gun = (_this select 0) select 0;
_pad = nil;
_pad = "Land_HelipadEmpty_F" createVehicle (getPos _gun);
//hint (str[_pad,getPos _pad,_gun,getPos _gun]); 
_pad setVectorUp [0,0,1];
_pad setPosATL (getPosATL _gun);
_pad setDir (getDir _gun);

/*
[_gun, _pad] spawn { //дебаг-костыль
	waitUntil {
		_d = (_this select 0) distance (_this select 1);
		hint str(d);
		if (_d>1) exitWith {detach (_this select 0); deleteVehicle (_this select 0);};
		sleep 3;
		_d>1;
	};
};*/

if (_gun isKindOf "TU_ARTY_M224_mortar") exitWith {
	_gun attachTo [_pad, [0,0,0.19]];
};
if (_gun isKindOf "TU_ARTY_120mm_mortar") exitWith {
	_gun attachTo [_pad, [0,0,0.36]];
};
if (_gun isKindOf "rhs_2b14_82mm_Base") exitWith {
	_gun attachTo [_pad, [0,0,0.38]];
};
if (_gun isKindOf "bn_ace2_aiming_circle") exitWith {
	_gun attachTo [_pad, [0,0,1]];
};

// default option in case of further classname changes
_gun attachTo [_pad, [0,0,0.38]]