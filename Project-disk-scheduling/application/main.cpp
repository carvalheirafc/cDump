#include <iostream>
#include <string>

#include "scheduling_algorithms.h"

int main (int argc, char **argv){

	if(argc > 1){
		SchedulingAlgorithms<int> sched(argv[1]);
	
	
		std::cout<<"FCFS: "<<std::endl;	
		sched.firstComeFirstServed();
		std::cout<<sched;	

		std::cout<<"SSTF: "<<std::endl;
		sched.shortestSeekTimeFirst();
		std::cout<<sched;

		std::cout<<"SCAN: "<<std::endl;
		sched.scan();
		std::cout<<sched;

		std::cout<<"SCAN DOWN: "<<std::endl;
		sched.scanDown();
		std::cout<<sched;


	}
	return EXIT_SUCCESS;
}
