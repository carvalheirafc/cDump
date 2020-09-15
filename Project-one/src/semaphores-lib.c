#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "semaphores-lib.h"





// Global Variables Declarations 


int **matrix_one, **matrix_two;
int **matrix_result;


void fillMatrix(int** targetMatrix, int number, int matrix_size){ 
	int ROWS = matrix_size;
	int COLUMNS = matrix_size;
	if(number == -1){
		srand(time(NULL));
		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLUMNS; j++){
				targetMatrix[i][j] = rand();		
			
			}
		}
	}
	
	
	else{
		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLUMNS; j++){
				targetMatrix[i][j] = number;		
			}
		}
	}
}

void matrixAlloc(int** matrix_to_alloc, int size){
	matrix_to_alloc = (int **) malloc(size * sizeof(int*));
	matrix_to_alloc[0] = (int *) malloc(size * sizeof(int));
}

void matrixMultiplicationWithTreads(int matrix_size){
	
	pthread_t *threads;
	
	
	matrixAlloc(matrix_one, matrix_size);
	matrixAlloc(matrix_two, matrix_size);
	matrixAlloc(matrix_result, matrix_size);
	threads = (pthread_t *) malloc(matrix_size * sizeof(pthread_t));
	
	fillMatrix(matrix_one, 2, matrix_size);
	//fillMatrix(matrix_two, 3, matrix_size);

	/*
	for(int i = 0; i < matrix_size; i++){
		//pthread_create(&threads[i], NULL, SummationProccess, (void*) (size_t)i);
		pthread_join(threads[i], 0);
	}*/

}
