#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 100;
	int pid = fork();

	if(pid == 0)
	{
		printf("child process's value of x = %d\n",x);
		printf("change the value of x to 10 in child process\n");
		x = 10;
	}
	else
	{
		printf("change the value of x to 1 in parent process\n");
		x = 1;
	}

	printf("the final value of x = %d\n",x);

	return 0;
}
