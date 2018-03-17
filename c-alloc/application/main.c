#include <stdio.h>
#include "array_alloc.h"


int main(int argc, char *argv[]){
	char *file_path;
	Vector v;
	if (argc >= 1){	
		v.file_path = argv[1];
		printf("File: %s", v.file_path);	
	}	
	
	//int col = 	checkColSize(v);	
	dinamic_Vector(v);	
	//printVector(v);	
	printf(" %s \n", v.vector);
	
	return EXIT_SUCCESS;
}
