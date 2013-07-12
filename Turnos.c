//***FUNCIONES DE JUEGO ***//
void crearJugador(int num){
	Jugador* player = (Jugador*)malloc(sizeof(Jugador));
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
	int rondas=0;
	while(rondas<9){
		actual = siguienteEnTurno();
		numJug = actual->numero;
		printf("Jugador %i es su turno\n",numJug);
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
		actual->turnos += 1;
		imprimirMatriz();
		if(verificarGane(actual,posX,posY)){
			printf("Felicitaciones Jugador %i: HA GANADO EL JUEGO\n",numJug);
			break;
		}
		rondas++;
	}
	printf("FIN DEL JUEGO\n");
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
	if(matriz[x][y] == 0){
		return 1;
	}else{
		return 0;
	}
}

int verificarGane(Jugador* jug,int x, int y){
	if(jug->turnos < 3){
		return 0;
	}
	if(!verificarVertical(jug->numero,y)){
		if(!verificarHorizontal(jug->numero,x)){
			if(!verificarDiagonalDer(jug->numero)){
				if(!verificarDiagonalIzq(jug->numero)){
					return 0;
				}
			}
		}
	}
	return 1;
}

int verificarVertical(int num,int y){
	int x,flag;
	for(x=0;x<tamano;x++){
		if(matriz[x][y] != num){
			return 0;
		}
	}
	return 1;
}

int verificarHorizontal(int num, int x){
	int y,flag;
	for(y=0;y<tamano;y++){
		if(matriz[x][y] != num){
			return 0;
		}
	}
	return 1;
}

int verificarDiagonalDer(int num){
	int i;
	int flag;
	for(i=0;i<tamano;i++){
		if(matriz[i][i]!=num){
			return 0;
		}
	}
	return 1;
}

int verificarDiagonalIzq(int num){
	int i,j;
	int flag;
	for(i=0,j=tamano-1;i<tamano;i++,j--){
		if(matriz[i][j]!=num){
			return 0;
		}
	}
	return 1;
}
