#define _GNU_SOURCE

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>


#include "threadlib-extra.h"


int *array_one, *array_two;
int *array_result;
int size = 0;

// Questão 01
//
//
void *SummationProccess(void* tid){
	int pos = (size_t)tid;
	array_result[pos] = array_one[pos] + array_two[pos];
	printf("Thread_id [%lu], Array-Result[%d] \n", (pthread_t)tid, array_result[pos]);
	pthread_exit(0);	
}


void ArraySummation(int array_size){
	pthread_t *threads;
	array_one = (int *) malloc(array_size * sizeof(int));
	array_two = (int *) malloc(array_size * sizeof(int));
	array_result = (int *) malloc(array_size * sizeof(int));
	threads = (pthread_t *) malloc(array_size * sizeof(pthread_t));
	
	int i;
	
	srand(time(NULL));
	for(i = 0; i<array_size; i++){
		array_one[i] = rand()%100;
		array_two[i] = rand()%100;
	}	
	
	for(i = 0; i < array_size; i++){
		pthread_create(&threads[i], NULL, SummationProccess, (void*) (size_t)i);
		pthread_join(threads[i], 0);
	}

}

// Questão 02
//
//
void *MultiProccess(void *tid){
	int pos = (size_t)tid * 2;
	
	array_two[pos] = array_one[pos] * array_one[pos+1];
	printf("Thread_id [%lu], Array-Result[%d] \n", (pthread_t)tid, array_two[pos]);
	pthread_exit(0);
}
  
void ArrayMultiplication(int array_size){
	pthread_t *threads;
	array_one = (int *) malloc(array_size * sizeof(int));
	array_two = (int *) malloc((array_size/2) * sizeof(int));
	threads = (pthread_t *) malloc((array_size/2) * sizeof(pthread_t));
	
	int i;
	srand(time(NULL));
	for(i = 0; i<array_size; i++){
		array_one[i] = rand()%100;
	}
	
	for(i = 0; i < (array_size/2); i++){
		pthread_create(&threads[i], NULL, MultiProccess, (void*) (size_t)i);
		pthread_join(threads[i], 0);
	}
}

// Questão 03
//
//
//
cpu_set_t cpu_set;
pthread_attr_t threads_attr;
int iterator;
int NPROC;

void *runner(void *tid){
	int processor_number;
	cpu_set_t temp_set;
	CPU_ZERO(&temp_set);
	CPU_SET(iterator % NPROC, &temp_set);

	processor_number = sched_setaffinity(0, sizeof(cpu_set_t), &temp_set);
	
	int pos = (size_t)tid * 2;
	
	array_two[pos] = array_one[pos] * array_one[pos+1];
	printf("Thread_id [%lu], in CPU [%d], Array-Result[%d] \n", (pthread_t)tid, sched_getcpu(),
					array_two[pos]);
	
	pthread_exit(NULL);
}

int CoreAndThreads(int array_size){

	pthread_t *threads;

	NPROC = sysconf(_SC_NPROCESSORS_ONLN);
	
	array_one = (int *) malloc(array_size * sizeof(int));
	array_two = (int *) malloc((array_size/2) * sizeof(int));
	threads = (pthread_t *) malloc((array_size/2) * sizeof(pthread_t));
	
	pthread_attr_init(&threads_attr);

	printf("Procesors [%d]\n", NPROC);
	
	int i;
	srand(time(NULL));
	for(i = 0; i<array_size; i++){
		array_one[i] = rand()%100;
	}
	
	for(iterator = 0; iterator < (array_size/2); iterator++){
		pthread_create(&threads[iterator], &threads_attr, runner, (void*)(size_t) iterator);		
		pthread_join(threads[iterator], 0);
	}
	pthread_attr_destroy(&threads_attr);
	
	return 0;
}

