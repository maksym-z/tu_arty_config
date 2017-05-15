if (isNil "tu_arty_subscribers" || {count tu_arty_subscribers == 0}) then {
	tu_arty_subscribers = [_this select 0];
} else {
	if (!((_this select 0) in tu_arty_subscribers)) then {
		tu_arty_subscribers pushBack (_this select 0);
	};
};