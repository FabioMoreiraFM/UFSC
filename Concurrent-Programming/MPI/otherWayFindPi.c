#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

unsigned int compute_pi(unsigned int);

int main(int argc, char **argv){
  unsigned int pontos = 0;
  double pontos_no_circulo = 0;
  double pontosMPI = 0;
  unsigned int i  = 0;
  int size;
  int rank;
  

  MPI_Status st;
  srand(time(NULL));
  
  if(argc != 2){
    printf("Uso:\n");
    printf("\t%s <numero de pontos a serem sorteados>\n", argv[0]);
    return 1;
  }
  
  pontos = atoi(argv[1]);  
  
  MPI_Init(&argc,&argv);

  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  if (rank == 0) {
    double buffer[size-1];

    for(int i = 1; i < size; i++)  {
      MPI_Recv(&buffer[i-1],1,MPI_DOUBLE,i,0,MPI_COMM_WORLD,&st);
      pontos_no_circulo += buffer[i-1];
    }
    
    double total = pontos_no_circulo/(pontos*(size-1))*4;

    printf("Pi = %.040f\n", total);

  } else {
    pontosMPI = compute_pi(pontos);
    MPI_Send(&pontosMPI,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
  }

  MPI_Finalize();

  return 0;
}

unsigned int compute_pi(unsigned int pontos){
  unsigned int i;
  unsigned int pontos_no_circulo;
  double x, y;

  pontos_no_circulo = 0;
  
  for(i=0; i<pontos; i++) {
    x = (double)rand()/(double)(RAND_MAX);
    y = (double)rand()/(double)(RAND_MAX);      

    if( (x*x + y*y) < 1 ){
      pontos_no_circulo++;
    }      
  }
  
  return pontos_no_circulo;
}
