#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
int main(int argc, char* argv[])
{
	int pid, fd[2], i=0;
	char c[5];
	if (argc<2)
        {
		printf("Error");
		return 1;
        }
          pipe(fd);
        fd[0]=open(argv[1], O_CREAT | O_TRUNC | O_RDWR);
        fd[1]=open(argv[2], O_CREAT | O_TRUNC | O_RDWR);
        dup2(fd[0], 0);
        dup2(fd[1], 1);
	pid=fork();
	if(pid==-1)
        {
        perror("fork");
        exit(1);
        }
	if(pid==0)
        {
			for(i=0;i<4;i++)
			c[i]=getchar();
			close(fd[0]);
        }
	wait(NULL);;
	for(i=0;i<5;i++)
	putchar(c[i]);
	close(fd[1]);
	return 0;
}
