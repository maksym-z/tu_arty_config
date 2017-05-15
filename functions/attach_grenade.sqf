params ["_grenade_mag_classname","_uav"];
private _grenade_ammo_classname = getText (configFile >> "CfgMagazines" >> _grenade_mag_classname >> "ammo");
private _model_name = ((getText (configFile >> "CfgAmmo" >> _grenade_ammo_classname >> "model")) select [1]) + ".p3d";
private _grenade = createSimpleObject [_model_name, getPos _uav]; //"rhsusf\addons\rhsusf_weapons\grenades_thrown\m67\m67_frag.p3d"
player removeMagazine _grenade_mag_classname;
_grenade attachTo [_uav, [0,0,-0.1]];
_uav setVariable ["bn_attached_grenade_object", _grenade, true];
_uav setVariable ["bn_attached_grenade_ammo", _grenade_ammo_classname, true];
private _action_id = _uav addAction ["Сбросить гранату",{[getConnectedUAV player, _this select 2] call tu_arty_fnc_release_grenade}];
_uav addEventHandler ["Killed",compile ("(_this select 0) removeAction " + (str _action_id) + ";")];