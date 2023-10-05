#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <string.h> 
#include <errno.h>
#include <fcntl.h> 
#include <unistd.h>

int main (int argc, char* argv[]){

    char* filepath = argv[1]; 
    int fd;
    char buffer[fd];

    fd = access(filepath, F_OK); //check if the file exists
    if (fd == -1){ //If the file descriptor fails, print the error message.
        printf("\n access() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file can be accessed\n");
    }

    fd = open (filepath, S_IRUSR);//check if the file can be read and opened
    if (fd == -1){
        printf("\n open() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file can be opened\n");
        fd = read (fd, buffer, sizeof(buffer)); //reads the entire file and adds the information to a buffer.
        printf("\n%s", buffer);
        printf("\n");
        close(fd);
    }

    return 0;
}