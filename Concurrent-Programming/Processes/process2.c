#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t filho1 = fork();
	int son1 = getpid();
	if(filho1 == 0){ //filho
		printf("Filho 1 - %d , Meu pai é %d \n", son1, getppid());
		pid_t filho3 = fork();
	   int son3 = getpid();
	   if(filho3 == 0){
	   	printf("Filho 3 - %d , Meu pai é %d \n", son3, getppid());
	   }else{
	   	pid_t filho4 = fork();
	   	int son4 = getpid();
	   	if(filho4 == 0)
	   	 printf("Filho 4 - %d , Meu pai é %d \n", son4, getppid());
	   	wait(NULL);
	   }
	}else{
		pid_t filho2 = fork();
		int son2 = getpid();
		wait(NULL);
		if(filho2 == 0){
			printf("Filho 2 - %d , Meu pai é %d \n", son2, getppid());
			pid_t filho5 = fork();
	   	int son5 = getpid();
	   	if(filho5 == 0){
	   	 printf("Filho 5 - %d , Meu pai é %d \n", son5, getppid());
	   	}else{
	   		pid_t filho6 = fork();
	   		int son6 = getpid();
	   		if(filho6 == 0)
	   		 printf("Filho 6 - %d , Meu pai é %d \n", son6, getppid());
	   		wait(NULL);
	   	}	
		}
	}
}
