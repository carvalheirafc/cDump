#ifndef __SCHEDULING_ALGORITHMS_H__
#define __SCHEDULING_ALGORITHMS_H__


#include "scheduling_disk.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

template<class T>
class SchedulingAlgorithms {
	private: 
		SchedulingDisk<T> disk;
		std::vector<std::pair<T, bool>> seek_time;
	
	public:
		SchedulingAlgorithms(std::string configuration_file): disk(configuration_file) { };
		~SchedulingAlgorithms() {}
		void run(){
			disk.loadConfiguration();
		}	
		void distanceFromHeader(){
			typename std::vector<T> sectors = this->disk.get_sectors();
			this->seek_time.clear();
			for(size_t it = 0; it < sectors.size(); it++){
				int absolute_value = std::abs(this->disk.get_cylinder_head() - sectors[it]);
				if(this->disk.get_cylinder_head() > sectors[it]){
					this->seek_time.push_back(std::make_pair(absolute_value, true));
				}else{
					this->seek_time.push_back(std::make_pair(absolute_value, false));
					
				}
			}
		}
		
		void calculateTotalCylindersMove(){
			int temp_total = 0;
			typename std::vector<T> sectors = disk.get_sectors();
			
			for(int it = 0; it < this->disk.get_cylinders_waiting(); it++){
				temp_total += std::abs(sectors[it] - sectors[it+1]);
			}
			disk.set_cylinder_head_moves(temp_total);
		}	
		
		void firstComeFirstServed(){
			run();
			calculateTotalCylindersMove();
		}
		
		void shortestSeekTimeFirst(){
			run();
			distanceFromHeader();
			typename std::vector<std::pair<T, bool>> seek_time_temp = this->seek_time;
			typename std::vector<T> sectors = this->disk.get_sectors();

			std::sort(seek_time.begin(), seek_time.end());
			
			size_t it = 0;
			for(auto& iterator: seek_time){
				if(iterator.second == true){
					sectors[it] = std::abs(this->disk.get_cylinder_head() - iterator.first);
				}else{
					sectors[it] = this->disk.get_cylinder_head() + iterator.first;
					
				}	
				it++;
			}
			this->disk.set_sectors(sectors);
			calculateTotalCylindersMove();
		}
		
		void scan(){
			run();
			typename std::vector<T> sectors = this->disk.get_sectors();
			size_t it = 1;
			
			std::sort(sectors.begin()+1, sectors.end());
			
			while(sectors[it] < this->disk.get_cylinder_head()){
				std::swap(sectors[it], sectors[it+1]);
				it += 2;
			}
			this->disk.set_sectors(sectors);
			calculateTotalCylindersMove();
			
		}

		void scanDown(){
			run();
			scan();
			typename std::vector<T> sectors = this->disk.get_sectors();
			typename std::vector<T> sectors_smallets;
			size_t it = 1;
			
			while(sectors[it] < this->disk.get_cylinder_head()){
				sectors.push_back(sectors[it]);
				sectors.erase(sectors.begin()+it);
				
			}
			this->disk.set_sectors(sectors);
			calculateTotalCylindersMove();
		}
		
		friend std::ostream& operator<<(std::ostream& oss, const SchedulingAlgorithms& obj){
			oss<<obj.disk;
			return oss;
		}
		
};

#endif //__SCHEDULING_ALGORITHMS_H__
