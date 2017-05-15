private ["_user","_bag1","_bag2","_bag_list","_helipad"];
_bag_list = ["RDS_Podnos_Gun_Bag","RDS_M224_Gun_Bag"];
_user = _this select 0;
_bag1 = _this select 1;
_bag2 = _this select 2;

if ((_bag1 in _bag_list) || (_bag2 in _bag_list)) then {
	_helipad = (nearestObjects [_user, ["Land_HelipadEmpty_F"], 5]) select 0;
};

/*

class Extended_WeaponDisassembled_Eventhandlers
{
    class CAManBase
    {
        class tu_arty_unlevel_gun
        {
			WeaponDisassembled = "_this call tu_arty_fnc_unlevel_gun";
        };
    };
};

*/