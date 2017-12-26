#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

int count = 0;
int l = FALSE;

int test_and_set(int *target)
{
	int rv = *target;
	*target = TRUE;
	return rv;
}
void *mythread(void *arg)
{
	int i;

	for(;;)
	{

		if(count >= 10000)
			return NULL;
		count++;
	}

	return NULL;
}
void *mythread_lock(void *arg)
{
	int i;
	do{
		while(test_and_set(&l));
		for(;;)
		{

			if(count >= 10000){
				l = FALSE;
				return NULL;
			}
			count++;
		}
	}while(TRUE);
		

	return NULL;
}


int main()
{
	struct timeval t;
	int num;
	int presec,preusec,postsec,postusec;
	int time;
	int sus,fus;
	pthread_t *p;
	int i;
	int lock;

	gettimeofday(&t,NULL);
	presec = t.tv_sec;
	preusec = t.tv_usec;

	sus = presec*1000000 + preusec;

	printf("0 : no lock\n");
	printf("1 : use lock\n");
	printf("input 0 or 1 : ");
	scanf("%d",&lock);

	switch(lock)
	{
		case 0 :
			printf("input number of thread(0 ~  : ");
			scanf("%d",&num);

			if(num == 0)
			{	
				while(1)
				{
					count++;
					if(count >= 10000000)
					{
						gettimeofday(&t,NULL);
						postsec = t.tv_sec;
						postusec = t.tv_usec;
						fus = postsec*1000000 + postusec;
						printf("%d\n",count);
						printf("%d\n",fus - sus);
						return 0;
					}
				}
			}
			else
			{
				p = (pthread_t*)malloc(sizeof(pthread_t)*num);

				for(i=0; i<num; i++)
					pthread_create(&p[i],NULL,mythread,NULL);
				for(i=0; i<num; i++)
					pthread_join(p[i],NULL);

				gettimeofday(&t,NULL);
				postsec = t.tv_sec;
				postusec = t.tv_usec;

				fus = postsec*1000000 + postusec;
				printf("%d\n",count);
				printf("%d\n",fus - sus);
				return 0;
			}
			break;

		case 1 :
			printf("input number of thread(0 ~  : ");
			scanf("%d",&num);

			if(num == 0)
			{	
				while(1)
				{
					count++;
					if(count >= 10000000)
					{
						gettimeofday(&t,NULL);
						postsec = t.tv_sec;
						postusec = t.tv_usec;
						fus = postsec*1000000 + postusec;
						printf("%d\n",count);
						printf("%d\n",fus - sus);
						return 0;
					}
				}
			}
			else
			{
				p = (pthread_t*)malloc(sizeof(pthread_t)*num);

				for(i=0; i<num; i++)
					pthread_create(&p[i],NULL,mythread_lock,NULL);
				for(i=0; i<num; i++)
					pthread_join(p[i],NULL);

				gettimeofday(&t,NULL);

				postsec = t.tv_sec;
				postusec = t.tv_usec;
				fus = postsec*1000000 + postusec;
				printf("%d\n",count);
				printf("%d\n",fus - sus);
				return 0;
			}
			break;
	}
	return 0;
}

