#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){
	int f, f2;
	ssize_t chars, writes;
	char buffer[1024];

	if(f = open("abc.txt", O_RDONLY) < 0){
		printf("I can't open the first file.\n");		
	}
	if(f2 = creat("uio.txt", 0644) < 0){
		printf("I can't open the second file.\n");		
	}

	chars = read(f, buffer, 1024);
	writes = write(f2, buffer, chars);

	close(f);
	close(f2);
	
	return 0;	
}
