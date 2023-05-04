#include "nt_imprimir.h"
#include <fstream>

Resultado *NT_Imprimir::Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Resultado *aux;

    for (int var = 0; var < this->lista_expr.size(); ++var) {
    Resultado* r = this->lista_expr[var]->Interpretar(ctx, ctx2,ctx3);
    aux = r;
    if(r->getTipo()=="String")
    {
        QString temporal = r->miniResultado.temporales[0];
        QString tposicion ="t"+QString::number(MiniResultado::x++);
        std::cout<<tposicion.toStdString()<<" = P + "<<ctx->placer<<";"<<std::endl;
        std::cout<<"stack[(int)"<<tposicion.toStdString()<<"] = "<<temporal.toStdString()<<";"<<std::endl;
        std::cout<<"P = P +"<<ctx->placer<<";"<<std::endl
                <<"imprimir();"<<std::endl
               <<"P = P -"<<ctx->placer<<";"<<std::endl;


    }
    else if(r->miniResultado.temporales.size()!=0)
    {
        QString temporal = r->miniResultado.temporales[0];
        if(r->getTipo()=="Integer")
            std::cout<<"printf(\"%d\", (int)"<<temporal.toStdString()<<");"<<std::endl;
        else if(r->getTipo()=="Float")
            std::cout<<"printf(\"%f\", "<<temporal.toStdString()<<");"<<std::endl;
        else if(r->getTipo()=="Boolean")
            std::cout<<"printf(\"%d\", "<<temporal.toStdString()<<");"<<std::endl;
    }
    else
    {
        std::string temporal = r->getValor().toString().toStdString() + "\n";
        if(r->getTipo()=="Integer")
            std::cout<<"printf(\"%d\", (int)"<<temporal<<");"<<std::endl;
        else if(r->getTipo()=="Float")
            std::cout<<"printf(\"%f\", "<<temporal<<");"<<std::endl;
        else if(r->getTipo()=="Boolean")
            std::cout<<"printf(\"%d\", "<<temporal<<");"<<std::endl;
    }






}
    std::cout<<"printf(\"%c\", (int)10);"<<std::endl
            <<"printf(\"%c\", (int)13);"<<std::endl;

    //std::cout<<r->getValor().toString().toStdString()<<std::endl;
     std::string output = aux->getValor().toString().toStdString() + "\n";
        std::cout <<"//imprime: "<< output;
        std::ofstream outFile("C:\\Users\\alber\\OneDrive\\Documentos\\untitled\\AST\\No_Terminales\\consola.txt", std::ios_base::app);
            if (outFile.is_open()) {
                outFile << output;
                outFile.close();
            } else {
                std::cerr << "Unable to open file 'consola.txt'\n";
            }



    return aux;
}

QString NT_Imprimir::Graficar() {
    std::stringstream pPosicion, lPosicion;
    pPosicion << (void *) this;
    lPosicion << (void *) this->lista_expr[0];


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
                                          " [ label=\"PRINTF\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + "1" +
                                   " [ label=\"(\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                                   + pPosicion.str() + "1" + ";\n");

    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                                   + lPosicion.str() + ";\n");
    nodo += this->lista_expr[0]->Graficar();

    nodo += QString::fromStdString("n" + pPosicion.str() + "2" +
                                   " [ label=\")\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                                   + pPosicion.str() + "2" + ";\n");

    return nodo;

}

NT_Imprimir::NT_Imprimir(const QVector<AbstractExpr*>&nodo):lista_expr(nodo) {

}

