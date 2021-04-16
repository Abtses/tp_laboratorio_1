/*
 * Operaciones.c
 *
 *  Created on: 26 de mar. de 2021
 *      Author: Abel
 */

#include "Operaciones.h"
#include <stdio.h>
#include <stdlib.h>

int ingresarNumero(){
	int numero;
	printf("ingrese el numero: ");
	scanf("%d",&numero);

	return numero;

}

int suma(int operandoUno,int operandoDos){
	int resultado;
	resultado=operandoUno+operandoDos;
	return resultado;
}

int resta(int operandoUno, int operandoDos){
	int resultado;
		resultado=operandoUno-operandoDos;
		return resultado;
}

float division(float operandoUno, float operandoDos){
	float resultado;
			resultado=operandoUno/operandoDos;
			return resultado;
}

int multiplicacion(int operandoUno, int operandoDos){
	int resultado;
			resultado=operandoUno*operandoDos;
			return resultado;
}

int factorial(int operando){
	int resultado;

	resultado=1;
	for(int i=operando-1;i>0;i--){
	        resultado+=resultado*i;
	    }
			return resultado;
}
