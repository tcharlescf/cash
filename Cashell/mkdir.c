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

void makeDir(int argc){
	char *arg = strtok(0, DELIMS);	
	
	if(!arg)
		fprintf(stderr, "md missing an argument\n");
	else
		mkdir(arg, 0777);	
}
