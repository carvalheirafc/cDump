   #include <sys/wait.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <string.h>
   #define TAM 12

   int main(int argc, char * argv[])
   {
       int vetor_pipe[2]; // 0 para ler e 1 para escrever; apenas uma convencao.....
       pid_t pid;
       char buffer[TAM];

       pipe(vetor_pipe); // cria o pipe
       pid = fork(); // cria um novo processo
       if (pid == 0) // se é o processo-filho
       {
           close(vetor_pipe[1]); // fecha o caminho de escrita pois não será utilizado pelo filho
           while (read(vetor_pipe[0], &buffer, TAM) > 0) // leia enquanto nao for o fim (EOF)
           close(vetor_pipe[0]); // fecha o caminho de leitura do pipe
	   printf("FILHO: O filho terminou e leu: %s\n", buffer);
           exit(EXIT_SUCCESS); // termina o processo filho
       }
       else // se for o processo-pai
       {
           close(vetor_pipe[0]); // fecha o caminho de leitura pois nao será utilizado
	sleep(2);
           write(vetor_pipe[1], argv[1], strlen(argv[1])); // envia o conteúdo do parametro passado pelo pipe
           close(vetor_pipe[1]); // fecha o caminho de escrita caracterizando o fim (EOF)
	   printf("PAI: O pai terminou e escreveu: %s\n", argv[1]);
           wait(NULL); // espera até que o filho termine
	   printf("PAI: O filho terminou\n");
           exit(EXIT_SUCCESS);
       }
       return 0;
   }
