#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "cash.h" 

void doPipe(char *argv[], int count){
	int fd[2], nbytes;
	pid_t pid;
	char readbuffer[80];

	char *commands[count];
	char *before_pipe[count];
	char *after_pipe[count];
	int i, where = 0;

	i = 0;
	while(i < count){
		commands[i] = argv[i];		
		printf("%s\n", commands[i]);
		i++;
	}

	// Find | where is
	for(i = 0; i < count; i++){
		if(strcmp(commands[i], "|") == 0){
			where = i;	
			printf("| indes : %d\n", where);
		}	
	}

	for(i = 0; i < where; i++){
		before_pipe[i] = commands[i];
		printf("Before_pipe : %s    %d\n", before_pipe[i], i);
	}

	for(i = where + 1; i < count; i++){
		after_pipe[i] = commands[i];		
		printf("After_pipe : %s     %d\n", after_pipe[i], i);
	}

	// Create the pipe
	pipe(fd);

	// The first command for pipe
	if((pid = fork()) == -1){
		perror("fork");
		exit(1);
	} else if(pid == 0){
		close(1); // Close output of the pipe
		dup2(fd[1], 1);

		if(strcmp(before_pipe[0], "ls") == 0)
			execlp("ls", "ls", NULL);
		else
			printf("wrong command\n");

	} else{
		close(fd[1]);
	}

	// The second command for pipe
	pid = fork();
	if(pid == 0){
		close(0); // Close input of the pipe
		dup2(fd[0], 0);
		if(strcmp(after_pipe[where + 1], "catch") == 0)
			execlp("grep", "grep", after_pipe[where + 2], NULL);
		else if(strcmp(after_pipe[where + 1], "wc") == 0)
			execlp("wc", "wc", NULL);
		else{
			printf("wrong command\n");
		}
	} else{
		close(fd[0]);		
	}
		
	waitpid(pid);
}
