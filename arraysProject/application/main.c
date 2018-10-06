#include <stdlib.h>
#include <stdio.h>

#include "n-arrays-lib.h"

int **dinamic_matrix_test;
int main(int argc, char **argv){
    if(argc <= 1){
        printf("Need Arguments to proceed !\n");
    }
    if(argc > 1){
        int row_size = atoi(argv[1]);
        int column_size = atoi(argv[2]);

    dinamic_matrix_test = allocate_memory(dinamic_matrix_test, row_size, column_size);
    dinamic_matrix_test = initialize_values(dinamic_matrix_test, row_size, column_size, -1);

    print_array(dinamic_matrix_test, row_size, column_size);
    free_allocated_memory(dinamic_matrix_test, row_size, column_size);
    }

    return (EXIT_SUCCESS);
}
