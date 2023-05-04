#include "nt_asigvar.h"

NT_AsigVar::NT_AsigVar(AbstractExpr *id, AbstractExpr *expr, bool si) : ID(id), Expr(expr) {this->si = si;std::cout << "CREA ASIGNACION" << std::endl;}

// asignamos variables a la memoria
Resultado *NT_AsigVar::Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {

    Resultado* idR = this->ID->Interpretar(ctx,ctx2,ctx3);
    Resultado* expR = this->Expr->Interpretar(ctx,ctx2,ctx3);

    // Get variable name and value from the Resultado objects
    QString varName = idR->getValor().toString();
    std::cout<<"// asignacion de "<< varName.toStdString()<<std::endl;
    //Resultado*aux = new Resultado(ctx->getVariableContent(idR->getValor().toString().toStdString()));
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
    } else {
        // Handle type mismatch error
        // You can return an error Resultado or throw an exception
        // depending on your error handling strategy
        //qDebug() << "Error: Type mismatch in variable assignment";
        return nullptr;
    }
    if(valueType!="Boolean")
    {
    int pos = ctx->getvariableplacer(varName.toStdString());
    QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
    MiniResultado::x++;
    std::cout<<temporal.toStdString()<<" = P + "<<pos<<";"<<std::endl;
    if(expR->miniResultado.temporales.size()==0)
    std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<expR->getValor().toFloat()<<";"<<std::endl;
    else
    std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<expR->miniResultado.temporales[0].toStdString()<<";"<<std::endl;
    }
    else
    {
        int pos = ctx->getvariableplacer(varName.toStdString());
        QString temporal = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
        QString lsalida = "L"+QString::fromStdString(std::to_string(MiniResultado::L++));
        MiniResultado::x++;
        //ETIQUETA DE VERDADERO
        for (int var = 0; var < expR->miniResultado.EV.size(); ++var) {
        std::cout<<expR->miniResultado.EV[var].toStdString()<<":"<<std::endl;
        }
        std::cout<<temporal.toStdString()<<" = P + "<<pos<<std::endl;
        if(expR->miniResultado.temporales.size()==0)
        std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<"1"<<std::endl;
        else
        std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<expR->miniResultado.temporales[0].toStdString()<<std::endl;
        //GOTO LSALIDA
        std::cout<<"goto "<<lsalida.toStdString()<<";"<<std::endl;


        //ETIQUETA DE FALSO
        for (int var = 0; var < expR->miniResultado.EF.size(); ++var) {
        std::cout<<expR->miniResultado.EF[var].toStdString()<<":"<<std::endl;
        }
        std::cout<<temporal.toStdString()<<" = P + "<<pos<<std::endl;
        if(expR->miniResultado.temporales.size()==0)
        std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<"0"<<std::endl;
        else
        std::cout<<"stack[(int)"<<temporal.toStdString()<<"]= "<<expR->miniResultado.temporales[0].toStdString()<<std::endl;
        //LSALIDA
        std::cout<<lsalida.toStdString()<<":"<<std::endl;



    }



if(varName == "return")
    std::cout<<"goto "<<ctx->Lsalidafuncion.toStdString()<<";// se va a lsalida de funcion"<<std::endl;

std::cout<<"//__________ "<<std::endl;

    //ctx->report();
    if(this->si)
    {
    return expR;
    }
    else{
        //QString newtemp = "t"+QString::number(MiniResultado::x++);
        //std::cout<<newtemp.toStdString()<<" = "<< expR->miniResultado.temporales[0].toStdString()<<" -1;"<<std::endl;
        aux->miniResultado.temporales.push_front(expR->miniResultado.temporales[1]);
        return aux;
    }
}


QString NT_AsigVar::Graficar() {
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
