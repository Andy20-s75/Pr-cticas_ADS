//Cola de prioridad
//Sesión 7: Algoritmos ávidos.
//Ejercicio 1. Codificación de Huffman
#include<stdio.h>
#include<stdlib.h>
struct Nodo{
	char C;
	float freq;
	Nodo *hijoIzq, *hijoDer;
};
struct Monticulo{
	Nodo* nodo[100];
	int tam;
};
void AcomodaA(Nodo *Monti[], int size);
void AcomodaB(Nodo *Monti[], int size);
int main(){
	Nodo *Monti[50];
	int size=0; //Número de elementos que hay actualmente en la cola.
	int op;
	char simb;
	float freq;
		
	do{
		printf("\n------------MENU------------\n1. Mostrar elementos.\n4. Salir.\nElige una opcion: ");
		scanf("%d", &op);
		
		switch(op){
			//Para AGREGAR.
		    case 0: {
		    	
		    	FILE *apu=fopen("frecuencias.txt", "r");
				
				if(apu==NULL){
					printf("No se pudo abrir el archivo.");
				}
				//Lee caracter y frecuencia.	
				while(fscanf(apu, " %c %d", &simb, &freq)==2){
					Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
					
					
					
					Monti[size]=nuevo;//Se pone en la raíz si es nuevo el nodo.
					size++;
					
					AcomodaA(Monti,size);		
				}		
			    
			    fclose(apu);
				printf("\nValor raiz actual: %c %d", Monti[0]->C,Monti[0]->freq);
				break;
			}
				//para ELIMINAR.
				case 2: {
					if(size!=0){
						printf("\nQue nodo te gustaria eliminar?(caracter y frecuencia): ");
						scanf(" %c %d", &simb,&freq);
						
						Monti[0]=Monti[size-1]; 
						size--;
						
						printf("\nNodo eliminado.");
						AcomodaB(Monti,size); //reacomoda la freq de prioridad(hacia abajo).
						
						break;	
					}else{
						printf("No hay nada en el arbol.");
						break;
					}
					break;
					
				}
				case 3: {//Leer.
					FILE *apu=fopen("frecuencias.txt", "r");
				if(apu!=NULL){
					while(fscanf(apu, " %c %d", &simb, &freq)==2){
						printf("%c %d\n", simb,freq);					
					}
				    break;
				}else{
					printf("El archivo no existe.");
				}
				fclose(apu);
					break;
				}

		}
	}while(op!=4);
	printf("\nSaliendo......");
	return 0;
}
void AcomodaA(Nodo *Monti[], int size){
	int ant=size-1; //nodo anterior.
	while(ant>0){
		int padre=(ant-1)/2;
		if(Monti[padre]->freq < Monti[ant]->freq){
			
			Nodo *swap=Monti[padre]; //80-82 hacen el swap.
			Monti[padre]=Monti[ant];
			Monti[ant]= swap;
			
			ant=padre; //el padre es la raíz ahora.
		}else{
			break; //Se detiene el proceso.
		}
    }
}
