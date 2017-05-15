// _time, _helpers, _gun, _range, _args, _action, _onCancel, _title
private _time = _this select 0;
private _helpers_required =  _this select 1;
private _gun =  _this select 2;
private _range = _this select 3;
private _args = _this select 4;
private _action = _this select 5;
private _onCancel = _this select 6;
private _title = _this select 7;
[_time, [_gun,_range,_helpers_required], _action, _onCancel, _title, {
	private _args = _this select 0;
	if (count (_args call tU_arty_fnc_select_helpers) < (_args select 2)) exitWith {
		hint "Помощники разбежались";
		//closeDialog 0;
		false
	};
	true
}] call ace_common_fnc_progressBar;