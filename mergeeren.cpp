#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

void MergeSort(int *A, int p, int r);
void Merge(int *A, int p, int q, int r);
	
int main(int argc, char* argv[]){	
    
	clock_t t_inicio, t_final;	//Variables para la medición de tiempos
    double t_intervalo;
	
	int i,j,n,*A;				//Variables para el algoritmo
	
	if (argc!=2) {				//Recibir por argumento el tamaño de n y el valor a buscar
		printf("\nIndique el tamanio de n y el valor a buscar - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	
	n=atoi(argv[1]);			//Tomar el argumento del main
	
	A=malloc(n*sizeof(int));	//Apartar memoria para n números  enteros
	if(A==NULL){
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}
	
	for(i=0;i<n;i++)			//Leer de la entrada estandar los n valores y colocarlos en el arreglo de números
		scanf("%d",&A[i]);

	//=========================================  
	//====== Algoritmo a medir el tiempo ======
	//=========================================

	t_inicio = clock();			//Inicia medición del tiempo
	MergeSort(A, 0, n - 1);		//Llamar al algoritmo
	t_final = clock();			//Termina medición del tiempo	
		
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición 
    printf("\nTiempo medido: %.10f segundos.", t_intervalo);
	
	for(i=0;i<n;i++)			//Enviar a la salida estandar el arreglo final
		printf("\nA[%d]=%d",i,A[i]);
	
	free(A);
	return 0;
}

void MergeSort(int *A, int p, int r){		//Algoritmo de ordenamiento de mezcla
	if (p < r){
		int q;
		if (((p + r - 1) % 2) == 1)
			q = (p + r - 2)/2;
		else
			q = (p + r - 1)/2;
		
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

void Merge(int *A, int p, int q, int r){
	int l = r - p + 1, i = p, j = q + 1, k;
	int C[l];
	for(k=0; k<l; k++){
		if(i<=q && j<=r){
			if(A[i]<A[j]){
				C[k]=A[i];
				i++;
			}
			else{
				C[k]=A[j];
				j++;
			}	
		}
		else if(i<=q){
			C[k]=A[i];
			i++;
		}
		else{
			C[k]=A[j];
				j++;
		}
	}
	k=p;
	for(i=0; i<l; i++){
		A[k]=C[i];
		k++;
	}
}
