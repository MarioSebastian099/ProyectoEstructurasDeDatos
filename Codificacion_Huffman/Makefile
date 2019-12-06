a.out: main.o Arbol.o LDE.o pila.o
	gcc main.o Librerias/Arbol.o Librerias/LDE.o Librerias/pila.o
main.o: main.c
	gcc -c main.c
Librerias/Arbol.o
	gcc -c Librerias/Arbol.c
Librerias/LDE.o
	gcc -c Librerias/LDE.c
Librerias/pila.o
	gcc -c Librerias/pila.c
run: a.out
	./a.out
clear:
	rm main.o Librerias/Arbol.o Librerias/LDE.o Librerias/pila.o
