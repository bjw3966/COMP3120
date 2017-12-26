#include <stdio.h>
#include <stdlib.h>

int main()
{
	int wait_rv;

	int pid = fork();

	if(pid == 0)
	{
		printf("child wait\n");
		wait_rv = wait();
		printf("wait return : %d\n",wait_rv);
	}
	else
	{
		printf("parent execute\n");
	}
}
