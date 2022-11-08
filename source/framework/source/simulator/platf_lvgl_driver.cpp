#include "platf_lvgl_driver.h"

#include "binding.hpp"

#include <QColor>
#include <QImage>

using namespace simulator::framework;

void driver_flush_display(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p)
{
    if (app == nullptr)
        return;
    QImage image = app->displayImage();
    int32_t x, y;
    for (y = area->y1; y <= area->y2; y++) {
        for (x = area->x1; x <= area->x2; x++) {
            const QColor color(color_p->ch.red, color_p->ch.green, color_p->ch.blue);
            image.setPixelColor(x, y, color);
            color_p++;
        }
    }
    app->setDisplayImage(image);
    lv_disp_flush_ready(disp_drv);
}

void driver_read_touchscreen(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
    if(app->isTouchPressed()) {
        data->point.x = app->getTouchPosition().x();
        data->point.y = app->getTouchPosition().y();
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void driver_read_keypad(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
    data->key = app->getKey();
    data->state = app->isKeyPressed() ? LV_INDEV_STATE_PRESSED : LV_INDEV_STATE_RELEASED;
}
