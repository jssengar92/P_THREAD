#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>

void * function(void *);
void handler(int );

int main()
{
	signal(SIGINT,handler);	/*Signal  handler for SIGINT(ctrl+c)*/
	pthread_t tid[10];
	int i=0,j;
	void *result;
	printf("Main thread is running\n");
	for(i=0;i<10;i++)
	{
		pthread_create(&tid[i],NULL,function,(void *)&i);
		sleep(1);
	}
	for(i=0;i<10;i++)
	{
		printf("Enter signal:");
		scanf("%d",&j);
		sleep(1);
		pthread_kill(tid[j],SIGINT);	/*kill signal to thread function*/
	}
	printf("Thread %d exit code:%s\n",i,((char *)result));
	
	
}
void * function(void *arg)
{
	signal(SIGINT,handler);
	int i;
	i=*(int *)arg;
	while(1)
	{
		printf("Thread %d is running\n",i);
		sleep(5);
	}
}
void handler(int sig)
{
	printf("Signal %d occur\n",sig);
	pthread_exit("bye");		
}


