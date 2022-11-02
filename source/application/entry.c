#include "framework/framework.h"

void app_main()
{
    for (;;) {
        int key = fw_getKey();
        if (key != 0) {
            fw_debug("Key pressed = %d", key);
        }
        fw_sleepMs(100);
    }
}
