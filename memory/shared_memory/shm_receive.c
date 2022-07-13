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
	char *shm_at;
        shm_id=shmget(key,1024,0666);
        if(shm_id<0)
        {
                perror("shared memory id is not created:");
                printf("shm_id = %d     errno = %d\n",shm_id,errno);
                exit(0);
        }
        printf("shared memory is successfully created\n");
        shm_at=(char *)shmat(shm_id,NULL,0);
        if(shm_at ==(char *)-1)
        {
                perror("attach is failed:");
                printf("str = %d     errno = %d\n",shm_id,errno);
                exit(0);
        }
	printf("data is : %s\n",shm_at);
	
        printf("receive data\n");
	*shm_at='*';
        shmdt(shm_at);
	return 0;

}

