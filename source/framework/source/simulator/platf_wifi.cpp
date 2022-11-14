#include "framework.h"

bool fw_is_wifi_enabled()
{
    return true;
}

int fw_get_wifi_signal()
{
    return 46;
}

int fw_get_wifi_ssid(char *ssid, size_t sz)
{
    fw_strcpy_s(ssid, sz, "Skynet");
    return 0;
}
