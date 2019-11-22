#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Librerias/Arbol.c"
#include "Librerias/LDE.c"
#include "Librerias/pila.c"

#define TAMCADENACODIFICADA 100000000

//================================================================]

void menu();
NODOL * obtenerFrecuencias(NODOL *);
ArbolBinario armarArbol(NODOL *);
int decToBin(int n);
void decodificarArbol(ArbolBinario, char *);
char * descomprimir(char *);

//================================================================]

int main(void)
{
	menu();
	return 0;
}

//================================================================]

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


//================================================================]

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

//================================================================]

ArbolBinario armarArbol(NODOL *principal)
{

	ArbolBinario raiz,ri, rd;
	elementoA e;
	while(longitudLDE(principal) > 1)
	{

		raiz =NULL;

		ri = quitarcabLDE(&principal);
		rd = quitarcabLDE(&principal);
		


		e.f = ri->dato.f + rd->dato.f;
		e.l = '$';
		
		nuevoArbol(&raiz, e, ri, rd);
		insertarcabLDE(raiz, &principal);
		ordenarLDE(principal);
		//printf("\n");
		//imprimirLDE(principal);

		
	}
	return quitarcabLDE(&principal);
}

//================================================================]

void decodificarArbol(ArbolBinario abh, char *cadena)
{

	ArbolBinario aux = abh;
	int i=0;
	char x;
	
	FILE  *w;
	w = fopen("ArchivosDeDecodificacion/decodificado.txt", "w+");
	
	while((x=cadena[i]) != 0)
	{


		if(x == '0')
			aux = aux->izq;

		if(x == '1')
			aux = aux->der;
		
		//printf("%c", x);
		if((!aux->izq) && (!aux->der))
		{
			
			fputc(aux->dato.l, w);
			aux = abh;
		}

			
		
			
		
		i++;
	}
	printf("%d\n", i);
	
	fclose(w);

}


//================================================================]

int decToBin(int n)
{
    int binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

//================================================================]

char * descomprimir(char *cadena)
{
	FILE *arch_com;
	arch_com = fopen("ArchivosCompartidos/comprimido.txt","r");
	int num;
	char *aux = (char*)calloc(8,sizeof(char));
	char *aux1 = (char*)calloc(8,sizeof(char));
	char *falta = (char*)calloc(8,sizeof(char));

	char l;
	int a,h=0,i;

	while((fscanf(arch_com,"%c",&l)) != EOF )
	{
		i=1;
		a=l;
		//printf("%d\n", a);

		if(a < 0)
		{
			a += 256;
		}

		
		//printf("%d\n", a);

		num = decToBin(a+1);
		//printf("%d\n", num);
		sprintf(aux, "%d", num);

			while(aux[i] != 0)
			{
				cadena[h] = aux[i];

				h++;
				i++;
				//printf("%c\n",aux[i]);
			}
	}

	cadena[h] = 0;
	fclose(arch_com);
	return cadena;
}

//================================================================]
