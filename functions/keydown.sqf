if ((_this select 1) == 200) exitWith {[0,1,2,3,_this select 2,_this select 3,6,-1] call tu_arty_fnc_elevate;};
if ((_this select 1) == 208) exitWith {[0,1,2,3,_this select 2,_this select 3,6,1] call tu_arty_fnc_elevate};
if ((_this select 1) == 209) exitWith {[0,1,2,3,_this select 2,_this select 3,6,1] call tu_arty_fnc_el_dial_change};
if ((_this select 1) == 201) exitWith {[0,1,2,3,_this select 2,_this select 3,6,-1] call tu_arty_fnc_el_dial_change};
if ((_this select 1) == 203) exitWith {[0,1,2,3,_this select 2,_this select 3,6,-1] call tu_arty_fnc_traverse};
if ((_this select 1) == 205) exitWith {[0,1,2,3,_this select 2,_this select 3,6,1] call tu_arty_fnc_traverse};
if ((_this select 1) == 45) exitWith {[0,1,2,3,_this select 2,_this select 3,6,-1] call tu_arty_fnc_def_change};
if ((_this select 1) == 44) exitWith {[0,1,2,3,_this select 2,_this select 3,6,1] call tu_arty_fnc_def_change};

// 0, 1, 2, 3, and 6 are placeholders