
#define TAMMAX 200

//Definicion del TDA "PILA"
typedef struct pila
{
	tipoDato listaPila[TAMMAX];
	int cima;
}PILA;

//Operaciones fundamentales para el TDA "PILA"
void crearPila(PILA *P);

