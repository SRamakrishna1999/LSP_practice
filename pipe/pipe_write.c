#include <unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int piperet,arr[2];
	char buff[20];
	piperet=pipe(arr);
	
	if(piperet==0)
	{
		printf("pipe is successsfully created\n");
		printf("please enter string\n");
		scanf("%s",buff);
		write(arr[1],buff,strlen(buff)+1);
	}
	else
		printf("pipe is not created\n");
}
		
