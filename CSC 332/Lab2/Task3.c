#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <string.h> 
#include <errno.h>
#include <fcntl.h> 
#include <unistd.h>

int main (int argc, char* argv[]){

    char* filepath = argv[1];
    char* fileDest = argv[2];
    int fd,fdDest,fdDestErr;
    char buffer[8192];

    if (argc != 3) { 
        printf ("Error: There are just two possible parameters.");
        return 1;
    }

    fd = access(filepath, F_OK); //checks existence of file
    if (fd == -1){ //error checking for access
        printf("\n access() failed [%s]\n", strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file can be accessed\n");
    }
    
    fdDest = open(fileDest, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH); //creates a file with the following permissions: Read, Write, and Truncate. Mode is specified as RW for the user and R for everyone else.
    if (fdDest == -1){ //error checking for open source directory
        printf("\n open() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n destination file can be accessed\n");
    } 

    fd = open (filepath, S_IRUSR);//checks if the file can be opened and can be read
    if (fd == -1){
        printf("\n open() failed [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file can be opened\n");

        fd = read (fd,buffer,sizeof(buffer)); //read the file
        if(fd == -1){ //error checking for reading source 
            printf("\n read() failed [%s]\n",strerror(errno)); 
            return 1;
        }
        else{
            printf("\n read() source successful\n");
        }

        fdDestErr = write (fdDest,buffer,fd); //writes to file destination 
        if(fdDestErr== -1){ //error checking for file destination
            printf("\n write() failed [%s]\n",strerror(errno)); 
            return 1;
        }
        else{
            printf("\n write() destination successful\n");
        }

        printf("\n");
        printf(" File from %s has been successfully copied into %s\n", filepath, fileDest);

        close(fd);
        close(fdDest);
        
    }

    return 0;
}