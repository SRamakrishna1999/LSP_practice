#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include<string.h>
#include<stdlib.h>

struct mesg
{
	long int type;
	char msg[20];
};

int main()
{
	struct mesg message;
	char buff[20]="welcom";
	int qid,n;
	key_t key=555;

	qid=msgget(key,0666);
	if(qid<0)
	{
		perror("message id is not created:");
		printf("qid = %d	errno = %d\n",qid,errno);
		exit(0);
	}

	message.type=123;
	printf("please enter message data\n");
	scanf("%s",message.msg);
	//strcpy(message.msg,buff);
	//message.msg[20]="welcom";
	if((n=msgsnd(qid,&message,20,0))<0)
	{
		perror("message is not send:");
                printf("n = %d        errno = %d\n",n,errno);
	}
	printf("message is sent\n");
	return 0;

}









