
#include "LDE.h"

void imprimirLDE(NODOL *cab)//Imprimir Lista Doblemente Ordenada con los datos solicitados
{
	NODOL *aux;
	for(aux=cab;aux;aux=aux->adelante)
	{
		printf("%c--%d\n", aux->dato->dato.l, aux->dato->dato.f);
	}
}



ArbolBinario quitarcabLDE(NODOL **cab)
{

	ArbolBinario aux=NULL;

	if(*cab)
	{
		aux = (*cab)->dato;
		*cab= (*cab)->adelante;
	}
	

	return aux;
}


void insertarcabLDE(item x, NODOL **cab)//Inserta cabecera en la LDE
{
	NODOL *nuevo=crearNodol(x);
	nuevo->adelante=*cab;
	if(*cab)
	(*cab)->atras=nuevo;
	*cab=nuevo;
}

int longitudLDE(NODOL *cab)//devuelve el número de elementos en la LDE
{
	int longitud=0;
	NODOL *aux=cab;
	while(aux)
	{
		longitud++;
		aux=aux->adelante;
	}
	return longitud;
}

void intercambiarLDE(NODOL *anterior, NODOL *actual)
{
	item aux=anterior->dato;
	anterior->dato=actual->dato;
	actual->dato=aux;
}


void ordenarLDE(NODOL *cab)//Ordena los datos de la LDE de menor a mayor por frecuencia
{
	int i, j, n=longitudLDE(cab);
	NODOL *aux=cab;
	for(i=n-1; i>0; i--)
	{
		aux=cab;
		for(j=0;j<i;j++)
		{
			if(aux->dato->dato.f > aux->adelante->dato->dato.f)
				intercambiarLDE(aux, aux->adelante);
			aux=aux->adelante;
		}
	}
}


