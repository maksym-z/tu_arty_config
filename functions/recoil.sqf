// спасибо ACE2 за наше счастливое детство
private ["_charge", "_chargeFactor","_elvOff", "_defOff", "_azOff","_gun"];

// diag_log "tu_arty_fnc_recoil";
// diag_log _this;
_gun = _this select 0;
if (!local _gun) exitWith {};

_charge = getNumber (configFile >> "CfgMagazines" >> (currentMagazine _gun) >> "initSpeed");

_chargeFactor = _charge/70+1;
_elvOff = (-1+(random 2))*_chargeFactor;
_defOff = (-0.5+(random 1))*_chargeFactor;
_azOff = (-0.25+(random 0.5))*_chargeFactor;

// diag_log [_elvOff, _defOff,_azOff];

_azimuthPhase = _gun animationPhase "MainTurret";
_elevationPhase = _gun animationPhase "MainGun";
_traversePhase = _gun animationPhase "MainTurretTraverse";
_elvOff = ((_elvOff+_elevationPhase) max 800) min 1511;
_azOff = _azOff + _azimuthPhase;
_defOff = ((_defOff+_traversePhase) max -200) min 200;

_gun animate ["MainGun", _elvOff];
_gun animate ["MainTurret", _azOff];
_gun animate ["MainTurretTraverse", _defOff];