#include "framework.h"

bool fw_is_cellular_enabled()
{
    return true;
}

int fw_get_cellular_signal()
{
    return 23;
}

int fw_get_cellular_carrier(char *carrier, size_t sz)
{
    fw_strcpy_s(carrier, sz, "Claro");
    return 0;
}
