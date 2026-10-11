//Problema de la mochila fraccionaria.
#include<stdio.h>
struct Objeto{
	int peso;
	int valor;
	float S;
};

void Merge(Objeto A[],int n, int L[], int R[]);
void MergeSort(Objeto A[], int n);
void Mochila(int W, int n, int wi[], int vi[]);
int main(){
	int W, n;
	printf("Ingrese la capacidad de tu mochila: ");
	scanf("%d", &W);
	
	printf("Cantidad de objetos: ");
	scanf("%d", &n);
	
	int vi[n], wi[n];
	
	for(int i=0; i<n; i++){
		printf("\nPeso Objeto %d: ",i+1);
		scanf("%d", &wi[i]);
		printf("Valor Objeto %d: ", i+1);
		scanf("%d", &vi[i]);
	}
	
	Mochila(W,n,wi,vi);
	
	
	return 0;
}
void Merge(Objeto A[],int n, Objeto L[], Objeto R[]){//O(n)
	int mL= n/2, mR= n - mL; 
	Objeto S[n]; //arreglo ordenado
	int i = 0, j = 0, k=0;

    while(i < mL && j < mR){
    		if(L[i].S > R[j].S){ //mayor
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
void MergeSort(Objeto A[], int n){//O(nlogn)
	if(n<=1) return;
	
	int mitad= n/2;
	int mitad2= n - mitad;
	Objeto L[mitad], R[mitad2];
	
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
void Mochila(int W, int n, int wi[], int vi[]){
	Objeto obj[n];
	
	for(int i=0; i<n; i++){//O(n) <- por cada iteracion
		obj[i].peso=wi[i]; 
		obj[i].valor=vi[i];
		obj[i].S=(float)vi[i]/wi[i]; //calcula el objeto mas valioso (ratio)
	}
	MergeSort(obj,n);
	
	float m=0.0;
	printf("Objetos tomados:\n");
	for(int i=0; i<n && W>0;i++){
		if(obj[i].peso <= W){
			W -=obj[i].peso; //se actualiza mochila
			m+= obj[i].valor; //valor ganado
			printf("\nObjeto %i tomado ENTERO, Peso: %d | Valor: %d", i+1, obj[i].peso, obj[i].valor);//cupo
		}else{
			float T=(float)W/obj[i].peso;//fraccion
			m+=obj[i].valor*T;
			printf("\nObjeto %i tomando una parte, Peso: %d | Valor: %d", i+1, obj[i].peso, obj[i].valor, T);
			W=0;//mochila llena
		}
	}
	
	printf("\nSuma de los valores de los objetos tomados en la mochila: %.2f", m);	
}
