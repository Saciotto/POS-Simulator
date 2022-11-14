#ifndef FW_CELLULAR_H
#define FW_CELLULAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>

bool fw_is_cellular_enabled();
int fw_get_cellular_signal();
int fw_get_cellular_carrier(char *carrier, size_t sz);

#ifdef __cplusplus
}
#endif

#endif // FW_CELLULAR_H
