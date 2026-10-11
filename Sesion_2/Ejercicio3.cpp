//Ejercicio 3. Sesión 3
#include <stdio.h>
#include <time.h>

// a)
void multiply(int A[2][2], int B[2][2]) {
    int x = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    int y = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    int z = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    int w = A[1][0]*B[0][1] + A[1][1]*B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

// b)
void Lineal(int F[2][2], int n) {
    int M[2][2] = {{0, 1}, {1, 1}};
    for (int i = 2; i <= n; i++)
        multiply(F, M);
}

int fiboLineal(int n) {
    if (n == 0) return 0;
    int F[2][2] = {{0, 1}, {1, 1}};
    Lineal(F, n - 1);
    return F[1][1];
}

// Incisos c, d, e
void Binario(int F[2][2], int n) {
    if (n == 0 || n == 1) return;

    int M[2][2] = {{0, 1}, {1, 1}};
    Binario(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

int fiboBinario(int n) {
    if (n == 0) return 0;
    int F[2][2] = {{0, 1}, {1, 1}};
    Binario(F, n - 1);
    return F[1][1];
}

int main() {
    int n;

    printf("Ingresa el valor de n para calcular F(n): ");
    scanf("%d", &n);

    // Lineal
    clock_t start1 = clock();
    int result1 = fiboLineal(n);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    // Binario
    clock_t start2 = clock();
    int result2 = fiboBinario(n);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("\nMétodo lineal:     F(%d) = %d | Tiempo: %.6f segundos\n", n, result1, time1);
    printf("Método binario:    F(%d) = %d | Tiempo: %.6f segundos\n", n, result2, time2);

    return 0;
}
