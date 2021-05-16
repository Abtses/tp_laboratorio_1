/*
 * ArrayEmployees.h
 *
 *  Created on: 14 de may. de 2021
 *      Author: Abel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;

 int isEmpty;
}typedef Employee;

struct
{
 int id;

 int isEmpty;
}typedef ids;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** verifica que el array esta vacio
 * \param list Employee
 * \param len int Array length
 * \retorna 1 si esta vacio, 0 si hay almenos un elemento
 *
 */
int SaberListadoVacio(Employee listado[], int tam);

/** inicia el arrays de id
 * \param list ids
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initIds(ids list[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
void IngresoAlta(Employee empleados[], int tam,ids listId[]);
int AltaEmpleado(Employee listado[],int tam,ids listId[]);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);
void MostrarEmpleado(Employee empleado);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - any number>-1 if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id,ids listId[]);
void BajaProducto(Employee listado[], int tam,ids listId[]);

void ModificarEmpleado(Employee listado[], int tam);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

void listarPromedio(Employee listado[], int tam);

#endif /* ARRAYEMPLOYEES_H_ */
