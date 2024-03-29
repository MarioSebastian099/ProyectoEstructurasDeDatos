#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Librerias/Arbol.c"
#include "Librerias/LDE.c"
#include "Librerias/pila.c"

//================================================================]

#define TAMCADENA 5000000
#define TAMCADENACODIFICADA 100000000

//================================================================]

void menu();
void leerCadena(char *);      
void escribirFrecuencias();
NODOL * obtenerFrecuencias(NODOL *);
ArbolBinario armarArbol(NODOL *);
void recorridoAB(ArbolBinario);
void escribirCodificado(char *);
void codificar();
int binToDec(int);
int pw(int, int);
//================================================================]

int *letras;
char **codigos;
PILA P;

//================================================================]


//================================================================]

void menu()
{
	
	letras = (int*)calloc(255,sizeof(int));
	codigos = (char**)calloc(255,sizeof(char*));
	
	int j;
	for(j=0; j<255; j++)
		codigos[j] = (char*)malloc(20*sizeof(char));     /////crear arreglo de cadenas

	codificar();

}

//================================================================] 

void codificar()
{

	char *cadena;
	cadena = (char*)malloc(TAMCADENA*sizeof(char));



	crearPila(&P);  ////PILA
	NODOL *principal=NULL;////Lista
	ArbolBinario abh;/////Arbol


	leerCadena(cadena);///lee la cadena de original.txt
	escribirFrecuencias(); ///escribe tabla de frecuencias
	principal = obtenerFrecuencias(principal);///Obtiene Frecuencias y las ingresa a una lista

	imprimirLDE(principal); //////Lista ordenada etapa 1

	free(letras);///liberar espacio
	abh = armarArbol(principal);/////Regresa el arbol de huffman formado a partir de la lista

	printf("Preorden\n");
	preorden(abh);     //////Arbol de huffman
	printf("\n");

	recorridoAB(abh);////Se obtiene el codigo para cada letra
	escribirCodificado(cadena);

	printf("Archivo codificado y comprimido con Exito" );
}

//================================================================]

void leerCadena(char *cadena)
{
	FILE *arch_org;
	int i = 0, j;
	char l;
	arch_org = fopen("ArchivosDeCodificacion/original.txt","r");

	while( (l=fgetc(arch_org)) != EOF )
	{
		j = l;
		if(j<0)
		{
			j+=256;
		}

		letras[j]++;
		cadena[i] = l;
		i++;
	}

	fclose(arch_org);
}


//================================================================]

void escribirFrecuencias()
{
	int i = 0, j=0 ;
	FILE *arch_frec;
	arch_frec = fopen("ArchivosCompartidos/frecuencias.txt","w+");

	while(i < 255)
	{
		if(letras[i] != 0)
		{
			if(j==0)
			{
				fprintf(arch_frec, "%c=%d", i,letras[i]);
				j++;
			}
			
			else
			fprintf(arch_frec, "\n%c=%d", i,letras[i]);

		//printf("%c=%d\n", i, letras[i] );
		}
		i++;
	}

	fclose(arch_frec);
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
		printf("\n");
		imprimirLDE(principal);

		
	}
	return quitarcabLDE(&principal);
}

//================================================================]

void recorridoAB(ArbolBinario raiz)

{

	if(raiz->izq)
		{
			insertarPila(&P, '0');
			recorridoAB(raiz->izq);
			quitarPila(&P);
		}
		
		if(raiz->der)
		{
			insertarPila(&P, '1');
			recorridoAB(raiz->der);
			quitarPila(&P);
		}


	if((!raiz->izq) && (!raiz->der))
	{
		printf("%c = %s\n", raiz->dato.l,cadenaPila(P));
		codigos[raiz->dato.l] = cadenaPila(P);
		//printf("%s%dcoido\n", codigos[raiz->dato.l],5);
	}
	
		
}

//================================================================]

void escribirCodificado(char *cadena)
{
	FILE *arch_cod, *arch_com;
	arch_cod = fopen("ArchivosDeCodificacion/codificado.txt","w+");
	char *aux = (char*)malloc(7*sizeof(char));
	char l;

	int i =0;
	while( (l=cadena[i]) != 0)
	{
		if(l<0)
		{
			l+=256;
		}

		fprintf(arch_cod, "%s", codigos[l]);
		//printf("%s\n", codigos[l]);
		i++;
	}
	fclose(arch_cod);


	cadena = (char*)malloc(TAMCADENACODIFICADA*sizeof(char));

	arch_cod = fopen("ArchivosDeCodificacion/codificado.txt","r");
	fscanf(arch_cod,"%s", cadena);
	fclose(arch_cod);

	//printf("\n%s", cadena);


	arch_com = fopen("ArchivosCompartidos/comprimido.txt","w+");
	i=1;

	int num=0, j=0;

	aux[0] = '1';

	while(cadena[j] != 0)
	{
		if(i==8)
		{
			num = atoi(aux);////int binario
			//printf("%d\n", num);
			aux[i] = 0;
			//printf("\n%s\n",aux);
			//printf("%d\n", num);
			free(aux);
			aux = (char*)malloc(7*sizeof(char));
			aux[0] = '1';
			fprintf(arch_cod, "%c", binToDec(num)-1);

			//printf("%d\n", binToDec(num)-1);
			i=1;
			j--;
		}
		else
		{
			aux[i] = cadena[j];
			//printf("%s\n", aux);
			i++;
		}
		 j++;

	}

	aux[i] = 0;
	num = atoi(aux);
	//printf("%dfinal\n", num);
	//free(aux);
	fprintf(arch_cod, "%c", binToDec(num)-1);
	//printf("%d\n", binToDec(num)-1);
	free(cadena);
	fclose(arch_com);

}

//================================================================]

int binToDec(int n)
{
    int decimalNumber = 0, i = 0, digit;
    while (n!=0)
    {
        digit = n%10;
        n /= 10;
        decimalNumber += digit * pw(2,i);
        ++i;
    }
    return decimalNumber;
}

//================================================================]

int pw(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return pw(x, y/2)*pw(x, y/2);
    else
        return x*pw(x, y/2)*pw(x, y/2);
}

//================================================================]
