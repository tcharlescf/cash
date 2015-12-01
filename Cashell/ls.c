#include <stdio.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE

extern int alphasort();

char pathname[MAXPATHLEN];

void die(char *msg){
	perror(msg);
	exit(0);
}

int select_file(struct direct *entry){
	    if ((strcmp(entry->d_name, ".") == 0) || 
			(strcmp(entry->d_name, "..") == 0))
			        return (FALSE);
		else
			return (TRUE);
}

void showList(){
	int i, count;
	struct direct **files;

	if(!getcwd(pathname, sizeof(pathname)))
		die("Error : can't get the path\n");

	count = scandir(pathname, &files, select_file, alphasort);

	if(count <= 0)
		die("There are no files here\n");
													      
	printf("File's count  = %d\n",count);
	for (i = 1; i < count + 1; ++i)
		printf("%s  ",files[i - 1]->d_name);
	printf("\n"); /* flush buffer */
}
