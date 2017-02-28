#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QMap>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int nX, nS;
    QTextStream(stdout) << "Input count inputs : ";
    QTextStream(stdin) >> nX;
    QString STR;
    QVector<QString> X; /*Множество входов*/
    for(int i = 0; i < nX; i++)
    {
        QTextStream(stdout) << "Input input[" << i << "] : ";
        QTextStream(stdin) >> STR;
        X.push_back(STR);
    }
    QTextStream(stdout) << "Input count states : ";
    QTextStream(stdin) >> nS;
    QVector<QString> S; /*Множество состояний*/
    for(int i = 0; i < nS; i++)
    {
        QTextStream(stdout) << "Input state[" << i << "] : ";
        QTextStream(stdin) >> STR;
        S.push_back(STR);
    }
//    int **Y = new int*[nX]; /*Множество выходов*/
//    int **ST = new int*[nX]; /*Множество переходов*/
//    for(int i = 0; i < nX; i++)
//    {
//        Y[i] = new int[nS];
//        ST[i] = new int[nS];
//    }
    QMap<QString, QMap<QString, QString> > Y; /*Множество выходов*/
    QMap<QString, QMap<QString, QString> > ST; /*Множество переходов*/
    for(int i = 0 ; i < X.length() ; i++)
    {
        for(int j = 0 ; j < S.length() ; j++)
        {
            QTextStream(stdout) << "Input transform[" << X[i] << "," << S[j] << "] : ";
            QTextStream(stdin) >> ST[X[i]][S[j]];
        }
    }
    for(int i = 0 ; i < X.length() ; i++)
    {
        for(int j = 0 ; j < S.length() ; j++)
        {
            QTextStream(stdout) << "Input entrance[" << X[i] << "," << S[j] << "] : ";
            QTextStream(stdin) >> Y[X[i]][S[j]];
        }
    }
    for(int i = 0 ; i < X.length() ; i++)
    {
        for(int j = 0 ; j < S.length() ; j++)
        {
            QTextStream(stdout) << "ST[" << X[i] << "," << S[j] << "] : " << ST[X[i]][S[j]] << "\t";
            QTextStream(stdout) << "Y[" << X[i] << "," << S[j] << "] : " << Y[X[i]][S[j]] << "\n";
        }
    }
    QString sActual = S[0];
    QVector<QString> Input;
//    QString STR;
    int n,in = 0;
    QTextStream(stdout) << "Input count strings : ";
    QTextStream(stdin) >> n;
    while(in++<n)
    {
        QTextStream(stdin) >> STR;
        Input.push_back(STR);
    }
    //
    for(int i = 0; i < Input.length(); i++)
    {
        STR = Input[i];
        QTextStream(stdout) << "sActual : " << sActual << "\t\t";
        QTextStream(stdout) << "Value Input[" << i << "] : " << STR << "\t\t";
        QTextStream(stdout) << "Entrance " << Y[STR][sActual]  << "\n";
        sActual = ST[STR][sActual];
    }
//    QTextStream(stdout) << "\n";
//    for(int i = 0; i < nX; i++)
//    {
//        delete [] Y[i];
//        delete [] ST[i];
//    }
//    delete [] Y;
//    delete [] ST;
    return a.exec();
}
