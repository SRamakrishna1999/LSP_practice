#include<stdio.h>
#include <unistd.h>
#include<string.h>

int main()
{
	int ret,arr[2];
	char buff[20];

	ret=pipe(arr);
	if(ret==-1)
	{
		printf("pipe is not created\n");
	}
	else
	{
		printf("pipe is created\n");
		printf("please enter string\n");

		scanf("%s",buff);

		write(arr[1],buff,strlen(buff)+1);

		read(arr[0],buff,strlen(buff)+1);

		printf("content :%s\n",buff);
	}
}
