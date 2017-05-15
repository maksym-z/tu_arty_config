// УДАЛИТЬ ПОТОМ
_trackable = _this select 0;
_origin = _this select 1;
_detector_type = "tu_arty_firefinder";
if (count _this > 2) then {
	_detector_type = _this select 2;
};

if (isNil 'tu_arty_trackable_list' || {count tu_arty_trackable_list == 0}) then {
	tu_arty_trackable_list = [_trackable];
	tu_arty_trackable_positions = [getPos _trackable]; 
	tu_arty_trackable_origins = [_origin];
	tu_arty_trackable_detector_types = [_detector_type];
	tu_arty_trackable_detection_time = [-1];
	tu_arty_trackable_counter = 0;
	if (isNil 'tu_arty_garbage_markers') then {
		tu_arty_garbage_markers=[];
		tu_arty_garbage_marker_time=[];
	};
	["tu_arty_firefinder", "onEachFrame", {
		if (count tu_arty_trackable_list == 0) exitWith {
			["tu_arty_firefinder", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
		};
		if (((vehicle player) getVariable ["tu_arty_firefinder",0]) == 0) exitWith {};
		if (tu_arty_trackable_counter <0) then { // track 1 round per frame to avoid performance deterioration
			tu_arty_trackable_counter = (count tu_arty_trackable_list) - 1;
		};
		_trackable = tu_arty_trackable_list select tu_arty_trackable_counter;
		if (!(isNull _trackable) && {alive _trackable} && {(getPos _trackable select 0)>1}) then {
			tu_arty_trackable_positions set [tu_arty_trackable_counter,getPos _trackable];
			if ((tu_arty_trackable_detection_time select tu_arty_trackable_counter) == -1) then {
				if ([tu_arty_trackable_list select tu_arty_trackable_counter] call tu_arty_fnc_is_shell_detected) then {
					tu_arty_trackable_detection_time set [tu_arty_trackable_counter, time];
				};
			} else {
				if ((time - (tu_arty_trackable_detection_time select tu_arty_trackable_counter)) > 5) then {
					if ([tu_arty_trackable_list select tu_arty_trackable_counter] call tu_arty_fnc_is_shell_detected) then {
						_actualPos = tu_arty_trackable_origins select tu_arty_trackable_counter;
						_approximatePos = _actualPos vectorAdd [(random 200) - 100,(random 200) - 100,0];
						_markerstr = createMarkerLocal ["tu_arty_mrk_origin"+(str time),_approximatePos];
						_markerstr setMarkerShapeLocal "ICON";
						_markerstr setMarkerTypeLocal "hd_destroy";
						_markerstr setMarkerColorLocal "ColorBlue";
						tu_arty_garbage_markers pushback _markerstr;
						tu_arty_garbage_marker_time pushback time;
						
						_markerstr = createMarkerLocal ["tu_arty_mrk_trackable"+(str time),tu_arty_trackable_positions select tu_arty_trackable_counter];
						_markerstr setMarkerShapeLocal "ICON";
						_markerstr setMarkerTypeLocal "hd_arrow";
						_markerstr setMarkerColorLocal "ColorBlue";
						_markerstr setMarkerDirLocal (_approximatePos getDir (tu_arty_trackable_positions select tu_arty_trackable_counter));
						tu_arty_garbage_markers pushback _markerstr;
						tu_arty_garbage_marker_time pushback time;
						tu_arty_trackable_list deleteAt tu_arty_trackable_counter;
						tu_arty_trackable_positions deleteAt tu_arty_trackable_counter;
						tu_arty_trackable_origins deleteAt tu_arty_trackable_counter;
						tu_arty_trackable_detection_time deleteAt tu_arty_trackable_counter;
						tu_arty_trackable_detector_types deleteAt tu_arty_trackable_counter;
						
						playSound3D ["A3\Sounds_F\sfx\alarm_independent.wss", vehicle player];

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
			};
		} else {
//			_place = (tu_arty_trackable_positions select tu_arty_trackable_counter);
//			[_place select 0, _place select 1, tu_arty_trackable_types select tu_arty_trackable_counter] remoteExec ["tu_arty_fnc_explosion_marker", 2, false];
			tu_arty_trackable_list deleteAt tu_arty_trackable_counter;
			tu_arty_trackable_positions deleteAt tu_arty_trackable_counter;
			tu_arty_trackable_origins deleteAt tu_arty_trackable_counter;
			tu_arty_trackable_detection_time deleteAt tu_arty_trackable_counter;
			tu_arty_trackable_detector_types deleteAt tu_arty_trackable_counter;
		};
		tu_arty_trackable_counter = tu_arty_trackable_counter - 1;
		
		//garbage collection, one marker per frame
	}] call BIS_fnc_addStackedEventHandler;
} else {
	if (_trackable in tu_arty_trackable_list) exitWith {};
	tu_arty_trackable_list pushback _trackable;
	tu_arty_trackable_positions pushback (getPos _trackable); 
	tu_arty_trackable_origins pushback _origin;
	tu_arty_trackable_detection_time pushback (-1);
	tu_arty_trackable_counter = (count tu_arty_trackable_list) - 1;
	tu_arty_trackable_detector_types pushback _detector_type;
};