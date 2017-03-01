#include <QCoreApplication>
#include "autro.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    autro obj;
    int n, i = 0;
    QString Input;
    QTextStream(stdout) << "Input length : ";
    QTextStream(stdin) >> Input;
    obj.Processing(Input.split(","));
    obj.Code_Generation();
    return a.exec();
}
