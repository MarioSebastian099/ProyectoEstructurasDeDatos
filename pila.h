
#define TAMMAX 200

//Declaración  "PILA"
typedef struct pila
{
	tipoDato listaPila[TAMMAX];
	int cima;
}PILA;


//Funciones de la Pila
void crearPila(PILA *P);
void insertarPila(PILA *P, tipoDato elemento);
tipoDato quitarPila(PILA *P);
void limpiarPila(PILA *P);

tipoDato cimaPila(PILA P);

int pilaLlena(PILA P);
int pilaVacia(PILA P);
