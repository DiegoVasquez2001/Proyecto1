#include <iostream>
#include <fstream>
using namespace std;

void GenerarNomina(string nombre, float sueldo){
	ofstream generarNomina;
	generarNomina.open("BDnomina.txt", ios::app);

	if(generarNomina.is_open()){
		generarNomina<<nombre<<" "<<sueldo<<endl;
	}
	else{
		cout<<"ERROR!"<<endl;
	}
	cout<<"NOMINA GENERADA EXITOSAMENTE!"<<endl;
	generarNomina.close();
}