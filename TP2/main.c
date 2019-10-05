#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#include "funciones.h"
#define TAMe 8

int menuSort();
int menu();
void informsEmployees(Employee employees[], int len);

float totalSalary(Employee e[],int len);
void showEmployeeSalary(Employee x);
void printEmployeesSalary(Employee list[],int len);
float getAverageSalary(Employee e[],int len);
int numExceedPromedio(Employee e[],int len);
int menuInforms();

int main()
{
    Employee list[TAMe];

    initEmployees(list,TAMe);

    int id=20000;
    char salir='n';

    id=id + hardcodeoEmployees(list,TAMe,8);
    do
    {
        switch(menu())
        {

        case 1:
            printf("1-High Employee\n");

            if(addEmployee(list,TAMe,id)) //si alta devuelve true osea 1 se hace lo que esta dentro de la condicion.
            {
                id++;
            }

            break;

        case 2:

            removeEmployee(list,TAMe);
            break;

        case 3:
            printf("3-Modify Employee\n");
            modifyEmployee(list,TAMe);
            break;

        case 4:
            printEmployees(list,TAMe);
            //
            break;

        case 5:
            sortEmployeesByLastNameSector(list,TAMe,menuSort());

            break;
        case 6:
            printf("Informs \n");
            informsEmployees(list,TAMe);
            break;

        case 7:
            printf("Confirm get out?¿ \n");
            fflush(stdin);
            salir=getchar();
            //
            break;

        default:
            printf("Invalid option \n");

        }
        system("pause");
    }
    while(salir =='n');

    return 0;
}
int menu()
{

    int option;
    system("cls");
    printf("menu de options\n\n");
    printf("1-High Employee\n");
    printf("2-low Employee\n");
    printf("3-Modify Employee\n");
    printf("4-List Employees\n");
    printf("5-Order Employees\n");
    printf("6-Informs \n");
    printf("7- Get out\n");
    printf("Enter option :\n");
    scanf("%d",&option);

    return option;

}
int menuSort()
{
    int option;
    system("cls");
    printf("******** Order Employee********\n");
    printf(" Enter 1 for order in ascending \n");
    printf(" Enter 0 for order in descending \n");
    //printf(" Enter option:");
    //scanf("%d",&option);

    getNumero(&option," Enter option: "," invalid opcion \n",0,1,3);

    return option;
}
int menuInforms()
{
    int option;

    system("cls");
    printf("****** Informs Employees *******\n\n");
    printf("1-Show list of Employees sorted alphabetically by last name and sector\n");
    printf("2-Show total salary , average and how many employees exceed the average salary \n");
    printf("5- Get out\n");
    printf(" Enter option:");
    scanf("%d",&option);

    return option;
}
void informsEmployees(Employee employees[], int len)
{
    char salir = 'n';
    system("cls");
    printf("***** Informs Employees ****\n\n");

    do
    {
        switch( menuInforms())
        {
        case 1:
            sortEmployeesByLastNameSector(employees,len,1);
            printEmployees(employees,len);
            break;

        case 2:
            system("cls");
            printEmployeesSalary(employees,len);
            printf(" \n Total salary: %.2f \n\n",totalSalary(employees,len));
            printf(" The average salary  is : %.2f \n\n ",getAverageSalary(employees,len));
            printf("Exceed average %d \n\n",numExceedPromedio(employees,len));
            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            printf("Confirm get out?¿ \n");
            fflush(stdin);
            salir=getchar();
            //
            break;

        default:
            printf("Invalid option \n");

        }
        system("pause");
    }
    while(salir == 'n');
}


void showEmployeeSalary(Employee x)//salario  y empleado
{
    printf(" %2d  %10s   %12s         %.2f \n",

           x.id,
           x.name,
           x.lastName,
           x.salary
          );
}
void printEmployeesSalary(Employee list[],int len)//informa salarios  por  empleado
{

    int flag=0;
    system("cls");
    printf("******* list of Employees whit Salary ********\n");
    printf(" id         name    last name           salary \n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            showEmployeeSalary(list[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        //printf("---- don´t find Employees ----- \n");
        printf("----- no employees found ----- \n");
    }
    printf("\n\n");
}

float totalSalary(Employee e[],int len)
{
    float total;
    for(int i=0; i<len; i++)
    {
        if(e[i].isEmpty==0)
        {
            total=(float)(total + e[i].salary);
        }
    }

    return total;
}
float getAverageSalary(Employee e[],int len) //promedio de salarios
{
    float average=0;
    float total=0;
    int cont=0;
    for(int i=0; i<len; i++)
    {
        if(e[i].isEmpty==0)
        {
            cont++;
            total=(float)(total + e[i].salary);
        }
    }

    average=total / (float) cont;


    return average;
}
int numExceedPromedio(Employee e[],int len)
{
    int cont=0;
    float average=getAverageSalary(e,len);
    for(int i=0; i<len; i++)
    {
        if(e[i].isEmpty==0 && (e[i].salary > average))
        {
            cont++;
        }
    }

    return cont;
}
