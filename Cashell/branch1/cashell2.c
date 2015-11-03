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

	char *source = argv[1];
	char *destination = argv[2];

	while (1) {
		printf("cash|| ");
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
					copyFile(source, destination);
				}
				else if (strcmp(cmd, "goodbye") == 0){ // Quit the shell
					break;
			} 
			else system(line);
			if (errno) 
				perror("Command failed");
			}
	}
	return 0;
}
