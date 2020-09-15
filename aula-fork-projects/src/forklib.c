#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include "forklib.h"

void forkTest(char* str){
	printf("%s \n", str);
}

void getPID(){
	char pidline[BUFFER];
	int i = 0;
	int pidno[64];
	FILE *fp = popen("pidof...", "r");
	fgets(pidline, BUFFER, fp);
	pid_t pid = strtoul(pidline, NULL, 10);
	printf("[%d] \n", pid);

	pclose(fp);
}

void setFork(){
	pid_t pid = fork();
	printf("[%d] \n", pid);

}

void forkTree(int cont){
	pid_t child_a;
	pid_t child_b;

	int parent_counter = 1;
	int child_counter = 100;

	child_a = fork();
	if(child_a == 0){
		printf("\nChild_A Terminated \n");

	} else {
		child_b = fork();
		if(child_b == 0){
			while(child_counter <= 200){
				printf("%d ", child_counter);
				fflush(stdout);
				child_counter++;
				sleep(ONE_SECCOND);
			}
			printf("\nChild_B Terminated \n");
			kill(getpid(), SIGKILL);

		} else {
			while(parent_counter <= 50){
				printf("%d ", parent_counter);
				fflush(stdout);
				parent_counter++;
				sleep(TWO_SECCOND);
			}
			printf("\nParent Terminated \n");
			kill(getpid(), SIGKILL);
		}
	}
}

void implementacao_filho1(int *a){
	*a = *a + 1;
	printf("executando filho 1 = %d\n", getpid());
}

void implementacao_filho2(int *a){
	*a = *a * 2;
	printf("executando filho 2 = %d\n", getpid());
}

void sharedMemory(){

	int filho1, filho2, pid, status;
	int *mem;

	
	int seg_id = shmget(IPC_PRIVATE, 1*sizeof(int), IPC_CREAT | 0666);
	

	printf("Pai comecou (PID=%d)\n", getpid());
	mem = shmat(seg_id, NULL, 0);
	*mem = 27;
	filho1 = fork();
	if(filho1 == 0){//se for o filho...
		// Segmento de memoria pra uso
		mem = shmat(seg_id, NULL, 0);
		implementacao_filho1(mem);	
		//printf com o espaço de memoria a ser usado. @param mem
		//printf("%s no processo PID=%d\n", mem, getpid());
		shmdt(mem);
		exit(0);
	}
	status = wait(NULL);
	if(filho1 > 0){
		filho2 = fork();
		if(!filho2){//se for o filho...
			mem = shmat(seg_id, NULL, 0);
			implementacao_filho2(mem);	
			//Nao precisa da chamada do sprintf pois ja foi usada no processo do filho
			//printf("%s no processo PID=%d\n", mem, getpid());
			shmdt(mem);
			exit(0);
			
		}
	}

	status = wait(NULL);
	printf("(PID=%d) Processo sendo finalizado\n", getpid());
	printf("valor final de a=%d\n", *mem);
	//Libera o espaço de memoria acoplado aos processos
	shmctl(seg_id, IPC_RMID, NULL);
	exit(0);
	printf("Pai terminou\n");


}
