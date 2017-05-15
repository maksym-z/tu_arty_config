// diag_log "remove event handler";
// diag_log _this;

if (!(local (_this select 2))) exitWith {};
(findDisplay 46) displayRemoveEventHandler ["KeyDown", (_this select 0) getVariable "tu_arty_gunner_handle"];
(_this select 0) setVariable ["tu_arty_elevation_dial", (_this select 0) getVariable "tu_arty_elevation_dial", true]; // mp synch
(_this select 2) setDir ((getDir (_this select 2)) + (random 20)-10);