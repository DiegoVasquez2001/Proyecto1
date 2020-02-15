#include <iostream>
#include <fstream>
#include "calculos.h"
#include <windows.h>
#include <cstdlib>
using namespace std;

int idEmpleado;
char nombreEmpleado[60];
char puestoEmpleado[100];
float sueldoHora;

void CalcularNomina(){
	ifstream lecturaArchivo;
	lecturaArchivo.open("Modulos/BDempleados.txt", ios::in);
	if(lecturaArchivo.is_open()){
		cout<<"COSULTA REALIZADA!"<<endl;
		cout<<"CARGANDO INFORMACION";
		Sleep(100);
		cout<<"..."<<endl;
		Sleep(1000);
		system("cls");
		lecturaArchivo>>idEmpleado;
		while(!lecturaArchivo.eof()){
			lecturaArchivo>>nombreEmpleado;
			lecturaArchivo>>puestoEmpleado;
			lecturaArchivo>>sueldoHora;
			cout<<"ID: "<<idEmpleado<<endl;
			cout<<"NOMBRE: "<<nombreEmpleado<<endl;
			cout<<"PUESTO: "<<puestoEmpleado<<endl;
			cout<<"SUELDO HORA: "<<sueldoHora<<endl;
			cout<<"CALCULANDO NOMINA PARA: "<<nombreEmpleado<<endl;
			Calculos(nombreEmpleado, sueldoHora, puestoEmpleado);
			cout<<"-----------------------------------------------------------"<<endl;
			lecturaArchivo>>idEmpleado;
		}
	}
	else{
		cout<<"ERROR EN CONSULTA"<<endl;
	}
	lecturaArchivo.close();
}