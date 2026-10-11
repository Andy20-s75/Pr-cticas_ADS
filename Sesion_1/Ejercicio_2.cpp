//Ejercicio 2.
#include <stdio.h>

int main() {
    int A[100], B[100][100];
    int n, i, j, k;


    printf("¿Cuántos elementos tiene el arreglo A? ");
    scanf("%d", &n);

    printf("Ingresa los %d elementos de A:\n", n);
    for (i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i < j) {
                int suma = 0;
                for (k = i; k <= j; k++) {
                    suma += A[k];
                }
                B[i][j] = suma;
            } else {
                B[i][j] = 0;
            }
        }
    }

    printf("\nMatriz B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}

