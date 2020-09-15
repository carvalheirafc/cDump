   #include <sys/wait.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <string.h>
   #define MAX_SIZE 4

   int main(int argc, char * argv[])
   {
       int vetor_pipe_ida[2], vetor_pipe_volta[2];
       pid_t pid;
       char buffer[MAX_SIZE];
	int num, resposta;

       pipe(vetor_pipe_ida); // cria o pipe
       pipe(vetor_pipe_volta); // cria o pipe
       pid = fork(); // cria um novo processo
       if (pid == 0) // se é o processo-filho
       {

           close(vetor_pipe_ida[1]); // fecha o caminho de escrita DESTE PIPE pois não será utilizado pelo filho
           while (read(vetor_pipe_ida[0], buffer, MAX_SIZE) > 0); // leia enquanto nao for o fim (EOF)
	   
	   sscanf(buffer, "%d", &num);	
           close(vetor_pipe_ida[0]); // fecha o caminho de leitura do pipe pois concluiu a leitura
           printf("FILHO: O filho leu: %d\n", num);
	   
	   num = num +1;
	   sprintf(buffer, "%d", num);

	   //agora vamos RESPONDER ao pai	 

           close(vetor_pipe_volta[0]); // fecha o caminho de leitura DESTE PIPE pois nao será utilizado pelo filho
           
	   write(vetor_pipe_volta[1],  buffer, MAX_SIZE); // envia o conteúdo do parametro passado pelo pipe
           close(vetor_pipe_volta[1]); // fecha o caminho de escrita do pipe pois concluiu a escrita
           
	   printf("FILHO: O filho escreveu: %d\n", num);
	   printf("FILHO: O filho terminou\n");
           
	   exit(0); // termina o processo filho
       }
       else // se for o processo-pai
       {
	   num = atoi(argv[1]);   
	   sprintf(buffer, "%d", num);
           close(vetor_pipe_ida[0]); // fecha o caminho de leitura DESTE PIPE  pois nao será utilizado pelo pai
           write(vetor_pipe_ida[1], buffer, MAX_SIZE); // envia o conteúdo do parametro passado pelo pipe
           close(vetor_pipe_ida[1]); // fecha o caminho de escrita caracterizando o fim (EOF)
	   printf("PAI: O pai escreveu: %s\n", buffer);


	   //agora vamos LER a RESPOSTA do filho	 
           
           close(vetor_pipe_volta[1]); // fecha o caminho de escrita do pipe pois concluiu a escrita
	   while (read(vetor_pipe_volta[0], buffer, MAX_SIZE) > 0) // leia enquanto nao for o fim (EOF)
           close(vetor_pipe_volta[0]); // fecha o caminho de leitura do pipe pois concluiu a leitura
	   sscanf(buffer, "%d", &num);	
	   printf("PAI: O pai leu: %d\n", num);
           
	   wait(NULL); // espera até que o filho termine
	   printf("PAI: O filho terminou\n");
	   printf("PAI: O pai terminou\n");
           exit(0);
       }
       return 0;
   }
