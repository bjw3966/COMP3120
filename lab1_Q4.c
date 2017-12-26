#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid = fork();
	char *argv[3] = {"command-line",".",NULL};

	if(pid == 0)
		execvp("ls",argv);

	return 0;
}
