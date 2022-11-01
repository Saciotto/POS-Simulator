#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QDirIterator>

#include "controllers/master_controller.hpp"
#include "controllers/pos_controller.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << it.next();
    }

    const QUrl mainView(QStringLiteral("qrc:/views/SimulatorView.qml"));

    qmlRegisterType<simulator::controllers::MasterController>("Simulator", 1, 0, "MasterController");
    qmlRegisterType<simulator::controllers::PosController>("Simulator", 1, 0, "PosController");

    simulator::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
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
