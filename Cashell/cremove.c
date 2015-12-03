#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#include "cash.h"

#define DELIMS " \t\r\n"

void doRemove(int argc){
	char *arg = strtok(0, DELIMS);
	// declare an array to store file name...
	char *filename = arg;
	 
	// check any error...
	if(remove(filename) == 0)
		printf("File %s has been deleted.\n", filename);
	else
		fprintf(stderr, "Error deleting file %s.\n", filename);
}
