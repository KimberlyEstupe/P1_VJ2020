#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <string>
using namespace std;

class nodoAVL{
private:
    string ID;
    string descripcion;
    string nombre;
    bool disponibilidad;
    int fe;
    nodoAVL* Padre;
    nodoAVL* Izq;
    nodoAVL* Der;
    nodoAVL(string id, string name, string descrip){
        ID=id;
        descripcion=descrip;
        fe=0;
        nombre=name;
        disponibilidad=true;
        Padre=nullptr;
        Izq=nullptr;
        Der=nullptr;
    }
    friend class ArbolAVL;
    friend class NodoMM;
    friend class Cubo;
};

class ArbolAVL{
    public:
        ArbolAVL();
        void Insertar(string id, string name, string descrip,nodoAVL* raiz);
        void InsertarRaiz(string id, string name, string descrip);
        bool Busca(string id);
        void RentarAc(string id);
        void ModificaDescripcion(string id, string descripcion, nodoAVL* raiz);
        void ReporteAVL();
        nodoAVL* ReRaiz();
        string UnUsuario(nodoAVL* hoja,  string usuario);

    private:
        enum {IZQUIERDO, DERECHO};
        nodoAVL* Raiz=nullptr;
        void SimpleIzquierda(nodoAVL* hoja);
        void SimpleDerecha(nodoAVL* hoja);
        void DobleIzquierda(nodoAVL* hoja);
        void DobleDerecha(nodoAVL* hoja);
        nodoAVL* BuscarR(string id,nodoAVL* hoja);
        void Equilibrar(nodoAVL *nodo, int rama, bool nuevo);
        void ReporRecurAVl(nodoAVL* hoja,  string usuario);

};

#endif // ARBOLAVL_H
