#ifndef FILESTATE_H
#define FILESTATE_H
#include <QFileInfo>


class FileState
{
public:
bool isExist; // файл существует?
qint64 size = 0;
private:
FileState();

}



#endif // FILESTATE_H
