#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd,fret;
	char * myfifo = "/tmp/myfifo";

	fret=mkfifo(myfifo, 0666);
	while(1)
		{
			char arr1[80];
			// Open FIFO for write only
			fd = open(myfifo, O_WRONLY);

			fgets(arr1, 80, stdin);

			write(fd, arr1, strlen(arr1)+1);
			close(fd);
		}
		return 0;
	
}
