#include <unistd.h> 
#include <stdio.h> 
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    int child,error, wait;
    //input command
    char* command = "ls"; 
    char* args[3] = {"ls","-la", NULL};
    //forks the child
    child = fork(); 

    if (child == -1){
        //if error print message
        printf("fork was unsuccessful\n");
        return 1;
    }
    if(child == 0){
        //forking by showing its pid
        printf("child process id is: %d\n", getpid());
        //ls -la comand
        execvp(command,args); 
        error = errno;
        printf("execvp failed: %i\n", error);
        return 0; 
    }
    if(child>0){
        wait = waitpid(child, NULL, 0);
        return 0;
    }
}