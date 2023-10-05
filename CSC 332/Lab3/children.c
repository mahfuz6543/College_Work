#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main (void) {

    int child1, child2, PID1, PID2, wait1, wait2;
    child1 = fork(); //first child
    
    if (child1 == -1) {
        printf("error fork was unsuccessful\n"); //if first child results in error print error message
        return 1;
    }
    else if (child1 == 0)
    {
        PID1 = getpid(); //variable stores childs PID
        printf("I am child one, my pid is: %i \n", PID1); //child 1:
        return 1;
    }
    else if (child1 > 0){ //check if its in the parent
        wait1 = waitpid(child1, NULL, 0); //waits for first child to terminate 
        child2 = fork(); //forks second child
        wait2 = waitpid(child2, NULL, 0); //waits for second child to terminate
        if (child2 == -1){ 
            printf("error fork was unsuccessful\n"); //error message if forking fails
            return 1;
        }    
        else if (child2 == 0)
        {
            PID2 = getpid(); //variable stores in second child 
            printf("I am child two, my pid is: %i \n", PID2);
        }
    }
    return 0;
}