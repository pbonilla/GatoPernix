#ifndef PLAYER
#define PLAYER
typedef struct{
	char* nombre;
	int numero;
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

void crearJugador(char* nombre, int num);
void encolarJugador(Jugador* jug);
Jugador* decolarJugador();
Jugador* siguienteEnTurno();
void flujoDeJuego();
int getCoor(char* eje);
int verificarGane(int jug);
int validarEntradas(int x, int y);

/*Globales*/
 int** matriz;
Nodo* cola;
