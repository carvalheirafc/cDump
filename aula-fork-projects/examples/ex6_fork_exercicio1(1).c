#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid[4]={-1, -1, -1, -1};
	int status,i;
	pid[0] = fork();
        if (pid[0] < 0){
		printf("Erro ao criar processo #0\n");
		return 1;
	}
	if(pid[0] > 0){ //se for o pai...
		printf("PAI: criando o segundo processo\n");
		pid[1] = fork();
        	if (pid[1] < 0){
			printf("Erro ao criar processo #1\n");
			return 1;
		}
	}
	//os filhos...
	if(pid[0] == 0){
		printf("FILHO#1: Criando o processo filho do filho cujo PID é %d\n", getpid());				
		pid[2] = fork();
		for(;;);
		
	}

	if(pid[1] == 0){
		printf("FILHO#2: Criando o processo filho do filho cujo PID é %d\n", getpid());				
		pid[3] = fork();
		for(;;);

	}

	
	if((pid[2] == 0) || (pid[3] == 0)){
		for(;;);	
	}
	else{
		for(i=0;i<2;i++)
			status = wait(NULL);
		printf("Processo-Filho #%d finalizou\n", status);
	}
	return 0;
}

