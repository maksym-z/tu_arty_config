// [shell, detector]
_shell = _this select 0;
_detector = _this select 1;
_detection_distance = getNumber (configFile >> "CfgVehicles" >> typeOf _detector >> "tu_arty_radar_detection_range");
_detection_angle = getNumber (configFile >> "CfgVehicles" >>  typeOf _detector >> "tu_arty_radar_detection_angle");
_radar_pos = _detector call compile (getText (configFile >> "CfgVehicles" >>  typeOf _detector >> "tu_arty_radar_pos"));
_radar_alpha = _detector call compile (getText (configFile >> "CfgVehicles" >>  typeOf _detector >> "tu_arty_radar_alpha"));
_detectable = _shell call compile (getText (configFile >> "CfgVehicles" >>  typeOf _detector >> "tu_arty_detectable"));
if (!_detectable) exitWith {false};
if ((_shell distance _detector) > _detection_distance) exitWith {false};
if (abs((((_detector getDir _shell) - _radar_alpha + 180) mod 360) - 180) > _detection_angle/2) exitWith {false};
//hint (str [_shell,_detector, [_detector, "FIRE"] checkVisibility [(ATLtoASL _radar_pos) vectorAdd [0,0,1], (getPosASL _shell)],abs((((_detector getDir _shell) - _radar_alpha + 180) mod 360) - 180),_radar_alpha]);

[_detector, "FIRE"] checkVisibility [(ATLtoASL _radar_pos) vectorAdd [0,0,1], (getPosASL _shell)] > 0