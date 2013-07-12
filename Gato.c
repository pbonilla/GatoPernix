#include <stdlib.h>
#include <stdio.h>
#define tamano 3

/*Globales*/
 int** matriz;

/*Prototipos*/
void crearMatriz();
void imprimirMatriz();
/*Funciones*/

int main(int argc,char* argv){
	crearMatriz();
	imprimirMatriz();
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
