#ifndef __THREADLIB_H__
#define __THREADLIB_H__

#define THREADS_NUMBER 2
#define MAX_PRODUCTION 5
#define THREAD_WAIT 0
#define THREAD_RUN 1
#define BUFFER_SIZE 10
#define BUFFER_SAFRA 3


void *Summation(void* thread_id);
int SummationBetweenThreads(int number_of_threads);

void *SummationWithMutex(void *thread_id);
int SummationBetweenThreadsWithMutex(int converted_argv);

void *producer(int *buffer);
void *consumer(int *buffer);
void ProductionConsumerThreads();


#endif //__THREADLIB_H__
