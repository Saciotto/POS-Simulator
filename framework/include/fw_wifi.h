#ifndef FW_WIFI_H
#define FW_WIFI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>

bool fw_is_wifi_enabled();
int fw_get_wifi_signal();
int fw_get_wifi_ssid(char *ssid, size_t sz);

#ifdef __cplusplus
}
#endif

#endif // FW_WIFI_H
