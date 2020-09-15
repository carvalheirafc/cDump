#ifndef __MUTEX_TEST_LIB_H__
#define __MUTEX_TEST_LIB_H__

#define N_THREADS_TEN 10
#define ROWS 100
#define COLUMNS 10
#define BUFFER_SIZE 10

void fillMatrix(int targetMatrix[ROWS][COLUMNS], int number);
void printMatrix(int targetMatrix[ROWS][COLUMNS]);

void *LineSummation(void *id);
void matrixSummationLines();

void *columnSummation(void *id);
void matrixSummationColumns();

void producerConsumerBuffer();

#endif //__MUTEX_TEST_LIB_H__
