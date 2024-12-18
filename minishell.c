#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PROMPTSIZE 255

int main(void){
    char input[PROMPTSIZE +1] = { 0x0 };
    fgets(input, PROMPTSIZE, stdin);
    input[strlen(input) -1]='\0';
    execvp(input, (char*[]){input, NULL});

    if(strcmp(input, "exit") == 0){
        exit(0);
    }

}
