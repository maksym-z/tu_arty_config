
//	diag_log "tu_arty_handleKeydown (dragging)";
//	diag_log _this;
private ["_phase","_gun","_shft","_phase","_new_phase"];

_code = _this select 1;
_shft = _this select 2;
_gun = _this select 5;

if (!(alive player) || {!(alive _gun)}) exitWith {
	[_gun] call tu_arty_fnc_endshift;
};

if (player getVariable ["tu_arty_busy",false]) exitWith {

};
	
if (_code in (actionKeys "turnLeft")) exitWith {
	//diag_log "Shifting left";
	_phase = _gun animationPhase "MainTurret_RotateFast";
	if (_shft) then {
		_new_phase = _phase-25;
	} else {
		_new_phase = _phase-5;
	};
	_gun animate ["MainTurret_RotateFast", _new_phase];
	player setDir (_new_phase / 6000 * 360 + 250) mod 360;
};

if (_code in (actionKeys "turnRight")) exitWith { 
	// diag_log "Shifting right";
	_phase = _gun animationPhase "MainTurret_RotateFast";
	if (_shft) then {
		_new_phase = _phase+25;
	} else {
		_new_phase = _phase+5;
	};
	_gun animate ["MainTurret_RotateFast", _new_phase];
	player setDir (_new_phase / 6000 * 360 + 250) mod 360;
};

if (_code in (actionKeys "MoveBack")) exitWith {
	player setVariable ["tu_arty_busy",true];
	[7, [_gun], {_this call tu_arty_fnc_endshift;}, {((_this select 0) select 0) animate ['MainTurret_RotateFast', (((_this select 0) select 0) animationPhase 'MainTurret_RotateFast') + (random 200) - 100]; _this call tu_arty_fnc_endshift; hint 'Бросил как попало'}, "Установка двуноги"] call ace_common_fnc_progressBar;
};

/* Arguments:
 * 0: NUMBER - Total Time (in game "ACE_time" seconds)
 * 1: ARRAY - Arguments, passed to condition, fail and finish
 * 2: CODE or STRING - On Finish: Code called or STRING raised as event.
 * 3: CODE or STRING - On Failure: Code called or STRING raised as event.
 * 4: STRING - (Optional) Localized Title
 * 5: CODE - (Optional) Code to check each frame
 * 6: ARRAY - (Optional) Exceptions for checking EFUNC(common,canInteractWith)
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [5, [], {Hint "Finished!"}, {hint "Failure!"}, "My Title"] call ace_common_fnc_progressBar
 **/