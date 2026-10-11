//Matriz entera 2
#include<stdio.h>
#include<string.h>
int main(){
	FILE *matriz;
	FILE *mochila;
	char nombre[30], nom_mochila[30];
		
	printf("Ingrese el nombre del archivo: ");
	scanf("%s", nombre);
	
	matriz=fopen(nombre, "r");
	if(matriz==NULL){
		printf("\nEl archivo no existe.\n");
		return 1;
	}
	
	if(strcmp(nombre, "matriz1.txt")==0){
		strcpy(nom_mochila,"mochila1.txt");
	}else if(strcmp(nombre, "matriz2.txt")==0){
		strcpy(nom_mochila, "mochila2.txt");
	}else if(strcmp(nombre, "matriz3.txt")==0){
		strcpy(nom_mochila, "mochila3.txt");
	}else if(strcmp(nombre, "matriz4.txt")==0){
		strcpy(nom_mochila,"mochila4.txt");
	}else if(strcmp(nombre, "matriz5.txt")==0){
		strcpy(nom_mochila, "mochila5.txt");
	}
	
	mochila=fopen(nom_mochila, "r");
	if(mochila==NULL){
		printf("\nNo se pudo conectar el archivo.");
		return 1;
	}
	
	char linea[1000];
	int colum=0, fila=0;
	//lee primera línea 
    if (fgets(linea, sizeof(linea), matriz)) {
        char *ptr = linea;
        int valor;
        while (sscanf(ptr, "%d", &valor) == 1) {//cuenta las columnas
            colum++;
            //recorre la linea completa ignorando los espacios
            while (*ptr && *ptr != ' ' && *ptr != '\n') ptr++;
            while (*ptr == ' ') ptr++;
        }
        fila = 1; //se conto la primera fila
    }
    //filas 
    while (fgets(linea, sizeof(linea), matriz)) {
        fila++;
    }
    fclose(matriz);
    
    int n= fila-1;
    int W= colum-1;
    int wi[n+1],vi[n+1];
    int V[n+1][W+1];
    printf("Objetos = %d\nCapacidad de la mochila= %d\n", n, W);
    
	for(int i=1; i<=n;i++){
		if(fscanf(mochila,"%d %d", &wi[i], &vi[i])!=2){//si no lee los dos datos
		printf("\nArchivo vacio.");
		fclose(mochila);
		return 1;		
		}
	}	
	
	for(int i=0; i<=n;i++){
		for(int w=0; w<=W;w++){//w peso actual
			if(i==0 || w==0){
				V[i][w]=0;
			
			}else if(wi[i]<=w){//si o no
				
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
	int w = W;
	printf("Objetos tomados:\n");
	for (int i = n; i > 0; i--) {
	    if (V[i][w] != V[i-1][w]) {
	        printf("Objeto %d tomado, Peso: %d | Valor: %d\n", i, wi[i], vi[i]);
	        w -= wi[i];//capacidad actualizada
	    }
	}//O(nW) depende de la cantidad de objetos y la capacidad de la mochila

	printf("Ganancia acumulada: %d", V[n][W]);
	fclose(mochila);
	
	return 0;
}
