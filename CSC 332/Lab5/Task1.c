#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main (void){
    int child1, child2, error;
    char input[64];
    char* command, command2; 
    //input command   
    while (1){
        char* executeableInfo[64];
        for(int i=0; i<64; i++)//check executeableInfo contains all 0
            executeableInfo[i]=0;
        int counter=0, counter2=0;
        printf("command: ");
        scanf(" %[^\n]s",input); //scan until it reaches new line

        if(strcmp(input,"exit") ==0)
            exit(0);
        
        if(strchr(input,'|') != NULL){ //checks if string contains |
            command = strtok (input, " ");
            char* executeableInfoTwo[64];
            for(int i=0; i<64; i++)
                executeableInfoTwo[i] = 0;
            int pipefd[2];
            if (pipe(pipefd)==-1){
                printf("error pipe was unsuccessful\n");
                return 1;
            }
            char* pieceOne = strtok(input,"|"); 
            char* pieceTwo = strchr(&input,'\0')+3;
            while (pieceOne != NULL){ //puts the string to pieces based on if there is a space
                executeableInfo[counter] = pieceOne;
                pieceOne = strtok (NULL, " ");
                counter++;
            }

            while (pieceTwo != NULL){ 
                executeableInfoTwo[counter2] = pieceTwo;
                pieceTwo = strtok (NULL, " ");
                counter2++;
            }
            child1=fork();
            if (child1==-1){ //checks for error in forking
                printf("error fork was unsuccessful\n");//error print message
                return 1;
            }

            if(child1 == 0){ //shows they are in child
                dup2(pipefd[1], 1); //dupes the pipe with write
                execvp(executeableInfo[0], executeableInfo);  //executes the command
                error=errno;
                printf("Executable Failed: %s\n", strerror(error)); 
            }

            if (child1>0){
                child2=fork(); 
                if (child2==-1){ //checks for error in forking child
                    printf("error fork was unsuccessful\n");//error print message
                    return 1;
                }

                if(child2==0){
                    waitpid(child1, NULL, 0);
                    close(1);
                    dup2(pipefd[0], 1);

                    execvp(executeableInfoTwo[0], executeableInfoTwo); //executes the command
                    error = errno;
                    printf("Executable Failed: %s\n", strerror(error)); 
                
                return 0;
                }
                if (child1 > 0 && child2 > 0){ //checks if they are in the parent
                    waitpid(child1, NULL, 0); //waits for child1
                    waitpid(child2, NULL, 0); //waits for child2
                }
            }
        }
        else{
            command=strtok (input, " "); //seperates the command by springs for 
            while (command !=NULL){
                executeableInfo[counter] = command;
                command=strtok (NULL, " ");
                counter++;
            }

            child1=fork(); 
            if (child1==-1){ 
                printf("fork was unsuccessful\n");
                return 1;
            }

            if(child1==0){
                execvp(executeableInfo[0], executeableInfo); 
                error = errno;
                printf("Executable failed: %s\n", strerror(error)); //if date command fails, this error message will execute
            }

            if(child1>0){ //shows are they in parent
                if(strchr(input,'|')){
                    waitpid(child2, NULL, 0);
                }
                waitpid(child1, NULL, 0);
            }
        }
    }
    return 0;
}