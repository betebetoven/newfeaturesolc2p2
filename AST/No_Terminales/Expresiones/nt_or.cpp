#include "NT_Or.h"

Resultado *NT_Or::Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Resultado* izqR = this->Izquierda->Interpretar(ctx,ctx2,ctx3);
    QString izqTipo = izqR->getTipo();
    QVariant izqValor = izqR->getValor();
    QVector<QString> ev = izqR->miniResultado.EV;
    QVector<QString> ef = izqR->miniResultado.EF;
    for(int i = 0; i <ef.size();i++)
    {
        std::cout<<ef[i].toStdString()<<":"<<std::endl;
    }
    Resultado* derR = this->Derecha->Interpretar(ctx,ctx2,ctx3);
    QString derTipo = derR->getTipo();
    QVariant derValor = derR->getValor();
    QVector<QString> evd = derR->miniResultado.EV;
    QVector<QString> efd = derR->miniResultado.EF;

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }

    Resultado *resultado;

    // Boolean OR Boolean
    if (izqTipo == "Boolean" && derTipo == "Boolean") {
        bool orResult = izqValor.toBool() || derValor.toBool();
        resultado = new Resultado(orResult);
        resultado->miniResultado.EV =ev+ evd;
        resultado->miniResultado.EF = efd;
    }
    else     if (izqTipo == "Boolean" && derTipo == "Integer") {
        bool orResult = izqValor.toBool() || derValor.toInt();
        resultado = new Resultado(orResult);
        resultado->miniResultado.EV =ev+ evd;
        resultado->miniResultado.EF = efd;
    }
    else     if (izqTipo == "Integer" && derTipo == "Boolean") {
        bool orResult = izqValor.toInt() || derValor.toBool();
        resultado = new Resultado(orResult);
        resultado->miniResultado.EV =ev+ evd;
        resultado->miniResultado.EF = efd;
    }
    else     if (izqTipo == "Integer" && derTipo == "Integer") {
        bool orResult = izqValor.toInt() || derValor.toInt();
        resultado = new Resultado(orResult);
        resultado->miniResultado.EV =ev+ evd;
        resultado->miniResultado.EF = efd;
    }

    resultado->miniResultado.EV =ev + evd;
    resultado->miniResultado.EF = efd;
    for (int var = 0; var < resultado->miniResultado.EV.size(); ++var) {
        std::cout<<"// si sube la etiqueta "<<resultado->miniResultado.EV[var].toStdString()<<std::endl;
    }
    return resultado;
}


QString NT_Or::Graficar() {
    std::stringstream pPosicion, dPosicion, iPosicion ;
    pPosicion << (void*)this;
    dPosicion << (void*)this->Derecha;
    iPosicion << (void*)this->Izquierda;
    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"OR\" fillcolor=cornflowerblue];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo += QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_Or::NT_Or(AbstractExpr* izquierda, AbstractExpr* derecha) : Izquierda(izquierda), Derecha(derecha) {}
