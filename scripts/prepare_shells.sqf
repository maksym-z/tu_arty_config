// diag_log "tu_arty_prepare_shells";
// diag_log _this;
private ["_source", "_qty","_classname_prepped","_classname_unprepped","_holder","_remember_mags","_all_mags","_leave_mags", "_n","_cancel","_prep_time", "_nearby"];

// _source, _qty, _classname_unprepped, _classname_prepped
_source = _this select 0;
_qty = _this select 1;
_classname_unprepped = _this select 2;
_classname_prepped = _this select 3;
_prep_time = 5; // to do: read from config
_all_mags = magazinesAmmoCargo _source; // [[mag, ammo],[mag, ammo]]
_remember_mags = [];
_leave_mags = [];
_n = 0;
_cancel = false;

{if (((_x select 0) != _classname_unprepped) || (_n >= _qty)) then {
		_leave_mags = _leave_mags + [_x];
	} else {
		_remember_mags = _remember_mags + [_x];
		_n = _n + 1;
	};
} forEach _all_mags;	

clearMagazineCargoGlobal _source; // to do: work with groundweaponholders
{_source addMagazineAmmoCargo [_x select 0, 1, _x select 1]} forEach _leave_mags; //putting stuff back

_nearby = nearestObjects [player, ['GroundWeaponHolder'], 3]; // preparing a place for mines
_holder = objNull;
 if (count _nearby > 0) then {_holder = _nearby select 0};
 if (isNull _holder) then {
	_holder = 'GroundWeaponHolder' createVehicle (getPosATL player);
	_holder addWeaponCargoGlobal ["FakeWeapon", 1];
};
 
_holder setPosATL [(getPosATL player) select 0, (getPosATL player) select 1, (getPosATL player) select 2]; 
// hint (str _holder);
// diag_log [(player getVariable ['tu_arty_prepare_status',2]), (player distance _holder), _n, alive player, alive _source];
player playAction "Gear";
while {
	((player getVariable ['tu_arty_prepare_status',2]) >= 1) && {_n>0} && {((player distance _holder) < 2) && (_holder != (backpackContainer player))} && {(alive player) && (alive _source)};
	//tu_arty_prepare_status: 2 - busy, 1 - ready, 0 - cancel
} do {
		[_prep_time, [_classname_prepped, _holder, _n], {
		diag_log "tu_arty_debug: prepare_shells.sqf";
		_tu_arty_params = _this select 0;
		diag_log _tu_arty_params;
		(_tu_arty_params select 1) addMagazineCargoGlobal [_tu_arty_params select 0, 1];
		if ((_tu_arty_params select 2) > 1) then {hint format ['Осталось %1', (_tu_arty_params select 2) - 1];} else {hint 'Готово.'};
		player setVariable ['tu_arty_prepare_status',1];
	}, {player setVariable ['tu_arty_prepare_status',0]; hint 'Подготовка прервана;'}, "Подготовка заряда"] call ace_common_fnc_progressBar;
	waitUntil {sleep 0.1; (player getVariable ['tu_arty_prepare_status',2]) < 2};
	if ((player getVariable ['tu_arty_prepare_status',0]) == 0) exitWith {_source addMagazineCargoGlobal [_classname_unprepped, _n];};
	_n = _n - 1;
	player setVariable ['tu_arty_prepare_status',2];
};
if (count (weaponCargo _holder - ['FakeWeapon']) == 0) then {clearWeaponCargoGlobal _holder};
player setVariable ['tu_arty_prepare_status',nil];