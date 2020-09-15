#ifndef __FORKLIB_H__
#define __FORKLIB_H__

#define BUFFER 1024
#define ONE_SECCOND 1
#define TWO_SECCOND 2
#define EXIT_PARENT 0
#define EXIT_CHILD 1

void forkTest(char* str);
void getPID();
void setFork();
void forkTree(int cont);
void implementacao_filho2(int *a);
void implementacao_filho1(int *a);
void sharedMemory();




#endif // __FORKLIB_H__
