/*
 * ArrayEmployees.c
 *
 *  Created on: 14 de may. de 2021
 *      Author: Abel
 */
#include "ArrayEmployees.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int initEmployees(Employee* list, int len)
{
	if(list==NULL || len<0){
		return -1;
	}else{
		for (int i = 0; i < len; i++)
		{
			(list+i)->isEmpty = TRUE;
		}
	}

	return 0;
}
int SaberListadoVacio(Employee listado[], int tam){
	int auxiliar=1;

	for(int i=0; i<tam; i++)
	{
		if(listado[i].isEmpty== FALSE){
			auxiliar=0;
			break;
		}
	}
	return auxiliar;
}
int initIds(ids list[], int len)
{
	if(list==NULL || len<0){
		return -1;
	}else{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
	}

	return 0;
}

int giveId(ids list[],int len){
	int index;
	int newId;

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	if(index==0){
		newId=1000;
	}else{
		newId=(list[index-1].id)+1;
	}
	list[index].id=newId;
	list[index].isEmpty=FALSE;

	return newId;
}

void removeId(ids list[],int len, int id){

	for(int i=0;i<len;i++){
		if(list[i].id==id){
			list[i].isEmpty=TRUE;
			break;
		}
	}
}

int BuscarLibre(Employee listado[], int tam)
{
	int i;
	int index;
	index = -1;

	for(i=0; i<tam; i++)
	{
		if(listado[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}

	return index;
}

int AltaEmpleado(Employee listado[],int tam,ids listId[]){

	int index;
	int status;
	index=BuscarLibre(listado,tam);

	if(index==-1)
	{
		printf("No hay espacio para cargar mas empleados\n");
		status=-1;
	}
	else
	{
		status=0;
		IngresoAlta(listado,tam, listId);
	}

	return status;
}
void IngresoAlta(Employee empleados[], int tam,ids listId[]){

	int id;
	char name[45];
	char lastName[45];
	float salary;
	int sector;

	printf("-- Ingreso de datos del empleado -- \n");


	id=giveId(listId,tam);

	printf("Nuevo ID del empleado es: %d\n",id);
	getString(name,45,"Ingrese su nombre: ");
	getString(lastName,45,"ingrese su apellido: ");
	getFloat(&salary,"ingrese su sueldo: ");
	getInt(&sector,"Ingrese su sector: ");

	addEmployee(empleados, tam,id,name,lastName,salary,sector);
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int index;

	if(list==NULL ||len<0){
		return -1;
	}else{
		index=BuscarLibre(list,len);
		(list+index)->id=id;
		strcpy(((list+index)->name),name);
		strcpy(((list+index)->lastName),lastName);
		(list+index)->salary=salary;
		(list+index)->sector=sector;
		(list+index)->isEmpty=FALSE;
	}
	return 0;
}

int printEmployees(Employee* list, int length){

	int i;

	for(i=0; i<length; i++){

		if(list[i].isEmpty==FALSE)
		{
			MostrarEmpleado(list[i]);
		}

	}

	return 0;
}

void MostrarEmpleado(Employee empleado)
{
	printf("%4d %15s %15s %.2f %d\n", empleado.id,
			empleado.lastName,
			empleado.name,
			empleado.salary,
			empleado.sector);
}

int findEmployeeById(Employee* list, int len,int id)
{
	int indice;

	if(list==NULL ||len<0||id<0){
		return -1;
	}else{
		for(int i=0; i<len; i++)
		{
			if(id == list[i].id)//Lo encontre
			{
				if(list[i].isEmpty == FALSE){
					indice=i;
					break;
				}
			}
		}

		return indice;
	}
}

void BajaProducto(Employee listado[], int tam,ids listId[]){
	int idIngresado;


	printEmployees(listado,tam);

	getInt(&idIngresado,"Ingrese el id a eliminar: ");
	removeEmployee(listado,tam,idIngresado,listId);


}

int removeEmployee(Employee* list, int len, int id,ids listId[])
{
	int indice;
	int respuesta;

	indice=findEmployeeById(list, len, id);
	if(indice==-1 || list==NULL || len<0){
		return -1;
		printf("El id ingresado no existe. \n");
	}else{
		MostrarEmpleado(list[indice]);
		getInt(&respuesta,"\n Esta seguro de eliminar este registro?(1=si cualquier otro numero sera tomado como no): ");
		if(respuesta==1){
			printf("\n Listado eliminado con exito.\n ");
			list[indice].isEmpty = TRUE;
			removeId(listId,len,id);
		}else{
			printf("\n Operacion cancelada. \n");
		}
	}
	return 0;
}

void ModificarEmpleado(Employee listado[], int tam){
	int idIngresado;
	int indice;
	int opcion;
	int dato;
	float datoFlotante;
	char datoCaracter[45];

	printEmployees(listado,tam);

	getInt(&idIngresado,"Ingrese el id a modificar: ");

	indice=findEmployeeById(listado, tam, idIngresado);

	if(indice==-1){
		printf("El id ingresado no existe. \n");
	}else{

		do{
			MostrarEmpleado(listado[indice]);

			printf("1. Apellido\n");
			printf("2. Nombre\n");
			printf("3. Salario\n");
			printf("4. Sector\n");
			printf("10. Salir\n");
			getInt(&opcion,"Elija una opcion a modificar: ");


			switch(opcion){
			case 1:
				getString(datoCaracter,15,"\nIngrese nuevo apellido: ");
				strcpy(listado[indice].lastName,datoCaracter);
				break;

			case 2:
				getString(datoCaracter,15,"\nIngrese nuevo Nombre: ");
				strcpy(listado[indice].lastName,datoCaracter);

				break;

			case 3:
				getFloat(&datoFlotante,"\nIngrese nuevo salario: ");
				while(datoFlotante<1){
					getFloat(&datoFlotante,"\nERROR. Ingrese salario valido: ");
				}
				listado[indice].salary=datoFlotante;
				break;

			case 4:
				do{
					getInt(&dato,"Ingrese el nuevo sector: \n");
				}while(dato<0);
				listado[indice].sector=dato;
				break;

			case 10:
				break;

			default:
				printf("\n Ingrese una opcion valida. ");
				break;
			}
		}while(opcion!=10);
	}
}

int sortEmployees(Employee* list, int len, int order)
{
	Employee auxiliar;
	/*
	if(order==1){
		order=MAX_PATH;
	}else{
		order=0;
	}
	*/
	if(list==NULL||len<0){
		return -1;
	}else{
		for(int i=0; i<len-1; i++){
			for(int j=i+1; j<len; j++){

				if(strcmp(list[i].lastName,list[j].lastName)>order)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
				if((list[i].lastName==list[j].lastName)){
					if(list[i].sector<list[j].sector){
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				}
			}
		}
	}
	return 0;
}

int obtenerPromedio(Employee listado[], int tam){
	int contador;
		float acumulador;
		float promedio;

		contador=0;
		acumulador=0;

		for(int i=0;i<tam;i++){
			if(listado[i].isEmpty==FALSE){
				contador++;
				acumulador+=listado[i].salary;
			}
		}
		if(contador==0){
			return 0;
		}

		promedio=acumulador/contador;

		return promedio;
}

void listarPromedio(Employee listado[], int tam){
	float promedio;
	int contador;
	contador=0;

	promedio=obtenerPromedio(listado,tam);

	for(int i=0;i<tam;i++){
		if((listado[i].salary >= promedio) && listado[i].isEmpty==FALSE){
			contador++;
		}
	}
	printf("El salario promedio es: %.2f \n",promedio);
	printf("Personas que ganan el promedio o mas: %d \n",contador);
}
