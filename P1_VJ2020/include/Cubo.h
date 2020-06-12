#ifndef CUBO_H
#define CUBO_H
#include <iostream>
#include <sstream>
#include <string>
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

    NodoMM(int x,int y, string Dep, string Empre, string persona, string usua, string clave){
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


    protected:
        NodoMM* InsertX(string Dep);
        NodoMM* InsertY(string Empre);
        void InsertNodY(NodoMM* nuevo, NodoMM* NodoX, NodoMM* NodoY);
        void InsertNodX(NodoMM* nuevo, NodoMM* NodoX);

        NodoMM* Cabeza;
        NodoMM* NodBusqueda;

};

#endif // CUBO_H
