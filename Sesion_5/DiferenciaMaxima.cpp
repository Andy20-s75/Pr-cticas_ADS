//Sin el Divide y Vencerás.
#include<stdio.h>
float Dif_Maxima(float A[], int n);
int main(){
	int n;
	printf("Ingresa el tamanio de tu arreglo: ");
	scanf("%d",&n);
	
	float A[n];
	printf("Ingresa tus valores:\n");
	for(int i=0; i<n; i++){
		printf("valor %d: ", i+1);
		scanf("%f", &A[i]);
	}
	Dif_Maxima(A, n);
	return 0;
}

float Dif_Maxima(float A[], int n){
	float menor=A[0], mayor=A[0],dif;
	for(int i=1; i<n; i++){
		if(A[i]<menor) menor=A[i];
		if(A[i]>mayor) mayor=A[i];
	}
	printf("El numero mas pequeño es: %.3f\n", menor);
	printf("El numero mas grande es: %.3f\n", mayor);
	
	dif= mayor-menor;
	
	printf("\nLa maxima diferencia es: %.3f", dif);
	return dif;
}
