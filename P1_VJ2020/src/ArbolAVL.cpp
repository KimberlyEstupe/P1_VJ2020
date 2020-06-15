#include "ArbolAVL.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <clocale>
#include <cstring>
#include <sstream>

using namespace std;
//https://www.youtube.com/watch?v=_z4xMj6C2yw
string cccaadenad2="";
string cccaadenad="";
ArbolAVL::ArbolAVL(){
    Raiz=nullptr;
}

void ArbolAVL::Insertar(string id, string nombre, string desripcion){
    nodoAVL* nuevo= new nodoAVL(id,nombre,desripcion);
    nodoAVL* auxP=nullptr;
    if(Raiz==nullptr){
        Raiz=nuevo;
    }else{
        auxP=nullptr;
        nodoAVL* tmp=Raiz;
        string p1, p2;
        while(tmp!=nullptr){
            auxP=tmp;
            p1=nuevo->ID;
            p2=tmp->ID;
            if(p1.compare(p2)==1) tmp=tmp->Der;
            else if(p1.compare(p2)==-1)tmp=tmp->Izq;
        }

        nuevo->Padre=auxP;
        p1=nuevo->ID;
        p2=auxP->ID;

        if(p1.compare(p2)==-1) auxP->Izq =nuevo;
        else if(p1.compare(p2)==1) auxP->Der =nuevo;
    }
}

//--------------------------- ROTACIONES ---------------------
nodoAVL* ArbolAVL::SimpleIzquierda(nodoAVL* hoja){
    return NULL;
}

//---------------------------METODOS DE BUSQUEDA---------------------
void ArbolAVL::Busca(string id){
    BuscarR(id, Raiz);
}

nodoAVL* ArbolAVL::BuscarR(string id ,nodoAVL* hoja){
    if (Raiz==nullptr) return NULL;
    else if(hoja->ID==id) return hoja;
    else if (hoja->ID<id) return BuscarR(id,hoja->Der);
    else if (hoja->ID>id) return BuscarR(id,hoja->Izq);
}

//--------------------------- REPORTE ---------------------
void ArbolAVL::ReporteAVL(){
    setlocale(LC_CTYPE,"Spanish");
    cccaadenad2="";
    cccaadenad="";
    ReporRecurAVl(Raiz);
    string texto=cccaadenad2+"\n"+cccaadenad+"\n}";
    string titulo="Arbol";
    try{
        ofstream f;
        f.open("ReporteAVL.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = Lista;" <<endl;
                f<<"node [shape = rectangle fontname=\"Arial\" fontsize=\"10\"]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='blue'> <font point-size='20'> "<<titulo<<" </font></font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<texto;
        f.close();
        system("dot -Tpng ReporteAVL.dot -o ReporteAVL.png");//Convierte el dot en imagen
        system("ReporteAVL.png");//Abre la imagen
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}

void ArbolAVL::ReporRecurAVl(nodoAVL* n){
    if(n!=nullptr){
            ReporRecurAVl(n->Izq);
            cccaadenad+=" N"+n->ID+" [label=\" "+n->ID+"\"] \n";

            if(n->Izq!=nullptr){//crea apuntador a nodo izquierdo
                cccaadenad2+=" N"+n->ID+" -> N"+n->Izq->ID+"\n";
            }else if(n->Izq==nullptr && n->Der!=nullptr){
                cccaadenad2+=" N"+n->ID+" -> I"+n->ID+"[color=white] \n";
                cccaadenad+=" I"+n->ID+" [label=\" Invis\", color=white, bgcolor=white, fontcolor=white]; \n";
            }

            if(n->Izq!=nullptr || n->Der!=nullptr){//Nodos invisibles
                cccaadenad2+=" N"+n->ID+" -> M"+n->ID+"[color=white] \n";
                cccaadenad+=" M"+n->ID+" [label=\" Invis\", color=white, bgcolor=white, fontcolor=white]; \n";
            }

            if(n->Der!=nullptr){//crea apuntador a nodo derecho
                cccaadenad2+=" N"+n->ID+" -> N"+n->Der->ID+"\n";
            }else if(n->Izq!=nullptr && n->Der==nullptr){
                cccaadenad2+=" N"+n->ID+" -> D"+n->ID+"[color=white] \n";
                cccaadenad+=" D"+n->ID+" [label=\" Invis\", color=white, bgcolor=white, fontcolor=white]; \n";
            }
            ReporRecurAVl(n->Der);
    }
}
