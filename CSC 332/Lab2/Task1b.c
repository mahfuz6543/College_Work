#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <string.h> 
#include <errno.h>
#include <fcntl.h> 
#include <unistd.h>

int main (int argc, char* argv[]){
    int fd;
    char* filepath = argv[1]; //takes file path from input
    if (argc != 2){ //error if there is mulitple arguments
        printf ("\n usage: \n");
        return 1;
    }

    fd = open(filepath, O_CREAT | 777); //opens and creates files with all permissions
    if(-1 == fd) { 
        printf("\n open() failed with error [%s]\n", strerror(errno)); 
        return 1; 
    }
    else {
        printf("\n open() successful \n");
        close(fd);
    }
    return 0;
}