params ['_aiming_circle'];
[5, _aiming_circle, {
	if (!(isNull (_this select 0)) && {(_this select 0) distance player < 3}) then {
		if (backpack player == "") then {
			player addBackpack "BN_Aiming_Circle_Bag";
		} else {
			_aiming_circle_bag = "BN_Aiming_Circle_Bag" createVehicle (position player); 
			_aiming_circle_bag setPos (position player);
		};
		deleteVehicle (_this select 0);
	} else {
		hint 'Куда девал буссоль?'
	}
}, {hint 'Действие отменено'}, 'Складываю буссоль'] call ace_common_fnc_progressBar;