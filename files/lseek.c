#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{

	int ropen,rread,rwrite,ret;
	int buff[100];
	ropen=open("abc",O_RDONLY);
	if(ropen<0)
	{
		perror("file is not open:");
		printf("ret=%d	errno=%d\n",ropen,errno);
		exit(0);
	}
	else
	{
		printf("file is successfully open\n");
		rread=read(ropen,buff,7);
		printf("present reading charecters is = %d\n",rread);
		//rwrite=write(1,buff,rread);
		//ret=lseek(ropen,10,SEEK_SET);
		ret=lseek(ropen,4,SEEK_CUR);
		//ret=lseek(ropen,0,SEEK_END);
		printf("present curser position is = %d\n",ret);
		rwrite=write(ropen,"jony",4);
		//rread=read(ropen,buff,ret);
		//write(1,buff,ret);
		close(ropen);
	}
	return 0;

}

