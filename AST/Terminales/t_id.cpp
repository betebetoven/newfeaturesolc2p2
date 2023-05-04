#include "t_id.h"
#include <sstream>

struct ResultadoVisitor {
    template<typename T>
    Resultado* operator()(const T& value) const {
        return new Resultado(value);
    }

    Resultado* operator()(const std::string& value) const {
        return new Resultado(QString::fromStdString(value));
    }
};

Resultado* T_ID::Interpretar(Environment* ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    std::string id_str = this->id.toStdString();
    std::cout<<"// obtenemos valor de "<< id_str<<std::endl;
    // Retrieve the variable content from the environment
    auto content = ctx->getVariableContent(id_str);
    std::string type_name = typeid(content).name();
    std::string vartype = ctx->getVariableType(id_str);
    int placer = ctx->getvariableplacer(id_str);

    // Create a new Resultado object with the content of the variable
    //Resultado* resultado = std::visit(ResultadoVisitor{}, content);
    Resultado* resultado;
    if (vartype == "String") {
        QString enter = "0";
        std::cout<<"//SI TRANSFORMA RESULTADO"<<std::endl;
        resultado = new Resultado(enter);
    } else if (vartype == "Integer") {
        resultado = new Resultado(0);
    } else if (vartype == "Float") {
        resultado = new Resultado(static_cast<float>(1.1));
    } else if (vartype == "Boolean") {
        resultado = new Resultado(false);
    }






    if(this->lista_expr.size() ==0)
    {
    std::cout<<"t"<<MiniResultado::x<<" =P + "<<placer<<";"<<std::endl;
        MiniResultado::x++;
        std::cout<<"t"<<MiniResultado::x<<" = stack[(int)t"<<MiniResultado::x-1<<"];"<<std::endl;
        QString generado = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
        resultado->miniResultado.temporales.push_front(generado);
        MiniResultado::x++;
        std::cout<<"//__________t id sube como"<<resultado->getTipo().toStdString()<<std::endl;
    }
    if(this->lista_expr.size() ==1)
    {
        QString tposicion = "t"+QString::number(MiniResultado::x++);
        QString tstack = "t"+QString::number(MiniResultado::x++);
        QString tindex = "t"+QString::number(MiniResultado::x++);
        QString theap = "t"+QString::number(MiniResultado::x++);
        QString temporaldeE= "";
        Resultado* x = this->lista_expr[0]->Interpretar(ctx,ctx2,ctx3);
        if(x->miniResultado.temporales.size()!=0)
            temporaldeE = x->miniResultado.temporales[0];
        else
        //t = p+0 t = stack[t]
        std::cout<<tposicion.toStdString()<<" =P + "<<placer<<";"<<std::endl;
        std::cout<<tstack.toStdString()<<" = stack[(int)"<<tposicion.toStdString()<<"];"<<std::endl;
        //t = t + tE      t = heap[t]
        if(x->miniResultado.temporales.size()!=0)
        {
            temporaldeE = x->miniResultado.temporales[0];
            std::cout<<tindex.toStdString()<<" = "<<tstack.toStdString()<<" + "<<temporaldeE.toStdString()<<";"<<std::endl;
            std::cout<<theap.toStdString()<<" = heap[(int)"<<tindex.toStdString()<<"];"<<std::endl;
        }
        else
        {
            std::cout<<tindex.toStdString()<<" = "<<tstack.toStdString()<<" + "<<x->getValor().toInt()<<";"<<std::endl;
            std::cout<<theap.toStdString()<<" = heap[(int)"<<tindex.toStdString()<<"];"<<std::endl;
        }



        resultado->miniResultado.temporales.push_front(theap);



            std::cout<<"//__________ "<<std::endl;


    }


    return resultado;
}

QString T_ID::Graficar() {
    std::stringstream pPosicion;
    pPosicion << (void*)this;

    return QString::fromStdString("n" + pPosicion.str() +
                                   " [ label=\"T ID" + this->id.toStdString() +
                                   "\"   fillcolor=\"#12342c\"];\n");
}
//const QVector<AbstractExpr*>&nodo
T_ID::T_ID(QString id) {
    //std::cout << "crea el T ID" << std::endl;
    this->id = id;
    this->lista_expr = {};
}


T_ID::T_ID(QString id,const QVector<AbstractExpr*>&nodo): id(id),lista_expr(nodo) {

}






