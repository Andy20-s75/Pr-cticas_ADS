#include<stdio.h>

void Merge(int A[],int n, int L[], int R[]);
void MergeSort(int A[],int n);
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
	MergeSort(A,n);
	
	
	
	printf("Valores ordenados: ");
		
	for(int i=0; i<n;i++){
		printf("%d ", A[i]);
	}
	
	return 0;
}

void Merge(int A[],int n, int L[], int R[]){
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

	for (int t = 0; t < n; t++) {
        A[t] = S[t]; //Pasa los valores de S al arreglo A
    }
}
	
void MergeSort(int A[], int n){
	if(n<=1) return;
	
	int mitad= n/2;
	int mitad2= n - mitad;
	int L[mitad], R[mitad2];
	
	for(int i=0; i< mitad;i++){
		L[i]=A[i];
	}
	
	for (int j=0; j < mitad2;j++){
		R[j]=A[mitad+j];
	}
	MergeSort(L,mitad);    //L<- Mergesort(A[1:n/2])
	MergeSort(R,mitad2);	//R<- Mergesort(A[n/2+1:n])
	Merge(A,n,L,R);
}
