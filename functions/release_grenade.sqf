params ["_uav","_action_id"];
if (isNull (_uav getVariable ["bn_attached_grenade_object",objNull])) exitWith {};
private _grenade = _uav getVariable "bn_attached_grenade_object";
private _grenade_ammo_classname = _uav getVariable ["bn_attached_grenade_ammo", ""];
{detach _x} forEach (attachedObjects _uav);
deleteVehicle _grenade;
_grenade = _grenade_ammo_classname createVehicle ((getPos _uav) vectorAdd [0,0,-0.2]);
_grenade setVelocity ((velocity _uav) vectorAdd [0,0,-3]);
_uav removeAction _action_id;