#ifndef FW_TIME_H
#define FW_TIME_H

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
} fw_time;

void fw_get_time(fw_time *time);

void fw_format_time(const fw_time *time, const char *format, char *str, size_t str_size);

#ifdef __cplusplus
}
#endif

#endif // FW_TIME_H
