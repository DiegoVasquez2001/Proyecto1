#include <windows.h>
#include <cstdlib>
#include "CalcularNomina.h"
#include "Altas.h"
#include "Busquedas.h"
#include "Cambios.h"
#include "ImprimirNomina.h"
#include <iostream>
using namespace std;

int opcion;

void Menu(){
	system("color 5F");
	SetConsoleTitle("CALCULO NOMINAS");
	cout<<"\t\t|==========| MENU DE TAREAS |==========|"<<endl;
	cout<<"\t\t\tESCOJA UNA OPCION: "<<endl;
	cout<<"\t\t\t1. ALTA DE EMPLEADOS"<<endl;
	cout<<"\t\t\t2. BUSCAR DE EMPLEADOS"<<endl;
	cout<<"\t\t\t3. CAMBIOS EMPLEADOS"<<endl;
	cout<<"\t\t\t4. CALCULO DE NOMINA"<<endl;
	cout<<"\t\t\t5. IMPRIMIR REPORTE DE NOMINA"<<endl;
	cout<<"\t\t\t0. SALIR DEL SISTEMA"<<endl;
	cout<<"\t\t|======================================|"<<"\n"<<endl;
	cout<<"INGRESE OPCION: "; cin>>opcion;

	switch(opcion){
		case 1:
			AltasEmpleado();
			cout<<"PRESIONE [1] PARA IR AL MENU PRINCIPAL [0] PARA SALIR DEL SISTEMA"<<endl;
			cin>>opcion;
			if(opcion==1){
				system("cls");
				Menu();
			}
			else if(opcion==0){
				system("exit");
			}
			else{
				system("color CF");
				cout<<"\n\t\t\tOPCION INVALIDA!"<<"\a"<<endl;
				Sleep(1000);
				system("cls");
				Menu();
			}
		break;
		case 2:
			BuscarEmpleado();
			cout<<"PRESIONE [1] PARA IR AL MENU PRINCIPAL [0] PARA SALIR DEL SISTEMA"<<endl;
			cin>>opcion;
			if(opcion==1){
				system("cls");
				Menu();
			}
			else if(opcion==0){
				system("exit");
			}
			else{
				system("color CF");
				cout<<"\n\t\t\tOPCION INVALIDA!"<<"\a"<<endl;
				Sleep(1000);
				system("cls");
				Menu();
			}
		break;
		case 3:
			CambiarEmpleado();
			cout<<"PRESIONE [1] PARA IR AL MENU PRINCIPAL [0] PARA SALIR DEL SISTEMA"<<endl;
			cin>>opcion;
			if(opcion==1){
				system("cls");
				Menu();
			}
			else if(opcion==0){
				system("exit");
			}
			else{
				system("color CF");
				cout<<"\n\t\t\tOPCION INVALIDA!"<<"\a"<<endl;
				Sleep(1000);
				system("cls");
				Menu();
			}
		break;
		case 4:
			system("cls");
			CalcularNomina();
			cout<<"PRESIONE [1] PARA IR AL MENU PRINCIPAL [0] PARA SALIR DEL SISTEMA"<<endl;
			cin>>opcion;
			if(opcion==1){
				system("cls");
				Menu();
			}
			else if(opcion==0){
				system("exit");
			}
			else{
				system("color CF");
				cout<<"\n\t\t\tOPCION INVALIDA!"<<"\a"<<endl;
				Sleep(1000);
				system("cls");
				Menu();
			}
		break;
		case 5:
			ImprimirNomina();
			cout<<"PRESIONE [1] PARA IR AL MENU PRINCIPAL [0] PARA SALIR DEL SISTEMA"<<endl;
			cin>>opcion;
			if(opcion==1){
				system("cls");
				Menu();
			}
			else if(opcion==0){
				system("exit");
			}
			else{
				system("color CF");
				cout<<"\n\t\t\tOPCION INVALIDA!"<<"\a"<<endl;
				Sleep(1000);
				system("cls");
				Menu();
			}
		break;
		case 0:
			system("exit");
		break;
		default:
			system("color CF");
			cout<<"\n\t\t\tOPCION INVALIDA!"<<"\a"<<endl;
			Sleep(1000);
			system("cls");
			Menu();
		break;
	}
}