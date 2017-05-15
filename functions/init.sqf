tu_arty_dials_handle = 0 spawn {};
enableEngineArtillery false;

// quick and dirty copy of ACE3 range table - will become obsolete with further versions of ACE3 
// no plagiarism intended, I just need this to work

tu_arty_fnc_open_table = {
	#define LIST_CHARGE ((uiNamespace getVariable "ACE_82mm_RangeTable_Dialog") displayCtrl 1501)

	private ["_weaponName", "_magazines", "_initSpeed", "_fireModes", "_muzzleVelocities", "_showToPlayer", "_artilleryCharge", "_mag"];

	_weaponName = _this select 0; 

	createDialog "ACE_82mm_RangeTable_Dialog";
	if (isNull (uiNamespace getVariable ["ACE_82mm_RangeTable_Dialog", displayNull])) exitWith {hint("Dialog failed to open");};

	//Get Magazine Types
	_magazines = getArray (configFile >> "CfgWeapons" >> _weaponName >> "magazines");

	//For now just get settings from first mag, all rounds have same flight characteristics:
	if ((count _magazines) < 1) exitWith {hint("No Magazines for weapon" + _weaponName);};
	_initSpeed = getNumber (configFile >> "CfgMagazines" >> (_magazines select 0) >> "initSpeed");

	//Get Charge Modes
	_fireModes = getArray (configFile >> "CfgWeapons" >> _weaponName >> "modes");

	_muzzleVelocities = [];
	
	{
	_mag = _x;
		_initSpeed = getNumber (configFile >> "CfgMagazines" >> _mag >> "initSpeed");
		if (!(_initSpeed in _muzzleVelocities)) then {
			_chargeName = getText (configFile >> "CfgMagazines" >> _mag >> "tu_arty_chargeName");
			if (({getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "showToPlayer") == 1} count _fireModes)>1) then {
				{
					_chargeName = getText (configFile >> "CfgMagazines" >> _mag >> "tu_arty_chargeName") + "/" + str(_x);
					_artilleryCharge = getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "artilleryCharge");
					LIST_CHARGE lbAdd format ["%1: %2", _chargeName, (count _muzzleVelocities)];
					LIST_CHARGE lbSetData [(count _muzzleVelocities), str (_artilleryCharge*_initSpeed)];
					_muzzleVelocities pushBack _initSpeed;
				} forEach _fireModes;
			} else {
				LIST_CHARGE lbAdd format ["%1", _chargeName];
				LIST_CHARGE lbSetData [(count _muzzleVelocities), str (_initSpeed)];
				_muzzleVelocities pushBack _initSpeed;
			};
		};
	} forEach _magazines;
	/*
	
	_muzzleVelocities = [];
	{
		_mag = _x;
		_initSpeed = getNumber (configFile >> "CfgMagazines" >> _mag >> "initSpeed");
		if (!(_initSpeed in _muzzleVelocities)) then {
			_chargeName = getText (configFile >> "CfgMagazines" >> _mag >> "tu_arty_chargeName");
			LIST_CHARGE lbAdd format ["%1: %2", _chargeName, (count _muzzleVelocities)];
			LIST_CHARGE lbSetData [(count _muzzleVelocities), str (_initSpeed)];
			_muzzleVelocities pushBack _initSpeed;
		};
	} forEach _magazines;*/

	LIST_CHARGE lbSetCurSel 0;
};

/*ace_mk6mortar_fnc_rangeTablePreCalculatedValues = nil;

ace_mk6mortar_fnc_rangeTablePreCalculatedValues = compileFinal preprocessFileLineNumbers "\tu_arty\functions\range_table_values.sqf";*/


tu_arty_fnc_page_change = {
	#define RANGE_TABLE       ((uiNamespace getVariable "ACE_82mm_RangeTable_Dialog") displayCtrl 20001)
	#define LIST_CHARGE       ((uiNamespace getVariable "ACE_82mm_RangeTable_Dialog") displayCtrl 1501)

	private ["_listBoxData", "_muzzleVelocity", "_airFriction", "_precalcArray"];

	_listBoxData = LIST_CHARGE lbData (lbCurSel LIST_CHARGE);
	if (isNil "_listBoxData" || {_listBoxData == ""}) exitWith {hint "lbCurSel out of bounds or no data"};
	_muzzleVelocity = parseNumber _listBoxData;

	_airFriction = -0.00015;

	_precalcArray = [_muzzleVelocity, _airFriction] call tu_arty_fnc_rangeTablePreCalculatedValues;

	lnbClear RANGE_TABLE;
	{
		RANGE_TABLE lnbAddRow _x;
	} forEach _precalcArray;

	//put dummy line at end because scrolling is fucked and can't see last line - прим. авт.
	RANGE_TABLE lnbAddRow ["", "", "", "", "", "", "", "", "", "", ""];
};