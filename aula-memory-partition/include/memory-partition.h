#ifndef __MEMORY_PARTITION_H__
#define __MEMORY_PARTITION_H__

struct Memory{
	int pid;
	int start;
	int end;
	int total_size	

}; 

void init(int size);

#endif //__MEMORY_PARTITION_H__
