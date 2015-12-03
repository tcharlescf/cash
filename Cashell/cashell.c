#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#ifdef _WIN32

#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n" // When press a space bar, tab key and enter

#include "cash.h"

int main(int argc, char *argv[]) { 
	char *cmd; // Declare cmd variable as a pointer type
	char line[MAX_LENGTH];
	pid_t pid;
	int i = 0, count = 0;
	char *arg_pipe[10];

	while(1) {
		printf("cash|| ");
		cmd = " ";
		if (!fgets(line, MAX_LENGTH, stdin)) // Type commands 
			break;
			
		if ((cmd = strtok(line, DELIMS))) { // Cut the string by DELIMS
			errno = 0; // Initialise error

			if (strcmp(cmd, "cd") == 0) {
			// When the command that is input is "cd"	
				changeDir(0); 
			} else if(strcmp(cmd, "md") == 0){
			// When the command that is input is "md"
				makeDir(0);
			} else if(strcmp(cmd, "copy") == 0){
			// When the command that is input is "copy"		
				copyFile(0);
			} else if (strcmp(cmd, "goodbye") == 0){
			// Quit the shell
				break;
			} else if(strcmp(cmd, "cat") == 0){
			// To see some contents of some file
				printContents();		
			} else if(strcmp(cmd, "path") == 0){
			// To show the current directory path
				showPath();	
			} else if(strcmp(cmd, "echo") == 0){
			// To show what I typed
				showEcho();		
			} else if(strcmp(cmd, "server") == 0){
			// This is a server for chatting
				turnOnServer();	
			} else if(strcmp(cmd, "client") == 0){
			// This is a client for chatting
				turnOnClient();		
			} else if(strcmp(cmd, "ls") == 0){
			// To show the file lists
				showList();		
			} else if(strcmp(cmd, "catch") == 0){
			// To grep some pattern from the file
				showCatch();		
			} else if(strcmp(cmd, "remove") == 0){
			// To remove files
				doRemove();		
			} else if(strcmp(cmd, "pipe") == 0){
				while(cmd != NULL){
					cmd = strtok(NULL, DELIMS);
					arg_pipe[i] = cmd;
					// printf("%s   %d\n", arg_pipe[i], i);
					i++;
				}
				count = i - 1;
				i = 0;
				while(i < count){
					if(strcmp(arg_pipe[i], "|") == 0){	
						doPipe(arg_pipe, count);
						break;
					}
					else	
						i++;
				}
			}
			if (errno) 
				perror("Command failed");
		}
	}
	return 0;
}
