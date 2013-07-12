//***FUNCIONES DE JUEGO ***//
void crearJugador(char* nombre, int num){
	Jugador* player = (Jugador*)malloc(sizeof(Jugador));
	player->nombre = (char*)malloc(sizeof(char)*50);
	strcat(player->nombre,nombre);
	player->numero = num;
	encolarJugador(player);
}

void encolarJugador(Jugador* jugador){
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
		return node->jug;
	}	
}

Jugador* siguienteEnTurno(){
	Jugador* jug = decolarJugador();
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




