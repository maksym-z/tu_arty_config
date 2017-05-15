/*
* Функция добавляет снаряд или иную цель в список. Список нужен для:
* 1) обнаружения снарядов РЛС контрбатарейной борьбы, обнаружения других целей другими РЛС
* 2) отображения точек попадания на реплее
* 3) since Apr 19, 2017: воздушного разрыва мин
* 
* Скрипт просматривает 1 элемент списка за кадр, т.е. при большом количестве объектов может снизиться качество работы вышеуказанных игровых средств, но не производительность сервера.
* Вхолостую (при пустом списке) процессорное время не жрёт.
*
* [ODK]Bn_
*/
_shell = _this select 0;
if (isNil 'tu_arty_observable_list' || {(count tu_arty_observable_list == 0) && !(_shell in tu_arty_observable_list)}) then {
	tu_arty_observable_list = [_shell];
	tu_arty_observable_positions = [getPos _shell]; 
	tu_arty_observable_authors = [(getShotParents _shell) select 0]; // нью энд эксайтинг скрипт комменд синс 1.62
	tu_arty_observable_types = [typeOf _shell];
	tu_arty_observable_origins = [getPos _shell];
	tu_arty_observable_detection_time = [-1];
	tu_arty_observable_counter = 0;
	tu_arty_observable_tracked_by = [[]];
	
	["tu_arty_monitor", "onEachFrame", {
		for "_i" from (count tu_arty_observable_list) to 0 step -1 do { // нумерация вагонов с хвоста поезда для эффективного удаления из массива
			_shell = tu_arty_observable_list select _i;
			if (!(isNull _shell) && {alive _shell} && {(getPos _shell select 0)>1}) then {
				// n секунд, полёт нормальный 
				tu_arty_observable_positions set [_i,getPos _shell];
			} else {
				// impact
				_place = (tu_arty_observable_positions select _i);
				private _color = (tu_arty_observable_authors select _i) getVariable ["tu_arty_explosion_marker_color", "ColorBlack"];
				[_place select 0, _place select 1, tu_arty_observable_types select _i, _color] remoteExec ["tu_arty_fnc_explosion_marker", 2, false];
				tu_arty_observable_list deleteAt _i; // спасибо товарищам бисам за нормальное удаление из массива
				tu_arty_observable_positions deleteAt _i; 
				tu_arty_observable_types deleteAt _i;
				tu_arty_observable_origins deleteAt _i;
				tu_arty_observable_detection_time deleteAt _i; 
				tu_arty_observable_tracked_by deleteAt _i;
				tu_arty_observable_authors deleteAt _i;
			};
			if (((typeOf _shell) == "bn_60mm_frag_prx") && {((velocity _shell) select 2) < -1} && {(getPosATL _shell select 2) < 5}) then { // TODO: бить себя по рукам за хардкод класснеймов в скриптах
				[_shell, tu_arty_observable_authors select _i] call tu_arty_fnc_proximity_burst;
			};
		};
		if (count tu_arty_observable_list == 0) exitWith {
			["tu_arty_monitor", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
		};
		
		if (!(isNil 'tu_arty_subscribers') && {count tu_arty_subscribers > 0}) then { // Наши подписчики - РЛС контрбатарейной борьбы (Upd: и не только)
			if (tu_arty_observable_counter <0) then { // track 1 round per frame to avoid performance deterioration
				tu_arty_observable_counter = (count tu_arty_observable_list) - 1;
			};
			if ((tu_arty_observable_detection_time select tu_arty_observable_counter) == -2) exitWith {tu_arty_observable_counter = tu_arty_observable_counter - 1;}; // shell already detected
			{
				_current_shell = tu_arty_observable_list select tu_arty_observable_counter;
				_detector = _x;
				_tracking_time_required = getNumber (configFile >> "CfgVehicles" >> typeOf _detector >> "tu_radar_tracking_time_required");
				_show_once = getNumber (configFile >> "CfgVehicles" >> typeOf _detector >> "tu_radar_show_once");
				if ((tu_arty_observable_detection_time select tu_arty_observable_counter) == -1) then {
					if ([_current_shell, _detector] call tu_arty_fnc_is_shell_detected) then {

						tu_arty_observable_detection_time set [tu_arty_observable_counter, time];
						(tu_arty_observable_tracked_by select tu_arty_observable_counter) pushBackUnique _detector;
						if (_tracking_time_required == 0) then { // todo: eliminate repetition
							{
								[tu_arty_observable_origins select tu_arty_observable_counter, getPos _current_shell,_detector] remoteExecCall ["tu_arty_fnc_firefinder_detection",_x,false];
							} forEach (crew _detector);
							tu_arty_observable_detection_time set [tu_arty_observable_counter, -1];
						};
					};
				} else {
					if (_detector in (tu_arty_observable_tracked_by select tu_arty_observable_counter)) then {

						if ((time - (tu_arty_observable_detection_time select tu_arty_observable_counter)) >= _tracking_time_required) then {
							if ([tu_arty_observable_list select tu_arty_observable_counter, _detector] call tu_arty_fnc_is_shell_detected) then {

								{
									[tu_arty_observable_origins select tu_arty_observable_counter, getPos _current_shell,_detector] remoteExecCall ["tu_arty_fnc_firefinder_detection",_x,false];
								} forEach (crew _detector);
//								playSound3D ["A3\Sounds_F\arsenal\weapons\Launchers\Titan\locking_Titan.wss", _detector]; // todo: move to config
								if (_show_once == 1) then {

									tu_arty_observable_detection_time set [tu_arty_observable_counter, -2];
								} else {

									tu_arty_observable_detection_time set [tu_arty_observable_counter, time];
								};
							} else {
								tu_arty_observable_detection_time set [tu_arty_observable_counter, -1];
								(tu_arty_observable_tracked_by select tu_arty_observable_counter) deleteAt ((tu_arty_observable_tracked_by select tu_arty_observable_counter) find _detector);
							};
						};
					};
				};
				
			} forEach tu_arty_subscribers;
			tu_arty_observable_counter = tu_arty_observable_counter - 1;
		};
		
	}] call BIS_fnc_addStackedEventHandler;
} else {
	if (!(_shell in tu_arty_observable_list)) then {
		tu_arty_observable_list pushback _shell;
		tu_arty_observable_positions pushback (getPos _shell); 
		tu_arty_observable_types pushback (typeOf _shell);
		tu_arty_observable_origins pushback (getPos _shell);
		tu_arty_observable_detection_time pushback (-1);
		tu_arty_observable_tracked_by pushback [];
		tu_arty_observable_authors pushback ((getShotParents _shell) select 0);
	};
};

