#ifndef FW_CLOCK_H
#define FW_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef struct {
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;
} fw_clock;

void fw_get_clock(fw_clock *clock);

void fw_format_time(const fw_clock *clock, const char *format, char *str, size_t str_size);

#ifdef __cplusplus
}
#endif

#endif // FW_CLOCK_H
