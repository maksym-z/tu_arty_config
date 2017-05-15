private _side_color = "ColorBlack";
if (player getVariable ["tu_arty_explosion_marker_color", ""] == "") then {
	switch (side player) do {
		case west: {_side_color = "colorBLUFOR"};
		case east: {_side_color = "colorOPFOR"};
		case civilian: {_side_color = "colorCivilian"};
		case resistance: {_side_color = "colorIndependent"};
	};
} else {
	_side_color = player getVariable ["tu_arty_explosion_marker_color", "ColorBlack"];
};
vehicle player setVariable ["tu_arty_explosion_marker_color", _side_color, true];