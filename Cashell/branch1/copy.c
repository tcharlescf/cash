#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>

#ifdef _WIN32

#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n" // When press a space bar, tab key and enter

#define BUFFER_SIZE 1024
#define COPYMORE 0644

#include "cash.h"


int copyFile(char *source, char *destination){
	int f_file, s_file, n_chars;
	char buffer[BUFFER_SIZE];	

	// open file
	if((f_file = open(source, O_RDONLY)) < 0)
		fprintf(stderr, "Can't open the file.\n");

	if((s_file = open(destination, O_WRONLY)) < 0)
		fprintf(stderr, "Can't make a new file.\n");
	
	// copy file	
	while((n_chars = read(f_file, buffer, BUFFER_SIZE)) > 0){
		if(write(s_file, buffer, n_chars) != n_chars)
			fprintf(stderr, "Can't write the s file to the d file\n");
		
		if(n_chars == -1)
			fprintf(stderr, "error\n");
	}

	// close file
/*	if(close(in_fd) == -1 || close(out_fd) == -1)
		fprintf(stderr, "close error\n"); */
	
	if(close(f_file) < 0)
		fprintf(stderr, "Failed close the source file.\n");
	if(close(s_file) < 0)	
		fprintf(stderr, "Failed close the destination file.\n");

	return 1;
}
