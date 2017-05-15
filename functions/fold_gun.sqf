TU_ARTY_GUN_INTERACTION_RANGE = 8;
private _gun = _this select 0;
if (count ([_gun, TU_ARTY_GUN_INTERACTION_RANGE] call tU_arty_fnc_select_helpers) < 3) exitWith {
	hint "Нужно 3 человека.";
};
{
	_x playAction "Gear";
} forEach ([_gun, TU_ARTY_GUN_INTERACTION_RANGE] call tU_arty_fnc_select_helpers);
[30,2, _gun, TU_ARTY_GUN_INTERACTION_RANGE, [], {
//	diag_log "finish"; 
//	diag_log _this; 
	private _gun = (_this select 0) select 0; 
	[_gun,1] call rhs_fnc_d30_pack; 
	_gun setVariable ["tu_arty_folded",true,true]
},{}, "Перевод гаубицы в походное положение"] call tu_arty_fnc_collective_action;