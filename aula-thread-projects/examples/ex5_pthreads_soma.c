#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NTHREADS 5

//pthread_t threads[NTHREADS];
pthread_t *threads;
int status, i;
void *thread_return;

int soma = 0;
int total = 0;


void* hello_world(void *tid){

	printf("Este é o INICIO da Thread %d. Soma=%d\n", (int)tid, total);
	soma = soma + 1;		
	total += soma;
	printf("Este é o FIM da Thread %d. Soma=%d\n", (int)tid, total);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){

	int size = atoi(argv[1]);
	threads = malloc(sizeof(pthread_t) * size);
		   	
	for(i=0; i<size; i++){
		printf("Processo principal criando thread #%d\n", i);
		status = pthread_create(&threads[i], NULL, hello_world, (void *)(size_t) i);

		if(status!=0){
			printf("Erro na criação da thread. Codigo de Erro:%d\n", status);
			return 1;
		}
	}
	
	//for(i=0; i<NTHREADS; i++){
	for(i=0; i<size; i++){
		printf("Esperando Thread %d finalizar....\n", i);
		pthread_join(threads[i], &thread_return);
		printf("Thread %d finalizada\n", i);
	}
	//printf("processo pai vai finalizar e o valor final de soma = %d\n", soma);
	printf("processo pai vai finalizar e o valor final de soma = %d\n", total);

	return 0;
}
