#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
void signal_handler (int signum){
   if (signum == SIGCHLD)
      puts ("SIGCHLD received");
}
int main() {
    pid_t second, third;
    const char *sp = "./second";
    const char *tp = "./third";
signal (SIGCHLD, signal_handler);
    third = fork();
    if (third == 0) {
        printf("[Main process] Third process started\n");
        execv(tp, NULL);
        exit(1);
    }
    second = fork();
    if (second == 0) {
        printf("[Main process] Second process started\n");
        execv(sp, NULL);
        exit(1);
    }
    return 0;
}
