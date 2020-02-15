#include<iostream>
#include "GenerarNomina.h"
using namespace std;

//------- VARIABLES PARA INGRESOS --------//
int horasExtra;
float sueldoBase;
float sueldoExtra;
float sueldoBruto;
const float bonificacionIncentivo = 250;
float ingresosVariables;
//----------VARIABLES PARA DESCUENTOS--------------//
float cuotaIgss;
float impuestoISR;
float descuentosVariables;
float totalDescuentos;
//-------- SUELDO LIQUIDO-----//
float sueldoLiquido;

//-------FUNCIÓN CALCULOS RECIBE COMO PARÁMETRO DEL ARCHIVO DE TEXTO ABIERTO EN LA LIBRERIA CALCULAR NOMINA DE NOMBRE, SUELDO POR HORA Y PUESTO
void Calculos(string nombre, float sueldoHora, string puesto){
	//------- INGRESOS -----------------------------//
	cout<<"INGRESE HORAS EXTRA TRABAJADAS: ";
	cin>>horasExtra;
	sueldoBase=((sueldoHora*8)*30);
	sueldoExtra=(horasExtra*sueldoHora)*1.5;
	cout<<"COMPUTE INGRESOS VARIABLES: "<<endl;
	cin>>ingresosVariables;
	sueldoBruto=sueldoBase+sueldoExtra+bonificacionIncentivo+ingresosVariables;
	//-------------------- DESCUENTOS ------------------------//
	if(puesto!="Administrador"){
		cuotaIgss=sueldoBruto*0.0483;
	}
	if(sueldoBruto>5000&&sueldoBruto<=8000){
		impuestoISR=sueldoBruto*0.05;
	}
	else if(sueldoBruto>8000&&sueldoBruto<=12000)
	{
		impuestoISR=sueldoBruto*0.06;
	}
	else if(sueldoBruto>12000){
		impuestoISR=sueldoBruto*0.07;
	}
	cout<<"COMPUTE DESCUENTOS VARIABLES: ";
	cin>>descuentosVariables;
	totalDescuentos=cuotaIgss+impuestoISR+descuentosVariables;
	//--------TOTAL SUELDO-----//
	sueldoLiquido=sueldoBruto-totalDescuentos;
	GenerarNomina(nombre, sueldoBruto);
}