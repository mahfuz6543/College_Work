#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main (void){
    int a = 10, b = 25, fq = 0, fr = 0, wait, wait2;
    fq = fork();
//parent P
    if (fq == -1){ 
        printf("error fork was unsuccessful\n");
        return 1;
    }

    if(fq == 0){ //shows we are in child Q
        a = a + b; //stores it in a
        printf("Process Q a = %i, b = %i , PID = %i\n" , a, b, getpid());

        fr = fork();//forks second child inside child 1
        
        if (fr == -1){ //error in forking
            printf("error fork was unsuccessful\n"); //error message
            return 1;
        }

        else if (fr != 0){ //checks if we are not in child
            b = b + 20; //calculations for B
            printf("Process R a = %i, b = %i , PID = %i\n", a,b,getpid());
        }

        else{ 
            a=(a*b)+30; //calculations for child Q 
            printf("Process Q a = %i, b = %i , PID = %i\n", a,b,getpid());
        }
    }

    else{
        b=a+b-5;// parent process
        printf("a = %i, b = %i , PID = %i\n", a,b,getpid());
    }
    //wait for childs to terminate
    wait = waitpid(fq, NULL, 0); 
    wait2 = waitpid(fr, NULL, 0);
    return 0;
} 