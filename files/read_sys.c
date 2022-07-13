#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


int main()
{
	int ret;
	char buff[100];

	ret = read(0,&buff,10);

	if(ret<0)
	{
		perror("read error:");
		printf("errno=%d\n",errno);
		exit(0);
	}
	printf("ret=%d	data=%s\n",ret,buff);
	return 0;
}
