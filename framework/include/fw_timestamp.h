#ifndef FW_TIMESTAMP_H
#define FW_TIMESTAMP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned long usec;
    unsigned long sec;
} fw_timestamp;

void fw_get_timestamp(fw_timestamp *time);

long fw_timestamp_diff(const fw_timestamp *ts1, fw_timestamp *ts2);

#ifdef __cplusplus
}
#endif

#endif // FW_TIMESTAMP_H
