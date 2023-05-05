#include "nt_suma.h"

Resultado *NT_Suma::Interpretar(Environment *ctx,EnvironmentFunc *ctx2, EnvironmentVect* ctx3) {
    Resultado* izqR = this->Izquierda->Interpretar(ctx,ctx2,ctx3);
    Resultado* derR = this->Derecha->Interpretar(ctx,ctx2,ctx3);

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }

    QString izqTipo = izqR->getTipo();
    QString derTipo = derR->getTipo();

    QVariant izqValor = izqR->getValor();
    QVariant derValor = derR->getValor();
    QString aux = "";

    Resultado *resultado;

    // Integer + Integer
    if (izqTipo == "Integer" && derTipo == "Integer") {
        int sum = izqValor.toInt() + derValor.toInt();
        if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()==0 )
                std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toInt() <<"+"<<derValor.toInt()<<";"<<std::endl;
                else if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()!=0 )
                {
                    QString temp = derR->miniResultado.temporales[0];
                    std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toInt() <<"+"<<temp.toStdString()<<";"<<std::endl;
                }
                else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()==0 )
                {
                    QString temp = izqR->miniResultado.temporales[0];
                    std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<derValor.toInt()<<";"<<std::endl;
                    aux = temp;
                }
                else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()!=0 )
                {
                    QString temp = izqR->miniResultado.temporales[0];
                    QString temp2 = derR->miniResultado.temporales[0];
                    std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<temp2.toStdString()<<";"<<std::endl;
                }



                resultado = new Resultado(sum);
                QString generado = QString::fromStdString("t"+(std::to_string(MiniResultado::x)));

                resultado->miniResultado.temporales.push_front(generado);
                resultado->miniResultado.temporales.push_back(aux);
                MiniResultado::x++;



    }
    // Integer + Float, Float + Integer, Float + Float
    else if ((izqTipo == "Integer" && derTipo == "Float") || (izqTipo == "Float" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Float")) {
        float sum = izqValor.toFloat() + derValor.toFloat();
        if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()==0 )
                std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toFloat() <<"+"<<derValor.toFloat()<<";"<<std::endl;
                else if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()!=0 )
                {
                    QString temp = derR->miniResultado.temporales[0];
                    std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toFloat() <<"+"<<temp.toStdString()<<";"<<std::endl;
                }
                else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()==0 )
                {
                    QString temp = izqR->miniResultado.temporales[0];
                    std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<derValor.toFloat()<<";"<<std::endl;
                }
                else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()!=0 )
                {
                    QString temp = izqR->miniResultado.temporales[0];
                    QString temp2 = derR->miniResultado.temporales[0];
                    std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<temp2.toStdString()<<";"<<std::endl;
                }





                resultado = new Resultado(sum);
                QString generado = QString::fromStdString("t"+(std::to_string(MiniResultado::x)));

                resultado->miniResultado.temporales.push_front(generado);
                MiniResultado::x++;
    }
    // Integer + String, String + Integer, String + String, String + Float, String + Boolean, Float + String, Boolean + String
    else if (izqTipo == "String" || derTipo == "String") {

        QString sum = izqValor.toString() + derValor.toString();
        resultado = new Resultado(sum);

        if (izqTipo == "String" && derTipo == "String")
        {

            Resultado* r = izqR;
            QString temporal = "t"+QString::number(MiniResultado::x++);
            QString temporalretorno = "t"+QString::number(MiniResultado::x++);
            std::cout<<temporal.toStdString()<<"= P + "<<ctx->placer<<";"<<std::endl
                    <<"stack[(int)"<<temporal.toStdString()<<"] = "<<r->miniResultado.temporales[0].toStdString()<<";"<<std::endl
                    <<"P = P + "<<ctx->placer<<";"<<std::endl
                    <<"copiar();"<<std::endl
                    <<"P = P - "<<ctx->placer<<";"<<std::endl
                    <<temporalretorno.toStdString()<<"= P +"<<ctx->placer<<";"<<std::endl
                    <<temporalretorno.toStdString()<<"= stack[(int)"<<temporalretorno.toStdString()<<"];"<<std::endl;

             r = derR;
            QString temporal2 = "t"+QString::number(MiniResultado::x++);
            QString temporalretorno2 = "t"+QString::number(MiniResultado::x++);
            std::cout<<temporal2.toStdString()<<"= P + "<<ctx->placer<<";"<<std::endl
                    <<"stack[(int)"<<temporal2.toStdString()<<"] = "<<r->miniResultado.temporales[0].toStdString()<<";"<<std::endl
                    <<"P = P + "<<ctx->placer<<";"<<std::endl
                    <<"copiar();"<<std::endl
                    <<"P = P - "<<ctx->placer<<";"<<std::endl
                    <<temporalretorno2.toStdString()<<"= P +"<<ctx->placer<<";"<<std::endl
                    <<temporalretorno2.toStdString()<<"= stack[(int)"<<temporalretorno2.toStdString()<<"];"<<std::endl
            <<"heap[(int)H]=-1;"<<std::endl
            <<"H=H+1;"<<std::endl;
            resultado->miniResultado.temporales.push_front(temporalretorno);
        } else if (izqTipo == "String" &&  derR->miniResultado.temporales.size()==0)
        {
            Resultado* r = izqR;
            QString temporal = "t"+QString::number(MiniResultado::x++);
            QString temporalretorno = "t"+QString::number(MiniResultado::x++);
            std::cout<<temporal.toStdString()<<"= P + "<<ctx->placer<<";"<<std::endl
                    <<"stack[(int)"<<temporal.toStdString()<<"] = "<<r->miniResultado.temporales[0].toStdString()<<";"<<std::endl
                    <<"P = P + "<<ctx->placer<<";"<<std::endl
                    <<"copiar();"<<std::endl
                    <<"P = P - "<<ctx->placer<<";"<<std::endl
                    <<temporalretorno.toStdString()<<"= P +"<<ctx->placer<<";"<<std::endl
                    <<temporalretorno.toStdString()<<"= stack[(int)"<<temporalretorno.toStdString()<<"];"<<std::endl;

            std::string input_str = derValor.toString().toStdString();
            for (size_t i = 0; i < input_str.length(); ++i) {
                    char current_char = input_str[i];
                    int ascii_value = static_cast<int>(current_char);
                    std::cout<<"heap[(int)H]="<<ascii_value<<";"<<std::endl
                    <<"H=H+1;"<<std::endl;
                }
            std::cout<<"heap[(int)H]=-1;"<<std::endl
            <<"H=H+1;"<<std::endl;
            resultado->miniResultado.temporales.push_front(temporalretorno);
        }else if ( izqR->miniResultado.temporales.size()==0 && derTipo == "String")
        {

            Resultado* r = derR;
            QString inicio = "t"+QString::number(MiniResultado::x++);
            std::cout<<inicio.toStdString()<<"=H;"<<std::endl;
            std::string input_str = izqValor.toString().toStdString();
            for (size_t i = 0; i < input_str.length(); ++i) {
                    char current_char = input_str[i];
                    int ascii_value = static_cast<int>(current_char);
                    std::cout<<"heap[(int)H]="<<ascii_value<<";"<<std::endl
                    <<"H=H+1;"<<std::endl;
                }


            QString temporal = "t"+QString::number(MiniResultado::x++);
            QString temporalretorno = "t"+QString::number(MiniResultado::x++);
            std::cout<<temporal.toStdString()<<"= P + "<<ctx->placer<<";"<<std::endl
                    <<"stack[(int)"<<temporal.toStdString()<<"] = "<<r->miniResultado.temporales[0].toStdString()<<";"<<std::endl
                    <<"P = P + "<<ctx->placer<<";"<<std::endl
                    <<"copiar();"<<std::endl
                    <<"P = P - "<<ctx->placer<<";"<<std::endl
                    <<temporalretorno.toStdString()<<"= P +"<<ctx->placer<<";"<<std::endl
                    <<temporalretorno.toStdString()<<"= stack[(int)"<<temporalretorno.toStdString()<<"];"<<std::endl;


            std::cout<<"heap[(int)H]=-1;"<<std::endl
            <<"H=H+1;"<<std::endl;
            resultado->miniResultado.temporales.push_front(inicio);
        }





    }
    // Integer + Boolean, Boolean + Integer, Boolean + Float, Float + Boolean, Boolean + Boolean
    else if (izqTipo == "Boolean" || derTipo == "Boolean") {
        int sum = izqValor.toInt() + derValor.toInt();
        resultado = new Resultado(sum);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Suma::Graficar() {
    std::stringstream  pPosicion, dPosicion, iPosicion ;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->Derecha;
    iPosicion <<(void*)this->Izquierda;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"+\" fillcolor=cornflowerblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_Suma::NT_Suma(AbstractExpr *izquierda, AbstractExpr *derecha) : Izquierda(izquierda), Derecha(derecha) {}
