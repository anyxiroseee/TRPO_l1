#include "filestate.h"
#include "filemonitor.h"
#include "checkstatesfiles.h"
#include <QCoreApplication>
#include <iostream>


int main (int argc, char *argv[])
{
 QCoreApplication a(argc, argv);
 setlocale(LC_ALL, "Russian");
 CheckStatesFiles Print;
 FileMonitor monitor;

        QObject::connect(&monitor, &FileMonitor::startMonitoring, &Print, &CheckStatesFiles::startMonitorState);
        QObject::connect(&monitor, &FileMonitor::endofMonitoring, &Print, &CheckStatesFiles::endofMonitorState);
        QObject::connect(&monitor, &FileMonitor::checkChanged, &Print, &CheckStatesFiles::changedState);
        QObject::connect(&monitor, &FileMonitor::checkDel, &Print, &CheckStatesFiles::deletedState);
        QObject::connect(&monitor, &FileMonitor::checkExistence, &Print, &CheckStatesFiles::existState);

    //добавляем файлы для отслеживания
    monitor.AddFile("C:/Users/anyxi/Desktop/forlab1/f1.txt");
    monitor.AddFile("C:/Users/anyxi/Desktop/forlab1/f2.txt");
    monitor.AddFile("C:/Users/anyxi/Desktop/forlab1/f3.txt");

    monitor.DelFile("C:/Users/anyxi/Desktop/forlab1/f1.txt");
    monitor.DelFile("C:/Users/anyxi/Desktop/forlab1/f2.txt");
    monitor.DelFile("C:/Users/anyxi/Desktop/forlab1/f3.txt");

    while (true) {
           monitor.UpdateFile();
       }

       return a.exec();

}
