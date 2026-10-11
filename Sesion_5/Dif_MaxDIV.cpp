//Con el Divide y Vnecerás.
#include <stdio.h>

float Buscar_Min(float A[], int inicio, int fin) {
    if (inicio == fin) {
        return A[inicio];
    } else {
        int mitad = (inicio + fin) / 2;
        float min_izq = Buscar_Min(A, inicio, mitad);
        float min_der = Buscar_Min(A, mitad + 1, fin);
        return (min_izq < min_der) ? min_izq : min_der;
    }
}

float Buscar_Max(float A[], int inicio, int fin) {
    if (inicio == fin) {
        return A[inicio];
    } else {
        int mitad = (inicio + fin) / 2;
        float max_izq = Buscar_Max(A, inicio, mitad);
        float max_der = Buscar_Max(A, mitad + 1, fin);
        return (max_izq > max_der) ? max_izq : max_der;
    }
}

void Dif_Maxima(float A[], int n) {
    float minimo = Buscar_Min(A, 0, n - 1);
    float maximo = Buscar_Max(A, 0, n - 1);
    float diferencia = maximo - minimo;

    printf("\nMinimo: %.2f\n", minimo);
    printf("Maximo: %.2f\n", maximo);
    printf("Diferencia: %.2f\n", diferencia);
}

int main() {
    int n;
    printf("Ingresa el tamaño de tu arreglo: ");
    scanf("%d", &n);

    float A[n];
    printf("Ingresa tus valores:\n");
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &A[i]);
    }

    Dif_Maxima(A, n);

    return 0;
}

