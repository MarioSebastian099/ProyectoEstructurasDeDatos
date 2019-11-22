#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Librerias/Arbol.cpp"
#include "Librerias/LDE.cpp"
#include "Librerias/pila.cpp"

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

