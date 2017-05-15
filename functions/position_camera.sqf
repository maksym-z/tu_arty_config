params ["_layer"];
bn_uav_cam camSetTarget [getPos bn_current_uav select 0, getPos bn_current_uav select 1, 0] vectorDiff (vectorDir bn_current_uav);
bn_uav_cam camSetPos (bn_current_uav modelToWorld [0, -1, -0.5]);
bn_uav_cam camPrepareFOV 0.4;
bn_uav_cam camCommitPrepared 0;