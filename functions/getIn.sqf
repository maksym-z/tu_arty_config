// diag_log "getIn";
// diag_log _this;

tu_arty_dials_handle = 0 spawn {};
//if (isNil tu_arty_init_functions) then {
// 0 = [] execVM "initFunctions.sqf";
//};


// do i need this anymore?
tu_arty_handleKeydown_gunner = {
//	diag_log "tu_arty_handleKeydown_gunner";
//	diag_log _this;
	if ((_this select 1) == 203) exitWith {(_this + [-1]) call tu_arty_fnc_traverse};
	if ((_this select 1) == 205) exitWith {(_this + [1]) call tu_arty_fnc_traverse};
	
	if ((_this select 1) == 200) exitWith {(_this + [-1]) call tu_arty_fnc_elevate};
	if ((_this select 1) == 208) exitWith {(_this + [1]) call tu_arty_fnc_elevate};
};

[] call tu_arty_fnc_assign_marker_color;

_handle = (findDisplay 46) displayAddEventHandler ["KeyDown", {(_this + [vehicle player]) call tu_arty_fnc_keydown_EH}]; //tu_arty_handleKeydown_gunner
(vehicle player) setVariable ["tu_arty_gunner_handle", _handle, true];
