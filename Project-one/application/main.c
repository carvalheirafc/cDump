#include <stdlib.h>
#include <stdio.h>

#include "semaphores-lib.h"



int main(int argc, char** argv){
if(argc <= 1){
		printf("Need Arguments to proceed !\n");
	}	
	if(argc > 1){
		int converted_argv = atoi(argv[1]);
	
		/* Questão 01 */
		matrixMultiplicationWithTreads(converted_argv);	
		/* Questão 02 */
	
		/* Questão 03 */
	}

	return(EXIT_SUCCESS);
}
