#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <fcntl.h>

FILE *fp;
int totaltime = 0;
int main()
{
	char a[10] = "/proc/";
	char id[10];
	char c1[20], c2[20];
	int pid;
	int i;
	char trash[100] = {0,};
	int time;
	char t1[100] = {0,};

	pid=fork();
	if(pid == 0){
		printf("input processor id : ");
		scanf("%s",id);
	}

	strcat(a,id);
	strcpy(c1,a);
	strcat(c1,"/stat");

	strcpy(c2,a);
	strcat(c2,"/status");
	while(1){
	if(pid == 0)
	{
//		printf("input processor id : ");
//		scanf("%s",id);

//		strcat(a,id);
//		strcpy(c1,a);
//		strcat(c1,"/stat");
	
//		strcpy(c2,a);
//		strcat(c2,"/status");

		fp = fopen(c1,"r");

		for(i=0; i<13; i++)
		{
			fscanf(fp,"%s ",trash);
		}

		for(i=0; i<2; i++)
		{
			fscanf(fp,"%d ",&time);
//			printf("%d\n",time);
			totaltime += time;
		}

		printf("time : %d\n",totaltime * 100);
		fclose(fp);

		fp = fopen(c2,"r");

		while(!feof(fp))
		{
			fscanf(fp,"%s ",trash);
//			printf("%s\n",trash);
			if(strcmp(trash,"VmSize:") == 0)
			{
				fscanf(fp,"%s",trash);
				fscanf(fp,"%s",t1);
				break;
			}
		}

		printf("VmSize : %s ",trash);
		printf("%s\n",t1);

		fclose(fp);
		sleep(3);

	}
	else
		wait();
}

}
