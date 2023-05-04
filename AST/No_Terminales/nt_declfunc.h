#ifndef NT_DECLFUNC_H
#define NT_DECLFUNC_H
#include "../abstractexpr.h"


class NT_DeclFunc: public AbstractExpr {
    AbstractExpr* tipo;
    AbstractExpr* ID;
    AbstractExpr* Expr;
    QVector<AbstractExpr*> declaraciones;

public:
    Resultado *Interpretar(Environment *ctx, EnvironmentFunc *ctx2, EnvironmentVect* ctx3) override;

    QString Graficar() override;

    NT_DeclFunc(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr);
    NT_DeclFunc(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr,const QVector<AbstractExpr*>& declaraciones);
};

#endif // NT_DECLFUNC_H
