#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/shm.h>
int a=0;	
void implementacao_filho1(int *a){
	*a = *a + 1;
	printf("executando filho 1 = %d\n", getpid());
}

void implementacao_filho2(int *a){
	*a = *a + 2;
	printf("executando filho 2 = %d\n", getpid());
}

int main(){

	int filho1, filho2, pid, status;
	char *mem;

	
	int seg_id = shmget(IPC_PRIVATE, 20*sizeof(char), IPC_CREAT | 0666);
	

	printf("Pai comecou (PID=%d)\n", getpid());

	filho1 = fork();
	if(filho1 == 0){//se for o filho...
		implementacao_filho1(&a);	
		// Segmento de memoria pra uso
		mem = shmat(seg_id, NULL, 0);
		//printf com o espaço de memoria a ser usado. @param mem
		sprintf(mem, "escrevendo teste");
		printf("%s no processo PID=%d\n", mem, getpid());
		shmdt(mem);
		exit(0);
	}
	status = wait(NULL);
	if(filho1 > 0){
		filho2 = fork();
		if(!filho2){//se for o filho...
			implementacao_filho2(&a);	
			mem = shmat(seg_id, NULL, 0);
			//Nao precisa da chamada do sprintf pois ja foi usada no processo do filho
			printf("%s no processo PID=%d\n", mem, getpid());
			shmdt(mem);
			exit(0);
			
		}
	}

	status = wait(NULL);
	printf("(PID=%d) Processo sendo finalizado\n", getpid());
	printf("valor final de a=%d\n", a);
	//Libera o espaço de memoria acoplado aos processos
	shmctl(seg_id, IPC_RMID, NULL);
	exit(0);
	printf("Pai terminou\n");
	
	return 0;
}

