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

void showPath(){
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "You are here :  %s\n", cwd);
	else
		perror("getcwd() error");
}
