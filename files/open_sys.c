
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>

int main()
{
	int ret;
	char buff[10];
	ret=open("abc",O_RDONLY);
	printf("ret = %d    errno=%d\n",ret,errno);
	if(ret==-1)
	{
		perror("file not open:");
		//printf("ret = %d    errno=%d\n",ret,errno);
	}
	else
	{
		printf("file is open\n");
		close(ret);

	}
	return 0;
}

