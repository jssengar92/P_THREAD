#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
void * fun(void *arg);
char msg[]="Hello World";
int main()
{
	pthread_t pid;
	int ret;
	void *exit1;
	printf("%s:Pid=%d Ppid=%d\n",__func__,getpid(),getppid());
	ret=pthread_create(&pid,NULL,fun,(void *)msg);
	if(ret==-1)
	{
		perror("pthread_create");
		goto OUT;
	}
	printf("Thraed created tid=%d\n",pid);
	printf("Thraed created Thread_self id is=%d\n",pthread_self());
	printf("Thread is waiting to finish\n");
	pthread_join(pid,&exit1);
	printf("Exit code is %s\n",exit1);
	printf("Now the message is %s\n",msg);
	return 0;
OUT:
	return -1;
}
void * fun(void *arg)
{
	printf("Fun thread is running\n");
	printf("Thraed created Thread_self id is=%d\n",pthread_self());
	printf("%s:Pid=%d Ppid=%d\n",__func__,getpid(),getppid());
	printf("Message is %s\n",(char *)arg);
	sleep(3);
	strcpy(msg,"Hello India");
	pthread_exit("Thanku SweetHeart for CPU time");
}
