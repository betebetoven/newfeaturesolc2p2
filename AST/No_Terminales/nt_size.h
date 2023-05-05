#ifndef NT_SIZE_H
#define NT_SIZE_H

#include "../abstractexpr.h"

class NT_Size: public AbstractExpr {
    AbstractExpr* id;

public:
    Resultado *Interpretar(Environment *ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) override;
    QString Graficar() override;
    NT_Size(AbstractExpr* id);
};

#endif // NT_SIZE_H
