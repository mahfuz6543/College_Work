#include <stdio.h>
#include <unistd.h>
#include <errno.h> 

int main (int argc, char* argv[]) 
{ 
    char* filepath = argv[1]; 
    int returnval; 
    
    //Check if file can be accessed and if it exists
    returnval = access (filepath, F_OK); 
    if (returnval == 0)
        printf ("\n %s exists\n", filepath); 
    else { 
        if (errno == ENOENT) //if there is issues, checks errno with ENOENT and outputs the error
            printf ("%s does not exist\n", filepath); 
        else if (errno == EACCES) //if there is issues, checks errno with EACCES and outputs the error
            printf ("%s is not accessible\n", filepath); 
        return 0;
    } 
    
    // Check read access with filepath and if it has read permission
    returnval = access (filepath, R_OK);
    if (returnval == 0)
        printf ("\n %s read permissions is accessible \n" , filepath);
    else { 
        if (errno == ENOENT)
            printf ("%s does not exist\n", filepath); 
        else if (errno == EACCES)
            printf ("%s read permissions is not accessible\n", filepath); 
        return 0;
    } 

    // Check write access with filepath and if it has write permission
    returnval = access (filepath, W_OK); 
    if (returnval == 0)
        printf ("\n %s write permissions is accessible \n" , filepath);
    else { 
        if (errno == ENOENT)
            printf ("%s does not exist\n", filepath); 
        else if (errno == EACCES)
            printf ("%s write permissions is not accessible\n", filepath); 
        return 0;
    } 

    return 0;
}