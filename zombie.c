#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle(int sig){
    wait(NULL);
}

int main(void){
    signal(SIGCHLD, handle);
    printf("main()\n");
    pid_t res = fork();
    if(res == 0){ // child
        printf("child\n");
        exit(0);
    } // SIGCHLD
    // parent
    printf("parent\n");
    pause();
    sleep(10);
    return 0;
}