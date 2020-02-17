#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int AIdEmpleado, auxID;
char ANombreEmpleado[60];
char APuestoEmpleado[100];
float ASueldoHora;

//FUNCIÓN PARA GENERAR NUEVO EMPLEADO
void AltasEmpleado(){
    ofstream escritura;
    ifstream consulta;
    bool repetido=false;
    escritura.open("Modulos/BDempleados.txt",ios::app);
    consulta.open("Modulos/BDempleados.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
        cout<<"INGRESE ID DEL EMPLEADO: ";
        cin>>auxID;
        consulta>>AIdEmpleado;
        while(!consulta.eof()){
            consulta>>ANombreEmpleado>>APuestoEmpleado>>ASueldoHora;
            if(AIdEmpleado==auxID){
                cout<<"YA EXISTE UN EMPLEADO CON ESTE ID!"<<endl;
                repetido=true;
                break;
            }
            consulta>>AIdEmpleado;
        }
        if(repetido==false){
            cout<<"INGRESE EL NOMBRE DEL EMPLEADO: ";
            cin>>ANombreEmpleado;
            cout<<"INGRESE EL PUESTO DEL EMPLEADO ";
            cin>>APuestoEmpleado;
            cout<<"INGRESE EL SUELDO POR HORA DEL EMPLEADO: ";
            cin>>ASueldoHora;
            escritura<<auxID<<" "<<ANombreEmpleado<<" "<<APuestoEmpleado<<" "<<ASueldoHora<<endl;
            cout<<"Registro Ageragado"<<endl;
        }

    }else{
        cout<<"ERROR AL GENERAR ARCHIVO!"<<endl;
    }
    escritura.close();
    consulta.close();
}