include<stdlib.h>
include<stdio.h>
include<string.h>
include "Librerias/Arbol.c"
include "Librerias/pila.c"

#define TAMCADENA 5000000
#define TAMCADENACODIFICADA 100000000

void menu();
void leerCadena(char *);
void escribirFrecuencias();
NODOL * obtenerFrecuencias(NODOL *);
ArbolBinario armarArbol(NODOL *);
void codificar();
int binToDec(int);
int pw(int,int);


int main(void)
{
	menu();
	return 0;
}

void menu()
{
codigos =(char **)calloc(255,sizeof(char*)); 
letras = (int*)calloc(255,sizeof(int));
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
	leerCadena(Cadena);/*lee la cadena de original.txt*/
	escribirFrecuencias();/*escribe tabla de frecuencias*/
	principal=obtenerFrecuencias(principal);/*Obtiene frecuencias*/
	imprimirLDE(principal);/*Lista ordenada etapa 1*/
	free(letras); /*Liberar el espacio*/
	abh=armarArbol(principal); /*Regresa el arbol de huffman*/
	
	printf("Preorden\n");
	preorden(abh); /*Arbol de huffman*/
	printf("\n");
	
	
	recorridoAB(abh); /*Se obtiene el codigo para cada letra*/
	escribirCodificado(cadena);


	printf("Archivo Codificado y comprimido con exito");

}
void leerCadena(char *cadena)
{
  FILE *arch_org;
  int i=0, j;
  char = l;
  arch_org = fopen("ArchivosDeCodificacion/original.txt","r");

  while((l = fgetc(arch_org)) != EOF){
    j = 1;
    if(j<0){
      j+ = 256;
    }
    letras[j]++;
    cadena[i] = l;
    i++;
  }
  fclose(arch_org);
}

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

NODOL *obtenerFrecuencias(NODOL *principal)
{
FILE *arch_frec;
arch_frec =fopen("ArchivosCompartidos/frecuencias.txt","r");
char l = 'a';
int f;
elementoA e;

while(l !=EOF)
{
fscanf(arch_frec,"%c=%d",&l,&f);
e.f=f;
e.l=l;
insertarcabLDE(crearNodo(e),&principal);
l=fgetc(arch_frec);
}
ordenarLDE(principal);
fclose(arch_frec);
return principal;
}

ArbolBinario armarArbol(NODOL *principal)
{
	ArbolBinario raiz, ri ,rd;
	elementoA e;

	while(longitudLDE(principal)>1)
	{
		raiz=NULL;

		ri=quitarcabLDE(&principal);
		rd=quitarcabLDE(&principal);

		e.f = ri->dato.f + rd->dato.f;
		e.l = '$';

		nuevoArbol(&raiz, e, ri ,rd);
		insertarcabLDE(raiz, &principal);
		ordenarLDE(principal);
		printf("\n");
		imprimirLDE(principal);

	}
	return quitarcabLDE(&principal);

}

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
