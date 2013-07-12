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

/*Prototipos*/
void crearMatriz();
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
