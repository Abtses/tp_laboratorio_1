#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"
#define X 3000

/*
 ============================================================================
 Name        : tp2_laboratorio_1.c
 Author      : Abel Robles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int len;
    int listId[X];

    LinkedList* listaEmpleados = ll_newLinkedList();

   do{
	    len=ll_len(listaEmpleados);
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2. *Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
    			"3. Alta de empleado\n"
    			"4. Modificar datos de empleado\n"
    			"5. Baja de empleado\n"
    			"6. Listar empleados\n"
    			"7. Ordenar empleados\n"
    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
    			"10. Salir\n");

    	getInt(&option,"ingrese la opcion: ");
        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv",listaEmpleados)!=0){
            		printf("\n Elementos desde texto cargados con exito. \n\n");
            		initIds(listaEmpleados,listId);
            	}else{
            		printf("\n ERROR DURANTE LA CARGA...\n\n");
            	}
                break;

            case 2:
            	if(controller_loadFromBinary("data.bin",listaEmpleados)!=0){
            		printf("\n Elementos desde binario cargados con exito. \n\n");
            		initIds(listaEmpleados,listId);
            	}else{
            		printf("\n ERROR DURANTE LA CARGA...\n\n");
            	}
            	break;

            case 3:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		controller_addEmployee(listaEmpleados,listId);
            	}
            	break;

            case 4:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		controller_ListEmployee(listaEmpleados);
            		controller_editEmployee(listaEmpleados);
            	}
            	break;

            case 5:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		controller_ListEmployee(listaEmpleados);
            		controller_removeEmployee(listaEmpleados);
            	}
            	break;

            case 6:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		controller_ListEmployee(listaEmpleados);
            	}
            	break;

            case 7:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		if(controller_sortEmployee(listaEmpleados)==1){
            			printf("\n Ordenado con exito.\n");
            		}else{
            			printf("\n ERROR AL ORDENAR \n");
            		}
            	}
            	break;

            case 8:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		if(controller_saveAsText("data.csv",listaEmpleados)!=0){
            			printf("\n Elementos guardados con exito. \n");
            		}else{
            			printf("\n ERROR AL GUARDAR\n");
            		}
            	}
            	break;

            case 9:
            	if(len<1){
            		printf("No hay elementos cargados. \n");
            	}else{
            		if(controller_saveAsBinary("data.bin",listaEmpleados)!=0){
            			printf("\n Elementos guardados con exito. \n");
            		}else{
            			printf("\n ERROR AL GUARDAR\n");
            		}
            	}
            	break;

            case 10:
            	printf("\nSaliendo...");
            	break;

            default:
            	printf("Opcion invalida. \n");
            	break;
        }
    }while(option != 10);

    return 0;
}

