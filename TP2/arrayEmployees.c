#include "arrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int initEmployees(Employee list[], int len)
{
    int todoOk=0;
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=1;
        todoOk=1;
    }
    return todoOk;
}
void showEmployee(Employee x)//muestra un empleado
{
    printf(" %2d  %10s   %12s         %.2f    %d \n",

           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}
void printEmployees(Employee list[],int len)//muesstra los empleados
{

    int flag=0;
    system("cls");
    printf("******* list of Employees ********\n");
    printf(" id         name    last name           salary     sector\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            showEmployee(list[i]);
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
void sortEmployeesById(Employee list[], int len,int order)
{

    Employee  auxEmployee;

    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if(order==1)
            {

                if( list[i].id > list[j].id && list[i].isEmpty==0 && list[j].isEmpty==0)//ordeno de menor a mayor por id y pregunto si esta o no vacio
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
            else if(order==0)
            {

                if( list[i].id < list[j].id && list[i].isEmpty==0 && list[j].isEmpty==0)//ordeno de mayor a menor por id y pregunto si esta o no vacio
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else
                {
                    printf("invalid order \n");
                }
            }
        }
    }
    printf("\n**** Employees ordered by id ******\n");
}
void sortEmployeesByName(Employee list[], int len,int order)
{

    Employee  auxEmployee;

    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if(order==1)
            {

                if( strcmp(list[i].name,list[j].name) > 0 && list[i].isEmpty==0 && list[j].isEmpty==0)//ordeno de a la z y pregunto si esta o no vacio
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
            else if(order==0)
            {

                if( strcmp(list[i].name,list[j].name) < 0 && list[i].isEmpty==0 && list[j].isEmpty==0)//ordeno de de la z a la a, pregunto si esta o no vacio
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else
                {
                    printf("invalid order \n");
                }
            }
        }
    }
     printf("\n**** Employees ordered by name ******\n");
}
void sortEmployeesByLastNameSector(Employee list[], int len,int order)
{
    int swap=0;
    Employee  auxEmployee;

    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if(order==1)
            {

                if( strcmp(list[i].lastName,list[j].lastName) > 0 && list[i].isEmpty==0 && list[j].isEmpty==0 )//ordeno de menor a mayor por id y pregunto si esta o no vacio
                {
                    swap=1;
                }else if(strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].sector > list[j].sector && list[i].isEmpty==0 && list[j].isEmpty==0){
                    swap=1;
                }
                /*if(swap==1){
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }*/
            }
            if(order==0)
            {

                if( strcmp(list[i].lastName,list[j].lastName) < 0 && list[i].isEmpty==0 && list[j].isEmpty==0 )//ordeno de menor a mayor por id y pregunto si esta o no vacio
                {
                    swap=1;
                }else if(strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].sector < list[j].sector && list[i].isEmpty==0 && list[j].isEmpty==0){
                    swap=1;
                }

            }

             if(swap==1){
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }

                swap=0;
        }
    }
    printf("\n**** Employees ordered by last name y sector ******\n");
}
int findFreePlace(Employee list[],int len) //encuentra  lugar disponible
{

    int index=-1;//si no encuentra lugar libre

    for(int i=0; i<len; i++)
    {

        if(list[i].isEmpty==1)
        {

            index=i;
            break;
        }
    }
    return index;

}
int findEmployeeById(Employee list[],int len,int id) // busca el empleado por id
{

    int index=-1;//si no encuentra lugar libre

    for(int i=0; i<len; i++)
    {

        if(list[i].isEmpty==0 && list[i].id ==id)
        {

            index=i;
            break;
        }
    }
    return index;
}
int addEmployee(Employee employees[],int len,int id)
{
    int ok=-1;
    int index;
    char name[51];
    char lastName[51];
    float salary;
    int sector;


    printf("****** add Employee *****\n");
    index=findFreePlace(employees,len);

    if(index==-1)
    {
        system("cls");
        printf("------ Complete system. Impossible to add more employees -----\n");
        system("pause");
    }
    else
    {

        printf(" Enter name: \n");
        fflush(stdin);
        gets(name);
        printf(" Enter last name: \n");
        fflush(stdin);
        gets(lastName);
        printf(" Enter salary: \n");
        scanf("%f",&salary);

        printf(" Enter sector: \n");
        scanf("%d",&sector);
        employees[index]=newEmployee(id,name,lastName,salary,sector);
        ok=1;
    }

    return ok;

}
Employee newEmployee(int id,char name[],char lastName[],float salary,int sector )
{

    Employee auxEmployee;
    auxEmployee.id=id;
    strcpy(auxEmployee.name,name);
    strcpy(auxEmployee.lastName,lastName);
    auxEmployee.salary=salary;
    auxEmployee.sector=sector;
    auxEmployee.isEmpty=0;

    return auxEmployee;
}
int hardcodeoEmployees(Employee employees[],int len,int cant)
{
    int cont=0;
    Employee auxE[10]= {{0001,"ema","rodriguez",19000,4,0},
        {0004,"alberto","alvarez",17000,3,0},
        {0003,"sofia","casares",18000,4,0},
        {0002,"marcela","alanis",15000,2,0},
        {0006,"erika","sota",16300,3,0},
        {0005,"domingo","ibañez",20500,3,0},
        {0007,"marcos","pedroza",14900,2,0},
        {2000,"carmen","alfonzin",21000,1,0},
        {2001,"luis","paz",19900,1,0}
    };


    if(cant<=len && cant<10)
    {
        for(int i=0; i<cant; i++)
        {

            employees[i]=auxE[i];
            cont++;
        }
    }
    return cont;
}
int removeEmployee(Employee employees[], int len)
{

    int ok=0;
    int index;
    int id;
    char confirm='n';

    system("cls");
    printf("**** Low of Employee ****\n\n");

    printf(" Enter id : ");
    scanf("%d",&id);

    index=findEmployeeById(employees,len,id);

    if( index==-1)
    {
        printf(" No exist the employee ");
        system("pause");
    }
    else
    {
        showEmployee(employees[index]);//mostramos el empleado en la posicion que esta
        printf("confirm removal ? :");
        fflush(stdin);
        confirm =getche();

        if(confirm=='y')
        {
            employees[index].isEmpty=1;
            printf("\n\nEmployee removed\n");
            ok=1;
        }
        else
        {
            printf("\n\nOperation canceled\n");
        }
        system("pause");
    }
    return ok;

}
int modifyEmployee(Employee employees[], int len)
{

    int ok=0;
    int index;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int option=0;

    system("cls");
    printf("**** Modify Employee ****\n\n");

    printf(" Enter id : ");
    scanf("%d",&id);

    index=findEmployeeById(employees,len,id);

    if( index==-1)
    {
        printf(" No exist the employee ");
        system("pause");
    }
    else
    {
        showEmployee(employees[index]);//mostramos el empleado en la posicion que esta
        printf(" Modify :\n");
        printf(" 1-Name\n");
        printf(" 2-LastName:\n");
        printf(" 3-Salary\n");
        printf(" 4-Sector\n");
        printf(" Enter option: \n");
        scanf("%d",&option);

        switch(option){
        case 1:
            printf("Enter name: \n");
            fflush(stdin);
            gets(name);
             strcpy(employees[index].name,name);

            printf(" *** updated name ***  ");
            break;

        case 2:

           printf("Enter last name: \n");
            fflush(stdin);
            gets(lastName);

             strcpy(employees[index].lastName,lastName);
            printf(" *** updated  last name *** ");
            break;

        case 3:
            printf("Enter salary: \n");
            scanf("%f",&salary);

            employees[index].salary=salary;
            printf(" *** updated  salary *** ");
            break;

        case 4:
            printf("Enter sector: \n");
            scanf("%d",&sector);
            employees[index].sector=sector;
            printf(" *** updated  sector ***  ");
            break;

        default:
                printf(" Invalid option \n");
            }

        }
        system("pause");

    return ok;

}

