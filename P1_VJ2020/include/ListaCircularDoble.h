#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/*ListaCircular ordenada por ID:

Usuario que realizo la renta
Departemento y empresa del usuario
Fecha
Tiempo de renta*/
class NodoCD{
private:
    NodoCD* sig;
    NodoCD* ant;
    string IdTransaccion;
    string IdActivo;
    string Vendedor;
    string Comprador;
    string Departamento;
    string Empresa;
    string Fecha;
    string TiempoRenta;

    NodoCD(string IdTran, string IdAc, string vende, string compra, string depar, string empres, string fec, string time){
        IdTransaccion=IdTran;
        IdActivo=IdAc;
        Comprador=compra;
        Vendedor=vende;
        Departamento=depar;
        Empresa=empres;
        Fecha=fec;
        TiempoRenta=time;
        sig=nullptr;
        ant=nullptr;
    }

    friend class ListaCircularDoble;
};

class ListaCircularDoble
{
    public:
        ListaCircularDoble();
        void InsertarCD(string IdTran, string IdAc, string vende, string compra, string depar, string empres, string fec, string time);
        void OrdenarDes();
        void OrdenarAs();
        void mostrar();

        void ReporteTransacciones();

        void TransPorUs(string usuario);
    private:

        void ReporteCD(string titulo, string texto);
        NodoCD* cabeza;
};

#endif // LISTACIRCULARDOBLE_H
