#define tamano 3
#define numCPU 1;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PrototipoStructs.h"
#include "Turnos.c"



/*Funciones*/

int main(int argc,char* argv){
	matriz = crearMatriz();
	crearJugador(1);
	crearJugador(2);
	flujoDeJuego();
	return 1;
}

int** crearMatriz(){
	
	int** matrix = (int**)malloc(sizeof(int*)*tamano);
	int i;
	for(i=0;i<tamano;i++){
		matrix[i] = (int*)malloc(sizeof(int)*tamano);
	}
	
	return matrix;
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


