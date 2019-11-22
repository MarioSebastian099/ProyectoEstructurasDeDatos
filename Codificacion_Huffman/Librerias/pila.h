
#define TAMMAX 200

//Definicion del TDA "PILA"
typedef struct pila
{
	tipoDato listaPila[TAMMAX];
	int cima;
}PILA;

//Operaciones fundamentales para el TDA "PILA"
void crearPila(PILA *P);
void insertarPila(PILA *P, tipoDato elemento);
tipoDato quitarPila(PILA *P);
void limpiarPila(PILA *P);

tipoDato cimaPila(PILA P);

int pilaLlena(PILA P);
int pilaVacia(PILA P);


