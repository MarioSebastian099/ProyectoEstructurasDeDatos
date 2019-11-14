

typedef struct elementoA
{
	char l;
	int f;
	
}elementoA;

typedef elementoA itema;

#include "Arbol.h"


ArbolBinario crearNodo(itema x)
{
	ArbolBinario nuevo = (ArbolBinario)malloc(sizeof(ElementodeArbolBinario));
	nuevo->izq = nuevo->der = NULL;
	nuevo->dato = x;
	return nuevo;
}


void nuevoArbol(ArbolBinario *raiz, itema x, ArbolBinario RI, ArbolBinario RD)
{
	*raiz = crearNodo(x);
	(*raiz)->izq = RI;
	(*raiz)->der = RD;
}

void preorden(ArbolBinario raiz)
{
		printf("%c", raiz->dato.l);

		if(raiz->izq)
		preorden(raiz->izq);

		if(raiz->der)
		preorden(raiz->der);
}



void preorden(ArbolBinario raiz)
{
		printf("%c", raiz->dato.l);

		if(raiz->izq)
		preorden(raiz->izq);

		if(raiz->der)
		preorden(raiz->der);
}

void BorrarArbol(ArbolBinario raiz)
{
   if(raiz->izq) BorrarArbol(raiz->izq);
   if(raiz->der) BorrarArbol(raiz->der);
   free(raiz);
}



C
:w funcionesArbol.
