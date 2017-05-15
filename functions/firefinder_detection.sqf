if (isNil "tu_arty_garbage_markers") then {
	tu_arty_garbage_markers = []; 
	tu_arty_garbage_marker_time = [];
};
private _actualPos = _this select 0;
private _shellPos = _this select 1;
private _detector = _this select 2;
private _detector_type = getText (configFile >> "CfgVehicles" >>  typeOf _detector >> "tu_arty_radar_type");

private _error = getNumber (configFile >> "CfgVehicles" >>  typeOf _detector >> "tu_arty_radar_error");

if (_detector_type == "ARTILLERY") exitWith {
	[_actualPos,_shellPos,_detector,_detector_type,_error] spawn {
		private _actualPos = _this select 0;
		private _shellPos = _this select 1;
		private _detector = _this select 2;
		private _detector_type = _this select 3;
		private _error = _this select 4;
		if (!(isNil "TU_ARTY_FIREFINDER_DETECTION_DELAY")) then {	// возможность задать задержку срабатывание контрбатарейной РЛС
			sleep TU_ARTY_FIREFINDER_DETECTION_DELAY;
		};
		playSound3D ["A3\Sounds_F\arsenal\weapons\Launchers\Titan\locking_Titan.wss", _detector, false, getPosASL _detector, 1, 0.9, 10]; // todo: move to config
		// isInside, soundPosition, volume, soundPitch, distance]
		_approximateOriginPos = _actualPos vectorAdd [(random _error) - _error/2,(random _error) - _error/2,0];
		_markerstr = createMarkerLocal ["tu_arty_mrk_origin"+(str time),_approximateOriginPos];
		_markerstr setMarkerShapeLocal "ICON";
		_markerstr setMarkerTypeLocal "hd_destroy";
		_markerstr setMarkerColorLocal "ColorBlue";
		tu_arty_garbage_markers pushback _markerstr;
		tu_arty_garbage_marker_time pushback time;

		_markerstr = createMarkerLocal ["tu_arty_mrk_shell"+(str time), _shellPos];
		_markerstr setMarkerShapeLocal "ICON";
		_markerstr setMarkerTypeLocal "hd_arrow";
		_markerstr setMarkerColorLocal "ColorBlue";
		_markerstr setMarkerSizeLocal [0.5,0.5];
		_markerstr setMarkerDirLocal (_approximateOriginPos getDir _shellPos);
		tu_arty_garbage_markers pushback _markerstr;
		tu_arty_garbage_marker_time pushback time;

		if (count tu_arty_garbage_marker_time ==2) then {
			[] spawn {
				waitUntil {
					if ((count tu_arty_garbage_marker_time > 0) && {tu_arty_garbage_marker_time select 0 < (time - 60)}) then {
						deleteMarkerLocal (tu_arty_garbage_markers select 0);
						tu_arty_garbage_marker_time deleteAt 0;
						tu_arty_garbage_markers deleteAt 0;
					};
					count tu_arty_garbage_marker_time == 0
				};
			};
		};
	};
};

if (_detector_type == "LONG RANGE AIR") exitWith {
	playSound3D ["A3\Sounds_F\arsenal\weapons\Launchers\Titan\locking_Titan.wss", _detector, false, getPosASL _detector, 1, 1.1, 10];
	_approximateTargetPos = _shellPos vectorAdd [(random _error) - _error/2,(random _error) - _error/2,0];
	_markerstr = createMarkerLocal ["tu_arty_mrk_air"+(str time), _approximateTargetPos];
	_markerstr setMarkerShapeLocal "ICON";
	_markerstr setMarkerTypeLocal "hd_dot";
	_markerstr setMarkerColorLocal "ColorBlue";
	_markerstr setMarkerSizeLocal [0.5,0.5];
	_markerstr setMarkerDirLocal (_approximateOriginPos getDir _shellPos);
	tu_arty_garbage_markers pushback _markerstr;
	tu_arty_garbage_marker_time pushback time;

	if (count tu_arty_garbage_marker_time == 1) then {
		[] spawn {
			waitUntil {
				if (count tu_arty_garbage_marker_time > 0) then {
					if (tu_arty_garbage_marker_time select 0 < (time - 5.5)) then {
						deleteMarkerLocal (tu_arty_garbage_markers select 0);
						tu_arty_garbage_marker_time deleteAt 0;
						tu_arty_garbage_markers deleteAt 0;
					};
				};
				count tu_arty_garbage_marker_time == 0
			};
		};
	};
};

if (_detector_type == "SHORT RANGE AIR") exitWith {
	_approximateTargetPos = _shellPos vectorAdd [(random _error) - _error/2,(random _error) - _error/2,0];
	_markerstr = createMarkerLocal ["tu_arty_mrk_air"+(str time), _approximateTargetPos];
	_markerstr setMarkerShapeLocal "ICON";
	_markerstr setMarkerTypeLocal "hd_dot";
	_markerstr setMarkerColorLocal "ColorGreen";
	_mrkSize = 0.5;
	if (!isNil 'tu_arty_shilka_current_target') then {
		_mrkSize = (sizeOf (typeOf tu_arty_shilka_current_target))/(20*((vehicle player) distance tu_arty_shilka_current_target)/1000);
	};
	_markerstr setMarkerSizeLocal [0.5,0.5];
	_markerstr setMarkerAlphaLocal 0.7;
	_markerstr setMarkerDirLocal (_approximateOriginPos getDir _shellPos);
	tu_arty_garbage_markers pushback _markerstr;
	tu_arty_garbage_marker_time pushback time;
	if (isNil 'tu_arty_shilka_current_target') then {playSound3D ["A3\Sounds_F\arsenal\weapons\Launchers\Titan\locking_Titan.wss", _detector, false, getPosASL _detector, 1, 1.1, 10];};

	if (count tu_arty_garbage_markers == 1) then {
		[] spawn {
			waitUntil {
				for "_i" from ((count tu_arty_garbage_markers)-1) to 0 step -1 do {
					if (tu_arty_garbage_marker_time select _i < (time - 1)) then {
						deleteMarkerLocal (tu_arty_garbage_markers select _i);
						tu_arty_garbage_marker_time deleteAt _i;
						tu_arty_garbage_markers deleteAt _i;
					} else {
						(tu_arty_garbage_markers select _i) setMarkerAlphaLocal (1-(time - (tu_arty_garbage_marker_time select _i)));
					};
				};
				count tu_arty_garbage_marker_time == 0
			};
		};
	};
};