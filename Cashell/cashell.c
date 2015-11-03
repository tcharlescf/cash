#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n" // spacebar 눌렀을 때, 탭 쳤을 때, 엔터 쳤을 때

int main(int argc, char *argv[]) { 
	char *cmd; // 포인터 타입으로 cmd 변수 선언
	char line[MAX_LENGTH];

	while (1) {
		printf("cash$$ ");
		if (!fgets(line, MAX_LENGTH, stdin)) // 명령어 입력 
			break;
			
			if ((cmd = strtok(line, DELIMS))) { // 문자열 자름
				errno = 0; // 에러 초기화

				if (strcmp(cmd, "cd") == 0) { // 입력된 명령어가 cd일 때
			        char *arg = strtok(0, DELIMS);

			        if (!arg) 
						fprintf(stderr, "cd missing argument.\n");
					else 
						chdir(arg); // 디렉토리 변경 함수 cd 
				} else if (strcmp(cmd, "exit") == 0) {
					break;
			} 
			else system(line);
			if (errno) 
				perror("Command failed");
			}
	}
	return 0;
}
