#include "checkstatesfiles.h"
#include <iostream>
using namespace std;

CheckStatesFiles::CheckStatesFiles()
{
}

void CheckStatesFiles::startMonitorState(QString fileName, qint64 Size) {
        wcout << L"Файл добавлен под наблюдение: " << fileName.toStdWString() << L", размер: "<< Size << L" байт" << endl;
}

void CheckStatesFiles::endofMonitorState(QString fileName) {
        wcout << L"Файл исключен из наблюдения: " << fileName.toStdWString() << endl;
}

void CheckStatesFiles::deletedState(QString fileName) {
        wcout << L"Файл удален: " << fileName.toStdWString() << endl;
}

void CheckStatesFiles::changedState(QString fileName, qint64 Size) {
        wcout << L"Файл изменен: " << fileName.toStdWString() << L", размер: "<< Size << L" байт"<< endl;
}
