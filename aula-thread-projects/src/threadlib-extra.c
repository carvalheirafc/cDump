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
/*
int CoreAndThreads(int number_of_threads){

	int NPROC, status, iterator;
	pthread_t *threads;
	pthread_attr_t first_attr, last_attr;
	cpu_set_t cpu_set_first, cpu_set_last;

	
	CPU_ZERO(&cpu_set_first);
	CPU_ZERO(&cpu_set_last);
	NPROC = sysconf(_SC_NPROCESSORS_ONLN);
	threads = (pthread_t *) malloc(number_of_threads * sizeof(pthread_t));
	pthread_attr_init(&first_attr);
	pthread_attr_init(&last_attr);

	printf("Procesors [%d]\n", NPROC);
	
	int index;
	for(index = 0; index < NPROC; index++){
		if(index < NPROC / 2){
			CPU_SET(index, &cpu_set_first);
		}else{
			CPU_SET(index, &cpu_set_last);
		}
	}
	
	pthread_attr_setaffinity_np(&first_attr, sizeof(cpu_set_t), &cpu_set_first);
	pthread_attr_setaffinity_np(&last_attr, sizeof(cpu_set_t), &cpu_set_last);


	for(index = 0; index < number_of_threads; index++){
		if(index % 2 == 0){
			pthread_create(&threads[index], &first_attr, counter,
				(void*)(size_t) index);
		}else{
			pthread_create(&threads[index], &last_attr, counter,
					(void*)(size_t) index);
		}

	pthread_join(threads[index], NULL);
	}

	pthread_attr_destroy(&first_attr);
	pthread_attr_destroy(&last_attr);

	return 0;
}
*/
