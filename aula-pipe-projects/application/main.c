#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "pipelib.h"


int main(int argc, char* argv[]){
	int converted_argument_number = 0;

	if(argc <= 1){
		printf("Error, invalids arguments....\n");
		printf("Use like: $./app @any_integer_number \n");
	
	} else if(argc > 0) {
		converted_argument_number = atoi(argv[1]);	
		//summationBetwenPipes(converted_argument_number);
		//communicationPipes(converted_argument_number);	
		nChilds(converted_argument_number);
	}
	
	return(EXIT_SUCCESS);
}
