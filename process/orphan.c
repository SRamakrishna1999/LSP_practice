#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{  
    int pid = fork();
 	printf("%d\n",pid);

    if (pid > 0)
        printf("in parent process\n");
  
    else if (pid == 0)
    {
        sleep(15);
        printf("in child process\n");
    }
  
    return 0;
}
