#define LIST_CHARGE ((uiNamespace getVariable "ACE_82mm_RangeTable_Dialog") displayCtrl 1501)

private ["_weaponName", "_magazines", "_initSpeed", "_fireModes", "_muzzleVelocities", "_showToPlayer", "_artilleryCharge", "_mag"];

_weaponName = _this select 0; //todo: work on other weapons

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
				_chargeName = _chargeName + "/" + str(_x);
				_artilleryCharge = getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "artilleryCharge");
				LIST_CHARGE lbAdd format ["%1: %2", _chargeName, (count _muzzleVelocities)];
				LIST_CHARGE lbSetData [(count _muzzleVelocities), str (_artilleryCharge*_initSpeed)];
				_muzzleVelocities pushBack _initSpeed;
			} forEach _fireModes;
		} else {
			LIST_CHARGE lbAdd format ["%1: %2", _chargeName, (count _muzzleVelocities)];
			LIST_CHARGE lbSetData [(count _muzzleVelocities), str (_initSpeed)];
			_muzzleVelocities pushBack _initSpeed;
		};
	};
} forEach _magazines;

LIST_CHARGE lbSetCurSel 0;