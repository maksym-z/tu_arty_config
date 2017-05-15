private _gun = _this select 0;
private _range = _this select 1;
allUnits select { // todo: заменить на playableUnits после тестирования
	((_x distance (getPos _gun)) < _range) && (alive _x) && {vectorMagnitude (velocity _x) < 3}
}