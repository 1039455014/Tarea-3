#make para compilar tarea3.c
CC=gcc

compila:
	$(CC) tarea3.c -o tarea3.x -lm 


#El argumento de las funciones a usar es argv[2] i.e. por ejemplo para ej1 (ejercicio 1) el 
#parametro que recibe la funcion dentro en el ejercicio 1 es  ---> 20


ej1:
	./tarea3.x 1 20

ej2:
	./tarea3.x 2 20

ej3:
	./tarea3.x 3 20

ej4:
	./tarea3.x 4 5

ej5:
	./tarea3.x 5 20

ej6:
	./tarea3.x 6 0.09
	gnuplot graf_1.gnu

ej7:
	./tarea3.x 7 20

ej8:
	./tarea3.x 8 20

ej9:
	./tarea3.x 9 300000
	gnuplot graf_2.gnu

ej10:
	./tarea3.x 10 100 

ej11:
	./tarea3.x 11 50
	gnuplot graf_3.gnu

ej12:
	./tarea3.x 12 1000

ej13:
	./tarea3.x 13 300
	gnuplot graf_5.gnu

ej14:
	./tarea3.x 14 2000000
	gnuplot graf_4.gnu

ej15:
	./tarea3.x 15 20
	gnuplot graf.gnu

ej16:
	./tarea3.x 16 5000

grafica:
	gnuplot graf.gnu

clean:
	rm -rf *.x
	rm -rf *.txt
	rm -rf *.c~
	rm -rf *.exe
	rm -rf *.o
	rm -rf *.dat~
	rm -rf *~
	rm -rf *.dat		
