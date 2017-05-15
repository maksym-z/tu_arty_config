disableSerialization;
_display = _this select 0;
_box = uiNamespace getVariable "TU_ARTY_prep_source";
if ((player distance _box > 3) && (_box != (backpackContainer player))) exitWith {hint "Слишком далеко"; closeDialog 2;};
lbClear (_display displayCtrl 2100);
_n = 0;
_init_charges = ["bn_82mm_shell_0", "bn_82mm_smoke_0"]; //todo: read from config
_added_charges = [];

// diag_log (magazineCargo _box);

{
//	diag_log (count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')));
	if ((count (getArray (configFile >> 'CfgMagazines' >> _x >> 'tu_arty_availableCharges')) > 0) && !(_x in _added_charges)) then {
		_added_charges = _added_charges + [_x]; 
		(_display displayCtrl 2100) lbAdd (getText (configFile >> "CfgMagazines" >> _x >> "displayName"));
		(_display displayCtrl 2100) lbSetData [_n, _x];
//		diag_log ["adding",_x];
		_n=_n+1;
	}
} forEach magazineCargo _box;

tu_arty_prep_init_charge_list = {
	_display = uiNamespace getVariable ['TU_ARTY_PREP_display', displayNull];
	_box = uiNamespace getVariable "TU_ARTY_prep_source";
	_shell_type = (_display displayCtrl 2100) lbData (lbCurSel (_display displayCtrl 2100));
	_charges = getArray (configFile >> "CfgMagazines" >> _shell_type >> "tu_arty_availableCharges");
	// hint (str _charges);
	_n = 0;
	lbClear (_display displayCtrl 3101);
	{
		(_display displayCtrl 3101) lbAdd (getText (configFile >> "CfgMagazines" >> _x >> "tu_arty_chargeName"));
		(_display displayCtrl 3101) lbSetData [_n, _x];
		_n = _n + 1;
	} forEach _charges;
	(_display displayCtrl 3900) sliderSetRange [1, {_x == _shell_type} count (magazineCargo _box)];
	(_display displayCtrl 3900) sliderSetSpeed [1, 2];
	(_display displayCtrl 3002) ctrlSetText (format [localize "STR_A3_tu_arty_prep_shells_dialog_RscText_1002", floor (sliderPosition (_display displayCtrl 3900))]);
};

tu_arty_prep_update = {
	_display = uiNamespace getVariable ['TU_ARTY_PREP_display', displayNull];
	(_display displayCtrl 3002) ctrlSetText (format [localize "STR_A3_tu_arty_prep_shells_dialog_RscText_1002", floor (sliderPosition (_display displayCtrl 3900))]);
};

tu_arty_prep_start = {
	_display = uiNamespace getVariable ['TU_ARTY_PREP_display', displayNull];
	// _source, _qty, _classname_unprepped, _classname_prepped
	_source = uiNamespace getVariable "TU_ARTY_prep_source";
	_qty = floor (sliderPosition (_display displayCtrl 3900));
	_classname_unprepped = (_display displayCtrl 2100) lbData (lbCurSel (_display displayCtrl 2100));
	_classname_prepped = (_display displayCtrl 3101) lbData (lbCurSel (_display displayCtrl 3101));
	if (_classname_prepped == "") exitWith {hint "Не выбрана мина или заряд";}; 
	0 = [_source, _qty, _classname_unprepped, _classname_prepped] execVM "\tu_arty_config\scripts\prepare_shells.sqf";
	closeDialog 1;
};

