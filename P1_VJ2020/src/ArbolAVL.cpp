#include "ArbolAVL.h"
#include "Cubo.h"
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



void ArbolAVL::InsertarRaiz(string id, string nombre, string desripcion){
    if(Raiz==nullptr){
        Raiz=new nodoAVL(id,nombre,desripcion);
    }
}

nodoAVL* ArbolAVL::ReRaiz(){
    return Raiz;
}

void ArbolAVL::Insertar(string id, string nombre, string desripcion, nodoAVL* raiz){
    nodoAVL* nuevo= new nodoAVL(id,nombre,desripcion);
    nodoAVL* auxP=nullptr;
    Raiz=raiz;
    if(Raiz==nullptr){
        Raiz=nuevo;
    }else{
        auxP=nullptr;
        nodoAVL* tmp=Raiz;
        string p1, p2;
        while(tmp!=nullptr){
            auxP=tmp;
            if(nuevo->ID.compare(tmp->ID)==1) tmp=tmp->Der;
            else if(nuevo->ID.compare(tmp->ID)==-1)tmp=tmp->Izq;
        }

        nuevo->Padre=auxP;
        p1=nuevo->ID;
        p2=nuevo->Padre->ID;

        if(p1.compare(p2)==-1){
                nuevo->Padre->Izq =nuevo;
                Equilibrar(nuevo->Padre,IZQUIERDO,true);
        }else if(p1.compare(p2)==1){
            nuevo->Padre->Der =nuevo;
            Equilibrar(nuevo->Padre,DERECHO,true);
        }
    }
}

//--------------------------- EQUILIBRAR ---------------------
void ArbolAVL::Equilibrar(nodoAVL* nodo, int rama, bool nuevo){
    bool continuar = true;
    while(continuar && nodo){

        if(nuevo)
             if(rama == IZQUIERDO) nodo->fe--;
             else                  nodo->fe++;
        else
             if(rama == IZQUIERDO) nodo->fe++;
             else                  nodo->fe--;

        if(nodo->fe==0) continuar=false;
       if(nodo->fe == -2) {
         if(nodo->Izq->fe == 1) DobleDerecha(nodo);
         else SimpleDerecha(nodo);
         continuar = false;
      }
      else if(nodo->fe == 2) {
        if(nodo->Der->fe == -1) DobleIzquierda(nodo);
         else SimpleIzquierda(nodo);
         continuar = false;
      }

      if(nodo->Padre){
        if(nodo->Padre->Der == nodo) rama = DERECHO;
        else rama = IZQUIERDO;
      }
        nodo = nodo->Padre;
    }
}

//--------------------------- ROTACIONES ---------------------
void ArbolAVL::SimpleIzquierda(nodoAVL* hoja){
    nodoAVL* anterior=hoja->Padre;
    nodoAVL* nodorota=hoja;
    nodoAVL* sig=hoja->Der;
    nodoAVL* ultimo=sig->Izq;

    if(anterior){
        if(anterior->Der==hoja) anterior->Der=sig;
        else anterior->Izq=sig;
    }else Raiz=sig;

    nodorota->Der=ultimo;
    sig->Izq=nodorota;

    nodorota->Padre=sig;
    if(ultimo) ultimo->Padre=nodorota;
    sig->Padre=anterior;

    nodorota->fe=0;
    sig->fe=0;
}

void ArbolAVL::SimpleDerecha(nodoAVL* hoja){
    nodoAVL* anterior=hoja->Padre;
    nodoAVL* nodorota=hoja;
    nodoAVL* sig=hoja->Izq;
    nodoAVL* ultimo=sig->Der;

    if(anterior){
        if(anterior->Der==hoja) anterior->Der=sig;
        else anterior->Izq=sig;
    }else Raiz=sig;

    nodorota->Izq=ultimo;
    sig->Der=nodorota;

    nodorota->Padre=sig;
    if(ultimo) ultimo->Padre=nodorota;
    sig->Padre=anterior;

    nodorota->fe=0;
    sig->fe=0;
}

void ArbolAVL::DobleDerecha(nodoAVL* hoja){
    SimpleIzquierda(hoja->Izq);
    SimpleDerecha(hoja);
}

void ArbolAVL::DobleIzquierda(nodoAVL* hoja){
    SimpleDerecha(hoja->Der);
    SimpleIzquierda(hoja);
}


//---------------------------METODOS DE BUSQUEDA---------------------
bool ArbolAVL::Busca(string id){
    nodoAVL* buscado=BuscarR(id, Raiz);
    if(buscado!=nullptr) return true;
    return false;
}

nodoAVL* ArbolAVL::BuscarR(string id ,nodoAVL* hoja){
    if (Raiz==nullptr) return nullptr;
    else if(hoja->ID==id) return hoja;
    else if (hoja->ID<id) return BuscarR(id,hoja->Der);
    else if (hoja->ID>id) return BuscarR(id,hoja->Izq);
    else if (hoja==nullptr) return nullptr;
}
//---------------------------METODOS DE ACTIVO RENTADO---------------------
void ArbolAVL::RentarAc(string id,nodoAVL* raiz ){
    Raiz=raiz;
    nodoAVL* buscado=BuscarR(id, Raiz);
    if(buscado!=nullptr) buscado->disponibilidad=false;
    else cout<<"Este nodo no existe";
}

//---------------------------METODOS MODIFICAR DESCRIPCION---------------------
void ArbolAVL::ModificaDescripcion(string id, string des,nodoAVL* raiz){
    Raiz=raiz;
    nodoAVL* buscado=BuscarR(id, Raiz);
     if(buscado!=nullptr) buscado->descripcion=des;
    else cout<<"Este nodo no existe"<<endl;
}


//--------------------------- REPORTE ---------------------
void ArbolAVL::ReporteAVL(){
    setlocale(LC_CTYPE,"Spanish");
    cccaadenad2="";
    cccaadenad="";
    ReporRecurAVl(Raiz, "Nombre Usuario");
    string texto=cccaadenad2+"\n"+cccaadenad+"\n}";
    string titulo="Arbol";
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
        f.close();
        system("dot -Tpng ReporteAVL.dot -o ReporteAVL.png");//Convierte el dot en imagen
        system("ReporteAVL.png");//Abre la imagen
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}

string ArbolAVL::UnUsuario(nodoAVL* n, string usuario){
    cccaadenad2="";
    cccaadenad="";
    ReporRecurAVl(n, usuario);
    return cccaadenad2+"\n"+cccaadenad+"\n";
}

void ArbolAVL::ReporRecurAVl(nodoAVL* n, string usuario){
    if(n!=nullptr){
            if(cccaadenad==""){
                cccaadenad="N"+usuario+ "[label=\" Usuario: "+ usuario+"\"]; \n";
                cccaadenad2="N"+usuario+ " -> N"+n->ID+"[color=white]; \n";
            }
            ReporRecurAVl(n->Izq,"");
            if(n->disponibilidad==true){
                cccaadenad+=" N"+n->ID+" [label=\" ID: "+n->ID+" \nNombre: "+n->nombre+" \nDescripcion: "+n->descripcion+"\", color=green3, fontcolor=green3]; \n";
            }else{
                cccaadenad+=" N"+n->ID+" [label=\" ID: "+n->ID+" \nNombre: "+n->nombre+" \nDescripcion: "+n->descripcion+"\", color=deeppink2, fontcolor=deeppink2]; \n";
            }

            if(n->Izq!=nullptr){//crea apuntador a nodo izquierdo
                cccaadenad2+=" N"+n->ID+" -> N"+n->Izq->ID+";\n";
            }else if(n->Izq==nullptr && n->Der!=nullptr){
                cccaadenad2+=" N"+n->ID+" -> I"+n->ID+"[color=white]; \n";
                cccaadenad+=" I"+n->ID+" [label=\" Invis\", color=white, bgcolor=white, fontcolor=white]; \n";
            }

            if(n->Izq!=nullptr || n->Der!=nullptr){//Nodos invisibles
                cccaadenad2+=" N"+n->ID+" -> M"+n->ID+"[color=white]; \n";
                cccaadenad+=" M"+n->ID+" [label=\" Invis\", color=white, bgcolor=white, fontcolor=white]; \n";
            }

            if(n->Der!=nullptr){//crea apuntador a nodo derecho
                cccaadenad2+=" N"+n->ID+" -> N"+n->Der->ID+";\n";
            }else if(n->Izq!=nullptr && n->Der==nullptr){
                cccaadenad2+=" N"+n->ID+" -> D"+n->ID+"[color=white]; \n";
                cccaadenad+=" D"+n->ID+" [label=\" Invis\", color=white, bgcolor=white, fontcolor=white]; \n";
            }
            ReporRecurAVl(n->Der,"");
    }
}
