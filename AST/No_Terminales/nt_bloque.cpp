#include "nt_Bloque.h"
#include "nt_declvar.h"
#include"nt_declvar.h"

Bloque::Bloque(const QVector<AbstractExpr*>& instrucciones, AbstractExpr *decl, AbstractExpr *expr, AbstractExpr *aumento, bool is_while, AbstractExpr *elsebloque) : instrucciones(instrucciones), decl(decl), expr(expr), aumento(aumento), is_while(is_while), elsebloque(elsebloque)
{this->declaracionparametros={};this->asignacionparametros={};}

Resultado* Bloque::Interpretar(Environment* env,EnvironmentFunc* ctx2, EnvironmentVect* ctx3) {
    Environment *envv = new Environment(env);

    Resultado* temp = new Resultado(nullptr);


//ESTO ES EL BLOQUE PARA LAS FUNCIONES
    if (decl == nullptr && expr == nullptr && aumento == nullptr) {
       if (this->declaracionparametros.size() != 0)
       {
           for (int i = 0; i < this->declaracionparametros.size(); i++) {
               NT_DeclVar *t =dynamic_cast<NT_DeclVar*>( this->declaracionparametros[i]);
               //t->Expr = this->asignacionparametros[i];//lleva E al lote Expr en la declaracion para que no sea null
               temp = t->Interpretar(envv,ctx2,ctx3);
           }
       }//ESTA ES LA FUNCION SIN PARAMETROS
        for (int i = 0; i < this->instrucciones.size(); i++) {
            temp = this->instrucciones[i]->Interpretar(envv,ctx2,ctx3);

        }
    }




//ESTO ES UN WHILE Y UN FOR JUELAGRANPUTA JAJAJAJA
    else if (is_while){
        QString temporal = "";
        QVector<QString> ev = {};
        QVector<QString> ef = {};

        if(decl != nullptr)
        Resultado *declResult = decl->Interpretar(envv,ctx2,ctx3);//DECLARACION

        this->liniciodeciclo ="L"+QString::number(MiniResultado::L++);//GENERACION DE LINICIO DE CICLO
        this->lsalidadeciclo = "L"+QString::number(MiniResultado::L++);//GENERACION DE LSALIDA DE CICLO
        std::cout<<this->liniciodeciclo.toStdString()<<":"<<std::endl;//IMPRESION LINICIO

        Resultado *exprResult = expr->Interpretar(envv,ctx2,ctx3);//EXPRESION CONDICIONAL DEL FOR O DEL WHILE
        if(exprResult->miniResultado.temporales.size()!=0)
        {
             temporal = exprResult->miniResultado.temporales[0];
             ev.push_front( "L"+QString::number(MiniResultado::L++));
            ef.push_front( "L"+QString::number(MiniResultado::L++));
            std::cout<<"if("<<temporal.toStdString()<<") goto "<<ev[0].toStdString()<<";"<<std::endl;
            std::cout<<"goto "<<ef[0].toStdString()<<";"<<std::endl;
            std::cout<<ev[0].toStdString()<<":"<<std::endl;
        }
        else if(exprResult->miniResultado.EV.size() != 0 && exprResult->miniResultado.EF.size()!=0)
        {
            ev=exprResult->miniResultado.EV;
           ef=exprResult->miniResultado.EF;
           std::cout<<ev[0].toStdString()<<":"<<std::endl;

        }
        else
        {
            temporal = QString::number(exprResult->getValor().toBool());
            ev.push_front( "L"+QString::number(MiniResultado::L++));
           ef.push_front( "L"+QString::number(MiniResultado::L++));
           std::cout<<"if("<<temporal.toStdString()<<") goto "<<ev[0].toStdString()<<";"<<std::endl;
           std::cout<<"goto "<<ef[0].toStdString()<<";"<<std::endl;
           std::cout<<ev[0].toStdString()<<":"<<std::endl;
        }







            //C3D SENTENCIAS
        for (int i = 0; i < this->instrucciones.size(); i++)
        {
            Bloque* test = dynamic_cast<Bloque*>(this->instrucciones[i]);
            if (test)
            {
                test->liniciodeciclo= this->liniciodeciclo;
                test->lsalidadeciclo = this->lsalidadeciclo;
                temp = test->Interpretar(envv,ctx2,ctx3);
            }
            else
            {
            temp = this->instrucciones[i]->Interpretar(envv,ctx2,ctx3);
            if(temp!=nullptr)
                {
                    if(temp->getValor().toString().toStdString()=="break")// aca se va al Lsalida
                        {
                            env->updateCommonVariables(envv);
                            std::cout<<"goto "<<this->lsalidadeciclo.toStdString()<<";  //break en while"<<std::endl;
                        }
                    if(temp->getValor().toString().toStdString()=="continue"&&aumento != nullptr)//aca se va al Lincio
                        {
                            std::cout<<"goto "<<this->liniciodeciclo.toStdString()<<"; continue en for"<<std::endl;
                        }
                }
            }
        }
            if (aumento != nullptr)
            Resultado *aumentoResult = aumento->Interpretar(envv,ctx2,ctx3);//ACA SE ENCUENTRA EL AUMENTO QUE SE DA EN EL FOR PARTE DEL C3D INTERNO
            std::cout<<"goto "<<this->liniciodeciclo.toStdString()<<";"<<std::endl;

            for (int var = 0; var < ef.size(); ++var) {//IMPRESION DE ETIQUETAS DEL ELSE DEL C3D DE CONDICIONAL
            std::cout<<ef[var].toStdString()<<":"<<std::endl;
            }


            std::cout<<this->lsalidadeciclo.toStdString()<<":"<<std::endl;

    }


 //ESTO ES UN IF_____________________________________
    else
    {
        QString temporal = "";
        QVector<QString> ev = {};
        QVector<QString> ef = {};
        QString lsalida = "";
        Resultado *exprResult = expr->Interpretar(envv,ctx2,ctx3);

        if(exprResult->miniResultado.temporales.size()!=0)
        {
             temporal = exprResult->miniResultado.temporales[0];
             ev.push_front( "L"+QString::number(MiniResultado::L++));
            ef.push_front( "L"+QString::number(MiniResultado::L++));
            std::cout<<"if("<<temporal.toStdString()<<") goto "<<ev[0].toStdString()<<";"<<std::endl;
            std::cout<<"goto "<<ef[0].toStdString()<<";"<<std::endl;
            std::cout<<ev[0].toStdString()<<":"<<std::endl;
        }
        else if(exprResult->miniResultado.EV.size() != 0 && exprResult->miniResultado.EF.size()!=0)
        {
            ev=exprResult->miniResultado.EV;
           ef=exprResult->miniResultado.EF;
           std::cout<<ev[0].toStdString()<<":"<<std::endl;

        }
        else
        {
            temporal = QString::number(exprResult->getValor().toBool());
            ev.push_front( "L"+QString::number(MiniResultado::L++));
           ef.push_front( "L"+QString::number(MiniResultado::L++));
           std::cout<<"if("<<temporal.toStdString()<<") goto "<<ev[0].toStdString()<<";"<<std::endl;
           std::cout<<"goto "<<ef[0].toStdString()<<";"<<std::endl;
           std::cout<<ev[0].toStdString()<<":"<<std::endl;
        }
        //esto es el c3d sentencias


            for (int i = 0; i < this->instrucciones.size(); i++)
            {
                temp = this->instrucciones[i]->Interpretar(envv,ctx2,ctx3);
                if(temp!=nullptr)
                {
                if(temp->getValor().toString().toStdString()=="break")
                    {env->updateCommonVariables(envv);
                    //env->report();
                    //return new Resultado(QString::fromStdString("break"));
                    std::cout<<"goto "<<this->lsalidadeciclo.toStdString()<<";  //break en if"<<std::endl;
                    }
                if(temp->getValor().toString().toStdString()=="continue"&&aumento != nullptr)
                    {
                    env->updateCommonVariables(envv);
                    //env->report();
                    //return new Resultado(QString::fromStdString("continue"));
                    std::cout<<"goto "<<this->liniciodeciclo.toStdString()<<"; //continue en if"<<std::endl;

                    }
                }
            }
            lsalida = "L"+QString::number(MiniResultado::L++);
            std::cout<<"goto "<<lsalida.toStdString()<<";"<<"   //se va a lsalida de if"<<std::endl;

        //else

            for (int var = 0; var < ef.size(); ++var) {
            std::cout<<ef[var].toStdString()<<":"<<std::endl;
            }

        //c3d de else
            if(elsebloque != nullptr)
        {
            Resultado *aux = elsebloque->Interpretar(env,ctx2,ctx3);
            //return aux;

        }

           std::cout<<lsalida.toStdString()<<":"<<"   //lsalida de if"<<std::endl;



    }

    env->updateCommonVariables(envv);
    //env->report();
    //envv->report();


    return temp;
}

QString Bloque::Graficar() {
    std::stringstream  pPosicion, lPosicion,elseposicion;
    pPosicion <<(void*)this;
    QString temp = QString::fromStdString("n" + pPosicion.str()  +
                " [ label=\"BLOQUE\" fillcolor=springgreen];\n");


    for (int i = 0; i < this->instrucciones.size(); i ++){
        lPosicion.str(std::string());
        lPosicion.clear();
        lPosicion << (void*)this->instrucciones[i];

        temp +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                        + lPosicion.str()+ ";\n");
      temp += this->instrucciones[i]->Graficar();
      if(this->elsebloque != nullptr)
      {
          lPosicion.str(std::string());
          lPosicion.clear();
          lPosicion << (void*)this->elsebloque;

          temp +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                          + lPosicion.str()+ ";\n");
          temp+=this->elsebloque->Graficar();
      }
        /// es un return? es un break, es un continue, etc....
    }
    std::cout << "alv si esta vacio" << std::endl;
    return temp;
}
