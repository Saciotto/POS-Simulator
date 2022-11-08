#include "fw_clock.h"

#include <stdio.h>
#include <string.h>

void fw_format_time(const fw_clock *clock, const char *format, char *str, size_t str_size)
{
    int format_len;
    while(*format) {
        char fmt = *format;
        format_len = 1;
        format++;
        if (fmt == 'D' || fmt == 'M' || fmt == 'Y' || fmt == 'h' || fmt == 'm' || fmt == 's') {
            while (*format == fmt) {
                format_len++;
                format++;
            }
            switch (fmt) {
            case 'D':
                snprintf(str, str_size, "%0*d", format_len, clock->day);
                break;
            case 'M':
                snprintf(str, str_size, "%0*d", format_len, clock->mon);
                break;
            case 'Y':
                if (format_len == 2)
                    snprintf(str, str_size, "%0*d", format_len, clock->year % 100);
                else
                    snprintf(str, str_size, "%0*d", format_len, clock->year);
                break;
            case 'h':
                snprintf(str, str_size, "%0*d", format_len, clock->hour);
                break;
            case 'm':
                snprintf(str, str_size, "%0*d", format_len, clock->min);
                break;
            case 's':
                snprintf(str, str_size, "%0*d", format_len, clock->sec);
                break;
            default:
                return;
            }
            size_t len = strlen(str);
            str_size -= len;
            str += len;
        } else {
            if (str_size > 1) {
                *str++ = fmt;
                str_size--;
            }
        }
    }
}
