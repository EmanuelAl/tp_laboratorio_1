#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    int x=0;
    int y=0;

    char seguir='s';
    char salir='n';

    int opcion=0;

    do{

        switch(menu(x,y)){
        case 1:
            do{
               printf("ingrese numero A: ");
               scanf("%d",&x);
            }while(x<0);

        case 2:
            do{
                printf("ingrese numero B: ");
                scanf("%d",&y);
            }while(y<0);

             break;
        case 3:
            sumar1(x,y);
            restar(x,y);
            dividir(x,y);
            multiplicar(x,y);

            printf("\n todo  cargado \n\n");
            system("pause");
            break;
        case 4:
            printf(" \nEl resultado de A+B es: %d \n",sumar1(x,y));
            printf(" \nEl resultado de A-B es: %d \n",restar(x,y));
            printf(" \nEl resultado de A/B es: %f \n",dividir(x,y));
            printf(" \nEl resultado de A*B es: %d \n",multiplicar(x,y));
            printf(" \nEl factorial de A es: %i y El factorial de B es: %i \n\n",factorial(x),factorial(y));
            system("pause");
            break;

        case 5:
            printf("\n esta seguro que quiere salir? s/n \n");
            fflush(stdin);
            salir=getche();

            if(salir=='s'){
                return 0;
            }
            system("pause");
            break;
        default:
            printf("opcion invalida.Reingrese opcion: \n");
            system("pause");
            break;
        }

        printf("\n desea continuar? s/n \n");
        fflush(stdin);//borra si hay basura en la memoria
        seguir=getch();// toma dato y lo pasa a la variable seguir

        system("cls");


    }while( seguir=='s');
    return 0;
}
