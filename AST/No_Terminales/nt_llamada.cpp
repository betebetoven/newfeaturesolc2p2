#include "nt_llamada.h"
#include "nt_bloque.h"

Resultado* NT_Llamada::Interpretar(Environment* env, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Resultado* idR = this->ID->Interpretar(env,ctx2,ctx3);
    std::string varName = idR->getValor().toString().toStdString();
    QString varType = idR->getTipo();
    Resultado* aux;
    this->nombre = varName;
    AbstractExpr* expr = ctx2->getVariableExpr(varName);

    if (expr) {//EXPR ES UN BLOQUE

            QString temporalposicion="";
            QString temporalderetorno = "";
            if(this->asignacionparametros.size()!=0)
            {
                temporalposicion = "t"+QString::number(MiniResultado::x++);
                std::cout<<temporalposicion.toStdString()<<"= P+"<<env->placer<<";"<<std::endl;
            }

            for (int var = 0; var < this->asignacionparametros.size(); ++var) {
                QString temporalindice = "t"+QString::number(MiniResultado::x++);
                std::cout<<temporalindice.toStdString()<<" = "<<temporalposicion.toStdString()<<" + "<<var+1<<";"<<std::endl;
                Resultado* p = this->asignacionparametros[var]->Interpretar(env,ctx2,ctx3);
                if(p->miniResultado.EV.size()==0)
                aux = p;

                //aqui es donde verificamos si termporal trae etiquetas, temporal, o valor
                if(p->miniResultado.temporales.size()!=0)
                std::cout<<"stack[(int)"<<temporalindice.toStdString()<<"] = "<<p->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
                else if(p->miniResultado.EV.size()!=0 && p->miniResultado.EF.size()!=0)
                {
                    for (int var = 0; var <p->miniResultado.EV.size(); ++var) {
                        std::cout<<p->miniResultado.EV[var].toStdString()<<":"<<std::endl;
                    }
                    std::cout<<"stack[(int)"<<temporalindice.toStdString()<<"] = 1"<<";"<<std::endl;
                    //goto lsalida
                    QString salidamini = "L"+QString::number(MiniResultado::L++);
                    std::cout<<"goto "<<salidamini.toStdString()<<";"<<std::endl;
                    for (int var = 0; var <p->miniResultado.EF.size(); ++var) {
                        std::cout<<p->miniResultado.EF[var].toStdString()<<":"<<std::endl;
                    }
                    std::cout<<"stack[(int)"<<temporalindice.toStdString()<<"] = 0"<<";"<<std::endl;
                    std::cout<<salidamini.toStdString()<<":"<<std::endl;
                }
                else
                    std::cout<<"stack[(int)"<<temporalindice.toStdString()<<"] = "<<p->getValor().toString().toStdString()<<";"<<std::endl;


            }

            std::cout<<"P = P + "<<env->placer<<";"<<std::endl;
            std::cout<<varName<<"();"<<std::endl;
            std::cout<<"P = P - "<<env->placer<<";"<<std::endl;
            if(temporalposicion!="")
            {
             temporalderetorno = "t"+QString::number(MiniResultado::x++);
             std::cout<<"//termporal de retorno"<<std::endl;
            std::cout<<temporalderetorno.toStdString()<<" = stack[(int)"<<temporalposicion.toStdString()<<"];"<<std::endl;
            }





            aux->miniResultado.temporales.push_front(temporalderetorno);
            return aux;
    } 

    return nullptr;




}

QString NT_Llamada::Graficar() {
    std::stringstream pPosicion;
    pPosicion << (void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
                                  " [ label=\"EXP: Llamada " + this->nombre +
                                  "\"   fillcolor=lightblue];\n");
}

NT_Llamada::NT_Llamada(AbstractExpr *id) : ID(id) {this-> asignacionparametros = {};}
NT_Llamada::NT_Llamada(AbstractExpr *id,const QVector<AbstractExpr*>& asignacionparametros) : ID(id), asignacionparametros(asignacionparametros) {}
