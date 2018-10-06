#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "n-arrays-lib.h"





int** allocate_memory(int **matrix_to_alocate, int row_size, int column_size){
    matrix_to_alocate = malloc(row_size * sizeof(int*));
    for(int i = 0; i < row_size; i++){
        matrix_to_alocate[i] = malloc(column_size * sizeof(int));
    }
    return matrix_to_alocate;
}

void free_allocated_memory(int **matrix_to_free, int row_size, int column_size){
    for(int i = 0; i < row_size; i++){
        free(matrix_to_free[i]);
    }
    free(matrix_to_free);
}

int** initialize_values(int **matrix_to_initialize,
    int row_size, int column_size, int standard_value){
        if(standard_value == -1){
            srand(time(NULL));
            for(int i = 0; i < row_size; i++){
                for(int j = 0; j < column_size; j++){
                    matrix_to_initialize[i][j] = rand() % 1000;
                }
            }
        }else{
            for(int i = 0; i < row_size; i++){
                for(int j = 0; j < column_size; j++){
                    matrix_to_initialize[i][j] = standard_value;
                }
            }
        }
    return matrix_to_initialize;
}

void print_array(int **matrix_to_print, int row_size, int column_size){
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < column_size; j++){
            if(j % row_size ==  0)
                printf("%d", matrix_to_print[i][j]);
            else
                printf("\t%d ", matrix_to_print[i][j]);
        }
        printf("\n");
    }
}
