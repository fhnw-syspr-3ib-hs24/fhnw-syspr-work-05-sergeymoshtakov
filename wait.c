#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){
    printf("main()\n");
    pid_t res = fork();
    if(res == 0){ // child
        printf("child\n");
        sleep(1); // s
        exit(-1);
    }

    // parent
    int status;
    wait(&status); // blocking
    printf("parent, child done, status = %d\n", (signed char) WEXITSTATUS(status));
    return 0;
}