// Ejercicio 3: Evaluación de polinomios
#include <stdio.h>
#include <math.h> 


int Clasico(int poli[], int grado, int x) { //1
    int resultado = 0; //1
    for (int i = 0; i <= grado; i++) {  //n
        resultado += poli[i] * (int)pow(x, i); //n^2
    }
    return resultado;
}


int Horner(int poli[], int grado, int x) {
    int resultado = poli[grado]; 
    for (int i = grado - 1; i >= 0; i--) {
        resultado = resultado * x + poli[i];
    }
    return resultado;
}

int main() {
    int poli[100];
    int grado, x;

    printf("Ingresa el grado del polinomio: ");
    scanf("%d", &grado);

    if (grado < 100) {
        for (int i = 0; i <= grado; i++) {
            printf("Ingresa el coeficiente a%d: ", i);
            scanf("%d", &poli[i]);
        }

        printf("Ingresa el valor de x: ");
        scanf("%d", &x);

        int resClasico = Clasico(poli, grado, x);
        int resHorner = 
		Horner(poli, grado, x);

        printf("\nResultado usando método clasico: %d\n", resClasico);
        printf("Resultado usando método de Horner: %d\n", resHorner);

    } else {
        printf("El grado debe ser menor que 100\n");
    }

    return 0;
}

