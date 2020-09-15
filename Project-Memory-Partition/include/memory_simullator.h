#ifndef __MEMORY_SIMULLATOR_H__
#define __MEMORY_SIMULLATOR_H__

#include <string>
#include <list>
#include <iostream>

#include "memory_inteval.h"

template <class T>
class Memory_Simullator {
	private:
		std::list<Memory_Interval> memoryList;
		int memory_size;
	public:
		Memory_Simullator(T memory_size){
			Memory_Interval init_memory("Free", 0, memory_size);
			memoryList.push_back(init_memory);
			this->memory_size = memory_size;
		}

		void insert(std::string pid, int size, int pattern){
			if(pattern == 1){
				if(!first_fit(pid, size)){
					std::cout<<"ERROR(NOT FOUND SPACE TO INSERT["<<pid<<"]."<<std::endl;
				}

			}
		}


		bool first_fit(std::string pid, int size){
			Memory_Interval new_reserved_space(pid);
			std::list<Memory_Interval>::iterator iterator;
			for(iterator = this->memoryList.begin(); iterator != this->memoryList.end(); iterator++){
				if((*iterator).get_pid().compare("Free") == 0 and 
								size <= (*iterator).get_end() - (*iterator).get_start()){

					if(iterator != this->memoryList.begin()){
						new_reserved_space.set_start((*iterator).get_start() + 1);
					}else{
						new_reserved_space.set_start((*iterator).get_start());
					}
					new_reserved_space.set_end(size);
					(*iterator).set_start(new_reserved_space.get_end());
					
					this->memoryList.insert(iterator, new_reserved_space);
					return true;
				}
			}
			return false;
		}
		
		bool best_fit(std::string pid, int size){
			Memory_Interval new_reserved_space(pid);
			std::list<Memory_Interval>::iterator iterator;
			std::list<Memory_Interval>::iterator best_index;
			int previous_index_size = 0;
			
			for(iterator = this->memoryList.begin(); iterator != this->memoryList.end(); iterator++){
				if((*iterator).get_end() - (*iterator).get_start() <= size){
						previous_index_size = (*iterator).get_end() - (*iterator).get_start();
				
						best_index = iterator;	
				}
			}
			return false;
		}
		void remove(std::string pid){
			if(pid.compare("Free") != 0){
				std::list<Memory_Interval>::iterator iterator;
				for(iterator = this->memoryList.begin(); iterator != this->memoryList.end(); iterator++){
					if((*iterator).get_pid().compare(pid) == 0){
						(*iterator).set_pid("Free");
						compressor(iterator);
					}
				}
			}else{
				std::cout<<"[ERROR 404]Double Free not allowed"<<std::endl;
			}
		}

		void compressor(std::list<Memory_Interval>::iterator iterator){
			std::list<Memory_Interval>::iterator neighbors = iterator;
			if(iterator != this->memoryList.begin()){
				// Left neig
				--neighbors;
				if((*neighbors).get_pid().compare("Free") == 0){
					(*iterator).set_start((*neighbors).get_start());
					this->memoryList.erase(neighbors, iterator);
				}
			}
			if(iterator != this->memoryList.end()){
				//Right neighbor
				neighbors = iterator;
				++neighbors;
				if((*neighbors).get_pid().compare("Free") == 0){
					(*iterator).update_end((*neighbors).get_end());
					this->memoryList.erase(neighbors);
				}
			}
		}
        
		friend std::ostream& operator <<(std::ostream &oss, const Memory_Simullator& obj){
			oss<<"Memory Status: "<<std::endl;
			for(auto& it: obj.memoryList){
				oss<<it;
			}
			oss<<std::endl;
			return oss;
		}
};




#endif //__MEMORY_SIMULLATOR_H__
