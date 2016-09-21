#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define max 1000
#define e 2.71828183
#define raiz_de_2 1.4142135623730950488016887242097
#define pi_analitico 3.1415926535897932384626433832795
//punto 4
float factorial(float n){
  if(n==1.0 || n==0.0){
    return 1.0;
  }
  return n*factorial(n-1);
}

//Punto 1
/*
  Serie de Taylor de la función seno al rededor de x=0:
  sen(x)=x-x^3/3!+x^5/5!-x^7/7!+x^9/9!+...+(-1)^(n)x^(2n+1)/(2n+1)!+...
  la siguiente función calcula cos(x) usando los primeros N terminos en la expansión de la serie de Taylor al rededor de x=0.
*/
float fseno(float x, int N){
  x=x*M_PI/180.0;
  int n;
  float sumatoria=x;
  float signo=-1.0;
  float termino;
  for(n=1; n<=N; n++){
    termino=(signo*pow(x,2*n+1))/factorial(2.0*n+1);
            sumatoria=sumatoria+termino;
            signo=(-1.0)*signo;
  }
  return sumatoria;
}

/*
  Serie de Taylor de la función coseno al rededor de x=0:
  cos(x)=1-x^2/2!+x^4/4!-x^6/6!+x^8/8!+...+(-1)^(n)x^(2n)/(2n)!+...
  la siguiente función calcula cos(x) usando los primeros N terminos en la expansión de la serie de Taylor al rededor de x=0.
*/

//punto 2
float fcoseno(float x, int N){//pag 53.
  x=x*M_PI/180;
  int n;
  float sumatoria=1.0;
  float signo=-1.0;
  float termino;
  for(n=1; n<=N; n++){
    termino=(signo*pow(x,2*n))/factorial(2.0*n);
    sumatoria=sumatoria+termino;
    signo=(-1.0)*signo;
  }
  return sumatoria;
}

//Punto 3
/*
  La funcion Divi_ente_por_dos(x) calcula el numero de veces que se puede dividir un numero x entre dos,
  asumiendo división entera. (ejemplo, si 9/2=4, 4/2=2, 2/2=1, entonces 9 se puede dividir por dos tres
  veces.). El programa recibe el numero a dividir (x) e imprime en pantalla el numero de veces
  que dicho numero es divisible (división entera) por dos.
*/
int Divi_ente_por_dos(int x){
  int contador=0;
  printf("la division entera por dos de %d es:\n",x);
  while(x!=1){
    x=floor(x/2);
    contador++;
    printf("%d). x=%d\n",contador,x);
  }
  return 0;
}
//Punto 5
float suma(float a, float b){
  return a+b;
}
float resta(float a, float b){
  return a-b;
}
float multiplicacion(float a, float b){
  return a*b;
}
float division(float a, float b){
  return a/b;
}

/*// usar la funcion argv[1] argv[2] argv[3]. a operacion b.
  Calculadora(float a, char operacion[], float b){
  switch(operacion){
  case 'suma':
  printf("a suma b =",suma(a,b));
  break;
  case 'resta':
  printf("a resta b =",resta(a,b));
  break;
  case 'multiplicacion':
  printf("a multiplicacion b =",multiplicacion(a,b));
  break;
  case 'division':
  printf("a division b =",division(a,b));
  break;
  default : printf("!No es una operacion permitida¡");
  }

  
    //printf("a ")
    //char d
    
    //        a=0;
    
    
    }
*/


//Punto 6
/*
  El siguiente programa evalúa la funcion f(x)=sin(x)*ln(2*x+1)*sinh(x) en el intervalo [0, 10]. la funcion recibe el tamaño del paso (dx)
  y escribe en un archivo tres columnas: la primer columna conteniendo el valor i del incremento en x (x=i*dx), 
la segunda columna contiene a x, y la tercera conteniendo el valor de f(x).
*/

f(double dx){
  double i,h,x;
  FILE *archivo;
  archivo = fopen("datos.txt","w");
  //for(i=0; i<10; i=i*dx){
  for(i=0; i<=10; i++){
    x=i*dx;
    //return sin(x)*sinh(x)*log10(2.0*x+1)/log10(e);//h=sin(i)*sinh(i)*log10(2.0*i+1)/log10(e);
    h=sin(x)*sinh(x)*log10(2.0*x+1)/log10(e);
    //fprintf(archivo,"%12.0f \t %12.4f \t %12.4f\n",i,x,h);
    fprintf(archivo,"%12.0f  %12.4f  %12.4f\n",i,x,h);
  }
  fclose(archivo);
}
/*
  El siguiente procedimiento lee la tabla producida en la parte anterior, y escribe otro
archivo de dos columnas: la primer columna contiene el valor f(x) y la segunda columna
el valor x.
*/
leer_archivo(){
  double i, h, x; //para leer archivos no se deben declarar las variables como double.
  int k;
  FILE *archivo_read,*archivo_salida;
  archivo_read = fopen("datos.txt","r");
  archivo_salida = fopen("datos2.txt","w");
  if(archivo_read == NULL){
    printf("\n\t\t¡Este archivo no existe!\n");
    exit(1);
  }
  for(k=0; k<=10; k++){
    fscanf(archivo_read,"%lf  %lf  %lf",&i,&x,&h);
    printf("%12.0lf \t %12.4lf \t %12.4lf\n",i,x,h);
    fprintf(archivo_salida,"%12.4lf \t %12.4lf\n",h,x);
  }
  fclose(archivo_read);
  fclose(archivo_salida);
}
//punto 7
/*
  las siguientes 4 funciones evalúan la siguiente operación
	____sin(x)+cos(x)(a+b)____
		    2
usando una precedencia de operadores distinta
*/
//b)
double f1(double x, double a, double b){
	printf("calcula seno(x) le suma a*coseno(x)/2 y luego suma b\n");  
	return sin(x)+cos(x)/2*a+b; 
  
}
double f2(double x, double a, double b){
	printf("calcula seno(x) le suma (a+b)-veces coseno(x)/2.\n");
	return sin(x)+cos(x)/2*(a+b); 
}
double f3(double x, double a, double b){
        printf("calcula seno(x) le suma coseno(x)/2 el resultado lo multiplica por a y luego suma b.\n");	
	return (sin(x)+cos(x)/2)*a+b;
}
double f4(double x, double a, double b){
	printf("calcula la suma seno(x)+coseno(x) el resultado lo divide entre 2 y el resultado lo multiplica por el resultado de a+b\n");
	return ((sin(x)+cos(x))/2)*(a+b); 
}





//punto 8
/*
  Este programa calcula la suma de los divisores de x. El programa recibe un entero x y devuelve
  la suma de los divisores de x.
*/
int suma_divisores_de(int x){
  int i,suma=0;
    for(i=1; i<=x; i++){
      if( (x % i)==0 ){
	//printf("%d\n",i);
	suma = suma+i;
      }
    }
    //printf("La suma de los divisores es: %d\n",suma);
    return suma;
    
}
/*
  Este programa calcula los números primos menores que x. El programa recibe
  un entero x e imprime en pantalla todos los números primos menores que x.
*/
int primos_menores_que(int x){
  int i;
  if(x==2){
    printf("%d\n",2);
  }
  else{
    printf("%d\n",2);
    for(i=3; i<=x; i=i+2){
      if(suma_divisores_de(i)==i+1)
	printf("%d\n",i);
            }
  }
}

//punto 9
/*
La siguiente funcion calcula el valor de la masa de un objeto de masa inicial m_0 y velocidad vel_m_0.
*/
double masa_particula(double m_0, double vel_m_0){
    double masa = m_0/sqrt(1-pow(vel_m_0,2)/pow(300000,2));//c=300000km/s la velocidad de la luz aproximadamente.
    return masa;
}
/*
El siguiente programa calcula el valor de la masa de un objeto o particula para diferentes valores de la velocidad de la partícula.
El programa recibe el valor del incremento dv de la velocidad y produce un archivo de columnas:
La primer columna contiene el valor de la velocidad de la partícula v, la segunda el valor de v/c (c es la velocidad de la luz) y la
tercera contiene el valor de la masa de la partícula.
*/
valor_de_masa(double dv, int n){//(double dv, double vel_m_0, int n){ //n es la cantidad de valores diferentes de la velocidad de la particula que se quieren
    int i;
    double d,m,vel_m_0;
    FILE *archivo;
    archivo = fopen("velocidades.txt","w");

    for(i=0; i<=n; i++){
        vel_m_0=i*dv;
        d=vel_m_0/300000;
        m=masa_particula(1,vel_m_0);
        fprintf(archivo,"%lf \t %lf \t %lf\n",vel_m_0,d,m);
    }
}





//punto 10 
/*
Los siguientes dos programas calculan el valor de  pi usando dos aproximaciones distintas
Este programa utiliza la aproximacion:
	pi1 ­> 2/π = √2/2 . √(2+ √2)/2 . √(2+ √(2+√2))/2 ...
El programa recibe el numero de términos (n) en la expansion anterior para el calculo
de pi e imprime en pantalla el valor de pi obtenido.
*/
double aproximacion_pi1(int n){
    double resultado;
    double a_n=raiz_de_2;
    double productoria_a_n=a_n*0.5;
    int i;
    //printf("pi:   experimental \t analitico\n\n");
    if(n==1)
        return resultado = 2.0/productoria_a_n;
    //printf("1). %16.15lf \t %18.16lf\n",resultado,pi_analitico);
    for(i=1; i<n; i++){
        a_n = sqrt(2+a_n);
        productoria_a_n=productoria_a_n*a_n*0.5;
        resultado = 2.0/productoria_a_n;
        //printf("%d). %16.15lf \t %18.16lf\n",i+1,resultado,pi_analitico);
    }
    return resultado;//productoria_a_n;
}
/*
Este programa utiliza la aproximacion:
	pi2 ­> π/4 =1 − 1/3 + 1/5 − 1/7 + 1/9 − 1/11 + ...
El programa recibe el numero de términos (n) en la expansion anterior para el calculo
de pi e imprime en pantalla el valor de pi obtenido.
*/

double aproximacion_pi2(int n){
    int i;
    double a_n = 1.0,resultado;
    //printf("pi:   experimental \t analitico\n\n");
    if (n==1)
        return resultado = 4.0*a_n;
    //printf("1). %16.15lf \t %18.16lf\n",resultado,pi_analitico);
    int signo = -1;

    for(i=1; i<n; i++){
        a_n = a_n + signo/(2.0*i+1);
        signo = -signo;
        resultado = 4.0*a_n;
        //printf("%d). %16.15lf \t %18.16lf\n",i+1,resultado,pi_analitico);
    }
    a_n=4.0*a_n;
    return a_n;
}
/*Esta funcion imprime en pantalla los dos valores de pi obtenidos con un numero de terminos n.*/
aproximacion_pi(int n){
    double pi1=aproximacion_pi1(n);
    double pi2=aproximacion_pi2(n);
    //printf("aproximacion de pi1\t\t pi \t\t aproximacion de pi2\n");
    printf("%16.16lf  \t  %16.16lf  \t  %16.16lf\n",pi1,pi_analitico,pi2);
}





//punto 11
double sin_uso_de_registros(int n){
    double alpha = pi_analitico/6.0,t1,t2,t_inicio,t_final,dif_tiempo;
    int x,y;
    t_inicio = clock();
    for(y=1; y<=n*n; y++){
        for(x=1; x<=n*n; x++){
            t1=sin(alpha)*x+cos(alpha)*y;
            t2=-cos(alpha)*x+sin(alpha)*y;
        }
    }
    t_final = clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}

double uso_de_registros(int n){
    double alpha = pi_analitico/6.0,t1,t2,s,c,t_inicio,t_final,dif_tiempo;
    int x,y;
    s=sin(alpha);
    c=cos(alpha);
    t_inicio = clock();
    for(y=1; y<=n*n; y++){
        for(x=1; x<=n*n; x++){
            t1=s*x+c*y;
            t2=-c*x+s*y;
        }
    }
    t_final = clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}
comparacion_tiempo_ejecu(int N){
    int i;
    double c1,c2;
    FILE *parchivo,*parchivo2;

    parchivo=fopen("tiempo_eje_sin_regis.txt","w");
    parchivo2=fopen("tiempo_eje_con_regis.txt","w");

    fprintf(parchivo,"\tTiempo de ejecucion en funcion del numero de iteraciones:\n");
    fprintf(parchivo,"\t\tsin uso de registro\n\n");
    fprintf(parchivo,"numero de iteraciones \t\t tiempo de ejecucion\n");

    fprintf(parchivo2,"\tTiempo de ejecucion en funcion del numero de iteraciones:\n");
    fprintf(parchivo2,"\t\t\tcon uso de registro\n\n");
    fprintf(parchivo2,"numero de iteraciones \t\t tiempo de ejecucion\n");

    //printf("\tTiempo de ejecucion en funcion del numero de iteraciones:\n");
    //printf("\tsin uso de registro \t\t uso de registro\n");

    for(i=1; i<=N; i++){
        c1=sin_uso_de_registros(i);
        c2=uso_de_registros(i);
        //printf("\t%d).%16.2lf  \t\t  %16.2lf\n",i,c1,c2);
        fprintf(parchivo,"\t%d  \t\t  %16.2lf  \n",i,c1);
        fprintf(parchivo2,"\t%d  \t\t  %16.2lf  \n",i,c2);
    }
    fclose(parchivo);
    fclose(parchivo2);
}




//punto 12 secuencia de operaciones
//caso 1
/*
La funcion caso_1(length) recibe un entero length y devuelve el tiempo de ejecucion de un loop de tamaño length del tipo 
	for i=1,length{
	   a[i] = b[i] * c
	}
donde c=2 es una constante.
*/
double caso_1(int length){
    int a[length],b[length],i;//c=2;
    double t_inicio,t_final,dif_tiempo;
    for(i=1; i<=length; i++){
        b[i-1]=i*i;
    }
    t_inicio=clock();
    for(i=1; i<=length; i++){
        a[i-1]=b[i-1]*2;
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("\t\nEl caso 1 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
//caso 2
/*
La funcion caso_2(length, nvectors) recibe dos enteros length, nvectors y devuelve el tiempo de ejecucion de un loop del tipo 
	for k=1,nvectors{
	    for i=1,length{
		a[i] = b[i] * c[i]
	    }
	}
donde c[i]=2, es similar a la funcion caso_1(length) solo que ahora la constante es un vector de entradas todas iguales a 
dos y cuyo loop esta dentro de otro loop (el de tamaño de nvectors).
*/

double caso_2(int length, int nvectors){
    int a[length],b[length],c[length],i,k;
    double t_inicio,t_final,dif_tiempo;

    for(i=1; i<=length; i++){
        b[i-1]=i*i;
        c[i-1]=2;
    }

    t_inicio=clock();
    for(k=1; k<=nvectors; k++){
        for(i=1; i<=length; i++){
            a[i-1]=b[i-1]*c[i-1];
        }
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("El caso 2 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
/*
la funcion comparacion_secuencia_operaciones(n) recibe un entero n y devuelve los tiempos promedios de ejecucion de caso_1(n) y caso_2(n, n*n) en n iteraciones.
*/

comparacion_secuencia_operaciones(int n){
    int i;
    double c1=0.0,c2=0.0;
    printf("\n  Iteracion \tcaso 1 \t\tcaso 2\n");
    for(i=1; i<=n; i++){
        c1=c1+caso_1(n);
        c2=c2+caso_2(n,n*n);//i*i);
        printf("  %d).\t %12.3lf \t %12.3lf\n",i,c1/n,c2/n);
	c1=0.0;
	c2=0.0;
    }
	printf("\nSegun la comparacion con los dos casos es evidente que el caso 2 requiere de mas\n tiempo para ejecutarse esto es debido a que el periodo de reuso de c[i] hace que su localidad temporal se desvanezca. \n\n");
}

//punto 13
//para float
//caso 1
/*
La funcion caso_1_float(length) es similar a la funcion caso_1(length) solo que los vectores a[] y b[] son ahora de tipo float
*/
double caso_1_float(int length){
    float a[length],b[length];//c=2.0;
    int i;
    double t_inicio,t_final,dif_tiempo;
    for(i=1; i<=length; i++){
        b[i-1]=i*i;
    }
    t_inicio=clock();
    for(i=1; i<=length; i++){
        a[i-1]=b[i-1]*2.0;
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("\t\nEl caso 1 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
//caso 2
/*
La funcion caso_2_float(length, nvectors) es similar a la funcion caso_2(length, nvectors) solo que los vectores a[] y b[] son ahora de tipo float
*/

double caso_2_float(int length, int nvectors){
    float a[length],b[length],c[length];
    int i,k;
    double t_inicio,t_final,dif_tiempo;

    for(i=1; i<=length; i++){
        b[i-1]=i*i;
        c[i-1]=2.0;
    }

    t_inicio=clock();
    for(k=1; k<=nvectors; k++){
        for(i=1; i<=length; i++){
            a[i-1]=b[i-1]*c[i-1];
        }
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("El caso 2 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
/*
La funcion comparacion_secuencia_operaciones_float(n) es similar a la funcion comparacion_secuencia_operaciones(n) solo que ahora trabaja con las fuciones caso_1_float() y caso_2_float().
*/
comparacion_secuencia_operaciones_float(int n){
    int i;
    double c1=0.0,c2=0.0;
    printf("\n  Iteracion \tcaso 1 \t\tcaso 2\n");
    for(i=1; i<=n; i++){
        c1=c1+caso_1_float(n);
        c2=c2+caso_2_float(n,n*n);//i*i);
        printf("  %d).\t %12.3lf \t %12.3lf\n",i,c1/n,c2/n);
	c1=0.0;
	c2=0.0;
    }
}
//para double
//caso 1
/*
La funcion caso_1_double(length) es similar a la funcion caso_1(length) solo que los vectores a[] y b[] son ahora de tipo double
*/
double caso_1_double(int length){
    double a[length],b[length],c=2.0;
    int i;
    double t_inicio,t_final,dif_tiempo;
    for(i=1; i<=length; i++){
        b[i-1]=i*i;
    }
    t_inicio=clock();
    for(i=1; i<=length; i++){
        a[i-1]=b[i-1]*c;
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("\t\nEl caso 1 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
//caso 2
/*
La funcion caso_2_double(length, nvectors) es similar a la funcion caso_2(length, nvectors) solo que los vectores a[] y b[] son ahora de tipo double
*/

double caso_2_double(int length, int nvectors){
    double a[length],b[length],c[length];
    int i,k;
    double t_inicio,t_final,dif_tiempo;

    for(i=1; i<=length; i++){
        b[i-1]=i*i;
        c[i-1]=2.0;
    }

    t_inicio=clock();
    for(k=1; k<=nvectors; k++){
        for(i=1; i<=length; i++){
            a[i-1]=b[i-1]*c[i-1];
        }
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("El caso 2 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
/*
La funcion comparacion_secuencia_operaciones_double(n) es similar a la funcion comparacion_secuencia_operaciones(n) solo que ahora trabaja con las fuciones caso_1_double() y caso_2_double().
*/
comparacion_secuencia_operaciones_double(int n){
    int i;
    double c1=0.0,c2=0.0;
    printf("\n  Iteracion \tcaso 1 \t\tcaso 2\n");
    for(i=1; i<=n; i++){
        c1=c1+caso_1_double(n);
        c2=c2+caso_2_double(n,n*n);//i*i);
        printf("  %d).\t %12.3lf \t %12.3lf\n",i,c1/n,c2/n);
	c1=0.0;
	c2=0.0;
    }
}
//para long double
//caso 1
/*
La funcion caso_1_longdouble(length) es similar a la funcion caso_1(length) solo que los vectores a[] y b[] son ahora de tipo longdouble
*/
double caso_1_longdouble(int length){
    long double a[length],b[length],c=2;
    int i;
    double t_inicio,t_final,dif_tiempo;
    for(i=1; i<=length; i++){
        b[i-1]=i*i;
    }
    t_inicio=clock();
    for(i=1; i<=length; i++){
        a[i-1]=b[i-1]*c;
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("\t\nEl caso 1 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
//caso 2
/*
La funcion caso_2_longdouble(length, nvectors) es similar a la funcion caso_2(length, nvectors) solo que los vectores a[] y b[] son ahora de tipo long double
*/

double caso_2_longdouble(int length, int nvectors){
    long double a[length],b[length],c[length];
    int i,k;
    double t_inicio,t_final,dif_tiempo;

    for(i=1; i<=length; i++){
        b[i-1]=i*i;
        c[i-1]=2;
    }

    t_inicio=clock();
    for(k=1; k<=nvectors; k++){
        for(i=1; i<=length; i++){
            a[i-1]=b[i-1]*c[i-1];
        }
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    //printf("El caso 2 tarda %12.3lf\n",dif_tiempo);
    return dif_tiempo;
}
/*
La funcion comparacion_secuencia_operaciones_longdouble(n) es similar a la funcion comparacion_secuencia_operaciones(n) solo que ahora trabaja con las fuciones caso_1_longdouble() y caso_2_longdouble().
*/

comparacion_secuencia_operaciones_longdouble(int n){
    int i;
    double c1=0.0,c2=0.0;
    printf("\n  Iteracion \tcaso 1 \t\tcaso 2\n");
    for(i=1; i<=n; i++){
        c1=c1+caso_1_longdouble(n);
        c2=c2+caso_2_longdouble(n,n*n);//i*i);
        printf("  %d).\t %12.3lf \t %12.3lf\n",i,c1/n,c2/n);
	c1=0.0;
	c2=0.0;
    }
}
/*
La funcion comparacion_secu_opera_de_todo_tipo(n) recibe un entero n y ejecuta las funciones comparacion_secuencia_operaciones(n), comparacion_secuencia_operaciones_float(n), comparacion_secuencia_operaciones_double(n) y comparacion_secuencia_operaciones_longdouble(n), para comparar sus valores
*/
comparacion_secu_opera_de_todo_tipo(int n){

    printf("\n Cuando el tipo de declaracion es int:\n");
        comparacion_secuencia_operaciones(n);
    printf("\n Cuando el tipo de declaracion es float:\n");
        comparacion_secuencia_operaciones_float(n);
    printf("\n Cuando el tipo de declaracion es double:\n");
        comparacion_secuencia_operaciones_double(n);
    printf("\n Cuando el tipo de declaracion es long double:\n");
        comparacion_secuencia_operaciones_longdouble(n);
	
printf("\nSe alcanza a notar una diferencia en la ejecucion del programa cuando se declaran los vectores como tipo long double\n\n ");

}


/*
comparacion_secu_opera_de_todo_tipo(int n){
    FILE *archivo;
    archivo=fopen("comparacion_tipo_declaracion.txt","w");
    int i;
    double c1_i,c2_i,c1_f,c2_f,c1_d,c2_d,c1_ld,c2_ld;
    printf("\n Iter caso 1: int:  float: double: long double:    caso 2:  int:  float:  double: long double:\n");
    for(i=1; i<=n; i++){
        c1_i=caso_1(i);
        c1_f=caso_1_float(i);
        c1_d=caso_1_double(i);
        c1_ld=caso_1_longdouble(i);

        c2_i=caso_2_longdouble(i,i*i);//i*i);
        c2_f=caso_2_longdouble(i,i*i);//i*i);
        c2_d=caso_2_longdouble(i,i*i);//i*i);
        c2_ld=caso_2_longdouble(i,i*i);//i*i);

        //printf("  %d).\t  %7.3lf %7.3lf %7.3lf   %7.3lf \t\t %7.3lf %7.3lf %7.3lf   %7.3lf\n",i,c1_i,c1_f,c1_d,c1_ld,c2_i,c2_f,c2_d,c2_ld);
        fprintf(archivo,"  %d).\t  %7.3lf %7.3lf %7.3lf   %7.3lf \n",i,c2_i,c2_f,c2_d,c2_ld);

    }
    fclose(archivo);
}
*/

//punto 14
/*
La funcion "codigo_loop_1er_orden(N)"recibe un entero N y devuelve el tiempo de ejecucion de un loop doble de la siguiente forma: 
for (loop=0; loop<10; loop++) {
    for (i=0; i<N; i++) {
    ... = ... x[i] ...
    }
   }
*/
double codigo_loop_1er_orden(int N){
    int loop,i,y[N];
    double t_inicio, t_final,dif_tiempo,a[N],x[N];
    for(loop=0; loop<N; loop++){
        x[loop]=loop;
        y[loop]=loop*loop;
    }
    t_inicio=clock();
    for(loop=0; loop<10; loop++){
        for(i=0; i<N; i++){
            a[i]=x[i]*y[i]*sin(i*i);
            a[i+10]=a[i]*cos(i*i)*log10l(i);
        }
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}
/*
La funcion "codigo_loop_2do_orden(N)"recibe un entero N y devuelve el tiempo de ejecucion de un loop doble de la siguiente forma: 
for (i=0; i<N; i++) {
    for (loop=0; loop<10; loop++) {
    ... = ... x[i] ...
    }
   }
*/
double codigo_loop_2do_orden(int N){
    int loop,i,y[N];
    double t_inicio, t_final,dif_tiempo,a[N],x[N];
    for(loop=0; loop<N; loop++){
        x[loop]=loop;
        y[loop]=loop*loop;
    }
    t_inicio=clock();
    for(i=0; i<N; i++){
        for(loop=0; loop<10; loop++){
            a[i]=x[i]*y[i]*sin(i*i);
            a[i+10]=a[i]*cos(i*i)*log10l(i);
        }
    }
    t_final=clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}
/*
La funcion comparacion_1er_y_2do_orden(N) recibe un entero N y devuelve 10 tiempos promedio de ejecucion de las funciones comparacion_1er_orden(N) y comparacion_2do_orden(N) en N iteraciones 
*/
comparacion_1er_y_2do_orden(int N){
    double c1=0, c2=0;
    int i,j;	

    for(j=1; j<10; j++){
	    //for(i=1; i<N; i++){
		c1=c1+codigo_loop_1er_orden(N);
		c2=c2+codigo_loop_2do_orden(N);	
	    //}
            printf("\n Iteracion  \t\t  promedio loop 1er orden  \t\t  promedio loop 2do orden \n");  
	    printf("      %d \t\t     %16.8lf \t\t       %16.8lf\n\n",j,c1/1.0*j,c2/1.0*j);
	c1=0;
	c2=0;
    }
	printf("\nEl loop de primer orden debe demorarse mas tiempo pues el periodo de reuso de una\n variable x[i] es N, un valor que puede que puede acabar con su localidad temporal\n en la memoria cache, contrario a lo que sucede con el loop de segundo orden, que su periodo\n de reuso es mas frecuente por lo tanto la ejecucion del programa debe ser mas rapida.\n\n");
}
//punto 15
/*

*/
double Multipl_de2_matri_1(int a[max][max], int b[max][max], int n){
    int i,j,k;
    int c[n][n];
    double t_inicio,t_final,dif_tiempo;
    t_inicio = clock();
    for(i=0; i<=n; i++){
        for(j=0; j<=n; j++){
            for(k=0; k<=n; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    t_final = clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}

double Multipl_de2_matri_2(int a[max][max], int b[max][max], int n){
    int i,j,k;
    int c[n][n];
    double t_inicio,t_final,dif_tiempo;
    t_inicio = clock();
    for(i=0; i<=n; i++){
        for(k=0; k<=n; k++){
            for(j=0; j<=n; j++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    t_final = clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}

double Multipl_de2_matri_3(int a[max][max], int b[max][max], int n){
    int i,j,k;
    int c[n][n];
    double t_inicio,t_final,dif_tiempo;
    t_inicio = clock();
    for(k=0; k<=n; k++){
        for(i=0; i<=n; i++){
            for(j=0; j<=n; j++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    t_final = clock();
    dif_tiempo = t_final-t_inicio;
    return dif_tiempo;
}

compara_produ_2_matri(int a[max][max], int b[max][max], int n){
    double M1=0.0,M2=0.0,M3=0.0;
    int i,j;
    FILE *pf=NULL,*pf2=NULL,*pf3=NULL;
    pf=fopen("pto15_comparacion_multipli_de_2matri.txt","w");
    pf2=fopen("pto15_comparacion_multipli_de_2matri_2.txt","w");		
    pf3=fopen("pto15_comparacion_multipli_de_2matri_3.txt","w");	
    for(j=1; j<20; j++){
        M1=M1+Multipl_de2_matri_1(a,b,n);
        M2=M2+Multipl_de2_matri_2(a,b,n);
        M3=M3+Multipl_de2_matri_3(a,b,n);
        fprintf(pf,"%d  \t %16.8lf \t %16.8lf \t %16.8lf\n",j,M1/(1.0*j),M2/(1.0*j),M3/(1.0*j));
	//fprintf(pf1,"%d   \t %16.8lf\n",j,M1/(1.0*j));
	//fprintf(pf2,"%d   \t %16.8lf\n",j,M2/(1.0*j));
	//fprintf(pf3,"%d   \t %16.8lf\n",j,M3/(1.0*j));
	M1=0.0;
	M2=0.0;
	M3=0.0;
	}
    //fclose(pf1);
    //fclose(pf2);
    //fclose(pf3);	
}


/*
compara_produ_2_matri(int a[max][max], int b[max][max], int n){
    double M1=0.0,M2=0.0,M3=0.0;
    int i,j;
    for(j=1; j<20; j++){
	M1=0.0;
	M2=0.0;
	M3=0.0;
    for(i=0; i<j; i++){
        M1=M1+Multipl_de2_matri_1(a,b,n);
        M2=M2+Multipl_de2_matri_2(a,b,n);
        M3=M3+Multipl_de2_matri_3(a,b,n);
    }
	printf("%d  %16.8e \t %16.8e \t %16.8e\n",j,M1/(1.0*j),M2/(1.0*j),M3/(1.0*j));
	
	}
}
*/


generaf(double v[max][max], int m, int n, int mayor, int menor)
// genera una matriz v de n reales aleatorios entre menor y mayor
{  int i,j;
   int rango;
   for(i=0; i < m; i++)
     for(j=0; j < n; j++)
     {   rango = (mayor - menor) + 1;
         v[i][j] = menor + (double) (rango*(rand()/(RAND_MAX + 1.0)));
     }

}

float sumatoria_fracturada(float x, int N){
    x=x*M_PI/180.0;
    double dif_tiempo,t_inicio,t_final;
    int i;
    float s=x,a[max],b[max];
    float signo=1.0;
    t_inicio=clock();
    for(i=0; i<N; i++){
        signo=(-1.0)*signo;
        a[i]=signo*pow(x,2*(i+1)+1);
        b[i]=1.0/factorial(2.0*(i+1)+1);
        s+=a[i]*b[i];
    }
    t_final=clock();
    /*
    t_inicio=clock();
    for(i=0; i<N; i++){
        s+=a[i]*b[i];
        //printf("%d %12.9f\n",i,a[i]*b[i]);
    }
    t_final=clock();
    */
    dif_tiempo=t_final-t_inicio;
    return s;
    //return dif_tiempo;
}
/*
float sumatoria_fracturada_en2(float x, int N){ //solo si el numero de terminos es par
    x=x*M_PI/180.0;
    double dif_tiempo,t_inicio,t_final;
    int i;
    float s1=x,s2=0,a[max],b[max],s;
    float signo=1.0;
    for(i=0; i<N; i++){
        signo=(-1.0)*signo;
        a[i]=signo*pow(x,2*(i+1)+1);
        b[i]=1.0/factorial(2.0*(i+1)+1);
    }
    t_inicio=clock();
    for(i=0; i<(N+1)/2; i++){//for(i=0; i<floor(N-1)/2; i++){ i<(N-1)/2+1
        s1+=a[2*i]*b[2*i];
        s2+=a[2*i+1]*b[2*i+1];
        //printf("\t\t\t%d %12.9f\n \t\t\t%d %12.9f, %d\n",2*i,a[2*i]*b[2*i],2*i+1,a[2*i+1]*b[2*i+1],(N-1)/2+1);
    }
    t_final=clock();
    dif_tiempo=t_final-t_inicio;
    s=s1+s2;
    //return s;
    return dif_tiempo;
}
*/


float sumatoria_fracturada_en2(float x, int N){ //solo si el numero de terminos es par
    x=x*M_PI/180.0;
    double dif_tiempo,t_inicio,t_final;
    int i;
    float s1=x,s2=0,a[max],b[max],s;
    float signo=1.0;
    /*
    for(i=0; i<N; i++){
        signo=(-1.0)*signo;
        a[i]=signo*pow(x,2*(i+1)+1);
        b[i]=1.0/factorial(2.0*(i+1)+1);
    }*/
    t_inicio=clock();
    for(i=0; i<(N+1)/2; i++){//for(i=0; i<floor(N-1)/2; i++){ i<(N-1)/2+1
        signo=(-1.0)*signo;
        a[2*i]=signo*pow(x,2*(2*i+1)+1);
        b[2*i]=1.0/factorial(2.0*(2*i+1)+1);
        signo=(-1.0)*signo;
        a[2*i+1]=signo*pow(x,2*(2*i+2)+1);
        b[2*i+1]=1.0/factorial(2.0*(2*i+2)+1);

        s1+=a[2*i]*b[2*i];
        s2+=a[2*i+1]*b[2*i+1];
        //printf("\t\t\t%d %12.9f\n \t\t\t%d %12.9f, %d\n",2*i,a[2*i]*b[2*i],2*i+1,a[2*i+1]*b[2*i+1],(N-1)/2+1);
    }
    t_final=clock();
    dif_tiempo=t_final-t_inicio;
    s=s1+s2;
    //return s;
    return dif_tiempo;
}


float sumatoria_fracturada_en3(float x, int N){ //solo si el numero de terminos es par
    x=x*M_PI/180.0;
    double dif_tiempo,t_inicio,t_final;
    int i;
    float s1=x,s2=0,s3=0,a[max],b[max],s;
    float signo=1.0;
    /*
    for(i=0; i<N; i++){
        signo=(-1.0)*signo;
        a[i]=signo*pow(x,2*(i+1)+1);
        b[i]=1.0/factorial(2.0*(i+1)+1);
    }*/
    t_inicio=clock();
    for(i=0; i<(N+1)/2; i++){//for(i=0; i<floor(N-1)/2; i++){ i<(N-1)/2+1
        signo=(-1.0)*signo;
        a[2*i]=signo*pow(x,2*(2*i+1)+1);
        b[2*i]=1.0/factorial(2.0*(2*i+1)+1);
        signo=(-1.0)*signo;
        a[2*i+1]=signo*pow(x,2*(2*i+2)+1);
        b[2*i+1]=1.0/factorial(2.0*(2*i+2)+1);

        s1+=a[2*i]*b[2*i];
        s2+=a[2*i+1]*b[2*i+1];
        //printf("\t\t\t%d %12.9f\n \t\t\t%d %12.9f, %d\n",2*i,a[2*i]*b[2*i],2*i+1,a[2*i+1]*b[2*i+1],(N-1)/2+1);
    }
    t_final=clock();
    dif_tiempo=t_final-t_inicio;
    s=s1+s2+s3;
    //return s;
    return dif_tiempo;
}

int main(int argc, char *argv[]){
  int N,i;
  float x,a,b,x1,x2,x3;
  char operacion[15];
  FILE *archivo,*archivo_read,*archivo_salida;
  double c,c1,c2;
  int Q[max][max],Q1[max][max],arreglo[max];
  int ejerc,var3,var10;
  float var;
	 	
  ejerc = atoi(argv[1]);
  var10 = atoi(argv[2]);
  var = atof(argv[2]);
  //*
  switch(ejerc){
    
  case 1:
	printf("Ingrese el angulo en grados y el numero de terminos a calcular:");
	scanf("%f %d",&x, &N);	
	printf("sen(%7.3f)=%12.9f\n\n",x,fseno(x,N));
	break;
  
  case 2:
	printf("Ingrese el angulo en grados y el numero de terminos a calcular:");
	scanf("%f %d",&x, &N);
	printf("cos(%7.3f)=%12.9f\n\n",x,fcoseno(x,N));
	break;
  
  case 3:
	printf("Ingrese el numero dividir:  ");
	scanf("%d",&var3);
	Divi_ente_por_dos(var3);
	break;
  
  case 4:
	//printf("\nIngrese un numero para calcular el factorial: ");
	//scanf("%f",&var3);
	printf("El factorial de %12.0f es %12.3f\n",var,factorial(var));
	break;
  
  case 5:
	
	break;
  
  case 6:
	f(var);
        leer_archivo();
	break;
  
  case 7:
	printf("\nIngrese x, a, b: ");
	scanf("%f %f %f",&x,&a,&b);
	printf("f1(%f,%f,%f)=%f\n\n",x,a,b,f1(x,a,b));
	printf("f2(%f,%f,%f)=%f\n\n",x,a,b,f2(x,a,b));
	printf("f3(%f,%f,%f)=%f\n\n",x,a,b,f3(x,a,b));
	printf("f4(%f,%f,%f)=%f\n\n",x,a,b,f4(x,a,b));
	printf("\n a)En efecto f4 resulta ser la implementacion correcta debido al orden como se ejecutan las operaciones impuestas por los parentesis\n c)se ejecutan en orden, primero la division o multiplicacion y segundo la suma o la resta\n\n");	
	break;
  
  case 8:
	printf("Primos menores que %d\n",var10);
	primos_menores_que(var10);	
	break;
  
  case 9:
	
	break;
  
  case 10:	
    printf("aproximacion de pi1\t\t pi \t\t aproximacion de pi2\n");
    for(i=1; i<=var10; i++)
      aproximacion_pi(i);	
	break;
  
  case 11:
	comparacion_tiempo_ejecu(50);
	break;
  
  case 12:
	
	break;
  
  case 13:
	
	break;
  
  case 14:
	
	break;
    
  case 15:
    Q[0][0]=3;   Q[0][1]=5; Q[0][2]=81; Q[0][3]=4;
    Q[1][0]=5;   Q[1][1]=6; Q[1][2]=15; Q[1][3]=9;
    Q[2][0]=8;   Q[2][1]=2; Q[2][2]=1; Q[2][3]=0;
    Q[3][0]=0;   Q[3][1]=7; Q[3][2]=23; Q[3][3]=20;
    
    Q[4][0]=33;   Q1[4][1]=55; Q1[4][2]=83; Q[4][3]=44;
    Q[5][0]=55;   Q1[5][1]=66; Q1[5][2]=16; Q[5][3]=99;
    Q[6][0]=88;   Q1[6][1]=22; Q1[6][2]=11; Q[6][3]=10;
    Q[7][0]=45;   Q1[7][1]=77; Q1[7][2]=22; Q[7][3]=67;
    
    
    Q1[0][0]=333;   Q1[0][1]=555; Q1[0][2]=834; Q1[0][3]=444;
    
    Q1[1][0]=555;   Q1[1][1]=666; Q1[1][2]=179; Q1[1][3]=999;
    
    Q1[2][0]=888;   Q1[2][1]=222; Q1[2][2]=111; Q1[2][3]=100;
    
    Q1[3][0]=455;   Q1[3][1]=777; Q1[3][2]=222; Q1[3][3]=677;
    
    
    
    Q1[4][0]=3333;   Q1[4][1]=5555; Q1[4][2]=8345; Q1[4][3]=4444;
    
    Q1[5][0]=5555;   Q1[5][1]=6666; Q1[5][2]=1813; Q1[5][3]=9999;
    
    Q1[6][0]=8888;   Q1[6][1]=2222; Q1[6][2]=1111; Q1[6][3]=1000;
    
    Q1[7][0]=4555;   Q1[7][1]=7777; Q1[7][2]=2222; Q1[7][3]=6777;
    
    compara_produ_2_matri(Q,Q1,300);
    break;
  
  case 16:
	
	break;

  default : printf("!No es una opcion permitida¡");
    
  }
  /*/	
    /*int **Q;
    int Fila=max;
            int Columna=max;
            Q=(int**)malloc((size_t*)sizeof(int*)*Fila);
            for(l=0; l<max; l++ ){
                    Q[l]=malloc((size_t*)sizeof(int)*Columna);
    
            }
*/    

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
    f(0.09);
    leer_archivo();
    */
    /*
    x=0;//45
    a=2;
    b=0;
    f1(x,a,b);
    f2(x,a,b);
    f3(x,a,b);
    f4(x,a,b);
    printf("f1(%f,%f,%f)=%f\n",x,a,b,f1(x,a,b));
    printf("f2(%f,%f,%f)=%f\n",x,a,b,f2(x,a,b));
    printf("f3(%f,%f,%f)=%f\n",x,a,b,f3(x,a,b));
    printf("f4(%f,%f,%f)=%f\n",x,a,b,f4(x,a,b));
    */
    //valor_de_masa(0.1, 100000, 20000);
    /*
    valor_de_masa(0.1, 20000);
    suma_divisores_de(20);
    primos_menores_que(50);
    */
    /*punto 10
    //c=aproximacion_pi1(2);
    //c=aproximacion_pi2(100);
    //printf("%16.16lf",c);
    printf("aproximacion de pi1  \t  aproximacion de pi2\n");
    for(i=1; i<=10000; i++)
    aproximacion_pi(i);
    */
    /*punto 11
    comparacion_tiempo_ejecu(50);
    */
    /*punto 12
    comparacion_secuencia_operaciones(200);
    */
    /*punto 13
    comparacion_secu_opera_de_todo_tipo(200);
    */
    /*punto 14
    comparacion_1er_y_2do_orden(2000);
    */
    /*Punto 15
            Q[0][0]=3;   Q[0][1]=5; Q[0][2]=81; Q[0][3]=4;
            Q[1][0]=5;   Q[1][1]=6; Q[1][2]=15; Q[1][3]=9;
            Q[2][0]=8;   Q[2][1]=2; Q[2][2]=1; Q[2][3]=0;
            Q[3][0]=0;   Q[3][1]=7; Q[3][2]=23; Q[3][3]=20;

            Q[4][0]=33;   Q1[4][1]=55; Q1[4][2]=83; Q[4][3]=44;
            Q[5][0]=55;   Q1[5][1]=66; Q1[5][2]=16; Q[5][3]=99;
            Q[6][0]=88;   Q1[6][1]=22; Q1[6][2]=11; Q[6][3]=10;
            Q[7][0]=45;   Q1[7][1]=77; Q1[7][2]=22; Q[7][3]=67;

            Q1[0][0]=333;   Q1[0][1]=555; Q1[0][2]=834; Q1[0][3]=444;
            Q1[1][0]=555;   Q1[1][1]=666; Q1[1][2]=179; Q1[1][3]=999;
            Q1[2][0]=888;   Q1[2][1]=222; Q1[2][2]=111; Q1[2][3]=100;
            Q1[3][0]=455;   Q1[3][1]=777; Q1[3][2]=222; Q1[3][3]=677;

            Q1[4][0]=3333;   Q1[4][1]=5555; Q1[4][2]=8345; Q1[4][3]=4444;
            Q1[5][0]=5555;   Q1[5][1]=6666; Q1[5][2]=1813; Q1[5][3]=9999;
            Q1[6][0]=8888;   Q1[6][1]=2222; Q1[6][2]=1111; Q1[6][3]=1000;
            Q1[7][0]=4555;   Q1[7][1]=7777; Q1[7][2]=2222; Q1[7][3]=6777;
    compara_produ_2_matri(Q,Q1,300);
    */
    /*punto 16
    x1=sumatoria_fracturada(45, 500);
    x2=sumatoria_fracturada_en2(45, 500);
    //x3=sumatoria_fracturada_en3(45, 500);
    printf("%f \t %f \t %f",x1,x2,x3);
    */

    return 0;
}
