#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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

int menu();
int main()
{
    char salir='n';
    int devuelve;

    int abrirTexto = 1;
    int guardarTexto = 0;

    int abrirBin = 1;
    int guardarBin = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:

                 if (abrirTexto == 1)
                    {
                devuelve = controller_loadFromText("data.csv",listaEmpleados);
                if (devuelve == 1)//si lo pudo leer
                {
                    printf("\n Archivo abierto modo text \n\n");
                }
                else
                {
                    printf("\nHa ocurrido  un error al abrir el archivo \n\n");
                }

                    }
                else
                    {
                    system("cls");
                    printf("\n El archivo ya esta abierto \n\n");
                    }
                    guardarTexto = 1;
                    abrirTexto++;
                break;
            case 2:
                if (abrirBin == 1)
                    {
                devuelve = controller_loadFromBinary("data.csv",listaEmpleados);
                if (devuelve == 1)//si lo pudo leer
                {
                    printf("\n Archivo abierto modo binario\n\n");
                }
                else
                {
                    printf("\nHa ocurrido  un error al abrir el archivo \n\n");
                }

                    }
                else
                    {
                    system("cls");
                    printf("\n El archivo ya esta abierto \n\n");
                    }
                    guardarBin= 1;
                    abrirBin++;
                break;
            case 3:
                devuelve = controller_addEmployee(listaEmpleados);
            if(devuelve == 1)
            {
                system("cls");
                printf("\n Empleado cargado \n\n");
            }
            else
            {
                printf("\n  Empleado no pudo ser cargado \n\n");
            }
            break;

            case 4:
                    controller_ListEmployee(listaEmpleados);
            devuelve = controller_editEmployee(listaEmpleados);
            if (devuelve == -1)
            {
                system("cls");
                printf("\n El ID es incorrecto o no existe \n\n");
            }
            else
            {
                system("cls");
                printf("\n El empleado ha sido modificado \n\n");
            }
                break;
            case 5:
                    controller_ListEmployee(listaEmpleados);
            devuelve = controller_editEmployee(listaEmpleados);
            if (devuelve == -1)
            {
                system("cls");
                printf("\n El ID es incorrecto o no existe \n\n");
            }
            else
            {
                system("cls");
                printf("\n El empleado ha sido eliminado \n\n");
            }
                break;
            case 6:
                devuelve = controller_ListEmployee(listaEmpleados);
                if (devuelve == -1)
                {
                printf("\n NO EXISTE LA LISTA\n\n");
                }
                else
                    {
                printf("\n EXISTE LISTA \n\n");
                    }
                break;
            case 7:
                     devuelve = controller_sortEmployee(listaEmpleados);
            if (devuelve == -1)
            {
                printf("\n NO SE ENCONTRO LA LISTA .\n\n");
            }
            else
            {
                printf("\n Lista ordenada \n\n");
            }
                break;
            case 8:
                if (guardarTexto == 1)
            {
                devuelve = controller_saveAsText("data.csv",listaEmpleados);
                if(devuelve == 1)
                {
                    printf("\n Archivo guardado\n\n");
                }
                else
                {
                    printf("\n No se pudo guardar archivo\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\n Se debe abrir  archivo  primero \n\n");
            }


                break;
            case 9:
                if (guardarBin == 1)
                    {
                devuelve = controller_saveAsBinary("data.bin",listaEmpleados);
                if(devuelve == 1)
                {
                    printf("\n Archivo guardado\n\n");
                }
                else
                {
                     printf("\n No se pudo guardar archivo\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\n Se debe abrir  archivo  primero \n\n");
            }
                break;
            case 10:
                printf("confirma salir?¿ \n");
                fflush(stdin);
                salir=getchar();

                break;

        default:
            printf("Opcion invalida \n");

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
    printf("Menu:\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados \n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("Enter option :\n");
    scanf("%d",&option);

    return option;

}
