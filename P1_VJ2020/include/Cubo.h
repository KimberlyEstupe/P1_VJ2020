#ifndef CUBO_H
#define CUBO_H
#include <iostream>
#include <sstream>
#include <string>
#include "ArbolAVL.h"

using namespace std;

class NodoMM{
public:
    string Departamento;
    string Empresa;
    string Empleado;//Nomre completo
    string Usuario;//Nombre usuario
    string contra;//contraseña

    int X,Y;
    NodoMM* Sig;
    NodoMM* Ant;
    NodoMM* Der;
    NodoMM* Izq;
    NodoMM* Arriba;
    NodoMM* Abajo;
    nodoAVL* LActivos;
    NodoMM(int x,int y, string Dep, string Empre, string persona, string usua, string clave,nodoAVL* raiz ){
        Departamento = Dep;
        Empresa = Empre;
        Empleado = persona;
        Usuario = usua;
        contra = clave;
        X=x;
        Y=y;
        Sig=nullptr;
        Ant=nullptr;
        Der=nullptr;
        Izq=nullptr;
        Arriba=nullptr;
        Abajo=nullptr;
        LActivos=raiz;
    }

  friend class Cubo;
};

class Cubo
{
    public:
        Cubo();
        void Insertar(string persona, string con, string usario, string Empre, string Depa);

        void ReposrteMM();
        bool Busca(string usu, string depa, string contr, string empre);
        bool BCABEZA(string usu, string depa, string contr, string empre);
        string usuario();
        string empresa();
        string departamento();

        NodoMM* Busca2(string usu, string depa, string empre);
        //---------------------- AVL-------------------------------------
        void activos(string id, string nombre, string desripcion);
        void ReporteAVL();
        void ModiTrans(string id, string desripcion);
        void RentarActivo(string id, string venndedor,string depa,string empre);
        void Reporteusuario(string usu,string depa, string empre);
        void ReporteEmpresa(string em);
        void ReporteDepartamento(string de);
        //--------------------------------------------------------------
    protected:
        NodoMM* InsertX(string Dep);
        NodoMM* InsertY(string Empre);
        void InsertNodY(NodoMM* nuevo, NodoMM* NodoX, NodoMM* NodoY);
        void InsertNodX(NodoMM* nuevo, NodoMM* NodoX);
        void RRAVL(string texto, string titulo);
        NodoMM* Cabeza;
        NodoMM* NodBusqueda;
};

#endif // CUBO_H
