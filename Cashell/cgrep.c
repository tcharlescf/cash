#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h> 

#include "cash.h"

#define DELIMS " \t\r\n"

void matching(char *argv[]){ 
	int fd, r, j = 0; 
	char temp, line[100]; 
	FILE *fp;
	char *file = argv[1];
	char *pattern = argv[0];

	fp = fopen(file, "r");

	if((fd = open(file, O_RDONLY)) != -1){ 
		while((r = read(fd, &temp, sizeof(char))) != 0){ 
		// 0 is the end of file. -1 is an error occured
		//	printf("The r value : %d\n", r);

			if(temp != '\n'){ 
				line[j] = temp; 
				j++; 
			} else{ 
			// Compare line to pattern that I typed as a pattern
				if(strstr(line, pattern) != NULL) 
					printf("-> %s\n", line); 

				memset(line, 0, sizeof(line)); 
				j=0; 
			}
		} 
	}   
} 

void showCatch(int argc){ 
	char *arg = strtok(0, DELIMS);
	struct stat stt; 

	char *tokens[2];
	// This token has arguments of the content and file name
	int i = 0;

	if(!arg){
		fprintf(stderr, "Missing arguments\n");		
	} else{
		while(arg != NULL){
		// To distinguish the tokens
			tokens[i] = arg;
			arg = strtok(NULL, DELIMS);
			i++;
		}	
		if(stat(tokens[1], &stt) == 0){
			matching(tokens);
		}
		else{
			perror("stat()");
			exit(1);
		}
		printf("\n");
	}
}
