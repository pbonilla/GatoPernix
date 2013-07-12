#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define tamano 3


typedef struct Player{
	char* nombre;
	int numero;
}Jugador;

typedef struct nodo{
	Jugador* jug;
	struct nodo *sig;
}Nodo;


/*Globales*/
 int** matriz;
Nodo* cola;

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


/*Funciones*/

int main(int argc,char* argv){
	crearMatriz();
	crearJugador("Pablo",1);
	crearJugador("Isaac",2);
	flujoDeJuego();
	return 1;
}

void crearMatriz(){
	matriz = (int**)malloc(sizeof(int*)*tamano);
	int i;
	for(i=0;i<tamano;i++){
		matriz[i] = (int*)malloc(sizeof(int)*tamano);
	}
}

void imprimirMatriz(){
	int i,j;
	for(i=0;i<tamano;i++){
		printf("%s","-------\n|");
		for(j=0;j<tamano;j++){
			printf("%i|",matriz[i][j]);
		}
		printf("\n");
	}
	printf("-------\n");
}


//***FUNCIONES DE JUEGO ***//
void crearJugador(char* nombre, int num){
	Jugador* player = (Jugador*)malloc(sizeof(Jugador));
	player->nombre = (char*)malloc(sizeof(char)*50);
	strcat(player->nombre,nombre);
	player->numero = num;
	encolarJugador(player);
}

void encolarJugador(Jugador* jugador){
	printf("%d\n",jugador->numero);
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->jug = jugador;
	if(cola==NULL){
		cola = nuevo;
	}else{
		Nodo* aux = cola;
		while(aux->sig!=NULL){
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

Jugador* decolarJugador(){
	if(cola==NULL){
		return NULL;
	}else{
		Nodo* node = cola;
		cola = cola->sig;
		printf("COLA %i",node->jug->numero);
		return node->jug;
	}	
}

Jugador* siguienteEnTurno(){
	Jugador* jug = decolarJugador();
	printf("llegue aca\n");
	encolarJugador(jug);
	return jug;
}

void flujoDeJuego(){
	Jugador* actual;
	int numJug;
	int posX,posY;
	while(1){
		actual = siguienteEnTurno();
		numJug = actual->numero;
		while(1){
			posX = getCoor("X");
			posY = getCoor("Y");
			if(validarEntradas(posX,posY)){
				matriz[posX][posY] = numJug;
				break;
			}else{
				printf("Error: Esta casilla ya esta ocupada\n");
			}
		}
		imprimirMatriz();
		if(verificarGane(numJug)){
			printf("Felicitaciones Jugador %i: HA GANADO EL JUEGO\n",numJug);
			break;
		}
	}
}


int getCoor(char* eje){
	int opcion;
	printf("Ingrese la coordenada %s: ",eje);
	while(1){
		scanf("%i",&opcion);
		printf("\n");
		if(0<opcion && opcion<4){
			opcion--;
			return opcion;
		}else{
			printf("Error: Favor ingrese un numero de 1 a 3\n");
		}
		
	}
}

int validarEntradas(int x, int y){
	return 1;
}

int verificarGane(int jug){
	return 1;
}
