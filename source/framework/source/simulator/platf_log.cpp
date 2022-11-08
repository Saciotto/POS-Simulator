#include "fw_log.h"

#include <QDebug>

void fw_log(const char* format, ...)
{
    char buffer[10000];
    buffer[sizeof(buffer) - 1] = '\0';
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer) - 1, (char*) format, args);
    va_end(args);
    qDebug() << buffer;
}
