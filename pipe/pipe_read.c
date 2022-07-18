#include <unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int arr[2];
	char buff[10];
	read(arr[0],buff,strlen(buff)+1);
	printf("conent is :%s\n",buff);
}
