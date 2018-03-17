#include <stdio.h>
#include <stdlib.h>
#include "array_alloc.h"


int checkColSize(Vector obj){
	int sl = 0;
	char *buffer;
	obj.file_stream = fopen(obj.file_path, "r");
	printf("Buffer: ");	
	if(obj.file_stream){	
		while(fscanf(obj.file_stream, " %[^\n] ", buffer) != EOF)
			sl ++;
	}	
	printf("sl %d", sl);
	fclose(obj.file_stream);	
	return sl;
}

int checkLineSize(Vector obj){
	int sl = 0;
	char buffer[99];
	
	obj.file_stream = fopen(obj.file_path, "r");
	printf("Buffer: ");	
	if(obj.file_stream){	
		for(size_t ii = 0; ii < 6; ii++)
			fscanf(obj.file_stream, " %s ", buffer); 
	}	
	printf("sl %s", buffer);
	fclose(obj.file_stream);	
	return sl;
}


void dinamic_Vector(Vector obj){
	char *buffer;
	obj.vector = (char*) calloc (MAX, sizeof(char));
	if(obj.vector == NULL){
		printf("Bad Allocator ! \n");
		exit (1);
	}
	obj.file_stream = fopen(obj.file_path, "r");
	if(!obj.file_stream){
		printf("Erro ao abrir arquivo: %s \n", obj.file_path);
	}
	
			fscanf(obj.file_stream," %s ", obj.vector);	
}

void printVector(Vector obj){
	for(size_t it = 0; it < MAX; it++){
		printf(" %c ", obj.vector[it]);
	}

}
