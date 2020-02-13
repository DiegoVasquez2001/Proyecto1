//PROGRAMA HIJO 2.1 - CALCULAR NÓMINAS
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

void BuscarEmpleado();
void CalcularNomina(float pagoHora, string puesto);

int main(){
	BuscarEmpleado();
	system("PAUSE");
	return 0;
}
int id;
char nombre[60];
char puesto[100];
float phora;

int varContador=1;

void BuscarEmpleado(){
	ifstream lecturaArchivo;
	lecturaArchivo.open("BDempleados.txt", ios::in);
	if(lecturaArchivo.is_open()){
		cout<<"COSULTA REALIZADA..."<<endl;
		lecturaArchivo>>id;
		while(!lecturaArchivo.eof()){
			lecturaArchivo>>nombre;
			lecturaArchivo>>puesto;
			lecturaArchivo>>phora;
			cout<<"ID: "<<id<<endl;
			cout<<"NOMBRE: "<<nombre<<endl;
			cout<<"PUESTO: "<<puesto<<endl;
			cout<<"SUELDO HORA: "<<phora<<endl;
			CalcularNomina(phora, puesto);
			lecturaArchivo>>id;
			varContador++;
		}
	}
	else{
		cout<<"ERROR EN CONSULTA"<<endl;
	}
	lecturaArchivo.close();
}

float ingresosFijos;
float ingresosVariables;
const int bonIncentivo=250;
float sueldoExtra;
float descuentosFijos;
float igss;
float isr;

void CalcularNomina(float pagoHora, string puesto){
	cout<<"COMPUTE INGRESOS VARIABLES: ";
	cin>>ingresosVariables;

	ingresosFijos=((pagoHora*8)*30)+ingresosVariables+bonIncentivo;
	cout<<ingresosFijos<<"\n";

	if(puesto=="Administrador"){
		cout<<"EXONERADO DE IGSS!"<<"\n";
	}
	else{
		igss = ingresosFijos*0.0483;
		cout<<igss<<"\n";
	}
}