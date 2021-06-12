#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

Employee* employee_new(){
	Employee* employ;
	employ=(Employee*)malloc(sizeof(Employee));

	return employ;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
	Employee* employ;
	employ=employee_new();

	if(idStr!=NULL||nombreStr!=NULL||horasTrabajadasStr!=NULL||sueldoStr!=NULL){
		employ->id=atoi(idStr);
		strcpy(employ->nombre,nombreStr);
		employ->horasTrabajadas=atoi(horasTrabajadasStr);
		employ->sueldo=atoi(sueldoStr);
		return employ;
	}
	return NULL;
}

int employee_setId(Employee* this,int id)
{
	if (this != NULL)
	{
		this->id = id;
		return 1;
	}
	return 0;
}

int employee_getId(Employee* this,int* id){
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		return 1;
	}
	return 0;
}

int employee_setNombre(Employee* this,char* nombre){
	if (this != NULL)
	{
		strcpy(this->nombre, nombre);
		return 1;
	}
	return 0;
}
int employee_getNombre(Employee* this,char* nombre){
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		return 1;
	}
	return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		return 1;
	}
	return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		return 1;
	}
	return 0;
}

int employee_setSueldo(Employee* this,int sueldo){
	if (this != NULL)
	{
		this->sueldo = sueldo;
		return 1;
	}
	return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		return 1;
	}
	return 0;
}
int* employee_compareByName(Employee *employ1, Employee *employ2){
	int* comparacion=0;
	if(employ1!=NULL && employ2!=NULL){
		comparacion=(int*)strcmp(employ1->nombre,employ2->nombre);
	}
	return comparacion;
}

int employee_show(Employee* employ){
	if(employ!=NULL){
		int id;
		char nombre[50];
		int horasTra;
		int sueldo;

		employee_getId(employ,&id);
		employee_getNombre(employ,nombre);
		employee_getHorasTrabajadas(employ,&horasTra);
		employee_getSueldo(employ,&sueldo);

		printf("%d--%s--%d--%d\n",id,nombre,horasTra,sueldo);
		return 1;
	}
	return 0;
}

