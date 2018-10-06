#ifndef __N_ARRAYS_LIB_H__
#define __N_ARRAYS_LIB_H__

int** allocate_memory(int **matrix_to_alocate, int row_size, int column_size);
void free_allocated_memory(int **matrix_to_free, int row_size, int column_size);

int** initialize_values(int **matrix_to_initialize,
    int row_size, int column_size, int standard_value);

void print_array(int **matrix_to_print, int row_size, int column_size);



//Later Code
/*
struct genericType{
    enum {
        typeUndefined,
        typeInterger,
        typeUnsigned,
        typeString,
        typeFloat,
    } Type
    union{
        int integer;
        unsigned usignedint;
        char* string;
        long longer;
    }value;
};*/

#endif // __N_ARRAYS_LIB_H__
