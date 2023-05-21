#include "filestate.h"

FileState::FileState(const QString& Name){

    fileName = Name; //задаем имя файла
    QFileInfo fileInfo(fileName);
    size = fileInfo.size(); //определяем размер
    isExist = fileInfo.isExist(); //определяем, существует ли файл
}

QString FileState::getfileName()
{
    return fileName;
}
qint64 FileState::getsize()
{
    return size;
}
bool FileState::getisExist()
{
    return isExist;
}

bool FileState::operator == (FileState file)const //перегрузка оператора сравнения
{
    if (file.fileName == fileName)
        return false;
    else
        return true;
}
