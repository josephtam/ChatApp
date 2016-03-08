#include "mainwindow.h"
#include <QApplication>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool writeToFile(ofstream *ofs, string s);

bool saveMode = true;

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

    ofstream dumpFile;
    if (saveMode)
    {
        dumpFile.open("dump.txt", ios::trunc);
        writeToFile(&dumpFile, "this is a test1");
        writeToFile(&dumpFile, "this is a test2");
        dumpFile.close();
    }

    return a.exec();
}

bool writeToFile(ofstream *ofs, string s)
{
    *ofs << s << endl;
    return true;
}


