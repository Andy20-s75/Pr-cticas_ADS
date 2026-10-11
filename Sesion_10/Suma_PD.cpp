//Sesión 10. Diferentes formas de sumar un número.
#include<stdio.h>
int Suma_PD(int n);
int main(){
	int n, formas;
	
	printf("Ingrese un numero entero: ");
	scanf("%d", &n);
	
	formas= Suma_PD(n);
	printf("Hay %d formas diferentes de sumar %d", formas, n);
	
	return 0;
}
int Suma_PD(int n){
	int F[n+1];
	//Caso base:
	F[0]=1;
	
	if(n>0){
		for(int i=1; i<=n;i++){
			F[i]=0;
			if(i-1>=0){
				F[i]+=F[i-1];
			}					
			if(i-3>=0){
				F[i]+=F[i-3];
			}
			if(i-4>=0){
				F[i]+=F[i-4];
			}
        }
	}
	
	return F[n];	
}
