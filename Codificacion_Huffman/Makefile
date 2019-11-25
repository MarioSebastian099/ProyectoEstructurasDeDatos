
a.out: main.o codificador.o decod.o maindecod.o Arbol.o LDE.o pila.o
	gcc main.o codificador.o decod.o maindecod.o Arbol.o LDE.o pila.o
main.o: main.c
	gcc -c main.c
codificador.o: codificador.c
	gcc -c codificador.c
decod.o: decod.c
	gcc -c decod.c
maindecod.o: maindecod.c
	gcc -c maindecod.c
Arbol.o: Arbol.c
	gcc -c Arbol.c
LDE.o: LDE.c
	gcc -c LDE.c
pila.o: pila.c
	gcc -c pila.c
run: a.out
	./a.out
clear:
rm a.out main.o codificador.o decod.o maindecod.o Arbol.o LDE.o pila.o
