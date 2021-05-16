/*
 ============================================================================
 Name        : tp2_laboratorio_1.c
 Author      : Abel Robles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"
#define TRUE 1
#define FALSE 0
#define X 10

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int vacio;

	Employee employeesArray[X];
	initEmployees(employeesArray, X);

	ids arrayID[X];
	initIds(arrayID,X);

	do {
		vacio=SaberListadoVacio(employeesArray,X);
		printf("1. ALTA empleado\n");
		printf("2. MODIFICACION empleado\n");
		printf("3. BAJA empleado\n");
		printf("4. INFORMES\n");

		printf("10. Salir\n\n");
		getInt(&opcion, "Elija una opcion: ");

		switch (opcion) {

		case 1:
			AltaEmpleado(employeesArray, X,arrayID);
			break;
		case 2:
			if(vacio==1){
				printf("No hay elementos cargados. \n");
			}else{
				ModificarEmpleado(employeesArray, X);
			}
			break;

		case 3:
			if(vacio==1){
				printf("No hay elementos cargados. \n");
			}else{
				BajaProducto(employeesArray,X,arrayID);
			}

			break;

		case 4:
			if(vacio==1){
				printf("No hay elementos cargados. \n");
			}else{
				do {
					printf(	"--Informes--\n"
							"1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
							"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
							"5.Salir\n\n");
					getInt(&opcion, "Elija una opcion: ");
					switch (opcion) {
					case 1:
						sortEmployees(employeesArray,X,0);
						printEmployees(employeesArray,X);
						break;
					case 2:
						listarPromedio(employeesArray,X);
						break;
					case 5:
						printf("Saliendo de informes... \n\n");
						break;
					}
				} while (opcion != 5);
			}


			break;
		case 10:
			printf("Saliendo... \n");
			break;
		default:
			printf("Opcion invalida. \n");
			break;
		}
	} while (opcion != 10);

	return EXIT_SUCCESS;
}
