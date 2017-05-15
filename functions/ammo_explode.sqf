private ["_box", "_n"];
diag_log "ammo explode";
diag_log _this;
hint (str _this);
_box = _this select 0;
n = 0;
if ("bn_82mm_shell_0" in (magazineCargo _box)) then {
	if (getDammage _box > 0.5) then {
		{if (_x == "bn_82mm_shell_0") then {_tu_arty_badabum = "Sh_82mm_AMOS" createVehicle (getPos _box); _tu_arty_badabum setPosATL [(getPosATL _box select 0) + random n, (getPosATL _box select 1) + random n, (getPosATL _box select 2)]; n=n+1;};} forEach (magazineCargo _box);
		deleteVehicle _box;
	};
};