#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NTHREADS 5

pid_t pid;

void* hello_world(void *tid){
	printf("Hello World. Esta é a Thread %d\n", (int)tid);
	sleep(((int)tid+1)*2);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){

	pthread_t threads[NTHREADS];
	int status, i, retorno;
	void *thread_return;

	pid = fork();
	for(i=0; i<NTHREADS; i++){
		printf("Processo [%d] criando thread #%d\n", getpid(), i);
		status = pthread_create(&threads[i], NULL, hello_world, (void *)(size_t) i);

		if(status!=0){
			printf("Erro na criação da thread. Codigo de Erro:%d\n", status);
			return 1;
		}
	}

	
	for(i=0; i<NTHREADS; i++){
		printf("Processo[%d]: Esperando Thread %d finalizar....\n", getpid(), i);
		retorno = pthread_join(threads[i], &thread_return);
		printf("Processo[%d]: Thread %d finalizada. Retorno=%d\n", getpid(), i, retorno);
	}
	printf("processo [%d] vai finalizar\n", getpid());

	return 0;
}
