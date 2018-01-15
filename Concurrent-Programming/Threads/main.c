#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

sem_t semaphore;
sem_t teste;

int protected_var = 0;

int shared_var = 0;

int threads_num = 100;

int iterations = 512; 

void *func_thread(void *arg) {
	for (int k = 0; k < iterations; ++k)
		++shared_var;
	sem_wait(&semaphore);
	   sem_wait(&teste);
		for (int i = 0; i < iterations; ++i)
  			++protected_var;
  		sem_post(&teste);
	sem_post(&semaphore);	
	return 0;
}

int main (int argc, char **argv) {
	sem_init(&semaphore,0,50);
	sem_init(&teste,0,1);
	 pthread_t thread[threads_num];
	 for (int i = 0; i < threads_num; i++)
	  pthread_create(&thread[i],NULL, func_thread, NULL);
	 for (int i = 0; i < threads_num; i++)
	  pthread_join(thread[i],NULL);
	 printf("Shared %d -- Protected %d \n",shared_var, protected_var);
	sem_destroy(&teste);
	sem_destroy(&semaphore);
	pthread_exit(NULL);
	return 0;
}

