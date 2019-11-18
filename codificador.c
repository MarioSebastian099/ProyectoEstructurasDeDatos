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


