#include <pthread.h>
#include <stdio.h>

int x = 0;
pthread_mutex_t mutex;	
  
void *PrintHello(void *arg){
    x++;
	pthread_mutex_lock(&mutex);
	 int x = (int) arg;
	
	 printf("%i - Não é mamãe \n ",x);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	pthread_t threadc[200];
	long int arg = 123;
	pthread_mutex_init (&mutex,NULL);
	 for(int i=0;i<200;i++)
	  pthread_create(&threadc[i],NULL,PrintHello,(void *)x);
	 for(int j=0;j<200;j++)
	  pthread_join(threadc[j],NULL);
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
}
