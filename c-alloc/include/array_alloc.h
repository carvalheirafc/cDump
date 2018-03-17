#ifndef __ARRAY_ALLOC_H__
#define __ARRAY_ALLOC_H__

#define EXIT_SUCCESS 0
#define MAX 8

typedef struct{
	//Atributes
	int size_line;
	FILE *file_stream;
	char *file_path;
	char *vector;
	
	//Methods
	void (*allocator)(FILE, char *);
}Vector;


int checkLineSize(Vector);
int checkColSize(Vector);
void dinamic_Vector(Vector);
void printVector(Vector);

#endif // __ARRAY_ALLOC_H__
