//PROGRAMA HIJO 2.1 - CALCULAR NÓMINAS
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

void BuscarEmpleado();
void CalcularNomina(float pagoHora, string puesto);
void GenerarNomina(string nombre, float sueldo);
void VerArchivoNomina();
void Menu();

int main(){
	Menu();
	system("PAUSE");
	return 0;
}
//----------------------------- DIAGRAMA HIJO 2.1 -----------------------------//
//AUTOR: DIEGO VÁSQUEZ//
//--- VARIABLES PARA LECUTRA DE LOS DATOS PERSONALES DEL EMPLEADO ---//
int id;
char nombre[60];
char puesto[100];
float phora;
int resp;

/*--- FUNCIÓN: BUSCAR EMPLEADO
	¿CUÁL ES SU FINALIDAD?
		MEDIANTE UN CICLO WHILE DICHA FUNCIÓN VA RECORRIENDO TODOS LOS REGISTROS DEL ARCHIVO, PERO ANTES DE CONCLUIR 
		MANDA A LLAMAR A LA FUNCIÓN CalcularNomina PARA HACER UN CALCULO MASIVO Y AUTOMATIZADO DE LOS EMPLEADOS

		SU OBJETIVO ES AHORRAR TIEMPO Y HACER EL CALCULO MASIVAMENTE
*/

void BuscarEmpleado(){
	//----- BORRAMOS EL ARCHIVO ANTERIOR YA QUE DESEAMOS OBTENER LOS DATOS ACTUALES ---//
	ofstream borrarViejaNomina;
	borrarViejaNomina.open("BDnomina.txt", ios::out);

	if(borrarViejaNomina.is_open()){
		borrarViejaNomina<<""<<endl;
	}
	else{
		cout<<"ERROR!"<<endl;
	}
	borrarViejaNomina.close();
	//----------PROCESO DE BUSQUEDA Y CALCULO-------------//
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
		}
	}
	else{
		cout<<"ERROR EN CONSULTA"<<endl;
	}
	lecturaArchivo.close();
	cout<<"PRESIONE LA TECLA (1) PARA VER EL ARCHIVO DE NOMINA, PRESIONE (0) PARA SALIR AL MENU PRINCIPAL"<<endl;
	cin>>resp;
	if(resp==1){
		VerArchivoNomina();
		cout<<"PRESIONE 1 PARA IR AL MENU PRINCIPAL"<<endl;
		cin>>resp;
		if(resp==1){
			Menu();
		}
		else{
			system("exit");
		}
	}
	else{
		Menu();
	}
}

//---- VARIABLES UTILES PARA EL CALCULO DE LA NOMINA ---///
float ingresosFijos;
float ingresosVariables;
const int bonIncentivo=250;
float sueldoExtra;
float descuentosFijos;
float igss;
float isr;
int horasTrabajadas;

//--------- TAL COMO SE MENCIONÓ EN LA FUNCIÓN BuscarEmpleado() ESTA FUNCIÓN ES LLAMADA POR LA MISMA Y EJECUTA EL CÁLCULO DEL EMPLEADO
// EN DONDE EL CICLO AÚN ESTÁ LEYENDO DENTRO DEL ARCHIVO. FINALMENTE LOS DATOS SE VAN A LA FUNCIÓN GenerarNomina() DONDE SE GUARDARÁ
// LA INFORMACIÓN DEL EMPLEADO E IMPRIMIR SU RECIBO DE PAGO SALARIAL

void CalcularNomina(float pagoHora, string puesto){
	cout<<"INGRESE HORAS TRABAJADAS: ";
	cin>>horasTrabajadas;
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
	GenerarNomina(nombre, ingresosFijos);
}

//RECIBE COMO PARÁMETROS EL NOMBRE Y EL SUELDO LIQUIDO Y GENERA LA INFORMACIÓN QUE SE VA A LA BDnomina.txt

void GenerarNomina(string nombre, float sueldo){
	ofstream generarNomina;
	generarNomina.open("BDnomina.txt", ios::out|ios::app);

	if(generarNomina.is_open()){
		generarNomina<<nombre<<" "<<sueldo<<endl;
	}
	else{
		cout<<"ERROR!"<<endl;
	}
	generarNomina.close();
}

//SU OBJETIVO MOSTRAR QUE TODO ESTÉ OK, DE LO CONTRARIO SE REPETIRÁ EL PROCEDIMIENTO DE CÁLCULO//

void VerArchivoNomina(){
	ifstream verNomina;
	verNomina.open("BDnomina.txt", ios::in);
	if(verNomina.is_open()){
		cout<<"COSULTA REALIZADA..."<<endl;
		verNomina>>nombre;
		while(!verNomina.eof()){
			verNomina>>ingresosFijos;
			cout<<"NOMBRE: "<<nombre<<endl;
			cout<<"SUELDO: "<<ingresosFijos<<endl;
			verNomina>>nombre;
		}
	}
	else{
		cout<<"ERROR EN CONSULTA"<<endl;
	}
	verNomina.close();
}
//-----------------------------------------------------------------//
int opcionesNomina;

void Menu(){
	system("cls");
	cout<<"SOFTWARE PARA CALCULAR NOMINAS 1.0"<<endl;
	cout<<"|\t\t\tTHE HACKERS CORP.\t|"<<endl;
	cout<<"SELECCIONE UNA OPCION: "<<endl;
	cout<<"1. REGISTRAR NUEVO EMPLEADO"<<endl;
	cout<<"2. BUSCAR EMPLEADO"<<endl;
	cout<<"3. MODIFICAR EMPLEADO"<<endl;
	cout<<"4. CALCULAR NOMINAS DE EMPLEADOS"<<endl;
	cout<<"5. IMPRIMIR REGISTRO DE NOMINAS"<<endl;
	cout<<"\n";
	cin>>opcionesNomina;
	switch(opcionesNomina){
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
			BuscarEmpleado();
			break;
			case 5:
			break;
			default:
			system("exit");
	}
	system("cls");
}