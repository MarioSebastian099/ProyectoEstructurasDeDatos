include<stdlib.h>
include<stdio.h>
include<string.h>
include "Librerias/Arbol.c"
include "Librerias/pila.c"

#define TAMCADENA 5000000
#define TAMCADENACODIFICADA 100000000

void menu();
void codificar();


int main(void)
{
	menu();
	return 0;
}

void menu()
{
	letras = (int*)calloc(255,sizeof(int));
	codigos = (char **)calloc(255,sizeof(char*));

	int j;
	
	for(j=0; j<255; j++)
	{
		codigos[j] = (char*)malloc(20*sizeof(char));
	}

	codificar();

}

void codificar()
{

	char *cadena;
	cadena = (char*)malloc(TAMCADENA*sizeof(char));

	crearPila(&P);
	NODOL *principal=NULL;
	ArbolBinario abh;
}
