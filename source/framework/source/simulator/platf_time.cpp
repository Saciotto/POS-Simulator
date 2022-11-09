#include "fw_time.h"

#include <QTime>

void fw_get_time(fw_time *time)
{
    QDateTime dt = QDateTime::currentDateTime();
    QDate date = dt.date();
    time->year = date.year();
    time->mon = date.month();
    time->day = date.day();
    QTime qtime = dt.time();
    time->hour = qtime.hour();
    time->min = qtime.minute();
    time->sec = qtime.second();
}
