#include "fw_clock.h"

#include <QTime>

void fw_get_clock(fw_clock *clock)
{
    QDateTime dt = QDateTime::currentDateTime();
    QDate date = dt.date();
    clock->year = date.year();
    clock->mon = date.month();
    clock->day = date.day();
    QTime time = dt.time();
    clock->hour = time.hour();
    clock->min = time.minute();
    clock->sec = time.second();
}
