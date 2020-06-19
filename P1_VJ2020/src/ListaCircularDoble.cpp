#include "ListaCircularDoble.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;
ListaCircularDoble::ListaCircularDoble(){
    cabeza=nullptr;
}

void ListaCircularDoble::InsertarCD(string IdTran, string IdAc, string vende, string compra, string depar, string empres, string fec, string time, string des){
    setlocale(LC_CTYPE,"Spanish");
    NodoCD* nuevo=new NodoCD(IdTran,IdAc,vende, compra, depar,empres,fec,time, des);
    if(cabeza==nullptr){
        cabeza=nuevo;
        cabeza->sig=cabeza;
    }else{
        NodoCD* aux=cabeza;
        while(aux->sig!=cabeza && aux->IdTransaccion.compare(nuevo->IdTransaccion)==1){
            aux=aux->sig;
        }
        if(aux->sig==cabeza){
            nuevo->sig=cabeza;
            nuevo->ant=aux;
            aux->sig=nuevo;
            cabeza->ant=nuevo;
        }else{
            NodoCD* pos3=aux->sig;
            nuevo->sig=pos3;
            nuevo->ant=aux;
            pos3->ant=nuevo;
            aux->sig=nuevo;
        }
    }

}
//---------------------------------------------Metodo mostrar-----------------------
void ListaCircularDoble::mostrar(){
    setlocale(LC_CTYPE,"Spanish");
   NodoCD *aux;
   aux = cabeza;
   while(aux->sig!=cabeza) {
      cout <<"ID"<< aux->IdTransaccion << " Nombre: ";
      aux = aux->sig;
   }
   cout << aux->IdTransaccion <<endl;
}

void ListaCircularDoble::TransCompra(string usuario){
    setlocale(LC_CTYPE,"Spanish");
    NodoCD *aux;
    aux = cabeza;
    if(cabeza->sig!=cabeza && cabeza!=nullptr){
        do{
            if(aux->Comprador==usuario){
                cout<<"ID: "<<aux->IdActivo<<" Nombre: "<<aux->IdTransaccion<<endl;
            }
            aux=aux->sig;
        }while(aux!=cabeza);
    }

}

void ListaCircularDoble::TransVende(string usuario){
    setlocale(LC_CTYPE,"Spanish");
    NodoCD *aux;
    aux = cabeza;
    if(cabeza->sig!=cabeza && cabeza!=nullptr){
        do{
            if(aux->Vendedor==usuario && aux->estadorenta==false){
                cout<<"ID: "<<aux->IdActivo<<"; Nombre: "<<aux->IdTransaccion<<endl;
            }
            aux=aux->sig;
        }while(aux!=cabeza);
    }
}

void ListaCircularDoble::Mcatalogo(string usuario){
    setlocale(LC_CTYPE,"Spanish");
    NodoCD *aux;
    aux = cabeza;
    if(cabeza!=nullptr){
        do{
            if(aux->Vendedor!=usuario && aux->estadorenta==true){
                cout<<"ID: "<<aux->IdActivo<<"; Nombre: "<<aux->IdTransaccion<<" Descripcion: "<<aux->descripcion<<endl;
            }
            aux=aux->sig;
        }while(aux!=cabeza);
    }
}

void ListaCircularDoble::RenCatalogo(string idac, string compra,string empresa,string depart){
    NodoCD* buscado=Buscar(idac);
    if(buscado!=nullptr){
            buscado->Comprador=compra;
            buscado->estadorenta=false;
            buscado->Fecha=empresa;
            buscado->TiempoRenta=depart;
    }
}

string ListaCircularDoble::vendedor(string id){
    NodoCD *aux;
    aux = cabeza;
    if(cabeza!=nullptr){
        do{
            if(aux->IdActivo==id){
                Nbuscado=aux;
                return aux->Vendedor;
            }
            aux=aux->sig;
        }while(aux!=cabeza);
    }
    return "";
}

string ListaCircularDoble::empresav(){
    return Nbuscado->Fecha;
}

string ListaCircularDoble::deparv(){
    return Nbuscado->TiempoRenta;
}

NodoCD* ListaCircularDoble::Buscar(string ID){
    NodoCD *aux;
    aux = cabeza;
    if(cabeza->sig!=cabeza && cabeza!=nullptr){
        do{
            if(aux->IdActivo==ID){
                return aux;
            }
            aux=aux->sig;
        }while(aux!=cabeza);
    }

    return NULL;
}


void ListaCircularDoble::OrdenarAs(){
    mostrar();
    cout<<endl;
    if(cabeza!=nullptr){
        if(cabeza->sig!=cabeza){
            NodoCD* cola=cabeza->ant;
                if(cabeza->sig!=cola){//3 a mas nodos
                       cout<<"Entro \n";
                }else{//solo hay 2 nodos
                    NodoCD* ultimo=cola;
                    cola=cabeza;
                    cabeza=ultimo;
                    cabeza->sig=cola;
                    cabeza->ant=cola;
                    cola->sig=cabeza;
                    cola->ant=cabeza;
                }
        }

    }else cout<<"La lista esa vacia"<<endl;
}

void ListaCircularDoble::OrdenarDes(){
     mostrar();
    cout<<endl;
    if(cabeza!=nullptr){
        if(cabeza->sig!=cabeza){

            NodoCD* cola=cabeza->ant;
                if(cabeza->sig!=cola){//3 a mas nodos
                    NodoCD* primero;
                    NodoCD* segundo;
                    NodoCD* siguiente;
                    NodoCD* anterior;
                    NodoCD* nuevaCabeza;
                        primero=cabeza;
                        segundo=cabeza->sig;
                        siguiente=segundo->sig;
                        anterior=cabeza->ant;
                        nuevaCabeza=cabeza->sig;

                           do{
                                if(segundo->IdTransaccion.compare(primero->IdTransaccion)==-1){
                                    segundo -> sig = primero;
                                    primero -> ant = segundo;
                                    segundo->ant = anterior;
                                    primero->sig = siguiente;
                                    siguiente->ant = primero;
                                    anterior->sig = segundo;
                                    segundo = primero->sig;
                                    siguiente = segundo->sig;
                                    anterior = primero->ant;
                                }else{
                                    primero=primero->sig;
                                    segundo=primero->sig;
                                    siguiente=segundo->sig;
                                    anterior=cabeza->ant;
                                }

                            }while(segundo!=nuevaCabeza);
                        cabeza=nuevaCabeza;
                        cout<<"\n------------------------------------------------------------------------------------------------------"<<endl;
                        mostrar();
                        cout<<"\n------------------------------------------------------------------------------------------------------"<<endl;
                        system("PAUSE");

                    //}while(cabeza!=cola);

                }else{//solo hay 2 nodos
                    NodoCD* ultimo=cola;
                    cola=cabeza;
                    cabeza=ultimo;
                    cabeza->sig=cola;
                    cabeza->ant=cola;
                    cola->sig=cabeza;
                    cola->ant=cabeza;
                }

        }
        cout<<"Termino \n";
        //system("PAUSE");
        mostrar();
    }else cout<<"La lista esa vacia"<<endl;
}
//----------------------------------------------------- R E P O R T E S--------------------------------------
void ListaCircularDoble::ReporteTransacciones(){
    string Cadena;
    NodoCD* aux=cabeza;
    int c=0;
    int c2=0;
    Cadena="{rank=same; \nNodo"+to_string(c)+"  [label= \" Transacción: "+aux->IdTransaccion+", \nActivo "+aux->IdActivo+", \nUsuario "+aux->Comprador+", \nTiempo: "+aux->TiempoRenta+"\" ]\n";
    while(aux->sig!=cabeza){
                        c2=c+1;
                        Cadena+="Nodo"+to_string(c)+" ->  Nodo"+to_string(c2)+" [color=blue] \n";
                        Cadena+="Nodo"+to_string(c2)+" ->  Nodo"+to_string(c)+" [color=blue] \n";
                        aux=aux->sig;
                        c++;
                        Cadena+="Nodo"+to_string(c)+"  [label= \" Transacción: "+aux->IdTransaccion+", \nActivo "+aux->IdActivo+", \nUsuario "+aux->Comprador+", \nTiempo: "+aux->TiempoRenta+"\" ]\n";                 // }
    }
    Cadena+="Nodo"+to_string(c)+" ->  Nodo0"+" [color=blue] \n";
    Cadena+="Nodo0 ->  Nodo"+to_string(c)+" [color=blue] \n";
    Cadena+=" }}";

    ReporteCD("Reporte Transaciones",Cadena);
}

void ListaCircularDoble::ReporteCD(string titulo, string texto){
    setlocale(LC_CTYPE,"Spanish");
    try{
        ofstream f;
        f.open("ReporteCircularDoblementeEnlazada.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = Lista;" <<endl;
                f<<"node [shape = rectangle fontname=\"Arial\" fontsize=\"10\"]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='blue'> <font point-size='20'> "<<titulo<<" </font></font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<texto;
        f.close();
        system("dot -Tpng ReporteCircularDoblementeEnlazada.dot -o ReporteCircularDoblementeEnlazada.png");//Convierte el dot en imagen
        system("ReporteCircularDoblementeEnlazada.png");//Abre la imagen
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}

//Inserta y elimina
