#include "autro.h"

autro::autro()
{
    Input_Y();
    Input_ST();
}

void autro::Processing(QVector<QString> Input)
{
    QString STR;
    QString sActual = S[0];
    int n = Input.size();
    for(int i = 0; i < Input.length(); i++)
    {
        STR = Input[i];
        QTextStream(stdout) << Y[STR][sActual] ;
        sActual = ST[STR][sActual];
    }
}

void autro::Input_S()
{
    QTextStream(stdout) << "\nInput_S\n";
    int n;
    QString STR;
    QTextStream(stdout) << "Input count states : ";
    QTextStream(stdin) >> n;
    for(int i = 0; i < n; i++)
    {
        QTextStream(stdout) << "Input state[" << i << "] : ";
        QTextStream(stdin) >> STR;
        S.push_back(STR);
    }
}

void autro::Input_X()
{
    QTextStream(stdout) << "\nInput_X\n";
    int n;
    QTextStream(stdout) << "Input count inputs : ";
    QTextStream(stdin) >> n;
    QString STR;
    for(int i = 0; i < n; i++)
    {
        QTextStream(stdout) << "Input input[" << i << "] : ";
        QTextStream(stdin) >> STR;
        X.push_back(STR);
    }
}

void autro::Input_Y()
{
    QTextStream(stdout) << "\nInput_Y\n";
    if(S.empty()) Input_S();
    if(X.empty()) Input_X();
    for(int i = 0 ; i < X.length() ; i++)
    {
        for(int j = 0 ; j < S.length() ; j++)
        {
            QTextStream(stdout) << "Input entrance[" << X[i] << "," << S[j] << "] : ";
            QTextStream(stdin) >> Y[X[i]][S[j]];
        }
    }
}

void autro::Input_ST()
{
    QTextStream(stdout) << "\nInput_ST\n";
    if(S.empty()) Input_S();
    if(X.empty()) Input_X();
    for(int i = 0 ; i < X.length() ; i++)
    {
        for(int j = 0 ; j < S.length() ; j++)
        {
            QTextStream(stdout) << "Input transform[" << X[i] << "," << S[j] << "] : ";
            QTextStream(stdin) >> ST[X[i]][S[j]];
        }
    }
}
