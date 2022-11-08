#ifndef BINDING_HPP
#define BINDING_HPP

#include "controllers/application_controller.hpp"

namespace simulator {
namespace framework {

extern controllers::ApplicationController* app;

void runApplication(controllers::ApplicationController* appController);

} // namespace framework
} // namespace simulator

#endif // BINDING_HPP
