#ifndef PLAYER
#define PLAYER
typedef struct{
	char* nombre;
	int numero;
	int turnos;
}Jugador;
#endif

#ifndef NODE
#define NODE
typedef struct nodo{
	Jugador* jug;
	struct nodo *sig;
}Nodo;
#endif

#ifndef PUNTO
#define PUNTO
typedef struct point{
	int coorX;
	int coorY;
}Punto;
#endif

#ifndef NODO_PUNTO
#define NODO_PUNTO
typedef struct nodoP{
	Punto* punto;
	nodoP* sig;
}NodoP;
#endif

#ifndef NODO_ARBOL
#define NODO_ARBOL
typedef struct nodoA{
	int** tablero;
	int valor;
	struct nodoA* hijo;
	struct nodoA* hermano;
}NodoA;
#endif


/*Prototipos*/
int** crearMatriz();
void imprimirMatriz();

void crearJugador(int num);
void encolarJugador(Jugador* jug);
Jugador* decolarJugador();
Jugador* siguienteEnTurno();
void flujoDeJuego();
int getCoor(char* eje);
int verificarGane(Jugador* jug, int x, int y);
int validarEntradas(int x, int y);
int verificarVertical(int num,int y);
int verificarHorizontal(int num,int x);
int verificarDiagonalDer(int num);

/*Globales*/
 int** matriz;
Nodo* cola;
