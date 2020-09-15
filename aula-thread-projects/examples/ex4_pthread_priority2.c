#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#define NTHREADS 1

void *runner(void *p){
	while(1)
		printf("Esta é a execucao da Thread %d do Processo %d\n", (int)(size_t) p, (int) (size_t)getpid());

	pthread_exit(NULL);
}


int main(int argc, char *argv[]){

	int i, scope, r;
	pthread_t tid[NTHREADS];
	pthread_attr_t attr;
	pid_t pid;
	
	pid = fork();

	if(pid==0){
		pthread_attr_init(&attr);//inicializa a estrutura de atributos
//		r = sched_setscheduler(getpid(), SCHED_OTHER, NULL);//estabelece o escalonamento
	}
	else{
		pthread_attr_init(&attr);//inicializa a estrutura de atributos
//		r = sched_setscheduler(getpid(), SCHED_RR, NULL);//estabelece o escalonamento
	}
	for(i=0;i<NTHREADS;i++)
		pthread_create(&tid[i], &attr, runner, (void*)(size_t)i);

	for(i=0;i<NTHREADS;i++)
		pthread_join(tid[i], NULL);

	pthread_attr_destroy(&attr);//destroi a estrutura de atributos

	return 0;
}
