#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int sour,dest;
	char buff[10];
	int byte;
	
	sour=open(argv[1],O_RDONLY);
	dest=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while(byte=read(sour,buff,1)>0)
	{
		write(1,buff,byte);
	}
}

