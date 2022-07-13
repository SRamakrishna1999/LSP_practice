#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	int ret;
	ret=write(-1,"Hello world\n",12);
	
	printf("ret=%d	errno=%d\n",ret,errno);

	if(ret<0)
	{
		perror("write error:");
		exit(0);
	}
	return 0;
}
