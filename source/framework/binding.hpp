#ifndef BINDING_HPP
#define BINDING_HPP

namespace simulator {

namespace controllers {
class PosController;
} // namespace controllers

namespace framework {

void init(controllers::PosController *posController);

void finish();

void startApplication();

} // namespace framework
} // namespace simulator

#endif // BINDING_HPP
