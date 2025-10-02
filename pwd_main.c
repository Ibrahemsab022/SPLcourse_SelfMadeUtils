#include <stdio.h> 
#include <unistd.h> 
 
#define BUFFER_SIZE 1024 
 
char buffer[BUFFER_SIZE]; 
char *dir = NULL; 
 
int main() 
{ 
        *dir = getcwd(buffer, BUFFER_SIZE); 
        printf("current dir is: %s\n", *dir); 
 
        return 0; 
} 
