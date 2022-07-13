#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("print present process state pid information\n");
	system("ps -eaf");
	exit(0);
}
