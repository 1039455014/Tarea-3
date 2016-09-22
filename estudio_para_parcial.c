#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define max 1000

int impresora_1(int counter){
    counter++;
    if(counter<10)
        impresora_1(counter);
    printf("%d hola\n",counter);
    return 0;
}
int impresora_2(int counter){
    counter++;
    printf("%d hola\n",counter);
    if(counter<10)
        impresora_2(counter);
    return 0;
}


main(int argc, char *argv){
double *p1,z=3.0;
    int *q,arreglo[max],i,counter;
    p1=&z;
    q=arreglo;
    printf("formas de imprimir un arreglo\n");
    for(i=0; i<10; i++){
        arreglo[i]=i*i+1;
        printf("%d\t%d\t%d\n",arreglo[i],*(q++),*(arreglo+i));
        //printf("%d\n",*(arreglo+i));
        //printf("arreglo[0]= %d\n",*arreglo);
        //printf("direccion de arreglo = %p es equivalente a direccion de arreglo[0] = %p\n",arreglo,&arreglo[0]);
        //printf("direccion = %p \t el valor de x con el puntero p1 = %16.13lf\n",p1,*p1);
        //++(*arreglo);
    }
    counter=0;
    impresora_1(counter);
    printf("\n\n");
    impresora_2(counter);

    int a,*p,c;
    c=1;
    p=&c;
    a=*p;
    /*
    for(i=0; i<10; i++){
        c=i;
        printf("%d,%d,%d,%p\n",*p,c,a,p);
        if(i>5)
            *p=NULL;
        //a=*p;
        printf("%d,%d,%d,%p\n",*p,c,a,p);
    }
    */
    i=(int)3.0/2.0;
    printf("\n%5d\n",i);
    //como romper la conexion entre p y c
    for(i=0; i<10; i++){
        c=i;
        //*p++;//devuelve el valor de la direccion que hay en la memoria siguiente esto es equivlente a *(p++)
        *p=*p+1; // distinto de (*p)++ que devuelve la direccion de memoria contigua a p
        printf("%12d\t%12d\t%12d\t%12p\t%12d\t%12d\n",*(p++),*p,c,a,p,(*p)++,++*p);
    }
    return 0;
}
