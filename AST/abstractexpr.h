#ifndef ABSTRACTEXPR_H
#define ABSTRACTEXPR_H

#include<QString>

#include "../Interprete/Contexto/resultado.h"
#include "../Interprete/Contexto/environment.h"
#include "../Interprete/Contexto/environmentfunc.h"
#include"../Interprete/Contexto/environmentvect.h"

#include <sstream>
//class Environment;
class EnvironmentFunc;
class AbstractExpr
{
public:
    virtual Resultado* Interpretar(Environment* ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) = 0;
       virtual QString Graficar() = 0;
};

#endif // ABSTRACTEXPR_H
