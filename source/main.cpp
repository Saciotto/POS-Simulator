#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controllers/master_controller.hpp"
#include "controllers/pos_controller.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    const QUrl mainView(QStringLiteral("qrc:/POS_Simulator/views/SimulatorView.qml"));
    const QUrl keyCodes(QStringLiteral("qrc:/POS_Simulator/views/constants/KeyCodes.qml"));

    qmlRegisterType<simulator::controllers::MasterController>("Simulator", 1, 0, "MasterController");
    qmlRegisterType<simulator::controllers::PosController>("Simulator", 1, 0, "PosController");

    qmlRegisterSingletonType(keyCodes, "KeyCodes", 1, 0, "Key");

    simulator::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/POS_Simulator");
    engine.rootContext()->setContextProperty("master", &masterController);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [mainView](QObject* obj, const QUrl& objUrl) {
            if (!obj && mainView == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(mainView);
    return app.exec();
}
