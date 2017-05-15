private _gun = _this select 0;
if (!(isNull attachedTo _gun)) exitWith {
	hint "Сначала отцепи.";
};
TU_ARTY_GUN_INTERACTION_RANGE = 8;
if (count ([_gun, TU_ARTY_GUN_INTERACTION_RANGE] call tU_arty_fnc_select_helpers) < 3) exitWith {
	hint "Нужно 3 человека.";
};
{
	_x playAction "Gear";
} forEach ([_gun, TU_ARTY_GUN_INTERACTION_RANGE] call tU_arty_fnc_select_helpers);
[30,2, _gun, TU_ARTY_GUN_INTERACTION_RANGE, [], {private _gun = (_this select 0) select 0; [_gun,0] call rhs_fnc_d30_pack; _gun setVariable ["tu_arty_folded",false,true]},{}, "Перевод гаубицы в боевое положение"] call tu_arty_fnc_collective_action;