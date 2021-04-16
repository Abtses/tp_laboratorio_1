/*
 * Operaciones.h
 *
 *  Created on: 26 de mar. de 2021
 *      Author: Abel
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/**brief Funcion para ingresar un numero
 * param void
 * return el numero ingresado
 */
int ingresarNumero();

/**brief suma numeros los numeros ingresados
 * param int operandoUno
 * param int operandoDos
 * return resultado de la suma de los numeros ingresados
 */
int suma(int operandoUno,int operandoDos);

/**brief resta numeros los numeros ingresados
 * param int operandoUno
 * param int operandoDos
 * return resultado de la resta de los numeros ingresados
 */
int resta(int operandoUno, int operandoDos);

/**brief divide numeros los numeros ingresados
 * param int operandoUno
 * param int operandoDos
 * return resultado de la division de los numeros ingresados
 */
float division(float operandoUno, float operandoDos);

/**brief multiplica numeros los numeros ingresados
 * param int operandoUno
 * param int operandoDos
 * return resultado de la multiplicacion de los numeros ingresados
 */
int multiplicacion(int operandoUno, int operandoDos);

/**brief hace el factorial de un numero
 * param int operando
 * return resultado del factorial del numeros
 */
int factorial(int operando);

#endif /* OPERACIONES_H_ */
