#include "nt_declvar.h"

Resultado *NT_DeclVar::Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {

    Resultado* idR = this->ID->Interpretar(ctx,ctx2,ctx3);
    Resultado* tipoR = this->tipo->Interpretar(ctx,ctx2,ctx3);

    if (this->Expr) {
        Resultado* exprR = this->Expr->Interpretar(ctx,ctx2,ctx3);

        if (exprR->getTipo() == tipoR->getTipo()) {
            QString varName = idR->getValor().toString();
            std::cout<<"// declaracion de "<< varName.toStdString()<<std::endl;
            std::string valueType = tipoR->getTipo().toStdString();

                        if (valueType == "Integer") {
                            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toInt());
                        } else if (valueType == "Float") {
                            ctx->addVariable(varName.toStdString(), valueType, static_cast<float>(exprR->getValor().toDouble()));
                        } else if (valueType == "Boolean") {
                            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toBool());
                        } else if (valueType == "String") {
                            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toString().toStdString());
                        }
                        if (valueType != "Boolean")
                        {
                        int pos = ctx->getvariableplacer(varName.toStdString());
                        QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
                        MiniResultado::x++;
                        std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
                        if(exprR->miniResultado.temporales.size()==0)
                        std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<exprR->getValor().toFloat()<<";"<<std::endl;
                        else
                        std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<exprR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;

                        }else
                        {
                            int pos = ctx->getvariableplacer(varName.toStdString());
                            QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
                            QString lsalida = "L"+QString::fromStdString(std::to_string(MiniResultado::L++));
                            MiniResultado::x++;
                            //ETIQUETA DE VERDADERO
                            for (int var = 0; var < exprR->miniResultado.EV.size(); ++var) {
                            std::cout<<exprR->miniResultado.EV[var].toStdString()<<":"<<std::endl;
                            }
                            std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
                            if(exprR->miniResultado.temporales.size()==0)
                            std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<"1"<<";"<<std::endl;
                            else
                            std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<exprR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
                            //GOTO LSALIDA
                            std::cout<<"goto "<<lsalida.toStdString()<<";"<<std::endl;


                            //ETIQUETA DE FALSO
                            for (int var = 0; var < exprR->miniResultado.EF.size(); ++var) {
                            std::cout<<exprR->miniResultado.EF[var].toStdString()<<":"<<std::endl;
                            }
                            std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
                            if(exprR->miniResultado.temporales.size()==0)
                            std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<"0"<<";"<<std::endl;
                            else
                            std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<exprR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
                            //LSALIDA
                            std::cout<<lsalida.toStdString()<<":"<<std::endl;

                        }
            std::cout<<"//__________ "<<std::endl;

        } else if(exprR->getTipo() == "Integer" && tipoR->getTipo() == "Boolean"){
            QString varName = idR->getValor().toString();
            std::cout<<"// declaracion de "<< varName.toStdString()<<std::endl;
            std::string valueType = tipoR->getTipo().toStdString();

            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toInt());
            int pos = ctx->getvariableplacer(varName.toStdString());
            QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
            MiniResultado::x++;
            std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
            if(exprR->miniResultado.temporales.size()==0)
            std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<exprR->getValor().toFloat()<<";"<<std::endl;
            else
            std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<exprR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
            std::cout<<"//__________ "<<std::endl;
        }


        else
        {

            return nullptr;
        }
    } else {

        QString varName = idR->getValor().toString();
        std::string valueType = tipoR->getTipo().toStdString();

        //ctx->addVariable(varName.toStdString(), tipoR->getTipo().toStdString(), nullptr);
        if (valueType == "Integer") {
            ctx->addVariable(varName.toStdString(), valueType, 1);
        } else if (valueType == "Float") {
            ctx->addVariable(varName.toStdString(), valueType, static_cast<float>(1.1));
        } else if (valueType == "Boolean") {
            ctx->addVariable(varName.toStdString(), valueType, false);
        } else if (valueType == "String") {
            std::cout<<"//SI AGREGA EL PARAMETRO DONDE TIENE QUE AGREGARLO_____"<<std::endl;

            ctx->addVariable(varName.toStdString(), valueType, "o");
        }

        std::cout<<"//__________ "<<std::endl;
    }

    return nullptr;
}
QString NT_DeclVar::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion, tPosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;
    tPosicion <<(void*)this->tipo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Decl Var\" , fillcolor=red];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + tPosicion.str()+ ";\n");
    nodo += this->tipo->Graficar();

    if (this->Expr != nullptr){
        nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                + ePosicion.str()+ ";\n");
        nodo += this->Expr->Graficar();
    }
    return nodo;
}


// constructor resumido c++-style
NT_DeclVar::NT_DeclVar(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr) : tipo(tipo), ID(id), Expr(expr) {
    //std::cout << "CREA DECLARACION" << std::endl;
}

//constructor tipo "java"
NT_DeclVar::NT_DeclVar(AbstractExpr *tipo, AbstractExpr *id) {
    this->Expr = nullptr;
    this->ID = id;
    this->tipo = tipo;
}
