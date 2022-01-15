#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QFile>
#include <iostream>
#include <functional>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <time.h>
#include <QTextStream>

#include "stackadt.h"
#include "cfantasymovies.h"
#include "crandom.h"
#include "creadfile.h"




int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);




    qmlRegisterType < CFantasyMovies > ("Comms", 1, 0, "CFantasyMovies");


    Stack OddMovieStack, EvenMovieStack;
    CReadFile readfile{};
    readfile.add(OddMovieStack); readfile.add(EvenMovieStack);
    readfile.readInput();
    CRandom movieList{OddMovieStack, EvenMovieStack};
    CFantasyMovies movieNight("testTitle", "testNumber", OddMovieStack, EvenMovieStack, movieList);
    srand(time(NULL));



    qDebug() <<"CFantasySize: " << movieNight.size();




    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *topLevel = engine.rootObjects().at(0);


    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    //connect - from QML to C++
    QObject::connect(window, SIGNAL(userNumber(QString)),
                        &movieNight, SLOT(setUserRandomNumber(QString)));
    // connect - from C++ to QML
    QObject::connect(&movieNight,
                     SIGNAL(userRandomNumberChanged(QVariant)),
                     window, SLOT(qmlMovieUpdate(QVariant)));


    return app.exec();
}
