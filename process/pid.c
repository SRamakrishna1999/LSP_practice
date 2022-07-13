#include <unistd.h>
#include <sys/types.h>
#include<stdio.h>
int main()
{
	printf("prosess id = %d\n",getpid());

	printf("parent procsss id = %d\n",getppid());
}

