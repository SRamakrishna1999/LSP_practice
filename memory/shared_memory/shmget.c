#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
int main()
{
	key_t key=10;
	int shm_id;
	shm_id=shmget(key,1024,0666 | IPC_CREAT);
	printf("%d\n",shm_id);
	if(shm_id<0)
	{
		perror("shared memory id is not created:");
		printf("shm_id = %d	errno = %d\n",shm_id,errno);
		exit(0);
	}
	printf("shared memory id is successfully created\n");
}
