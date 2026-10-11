//Ejercicio 1. Sesión 2
#include<stdio.h>
int FibonacciA(int n){
	if (n==0) return 0; //1
	if(n==1) return 1; //1
	return FibonacciA(n-1)+ FibonacciA(n-2); //n
} //O(n)??

void FibonacciB(int fibo[], int n) { //b) 
    if (n >= 0) fibo[0] = 0; //1
    if (n >= 1) fibo[1] = 1; //1
    for (int i = 2; i <= n; i++) { //n
        fibo[i] = fibo[i - 1] + fibo[i - 2]; //n-1
    }
} //O(n)?

int main(){
	int n, op, fibo[100];
	printf("1. Fibonacci Recursivo. \n2. Fibonacci Iterado.\nCual quieres?: ");
	scanf("%d", &op);
	switch(op){
		case 1:
			printf("Ingresa un numero: ");
			scanf("%d", &n);
			printf("Fibonacci Recursivo: %d", FibonacciA(n));
			//a) Se ralentiza de 40 para arriba.	
			break;
			case 2:
				printf("Ingresa un numero: ");
				scanf("%d", &n);
				FibonacciB(fibo, n);
				printf("Fibonacci iterativo: %d", fibo[n]);			
				break;
				// c) Este no tarda :O, tal vez se deba a la recursividad, ya que repite calculos.
				default:
				printf("Opcion desconocida.");	
	}	
	return 0;
}
