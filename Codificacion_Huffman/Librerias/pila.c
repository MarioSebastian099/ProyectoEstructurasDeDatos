
//Definicion del tipo de dato genérico
typedef char tipoDato;


#include "pila.h"

//Función que inicializa el valor de pila en -1
void crearPila(PILA *P)
{
	P->cima=-1;
}

//Función para ingresar elementos en una pila
void insertarPila(PILA *P, tipoDato elemento)
{
	if(pilaLlena(*P)==1)
	{
		puts("ERROR, LA PILA ESTA LLENA");
		system("PAUSE");
		exit(-1);
	}
	P->cima++;
	P->listaPila[P->cima]=elemento;
}


//Función para sacar elementos de una pila
tipoDato quitarPila(PILA *P)
{
	tipoDato aux;
	if(pilaVacia(*P)==1)
	{
		puts("ERROR, LA PILA ESTA VACIA");
		system("PAUSE");
		exit(-1);
	}
	aux = P->listaPila[P->cima];
	P->cima--;
	return aux;
}



//Función que devuelve el valor de la cima a -1
void limpiarPila(PILA *P)
{
	P->cima=-1;
}

//Funcion que lee el elemento de la cima de la pila sin elemininarlo
tipoDato cimaPila(PILA P)
{
	return (P.listaPila[P.cima]);
}

//Funcion que determina si la pila está llena
int pilaLlena(PILA P)
{
	if(P.cima==TAMMAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Funcion que determina si la pila está vacia
int pilaVacia(PILA P)
{
	if(P.cima==-1)
	{
		return 1;
	}
	else
	{
		return 0;	
	}
	
}


char * cadenaPila(PILA P)
{
	PILA aux;
	crearPila(&aux);

	int i =0;

	while(!pilaVacia(P))
	{
		insertarPila(&aux, quitarPila(&P));
		i++;
	}

	char * cadena = (char*)malloc(i+1*sizeof(char));
	
	i=0;

	while(!pilaVacia(aux))
	{
		cadena[i] = quitarPila(&aux);
		i++;
	}
	cadena[i] = 0;

	return cadena;
}


