#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		printf("fork is fail\n");
		exit(0);
	}
	if(pid==0)
	{
		printf("children process pid = %d\n",getpid());
		printf("parent process pid =%d\n",getppid());
	}
	/*
	else
	{
		printf("process pid =%d\n",getpid());
		printf("parent process pid =%d\n",getppid());
	}*/
	return 0;

}

