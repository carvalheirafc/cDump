#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "threadlib.h"

int status, iterator, total_summation = 0;
int controller = THREAD_WAIT;
int last_thread_flag = 0;
pthread_t *threads;


void *Summation(void* thread_id){
	if(iterator == 1)
		sleep(1000);
	printf("This is the Beggining of Thread [%lu], Summation [%d]\n",
			(pthread_t)thread_id, total_summation);
	total_summation = total_summation + iterator;
	printf("This is the End of Thread [%lu], Summation [%d]\n",
			(pthread_t)thread_id, total_summation);
	pthread_exit(0);
}

int SummationBetweenThreads(int number_of_threads){

	threads = (pthread_t *) malloc(number_of_threads * sizeof(pthread_t));
	total_summation = number_of_threads;

	for(iterator = 1; iterator < number_of_threads; iterator++){
		printf("Main Process Creating Thread [%d]\n", iterator);
		if(iterator == number_of_threads - 1)
			last_thread_flag = 1;
		status = pthread_create(&threads[iterator], NULL, Summation,
			(void*)(size_t) iterator);

		if(status != 0){
			printf("Creation of Thread Error[%d] \n", status);
			return -1;
		}
		pthread_join(threads[iterator], 0);
	}
	return 0;
}

/** Using Mutex */
pthread_mutex_t mutex_controller;
pthread_cond_t thread_busy;

void *SummationWithMutex(void *thread_id){
	pthread_mutex_lock(&mutex_controller);
	total_summation = total_summation + iterator;
	printf("This is the End of Thread [%lu], Summation [%d]\n",
		(pthread_t)thread_id, total_summation);

	pthread_cond_signal(&thread_busy);
	pthread_mutex_unlock(&mutex_controller);
	pthread_exit(0);

}


int SummationBetweenThreadsWithMutex(int number_of_threads){
	threads = (pthread_t *) malloc(number_of_threads * sizeof(pthread_t));


	pthread_mutex_init(&mutex_controller, NULL);
	pthread_cond_init(&thread_busy, NULL);

	total_summation = number_of_threads;
	for(iterator = 1; iterator < number_of_threads; iterator++){
		pthread_create(&threads[iterator], NULL, SummationWithMutex, (void*)(size_t) iterator);
		pthread_join(threads[iterator], 0);
	}
	pthread_cond_destroy(&thread_busy);
	pthread_mutex_destroy(&mutex_controller);

	return 0;
}



pthread_mutex_t mutex_driver;
int buffer_iterator = 0;
int producer_iterator = 0;
int consumer_iterator = 0;
int buffer[BUFFER_SIZE] = {11, 22, 33 ,44 , 55, 66, 77, 88, 99, 10};

void *producer(int *buffer){
	int count = 0;
	
	pthread_mutex_lock(&mutex_driver);
	while(count < BUFFER_SAFRA){
		while(producer_iterator < BUFFER_SIZE){
			if(count == BUFFER_SAFRA){
				printf("Producer Exiting...\n");
				break;
			}
			buffer[producer_iterator] = 1;
			printf("Producer-Writing in buffer[%d]: %d\n", producer_iterator, buffer[producer_iterator]);
			producer_iterator++;
			count++;
		}
	pthread_mutex_unlock(&mutex_driver);
	pthread_exit(0);
	}
}

void *consumer(int *buffer){
	pthread_mutex_lock(&mutex_driver);

	int count = 0;
	while(count < BUFFER_SAFRA){
		while(consumer_iterator < BUFFER_SIZE){
			if(count == BUFFER_SAFRA){
				printf("Consumer Exiting \n");
				break;
			}
			printf("Consumer-Read buffer[%d]: %d\n", consumer_iterator, buffer[consumer_iterator]);
			count++;
			consumer_iterator++;
		}

	pthread_mutex_unlock(&mutex_driver);
	pthread_exit(0);
	}
}

void ProductionConsumerThreads(){
	pthread_t producer_thread, consumer_thread;

	pthread_mutex_init(&mutex_driver, 0);
	int index;
	for(index = 0; index < BUFFER_SIZE; index++){
		pthread_create(&producer_thread, NULL, (void *) producer , buffer);
		pthread_create(&consumer_thread, NULL, (void *) consumer , buffer);
		pthread_join(producer_thread, 0);
		pthread_join(consumer_thread, 0);
	}
	pthread_mutex_destroy(&mutex_driver);
}
