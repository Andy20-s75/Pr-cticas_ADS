// Ejercicio 2. Sesión 2
#include <stdio.h>
int potenciaLineal(int a, int n, int m) {
    int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado = (resultado * a) % m;
    }
    return resultado;
}

int potenciaLog(int a, int n, int m) {
    int resultado = 1;
    a = a % m;
    while (n > 0) {
        if (n % 2 == 1) {
            resultado = (resultado * a) % m;
        }
        a = (a * a) % m;
        n = n / 2;
    }
    return resultado;
}

int main() {
    int a, exp, mod;

   
    printf("Ingresa la base (a): ");
    scanf("%d", &a);
    printf("Ingresa el exponente (n): ");
    scanf("%d", &exp);
    printf("Ingresa el módulo (m): ");
    scanf("%d", &mod);

    printf("\nPotencia lineal: %d\n", potenciaLineal(a, exp, mod));
    printf("Potencia rápida: %d\n", potenciaLog(a, exp, mod));

    return 0;
}
