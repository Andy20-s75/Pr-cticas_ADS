#include <stdio.h>
//Ejercicio 1.
void merge(int x[], int y[], int resultado[], int n) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < n) {
        if (x[i] < y[j]) {
            resultado[k++] = x[i++];
        } else {
            resultado[k++] = y[j++];
        }
    }
    while (i < n) {
        resultado[k++] = x[i++];
    }
    while (j < n) {
        resultado[k++] = y[j++];
    }
}
//Ejercicio 2.
int eliminarDuplicados(int arr[], int n, int resultado[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int duplicado = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == resultado[j]) {
                duplicado = 1;
                break;
            }
        }
        if (!duplicado) {
            resultado[k++] = arr[i];
        }
    }
    return k; 
}
//Ejercicio 3.
void mezcla(int a[], int b[], int resultado[], int n) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) resultado[k++] = a[i++];
        else resultado[k++] = b[j++];
    }
    while (i < n) resultado[k++] = a[i++];
    while (j < n) resultado[k++] = b[j++];
}

int main() {
    int x[] = {0, 1, 3, 5};
    int y[] = {2, 4, 6, 7};
    int n = 4;
    int resultado[8]; 

    merge(x, y, resultado, n);

    printf("\nArreglo combinado:\n");
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", resultado[i]);
    }
    
    int r;
    printf("\nCuantos numeros pondras? ");
    scanf("%d", &r);
    int arr[r];
    for(int i=0; i<r; i++){
    	printf("Valor %i: ", i+1);
    	scanf("%d", &arr[i]);
	}
    int resultado2[r];
    int nuevoTam = eliminarDuplicados(arr, r, resultado);

    printf("\nArreglo sin duplicados:\n");
    for (int i = 0; i < nuevoTam; i++) {
        printf("%d ", resultado[i]);
    }
    
    int A1[] = {1, 4};
    int A2[] = {2, 5};
    int A3[] = {3, 6};
    int t = 2;
    int temp1[4], resultado3[6];
    merge(A1, A2, temp1, n);
    mezcla(temp1, A3, resultado, n * 2);

    printf("\nArreglo combinado:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", resultado[i]);
    }

    return 0;
}
