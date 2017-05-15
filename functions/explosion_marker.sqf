if (!isDedicated && (isNil "tu_arty_debug_mode")) exitWith {};
_coordX = _this select 0;
_coordY = _this select 1;
_type = _this select 2;
_color = "ColorBlack";
if (count _this>3) then {
	_color = _this select 3;
};

_iconSize = getNumber (configFile >> "CfgAmmo" >> _type >> "tu_arty_explosion_marker_size");
_alpha = getNumber (configFile >> "CfgAmmo" >> _type >> "tu_arty_explosion_marker_alpha");

if (_iconSize==0) then {_iconSize=1};
if (_alpha==0) then {_alpha=1};

_newmarker = createMarkerLocal ["mrkExplosion"+str(time), [_coordX, _coordY]];
_newmarker setMarkerShapeLocal "icon";
_newmarker setMarkerSizeLocal[0.5*_iconSize, 0.5*_iconSize];
_newmarker setMarkerTypeLocal "tu_arty_explosion";
_newmarker setMarkerColorLocal _color;
_newmarker setMarkerAlphaLocal _alpha;

tu_log_update_markers pushBack _newmarker;