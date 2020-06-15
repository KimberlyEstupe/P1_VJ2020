#include "Menus.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <time.h>
#include <stdlib.h>

//---------Archivos--------
#include "Cubo.h"
#include "ListaCircularDoble.h"
Cubo cubo;
ListaCircularDoble LCD;
ListaCircularDoble LC2;
using namespace std;

void Menus::pruebasCodigo(){
    LCD.InsertarCD(GenerarClave(),"y8","ll","x","sdf","z","66","pp");
    LCD.InsertarCD(GenerarClave(),"s9","ll","x","sdf","z","66","pp");
    LCD.InsertarCD(GenerarClave(),"s9","ll","sdf","x","z","66","pp");
    LCD.InsertarCD(GenerarClave(),"s9","sdf","ll","x","z","66","pp");
    LCD.OrdenarAs();

    cout<<endl;
    LC2.InsertarCD(GenerarClave(),"y8","ll","x","sdf","z","66","pp");
    LC2.InsertarCD(GenerarClave(),"y8","ll","x","sdf","z","66","pp");
    LC2.InsertarCD(GenerarClave(),"y8","ll","x","sdf","z","66","pp");
    LC2.OrdenarAs();
}




void Menus::MUsuarioIngresado(string n){
    system("CLS");
    int op=8;
    do{
    string name, des;
        cout<<"\t \t \t \t*---------* M E N U   U S U A R I O  *---------* \n"<<endl;
        cout<<"Bienvenido "<<n<<"\n"<<endl;
        cout<<" 1. Agregar Activo  \n"<<endl;//
        cout<<" 2. Eliminar Activo  \n"<<endl;
        cout<<" 3. Modificar Activo \n"<<endl;
        cout<<" 4. Rentar Activo \n"<<endl;
        cout<<" 5. Activos Rentados\n"<<endl;
        cout<<" 6. Mis Activos Rentados \n"<<endl;
        cout<<" 7. Cerrar Sesion y regresar a Menu principal  \n"<<endl;
        cout<<"Ingrese Opcion:  "<<endl;
        cin>>op;
        switch(op){
            case 1:system("CLS");
                    cout<<"\t \t \t*---------* A G R E G A R   A C T I V O  *---------* \n"<<endl;
                    cout<<"Ingrear Nombre de Activo: "<<endl;
                    cout<<"Ingrear Descripcion de Activo: "<<endl;

                    system("PAUSE");
                    op=8;
                    system("CLS");
                break;

            case 2: cout<<"\t \t \t*---------* E L I M I N A R   A C T I V O  *---------* \n"<<endl;
                op=8;
                system("CLS");
                break;

            case 3: cout<<"\t \t \t*---------* M O D I F I C A R   A C T I V O  *---------* \n"<<endl;
                op=8;
                system("CLS");
                break;

            case 4: cout<<"\t \t \t*---------* R E N T A R   A C T I V O  *---------* \n"<<endl;
                op=8;
                system("CLS");
                break;

            case 5: cout<<"\t \t \t*---------* A C T I V O S   R E N T A D O S *---------* \n"<<endl;
                op=8;
                system("CLS");
                break;

            case 6: cout<<"\t \t*---------* M I S   A C T I V O S   R E N T A D O S *---------* \n"<<endl;
                op=8;
                system("CLS");
                break;

            case 7: cout <<"\nCERRANDO SESIÓN...\n \n"<<endl;
                inicio();
                system("CLS");
                break;

            default: cout << "Usted ha ingresado una opción incorrecta, ingres una opcion entre (1 a 7) \n \n";
                system("PAUSE");
                op=8;
                system("CLS");
                break;
        }
    }while(op>0 && op<=8);
}

void Menus::Admin(){
    system("CLS");
    int op=2;
    do{
        cout<<"\t \t \t \t*---------* M E N U    A D M I N I S T R A D O R  *---------* \n"<<endl;
        cout<<" 1. Registrar Usuario  \n"<<endl;
        cout<<" 2. Reporte Matriz De Empleados      \n"<<endl;
        cout<<" 3. Reporte Activos Disponibles de un Departamento      \n"<<endl;
        cout<<" 4. Reporte Activos Disponibles de una Empresa      \n"<<endl;
        cout<<" 5. Reporte Transacciones      \n"<<endl;
        cout<<" 6. Reporte Activos de un usuario      \n"<<endl;
        cout<<" 7. Activos Rentados por un Usuario      \n"<<endl;
        cout<<" 8. Ordenar Transacciones \n"<<endl;
        cout<<" 9. Regresar a Menu principal \n"<<endl;
        cout<<"Ingrese Opcion:  "<<endl;
        cin>>op;
        switch(op){
            case 1:CrearUsuario();
                    op=10;
                    system("CLS");
                    break;

            case 2: cout<<"\t \t \t*---------* REPORTE MATRIZ DE EMPLEADOS *---------* \n"<<endl;
                    cubo.ReposrteMM();
                    op=10;
                    system("CLS");
                    break;

            case 3: cout<<"\t \t \t*---------* REPORTE ACTIVOS DISPONIBLES DE UN DEPARTAMENTO *---------* \n"<<endl;
                    op=10;
                    system("CLS");
                    break;

            case 4: cout<<"\t \t \t*---------* REPORTE ACTIVOS DISPONIBLES DE UNA EMPRESA *---------* \n"<<endl;
                    op=10;
                    system("CLS");
                    break;

            case 5: cout<<"\t \t \t*---------* REPORTE DE TRANSACCIONES *---------* \n"<<endl;
                    LCD.ReporteTransacciones();
                    op=10;
                    system("CLS");
                    break;

            case 6: cout<<"\t \t \t*---------* REPORTE ACTIVOS DE UN USUARIO *---------* \n"<<endl;
                    op=10;
                    system("CLS");
                    break;

            case 7: cout<<"\t \t \t*---------* REPORTE ACTIVOS RENTADOS POR UN USUARIO *---------* \n"<<endl;
                    op=10;
                    system("CLS");
                    break;

            case 8: OrdenarActivos();

                    op=10;
                    system("CLS");
                    break;

            case 9: cout<<"REGRESANDO A LOGIN ... \n"<<endl;
                    system("PAUSE");
                    RentaActivosLogin();
                    system("CLS");
                    break;

            default: cout << "Usted ha ingresado una opción incorrecta, ingres una opcion entre (1 a 9) \n \n";
                system("PAUSE");
                op=10;
                system("CLS");
                break;

        }
    }while(op>0 && op<=10);
}

//********************* COMPLETOS *******************************************************************************************************
void Menus::OrdenarActivos(){
    system("CLS");
    int op=2;
    do{
        cout<<"\t \t \t \t*---------* ORDENAR TRANSACCIONES  *---------* \n"<<endl;
        cout<<" 1.Ascendentemente  \n"<<endl;
        cout<<" 2.Descendentemente \n"<<endl;
        cout<<" 3. Regresar \n"<<endl;
        cout<<"Ingrese Opcion:  "<<endl;
        cin>>op;
        switch(op){
            case 1: LCD.OrdenarAs();
                cout<<"Transacciones Ordenas Ascendetemente"<<endl;
                LCD.ReporteTransacciones();
                system("PAUSE");
                op=3;
                system("CLS");
                break;
            case 2: LCD.OrdenarDes();
                cout<<"Transacciones Ordenas Descendentement"<<endl;
                LCD.ReporteTransacciones();
                system("PAUSE");
                op=3;
                system("CLS");
                break;
            case 3:
                system("CLS");
                Admin();
                break;
            default: cout << "Usted ha ingresado una opción incorrecta\n \n";
            op=3;
            system("PAUSE");
            system("CLS");
            break;
        }
    }while(op>0 && op<5);
}

void Menus::CrearUsuario(){
    string nombre,usuario,contra,depa,empre;
    system("CLS");
                    cout<<"\t \t \t*+++++++++++++++++++++++*  A D M I N I S T R A D O R  *+++++++++++++++++++++++*  \n"<<endl;
                    cout<<"\t \t \t*+++++++++++++++++++++++++++++*  CREAR USUARIO  *+++++++++++++++++++++++++++++*  \n"<<endl;
                    cout<<"Ingrese los siguientes campos que se le piden"<<endl;
                    cout<<"\n* Ingrese Nombre Completo:  "<<endl;
                    cin>>nombre;
                    cout<<"\n* Ingrese Usuario:  "<<endl;
                    cin>>usuario;
                    cout<<"\n* Ingrese Contraseña:  "<<endl;
                    cin>>contra;
                    cout<<"\n* Ingrese Departamento:  "<<endl;
                    cin>>depa;
                    cout<<"\n* Ingrese Empresa:  "<<endl;
                    cin>>empre;
                    cubo.Insertar(Mayusculas(depa),Mayusculas(empre),Mayusculas(nombre),Mayusculas(usuario),Mayusculas(contra));
}

void Menus::RentaActivosLogin(){
    system("CLS");
    string usuario="";
    string contra="";
    string depa="";
    string empre="";
    cout<<"\t \t \t \t*---------* R E N T A   D E   A C T I V O S  *---------* \n"<<endl;
    cout<<"\t \t \t \t*--------------------*  L O G I N *--------------------* \n \n"<<endl;
    cout<<"\n* Ingrese Usuario:  "<<endl;
    cin>>usuario;
    cout<<"\n* Ingrese Contraseña:  "<<endl;
    cin>>contra;
    cout<<"\n* Ingrese Departamento:  "<<endl;
    cin>>depa;
    cout<<"\n* Ingrese Empresa:  "<<endl;
    cin>>empre;

    if(cubo.BCABEZA(Mayusculas(usuario), Mayusculas(depa), Mayusculas(contra), Mayusculas(empre)) ){
        Admin();
    }else if (cubo.Busca(Mayusculas(usuario), Mayusculas(depa), Mayusculas(contra), Mayusculas(empre))){
        MUsuarioIngresado(cubo.usuario());
    }else{
        cout<<"Este usuario no existe "<<endl;
        system("PAUSE");
        inicio();
    }
}

void Menus::inicio(){
    system("CLS");
    int op=2;
    do{
        cout<<"\t \t \t \t*---------* R E N T A   D E   A C T I V O S  *---------* \n"<<endl;
        cout<<" 1.Iniciar Sesion   \n \n"<<endl;
        cout<<" 2.Salir            \n \n"<<endl;
        cout<<"Ingrese Opcion:  "<<endl;
        cin>>op;
        switch(op){
            case 1: RentaActivosLogin();
            op=2;
                break;
            case 2: cout <<"\nTenga un buen dia...\n \n"<<endl;
                system("PAUSE");
                exit(0);
                break;
            default: cout << "Usted ha ingresado una opción incorrecta\n \n";
            system("PAUSE");
            system("CLS");
            break;
        }
    }while(op!=1);

}

string Menus::Mayusculas(string cadena){
    for (int i = 0; i < cadena.length(); i++) {
    cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}

string Menus::GenerarClave(){
    char letras[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    int longitud=sizeof(letras)/sizeof(*letras);
    string clave="";
    for(int i=0; i <= 14; i++){
        int num =  1 + rand()%longitud;
        clave+=letras[num];
    }
    return clave;
}
