#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int oret,rret,wret;
	char buff[4096];
	oret=open(argv[1],O_RDONLY);
	if(oret==-1)
	{
		perror("file not open :");
		printf("oret = %d	errno=%d\n",oret,errno);
		exit(0);
	}
	else
	{
		printf("file is successfully open\n");

		rret=read(oret,buff,4096);
		if(rret>=0)
		{
			printf("file is read successfully\n");
			wret=write(1,buff,rret);
			//printf("%d",wret);
			if(wret<0)
			{

				perror("write error :");
				printf("wret = %d	errno=%d\n",wret,errno);
				exit(0);
			}
			else
			{
				printf("file is successfully write\n");
			}

		}
		else
		{
			perror("read error:");
			printf("rret=%d		errno=%d",rret,errno);
			exit(0);
		}
	}
	
	close(oret);
	return 0;
}



