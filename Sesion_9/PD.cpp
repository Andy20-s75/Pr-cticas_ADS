//Sesiòn 9: Programaciòn Dinàmica
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITO INT_MAX

struct Cambio{
    int *d; 
    int n; 
};
//denominacion y la cantidad de monedas
int CHANGE(int N, int d[], int n, int P[]);
//Cuantas monedas regresara y en que denominaciones
int main(){
    Cambio *C = (Cambio*)malloc(sizeof(Cambio));
    int monto;

    printf("Cuantas monedas desea ingresar? ");
    scanf("%d", &C->n);

    C->d = (int*)malloc(C->n * sizeof(int));

    printf("Ingrese las denominaciones:\n\n");
    for(int i = 0; i < C->n; i++) {
        printf("Moneda %i: ", i + 1);
        scanf("%i", &C->d[i]);
    }

    printf("\nCantidad total a cambiar: ");
    scanf("%d", &monto);

    int P[monto+1];
    int result = CHANGE(monto, C->d, C->n,P);

    if (result == INFINITO){
        printf("\nNo hay forma de formar ese monto.\n");
    }else{
        printf("\nMinimo numero de monedas: %d\n", result);
        
        printf("Monedas a devolver:\n");
        int i=monto;
        while(i>0){
        	printf("- %d\n", P[i]);
        	i-=P[i]; 
		}
    }
    free(C->d);
    free(C);
    return 0;
}

int CHANGE(int N, int d[], int n, int P[]){
	//Cuantas monedas regresara y en que denominaciones
    int D[N + 1];
    D[0] = 0;
    P[0]=0;

    for(int i = 1; i <= N; i++){
        D[i] = INFINITO;//valor inicial

        for(int j = 0; j < n; j++){ //cantidad de denominaciones
            if(i - d[j] >= 0 && D[i - d[j]] != INFINITO){

                int cambio = 1 + D[i - d[j]];
                if(cambio < D[i]){
                    D[i] = cambio;
                    P[i]=d[j];
                }
            }
        }
    }

    return D[N];//minimo de monedas
}
