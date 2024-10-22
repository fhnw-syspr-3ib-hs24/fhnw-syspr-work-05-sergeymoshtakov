#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    printf("main()\n");
    pid_t res = fork();

    if(res == 0){ // child
        printf("child\n");
        exit(0);
    }

    // parent
    printf("parent\n");
    
    return 0;
}