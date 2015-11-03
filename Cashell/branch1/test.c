#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "test.h"

int main(int argc, char *argv){
	char *source; 		
	char *destination;

	source = argv[1];
	destination = argv[2];
	copyFile(source, destination);

	return 0;
}
