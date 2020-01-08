//Created by Jakub Mączka 2019
//Copyright Jakub Mączka 2019

#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
    MainWindow mainwindow;
    mainwindow.show();

    return app.exec();
}

