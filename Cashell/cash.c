#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
	char line[MAX_LENGTH];

	while (1) {
	    printf("$ ");
	    if (!fgets(line, MAX_LENGTH, stdin)) 
			break;
	    system(line);
	}

	return 0;
}
