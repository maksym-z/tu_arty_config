private ["_object","_pos","_truck"];
//TU_ARTY_TOWING_TRUCK_CLASSES = ["rhs_gaz66_vmf"];
_object = _this select 0;
//_truck = nearestObjects [_object, TU_ARTY_TOWING_TRUCK_CLASSES, 10] select 0;
_truck = attachedTo _object;
if (!(isNull _truck) && {_truck getVariable ["tu_arty_tow_busy", false]}) then {
	_position = ((getPos _object) vectorAdd ((vectorNormalized (vectorDir _truck)) vectorMultiply -0.5));
	_truck setVariable ["tu_arty_tow_busy", false, true];
	_object lock false;
	detach _object;
	
	_object setPosATL [_position select 0, _position select 1, 0];
	
} else {
	hint "Не прицеплено";
}