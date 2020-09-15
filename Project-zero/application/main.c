#include <stdio.h>
#include <stdlib.h>
#include "threadlib-extra.h"

int main(int argc, char* argv[]){
	if(argc <= 1){
		printf("Need Arguments to proceed !\n");
	}	
	if(argc > 1){
		int converted_argv = atoi(argv[1]);
	
		/* Questão 01 */
		//ArraySummation(converted_argv);
	
		/* Questão 02 */
		//ArrayMultiplication(converted_argv);
	
		/* Questão 03 */
		CoreAndThreads(converted_argv);
	}
return(EXIT_SUCCESS);
}
