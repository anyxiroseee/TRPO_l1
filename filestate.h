#pragma once
#ifndef FILESTATE_H
#define FILESTATE_H
#include <QFileInfo>
#include <QString>

class FileState
{

private:
QString fileName;                      //имя
bool isExist;                          //файл существует?
qint64 size = 0;                       //размер

public:
FileState();                           //конструктор по умолчанию
FileState (const QString& fileName);   //конструктор с параметром (имя файла)
QString getfileName() const;           //получаем имя файла
bool getisExist() const;               //проверяем, существует файл или нет
qint64 getsize() const;                //получаем размер файла
bool operator == (const FileState& file) const;
};

#endif // FILESTATE_H
