#include "Employee.h"
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


Employee* employee_new()//devuelve un puntero
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if(nuevo != NULL)//si no es null inicializo los campos de la variable de tipo estructura a la que apunta nuevo
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->sueldo = 0;
        nuevo->horasTrabajadas=0;
    }
    return nuevo;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,int sueldo)
{
    int id=atoi(idStr);

    Employee* nuevo = employee_new();//puntero con la direccion dinamina
    if( nuevo != NULL)
    {
        if(employee_setId(nuevo, id) &&
                employee_setNombre(nuevo, nombreStr)&&
           employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr))&&
                employee_setSueldo(nuevo, sueldo))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if( this != NULL && id >= 10000 && id <= 20000)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
         if( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this!= NULL && horasTrabajadas !=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
//-------------------------------------------------
int employee_compareById(void* emp1,void* emp2)
{
    int retorno=0;
    int id1;
    int id2;
    employee_getId((Employee*) emp1, &id1);// le carga a id1 el valor que hay en el id del emp1
    employee_getId((Employee*) emp2, &id2);
    if(id1 > id2){
        retorno=1;
    }else if(id2 > id1){
        retorno=-1;
    }

    return retorno;
}
int employee_compareByName(void* emp1,void* emp2)
{
     char nombre1[50];
    char nombre2[50];
    int retorno = 0;

    employee_getNombre((Employee*) emp1, nombre1);
    employee_getNombre((Employee*) emp2, nombre2);

    if(strcmp(nombre1, nombre2) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombre1, nombre2) < 0)
    {
        retorno = -1;
    }

    return retorno;


}
int employee_compareByHorasTrabajadas(void* emp1,void* emp2)
    {
       int retorno=0;
    int horas1;
    int horas2;
    employee_getHorasTrabajadas((Employee*) emp1, &horas1);
    employee_getHorasTrabajadas((Employee*) emp2, &horas2);
    if(horas1 > horas2){
        retorno=1;
    }else if(horas1 < horas2){
        retorno=-1;
    }

    return retorno;
    }
int employee_compareBySueldo(void* emp1,void* emp2)
{
    int retorno=0;
    int sueldo1;
    int sueldo2;
    employee_getSueldo((Employee*) emp1, &sueldo1);// le carga a id1 el valor que hay en el id del emp1
    employee_getSueldo((Employee*) emp2, &sueldo2);
    if(sueldo1 > sueldo2){
        retorno=1;
    }else if(sueldo2 > sueldo1){
        retorno=-1;
    }

    return retorno;
}
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

