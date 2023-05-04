#ifndef NT_IMPRIMIR_H
#define NT_IMPRIMIR_H

#include "../abstractexpr.h"


class NT_Imprimir: public AbstractExpr {
   QVector<AbstractExpr*> lista_expr;
public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) override;
    QString Graficar() override;
     NT_Imprimir(const QVector<AbstractExpr*>& nodo);
};


#endif // NT_IMPRIMIR_H
