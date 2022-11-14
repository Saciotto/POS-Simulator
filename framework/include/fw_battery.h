#ifndef FW_BATTERY_H
#define FW_BATTERY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool fw_has_battery();
bool fw_is_battery_charging();
int fw_get_battery_level();

#ifdef __cplusplus
}
#endif

#endif // FW_BATTERY_H
