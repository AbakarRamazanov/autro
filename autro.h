#ifndef AUTRO_H
#define AUTRO_H
#include <QTextStream>
#include <QString>
#include <QMap>
#include <QVector>
#include <QDebug>

class autro
{
    QVector<QString> X;
    QVector<QString> S;
    QMap<QString, QMap<QString, QString> > Y;
    QMap<QString, QMap<QString, QString> > ST;
public:
    void Input_S();
    void Input_X();
    void Input_ST();
    void Input_Y();
    void Processing(QVector<QString> Str);
    autro();
};

#endif // AUTRO_H
