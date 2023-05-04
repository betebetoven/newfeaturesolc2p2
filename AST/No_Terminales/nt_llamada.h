#ifndef NT_LLAMADA_H
#define NT_LLAMADA_H

#include "../abstractexpr.h"

class NT_Llamada : public AbstractExpr {
    AbstractExpr* ID;
    std::string nombre;

public:
    Resultado* Interpretar(Environment* env, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) override;
    QString Graficar() override;
    QVector<AbstractExpr*> asignacionparametros;
    NT_Llamada(AbstractExpr *id);
    NT_Llamada(AbstractExpr *id,const QVector<AbstractExpr*>& asignacionparametros);
};

#endif // NT_LLAMADA_H
//const QVector<AbstractExpr*>&
