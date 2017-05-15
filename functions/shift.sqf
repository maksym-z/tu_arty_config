private ["_gun", "_phase", "_absPhase", "_handle", "_endaction"];
_gun = _this select 0;
closeDialog 0;
player attachTo [_gun, [0,0,-0.27], "shift_right"];

_phase = _gun animationPhase "MainTurret";

_absPhase = (abs _phase) mod 6000; 

if(_phase < 0) then {
	_absPhase = 6000-_absPhase;
};

// hint (str _phase);

player setDir (((_absPhase / 6000 * 360 + 250) mod 360) + (random 46) - 23); // привет Фьёзеку

player setVariable ["tu_arty_dragged_gun",_gun];
_handle = (findDisplay 46) displayAddEventHandler ["KeyDown", {(_this + [player getVariable "tu_arty_dragged_gun"]) call tu_arty_fnc_handleKeydown}];
_gun setVariable ["bn_drag_handle", _handle, true];

// _player playAction "Gear";
player playMove "ACINPKNLMSTPSRASWRFLDNON";

/* _endaction = player addAction ["<t color='#FF0000'>Установить двуногу</t>",{
	[_this select 0, _this select 2] call tu_arty_fnc_endshift;
}];
 */
if( !(alive player) || {!(alive _gun)}) exitWith {
		[_gun] call tu_arty_fnc_endshift;
};
