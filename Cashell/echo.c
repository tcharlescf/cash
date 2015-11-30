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
#define DELIMS " \t\r\n"

#include "cash.h"

void showEcho(int argc){
	char *arg = strtok(0, DELIMS);	
	int i;

	if(!arg)
		fprintf(stderr, "There's nothing to answer\n");
	else{
		printf("The echo : ");
		for(i = 0; i < strlen(arg); i++){
			printf("%c", arg[i]);	
		}
		printf("\n");
	}
}
