private ["_radar_pos","_radar","_half_detection_distance","_detection_angle","_beta"];
_radar = (vehicle player);
tu_arty_exit_radar = false;
_half_detection_distance = (getNumber (configFile >> "CfgVehicles" >> typeOf (vehicle player) >> "tu_arty_radar_detection_range")) / 2;
_detection_angle = getNumber (configFile >> "CfgVehicles" >>  typeOf (vehicle player) >> "tu_arty_radar_detection_angle");
/*_cx = (getPos vehicle player) select 0;
_cy = (getPos vehicle player) select 1;
_beta = (vehicle player) getVariable ["tu_arty_fnc_firefinder_angle",0];
_xR = _cx + (sin (_beta+_detection_angle/2)) * _half_detection_distance;
	_yR = _cy + (cos (_beta+_detection_angle/2)) * _half_detection_distance;
	_xL = _cx + (sin (_beta-_detection_angle/2)) * _half_detection_distance;
	_yL = _cy + (cos (_beta-_detection_angle/2)) * _half_detection_distance;;*/
_mrkLeft = createMarkerLocal ["tu_arty_mrk_left", position player];
_mrkLeft setMarkerColorLocal "ColorGreen";
_mrkLeft setMarkerShapeLocal "RECTANGLE";
_mrkLeft setMarkerAlphaLocal 0.9;

_mrkRight = createMarkerLocal ["tu_arty_mrk_right", position player];
_mrkRight setMarkerColorLocal "ColorGreen";
_mrkRight setMarkerShapeLocal "RECTANGLE";
_mrkRight setMarkerAlphaLocal 0.9;
"tu_arty_mrk_left" setMarkerSizeLocal [10,_half_detection_distance];
"tu_arty_mrk_right" setMarkerSizeLocal [10,_half_detection_distance];
/*_mrkRight setMarkerDirLocal (_beta+_detection_angle/2);
_mrkLeft setMarkerDirLocal (_beta-_detection_angle/2);
*/

waitUntil {
	_radar_pos = _radar call compile (getText (configFile >> "CfgVehicles" >>  typeOf _radar >> "tu_arty_radar_pos"));
	_cx = _radar_pos select 0;
	if (_cx <= 0) exitWith {true};
	_cy = _radar_pos select 1;
	_beta = _radar call compile (getText (configFile >> "CfgVehicles" >>  typeOf _radar >> "tu_arty_radar_alpha"));
	_xR = _cx + (sin (_beta+_detection_angle/2)) * _half_detection_distance;
	_yR = _cy + (cos (_beta+_detection_angle/2)) * _half_detection_distance;
	_xL = _cx + (sin (_beta-_detection_angle/2)) * _half_detection_distance;
	_yL = _cy + (cos (_beta-_detection_angle/2)) * _half_detection_distance;
	"tu_arty_mrk_left" setMarkerPosLocal [_xL,_yL];
	"tu_arty_mrk_left" setMarkerDirLocal (_beta-_detection_angle/2);
	"tu_arty_mrk_right" setMarkerPosLocal [_xR,_yR];
	"tu_arty_mrk_right" setMarkerDirLocal (_beta+_detection_angle/2);
	!(alive player) || ((vehicle player) != _radar) || tu_arty_exit_radar
};

 deleteMarkerLocal 'tu_arty_mrk_left'; 
 deleteMarkerLocal 'tu_arty_mrk_right';