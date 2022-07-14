#include<stdio.h>
#include<unistd.h>
#include<errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<stdlib.h>

char buf[4096];
int main(int argc,char *argv[])
{
	int ret,i=1;
//        char buf[4096];
	while(argv[i])
	{
	ret=open(argv[i],O_RDONLY);
	if(ret<0)
	{
		printf("ret=%d  errno=%d\n",ret,errno);
		exit (0);
	}
		read(ret,buf,4096);
		write(1,buf,4096);
		i++;
	}
	 close(ret);

}
