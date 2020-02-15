
#include <iostream>
#include <fstream>
#include <InterfazGrafica>
using namespace std;

int main () {
	string nombre, puesto;
	int id, nit, sueldoph, seg;
	seg=1;
	
	
	  	
	do 
	{	
		ofstream file;

		file.open("BDempleados.txt",ios::out|ios::app);
		if(file.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		cout << "\t\t\t\t\tIngrese datos del empleado:\n";  
		cout << "\tID: ";
		cin >> id;
		cout << "\tNombre: ";
		cin >> nombre; 
		cout << "\tNIT: ";
		cin >> nit; 
		cout << "\tPuesto: ";
		cin >> puesto;
		cout << "\tSueldo Por Hora: ";
		cin >> sueldoph;
		cout << "\tDesea seguir ingresando empleados? \n\t1=Seguir \n\t0=Terminar: ";
		cin >> seg;
		file<<id;
		file<<"\t";
		file<<nombre;
		file<<"\t";
		file<<nit;
		file<<"\t";
		file<<puesto;
		file<<"\t";
		file<<sueldoph;
		file<<"\t";	
		file.close();
	}
	while(seg !=0);

	system("PAUSE");
	return 0;
}
