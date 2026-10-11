//Sesion 8: Algoritmo de Kruskal
#include<stdio.h>
#include<stdlib.h>

struct Grafo{
    int n;      //numero de elementos
    int *raiz;  //padre de cada elemento
    int *nivel; //altura
};
Grafo* makeset(int u);
int find(Grafo *u, int x);
void G_union (Grafo *arbol, int u, int v);
void Merge(int A[],int n, int L[], int R[]);
void MergeSort(int A[],int n);
void kruskal(Grafo *g, int u[], int v[], int w[], int a);

int main(){
	Grafo *g=makeset(5);
	int u[] = {0, 0, 1, 1, 1, 3, 2, 0}; //origen
    int v[] = {1, 2, 2, 3, 4, 4, 4, 4}; //destino
    int w[] = {2, 5, 5, 3	, 2, 4, 4, 6}; // pesos
    int a=9; //total de aristas
	printf("Estado inicial de los conjuntos:\n");
	for(int i=0;i< g->n;i++){
		printf("Nodo %d tiene como raiz a: %d| nivel[%d]\n", i, g->raiz[i],i,g->nivel[i]);
	}
	
	kruskal(g, u, v, w, a);

	
	return 0;
}
Grafo* makeset(int u){ //crea un conjunto nuevo
	Grafo *nuevo=(Grafo*)malloc(sizeof(Grafo));
	if(nuevo==NULL) return NULL;
	
	nuevo->n=u;
	nuevo->raiz=(int*)malloc(u*sizeof(int));
	nuevo->nivel=(int*)malloc(u*sizeof(int));
	if(nuevo->raiz==NULL || nuevo->nivel==NULL){
		free(nuevo->raiz);
		free(nuevo->nivel);
		free(nuevo);
		free(nuevo);
		return NULL;
	}
	for(int i; i<u;i++){
		nuevo->raiz[i]=i;
		nuevo->nivel[i]=0; //apenas inicia
	}	
	return nuevo;
}

int find(Grafo *en, int x){
	if(en->raiz[x] != x){ //x no es su propio padre (hay mas de un conjunto ahora)
		en->raiz[x]= find(en,en->raiz[x]); //busca hasta encontrar al padre de x 
	}
	return en->raiz[x];//devuelve a la raiz encontrada
}

void G_union (Grafo *arbol, int u, int v){
	int xu = find(arbol, u);
	int xv = find(arbol, v);
	if(xu == xv){
		printf("%d y %d estan en el mismo conjunto", xu, xv);
	}
	if(arbol->nivel[xu] < arbol->nivel[xv]){ //si se cumple, entonces xu se coloca abajo de xv
		arbol->raiz[xu]=xv;
	}else if(arbol->nivel[xu] > arbol->nivel[xv]){//se hace lo mismo pero al revez
		arbol->raiz[xv]=xu;
	}else{ //tienen el mismo tamaño(nivel)
		arbol->raiz[xv]=xu;//xv esta abajo de xu ahora
		arbol->nivel[xu]++; //se incrementa el nivel de la raiz
	}
}

void Merge(int A[],int n, int L[], int R[]){
	int mL= n/2, mR= n - mL; //aqui se muestra la "division" del arreglo completo de cada lado (D/I).
	int S[n]; //arreglo ordenado
	int i = 0, j = 0, k=0;

    while(i < mL && j < mR){
    		if(L[i] < R[j]){
				S[k++]=L[i++];  		
			}else{
				S[k++]=R[j++];
			}
	}
	while (i < mL) {  //copia los elementos restantes de L si es que R acabo ya y viceversa
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
void kruskal(Grafo *g, int u[], int v[], int w[], int a){
	MergeSort(w,a); //ordenar pesos
	printf("\nAristas ordenadas por peso:\n");
	for(int i=0;i < a;i++){
		printf("(%d, %d) peso %d\n",u[i], v[i], w[i]);
	}
	
	int Xu[a], Xv[a];
	int cont=0;

	for(int i=0; i<a;i++){
		int xu=find(g,u[i]);
		int xv=find(g, v[i]);
		printf("\nArista (%d,%d), peso %d", u[i], v[i],w[i]);	
	
		if(xu!= xv){
			printf("\nNo forma ciclo");
			G_union(g,xu,xv);
			cont++; //la arista se agrega al arbol
		}else{
			printf("\nSe forma un ciclo");
		}
    }	
}

