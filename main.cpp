#include "filestate.h"
#include "filemonitor.h"
#include <QCoreApplication>
#include <iostream>
#include <QObject>
using namespace std;

int main (int argc, char *argv[])
{

 QCoreApplication a(argc, argv);
 setlocale(LC_ALL, "Russian");
 FileMonitor monitor;

   void changedState(QString fileName, qint64 size);
   void startMonitorState(QString fileName, qint64 size);
   void deletedState(QString fileName);
   void endofMonitorState(QString fileName);
   void existState(QString fileName, qint64 size);

   QObject::connect(&monitor, &FileMonitor::startMonitoring, startMonitorState);
   QObject::connect(&monitor, &FileMonitor::endofMonitoring, endofMonitorState);
   QObject::connect(&monitor, &FileMonitor::checkChanged, changedState);
   QObject::connect(&monitor, &FileMonitor::checkDel, deletedState);
   QObject::connect(&monitor, &FileMonitor::checkExistence, existState);

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

void startMonitorState(QString fileName, qint64 Size) {
        wcout << L"Файл добавлен под наблюдение: " << fileName.toStdWString() << L", размер: "<< Size << L" байт" << endl;
}

void endofMonitorState(QString fileName) {
        wcout << L"Файл исключен из наблюдения: " << fileName.toStdWString() << endl;
}

void deletedState(QString fileName) {
        wcout << L"Файл удален: " << fileName.toStdWString() << endl;
}

void changedState(QString fileName, qint64 Size) {
        wcout << L"Файл изменен: " << fileName.toStdWString() << L", размер: "<< Size << L" байт"<< endl;
}

void existState(QString fileName, qint64 Size) {

        wcout << L"Файл создан: "<<  fileName.toStdWString() << L", размер: " << Size << L" байт" << endl;
}
