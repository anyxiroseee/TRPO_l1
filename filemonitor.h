#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include <QVector>
#include <QObject>
#include "filestate.h"

class FileMonitor : public QObject
{

private:
    Q_OBJECT
    QVector<FileState> infoFiles; //контейнер с объектами
    FileMonitor();
    FileMonitor& operator= (FileMonitor const&);
    FileMonitor(FileMonitor const&);//конструктор копирования

public:
    bool AddFile(QString Name); //добавляем файл под наблюдение
    bool DelFile(QString Name); //исключаем файл из наблюдения
    void UpdateFile(); //обновление информации о файлe
    static FileMonitor& Instance(); //чтобы на протяжении работы программы создавался один экземпляр


signals:
    void startMonitoring(QString Name, qint64 size); //сигнал о добавлении под наблюдение
    void checkExistence(QString Name, qint64 size); //сигнал о существовании файла
    void checkChanged(QString Name, qint64 size); //сигнал об изменении файла
    void checkDel(QString Name); //сигнал об удалении файла
    void endofMonitoring(QString Name); //сигнал об исключении из наблюдения

};

#endif // FILEMONITOR_H
