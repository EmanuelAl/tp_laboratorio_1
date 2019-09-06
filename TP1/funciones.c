#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
int sumar1(int a, int b){
    int suma;

    suma=a+b;
    return suma;

}
int restar(int a,int b){
    int resta;

    resta=a-b;

    return  resta;
}
int multiplicar(int a,int b){
    int producto;

    producto=a*b;
    return producto;
}
float dividir(int a,int b){
    float resultado;
    if(b!=0){
    resultado=a/b;
    }else{
        printf("Error. no se puede dividir por cero");
    }
    return resultado;
}
/*int factorizar(int a){
    int fact=1;
    if(a<0){
        fact=0;
    }else if(a==0){
        fact=1;
    }if(a>0){
        for(int i=a;i>=1;i--){
        fact=fact*i;
    }
    }

    return fact;

}*/
int factorial( int x){

 int fact = 1;

 if( x > 1){
    fact = x * factorial( x-1);
 }

 return fact;
}
int menu(int x,int y){
    int opcion=0;

    if(x==0 || y==0){
        printf(" 1) Ingresar 1er operando (A=x) \n");
        printf(" 2) Ingresar 1er operando (B=y) \n");
        printf(" 3) Calcular todas las operaciones \n");
        printf(" 4) Informar resultados \n");
        printf(" 5) Salir \n");

    }else{
        printf(" 1) Ingresar 1er operando (A=%d) \n",x);
        printf(" 2) Ingresar 1er operando (B=%d) \n",y);
        printf(" 3) Calcular todas las operaciones \n");
        printf(" 4) Informar resultados \n");
        printf(" 5) Salir \n");
    }


    printf("ingrese opcion : ");
    scanf("%d",&opcion);
    system("cls");
    return opcion;

}
