#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int g = 0;

int main(void){
    printf("main()\n");
    pid_t res = fork();
    g++;
    if(res == 0){ // child
        printf("child\n");
        g++;
        exit(0);
    }

    // parent
    printf("parent, %d\n", g);
    
    return 0;
}