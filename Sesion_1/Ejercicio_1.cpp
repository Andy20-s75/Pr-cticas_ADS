//Ejercicio 1. Funcion Multiply(x,y)
#include<stdio.h>
#include<stdlib.h>
int multiply(int x, int y){
	if (y == 0) {
        return 0;
    }

    int z = multiply(x, y / 2);

    if (y % 2 == 0) {
        return 2*z;
    } else {
        return x+2*z;
    }
}

int main(){
	int  x, y, resultado;
	
	printf("Ingrese el valor x:");
	scanf("%d", &x);
	printf("Ingrese el valor y: ");
	scanf("%d", &y);
	/*
    x = rand() % 10000000;
    y= rand() % 1000000;*/	
	
	if(y < 0){
		printf("\nEl valor de y debe ser mayor o igual a cero");
	}
	
	resultado = multiply(x, y);
    printf("El resultado de %d X %d es: %d\n", x, y, resultado);
	
	
	return 0;
}
