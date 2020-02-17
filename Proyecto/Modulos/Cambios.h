#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int CIdEmpleado, CauxID;
char CNombreEmpleado[60];
char auxNombre[60];
char CPuestoEmpleado[100];
float CSueldoHora;
bool cEncontrado;

void CambiarEmpleado(){
    ofstream aux;
    ifstream lectura;
    cEncontrado=false;
    int CauxID=0;
    char auxNombre[30];
    aux.open("Modulos/auxiliar.txt",ios::out);
    lectura.open("Modulos/BDempleados.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"INGRESE ID DEL EMPLEADO A MODIFICAR: ";
        cin>>CauxID;
        lectura>>CIdEmpleado;
        while(!lectura.eof()){
            lectura>>CNombreEmpleado>>CPuestoEmpleado>>CSueldoHora;
            if(CauxID==CIdEmpleado){
                cEncontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"ID: "<<CIdEmpleado<<endl;
                cout<<"NOMBRE: "<<CNombreEmpleado<<endl;
                cout<<"PUESTO: "<<CPuestoEmpleado<<endl;
                cout<<"SUELDO POR HORA: "<<CSueldoHora<<endl;
                cout<<"__________________________"<<endl;
                cout<<"NUEVO NOMBRE PARA "<<CIdEmpleado<<": ";
                cin>>auxNombre;
                aux<<CIdEmpleado<<" "<<auxNombre<<" "<<CPuestoEmpleado<<" "<<CSueldoHora<<endl;
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<CIdEmpleado<<" "<<CNombreEmpleado<<" "<<CPuestoEmpleado<<" "<<CSueldoHora<<endl;
            }
            lectura>>CIdEmpleado;
        }
    }else{
        cout<<"NO SE PUEDE ABRIR EL ARCHIVO"<<endl;
    }
    if(cEncontrado==false){
        cout<<"NO SE ENCONTRÓ EMPLEADO CON DICHA CLAVE"<<CauxID<<endl;
    }
    remove("BDempleados.txt");
    rename("auxiliar.txt","BDempleados.txt");
    aux.close();
    lectura.close();
}