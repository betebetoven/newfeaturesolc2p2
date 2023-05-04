#ifndef T_ID_H
#define T_ID_H
#include "../abstractexpr.h"

class T_ID : public AbstractExpr{
    QString id ;
    QVector<AbstractExpr*> lista_expr;
public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) override;

    QString Graficar() override;

    T_ID(QString id);
    //
    T_ID(QString id,const QVector<AbstractExpr*>&nodo);

};


#endif // T_ID_H
