/*	PROGRAMA PARA REGISTRO DE EMPLEADOS	*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int resp1;
void RegistrarEmpleado();

int main(void){
	cout <<"************************************************\n";
	cout <<"|\t\tREGISTRO EMPLEADOS\t\t|\n";
	cout <<"************************************************\n";
	cout <<"DESEA AGREGAR UN NUEVO EMPLEADO (1- Si 0- No): ";
	cin >> resp1;
	if(resp1==1){
		system("cls");
		RegistrarEmpleado();
		
	}
	else{
		system("exit");
	}
	
	return 0;
}
//--------
int resp2=1;

string nombreEmpleado;

void RegistrarEmpleado(){
	do{
		printf("INGRESE NOMBRE EMPLEADO: ");
		cin >> nombreEmpleado;
		printf("DESEA REGISTRAR OTRO EMPLEADO 1- Si 0- No: ");
		cin >> resp2;
	}while(resp2!=0);
	printf("DESEA GUARDAR REGISTROS\n");
	main();
}
