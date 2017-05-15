/*
* Воздушный разрыв миномётных мин.
*/
params ['_shell','_author'];
private _blast = createVehicle ["bn_60mm_proximity_burst", position _shell, [], 0, "NONE"]; 
[_author, "bn_60mm_proximity_burst", _blast] call ace_frag_fnc_addPfhRound;
deleteVehicle _shell;