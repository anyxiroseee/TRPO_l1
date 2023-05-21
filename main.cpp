#include "filestate.h"
#include "filemonitor.h"
#include "checkstatesfiles.h"
#include <QCoreApplication>
#include <iostream>

int main (int argc, char *argv[])
{
 QCoreApplication a(argc, argv);
 setlocale(LC_ALL, "Russian");

        QObject::connect(this, &FileMonitor::StartMonitor, &CheckStatesFiles::startMonitorState);
        QObject::connect(this, &FileMonitor::FinishMonitor, &CheckStatesFiles::endofMonitorState);
        QObject::connect(this, &FileMonitor::checkChanged, &CheckStatesFiles::changedState);
        QObject::connect(this, &FileMonitor::checkDeleted, &CheckStatesFiles::deletedState);

    QCoreApplication a(argc, argv);
    FileMonitor& monitor = FileMonitor::Instance();

    // добавляем файлы для отслеживания
    monitor.addFile("C:\Users\anyxi\Desktop\forlab1\f1.txt");

   /* monitor.addFile("C:\Users\anyxi\Desktop\forlab1\f2.txt");
    monitor.addFile("C:\Users\anyxi\Desktop\forlab1\f3.txt");*/

    monitor.delFile("C:\Users\anyxi\Desktop\forlab1\f1.txt");
}
