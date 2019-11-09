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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    Employee* auxEmpleado=NULL;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];


    int sueldo;
    char nombre[50];
    //int horasTrabajadas;
    int cant;
    int r;
    if(pFile != NULL){
        while( !feof(pFile)){
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas ,auxSueldo);//devolvera la cantidad que pudo cargar
        if( cant == 4)//si pudo cargar los cuatro
        {
            //id = atoi(auxId);//funcion que convierte el parametro ingresado a tipo int
            strcpy(nombre, auxNombre);
            sueldo = atoi(auxSueldo);//funcion que convierte el parametro ingresado a tipo float
            //horasTrabajadas = atoi(auxHorasTrabajadas);
            auxEmpleado = employee_newParametros(auxId, nombre,auxHorasTrabajadas, sueldo);

            if( auxEmpleado != NULL)
            {
                r = ll_add(pArrayListEmployee,(Employee*)auxEmpleado);//guarda el puntero en una posicion de la lista
                if(r==0){
                    printf(" Se agrego a la lista con exito\n ");
                    todoOk=1;
                }else if(r==-1){
                    printf(" No se pudo agregar elemento a la lista\n ");
                }
        }
    }
        }
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
 Employee* aux=NULL;
int todoOk=-1;
int cant;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            aux = employee_new();
            if(aux!=NULL){
               cant= fread(aux,sizeof(Employee),1,pFile);
               if(cant==1){
                ll_add(pArrayListEmployee,aux);
                todoOk=1;
               }

            }

        }

        }
        return todoOk;
    }
