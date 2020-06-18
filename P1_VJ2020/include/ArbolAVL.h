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
};

class ArbolAVL
{
    public:
        ArbolAVL();
        void Insertar(string id, string name, string descrip);
        void Busca(string id);
        void RentarAc(string id);
        void ModificaDescripcion(string id, string descripcion);
        void ReporteAVL();


    protected:

    private:
        enum {IZQUIERDO, DERECHO};
        nodoAVL* Raiz=nullptr;
        void SimpleIzquierda(nodoAVL* hoja);
        void SimpleDerecha(nodoAVL* hoja);
        void DobleIzquierda(nodoAVL* hoja);
        void DobleDerecha(nodoAVL* hoja);
        nodoAVL* BuscarR(string id,nodoAVL* hoja);
        void Equilibrar(nodoAVL *nodo, int rama, bool nuevo);
        void ReporRecurAVl(nodoAVL* hoja);
};

#endif // ARBOLAVL_H
