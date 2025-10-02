#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
 
int main(int argc, char *argv[]) 
{ 
        if(argc >= 1) 
        { 
                int  i; 
 
                for(i = 1; i < argc - 1; i++) 
                { 
                        write(1, argv[i], strlen(argv[i])); 
                        write(1, " ", 1); 
                } 
 
                write(1, "\n", 1); 
        } 
 
        else 
        { 
                write(1, "\n", 1);  
        } 
} 
