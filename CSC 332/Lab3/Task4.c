#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

int main (int argc, char* argv){
    char* filepath = "readme.txt"; //open file the readme.txt
    int fd, pipefd[2], fq = 0, wait, fdErr, fdErrTwo; 
    int returnvalue;
    struct stat OGfileCharacteristics;
    char parentBuffer[20] = {"Parent is writing: "};

    if (pipe(pipefd) == -1){//if there is error with pipe
        printf("There's error has with the pipe\n");
        return 1;
    }

    fq = fork();
    if (fq == -1){
        printf("error fork was unsuccessful\n");
        return 1;
    }

    if(fq == 0){
        fd = open (filepath, O_RDONLY|S_IRUSR);
        if (fd == -1){ //error checking
            printf("\n open() failed with error [%s]\n", strerror(errno)); 
            return 1; 
        }
        else{ //continue if no error
            printf("\n file can be opened\n");
            fstat(fd,&OGfileCharacteristics); 
            char* buffer = malloc(OGfileCharacteristics.st_size);
            returnvalue = read (fd,buffer,OGfileCharacteristics.st_size);
            
            if(returnvalue == -1){ //error for reading source 
                printf("\n read() failed with error [%s]\n",strerror(errno)); //outputs error 
                return 1;
            }
            else{
                printf("\n read() source file successful\n");
                write(pipefd[1], buffer,OGfileCharacteristics.st_size);
                close(pipefd[1]); 
            }
        }
    }

    if(fq > 0){//checks if we are in the parent
        wait = waitpid(fq, NULL, 0); 
        fd = open (filepath, O_WRONLY);//checks if the file can be opened and can be read
        
        if (fd == -1){ //error checking
            printf("\n open() failed with error [%s]\n",strerror(errno)); 
            return 1; 
        }
        else{
            fstat(fd,&OGfileCharacteristics); //takes info form file descriptor and write it to OGfilecharacteristics
            char* buffer = malloc(OGfileCharacteristics.st_size); //creates buffer of proper size
            returnvalue = read(pipefd[0],buffer,OGfileCharacteristics.st_size);
            
            fdErr = write(fd,parentBuffer,strlen(parentBuffer));
            if(fdErr== -1){
                printf("\n write() failed with error [%s]\n",strerror(errno));
                return 1;
            }
            else{
                printf("\n write() destination file successful\n");
            }

            fdErrTwo = write(fd,buffer,OGfileCharacteristics.st_size);

            if(fdErrTwo== -1){//error checking for file destination
                printf("\n write() failed with error [%s]\n",strerror(errno));
                return 1;
            }
            else{
                printf("\n write() destination file successful\n");
            }

            printf("\n File from %s has been successfully processed \n", filepath);
        }
    }
    return 0;
}