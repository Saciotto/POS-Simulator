#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

int fw_getKey();

void fw_display(const unsigned char *bitmap, size_t size);

void fw_setDisplayPixel(int x, int y, int r, int g, int b);

void fw_debug(const char *format, ...);

void fw_sleepMs(unsigned long time);

void app_main();

#ifdef __cplusplus
}
#endif

#endif // FRAMEWORK_H
