#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main (void){
    int child1 = 0, child2 = 0, error, wait, wait2;
    //forks the child1
    child1 = fork(); 
    if (child1 == -1){
        //if error print message
        printf("fork was unsuccessful\n");
        return 1;
    }
    if(child1 == 0){
        //executes the program
        execl("Prcs_P1", "Prcs_P1", NULL);
        error = errno;
        //if command fails show the error
        printf("excl failed: %i\n", error);
        return 0;
    }
    if(child1 > 0){
        wait = waitpid(child1, NULL, 0);
        child2 = fork();
        if (child2 == -1){
            printf("fork was unsuccessful\n");
            return 1;
        }
        if(child2 == 0){
            //executes the program
            execl("Prcs_P2", "Prcs_P2", NULL); 
            error = errno;
            printf("excl failed: %i\n", error);
        }
        if(child2>0){
            wait2 = waitpid(child2, NULL, 0);
            return 0;
        }
    }
}