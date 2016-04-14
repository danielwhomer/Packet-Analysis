#define TEXT_TEST

#ifndef TEXT_TEST

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#else

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "panal.h"

using namespace std;

int main(int argc, char *argv[])
{
    int iface_count = 0;
    NetworkInterface *interfaces;
    NetworkInterface::findAllInterfaces(interfaces, iface_count);

    for (int i=0; i<iface_count; ++i) {
        cout << interfaces[i] << endl;
    }

    Sniffer sniff(interfaces[0].getName());

    sniff.start(100);

    delete [] interfaces;
}

#endif //TEXT_TEST
