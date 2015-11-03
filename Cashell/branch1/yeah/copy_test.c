#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_READ 1024

int main(int argc, char *argv[]){
	int src_fd, dst_fd;
	char buf[MAX_READ];
	ssize_t rcnt, tot_cnt = 0;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 0644

	if(argc < 3){
		fprintf(stderr, "Usage : file_copy src_file dest_file.\n");
		exit(1);
	}
	
	if((src_fd = open(argv[1], O_RDONLY)) == -1){
		perror("src open.\n");		
		exit(1);
	}

	if((dst_fd = creat(argv[2], 0644)) == -1){
		perror("dst open.\n");		
		exit(1);
	}

	while((rcnt = read(src_fd, buf, MAX_READ)) > 0){
		tot_cnt += write(dst_fd, buf, rcnt);		
	}

	if(rcnt < 0){
		perror("read.\n");		
		exit(1);
	}
	
	printf("total write count = %d.\n", tot_cnt);
	close(src_fd);
	close(dst_fd);

	return 0;	
}
