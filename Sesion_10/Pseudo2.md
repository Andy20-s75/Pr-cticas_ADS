***Input:*** int n

***Output:*** int F

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_



**Suma\_PD(int n)**

***int F\[] ->*** *//Se guradan las diferentes formas*



**//Caso base**

F\[0]=1



if(n>0) then

  for  i=1; to n do



      F\[i]=0 -> inicializamos

      if  i-1 >= 0 then

         F\[i]= F\[i]+F\[i-1];

      endif

 

      if  i-3 >= 0 then

          F\[i]= F\[i] + F\[i-3];

      endif

 

      if  i-4  >= 0 then

          F\[i]= F\[i] + F\[i-3];

      endif



   endfor

endif

  return F\[n];

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Esto tiene complejidad de O(n)

