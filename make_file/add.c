#include<stdio.h>
void fun();
extern int hello;
void fun()
{
//printf("hii\n");
hello=hello+10;
printf("%d",hello);
}
