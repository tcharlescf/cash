#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

main(int argc, char *argv[]){
    char *file = argv[1];
    rmdir(file);
}
