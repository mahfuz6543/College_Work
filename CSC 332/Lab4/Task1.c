#include <unistd.h> 
#include <stdio.h> 
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    int child, error,error2, wait;
     //forks the child
    child = fork();
     //terminate
    wait = waitpid(child, NULL,0);

    if (child == -1){ 
        //if error print message
        printf("fork was unsuccessful\n");
        return 1;
    }
    if(child == 0){
         //forking by showing its pid
        printf("child process id is: %d\n", getpid());
        //date command
        execl("/usr/bin/date","/usr/bin/date", NULL); 
        error = errno; 
        printf("execl failed: %i\n",error);
        return 0; 
    }
    if(child>0){
        wait = waitpid(child, NULL, 0); 
        return 0;
    }
}