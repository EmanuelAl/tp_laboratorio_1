#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "imput.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* pFile=NULL;
    pFile=fopen(path,"r");//modo lectura
    if(pFile!=NULL){
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        todoOk=1;
    }
    fclose(pFile);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* pFile=NULL;
    pFile=fopen(path,"r");//modo lectura
    if(pFile!=NULL){
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        todoOk=1;
    }
    fclose(pFile);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
     Employee* pEmpleado;
    int todoOk = -1;

    int idAuxiliar;

    char nombre[50];
    char sueldo[50];
    int sueldoAux;
    char horas[50];
    int horasAux;

    pEmpleado = employee_new();

    if(pArrayListEmployee != NULL)
    {

        idAuxiliar = controller_nextID(pArrayListEmployee);

                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(nombre);

                    while(esSoloLetras(nombre)==0)
                    {
                        printf("Nombre no valido. Intente nuevamente : ");
                        fflush(stdin);
                        gets(nombre);
                    }


                    printf("Ingrese sueldo: ");
                    fflush(stdin);
                    gets(sueldo);

                    while(esNumerico(sueldo)==0)
                    {
                        printf("Sueldo no valido. Intente nuevamente :  ");
                        fflush(stdin);
                        gets(sueldo);
                    }
                    sueldoAux= atoi(sueldo);


                printf("Ingrese horas trabajadas: ");
                    fflush(stdin);
                    gets(horas);

                    while(esNumerico(horas)==0)
                    {
                        printf("Horas no validas. Intente nuevamente :  ");
                        fflush(stdin);
                        gets(horas);
                    }

                    horasAux= atoi(horas);

        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, idAuxiliar);
            employee_setNombre(pEmpleado, nombre);
            employee_setSueldo(pEmpleado, sueldoAux);
            employee_setHorasTrabajadas(pEmpleado, horasAux);
            ll_add(pArrayListEmployee, pEmpleado);
            todoOk = 1;
        }
    }
    return todoOk;

}
int controller_nextID(LinkedList* pArrayListEmployee)
    {
        int id = 0;
        int idAnterior;
        int idActual;
        Employee* pEmployee;
        int listLen;
        int i;

        if(pArrayListEmployee != NULL)
        {
            listLen = ll_len(pArrayListEmployee);
                if(listLen > 0)
                {
                    for(i = 0; i<listLen; i++)
                        {
                            pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                            employee_getId(pEmployee,&idActual);
                            if(idActual > id)
                            {
                                idAnterior = id;
                                id = idActual;
                                    if(idAnterior + 1 != id)
                                    {
                                        id = idAnterior;
                                        break;
                                    }
                            }
                        }
                    id++;

                }
            else
            {
                id = 1;
            }
        }
        return id;
    }

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
      Employee* empleado;

    int todoOk = -1;
    int i;

    char idStr[10];
    int idIngresado;
    int idObtenido;

    char opcionStr[50];
    int opcionInt;

    char nombre[50];

    char sueldoStr[50];
    int sueldoInt;

    char horasStr[50];
    int horasInt;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el id del empleado a modificar : ");
        fflush(stdin);
        gets(idStr);

        while(esNumerico(idStr)==0)
        {
            printf("id no valido. Intente nuevamente : ");
            fflush(stdin);
            gets(idStr);
        }
        idIngresado=atoi(idStr);

        for(i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&idObtenido);

            if(idObtenido == idIngresado)
            {

                printf(" \n Modificar: \n ");
                printf(" 1) Nombre \n");
                printf("2) Sueldo \n");
                printf("3) Horas trabajadas \n");

                printf("\nIngrese opcion: ");
                fflush(stdin);
                gets(opcionStr);

                while(esNumerico(opcionStr)==0)
                {
                    printf("Opcion no valida. Intente nuevamente : ");
                    fflush(stdin);
                    gets(opcionStr);
                }
                opcionInt=atoi(opcionStr);

                switch(opcionInt)
                {
                case 1:
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(nombre);

                    while(esSoloLetras(nombre)==0)
                    {
                        printf("Nombre no valido. Intente nuevamente : ");
                        fflush(stdin);
                        gets(nombre);
                    }

                    stringToUpper(nombre);
                    todoOk = 1;
                    employee_setNombre(empleado, nombre);
                    break;

                case 2:
                    printf("Ingrese sueldo: ");
                    fflush(stdin);
                    gets(sueldoStr);

                    while(esNumerico(sueldoStr)==0)
                    {
                        printf("Sueldo no valido. Intente nuevamente : ");
                        fflush(stdin);
                        gets(sueldoStr);
                    }

                    sueldoInt= atoi(sueldoStr);
                    todoOk = 1;
                    employee_setSueldo(empleado, sueldoInt);
                    break;

                case 3:
                    printf("Ingrese horas :  ");
                    fflush(stdin);
                    gets(horasStr);

                    while(esNumerico(horasStr)==0)
                    {
                        printf("Horas no validas. Intente nuevamente : ");
                        fflush(stdin);
                        gets(horasStr);
                    }

                    horasInt= atoi(horasStr);
                    todoOk = 1;
                    employee_setHorasTrabajadas(empleado, horasInt);
                    break;

                default:
                    printf("Opcion no valida ");
                }
            }
        }
    }


    return todoOk ;

}

/** \brief Baja de empleado
 *

 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     Employee* empleado;

    int todoOk = -1;

    char idStr[10];
    int idIngresado;
    int idObtenido;

    int confirm;


    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el id del empleado a dar de baja : ");
        fflush(stdin);
        gets(idStr);

        while(esNumerico(idStr)==0)
        {
            printf("id no valido. Intente nuevamente : ");
            fflush(stdin);
            gets(idStr);
        }
        idIngresado=atoi(idStr);

        for(int i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&idObtenido);

            if(idObtenido == idIngresado)
            {
            printf("Confirma  la baja del empleado ? ");
            printf("1- si\n");
            printf("2- no\n");
            scanf("%d",&confirm);
          while(confirm!=1 || confirm!=2){

            printf("\n confirmacion invalida. Intente nuevamente : ");
            scanf("%d",&confirm);
          }
            if(confirm==1)
                {
                    employee_delete(empleado);
                    ll_remove(pArrayListEmployee,i);
                    printf("\n\n Se dio de baja empleado\n");
                todoOk=1;
            }
            else if(confirm==2)
            {
                printf("\n\nOperacion cancelada\n");

            }

        }
    }

}
return todoOk;
}

/** \brief Listar empleados
 *

 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    char nombre[50];
    int id;
    int sueldo;
    int horasTrabajadas;

    Employee* pEmp;

    if(pArrayListEmployee != NULL)
    {

        printf("\n\n ID \t\t   NOMBRE \t\t SUELDO \t\tHORAS TRABAJADAS \n\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            employee_getNombre(pEmp, nombre);
            employee_getId(pEmp,&id);
            employee_getSueldo(pEmp,&sueldo);
            employee_getHorasTrabajadas(pEmp,&horasTrabajadas);

            printf("%d  %20s %20d %20d \n", id, nombre, sueldo, horasTrabajadas);
        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
 int todoOk = -1;
int opcion;
    if(pArrayListEmployee != NULL)
    {

                printf("Ordenar... \n ");
                printf(" 1) Por Nombre \n");
                printf(" 2) Por Sueldo \n");
                printf(" 3) Por horas trabadas.\n");

                printf("\n ingresa opcion: ");
                scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    ll_sort(pArrayListEmployee, employee_compareByName, 1);
                    break;
                case 2:

                    ll_sort(pArrayListEmployee, employee_compareBySueldo, 1);
                    break;
                case 3:

                    ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 1);
                    break;
                default:
                    printf("\nOpcion invalida!");
            }

        todoOk = 0;
    }

    return todoOk ;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* aux;

    int todoOk = -1;

    int* auxId;
    char* auxNombre;
    int* auxSalario;
    int* auxHoras;

    if(pArrayListEmployee != NULL && path != NULL)
    {

        auxId = malloc(sizeof(int));
        auxNombre = malloc(sizeof(char)*100);
        auxSalario = malloc(sizeof(int));
        auxHoras = malloc(sizeof(int));

        f = fopen(path, "w");
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            employee_getId(aux,auxId);
            employee_getSueldo(aux,auxSalario);
            employee_getNombre(aux, auxNombre);
            employee_getHorasTrabajadas(aux,auxHoras);
            fprintf(f,"%d,%s,%d,%d\n",*auxId,auxNombre,*auxSalario,*auxHoras);

            todoOk=1;
        }

        free(auxNombre); free(auxId); free(auxSalario); free(auxHoras);
        fclose(f);
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
        FILE* f=NULL;
        Employee* auxEmployee;

    int todoOk = -1;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path,"wb");

        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);//obtengo cada elemento del array
            fwrite(auxEmployee, sizeof(Employee),1,f);
        }
        todoOk=1;

    }
     fclose(f);
    return todoOk;
}

