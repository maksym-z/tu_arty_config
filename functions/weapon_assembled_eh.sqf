diag_log "weapon assembled EH";
diag_log _this;
params ['_unit','_weapon']; 
if !(local _unit) exitWith {};
detach _weapon;
if (_weapon isKindOf "bn_ace2_aiming_circle") exitWith {};
_weapon setDir ((getDir _weapon) + (random 60)-30);
if (_weapon isKindOf "TU_Arty_Aiming_Stake") then {
	[_weapon, true, [0,1,0]] call ace_dragging_fnc_setCarryable;
};
if (_weapon isKindOf "TU_ARTY_M224_mortar") then {
	[_weapon, true, [0,1.2,0],  (random 40)-20] call ace_dragging_fnc_setDraggable;
};