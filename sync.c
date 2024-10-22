#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void handle(int sig) {
//    switch (sig) ...
}

int main(void) {
    printf("main()\n");
    signal(SIGUSR1, handle);
    signal(SIGCHLD, handle);
    pid_t res = fork();
    if (res == 0) { // child
        printf("child\n");
        pid_t ppid = getppid();
        kill(ppid, SIGUSR1);
        sleep(1); // do some work
        kill(ppid, SIGUSR1);
        sleep(1); // do more work
        exit(0); // sends SIGCHLD
    }
    // parent
    printf("parent\n");
    pause(); // blocking
    printf("0%%\n");
    pause(); // blocking
    printf("50%%\n");
    //wait(NULL); // blocking
    pause(); // blocking
    printf("100%%\n");
    return 0;
}


