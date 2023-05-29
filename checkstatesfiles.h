#ifndef CHECKSTATESFILES_H
#define CHECKSTATESFILES_H

#include <QString>
#include <QObject>

class CheckStatesFiles : public QObject //вывод
{
    Q_OBJECT
public:
    CheckStatesFiles(); //конструктор
    void changedState(QString fileName, qint64 size);
    void deletedState(QString fileName);
    void startMonitorState(QString fileName, qint64 size);
    void endofMonitorState(QString fileName);
    void existState(QString fileName, qint64 size);
};

#endif // CHECKSTATESFILES_H
