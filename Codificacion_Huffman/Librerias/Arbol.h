
typedef struct nodo
{
	itema dato;
	struct nodo *izq, *der;
	
}ElementodeArbolBinario;

typedef ElementodeArbolBinario *ArbolBinario;

ArbolBinario crearNodo(itema x);
void nuevoArbol(ArbolBinario *raiz, itema x, ArbolBinario RI, ArbolBinario RD);
void eliminarNodosAB(ArbolBinario raiz);
void preorden(ArbolBinario raiz);