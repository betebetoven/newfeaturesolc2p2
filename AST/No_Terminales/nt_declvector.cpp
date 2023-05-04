#include "nt_declvector.h"

NT_DeclVector::NT_DeclVector(AbstractExpr* tipo, AbstractExpr* id, const QVector<AbstractExpr*>& expr)
    : tipo(tipo), ID(id), Expr(expr) {}

NT_DeclVector::NT_DeclVector(AbstractExpr* tipo, AbstractExpr* id)
    : tipo(tipo), ID(id), Expr({}) {}

Resultado* NT_DeclVector::Interpretar(Environment* ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Resultado* idR = this->ID->Interpretar(ctx, ctx2, ctx3);
    Resultado* tipoR = this->tipo->Interpretar(ctx, ctx2, ctx3);

    QString varName = idR->getValor().toString();
    std::string valueType = tipoR->getTipo().toStdString();
    std::cout<<"//declaracion parametros de vector "<<varName.toStdString()<<std::endl;
    QVector<const Value> values;
    std::string c3dCode;
    QString temporal = "t"+QString::number(MiniResultado::x++);
    std::cout<<temporal.toStdString()<<" = H;"<<std::endl;
    for (int i = 0; i < this->Expr.size(); i++) {
        Resultado* exprR = this->Expr[i]->Interpretar(ctx, ctx2, ctx3);
        if (valueType == "String")
            std::cout<<temporal.toStdString()<<" = H;"<<std::endl;
        if (exprR->getTipo() == tipoR->getTipo()) {
            if (exprR->getTipo() == tipoR->getTipo()) {
            if (exprR->miniResultado.temporales.size() == 0){
                // Add the exprR->getValor() to the heap
                if (valueType == "Integer")
                c3dCode += "heap[(int)H] = " + std::to_string(exprR->getValor().toInt()) + ";\n";
                else if (valueType == "Float")
                    c3dCode += "heap[(int)H] = " + std::to_string(static_cast<float>(exprR->getValor().toDouble())) + ";\n";
                else if (valueType == "Boolean")
                    c3dCode += "heap[(int)H] = " + std::to_string(exprR->getValor().toBool()) + ";\n";

                c3dCode += "H = H + 1;\n";
            } else {
                // Use the temporal value at exprR->Miniresultado.temporales[0] to add to the heap

                c3dCode += "heap[(int)H] = " + exprR->miniResultado.temporales[0].toStdString() + ";\n";
                c3dCode += "H = H + 1;\n";
            }
            }

        } else {
            return nullptr;
        }





    }
     std::cout << c3dCode;

    bool aux = 0;
    if (valueType == "Integer")
    ctx->addVariable(varName.toStdString(), valueType, 0);
    else if (valueType == "Float")
    ctx->addVariable(varName.toStdString(), valueType, static_cast<float>(0.0));
    else if (valueType == "Boolean")
        ctx->addVariable(varName.toStdString(), valueType, aux);
    else if (valueType == "String")
        ctx->addVariable(varName.toStdString(), valueType, "k");

    int pos = ctx->getvariableplacer(varName.toStdString());
    std::cout<<"//declaramos vector "<<varName.toStdString()<<std::endl;
    QString tmp = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
    std::cout<<tmp.toStdString()<<" = P + "<<pos<<";"<<std::endl;
    std::cout<<"stack[(int)"<<tmp.toStdString()<<"]= "<<temporal.toStdString()<<";"<<std::endl;
    std::cout<<"//_________fin declaracion vector "<<varName.toStdString()<<std::endl;





    return nullptr;
}

QString NT_DeclVector::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion, tPosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    //ePosicion <<(void*)this->Expr;
    tPosicion <<(void*)this->tipo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Decl VECTOR\" , fillcolor=red];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + tPosicion.str()+ ";\n");
    nodo += this->tipo->Graficar();

    /*if (this->Expr != nullptr){
        nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                + ePosicion.str()+ ";\n");
        nodo += this->Expr->Graficar();
    }*/
    return nodo;
}
