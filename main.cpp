#include <QCoreApplication>
#include "autro.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    autro obj;
    int n, i = 0;
    QVector<QString> Str;
    QTextStream(stdout) << "Input length : ";
    QTextStream(stdin) >> n;
    QString S;
    while(i<n)
    {
        QTextStream(stdout) << "Input str[" << i++ <<"] : ";
        QTextStream(stdin) >> S;
        Str.push_back(S);
    }
    obj.Processing(Str);
    return a.exec();
}
