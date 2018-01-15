#include <stdio.h>
#include <omp.h>

int main() {
  int x = 0;
  int a = 0;
  int b = 0;

  omp_set_num_threads(3); // modificar nº de threads executando

  #pragma omp parallel reduction(+:a) //iniciar programação paralela
  {
   // pegando o nº de threads e imprimindo na tela.
   #pragma omp single
   {
   x = omp_get_num_threads(); // pega nº threads
   printf("Hello World ----- %d \n",x);
   }
   
   //utilizando reduction
   a = a + 2;

    // utilizando for e só uma thread faz o for
    #pragma omp parallel for schedule(static, 5) reduction(+:b)
    for (int i = 0; i < 20; ++i)
     b += 1;

    //só uma thread imprime
 	  #pragma omp single
     printf("Valor de b : %d \n", b);
  }

  printf("Valor de a: %d\n",a); // imprime valor total de a após calculado no omp parallel
  printf("\n ------------------------ \n");

  omp_set_num_threads(380);
  int t = 0,s = 0;
  #pragma omp parallel shared(t,s)
  {	
  	t++;
  	#pragma omp critical
  	s++;
  }
  printf("Valor de T: %d ---  Valor de S: %d \n",t,s);

}
