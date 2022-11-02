#include "binding.hpp"

#include "controllers/pos_controller.hpp"
#include "controllers/keypad_controller.hpp"
#include "controllers/display_controller.hpp"

#include "framework.h"

#include <QImage>
#include <QDebug>
#include <QThread>

static simulator::controllers::PosController *pos = nullptr;
static QThread *appThread = nullptr;

void simulator::framework::init(simulator::controllers::PosController *posController)
{
    pos = posController;
}

void simulator::framework::startApplication()
{
    appThread = QThread::create(app_main);
    appThread->start();
}

int fw_getKey()
{
    if (pos == nullptr)
        return 0;
    return pos->keypadController()->nextKey();
}

void fw_display(const unsigned char *bitmap, size_t size)
{
    if (pos == nullptr || bitmap == nullptr || size == 0)
        return;
    QImage image(QImage::fromData(bitmap, size));
    pos->displayController()->setImage(image);
}

void fw_debug(const char *format, ...)
{
    char buffer[10000];
    buffer[sizeof(buffer) - 1] = '\0';
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer) - 1, (char *) format, args);
    va_end(args);
    qDebug() << buffer;
}

void fw_sleepMs(unsigned long time)
{
    if (appThread != nullptr)
        appThread->usleep(time * 1000);
}
