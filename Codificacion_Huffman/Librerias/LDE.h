

typedef ArbolBinario item;


//Definicion del TDA "NODOL"
typedef struct nodol
{
	item dato;
	struct nodol *adelante, *atras;
}NODOL;

NODOL *crearNodol(item x)
{
	NODOL *nuevo=(NODOL*)malloc(sizeof(NODOL));
	nuevo->dato = x;
	nuevo->adelante = nuevo->atras = NULL;
	return nuevo;
}
