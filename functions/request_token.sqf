params ["_token_name","_requestor","_gun"];
/*if (isNull (_gun getVariable [_token_name, objNull])) then {
	_gun setVariable [_token_name, objNull, false];
	_gun setVariable [_token_name + "_time", time, false];
};*/
if ((isNull (_gun getVariable [_token_name, objNull])) || (((_gun getVariable [_token_name + "_time", 0]) + 60) < time)) then {
	// token granted
	diag_log "tu_arty: token granted";
	_gun setVariable [_token_name, _requestor, false];
	_gun setVariable [_token_name + "_time", time, false];
	missionNamespace setVariable [_token_name + "_received", 1, false];
	(owner _requestor) publicVariableClient (_token_name + "_received"); 
} else {
	// token denied
	diag_log "tu_arty: token denied, current holder / since:";
	diag_log [_gun getVariable [_token_name, objNull], _gun getVariable [_token_name + "_time", 0]];
	missionNamespace setVariable [_token_name + "_received", -1, false];
	(owner _requestor) publicVariableClient (_token_name + "_received"); 
};