#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include<stdlib.h>

struct mesg
{
        long int type;
        char msg[20];
};

int main()
{
        struct mesg message;
        int qid,n;
	key_t key=555;
        qid=msgget(key,0666);
        if(qid<0)
        {
                perror("message id is not created:");
                printf("qid = %d        errno = %d\n",qid,errno);
		exit(0);
        }

       // message.type=123;
       // message.msg="welcom";
        if((n=msgrcv(qid,&message,20,0,0))<0)
        {
                perror("message is not send:");
                printf("n = %d        errno = %d\n",n,errno);
		exit(0);
        }
	printf("message is receive\n");
	printf("message type integer data = %ld\n",message.type);
	printf("message data = %s\n",message.msg);


}


