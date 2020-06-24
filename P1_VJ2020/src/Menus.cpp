#include "Menus.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <time.h>
#include <stdlib.h>

//---------Archivos--------
#include "Cubo.h"
#include "ListaCircularDoble.h"
#include "ArbolAVL.h"
Cubo cubo;
ListaCircularDoble Rentactivo;
ListaCircularDoble catalogo;
ArbolAVL AVL;
using namespace std;

void Menus::pruebasCodigo(){
    cubo.Insertar("Nombre","Contraseña","Usuario","Empresa","Departamento");
    cubo.Insertar("KARLA","KARLA","KARLA","HIPER","ZACAPA");
    cubo.Insertar("MARIA","MARIA","MARIA","PERI","SOLOLA");
    cubo.Insertar("SHARON","SHARON","SHARON","PERI","SOLOLA");
    cubo.Insertar("NATALIO","NATALIO","NATALIO","PERI","SOLOLA");
    cubo.Insertar("DIEGO","DIEGO","DIEGO","HIPER","IZABAL Rosa");
    cubo.Insertar("JONATAN","JONATAN","JONATAN","PERI","ZACAPA");
    cubo.Insertar("KEVIN","KEVIN","KEVIN","HIPER","ZACAPA");
    cubo.Insertar("LESLY","LESLY","LESLY","DOLAR","ZACAPA");
    cubo.Insertar("AMALY","AMALY","AMALY","LITTLE","ZACAPA");
    cubo.Insertar("PEPE","PEPE","PEPE","HIPER","GUATEMALA");

    if(cubo.Busca("KARLA","ZACAPA","KARLA","HIPER")){
        cubo.activos("I7PSD","NOMBRE1","decrip");
        catalogo.InsertarCD("NOMBRE1","I7PSD","KARLA","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("MP849","NOMBRE2","decrip");
        catalogo.InsertarCD("NOMBRE2","MP849","KARLA","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("SDMC6","NOMBRE3","decrip");
        catalogo.InsertarCD("NOMBRE3","SDMC6","KARLA","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("L9MC6","NOMBRE4","decrip");
        catalogo.InsertarCD("NOMBRE4","L9MC6","KARLA","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("ADP9X","NOMBRE5","decrip");
        catalogo.InsertarCD("NOMBRE5","ADP9X","KARLA","X","ZACAPA","HIPER","X","X","decrip");

        cubo.ModiTrans("ADP9X","Nueva Descripcion");
    }

    if(cubo.Busca("KEVIN","ZACAPA","KEVIN","HIPER")){
        cubo.activos("VHYS6","NOMBRE6","decrip");
        catalogo.InsertarCD("NOMBRE6","VHYS6","KEVIN","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("SLIST","NOMBRE7","decrip");
        catalogo.InsertarCD("NOMBRE7","SLIST","KEVIN","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("I9PSD","NOMBRE8","decrip");
        catalogo.InsertarCD("NOMBRE8","I9PSD","KEVIN","X","ZACAPA","HIPER","X","X","decrip");
        cubo.activos("T36S8","NOMBRE9","decrip");
        catalogo.InsertarCD("NOMBRE9","T36S8","KEVIN","X","ZACAPA","HIPER","X","X","decrip");
    }

    if(cubo.Busca("PEPE","GUATEMALA","PEPE","HIPER")){
        cubo.activos("M36S8","NOMBRE10","decrip");
        catalogo.InsertarCD("NOMBRE10","M36S8","PEPE","X","GUATEMALA","HIPER","X","X","decrip");
        cubo.activos("UL1ST","NOMBRE11","decrip");
        catalogo.InsertarCD("NOMBRE11","UL1ST","PEPE","X","GUATEMALA","HIPER","X","X","decrip");
        cubo.activos("ZA49F","NOMBRE12","decrip");
        catalogo.InsertarCD("NOMBRE12","ZA49F","PEPE","X","GUATEMALA","HIPER","X","X","decrip");
        cubo.activos("POC30","NOMBRE13","decrip");
        catalogo.InsertarCD("NOMBRE13","POC30","PEPE","X","GUATEMALA","HIPER","X","X","decrip");
        cubo.ModiTrans("POC30","Nueva Descripcion");
        cubo.activos("N36SD","ACPEPE","decrip");
        catalogo.InsertarCD("ACPEPE","N36SD","PEPE","X","GUATEMALA","HIPER","X","X","decrip");
        cubo.activos("AA6SD","ACPEPE2","decrip");
        catalogo.InsertarCD("ACPEPE2","AA6SD","PEPE","X","GUATEMALA","HIPER","X","X","decrip");
    }

    string des=catalogo.vendedor("UL1ST");
     if(des!=""){
        catalogo.RenCatalogo("UL1ST","LESLY","DOLAR","ZACAPA");
        cubo.RentarActivo("UL1ST",des,catalogo.deparv(),catalogo.empresav());
        Rentactivo.InsertarCD(GenerarClave(),"UL1ST",des,"LESLY","ZACAPA","DOLAR","05/08/2020","3 meses","D");
    }

    des=catalogo.vendedor("I9PSD");
     if(des!=""){
	catalogo.RenCatalogo("I9PSD","AMALY","LITTLE","ZACAPA");
        cubo.RentarActivo("I9PSD",des,catalogo.deparv(),catalogo.empresav());
        Rentactivo.InsertarCD(GenerarClave(),"I9PSD",des,"AMALY","ZACAPA","LITTLE","05/03/2020","3 meses","D");
    }

    des=catalogo.vendedor("I7PSD");
     if(des!=""){
        cubo.RentarActivo("I7PSD",des,catalogo.deparv(),catalogo.empresav());
        catalogo.RenCatalogo("I7PSD","JONATAN","PERI","ZACAPA");
        Rentactivo.InsertarCD(GenerarClave(),"I7PSD",des,"JONATAN","ZACAPA","PERI","05/06/2020","5 meses","D");
    }

    Admin();
    //cubo.ReporteDepartamento("Zacapa");

    cout<<endl;

}




void Menus::MUsuarioIngresado(string n){
    system("CLS");
    int op=8;
    do{
    string name, des;//Agregar activo
    string clave,emp,depa,clave2,tiempo, fecha;
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
        system("CLS");
        switch(op){
            case 1:system("CLS");
                    cout<<"\t \t \t*---------* A G R E G A R   A C T I V O  *---------* \n"<<endl;
                    cout<<"Ingrear Nombre de Activo: "<<endl;
                    cin>>name;
                    cout<<"Ingrear Descripcion de Activo: "<<endl;
                    cin>>des;
                    clave=GenerarClave();
                    catalogo.InsertarCD(Mayusculas(name),clave,n,"x",cubo.departamento(),cubo.empresa(),"x","x",Mayusculas(des));
                    cubo.activos(clave,Mayusculas(name),Mayusculas(des));
                    system("PAUSE");
                    op=8;
                    system("CLS");
                break;

            case 2: cout<<"\t \t \t*---------* E L I M I N A R   A C T I V O  *---------* \n"<<endl;
                op=8;
                system("CLS");
                break;

            case 3: cout<<"\t \t \t*---------* M O D I F I C A R   A C T I V O  *---------* \n"<<endl;
                //catalogo.TransVende(n);
                cout<<"Ingrese activo que desea modificar: ";
                cin>>name;
                cout<<"Ingrese descripcion modificar: ";
                cin>>des;
                cubo.ModiTrans(Mayusculas(name),des);
                op=8;
                system("CLS");
                break;

            case 4: cout<<"\t \t \t*---------* R E N T A R   A C T I V O  *---------* \n"<<endl;
                catalogo.Mcatalogo(n);
                cout<<"Ingrese el id de activo que desea rentar: ";
                cin>>name;
                cout<<"Ingrese el tiempo a rentar : ";
                cin>>tiempo;
                cout<<"Fecha actual( dd/mm/aa ): ";
                cin>>fecha;
                des=catalogo.vendedor(Mayusculas(name));
                if(des!=""){
                    catalogo.RenCatalogo(Mayusculas(name),n,cubo.empresa(),cubo.departamento());
                    cubo.RentarActivo(Mayusculas(name),des,catalogo.deparv(),catalogo.empresav());
                    Rentactivo.InsertarCD(GenerarClave(),Mayusculas(name),des,n,cubo.departamento(),cubo.empresa(),fecha,tiempo,"D");
                }

                system("CLS");
                op=8;
                break;

            case 5: cout<<"\t \t \t*---------* A C T I V O S   R E N T A D O S *---------* \n"<<endl;
                catalogo.TransCompra(n);
                system("PAUSE");
                op=8;
                system("CLS");
                break;

            case 6: cout<<"\t \t*---------* M I S   A C T I V O S   R E N T A D O S *---------* \n"<<endl;
                catalogo.TransVende(n);
                system("PAUSE");
                op=8;
                system("CLS");
                break;

            case 7: cout <<"\nCERRANDO SESIÓN...\n \n"<<endl;
                system("PAUSE");
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
    string nombre,usuario,contra,depa,empre;
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
        system("CLS");
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
                    cout<<"Ingrese el departamento ";
                    cin>>nombre;
                    cubo.ReporteDepartamento(Mayusculas(nombre));
                    op=10;
                    system("CLS");
                    break;

            case 4: cout<<"\t \t \t*---------* REPORTE ACTIVOS DISPONIBLES DE UNA EMPRESA *---------* \n"<<endl;
                    cout<<"Ingrese la empresa ";
                    cin>>nombre;
                    cubo.ReporteEmpresa(Mayusculas(nombre));
                    op=10;
                    system("CLS");
                    break;

            case 5: cout<<"\t \t \t*---------* REPORTE DE TRANSACCIONES *---------* \n"<<endl;
                    Rentactivo.ReporteTransacciones();
                    op=10;
                    system("CLS");
                    break;

            case 6: cout<<"\t \t \t*---------* REPORTE ACTIVOS DE UN USUARIO *---------* \n"<<endl;
                    cout<<"\n* Ingrese Usuario:  "<<endl;
                    cin>>usuario;
                    cout<<"\n* Ingrese Departamento:  "<<endl;
                    cin>>depa;
                    cout<<"\n* Ingrese Empresa:  "<<endl;
                    cin>>empre;
                    cubo.Reporteusuario(Mayusculas(usuario),Mayusculas(depa),Mayusculas(empre));

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
            case 1: Rentactivo.OrdenarAs();
                cout<<"Transacciones Ordenas Ascendetemente"<<endl;
                Rentactivo.ReporteTransacciones();
                system("PAUSE");
                op=3;
                system("CLS");
                break;
            case 2: Rentactivo.OrdenarDes();
                cout<<"Transacciones Ordenas Descendentement"<<endl;
                Rentactivo.ReporteTransacciones();
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
                    cubo.Insertar(Mayusculas(nombre),Mayusculas(contra),Mayusculas(usuario),Mayusculas(empre),Mayusculas(depa));
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
