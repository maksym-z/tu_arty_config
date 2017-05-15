// Выбор типа и источника боепитания
/*diag_log "bn_csw_load: adding subactions"; 
diag_log _this;*/

private _mags_allowed = getArray (configFile >> "CfgWeapons" >> (_gun weaponsTurret _turret_path) select 0>> "magazines");

private _available_magazine_info = [];  //[[magazine, description, icon] ...]

private _magazines = [];
{
	_magazines pushBackUnique _x;
} forEach (magazines player);

{
	if ((_x isKindOf ["HandGrenade", configFile >> "CfgMagazines"]) || (_x isKindOf ["1Rnd_HE_Grenade_shell",configFile >> "CfgMagazines"])) then {
		_available_magazine_info pushBack [
			_x,
			getText (configFile >> "CfgMagazines" >> _x >> "displayName"),
			getText (configFile >> "CfgMagazines" >> _x >> "picture")
		];
	};
} forEach _magazines;


private _actions = [];
{
	private _target = _this select 0;
	private _selected_magazine = _x select 0;
	private _childStatement = {(_this select 2) call tu_arty_fnc_attach_grenade;};
    private _action = [
		format["bn_grenade_attach:%1",_x], 
		format["%1", (_x select 1)],
		_x select 2, 
		_childStatement, 
		{true}, 
		{}, 
		[_selected_magazine, _target], 
		{[0, 0, 0]}, 
		3,
		[false,true,false,false,false],
		{}
		] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];
} forEach _available_magazine_info;

_actions