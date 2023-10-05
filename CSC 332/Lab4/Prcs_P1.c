#include <unistd.h> 
#include <stdio.h> 
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h> 

int main(int argc, char* argv[]){
    char* file1 = "destination1.txt"; 
    char* file2 = "destination2.txt";
    int file1Descriptor,file2Descriptor;
    // create 2 destination files 
    file1Descriptor = creat(file1, 0777);
    if (file1Descriptor == -1){
        printf("\n creat() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file1 created\n");
    }
    file2Descriptor = creat(file2, 0777);
    if (file2Descriptor == -1){
        printf("\n creat() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file2 created\n");
    }

}