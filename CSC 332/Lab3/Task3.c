#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int value = atoi(argv[1]); //converting char to int

    if (argc != 2){ //error if there is more than 2 args
        printf ("error: there can be only one parameter");
        return 1;
    }

    int fq = 0, fr = 0, wait, wait2, total = 0, oddTotal =0, evenTotal=0;
    fq = fork(); //forks first child

    if (fq == -1){ //error if fork fails
        printf("fork was unsuccessful\n"); 
        return 1;
    }

    if(fq == 0){
        printf("number of values:"); //message to show values
        for (int i = 2; 
            i <= value; 
            i +=2){ //outputting all the even values lower or equal to input
            printf("%i ", i); //added values
            evenTotal = evenTotal + i;
        }
        printf("\n%i\n",evenTotal); //outputs the even sum

    }
    
    if(fq > 0){ 
        wait = waitpid(fq, NULL, 0); 
        fr = fork();
        
        if (fr == -1){ //checks error in forking
            printf("fork was unsuccessful\n"); //error message
            return 1;
        }

        if(fr == 0){//process in second child
            printf("Adding the following odd values:");
            for (int i = 1; 
                i <= value; 
                i +=2){ //increment through each odd number that is either less than or equal to the input
                printf("%i ", i);
                oddTotal = oddTotal + i;
            }
            printf("\n%i \n",oddTotal); //total output
        }

        if (fr > 0){ 
            wait2 = waitpid(fr, NULL, 0);
            printf("Adding the all the values lower than the input:"); 
            for (int i = 1; 
                i <= value; 
                i++){
                printf("%i ", i); //prints all the values
                total = total + i; //adds total
            }
            printf("\n%i\n",total); //total output
        }

    }
    return 0; 
}