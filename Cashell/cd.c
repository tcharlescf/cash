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

void changeDir(int argc){
	char *arg;
	arg = strtok(0, DELIMS); 

	if(!arg)
		fprintf(stderr, "cd missing an argument\n");
	else
		chdir(arg);	
}

