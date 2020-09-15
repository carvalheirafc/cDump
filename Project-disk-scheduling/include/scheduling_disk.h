#ifndef __SCHEDULING_DISK_H__
#define __SCHEDULING_DISK_H__

//#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

template <class T>
class SchedulingDisk {
	private:
		std::string configuration_file;
		std::vector<T> sectors;
		
		int cylinder_head;
		int cylinders_waiting;	
		int cylinders_total;

	public:
		SchedulingDisk(std::string config_file){
			this->configuration_file = config_file;
			this->cylinder_head = 0;
			this->cylinders_waiting = 0; 	
			this->cylinders_total = 0;
		}				
		~SchedulingDisk() {		}
		
		void loadConfiguration(){
			std::fstream file_stream_in;
			int index_line = 0;
			std::string buffer;

			try{
				
				file_stream_in.open(this->configuration_file, std::fstream::in);
				file_stream_in.exceptions(std::fstream::badbit);				
				
				while(std::getline(file_stream_in, buffer)){
					if(index_line == 0)
						this->cylinder_head = std::stoi(buffer);
					if(index_line == 1)
						this->cylinders_waiting = std::stoi(buffer);
					if(index_line == 2)
						readSectors(buffer);
					index_line++;
				}	
				
				file_stream_in.close();	
				this->cylinders_total = 0;		
			}catch(std::exception const& e){
				std::cout<<"Something went wrong..."<<std::endl;
				std::cout<<e.what()<<std::endl;
			}
		}
		
		void readSectors(std::string buffer){
			this->sectors.clear();
			std::istringstream iss(buffer);	
			std::string token;
			
			this->sectors.push_back(this->cylinder_head);
			while(std::getline(iss, token, ' ')){
				this->sectors.push_back(std::stoi(token));
			}
		}
		
		void set_sectors(typename std::vector<T> sectors_to_copy){
			this->sectors.clear();
			this->sectors = sectors_to_copy;
		}	
		
		void set_cylinder_head_moves(int cylinder_head_moves){
			this->cylinders_total = cylinder_head_moves;
		}
		
		const std::vector<T> get_sectors(){
			return this->sectors;
		}
		
		const int get_cylinders_waiting(){
			return this->cylinders_waiting;
		}	
		
		const int get_cylinder_head(){
			return this->cylinder_head;
		}	
		
		friend std::ostream& operator<<(std::ostream& oss, const SchedulingDisk& obj){
			oss<<"Ordem: ";
			for(auto &it: obj.sectors)
				oss<<it<<" ";
			oss<<std::endl;
			
			oss<<"Cilindros: "<<obj.cylinders_total<<std::endl;
			return oss;
		}
};


#endif //__SCHEDULING_DISK_H__
