#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.71828183

FILE *archivo,*archivo_salida;

FILE *pf;
lea(){
    int i;
    float p,q,r;
    pf=fopen("datos.txt","r");
    for(i=1;i<7;i++){
        fscanf(pf,"%f %f %f",&p,&q, &r);
        printf("%7.3f   %7.3f    %7.3f\n",p,q,r);
    }
    fclose(pf);
}
/*
leer_archivo(){
    double i, h, x;
    int k;
    FILE *archivo,*archivo_salida;
    archivo = fopen("datos.txt","r");
    archivo_salida = fopen("datos2.txt","w");
    if(archivo == NULL){
        printf("\n\t\t¡Este archivo no existe!\n");
        exit(1);
    }
    for(k=1; k<4; k++){
        fscanf(archivo,"%f  %f  %f",&i,&x,&h);
        printf("%12.0f \t %12.4f \t %12.4f\n",i,x,h);
        fprintf(archivo_salida,"%12.0f \t %12.4f \t %12.4f\n",i,x,h);
    }
    fclose(archivo);
}
*/

int main(){
    int N=9;
    float x=45.0,a,b;
    char operacion[15];
    /*
    printf("Ingrese el angulo en grados y el numero de terminos a calcular:");
    scanf("%f %d",&x, &N);
    printf("cos(%7.3f)=%12.9f\n",x,fcoseno(x,N));
    printf("sen(%7.3f)=%12.9f\n",x,fseno(x,N));
    printf("El factorial de %d es %12.3f\n",N,factorial(0));
    Divi_ente_por_dos(N);
    */
    /*
    printf("ingrese: a operacion b \n");
    scanf("%f\n",&a);
    gets(operacion);
    scanf("%f",&b);
    //printf("%s \n",operacion);
    printf("%f %s %f = %f",a,operacion,b, suma(a,b));
    //Calculadora(a,operacion,b);
   //
   */
    //leer_archivo();
    lea();

    return 0;
}
