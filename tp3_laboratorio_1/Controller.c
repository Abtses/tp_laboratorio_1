#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee) {
	if (path != NULL || pArrayListEmployee != NULL) {
		FILE* pArch=fopen(path,"r");
		parser_EmployeeFromText(pArch,pArrayListEmployee);
		fclose(pArch);
		return 1;
	}
	return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee) {
	if(path != NULL && pArrayListEmployee != NULL){
		int status;
		FILE* pArch = fopen(path,"rb");
		status=parser_EmployeeFromBinary(pArch, pArrayListEmployee);
		fclose(pArch);
		if(status==0){
			return 0;
		}
		return 1;
	}
	return 0;
}
int initIds(LinkedList* pArrayListEmployee,int list[]){

	if(pArrayListEmployee!=NULL){
		Employee* aux;
		int len;
		len=ll_len(pArrayListEmployee);
		for(int i=0;i<len;i++){
			aux=ll_get(pArrayListEmployee,i);
			list[i]=aux->id;
			//printf("%d \n",list[i]);
		}
		return 1;
	}
	return 0;
}
int idAutoIncremental(LinkedList* this,int list[]){
	if(this!=NULL && list!=NULL){
		int len;
		int aux;
		int incremental;
		len=ll_len(this)+1;
		aux=0;
		for(int i=0;i<len;i++){
			if(list[i]>aux){
				aux=list[i];
			}
		}
		incremental=aux+1;
		return incremental;
	}
	return -1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int list[]) {

	if(pArrayListEmployee!=NULL){
		Employee* empleado;
		int entero;
		int idUp;
		char stringId[50];
		char stringNombre[50];
		char stringHoras[50];
		char stringSueldo[50];
		int len;
		len=ll_len(pArrayListEmployee);

		printf("*---INGRESO DE NUEVO EMPLEADO---*\n\n");

		idUp=idAutoIncremental(pArrayListEmployee,list);
		itos(idUp,stringId);
		printf("Nuevo id para el Empleado: %s \n",stringId);


		getString(stringNombre,50,"Ingrese el nombre del empleado: ");

		getInt(&entero,"Ingrese las horas trabajadas: ");
		while(entero<1){
			getInt(&entero,"ERROR ingrese un numero valido. Ingrese las horas trabajadas: ");
		}
		itos(entero,stringHoras);

		getInt(&entero,"Ingrese el sueldo: ");
		while(entero<1){
			getInt(&entero,"ERROR ingrese un numero valido. Ingrese el sueldo: ");
		}
		itos(entero,stringSueldo);
		empleado=employee_newParametros(stringId,stringNombre,stringHoras,stringSueldo);

		if(empleado!=NULL){
			ll_add(pArrayListEmployee,empleado);
			list[len]=idUp;
			return 1;
		}
	}
	return 0;
}
int findById(LinkedList* pArray, int id){
	if(pArray==NULL || id<0){
		return -1;
	}else{
		Employee* auxiliar;

		for(int i=0;i<ll_len(pArray);i++){
			auxiliar=(Employee*)ll_get(pArray,i);
			if(auxiliar->id==id){
				return i;
			}
		}
		return -1;
	}
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) {
	if(pArrayListEmployee!=NULL){
		int entero;
		int id;
		Employee* auxiliar;
		int respuesta;
		char string[50];
		int integer;

		getInt(&entero,"Ingrese el ID del empleado a modificar: ");
		id=findById(pArrayListEmployee,entero);
		if(id==-1){
			printf("\n ERROR. Id no encontrado \n");
		}else{
			auxiliar=ll_get(pArrayListEmployee,id);
			do{
				employee_show(auxiliar);
				printf("\n1.Nombre.\n"
					"2.Horas trabajadas.\n"
					"3.Sueldo.\n"
					"4.Salir\n");
			getInt(&respuesta,"Ingrese el campo a modificar: ");
			switch(respuesta){
			case 1:
				getString(string,50,"Ingrese el nuevo nombre: ");
				employee_setNombre(auxiliar,string);
				break;
			case 2:
				getInt(&integer,"Ingrese las horas trabajadas: ");
				while(integer<1){
					getInt(&integer,"ERROR. Ingrese las horas trabajadas: ");
				}
				employee_setHorasTrabajadas(auxiliar,integer);
				break;
			case 3:
				getInt(&integer,"Ingrese el nuevo sueldo: ");
				while(integer<1){
					getInt(&integer,"ERROR. Ingrese el nuevo sueldo: ");
				}
				employee_setSueldo(auxiliar,integer);
				break;
			case 4:
				printf("\nVolviendo al menu...\n");
				break;
			default:
				printf("\nOPCION INVALIDA\n");
				break;
			}
			ll_set(pArrayListEmployee,id,auxiliar);
			}while(respuesta!=4);
			return 1;
		}
	}
	return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {
	if(pArrayListEmployee!=NULL){
		int entero;
		int id;
		Employee* auxiliar;
		int respuesta;

		getInt(&entero,"Ingrese ID del empleado a remover: ");
		id=findById(pArrayListEmployee,entero);
		if(id==-1){
			printf("\n ERROR. Id no encontrado \n");
		}else{
			auxiliar=(Employee*)ll_get(pArrayListEmployee,id);
				employee_show(auxiliar);
				getInt(&respuesta,"Esta seguro de remover este empleado? (1=si. Cualquier otro numero sera tomado como no)");
				if(respuesta==1){
					ll_remove(pArrayListEmployee,id);
					printf("Usuario eliminado con exito. \n");
				}else{
					printf("Cancelando.. volviendo al menu. \n");
				}
				return 1;
		}
	}
	return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {

	if(pArrayListEmployee!=NULL){
	Employee*paux;
		for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
			paux=(Employee*)ll_get(pArrayListEmployee,i);
			employee_show(paux);
		}
	return 1;
	}
	return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {
	if(pArrayListEmployee!=NULL){
		ll_sort(pArrayListEmployee,(void*)employee_compareByName,1);
		return 1;
	}
	return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee) {
	if (pArrayListEmployee != NULL && path!=NULL){
		FILE *pArch;
		Employee *lec;
		int len = ll_len(pArrayListEmployee);

		if ((pArch = fopen(path, "w")) != NULL){
			fprintf(pArch, "id,nombre,horasTrabajadas,sueldo\n");
			for (int i = 0; i < len; i++){
				lec = (Employee*)ll_get(pArrayListEmployee, i);
				fprintf(pArch, "%d,%s,%d,%d\n",lec->id,lec->nombre,lec->horasTrabajadas,lec->sueldo);
			}
			fclose(pArch);
		}
		return 1;
	}
	return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee) {
	if (pArrayListEmployee != NULL && path!=NULL){
		FILE *pArch;
		Employee *lec;
		int len = ll_len(pArrayListEmployee);

		if ((pArch = fopen(path, "wb")) != NULL){
			for (int i = 0; i < len; i++){
				lec = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(lec, sizeof(Employee), 1, pArch);
			}
			fclose(pArch);
		}
		return 1;
	}
	return 0;
}

