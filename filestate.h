#ifndef FILESTATE_H
#define FILESTATE_H
#include <QFileInfo>
#include <QString>

class FileState
{

private:
QString fileName; //имя
bool isExist; // файл существует?
qint64 size = 0; //размер

public:
FileState();
FileState (const QString& fileName);
QString getfileName() const; //получаем имя файла
bool getisExist() const; //проверяем, существует файл или нет
qint64 getsize() const; //получаем размер

}

#endif // FILESTATE_H
