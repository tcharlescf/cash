#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "cash.h"

#define DELIMS " \t\r\n"

void doRemoveDir(int argc){
	char *arg = strtok(0, DELIMS);
	char *filename = arg;

	if(rmdir(filename) == 0)
		printf("Directory %s has been deleted. \n", filename);
	else
		fprintf(stderr, "Error deleting file %s.\n", filename);
}
