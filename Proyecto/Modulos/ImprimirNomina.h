#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

float ISueldoEmpleado;
char INombreEmpleado[60];

void ImprimirNomina(){
	ifstream verNomina;
	verNomina.open("BDnomina.txt", ios::in);
	if(verNomina.is_open()){
		cout<<"...NOMINA PARA TODOS LOS EMPLEADOS..."<<endl;
		verNomina>>INombreEmpleado;
		while(!verNomina.eof()){
			verNomina>>ISueldoEmpleado;
			cout<<"NOMBRE: "<<INombreEmpleado<<endl;
			cout<<"SUELDO: "<<ISueldoEmpleado<<endl;
			verNomina>>INombreEmpleado;
		}
	}
	else{
		cout<<"ERROR EN CONSULTA"<<endl;
	}
	verNomina.close();
}