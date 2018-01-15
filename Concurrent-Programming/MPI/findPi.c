#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

unsigned int compute_pi(unsigned int, unsigned int);

int main(int argc, char **argv){
  
  int rank, size;
  MPI_Status st;  

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  if(argc != 2){
    printf("Uso:\n");
    printf("\t%s <numero de pontos a serem sorteados>\n", argv[0]);
    return 1;
  }

  unsigned int pontos;
  unsigned int pontos_no_circulo;
  
  pontos = atoi(argv[1]);

  pontos_no_circulo = 0;
  unsigned int seed = rank;
  double x, y;
  srand(seed);
  int i;
  for (i = 0; i < pontos; i = i + 1) {
    x = (double)rand()/(double)(RAND_MAX);
    y = (double)rand()/(double)(RAND_MAX);
    if( (x*x + y*y) < 1 ){
      pontos_no_circulo++;
    }
  }

  if (rank == 0) {
    for (i = 1; i < size; i = i + 1) {
      int buffer[2];
      MPI_Recv(&buffer, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
      pontos_no_circulo += buffer[0];
      printf("%d\n", pontos_no_circulo);
    }
    pontos = pontos * size;
    printf("Pi = %.040f\n", ((double)pontos_no_circulo/(double)pontos)*4);
  } else {
    int buffer[1];
    buffer[0] = pontos_no_circulo;
    MPI_Send(buffer, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}
