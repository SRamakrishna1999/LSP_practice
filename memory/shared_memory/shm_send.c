#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <sys/types.h>
#include<unistd.h>

int main()
{
	int shm_id;
	key_t key=123;
	char *shm_at,*s;
	shm_id=shmget(key,1024,0666 | IPC_CREAT);
	if(shm_id<0)
	{
		perror("shared memory id is not created:");
		printf("shm_id = %d	errno = %d\n",shm_id,errno);
		exit(0);
	}
	printf("shared memory is successfully created :%d\n",shm_id);

	shm_at= shmat(shm_id,NULL,0);
	printf("hiii\n");
	if(shm_at ==((char *)-1))
	{
		perror("attach is failed:");
                printf("str = %d     errno = %d\n",shm_id,errno);
                exit(0);
	}
	s=shm_at;
	char str1[10]="siva";
	int i=0;
	for(i=0;str1[i]!='\0';i++)
	{
		*s=str1[i];
		s++;
	}
	//printf("sending data\n");
	while(*shm_at!='*')
	{
		sleep(1);
		printf("sending data\n");
	}
	//printf("data successfully read\n");
	shmdt(shm_at);
	return 0;
}
