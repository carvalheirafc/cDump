#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string.h>

#include "pipelib.h"


void printChar(char* buffer){
	printf("Write in Buffer: ");
	for(int it = 0; it < strlen(buffer); it++){
		printf("%c", buffer[it]);
	}
	printf("\n");
}


// @Questao 01
void nChilds(int argNumber){
	
	pid_t pid;
	pid = fork();
	if(argNumber == 0){
		exit(EXIT_SUCCESS);
	}
	if (pid > 0){
		wait(NULL);

	}else{
		printf("ThisPid: %d, ParentPid: %d \n", getpid(), getppid());
		nChilds(argNumber-1);
		exit(EXIT_SUCCESS);
	}

}

// @Questao 03
// ps: Nao funciona corretamente....
// Não perca o tempo tentando corrigir...
//
void summationBetwenPipes(int argNumber){
	int foward_pipe_array[PIPE_SIZE], backward_pipe_array[PIPE_SIZE];
	pid_t pid;
	int summationTotal = argNumber;
	char convertedNumber[BUFFER_SIZE];
	char buffer[BUFFER_SIZE];

	pipe(foward_pipe_array);
	pipe(backward_pipe_array);


	//Child Block
	for(int it = 0; it < argNumber; it ++){
		pid = fork();	
		if(pid == 0){
			printf("Child is On \n");
			printf("ThisPid: %d, ParentPid: %d \n", getpid(), getppid());
			close(foward_pipe_array[WRITE]);
			while (read(foward_pipe_array[READ], &convertedNumber, BUFFER_SIZE) > 0)
			close(foward_pipe_array[READ]);
			printf("Child Read ");
			printChar(convertedNumber);
			summationTotal = atoi(convertedNumber);
			summationTotal = summationTotal + it;

			printf("Summation Process: %d \n", summationTotal);
			sprintf(buffer, "%d", summationTotal);
			
			
			printf("Debug> ");
			printChar(convertedNumber);
			
			close(backward_pipe_array[READ]);
			write(backward_pipe_array[WRITE], buffer, BUFFER_SIZE);
			close(backward_pipe_array[WRITE]);
			printf("Child is gone...\n");
	
		
			exit(EXIT_SUCCESS);
		}
	//Parent Block
		if(pid > 0){
			printf("Parent is On \n");
			printf("ThisPid: %d, ParentPid: %d \n", getpid(), getppid());
			sprintf(convertedNumber, "%d", argNumber);
			close(foward_pipe_array[READ]);
			write(foward_pipe_array[WRITE], convertedNumber, BUFFER_SIZE);
			close(foward_pipe_array[WRITE]);
			
			close(backward_pipe_array[WRITE]);
			while (read(backward_pipe_array[READ], &convertedNumber, BUFFER_SIZE) > 0)
			close(backward_pipe_array[READ]);
			
			printf("Parent is gone...\n");
			wait(NULL);	
			
		
		}	
	}
}

// @Questao 02
void communicationPipes(int argNumber){
	int foward_pipe_array[PIPE_SIZE], backward_pipe_array[PIPE_SIZE];
	pid_t pid;
	int intNumber = 0;
	char convertedNumber[BUFFER_SIZE];
	char buffer[BUFFER_SIZE];

	pipe(foward_pipe_array);
	pipe(backward_pipe_array);

	pid = fork();


	//Child Block
	if(pid == 0){
			
		printf("Child is On \n");
		printf("ThisPid: %d, ParentPid: %d \n", getpid(), getppid());
		close(foward_pipe_array[WRITE]);
		while (read(foward_pipe_array[READ], &convertedNumber, BUFFER_SIZE) > 0)
		close(foward_pipe_array[READ]);
		printf("Child Read ");
		printChar(convertedNumber);
		intNumber = atoi(convertedNumber);


		sprintf(buffer, "%d", intNumber+1);
			
			
		printf("Debug> ");
		printChar(convertedNumber);
			
		close(backward_pipe_array[READ]);
		write(backward_pipe_array[WRITE], buffer, BUFFER_SIZE);
		close(backward_pipe_array[WRITE]);
		printf("Child is gone...\n");
		
			
		exit(EXIT_SUCCESS);

	}
	//Parent Block
	if(pid > 0){
		printf("Parent is On \n");
		sprintf(convertedNumber, "%d", argNumber+1);
		close(foward_pipe_array[READ]);
		write(foward_pipe_array[WRITE], convertedNumber, BUFFER_SIZE);
		close(foward_pipe_array[WRITE]);
		printf("Parent is gone...\n");
		

		char newChar[BUFFER_SIZE];
		close(backward_pipe_array[WRITE]);
		while (read(backward_pipe_array[READ], &newChar, BUFFER_SIZE) > 0)
		printf("Parent Read: ");
		printChar(newChar);
		close(backward_pipe_array[READ]);
		
		wait(NULL);
	}
}
