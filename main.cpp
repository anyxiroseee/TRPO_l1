#include "filestate.h"
#include "filemonitor.h"
#include <QCoreApplication>
#include <iostream>
#include <QObject>
#include <QTextStream>
#include <QFileInfo>

using namespace std;

void changedState(QString fileName, qint64 size);
void startMonitorState(QString fileName, qint64 size);
void deletedState(QString fileName);
void endofMonitorState(QString fileName);
void existState(QString fileName, qint64 size);

int main (int argc, char *argv[])
{

 QCoreApplication a(argc, argv);
 setlocale(LC_ALL, "Russian");
 FileMonitor& monitor = FileMonitor::Instance();


   QObject::connect(&monitor, &FileMonitor::startMonitoring, startMonitorState);
   QObject::connect(&monitor, &FileMonitor::endofMonitoring, endofMonitorState);
   QObject::connect(&monitor, &FileMonitor::checkChanged, changedState);
   QObject::connect(&monitor, &FileMonitor::checkDel, deletedState);
   QObject::connect(&monitor, &FileMonitor::checkExistence, existState);

   int choice = -1;
   QTextStream qin(stdin); //создание потока ввода с консоли, stdin - стандартный входной поток
   QString fileName;

   while (choice != 3) {
       wcout << L"Выберите действие:" << endl;
       wcout << L"1 - добавить файл под наблюдение" << endl;
       wcout << L"2 - удалить файл из наблюдения" << endl;
       wcout << L"3 - выход из окна выбора" << endl;

       qin >> choice;

       switch (choice) {
           case 1:
               wcout << L"Введите имя файла для добавления под наблюдение: " << endl;
               qin >> fileName;
               if (QFile::exists(fileName)) {
                   monitor.AddFile(fileName);
               } else {
                   wcout << L"Файл не найден на компьютере!" << endl;
               }
               break;
           case 2:
               wcout << L"Введите имя файла для исключения из наблюдения: " << endl;
               qin >> fileName;
               if (QFile::exists(fileName)) {
                   monitor.DelFile(fileName);
               } else {
                   wcout << L"Файл не найден на компьютере!" << endl;
               }
               break;
           case 3:
               wcout << L"Выход из окна выбора..." << endl;
               break;
           default:
               wcout << L"Некорректный ввод! Пожалуйста, выберите 1, 2 или 3." << endl;
               break;
       }
   }


 /*   //добавляем файлы для отслеживания
    monitor.AddFile("C:/Users/anyxi/Desktop/forlab1/f1.txt");
    monitor.AddFile("C:/Users/anyxi/Desktop/forlab1/f2.txt");
    monitor.AddFile("C:/Users/anyxi/Desktop/forlab1/f3.txt");

    monitor.DelFile("C:/Users/anyxi/Desktop/forlab1/f1.txt");
    monitor.DelFile("C:/Users/anyxi/Desktop/forlab1/f2.txt");
    monitor.DelFile("C:/Users/anyxi/Desktop/forlab1/f3.txt"); */

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
