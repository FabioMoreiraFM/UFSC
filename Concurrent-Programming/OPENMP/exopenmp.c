#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define NRA 8                 /* number of rows in matrix A */
#define NCA 8                 /* number of columns in matrix A */
#define NCB 8                 /* number of columns in matrix B */

int main (int argc, char *argv[])
{
  omp_set_num_threads(3);
  int i, j, k;

  /* matrix A to be multiplied */
  double **a = (double **) malloc(sizeof(double *) * NRA);
  #pragma omp parallel for schedule(static) shared(a)
  for (i = 0; i < NRA; i ++)
    a[i] = (double *) malloc(sizeof(double) * NCA);

  /* matrix B to be multiplied */
  double **b = (double **) malloc(sizeof(double *) * NCA);
  #pragma omp parallel for schedule(static) shared(b)
  for (i = 0; i < NCA; i ++)
    b[i] = (double *) malloc(sizeof(double) * NCB);

  /* result matrix C */
  double **c = (double **) malloc(sizeof(double *) * NRA);
  #pragma omp parallel for schedule(static) shared(c)
  for (i = 0; i < NRA; i ++)
    c[i] = (double *) malloc(sizeof(double) * NCB);

  printf("Initializing matrices...\n");

  /*** Initialize matrices ***/
  for (i=0; i<NRA; i++)
    #pragma omp parallel for schedule(static) shared(a)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;

  for (i=0; i<NCA; i++)
    #pragma omp parallel for schedule(static) shared(b)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;

  for (i=0; i<NRA; i++)
    #pragma omp parallel for schedule(static) shared(c)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;

  /*** Do the matrix-matrix multiplication ***/
  double e;
  for (i=0; i<NRA; i++)
    for(j=0; j<NCB; j++) {
      e = c[i][j];
      #pragma omp parallel for schedule(static) shared(a,b) reduction(+:e)
      for (k=0; k<NCA; k++)
	e += a[i][k] * b[k][j];
      c[i][j] = e;
    }

  /*** Print results ***/
  printf("******************************************************\n");
  printf("Result Matrix:\n");
  for (i=0; i<NRA; i++)
  {
    for (j=0; j<NCB; j++)
      printf("%10.2f  ", c[i][j]);
    printf("\n");
  }
  printf("******************************************************\n");
  printf ("Done.\n");

  for (i = 0; i < NRA; i ++)
    free(a[i]);
  free(a);

  for (i = 0; i < NCA; i ++)
    free(b[i]);
  free(b);

  for (i = 0; i < NRA; i ++)
    free(c[i]);
  free(c);

  return 0;
}

