private ['_aiming_circle'];
_aiming_circle = _this select 0;
player attachTo [_aiming_circle, [0.15,-0.5,0], "pos_gunner"];
player setVectorDir [0,-1,0]; 
player playMove "AinvPercMstpSnonWnonDnon";
bn_te_handle = [_aiming_circle] execVM '\bn_te\scripts\t-e.sqf';
sleep 3;
waitUntil {
	(isNull (uiNamespace getVariable ["BN_TE_Display", displayNull])) || !(alive player) || (player getVariable ["ACE_isUnconscious", false])
};
detach player;
player playMove "";