#include "framework.h"

bool fw_has_battery()
{
    return true;
}

bool fw_is_battery_charging()
{
    return false;
}

int fw_get_battery_level()
{
    return 76;
}
