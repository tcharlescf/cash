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

#define MAX_READ 1024

int copyFile(int argc){

	char *arg, *source, *destination;
	int cnt = 0;

	arg = strtok(0, DELIMS);
	while(arg != NULL){
		printf("%s\n", arg);		
//		arg = strtok(0, DELIMS);
		
		if(cnt == 0){
			source = arg;
			cnt++;
			printf("This is a source content : %s\n", source);
			arg = strtok(0, DELIMS);
		} else if(cnt == 1){
			destination = arg;		
			printf("This is a destination content : %s\n", destination);
			arg = strtok(0, DELIMS);
		}
	}

	int src, dst;
	char buf[MAX_READ];	
	ssize_t rcnt, tot_cnt = 0;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if((src = open(source, O_RDONLY)) == -1){
		perror("src open.\n");		
		exit(1);
	}

	if((dst = creat(destination, 0644)) == -1){
		perror("dst open.\n");		
		exit(1);
	}

	while((rcnt = read(src, buf, 1024)) > 0){
		tot_cnt += write(dst, buf, rcnt);		
	}

	if(rcnt < 0){
		perror("read.\n");		
		exit(0);
	}
	
	close(src);
	close(dst);

	return 0;
}
