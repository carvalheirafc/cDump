#define _GNU_SOURCE

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

#include "scopethreadlib.h"


void *counter(void *thread_arg){
	int i;
	for(i = 0; i < 1000; i++){
		//THIS IS A USELESS FOR
		//THIS IS A USELESS COMMENT
	}
	printf("End of Wait [%d]\n", i);
	printf("This is the End of Thread [%lu] in CPU [%d]\n",
		(pthread_t)thread_arg, sched_getcpu());
	pthread_exit(0);

}

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
