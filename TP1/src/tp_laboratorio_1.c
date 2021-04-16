/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main(void) {
	int opcion;
	int operandoUno;
	int operandoDos;
	int operando1;
	int operando2;
	int existenResultados;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int resultadoFactorialUno;
	int resultadoFactorialDos;

	operando1=0;
	operando2=0;
	existenResultados=0;

	setbuf(stdout, NULL);
	do {
		if(operando1==0){
			printf("1. Ingresar primer operando A=X \n");
		}else{
			printf("1. Ingresar primer operando A=%d \n", operandoUno);
		}
		if(operando2==0){
			printf("2. Ingresar segundo operando B=Y \n");
		}else{
			printf("2. Ingresar segundo operando B=%d \n", operandoDos);
		}

		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. salir\n");
		printf("Elija una opcion: \n");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			operando1=1;
			operandoUno = ingresarNumero();
			break;
		case 2:
			operando2=1;
			operandoDos = ingresarNumero();
			break;
		case 3:
			if(operando1==0 || operando2==0){
				printf("No se ha ingresado algun operando, ingrese ambos para realizar las operaciones.\n");
			}else{
				existenResultados=1;
				resultadoSuma=suma(operandoUno,operandoDos);
				resultadoResta=resta(operandoUno,operandoDos);
				resultadoDivision=division((float)operandoUno,(float)operandoDos);
				resultadoMultiplicacion=multiplicacion(operandoUno,operandoDos);
				resultadoFactorialUno=factorial(operandoUno);
				resultadoFactorialDos=factorial(operandoDos);
			}

			break;
		case 4:
			if(existenResultados==0){
				printf("No existen resultados a mostrar.\n");
			}else{
				printf("El resultado de A+B es: %d \n",resultadoSuma);
				printf("El resultado de A-B es: %d \n",resultadoResta);
				if(operandoDos==0){
					printf("No es posible dividir por cero.\n");
				}else{
					printf("El resultado de A/B es: %.2f \n",resultadoDivision);
				}
				printf("El resultado de A*B es: %d \n",resultadoMultiplicacion);
				printf("El factorial de A es: %d y El factorial de B es: %d \n",resultadoFactorialUno,resultadoFactorialDos);
			}

			break;
		}

	} while (opcion != 5);
	return EXIT_SUCCESS;
}
