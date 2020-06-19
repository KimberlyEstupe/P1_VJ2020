#include "Cubo.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <clocale>
#include <cstring>
#include <sstream>
#include "ArbolAVL.h"
using namespace std;


Cubo::Cubo(){
    Cabeza=new NodoMM(0,0,"GUATE","USAC","ADMIN","ADMIN","ADMIN",NULL);
}

//======================================================================== * METODOS DE INSERTAR *===============================================================
void Cubo::Insertar(string persona, string con, string usario, string Empre, string Depa){
    NodoMM* NodoDepa = InsertX(Depa);
    NodoMM* NodoEmpre = InsertY(Empre);
    nodoAVL* navl=nullptr;
    NodoMM* newNodo=new NodoMM(NodoDepa->X,NodoEmpre->Y,Depa,Empre,persona,usario,con,navl);
    InsertNodY(newNodo, NodoDepa, NodoEmpre);
}

NodoMM* Cubo::InsertX(string Depa){
    setlocale(LC_CTYPE,"Spanish");
    NodoMM* aux=Cabeza;
        while(aux->Der!=nullptr && aux->Departamento!=Depa){
                aux=aux->Der;
        }
        if(aux->Der==nullptr && aux->Departamento!=Depa){
            NodoMM* nuevo=new NodoMM(aux->X+1,0,Depa,"","","","",NULL);
            aux->Der=nuevo;
            nuevo->Izq=aux;
            return nuevo;
        }else{return aux;}
}

NodoMM* Cubo::InsertY(string Empre){
    setlocale(LC_CTYPE,"Spanish");
    NodoMM* aux=Cabeza;

        while(aux->Abajo!=nullptr && aux->Empresa!=Empre){
                aux=aux->Abajo;
        }
        if(aux->Abajo==nullptr && aux->Empresa!=Empre){
            NodoMM* nuevo=new NodoMM(0,aux->Y+1,"",Empre,"","","",NULL);
            aux->Abajo=nuevo;
            nuevo->Arriba=aux;
            return nuevo;
        }else{return aux;}
}

void Cubo::InsertNodY(NodoMM* nuevo,NodoMM* NodoX, NodoMM* NodoY){
    NodoMM* aux=NodoY;

    while(aux->Der!=nullptr && aux->Der->X <= nuevo->X){
        aux=aux->Der;
    }
    if(aux->X==nuevo->X && aux->Y==nuevo->Y && aux->Empleado!=""){    //Insercion Eje z
                while(aux->Sig!=nullptr && aux->Usuario!=nuevo->Usuario){
                    aux=aux->Sig;
                }
                if(aux->Sig==nullptr && aux->Usuario!=nuevo->Usuario){
                    aux->Sig=nuevo;
                    nuevo->Ant=aux;
                }
    }else{
            if(aux->Der==nullptr){
                aux->Der=nuevo;
                nuevo->Izq=aux;
            }else{
                NodoMM* pos3=aux->Der;
                nuevo->Izq=aux;
                nuevo->Der=pos3;
                aux->Der=nuevo;
                pos3->Izq=nuevo;
            }
        InsertNodX(nuevo,NodoX);
    }
}

void Cubo::InsertNodX(NodoMM* nuevo, NodoMM* NodoX){
    NodoMM* aux=NodoX;

    while(aux->Abajo!=nullptr && aux->Abajo->Y <= nuevo->Y){
        aux=aux->Abajo;
    }
    if(aux->Abajo==nullptr){
            aux->Abajo=nuevo;
            nuevo->Arriba=aux;
    }else{
            NodoMM* pos3=aux->Abajo;
            nuevo->Arriba=aux;
            nuevo->Abajo=pos3;
            aux->Abajo=nuevo;
            pos3->Arriba=nuevo;
    }
}

void Cubo::activos(string id, string nombre, string desripcion){
    ArbolAVL avl;
    if(NodBusqueda->LActivos==nullptr && NodBusqueda->LActivos==NULL){
        NodBusqueda->LActivos=new nodoAVL(id,nombre,desripcion);
    }else{
        avl.Insertar(id,nombre,desripcion,NodBusqueda->LActivos);
        NodBusqueda->LActivos=avl.ReRaiz();
    }


}

void Cubo::ModiTrans(string nombre, string desripcion){
    ArbolAVL avl;
    avl.ModificaDescripcion(nombre,desripcion,NodBusqueda->LActivos);
}

//======================================================================== * METODOS DE BUSQUEDA *===============================================================
string Cubo::usuario(){
    return NodBusqueda->Usuario;
}

string Cubo::empresa(){
    return NodBusqueda->Empresa;
}

string Cubo::departamento(){
    return NodBusqueda->Departamento;
}

bool Cubo::BCABEZA(string usu, string depa, string contr, string empre){
    if(Cabeza->Usuario==usu && Cabeza->contra==contr && Cabeza->Departamento==depa && Cabeza->Empresa==empre){
            return true;
    }
    return false;
}

bool Cubo::Busca(string usu, string depa, string contr, string empre){
    if(Cabeza->Der!=nullptr){
        NodBusqueda=NULL;
        NodoMM* aux=Cabeza->Abajo;
        NodoMM* aux2=Cabeza->Abajo->Der;
        NodoMM* aux3=Cabeza->Abajo->Der;

        while(aux!=nullptr){
            while(aux2!=nullptr){
                    while(aux3!=nullptr){
                        //if(aux3->Usuario==usu){
                        if(aux3->Usuario==usu && aux3->contra==contr && aux3->Departamento==depa && aux3->Empresa==empre){
                            NodBusqueda=aux3;
                            return true;
                        }
                        aux3=aux3->Sig;
                    }
                aux2=aux2->Der;
                aux3=aux2;
            }
            aux=aux->Abajo;
            aux2=aux;
        }

    }return false;
}

NodoMM* Cubo::Busca2(string usu, string dep, string empre){
    if(Cabeza->Der!=nullptr){
        NodBusqueda=NULL;
        NodoMM* aux=Cabeza->Abajo;
        NodoMM* aux2=Cabeza->Abajo->Der;
        NodoMM* aux3=Cabeza->Abajo->Der;

        while(aux!=nullptr){
            while(aux2!=nullptr){
                    while(aux3!=nullptr){
                        //if(aux3->Usuario==usu){
                        if(aux3->Usuario==usu && aux3->Departamento==dep && aux3->Empresa==empre){
                            NodBusqueda=aux3;
                            return aux3;
                        }
                        aux3=aux3->Sig;
                    }
                aux2=aux2->Der;
                aux3=aux2;
            }
            aux=aux->Abajo;
            aux2=aux;
        }

    }return NULL;
}


void Cubo::RentarActivo(string id, string usu, string depa, string empre){
    ArbolAVL avl;
    if(Busca2(usu,depa,empre)){
        avl.RentarAc(id);
    }
}

//======================================================================== * REPORTE *===============================================================
void Cubo::ReporteAVL(){
    ArbolAVL avl;
    string texto=avl.UnUsuario(NodBusqueda->LActivos,NodBusqueda->Usuario);
    RRAVL(texto,"Reporte Usuario");
}

void Cubo::Reporteusuario(string usu, string depa, string empre){
    ArbolAVL avl;
    if(Busca2(usu,depa,empre)){
        string texto=avl.UnUsuario(NodBusqueda->LActivos,NodBusqueda->Usuario);
        RRAVL(texto,"Reporte Usuario");
    }
}

void Cubo::RRAVL(string texto, string titulo){
    setlocale(LC_CTYPE,"Spanish");
    try{
        ofstream f;
        f.open("ReporteAVL.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = Lista;" <<endl;
                f<<"node [shape = ellipse fontname=\"Arial\" fontsize=\"10\"]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='blue'> <font point-size='20'> "<<titulo<<" </font></font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<texto;
                f<<"}"<<endl;
        f.close();
        system("dot -Tpng ReporteAVL.dot -o ReporteAVL.png");//Convierte el dot en imagen
        system("ReporteAVL.png");//Abre la imagen
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}

void Cubo::ReposrteMM(){
    setlocale(LC_CTYPE,"Spanish");
    try{
        std::ofstream f;
        f.open("ReporteMatriz.dot");
        f<<"digraph G {" << endl;
                f<<"  rankdir = Lista;" <<endl;
                f<<"  node [shape = rectangle  fontname=\"Arial\"]" <<endl;
                f<<"  graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='#008B8B' point-size='20' fontname=\"Century Gothic\"> R E P O R T E   D E   E M P L E A D O S </font>>;"<<endl;
                //f<<"label = < M A T R I Z >;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<" " <<endl;
                f<<" " <<endl;

                //Grafica ejer X
                NodoMM *aux = Cabeza;
                NodoMM *aux2 = Cabeza;
                    f<<"  {rank=same "<<endl;
                    f<<"     NodoX"<<aux->X<<"  [label= \""<<aux->Empleado<<","<<aux->Usuario <<"\" , group="<<aux->X<<"]"<<endl;
                    while(aux->Der!=nullptr){
                        f<<"     NodoX"<<aux->X<<" ->  NodoX"<<aux->Der->X<<"[dir=both]"<<endl;
                        aux=aux->Der;
                        f<<"     NodoX"<<aux->X<<"  [label= \""<< aux->Departamento <<"\" , group="<<aux->X<<"]"<<endl;                  // }
                    }
                    f<<"  }" <<endl;
                    f<<" " <<endl;

                //Grafica Ejer Y
                aux = Cabeza;
                f<<"   NodoX"<<aux->Y<<" ->  NodoY"<<aux->Abajo->Y<<"[dir=both]"<<endl;
                aux=aux->Abajo;
                f<<"   NodoY"<<aux->Y<<"  [label= \""<< aux->Empresa<<"\" , group=0]"<<endl;
                while(aux->Abajo!=nullptr){
                        f<<"   NodoY"<<aux->Y<<" ->  NodoY"<<aux->Abajo->Y<<"[dir=both]"<<endl;
                        aux=aux->Abajo;
                        f<<"   NodoY"<<aux->Y<<"  [label= \""<< aux->Empresa<<"\" , group= 0]"<<endl;                  // }
                }
                f<<""<<endl;

                //Unir Nodos en eje Y
               aux=Cabeza->Abajo;
               if(aux->Der!=nullptr){

                   while(aux!=nullptr){
                       aux2=aux->Der;
                        f<<"  {rank=same "<<endl;
                       f<<"     NodoY"<<aux->Y<<" ->  Nodo"<<aux2->X<<aux2->Y<<" [color=blue3][dir=both]"<<endl;

/* *****************************************************NODOS Z*******************************************************************************************************/
                                        NodoMM *aux3 = aux2;
                                        string contenido="* "+aux2->Empleado+"("+aux2->Usuario+","+aux2->contra+")";
                                        while(aux3->Sig!=nullptr){
                                            aux3=aux3->Sig;
                                            contenido+=" \n* "+aux3->Empleado+"("+aux3->Usuario+","+aux3->contra+")";
                                        }
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */

                       f<<"     Nodo"<<aux2->X<<aux2->Y<<"  [label= \""<< contenido<<"\" , group="<<aux2->X<<"]"<<endl;


                           while(aux2->Der!=nullptr){
                                    f<<"     Nodo"<<aux2->X<<aux2->Y<<" ->  Nodo"<<aux2->Der->X<<aux2->Y<<" [color=blue3][dir=both]"<<endl;
                                    aux2=aux2->Der;

/* ****************************************************NODOS Z********************************************************************************************************/
                                    aux3 = aux2;
                                    contenido="* "+aux2->Empleado+"("+aux2->Usuario+","+aux2->contra+")";
                                        while(aux3->Sig!=nullptr){
                                            aux3=aux3->Sig;
                                            contenido+=" \n* "+aux3->Empleado+"("+aux3->Usuario+","+aux3->contra+")";
                                        }
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */
                                    f<<"     Nodo"<<aux2->X<<aux2->Y<<"  [label= \""<<contenido<<"\" , group="<<aux2->X<<"]"<<endl;                  // }
                            }

                        aux=aux->Abajo;
                        f<<"  }"<<endl;
                    }

                }
                f<<" " <<endl;

                //Unir Nodos en eje X
                aux=Cabeza->Der;
                if(aux->Der!=nullptr){
                    while(aux!=nullptr){
                        aux2=aux->Abajo;
                        f<<"   NodoX"<<aux->X<<" ->  Nodo"<<aux2->X<<aux2->Y<<" [color=darkslategrey][dir=both]"<<endl;
                        while(aux2->Abajo!=nullptr){
                                    f<<"   Nodo"<<aux2->X<<aux2->Y<<" ->  Nodo"<<aux2->Abajo->X<<aux2->Abajo->Y<<" [color=darkslategrey][dir=both]"<<endl;
                                    aux2=aux2->Abajo;                 // }
                        }
                        aux=aux->Der;
                    }
                }




                f<<"}" <<endl;
        f.close();
        system("dot -Tpng ReporteMatriz.dot -o ReporteMatriz.png");
        system("ReporteMatriz.png");
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
        system("ReporteMatriz.dot");
    }
}
