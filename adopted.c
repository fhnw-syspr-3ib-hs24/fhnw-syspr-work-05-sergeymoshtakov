#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    printf("main()\n");
    pid_t res = fork();
    if(res == 0){ // child
        printf("child, ppid = %d\n", getppid());
        sleep(1);
        printf("child, ppid = %d\n", getppid());
        exit(0);
    }

    // parent
    printf("parent\n");
    
    return 0;
}