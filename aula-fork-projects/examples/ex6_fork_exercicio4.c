#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid[3]={ -1, -1, -1};
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
		if(pid[1] > 0){//se for o pai...
			for(i=1;i<=50;i++){
			   printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			   sleep(2);
			}
			printf("Processo pai vai morrer");
			exit(0);
		}
	}
	//os filhos...
	if(pid[0] == 0){
		for(i=100;i<=199;i++){
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(1);
		}
		printf("Filho 1 vai morrer");
		exit(0);
		
	}

	if(pid[1] == 0){
		for(i=200;i<=299;i++){
			printf("PID=%d; PPID=%d; %d\n", getpid(), getppid(), i);
			sleep(1);
		}
		printf("Filho 2 vai morrer");
		exit(0);

	}

	
	return 0;
}

