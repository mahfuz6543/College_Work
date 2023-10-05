#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h> 

int main(int argc, char* argv[]){
    int count;
    char* sourcefile = "source.txt";
    char* file1 = "destination1.txt";
    char* file2 = "destination2.txt";
    int file1Descriptor,file2Descriptor,sourceDescriptor,returnValue, destDescriptor, destDescriptor2;
    struct stat OGfileCharacteristics;
    // 100 character array
    char hundred[100];
    // 50 character array
    char fifty[50]; 
    // access of the files
    sourceDescriptor = access(sourcefile, F_OK);

    if (sourceDescriptor == -1){
        printf("\n access() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }   
    else{
        printf("\n file can be accessed\n");
    }
    destDescriptor = open (file1, O_RDWR);
    if (destDescriptor == -1){
        printf("\n open() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }     
    else{
        printf("\n file can be open\n");
    }
    destDescriptor2 = open (file2, O_RDWR);
    if (destDescriptor2 == -1){
        printf("\n open() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }   
    else{
        printf("\n file can be open\n");
    }

    sourceDescriptor = open (sourcefile, S_IRUSR);
    // if file can be read
    if (sourceDescriptor == -1){ 
        //if its error, print the message
        printf("\n open() failed with error [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file can be opened\n");
        //reads from file descriptor
        fstat(sourceDescriptor,&OGfileCharacteristics);
        //loop through the file
        while (count <= OGfileCharacteristics.st_size){ 
            returnValue = read(sourceDescriptor,hundred,100);
            for (int i=0; i<100; i++){ 
                //checks if index value is 1, it is change to L
                if (hundred[i] == '1'){
                    hundred[i] = 'L';
                }
            }
            //increment count by number of bytes read
            count = count + returnValue; 
            returnValue = write(destDescriptor,hundred,returnValue);

            returnValue = read (sourceDescriptor,fifty,50); 
            for (int i=0; i<50; i++){
                //checks if index value is 3, it is change to E
                if (fifty[i] == '3'){ 
                    fifty[i] = 'E';
                }
            }
            count = count + returnValue;
            returnValue = write(destDescriptor2,fifty,returnValue); 
        }
        return 0;
    }
}