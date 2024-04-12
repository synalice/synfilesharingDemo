#include "mainwindow.h"

#include <QApplication>
#include <synfilesharing/synfilesharing.h>

int main(int argc, char *argv[])
{
    synfs::helloWorld();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
