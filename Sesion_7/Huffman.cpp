//Sesión 7: Algoritmos ávidos.
//Ejercicio 1. Codificación de Huffman
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char C;
    float freq;
    struct Nodo *hijoIzq, *hijoDer;
} Nodo;

typedef struct Monticulo {
    Nodo *nodo[100];
    int tam;
} Monticulo;

Nodo* ExtractMin(Monticulo* monti){
    if(monti->tam == 0) return NULL;

    Nodo* min = monti->nodo[0];
    monti->nodo[0] = monti->nodo[monti->tam - 1]; // el primer nodo sera el ultimo
    monti->tam--;

    int i = 0;
    int NodoHijo = 2*i + 1; //nodo izquierdo
    Nodo* final = monti->nodo[0];

    while (NodoHijo < monti->tam) { // mientras exista hijo izquierdo
        if (NodoHijo + 1 < monti->tam &&
            monti->nodo[NodoHijo + 1]->freq < monti->nodo[NodoHijo]->freq) {
            NodoHijo++;
        }

        // si final es mayor que el hijo, lo baja
        if (final->freq > monti->nodo[NodoHijo]->freq) {
            monti->nodo[i] = monti->nodo[NodoHijo];
            i = NodoHijo;
            NodoHijo = 2*i + 1;   //  actualizar el índice del hijo 
        } else {
            break; // ya está en posición correcta
        }
    }

    monti->nodo[i] = final;
    return min;
}


void Insert(Monticulo* monti, Nodo* nuevo) {
    int i = monti->tam;
    monti->nodo[i] = nuevo;
    // subir mientras sea menor que el padre
    while (i > 0 && monti->nodo[i]->freq < monti->nodo[(i - 1) / 2]->freq) {
        Nodo* tmp = monti->nodo[(i - 1) / 2];
        monti->nodo[(i - 1) / 2] = monti->nodo[i];
        monti->nodo[i] = tmp;
        i = (i - 1) / 2;
    }
    monti->tam++;
}
Nodo* Huffman(Monticulo* monti) {

    int paso = 1;

    while (monti->tam > 1) {

        Nodo* x = ExtractMin(monti);
        Nodo* y = ExtractMin(monti);

        printf("\nPaso %d:", paso++);
        printf("\n  Hijo izquierdo:  %c (%.2f)", x->C, x->freq);
        printf("\n  Hijo derecho:    %c (%.2f)", y->C, y->freq);

        Nodo* z = (Nodo*)malloc(sizeof(Nodo));
        z->C = '*';                     // Nodo interno (no tiene letra)
        z->freq = x->freq + y->freq;    // Suma de frecuencias
        z->hijoIzq = x;
        z->hijoDer = y;

        printf("\n  Nodo padre creado: %c (%.2f)\n", z->C, z->freq);

        Insert(monti, z);
    }

    // último nodo es la raíz
    Nodo* raiz = ExtractMin(monti);

    printf("\n\nÁrbol completo generado. Frecuencia total: %.2f\n", raiz->freq);

    return raiz;
}

int main(){
    Monticulo *monti = (Monticulo*)malloc(sizeof(Monticulo));
    if(!monti){ printf("Fallo malloc\n"); return 1; }
    monti->tam = 0;

    FILE* arch = fopen("frecuencias.txt", "r");
    if(!arch){
        printf("No se pudo abrir frecuencias.txt\n");
        free(monti);
        return 1;
    }

    char letra;
    float freq;
    while (fscanf(arch, " %c %f", &letra, &freq) == 2) { // Lee el caracter y la frecuencia
        Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
        if(!nodo){ printf("Fallo malloc nodo\n"); break; }
        nodo->C = letra;
        nodo->freq = freq;
        nodo->hijoDer = nodo->hijoIzq = NULL;
        Insert(monti, nodo);
    }
    fclose(arch);

    // Prueba: extraer todos los mínimos y mostrarlos
    printf("Caracter   Frecuencia:\n");
    Nodo* x;
    while ((x = ExtractMin(monti)) != NULL) {
        printf("%c %.2f\n", x->C, x->freq);
        free(x);
        if(monti->tam == 0) break;
    }

    free(monti);
    return 0;
}

