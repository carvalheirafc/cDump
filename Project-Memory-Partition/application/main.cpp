#include <iostream>

#include "memory_simullator.h"

int print_menu(){
	int choice;
	std::cout<<"(1) Insert(FF)"<<std::endl;
	std::cout<<"(2) Remove"<<std::endl;
	std::cout<<"(3) Print Memory"<<std::endl;
	std::cout<<"(-1) Exit"<<std::endl;
	std::cin>>choice;
	return choice;
}


int main (int argc, char **argv){
    bool run = true;
		int menu_choice;
		int memory_size;

		std::cout<<"Memory Size: ";
		std::cin>>memory_size;
		Memory_Simullator<int> memoryL1(memory_size);
    
		
		while(run){
			menu_choice = print_menu();
			
			if(menu_choice == 1){
				std::string pid;
				int size;
				int method;

				std::cout<<"Pid: ";
				std::cin>>pid;
				
				std::cout<<"Size: ";
				std::cin>>size;
				
				std::cout<<"(1) First Fit: ";
				std::cin>>method;

				memoryL1.insert(pid, size, method);
			}
			
			if(menu_choice == 2){
				std::string pid;
				std::cout<<"Pid Name: ";
				std::cin>>pid;
				
				memoryL1.remove(pid);
			}
			
			if(menu_choice == 3){
				
				std::cout<<memoryL1;
			}
			
			if(menu_choice == -1){
				
				run = false;
				break;
			}
			
		}

    return EXIT_SUCCESS;
}
