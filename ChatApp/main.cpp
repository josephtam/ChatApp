#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int i = 0;
    char msg[100];
    sprintf(msg, "test %d", i);
    w.writeToDisplay(msg);
    w.writeToUsersList(msg);

    return a.exec();
}
