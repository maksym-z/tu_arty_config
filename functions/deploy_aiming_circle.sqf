[20, [], {
	if (backpack player == "BN_Aiming_Circle_Bag") then {
		removeBackpack player;
		_aiming_circle = "bn_ace2_aiming_circle" createVehicle ((position player) vectorAdd (vectorDir player)); 
		_aiming_circle enableSimulation false; 
		_aiming_circle setVectorUp [0,0,1];
		_aiming_circle setPos ((position player) vectorAdd ((vectorDir player) vectorMultiply 2))
	} else {
		hint 'Куда девал буссоль?'
	}
}, {hint 'Действие отменено'}, 'Установка и ориентирование буссоли'] call ace_common_fnc_progressBar;