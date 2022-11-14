#include "fw_timestamp.h"

long fw_timestamp_diff(const fw_timestamp *ts1, fw_timestamp *ts2)
{
    long diff = ((long) ts1->sec - (long) ts2->sec) * 1000;
    diff += ((long) ts1->usec - (long) ts2->usec) / 1000;
    return diff;
}
