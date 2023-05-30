#include "filestate.h"


FileState::FileState(){

    fileName = "null";
    size = 0;
    isExist = false;

}

FileState::FileState(const QString& Name){

    fileName = Name; //задаем имя файла
    QFileInfo fileInfo(fileName); //инициализация объекта
    size = fileInfo.size(); //определяем размер
    isExist = fileInfo.exists(); //определяем, существует ли файл
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

bool FileState::operator == (const FileState& file) const //перегрузка оператора сравнения
{
    if (file.fileName == fileName)
        return true;
        return false;
}

