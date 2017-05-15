disableSerialization;
private ["_unit","_anims","_def", "_val_left", "_val_right", "_display","_el","_delta_el", "_el_dial", "_milSys", "_isDone","_digits"];
_unit = _this select 0;
_anims = ["OpticRevolve","OpticElevate"];
_milSys = getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "bn_arty_milSys");
if (_milSys == 0) then {_milSys = 6000};
_display = uiNamespace getVariable ["TU_ARTY_Display", displayNull];
if ((isNull _display) || (_unit != (vehicle player))) exitWith {};

waitUntil {
//	hint "Dials dialing";
	_isDone = ({(_unit animationPhase _x) - (_unit getVariable [_x, _unit animationPhase _x]) < 0.5} count _anims) == count _anims;

	_def = (_unit animationPhase "OpticRevolve");// * _milSys/6400;
	// US mils to Russian mils
	_def = round (_def + _milSys/2) % _milSys;
	if (_def<0) then {_def=_def+_milSys};
	
//	diag_log _def;
	
	// bubble level
	_el = floor ((asin ((_unit weaponDirection (weapons _unit select 0)) select 2)) / 360 * _milSys); // прицел фактический, игроку неизвестен
	_el_dial = (_unit getVariable ["tu_arty_elevation_dial",1000]); // прицел, установленный на барабанчике/ручке
	_delta_el = _el_dial - _el; // отклонение продольного уровня фактическое
	if (_milSys == 6400) then {
		_digits = [_el_dial, 4] call ACE_common_fnc_numberToDigits;
	} else {
		_digits = [1000-(_el_dial-_milSys/8), 4] call ACE_common_fnc_numberToDigits; // прицел 10-00 соответствует возвышению ствола 45 градусов - rtfm
	};
	_val_left = str (_digits select 0) + str (_digits select 1);
	_val_right = str (_digits select 2) + str (_digits select 3);
	(_display displayCtrl 1002) ctrlSetText _val_left;
	(_display displayCtrl 1003) ctrlSetText _val_right;
	
	(_display displayCtrl 1900) sliderSetRange [-20, 20];
	
	//if (abs _delta_el >= 20) then {
	(_display displayCtrl 1900) sliderSetPosition _delta_el; //} else {(_display displayCtrl 1900) sliderSetPosition ((_delta_el * 2) min 20) max -20;};
		
	// deflection	dial
	_digits = [_def, 4] call ACE_common_fnc_numberToDigits;
	_val_left = str (_digits select 0) + str (_digits select 1);
	_val_right = str (_digits select 2) + str (_digits select 3);
	(_display displayCtrl 1001) ctrlSetText _val_left;
	(_display displayCtrl 1000) ctrlSetText _val_right;
	
//	hint str (["Dials still dialing",_def, _delta_el]);
	sleep 0.05;	
	!dialog;
};
// hint str (["Dials done",_def, _delta_el]);