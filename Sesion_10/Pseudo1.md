**Input:** int n

**Output**: int F->Formas en las que se puede sumar esa n

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

***Suma\_R(int n):***

**//Caso base:**

if(n==0) return *1*; ->suma cero, solo *una* forma posible

if(n<0) return 0; -> No es posible



if(n>0) then

 

***Formas***= Suma\_R(n-1)+Suma\_R(n-3)+Suma(n-4)



Como es recursivo va a depender de n, entonces su complejidad es de **O(n)**

**\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_**



