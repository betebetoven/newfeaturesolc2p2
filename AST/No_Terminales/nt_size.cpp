#include "nt_size.h"
#include <fstream>

NT_Size::NT_Size(AbstractExpr* id, int option)
    : id(id), option(option) {}

Resultado* NT_Size::Interpretar(Environment *ctx, EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {

    QString nombre;
    if(this->option == 1)
        nombre = "size";
    if(this->option == 2)
        nombre = "mean";
    if(this->option==3)
        nombre = "mediana";

    Resultado* r = this->id->Interpretar(ctx, ctx2, ctx3);
    QString temporal = "t"+QString::number(MiniResultado::x++);
    QString temporalretorno = "t"+QString::number(MiniResultado::x++);
    std::cout<<temporal.toStdString()<<"= P + "<<ctx->placer<<";"<<std::endl
            <<"stack[(int)"<<temporal.toStdString()<<"] = "<<r->miniResultado.temporales[0].toStdString()<<";"<<std::endl
            <<"P = P + "<<ctx->placer<<";"<<std::endl
            <<nombre.toStdString()<<"();"<<std::endl
            <<"P = P - "<<ctx->placer<<";"<<std::endl
            <<temporalretorno.toStdString()<<"= P +"<<ctx->placer<<";"<<std::endl
            <<temporalretorno.toStdString()<<"= stack[(int)"<<temporalretorno.toStdString()<<"];"<<std::endl;

    Resultado* nuevo = new Resultado(0);
    nuevo->miniResultado.temporales.push_front(temporalretorno);

    // ... The rest of the code remains the same

    return nuevo;
}

QString NT_Size::Graficar() {
    return "";
}
