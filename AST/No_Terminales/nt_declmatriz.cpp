#include "nt_declmatriz.h"

NT_DeclMatriz::NT_DeclMatriz(AbstractExpr* tipo, AbstractExpr* id, const QVector<AbstractExpr*>& expr)
    : tipo(tipo), ID(id), Expr(expr) {}

Resultado* NT_DeclMatriz::Interpretar(Environment* ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Resultado* idR = this->ID->Interpretar(ctx, ctx2, ctx3);
    Resultado* tipoR = this->tipo->Interpretar(ctx, ctx2, ctx3);

    QString varName = idR->getValor().toString();
    std::string valueType = tipoR->getTipo().toStdString();
    std::cout<<"//declaracion parametros de vector "<<varName.toStdString()<<std::endl;
    //QVector<const Value> values;
    std::string c3dCode;
    QString temporal = "t"+QString::number(MiniResultado::x++);
    std::cout<<temporal.toStdString()<<" = H;"<<std::endl;
    QVector<int> dimensiones = {};
    for (int i = 0; i < this->Expr.size(); i++) {
        Resultado* exprR = this->Expr[i]->Interpretar(ctx, ctx2, ctx3);
        dimensiones.push_back(exprR->getValor().toInt());
        //std::cout<<"//valor dimension-> "<<exprR->getValor().toInt()<<std::endl;
    }
    int cont = 1;
    for (int var = 0; var < dimensiones.size(); ++var) {
        cont *= dimensiones[var];
    }
    for (int var = 0; var < cont; ++var) {
        c3dCode += "heap[(int)H] = 0;\n";
        c3dCode += "H = H + 1;\n";

    }
    c3dCode += "heap[(int)H] = -1;\n";
    c3dCode += "H = H + 1;\n";
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

    ctx3->addVariable(varName.toStdString(), valueType,dimensiones);
    int pos = ctx->getvariableplacer(varName.toStdString());
    std::cout<<"//declaramos matriz "<<varName.toStdString()<<std::endl;
    QString tmp = "t"+QString::fromStdString(std::to_string(MiniResultado::x++));
    std::cout<<tmp.toStdString()<<" = P + "<<pos<<";"<<std::endl;
    std::cout<<"stack[(int)"<<tmp.toStdString()<<"]= "<<temporal.toStdString()<<";"<<std::endl;
    std::cout<<"//_________fin declaracion matriz "<<varName.toStdString()<<std::endl;
    return nullptr;
}

QString NT_DeclMatriz::Graficar() {
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
