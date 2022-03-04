#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
int main(int argc, char* argv[]){
	int pid;
	if (argc<7)
        {
		printf("Error");
		return 1;
        }
	pid=fork();
	if(pid==-1)
        {
        perror("fork");
        exit(1);
        }
	if(pid==0)
        {
		pid=fork();
	if(pid==-1)
        {
        perror("fork");
        exit(1);
        }
	if (pid==0)
        {
		execlp(argv[1],argv[1],argv[2],argv[3],NULL);
		execlp(argv[4],argv[4],argv[5],argv[6],NULL);
		perror("Error2");
		exit(1);
        }
        }
	wait(NULL);
	wait(NULL);
	return 0;
}
