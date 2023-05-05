#include "nt_assignvector.h"

NT_AsigVector::NT_AsigVector(AbstractExpr *id, const QVector<AbstractExpr*>& exprList, AbstractExpr *expr) : ID(id), ExprList(exprList), Expr(expr)  {}

// Assign vector variables to memory
Resultado *NT_AsigVector::Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Resultado* idR = this->ID->Interpretar(ctx,ctx2,ctx3);
    Resultado* expR = this->Expr->Interpretar(ctx,ctx2,ctx3);

    // Get variable name and value from the Resultado objects
    QString varName = idR->getValor().toString();
    std::cout<<"// asignacion de vector  "<< varName.toStdString()<<std::endl;
    std::variant<std::nullptr_t, int, float, std::string, bool> variableContent = ctx->getVariableContent(idR->getValor().toString().toStdString());

    Resultado *aux = std::visit(
        [](auto &&arg) -> Resultado * {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, bool>) {
                return new Resultado(arg);
            } else if constexpr (std::is_same_v<T, std::string>) {
                return new Resultado(QString::fromStdString(arg));
            } else {
                return nullptr;
            }
        },
        variableContent);
    std::string valueType = expR->getTipo().toStdString();
    //std::cout << "Entro en asignacion" << expR->getValor().toString().toStdString()<<std::endl;
    // Update the variable in the environment based on the value type
    if (valueType == "Integer") {
        ctx->updateVariable(varName.toStdString(), expR->getValor().toInt(),expR->getTipo());
    } else if (valueType == "Float") {
        ctx->updateVariable(varName.toStdString(), static_cast<float>(expR->getValor().toDouble()),expR->getTipo());
    } else if (valueType == "Boolean") {
        ctx->updateVariable(varName.toStdString(), expR->getValor().toBool(),expR->getTipo());
    } else if (valueType == "String") {
        ctx->updateVariable(varName.toStdString(), expR->getValor().toString().toStdString(),expR->getTipo());
    }

    if(valueType!="Boolean")
    {
        if(this->ExprList.size() ==1)
        {
    int pos = ctx->getvariableplacer(varName.toStdString());
    QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
    QString indicestack = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
    QString indicesaltoheap = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
    // valorheap = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
    Resultado* x = this->ExprList[0]->Interpretar(ctx,ctx2,ctx3);
    std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
    std::cout<<indicestack.toStdString()<<" = stack[(int)"<<temporal.toStdString()<<"];"<<std::endl;
    if(x->miniResultado.temporales.size()==0)
    std::cout<<indicesaltoheap.toStdString()<<" = "<<indicestack.toStdString()<<" + "<<x->getValor().toInt()<<";"<<std::endl;
    else
    std::cout<<indicesaltoheap.toStdString()<<" = "<<indicestack.toStdString()<<" + "<<x->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
    if(expR->miniResultado.temporales.size()==0)
    std::cout<<"heap[(int)"<<indicesaltoheap.toStdString()<<"]= "<<expR->getValor().toFloat()<<";"<<std::endl;
    else
    std::cout<<"heap[(int)"<<indicesaltoheap.toStdString()<<"]= "<<expR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
    }else if(this->ExprList.size() >1)
        {

            int placer = ctx->getvariableplacer(varName.toStdString());
            QString tposicion = "t"+QString::number(MiniResultado::x++);
            QString tstack = "t"+QString::number(MiniResultado::x++);
            QString tindex = "t"+QString::number(MiniResultado::x++);
            QString theap = "t"+QString::number(MiniResultado::x++);
            QString temporaldeE= "";
            int total = ctx3->linearSize(varName.toStdString());
            QString tcontador = "t"+QString::number(MiniResultado::x++);
            std::cout<<tcontador.toStdString()<<" = 0;"<<std::endl;
            for (int var = 0; var < this->ExprList.size()-1; ++var) {
                Resultado* x = this->ExprList[var]->Interpretar(ctx,ctx2,ctx3);
                QString temporalderesta="t"+QString::number(MiniResultado::x++);
                QString temporaldemulti="t"+QString::number(MiniResultado::x++);
                total = total / ctx3->getDimensionFrom(varName.toStdString(),var);

                //std::cout<<temporalderesta.toStdString()<<" = "<<x->getValor().toInt()<<" - 1;"<<std::endl;
                std::cout<<temporalderesta.toStdString()<<" = "<<x->getValor().toInt()<<";"<<std::endl;
                std::cout<<temporaldemulti.toStdString()<<" = "<<temporalderesta.toStdString()<<" * "<<total<<";"<<std::endl;
                std::cout<<tcontador.toStdString()<<" = "<<tcontador.toStdString()<<" + "<<temporaldemulti.toStdString()<<";"<<std::endl;

                //temporaldeE = tcontador;
            }
            Resultado* x = this->ExprList[this->ExprList.size()-1]->Interpretar(ctx,ctx2,ctx3);
            temporaldeE="t"+QString::number(MiniResultado::x++);
            std::cout<<temporaldeE.toStdString()<<" = "<<tcontador.toStdString()<<" + "<<x->getValor().toInt()<<";"<<std::endl;
            //std::cout<<temporaldeE.toStdString()<<" = "<<temporaldeE.toStdString()<<" - 1;"<<std::endl;



            //else
            //t = p+0 t = stack[t]
            std::cout<<tposicion.toStdString()<<" =P + "<<placer<<";"<<std::endl;
            std::cout<<tstack.toStdString()<<" = stack[(int)"<<tposicion.toStdString()<<"];"<<std::endl;

            std::cout<<tindex.toStdString()<<" = "<<tstack.toStdString()<<" + "<<temporaldeE.toStdString()<<";"<<std::endl;
            //std::cout<<theap.toStdString()<<" = heap[(int)"<<tindex.toStdString()<<"];"<<std::endl;
            if(expR->miniResultado.temporales.size()==0)
            std::cout<<"heap[(int)"<<tindex.toStdString()<<"]= "<<expR->getValor().toFloat()<<";"<<std::endl;
            else
            std::cout<<"heap[(int)"<<tindex.toStdString()<<"]= "<<expR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;






        }




















    }
    else
    {
        if(this->ExprList.size() ==1)
        {

        int pos = ctx->getvariableplacer(varName.toStdString());
        QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
        QString indicestack = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
        QString indicesaltoheap = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
        QString lsalida = "L"+QString::fromStdString(std::to_string(MiniResultado::L++));
        Resultado* x = this->ExprList[0]->Interpretar(ctx,ctx2,ctx3);
        //ETIQUETA DE VERDADER
        for (int var = 0; var < expR->miniResultado.EV.size(); ++var) {
        std::cout<<expR->miniResultado.EV[var].toStdString()<<":"<<std::endl;
        }
        std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
        std::cout<<indicestack.toStdString()<<" = stack[(int)"<<temporal.toStdString()<<"];"<<std::endl;
        if(x->miniResultado.temporales.size()==0)
        std::cout<<indicesaltoheap.toStdString()<<" = "<<indicestack.toStdString()<<" + "<<x->getValor().toInt()<<";"<<std::endl;
        else
        std::cout<<indicesaltoheap.toStdString()<<" = "<<indicestack.toStdString()<<" + "<<x->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
        if(expR->miniResultado.temporales.size()==0)
        std::cout<<"heap[(int)"<<indicesaltoheap.toStdString()<<"]= 1;"<<std::endl;
        else
        std::cout<<"heap[(int)"<<indicesaltoheap.toStdString()<<"]= 1;"<<std::endl;


        //GOTO LSALIDA
        std::cout<<"goto "<<lsalida.toStdString()<<";"<<std::endl;
        //ETIQUETA DE FALSO
        for (int var = 0; var < expR->miniResultado.EF.size(); ++var) {
        std::cout<<expR->miniResultado.EF[var].toStdString()<<":"<<std::endl;
        }
        std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
        std::cout<<indicestack.toStdString()<<" = stack[(int)"<<temporal.toStdString()<<"];"<<std::endl;
        if(x->miniResultado.temporales.size()==0)
        std::cout<<indicesaltoheap.toStdString()<<" = "<<indicestack.toStdString()<<" + "<<x->getValor().toInt()<<";"<<std::endl;
        else
        std::cout<<indicesaltoheap.toStdString()<<" = "<<indicestack.toStdString()<<" + "<<x->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
        if(expR->miniResultado.temporales.size()==0)
        std::cout<<"heap[(int)"<<indicesaltoheap.toStdString()<<"]= 0;"<<std::endl;
        else
        std::cout<<"heap[(int)"<<indicesaltoheap.toStdString()<<"]= 0;"<<std::endl;


        //LSALIDA
        std::cout<<lsalida.toStdString()<<":"<<std::endl;

        }

    }





    return nullptr;
}

QString NT_AsigVector::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"AsigVar\" , fillcolor=midnightblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + ePosicion.str()+ ";\n");
    nodo += this->Expr->Graficar();
    return nodo;
}
