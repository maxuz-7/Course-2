#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
int pid;
int temp;
void handler(int sig){
	
	if(pid == getppid()){
		printf("Son\n");
		signal(SIGUSR1,handler);
		kill(getppid(),SIGUSR1);
	}
	else
	if(pid == temp){
		printf("Father\n");
		signal(SIGUSR1,handler);
		kill(pid,SIGUSR1);
	}	
}
void MyAlarm(int sig){
	printf("Son exit\n");
	exit(0);
}

int main(int argc, char **argv)
{
	signal(SIGUSR1,handler);	
	if (!(temp = fork())){
		pid = getppid();
		signal(SIGALRM, MyAlarm);
		alarm(3);
		kill(getppid(),SIGUSR1);
		while(1);
	}
	pid = temp;
	while(wait(NULL) == -1);
	while(1){
		printf("Father\n");
		sleep(1);
	}
	return 0;
}

