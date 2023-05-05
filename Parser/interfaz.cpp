#include "interfaz.h"
#include "parser.hpp"
#include "lex.yy.c"

QString Clase3::Interfaz::Analaizar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();
    //restart
    MiniResultado::x = 0;
    MiniResultado::L = 0;
    QString t1 = "t"+QString::number(MiniResultado::x++);
    QString t2 = "t"+QString::number(MiniResultado::x++);
    QString L1 = "L"+QString::number(MiniResultado::L++);
    QString L2 = "L"+QString::number(MiniResultado::L++);
    std::cout << "#include <stdio.h> "<< std::endl
                      << "float stack[100000];"<< std::endl
                      << "float heap[100000];"<< std::endl
                      << "float P;"<< std::endl
                      << "float H;"<< std::endl
    << "void imprimir () {"<< std::endl
    << t1.toStdString()<<" = stack[(int)P];"<< std::endl
    << t2.toStdString()<<" = heap[(int)"<<t1.toStdString()<<"];"<< std::endl
    << L1.toStdString()<<":"<< std::endl
    << "if ("<<t2.toStdString()<<" ==-1) goto "<< L2.toStdString()<<";"<< std::endl
    << "printf(\"%c\", (int)"<<t2.toStdString()<<");"<< std::endl
    << t1.toStdString()<<" = "<<t1.toStdString()<<" + 1;"<< std::endl
    << t2.toStdString()<<" = heap[(int)"<<t1.toStdString()<<"];"<< std::endl
    << "goto "<< L1.toStdString()<<";"<< std::endl
    << L2.toStdString()<<":"<< std::endl
    << "return;}"<< std::endl;
    QString contador = "t"+QString::number(MiniResultado::x++);
    QString tecero = "t"+QString::number(MiniResultado::x++);
     QString teuno = "t"+QString::number(MiniResultado::x++);
     QString Lcero = "L"+QString::number(MiniResultado::L++);
     QString Luno = "L"+QString::number(MiniResultado::L++);
    std::cout<<"void size() {\n"<<std::endl
            <<contador.toStdString()<<" = 0;"<<std::endl
            <<tecero.toStdString()<<" = stack[(int)P];"<<std::endl
            <<teuno.toStdString()<<" = heap[(int)"<<tecero.toStdString()<<"];"<<std::endl
            <<Lcero.toStdString()<<":"<<std::endl
            <<"if ("<<teuno.toStdString()<<"==-1) goto "<<Luno.toStdString()<<";"<<std::endl
            //<<contador.toStdString()<<" = "<<contador.toStdString()<<" +"<<teuno.toStdString()<<";"<<std::endl
            <<contador.toStdString()<<" = "<<contador.toStdString()<<" +1;"<<std::endl
            <<tecero.toStdString()<<" = (int)"<<tecero.toStdString()<<" + 1;"<<std::endl
            <<teuno.toStdString()<<" = heap[(int)"<<tecero.toStdString()<<"];"<<std::endl
            <<"goto "<< Lcero.toStdString()<<";"<<std::endl
            <<Luno.toStdString()<<":"<<std::endl
            <<"stack[(int)P]="<<contador.toStdString()<<";"<<std::endl
            <<"return;}"<<std::endl;

    QString mcontador = "t"+QString::number(MiniResultado::x++);
    QString mcontadorsuma = "t"+QString::number(MiniResultado::x++);
    QString mtecero = "t"+QString::number(MiniResultado::x++);
     QString mteuno = "t"+QString::number(MiniResultado::x++);
     QString mLcero = "L"+QString::number(MiniResultado::L++);
     QString mLuno = "L"+QString::number(MiniResultado::L++);
    std::cout<<"void mean() {\n"<<std::endl
            <<mcontador.toStdString()<<" = 0;"<<std::endl
              <<mcontadorsuma.toStdString()<<" = 0;"<<std::endl
            <<mtecero.toStdString()<<" = stack[(int)P];"<<std::endl
            <<mteuno.toStdString()<<" = heap[(int)"<<mtecero.toStdString()<<"];"<<std::endl
            <<mLcero.toStdString()<<":"<<std::endl
            <<"if ("<<mteuno.toStdString()<<"==-1) goto "<<mLuno.toStdString()<<";"<<std::endl
            <<mcontadorsuma.toStdString()<<" = "<<mcontadorsuma.toStdString()<<" +"<<mteuno.toStdString()<<";"<<std::endl
            <<mcontador.toStdString()<<" = "<<mcontador.toStdString()<<" +1;"<<std::endl
            <<mtecero.toStdString()<<" = (int)"<<mtecero.toStdString()<<" + 1;"<<std::endl
            <<mteuno.toStdString()<<" = heap[(int)"<<mtecero.toStdString()<<"];"<<std::endl
            <<"goto "<< mLcero.toStdString()<<";"<<std::endl
            <<mLuno.toStdString()<<":"<<std::endl
           <<mcontadorsuma.toStdString()<<" = "<<mcontadorsuma.toStdString()<<" / "<<mcontador.toStdString()<<";"<<std::endl
            <<"stack[(int)P]="<<mcontadorsuma.toStdString()<<";"<<std::endl
            <<"return;}"<<std::endl;








    Environment *env = new Environment(nullptr);
    EnvironmentFunc *env2 = new EnvironmentFunc(nullptr);
    EnvironmentVect *env3 = new EnvironmentVect(nullptr);
    for (int i = 0; i < this->raiz.size(); i ++){

      Resultado* temp = this->raiz[i]->Interpretar(env, env2, env3);
        /// es un return? es un break, es un continue, etc....
    }
    int meta = MiniResultado::x -1;
        std::cout << "float ";
        for (int var = 0; var < meta; ++var) {
            std::cout << "t" << var<< ", ";
        }
        std::cout << "t" << meta<< ";"<<std::endl;



    std::cout << "ACA ESTA LA ENV DEL MAIN: " << this->raiz.size() << std::endl;
    env->report();
    return "salida";

    return 0;
}

QString Clase3::Interfaz::Ejecutar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();


    std::stringstream  pPosicion, lPosicion;
    pPosicion <<(void*)this;
    QString temp = QString::fromStdString("n" + pPosicion.str()  +
                " [ label=\"MAIN\" fillcolor=springgreen];\n");


    for (int i = 0; i < this->raiz.size(); i ++){
        lPosicion.str(std::string());
        lPosicion.clear();
        lPosicion << (void*)this->raiz[i];

        temp +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                        + lPosicion.str()+ ";\n");
      temp += this->raiz[i]->Graficar();
        /// es un return? es un break, es un continue, etc....
    }
    std::cout << "alv si esta vacio" << std::endl;
    return temp;

}

Clase3::Interfaz::Interfaz() {
    yylex_init(&this->lexer);
    this->loc = new yy::location();
    this->Parser = new yy::Parser(lexer, *loc, *this);
    //this->raiz = QVector<AbstractExpr*>();
}

Clase3::Interfaz::~Interfaz() {
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
}
