#include "fw_thread.h"

#include <QThread>

void fw_sleep_ms(unsigned long time)
{
    QThread* thread = QThread::currentThread();
    if (thread != nullptr)
        thread->usleep(time * 1000);
}
