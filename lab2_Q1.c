#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
	struct timeval t;

	gettimeofday(&t,NULL);
	printf("%d : %d\n",t.tv_sec,t.tv_usec);
	//this timer can measure up to usec
	return 0;
}
