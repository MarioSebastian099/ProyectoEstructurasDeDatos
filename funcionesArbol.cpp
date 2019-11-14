

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
