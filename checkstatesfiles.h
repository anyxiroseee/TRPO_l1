#ifndef CHECKSTATESFILES_H
#define CHECKSTATESFILES_H

#include <QString>
#include <QObject>

class CheckStatesFiles : public QObject //вывод
{
    Q_OBJECT
public:
    CheckStatesFiles(); //конструктор
    void createdState(QString fileName, qint64 size);
    void changedState(QString fileName, qint64 size);
    void deletedState(QString fileName);

}

#endif // CHECKSTATESFILES_H
