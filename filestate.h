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
qint64 size;                       //размер DELETE NOL

public:
FileState();                           //конструктор по умолчанию
FileState (const QString& fileName);   //конструктор с параметром (имя файла)
QString getfileName();           //получаем имя файла
bool getisExist();               //проверяем, существует файл или нет
qint64 getsize();                //получаем размер файла
bool operator == (const FileState& file)const;
};

#endif // FILESTATE_H
