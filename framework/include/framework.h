#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "fw_battery.h"
#include "fw_cellular.h"
#include "fw_log.h"
#include "fw_lvgl.h"
#include "fw_string.h"
#include "fw_thread.h"
#include "fw_time.h"
#include "fw_timestamp.h"
#include "fw_wifi.h"

extern void app_main();

#ifdef __cplusplus
}
#endif

#endif // FRAMEWORK_H
