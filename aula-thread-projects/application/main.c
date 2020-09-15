#include <stdio.h>
#include <stdlib.h>
#include "threadlib.h"
#include "threadlib-extra.h"
#include "scopethreadlib.h"

int main(int argc, char* argv[]){
	int converted_argv = atoi(argv[1]);
    
	
	ArrayMultiplication(converted_argv);
	//ArraySummation(converted_argv);
	//CoreAndThreads(converted_argv);
	//SummationBetweenThreadsWithMutex(converted_argv);
	//SummationBetweenThreads(converted_argv);
	//ProductionConsumerThreads();

return(EXIT_SUCCESS);
}
