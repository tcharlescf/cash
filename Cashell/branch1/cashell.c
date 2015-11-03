#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#ifdef _WIN32

/* #define chdir _chdir */

#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n" // spacebar 눌렀을 때, 탭 쳤을 때, 엔터 쳤을 때

#include "cash.h"

int main(int argc, char *argv[]) { 
	char *cmd; // 포인터 타입으로 cmd 변수 선언
	char line[MAX_LENGTH];

	while (1) {
		printf("cash|| ");
		if (!fgets(line, MAX_LENGTH, stdin)) // 명령어 입력 
			break;
			
			if ((cmd = strtok(line, DELIMS))) { // 문자열 자름
				errno = 0; // 에러 초기화

				if (strcmp(cmd, "cd") == 0) { // 입력된 명령어가 cd일 때
			        char *arg = strtok(0, DELIMS);

			        if (!arg) 
						fprintf(stderr, "cd missing argument.\n");
					else 
						changeDir(arg); // A function changes a directory. 
				} else if(strcmp(cmd, "md") == 0){
					char *arg = strtok(0, DELIMS);
					
					if(!arg)	
						fprintf(stderr, "mkdir missing argument.\n");
					else
						makeDir(arg, 0777); // A function makes a directory.
				}
				else if (strcmp(cmd, "exit") == 0) {
					break;
			} 
			else system(line);
			if (errno) 
				perror("Command failed");
			}
	}
	return 0;
}
