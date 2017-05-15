private ["_object","_truck", "_z"];
_object = _this select 0;
TU_ARTY_TOWING_TRUCK_CLASSES = ["rhs_gaz66_vmf","RHS_Ural_Base","CUP_HMMWV_Base"];
_truck = nearestObjects [_object, TU_ARTY_TOWING_TRUCK_CLASSES, 15] select 0;
private _barrel_offset = [0,3.4,-1];
private _truck_offset = [0,-2.7,0.3];
private _offset_array = getArray (configFile >> "CfgVehicles" >> typeOf _truck >> "tu_arty_gun_attachment_point");
private _rotation_array = getArray (configFile >> "CfgVehicles" >> typeOf _truck >> "tu_arty_gun_rotation");
if (count _offset_array > 0) then {
	_truck_offset = _offset_array;
};
if (count _this > 1) then {
	_truck = _this select 1;
};
if (count _this > 2) then {
	_truck_offset = _this select 2;
};
private _attach_position = _truck modelToWorld _truck_offset;
private _barrel_position = _object modelToWorld _barrel_offset;
if (_truck getVariable ["tu_arty_tow_busy", false]) exitWith {hint "Занято"};
if (_attach_position distance _barrel_position < 2) then {
	{_x action["Eject", _object];} forEach (crew _object);
	_z=0;
	_object attachTo [_truck, [_truck_offset select 0,0 - (abs(_truck_offset select 1) + abs(_barrel_offset select 1)),_truck_offset select 2]];
	_object enableSimulation true;
	_object setDir 0;
	_object lock true;
	_truck setVariable ["tu_arty_tow_busy", true, true];
	if (count _rotation_array > 0) then {
		_object setVectorUp _rotation_array;
	};
} else {
	hint ("Тягач (" + (getText (configFile >> "CfgVehicles" >> typeOf _truck >> "displayName")) + ") слишком далеко");
};