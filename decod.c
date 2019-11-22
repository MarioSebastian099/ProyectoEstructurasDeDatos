#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Librerias/Arbol.c"
#include "Librerias/LDE.c"
#include "Librerias/pila.c"

#define TAMCADENACODIFICADA 100000000

void menu();
NODOL * obtenerFrecuencias(NODOL *);
ArbolBinario armarArbol(NODOL *);
int decToBin(int n);
void decodificarArbol(ArbolBinario, char *);
char * descomprimir(char *);

int main(void)
{
        menu();
        return 0;

}


void menu()
{

        NODOL *principal=NULL;////Lista
        ArbolBinario abh;/////Arbol

        char *cadena;
        cadena = (char*)malloc(TAMCADENACODIFICADA*sizeof(char));


        principal = obtenerFrecuencias(principal);
        abh = armarArbol(principal);
        cadena = descomprimir(cadena);

        decodificarArbol(abh, cadena);
        free(cadena);
        printf("Texto Descomprimido y Decodificado\n");


}

NODOL * obtenerFrecuencias(NODOL *principal)
{
        FILE *arch_frec;
        arch_frec = fopen("ArchivosCompartidos/frecuencias.txt","r");
        char l = 'a';
        int f;

        elementoA e;

        while(l != EOF)
        {
                fscanf(arch_frec,"%c=%d", &l, &f);
                e.f = f;
                e.l = l;
                insertarcabLDE(crearNodo(e), &principal);
                l = fgetc(arch_frec);
        }

        ordenarLDE(principal);
        fclose(arch_frec);

        return principal;

}


ArbolBinario armararbol(NODOL *principal)
{
	ArbolBinario raiz,ri, rd;
	elementoA e;

	while(longitudLDE(principal)>1)
	{
		raiz=NULL;

		ri=quitarcabLDE(&principal);
		rd=quitarcabLDE(&principal);

		e.f =ri->dato.f + rd->datof;
		e.l= '$';

		nuevoArbol(&raiz, e, ri, rd);
		insertarcabLDE(raiz, &principal);
		ordenarLDE(principal);


	}

	return quitarcabLDE(&principal);

}
