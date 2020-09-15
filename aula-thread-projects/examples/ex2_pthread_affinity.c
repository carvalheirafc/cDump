#define _GNU_SOURCE
#include <sched.h>
//#include <utmpx.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *runner(void *p){
//	while(1)
		printf("Esta é a execucao da Thread %d na CPU=%d\n", (int)(size_t) p, sched_getcpu());

	pthread_exit(NULL);
}
int main(int argc, char *argv[]){

	int i, NPROC, NTHREADS;
	NTHREADS=atoi(argv[1]);
	pthread_t tid[NTHREADS];

	pthread_attr_t attr; //variavel que contem os atributos que vamos utilizar
	cpu_set_t cpu_set; //conjunto das cpus (cores) que vamos utilizar
	CPU_ZERO(&cpu_set);//Apos a execucao dessa instrucao, o conjunto sera vazio

	NPROC = sysconf(_SC_NPROCESSORS_ONLN);//OBTEM O NUMERO DE CORES DO SISTEMA

	printf("Numero de cores:%d\n", NPROC);

	pthread_attr_init(&attr);//inicializa a estrutura dos atributos

	CPU_SET(0, &cpu_set);//adiciona uma CPU ao conjuntp
	CPU_SET(1, &cpu_set);
	CPU_SET(2, &cpu_set);
	CPU_SET(3, &cpu_set);

	pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpu_set);//estabelece a afinidade

	for(i=0;i<NTHREADS;i++)
		pthread_create(&tid[i], &attr, runner, (void*)(size_t)i);

	for(i=0;i<NTHREADS;i++)
		pthread_join(tid[i], NULL);

	pthread_attr_destroy(&attr);//destroy a estrutura de atributos

	return 0;
}
