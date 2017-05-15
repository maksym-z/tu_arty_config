	player setPosATL [getPosATL player select 0, getPosATL player select 1, (getPosATL player select 2)+0.27];
	detach player;
	player playMoveNow "crouch";
	player switchMove "";
//	player removeAction (_this select 1);

	(findDisplay 46) displayRemoveEventHandler ["KeyDown", (player getVariable "tu_arty_dragged_gun") getVariable "bn_drag_handle"];
	((_this select 0) select 0) setVariable ["bn_drag_handle", "", true]; // вложенный массив передаёт эйс, нахрена - не знаю
	player setVariable ["tu_arty_dragged_gun", objNull];
	player setVariable ["tu_arty_busy",false];
