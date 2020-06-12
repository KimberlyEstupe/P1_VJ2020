#include "ListaCircularDoble.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <clocale>
#include <sstream>
#include <string>

using namespace std;
ListaCircularDoble::ListaCircularDoble()
{
    cabeza=nullptr;
}

void ListaCircularDoble::InsertarCD(string IdTran, string IdAc, string vende, string compra, string depar, string empres, string fec, string time){
    setlocale(LC_CTYPE,"Spanish");
    NodoCD* nuevo=new NodoCD(IdTran,IdAc,vende, compra, depar,empres,fec,time);
    if(cabeza==nullptr){
        cabeza=nuevo;
        cabeza->sig=cabeza;
    }else{
        NodoCD* aux=cabeza;
        while(aux->sig!=cabeza && aux->IdTransaccion<IdTran){
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

void ListaCircularDoble::mostrar(){
    setlocale(LC_CTYPE,"Spanish");
   NodoCD *aux;
   aux = cabeza;
   while(aux->sig!=cabeza) {
      cout << aux->IdTransaccion << "-> ";
      aux = aux->sig;
   }
   cout << aux->IdTransaccion <<endl;
}

void ListaCircularDoble::OrdenarAs(){
    if(cabeza->ant->IdTransaccion<cabeza->IdTransaccion){
        cout<<"En el if"<<endl;
    }
    mostrar();
}

void ListaCircularDoble::OrdenarDes(){
    if(cabeza->ant->IdTransaccion >cabeza->IdTransaccion){
        cout<<"Des"<<endl;
    }
    mostrar();
}

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
