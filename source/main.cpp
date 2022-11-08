#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "components/display.hpp"
#include "controllers/application_controller.hpp"
#include "controllers/display_controller.hpp"
#include "controllers/keypad_controller.hpp"
#include "controllers/pos_controller.hpp"
#include "controllers/touchscreen_controller.hpp"
#include "framework/source/simulator/binding.hpp"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<simulator::controllers::PosController>("simulator", 1, 0, "PosController");
    qmlRegisterType<simulator::controllers::KeypadController>("simulator", 1, 0, "KeypadController");
    qmlRegisterType<simulator::controllers::DisplayController>("simulator", 1, 0, "DisplayController");
    qmlRegisterType<simulator::controllers::ApplicationController>("simulator", 1, 0, "ApplicationController");
    qmlRegisterType<simulator::controllers::TouchscreenController>("simulator", 1, 0, "TouchscreenController");

    qmlRegisterType<simulator::components::Display>("components", 1, 0, "Display");

    simulator::controllers::PosController pos;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("pos", &pos);

    const QUrl mainView(QStringLiteral("qrc:/views/SimulatorView.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [mainView](QObject* obj, const QUrl& objUrl) {
            if (!obj && mainView == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(mainView);
    pos.startApplication();
    return app.exec();
}
