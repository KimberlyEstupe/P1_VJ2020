#ifndef MENUS_H
#define MENUS_H
#include "Cubo.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Menus
{
    public:
        void inicio();//Completo
        void pruebasCodigo();//*

    private:
        void Admin();//FALTAN LOS CASE
        void MUsuarioIngresado(string n);


        void RentaActivosLogin();
        void OrdenarActivos();
        void CrearUsuario();
        string Mayusculas(string cadena);
        string GenerarClave();


};

#endif // MENUS_H
