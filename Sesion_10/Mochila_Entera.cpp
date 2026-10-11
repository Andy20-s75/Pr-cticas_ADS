//Mochila entera
#include<stdio.h>
int main(){
	FILE *arch;
	FILE *matriz;
	char nombre[30];
	int n,W;
	
	printf("Ingrese el nombre del archivo: ");
	scanf("%s", nombre);
	
	arch=fopen(nombre, "r");
	if(arch==NULL){
		printf("\nEl archivo no existe.\n");
	}
	//leer numero de objetos y la capacidad
	fscanf(arch, "%d %d", &n, &W); 
	int wi[n+1], vi[n+1];
	int V[n+1][W+1];
	
	for(int i=1;i<=n;i++){
		fscanf(arch, "%d %d", &wi[i], &vi[i]);//lee
	}
	printf("\nDatos leidos del archivo:\n");
	printf("Objetos: %d\n", n);
	printf("Capacidad: %d\n", W);
	
	for(int i = 1; i <= n; i++){
	    printf("Objeto %d -> Peso: %d  Valor: %d\n", i, wi[i], vi[i]);
	}
	
	for(int i=0; i<=n;i++){
		for(int w=0; w<=W;w++){//peso actual
			if(i==0 || w==0){
				V[i][w]=0;
			
			}else if(wi[i]<=w){//max
				
				int si=vi[i]+V[i-1][w-wi[i]];
				int no= V[i-1][w];
				
				if(si>no){
					V[i][w]=si;
				}else{
					V[i][w]=no;
				}
				
			}else{
				V[i][w]= V[i-1][w];//no lo toma
			}
		}
	}
	printf("Ganancia acumulada: %d", V[n][W]);
	fclose(arch);
	
	
	matriz = fopen("matriz.txt", "w");
	
	for(int i = 0; i <= n; i++){
	    for(int w = 0; w <= W; w++){
	        fprintf(matriz, "%d ", V[i][w]);
	    }
	    fprintf(matriz, "\n");
	}
	fclose(matriz);	
	return 0;
}
