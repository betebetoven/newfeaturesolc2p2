#include "t_string.h"


Resultado *T_String::Interpretar(Environment *ctx,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
//    auto  StringTipo = ctx->tabla_tipos->getTipo(QString("String"));
     QString trimmedStr = this->str.mid(1, this->str.length() - 2);
     std::cout<<"//"<<trimmedStr.toStdString()<<std::endl;
     QString temporal = "";
     QString c3dCode = "";
    for (int i = 0; i < trimmedStr.length(); ++i) {
             // Get the ASCII value of the character
             int asciiValue = static_cast<int>(trimmedStr[i].toLatin1());

             if (i == 0) {
                 temporal = "t"+QString::number(MiniResultado::x++);
                 c3dCode += temporal +" = H;\n";

             }

             c3dCode += "heap[(int)H] = " + QString::number(asciiValue) + ";\n";
             c3dCode += "H = H + 1;\n";
         }
        c3dCode += "heap[(int)H] = -1;\n";
        c3dCode += "H = H + 1;\n";
        std::cout << c3dCode.toStdString()<<std::endl;


     Resultado* r = new Resultado(trimmedStr);
     r->miniResultado.temporales.push_front(temporal);
     std::cout<<"// SUBE COMO______________ "<<r->getTipo().toStdString()<<std::endl;
    return r;
}

QString T_String::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
    " [ label=\"T STR: " + this->str.toStdString().substr(1,this->str.size()-2) +
    "\"   fillcolor=\"#004376\"];\n");
}

T_String::T_String(QString str) {
    this->str = str;
}
