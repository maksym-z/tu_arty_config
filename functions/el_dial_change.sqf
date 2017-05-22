private ["_phase", "_newPhase", "_gun","_mult","_dir","_milSys"];
_gun = vehicle player;

_dir = _this select 7;	// +1/-1
_milSys = getNumber (configFile >> "CfgVehicles" >> typeOf _gun >> "initSpeed");
if (_milSys == 0) then {_milSys = 6000};
if (_milSys == 6400) then {_dir = _dir * -1};
_mult = 1; // 6400 / _milSys;	
// US mils to Russian mils, if necessary

if (_this select 4) then {_mult=_mult*5};	// shift
if (_this select 5) then {_mult=_mult*10};	// ctrl

// hint str (_this);

//  возвышение прицела
_phase = _gun animationPhase "OpticElevate";
_newPhase = (round(_phase+_dir*_mult) min _milSys/4) max _milSys/8;
_gun animate ["OpticElevate", _newPhase];
_gun setVariable ["OpticElevate",_newPhase];


//_phase = _gun getVariable ["tu_arty_elevation_dial",0];  //анимация OpticElevate не успевает за скриптом
_newPhase = (round(_phase+_dir*_mult) min _milSys/4) max _milSys/8;
_gun setVariable ["tu_arty_elevation_dial",_newPhase];


if (scriptDone tu_arty_dials_handle) then {tu_arty_dials_handle = [vehicle player] execVM "\tu_arty_config\scripts\dials.sqf"};