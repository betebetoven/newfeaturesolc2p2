#ifndef NT_DECLMATRIZ_H
#define NT_DECLMATRIZ_H

#include "../abstractexpr.h"
#include <QVector>

class NT_DeclMatriz: public AbstractExpr {
    AbstractExpr* tipo;
    AbstractExpr* ID;

public:
    QVector<AbstractExpr*> Expr;
    Resultado* Interpretar(Environment* ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) override;

    QString Graficar() override;

    NT_DeclMatriz(AbstractExpr* tipo, AbstractExpr* id, const QVector<AbstractExpr*>& expr);

};

#endif // NT_DECLMATRIZ_H
