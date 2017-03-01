#include "autro.h"

autro::autro()
{
    Input_Y();
    Input_ST();
}

void autro::Processing(QStringList Input)
{
    QString sActual = S[0];
    foreach (QString Str, Input) {
        QTextStream(stdout) << Y[Str][sActual] ;
        sActual = ST[Str][sActual];
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

void autro::Code_Generation()
{
    QString Current_Str;
    Current_Str = "switch(Input)\n{\n";
    foreach (QString Inputs, X) {
        Current_Str.append("case ");
        Current_Str.append(Inputs);
        Current_Str.append(" :\n{\n");
        Current_Str.append("switch (Status)\n{\n");
        foreach (QString State, S) {
            Current_Str.append("case ");
            Current_Str.append(State);
            Current_Str.append(" :\n{\n");
            Current_Str += "std::cout << Entrance.find(" + Inputs + "," + State + ") << std::endl;\n";
            Current_Str += "Status = Transform.find(" + Inputs + "," + State + ");\n";
            Current_Str.append("break;\n}\n");
        }
        Current_Str.append("}\nbreak;\n}\n");
    }
    Current_Str.append("}");
    Code.append(Current_Str);
    QTextStream(stdout) << "\n\n\n\n\n\n\n" << Code;
}
