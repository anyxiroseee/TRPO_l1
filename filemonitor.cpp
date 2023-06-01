#include "filemonitor.h"
#include "filestate.h"
#include "checkstatesfiles.h"
#include <iostream>

FileMonitor::FileMonitor()
{
}

bool FileMonitor::AddFile(QString Name)
{
    FileState file(Name);
            if (!infoFiles.contains(file) && Name != ""){
        infoFiles.push_back(file);
        emit startMonitoring(file.getfileName(), file.getsize());
        return true;
    }
    else
        return false;
}

bool FileMonitor::DelFile(QString Name)
{
    FileState oldfile(Name);
    if (infoFiles.contains(oldfile)){
        infoFiles.removeOne(oldfile);
        emit endofMonitoring(oldfile.getfileName());
        return true;
    }
    else
        return false;
}

void FileMonitor::UpdateFile()
{

    for (int k = 0; k < infoFiles.count(); k++)
    {
        FileState newfile(infoFiles[k].getfileName());
        if ((newfile.getisExist() != infoFiles[k].getisExist()) && (newfile.getisExist())){
            infoFiles[k] = newfile; //обновляем данные о файле в контейнере
            emit checkExistence(newfile.getfileName(), newfile.getsize()); //сигнал о сущ-нии файла
        }
        else if ((newfile.getisExist() != infoFiles[k].getisExist()) && (!newfile.getisExist())) //текущее состояние файла не совпадает с предыдущим
        {
            infoFiles[k] = newfile;
            emit checkDel(newfile.getfileName()); //сигнал об удалении
        }
        else if ((newfile.getsize() != infoFiles[k].getsize()) && (newfile.getisExist()))
        {
            infoFiles[k] = newfile;
            emit checkChanged(newfile.getfileName(), newfile.getsize()); //сигнал об изменении
        }
    }
}

