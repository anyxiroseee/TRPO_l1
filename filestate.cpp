#include "filestate.h"

FileState::FileState(const QString& fileName){

    QFileInfo fileInfo();
    fileName = fileName;
    size = fileInfo.size();
    isExist = fileInfo.isExist();

}
