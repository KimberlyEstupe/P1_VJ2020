#ifndef CUBODISPERSO_H
#define CUBODISPERSO_H
class NodoMM{
    private:
    string Departamento;
    string Empresa;
    string Empleado;//Nomre completo
    string Usuario;//Nombre usuario
    string contra;//contraseña
    int X,Y;
    NodoMM* SigMM;
    NodoMM* AntMM;
    NodoMM* DerMM;
    NodoMM* IzqMM;
    NodoMM* ArribaMM;
    NodoMM* AbajoMM;

    NodoMM(int x,int y, string Dep, string Empre, string persona, string Usuario, string contra){
        this->Departamento = Dep;
        this->Empresa = Empre;
        this->Empleado = persona;
        this->Usuario = Usuario;
        this->contra = contra;
        this->X=x;
        this->Y=y;
        SigMM=NULL;
        AntMM=NULL;
        DerMM=NULL;
        IzqMM=NULL;
        ArribaMM=NULL;
        AbajoMM=NULL;
    }
};

class CuboDisperso
{
    public:
        CuboDisperso();

    protected:

    private:
};

#endif // CUBODISPERSO_H
