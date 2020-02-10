//PROGRAMA HIJO 2.1 - CALCULAR NÓMINAS
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

void BuscarEmpleado();
void CalcularNomina(float pagoHora);

int main(){
	BuscarEmpleado();
	return 0;
	system("PAUSE");
}
int id;
char nombre[60];
char puesto[100];
float phora;


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
			CalcularNomina(phora);
			lecturaArchivo>>id;
		}
	}
	else{
		cout<<"ERROR EN CONSULTA"<<endl;
	}

	lecturaArchivo.close();
}

float r;
float ingresosFijos;

void CalcularNomina(float pagoHora){
	cout<<"COMPUTE INGRESOS FIJOS: ";
	cin>>ingresosFijos;
	r=((pagoHora*8)*30)+ingresosFijos;
	cout<<r<<"\n";
}