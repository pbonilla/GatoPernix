/* Globales*/
NodoA* raiz; 

/*Prototipos*/

NodoP* getPosiblesCoordenadas();
Punto* crearPunto(int x, int y);
void crearArbol();

/*Funciones*/
NodoP* getPosiblesCoordenadas(int** _matriz){
	int i,j;
	NodoP* primero;
	for(i=0;i<tamano;i++){
		for(j=0;j<tamano;j++){
			if(_matriz[i][j] == 0){
				Punto* punto = crearPunto(i,j);
				NodoP* nuevo = (NodoP*)malloc(sizeof(NodoP));
				nuevo->punto = punto;
				if(primero == NULL){
					primero = nuevo;
				}else{
					NodoP* aux = primero;
					while(aux->sig != NULL){
						aux = aux->sig;
					}
					aux->sig = nuevo;
				}
			}
		}
	}
	return primero;
}

int** actualizaMatriz(Punto* punto, int** matrizO, int numJug){
	int** matrizC = crearMatriz();
	copyMatriz(matrizC,matrizO);
	matrizC[punto->coorX][punto->coorY] = numJug;
	return matrizC;
}

void copyMatriz(int** mCopia, int** mOriginal){
	int i,j;
	for(i=0;i<tamano;i++){
		for(j=0;j<tamano;j++){
			mCopia[i][j] = mOriginal[i][j];
		}
	}
}

Punto* crearPunto(int x, int y){
	Punto* punto = (Punto*)malloc(sizeof(Punto));
	punto->coorX = x;
	punto->coorY = y;
	return punto;
}

void crearArbol(){
	raiz = (NodoA*)malloc(sizeof(NodoA));
}

NodoA* crearNodo(int** matrix){
	NodoA* hijo = (NodoA*)malloc(sizeof(NodoA));
	hijo->tablero = matrix;
	return hijo;
}

void agregarHijo(NodoA* padre, NodoA* hijo){
	if(padre->hijo == NULL){
		padre->hijo = hijo;
	}else{
		NodoA* aux = padre->hijo;
		while(aux->sig!=NULL){
			aux = aux->sig;
		}
		aux->sig = hijo;
	}
}

NodoA* getHojas(){
	
}
