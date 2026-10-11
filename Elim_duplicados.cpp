//Eliminar duplicados
#include<stdio.h>

int Merge(int A[],int n, int L[], int R[]);
int MergeSort(int A[],int n);
int main(){
	int n;
	printf("Cuantos valores: ");
	scanf("%d", &n);
	
	int A[n];
	for(int i=0;i<n;i++){
		printf("Valor %i: ", i +1);
		scanf("%d", &A[i]);	
	}
	
	for(int i=0;i<n;i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	n=MergeSort(A,n);
		
	printf("Valores ordenados sin duplicados: ");
	
	for(int i=0; i<n;i++){
		printf("%d ", A[i]);
	}
	
	return 0;
}

int Merge(int A[],int n, int L[], int R[]){
	int mL= n/2, mR= n - mL; 
	int S[n]; //arreglo ordenado
	int i = 0, j = 0, k=0;

    while(i < mL && j < mR){
    		if(L[i] < R[j]){
				S[k++]=L[i++];  		
			}else{
				S[k++]=R[j++];
			}
	}
	while (i < mL) {
        S[k++] = L[i++];
    }

    while (j < mR) {
        S[k++] = R[j++];
    }
    //eliminar duplicados
    int E=0;
    if(n>0){
    	A[E++]=S[0];
	}
	for (int t = 1; t < n; t++) {
        if(S[t] != S[t-1]){
        	A[E++]= S[t];
		} 
    }
    return E;
}
	
int MergeSort(int A[], int n){
	if(n<=1) return n;
	
	int mitad= n/2;
	int mitad2= n - mitad;
	int L[mitad], R[mitad2];
	
	for(int i=0; i< mitad;i++){
		L[i]=A[i];
	}
	
	for (int j=0; j < mitad2;j++){
		R[j]=A[mitad+j];
	}
	mitad=MergeSort(L,mitad);    //ignora los duplicados de L
	mitad2=MergeSort(R,mitad2);	//y de R
	return Merge(A,mitad+mitad2,L,R);//los junta
}
