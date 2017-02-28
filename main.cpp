#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int nX, nS;
    QTextStream(stdin) >> nX;
//    int *X = new int[nX]; /*Множество входов*/
//    for(int i = 0; i < nX; i++)
//    {
//        QTextStream(stdout) << "Input entrance[" << i << "] : ";
//        QTextStream(stdin) >> X[i];
//    }
    QTextStream(stdin) >> nS;
//    int *S = new int[nS]; /*Множество состояний*/
//    for(int i = 0; i < nS; i++)
//    {
//        QTextStream(stdout) << "Input entrance[" << i << "] : ";
//        QTextStream(stdin) >> S[i];
//    }
    int **Y = new int*[nX]; /*Множество выходов*/
    int **ST = new int*[nX]; /*Множество переходов*/
    for(int i = 0; i < nX; i++)
    {
        Y[i] = new int[nS];
        ST[i] = new int[nS];
    }
    for(int i = 0; i < nX; i++)
    {
        for(int j = 0; j < nS; j++)
        {
            QTextStream(stdout) << "Input exit[" << i+1 << "," << j+1 << "] : ";
            QTextStream(stdin) >> Y[i][j];
        }
    }
    for(int i = 0; i < nX; i++)
    {
        for(int j = 0; j < nS; j++)
        {
            QTextStream(stdout) << "Input state[" << i+1 << "," << j+1 << "] : ";
            QTextStream(stdin) >> ST[i][j];
        }
    }
    int sActual = 0;
    QString Str;
    QTextStream(stdin) >> Str;
    QChar ch;
    int ich;
    for(int i = 0; i < Str.length(); i++)
    {
        ch = Str[i];
        ich = ch.digitValue();
//        QTextStream(stdout) << "Value Str[" << i+1 << "] : " << ich << "\n";
        QTextStream(stdout) /*<< "Entrance "*/ << Y[ich][sActual];
        sActual = ST[ich][sActual];
    }
    QTextStream(stdout) << "\n";
    for(int i = 0; i < nX; i++)
    {
        delete [] Y[i];
        delete [] ST[i];
    }
    delete [] Y;
    delete [] ST;
    return a.exec();
}
