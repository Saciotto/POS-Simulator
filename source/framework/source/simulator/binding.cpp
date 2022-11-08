#include "binding.hpp"

#include "controllers/application_controller.hpp"

#include "controllers/display_controller.hpp"
#include "controllers/keypad_controller.hpp"
#include "controllers/pos_controller.hpp"

#include "framework.h"

#include <QDebug>

simulator::controllers::ApplicationController* simulator::framework::app = nullptr;

void simulator::framework::runApplication(simulator::controllers::ApplicationController* appController)
{
    app = appController;
    app_main();
}
