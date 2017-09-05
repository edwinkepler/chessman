/**
 * @copyright 2017 Edwin Kepler
 * @license LGPL3
 */

#include <QtCore/QCommandLineParser>
#include <QtCore/QTranslator>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlApplicationEngine>

#include "src/gamecontrollerobject.hpp"
#include "src/logobject.hpp"

void parse_arguments(QGuiApplication& app) {
    QCommandLineParser parser;
    parser.setApplicationDescription("Chess game");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.parse(app.arguments());
    parser.process(app);
}

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);

    QGuiApplication chessman(argc, argv);
    chessman.setApplicationName("chessman");
    chessman.setApplicationVersion("0.1.4");
    chessman.setOrganizationName("Edwin Kepler");
    chessman.setOrganizationDomain("https://www.github.com/edwinkepler");

    parse_arguments(chessman);
    
    QQmlApplicationEngine *qmlapp = 
        new QQmlApplicationEngine(QUrl(QLatin1String("qrc:/main.qml")));

    return chessman.exec();
}
  