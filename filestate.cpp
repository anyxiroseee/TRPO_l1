#include "filestate.h"

FileState::FileState(const QString& Name){

    QFileInfo fileInfo();
    fileName = Name;
    size = fileInfo.size();
    isExist = fileInfo.isExist();

}
