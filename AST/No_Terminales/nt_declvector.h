#ifndef NT_DECLVECTOR_H
#define NT_DECLVECTOR_H

#include "../abstractexpr.h"
#include <QVector>

class NT_DeclVector: public AbstractExpr {
    AbstractExpr* tipo;
    AbstractExpr* ID;

public:
    QVector<AbstractExpr*> Expr;
    Resultado* Interpretar(Environment* ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) override;

    QString Graficar() override;

    NT_DeclVector(AbstractExpr* tipo, AbstractExpr* id, const QVector<AbstractExpr*>& expr);
    NT_DeclVector(AbstractExpr* tipo, AbstractExpr* id);
};

#endif // NT_DECLVECTOR_H
