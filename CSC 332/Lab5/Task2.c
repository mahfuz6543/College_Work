#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/wait.h>
#include <string.h>
#include <errno.h>


int main(void){
    char* filepath = "grades.txt"; //read text file
    int spaces=0, newline=0, newspace=0, fd;
    int students=0, managers=0, workers=2, columns=0, average=0;
    int managerfd=0, workersfd=0;
    int i=0, j=0;
    char str[100];
    char buffer[fd]; //buffer to hold all read 

    FILE* file = fopen("grades.txt", "r"); //opens the file 
    fd = open (filepath, S_IRUSR|S_IWUSR);
    if (fd == -1){ //if file descriptor returns error, print out error messege
        printf("\n open() failed [%s]\n",strerror(errno)); 
        return 1; 
    }
    else{
        printf("\n file can be opened\n");
        read (fd,buffer,sizeof(buffer)); //reads through all the file and inputs it into a buffer

        while (i<sizeof(buffer)){ //used to count how many newline
            if (buffer[i]=='\n'){
                newline++;
            } 
            i++;
        }
        
        while (i<sizeof(buffer)){ //used to count how many spaces
            if (buffer[i]==' '){
                spaces++;
            } 
            i++;
        }
        spaces=spaces/(newline + 1);
        columns=spaces+1;
        int columnDecrement=columns;
        managers=columns/2;
        int managerDecrement=managers;
        students=newline+1;
        int stringStore;
        char *tempBuffer[2]={0,0};
        int scoreArray[columns][students];//creating 2d array to store all grades
        for (int a=0; a<students; a++){
            for (int b=0; b<columns; b ++){
                fscanf(file, "%i", &scoreArray[a][b]);
                printf("%i", scoreArray[a][b]);
            }
        }       
        for(int x=0; x<managers; x++){ //loops throught number of managers
            managerfd=fork();//create number of managers based on the amount needed
            if (managerfd==-1){
                 printf("\n fork() failed with error [%s]\n",strerror(errno)); 
                return 1; 
            }
            if (managerfd==0){
                for (int y=0; y<workers; y++){
                    workersfd=fork();
                    if (workersfd==-1){
                        printf("\n fork() failed with error [%s]\n",strerror(errno)); 
                        return 1; 
                    }
                    if (workersfd==0){
                        int total=0, average=0;
                        for (int rowValue=0; rowValue<students; rowValue++){
                            total=scoreArray[rowValue][y];
                        }
                        average=total/students;
                        sprintf(tempBuffer, "%i", average); //avg
                        printf ("Homework : %i, ", average); //homework grades

                    } 

                }
                while (columns>0){ //column childs the complete
                    wait(NULL);
                    columnDecrement--;
                }
            }
        }
        while (managers>0){//manager childs the complete
            wait(NULL);
            managerDecrement--;
        }
        return 0;
    }
}