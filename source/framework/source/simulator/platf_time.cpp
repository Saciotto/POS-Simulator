#include "fw_time.h"

#include <QDateTime>

void fw_get_timestamp(fw_timestamp *time)
{
    qint64 ts = QDateTime::currentMSecsSinceEpoch();
    time->sec = static_cast<unsigned long>(ts / 1000);
    time->usec = static_cast<unsigned long>(ts % 1000) * 1000;
}
