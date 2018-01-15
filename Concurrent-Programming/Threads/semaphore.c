#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define MAX_THREAD 8

pthread_mutex_t prod;
pthread_mutex_t cons;

int buffer[20];
int i,f;
int produzir = 10;
int consumir = 10;
sem_t cheio;
sem_t vazio;



int produz() {
	int x = rand() % 100;
	printf("Valor Produzido: %d \n", x);
	return x;
}

void consome(int consumido) {
	printf("Valor Consumido: %d \n", consumido);
}

void *produtor(void *arg) {
	while (produzir > 0) {
		sem_wait(&cheio);
		pthread_mutex_lock(&prod);
		  // if colocado estrategicamente pq podem entrar threads excedentes
		  // dentro do semáforo o que fará com que ele
		  // produza mais que o permitido.
		  if (produzir > 0) { 
		    f = (f + 1 ) % 20;
		    buffer[f] = produz();
		  }
		  produzir--;
	    pthread_mutex_unlock(&prod);
		sem_post(&vazio);
	}
}

void *consumidor(void *arg) {
	while (consumir > 0) {
		sem_wait(&vazio);
		pthread_mutex_lock(&cons);
		  // mesma lógica aqui
		  if (consumir > 0) {
		    i = (i + 1) % 20;
		    consome(buffer[i]);
		    consumir--;
		  }
		pthread_mutex_unlock(&cons);
		sem_post(&cheio);
		
	}
}

int main() {
	pthread_t thread[MAX_THREAD];
	
	sem_init(&cheio,0,4);
	sem_init(&vazio,0,0);	

	pthread_mutex_init(&prod,NULL);
	pthread_mutex_init(&cons,NULL);
	for (int i = 0; i < MAX_THREAD/2; ++i)
	{
		pthread_create(&thread[i],NULL,produtor,NULL);
	}
	
	for (int i = MAX_THREAD/2; i < MAX_THREAD; ++i)
	{
		pthread_create(&thread[i],NULL,consumidor,NULL);
	}

	for (int i = 0; i < MAX_THREAD; ++i)
	{
		pthread_join(thread[i],NULL);
	}

	pthread_mutex_destroy(&prod);
	pthread_mutex_destroy(&cons);
	sem_destroy(&vazio);
	sem_destroy(&cheio);

	return 0;
}