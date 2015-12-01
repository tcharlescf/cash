#include <stdio.h>
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

void printContents(){
	FILE *fp;

	char *file_name;
	char ch;
	char *arg;
	arg = strtok(0, DELIMS);	

	if(!arg)
		fprintf(stderr, "cat missing an argument\n");
	else{
		file_name = arg;
		fp = fopen(file_name, "r");	
		

		while(1){
		ch = fgetc(fp);

			if(ch == EOF)		
				break;
			printf("%c", ch);
		}
		fclose(fp);
	}
}

