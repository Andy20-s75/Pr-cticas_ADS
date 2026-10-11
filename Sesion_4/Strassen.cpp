#include<stdio.h>
int Matriz(int row,int column);
int Matriz2(int row, int column);
int Strassen(int);
int main(){
	int row, column, r2,c2;
	Matriz(row,column);
	Matriz2(r2,c2);
	
	
	
	
	return 0;
}
int Strassen(int A[]){
	
}

int Matriz(int row,int column){
	printf("Filas: ");
	scanf("%d", &row);
	printf("Columnas: ");
	scanf("%d", &column);
	
	int A[row][column];
	
	for(int i=0;i<row;i++){
		for(int j=0; j<column;j++){
			printf("Valor %dx%d: ", i+1,j+1);
			scanf("%d", &A[i][j]);
	    }
	}
	printf("\nTu matriz:\n");
		for(int i=0;i<row;i++){
		for(int j=0; j<column;j++){
			printf("%d ", A[i][j]);
	    }
	    printf("\n");
	}
}
int Matriz2(int row,int column){
	printf("Matriz 2\n Filas: ");
	scanf("%d", &row);
	printf("Columnas: ");
	scanf("%d", &column);
	
	int A[row][column];
	
	for(int i=0;i<row;i++){
		for(int j=0; j<column;j++){
			printf("Valor %dx%d: ", i+1,j+1);
			scanf("%d", &A[i][j]);
	    }
	}
	printf("\n\nTu matriz:\n");
	for(int i=0;i<row;i++){
		for(int j=0; j<column;j++){
			printf("%d ", A[i][j]);
	    }
	    printf("\n");
	}
}
