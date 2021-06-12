#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee) {
	if (pFile != NULL && pArrayListEmployee != NULL) {
		char string[50];
		char horas[50];
		char entero[50];
		char sueldo[50];
		Employee *lec;

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", entero, string, horas,
				sueldo);
		while (!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", entero, string, horas,
					sueldo);
			lec = employee_new();
			lec->id = atoi(entero);
			strcpy(lec->nombre, string);
			lec->horasTrabajadas = atoi(horas);
			lec->sueldo = atoi(sueldo);
			//printf("%d--%s--%s\n",lectura.id,lectura.nombre,lectura.apellido);
			ll_add(pArrayListEmployee, lec);
		}
		return 1;
	}
	return 0;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee){
	if (pFile != NULL && pArrayListEmployee != NULL){
		int id;
		int horasTrabajadas;
		int sueldo;
		Employee *lec;
		int flagSucc;
		flagSucc=0;
		while (!feof(pFile)){
			lec = employee_new();
			fread(lec, sizeof(Employee), 1, pFile);

			employee_getId(lec, &id);
			employee_getHorasTrabajadas(lec, &horasTrabajadas);
			employee_getSueldo(lec, &sueldo);

			if (id != 0 && horasTrabajadas != 0 && sueldo != 0){
				ll_add(pArrayListEmployee, lec);
				flagSucc=1;
			}
		}
		if(flagSucc!=0){
			return 1;
		}
	}
	return 0;
}
