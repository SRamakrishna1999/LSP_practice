#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
int fd1;
char * myfifo = "/tmp/myfifo";

char str1[80];
while(1)
{	
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);

        printf("file content: %s\n", str1);
    	close(fd1);
}

    return 0;
}
