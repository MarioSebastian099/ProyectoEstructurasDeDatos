typedef char tipoDato;
#include "pila.h"

//Función que inicializa el valor de pila en -1
void crearPila(PILA *P)
{
	P->cima=-1;
}

//Ingreso de datos a la pila
void insertarPila(PILA *P, tipoDato elemento)
{
	if(pilaLlena(*P)==1)
	{
		puts("Error la pila esta llena");
		exit(-1);
	}
	P->cima++;
	P->listaPila[P->cima]=elemento;
}

//pop elementos de pila
tipoDato quitarPila(PILA *P)
{
	tipoDato aux;
	
	if(pilaVacia(*P)==1)
	{
		puts("Error la pila esta vacia");
		exit(-1);
	}
	aux = P->listaPila[P->cima];
	P->cima--;
	return aux;
}
