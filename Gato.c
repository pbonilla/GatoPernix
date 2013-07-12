#define tamano 3
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PrototipoStructs.h"
#include "Turnos.c"



/*Funciones*/

int main(int argc,char* argv){
	crearMatriz();
	crearJugador(1);
	crearJugador(2);
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


