params ['_uav'];
bn_current_uav = _uav;
bn_uav_cam = "camera" camCreate (getPos _uav);
bn_uav_cam cameraEffect ["internal", "back","bnuavsight"];

["bn_uav_cam_pfh", "onEachFrame", tu_arty_fnc_position_camera] call BIS_fnc_addStackedEventHandler;
_layer = ["bn_uav_sight"] call BIS_fnc_rscLayer;
_layer cutRsc ["bn_uav_sight", "PLAIN", 0, false];
waitUntil {
	sleep 1;
	private _control = uavControl bn_current_uav;
	(_control select 0 != player) || (_control select 1 == "") || !(alive bn_current_uav) || !(alive player)
};
_layer cutRsc ["Default", "PLAIN"];
["bn_uav_cam_pfh", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
camDestroy bn_uav_cam;
bn_uav_cam = nil;