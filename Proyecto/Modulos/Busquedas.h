#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int BIdEmpleado, BauxID;
char BNombreEmpleado[60];
char BPuestoEmpleado[100];
float BSueldoHora;
bool encontrado;

void BuscarEmpleado(){
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("Modulos/BDempleados.txt",ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"INGRESE EL ID DEL EMPLEADO A BUSCAR: ";
        cin>>BauxID;
        lectura>>BIdEmpleado;//lectura adelantada

        while(!lectura.eof()){
            lectura>>BNombreEmpleado>>BPuestoEmpleado>>BSueldoHora;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if(BauxID==BIdEmpleado){
                cout<<"______________________________"<<endl;
                cout<<"ID: "<<BIdEmpleado<<endl;
                cout<<"NOMBRE: "<<BNombreEmpleado<<endl;
                cout<<"PUESTO: "<<BPuestoEmpleado<<endl;
                cout<<"SUELDO POR HORA: "<<BSueldoHora<<endl;
                cout<<"______________________________"<<endl;
                encontrado=true;
            }

            lectura>>BIdEmpleado;//lectura adelantada
        }
        if(encontrado==false){
            cout<<"NO HAY REGISTROS CON LA CLAVE:"<<BauxID<<endl;
        }
    }else{
        cout<<"NO SE PUEDE ACCEDER AL ARCHIVO"<<endl;
    }
    //cerrando el archivo
    lectura.close();
}