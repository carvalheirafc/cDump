#include <sys/wait.h>
	   #include <stdio.h>
	   #include <stdlib.h>
	   #include <unistd.h>
	   #include <string.h>

#define MAX_SIZE 4
#define PIPE_SIZE 2
#define WRITE 1
#define READ 0

int main(int argc, char const *argv[])
{
	int vetor_pipe_ida[PIPE_SIZE], vetor_pipe_volta[PIPE_SIZE];
	pid_t pid;
	char buffer[MAX_SIZE];
	char convertedNumber[MAX_SIZE];
	int num;
	int SomaFinal = atoi(argv[1]);
	pipe(vetor_pipe_ida);
	pipe(vetor_pipe_volta);

	for (int i = 0; i <= atoi(argv[1]); ++i)
	{
		printf("i: %d\n", i);
		pid = fork();
		if(pid == 0){
			printf("Filho rodando...\n");
			close(vetor_pipe_ida[WRITE]);
			while(read(vetor_pipe_ida[READ], &convertedNumber, MAX_SIZE) > 0);
			close(vetor_pipe_ida[READ]);
			SomaFinal += i;

			printf("Soma: %d\n", SomaFinal);
			sprintf(convertedNumber, "%d", SomaFinal);
			close(vetor_pipe_ida[READ]);
			write(vetor_pipe_ida[WRITE], convertedNumber, MAX_SIZE);
			close(vetor_pipe_ida[WRITE]);
			exit(0);



		}

		if(pid > 0){
			printf("Pai rodando...\n");
			num = atoi(argv[1]);
			sprintf(buffer, "%d", num);
			close(vetor_pipe_ida[0]);
			write(vetor_pipe_ida[1], buffer, MAX_SIZE);
			close(vetor_pipe_ida[1]);
			wait(NULL);
		}
	}

	return 0;
}
