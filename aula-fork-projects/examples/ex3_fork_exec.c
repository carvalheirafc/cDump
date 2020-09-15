#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t  pid;
	/* cria outro processo */
	pid = fork();
	if (pid < 0) { /* ocorrência de erro*/
		fprintf(stderr, "Criação Falhou");
		exit(-1);
	}
	else if (pid == 0) { /* processo filho*/
	printf("Esta é a execução do filho(PID=%d), cujo pai tem PID=%d\n    ", getpid(), getppid());
		execlp("/bin/ls", "ls", "-l", NULL);
		printf("testando o execlp\n");
		exit(0);
	}
	else { /* processo pai */
		wait(NULL);
		printf("Processo-Filho finalizou\n");
		exit(0);
		
	}
}

