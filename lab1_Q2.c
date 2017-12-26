#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int pid;
	
	int des;

	char *buf1 = "1111111111111111111111111111111111111111111\n";
	char *buf2 = "2222222222222222222222222222222222222222222\n";

	des = open("./Q2.txt",O_RDWR);
	pid = fork();

	if(pid == 0)
	{

		printf("the file descriptor fo child = %d\n",des);
		write(des, buf1, strlen(buf2));
	}
	else
	{
		printf("the file descriptor fo parent = %d\n",des);
		write(des, buf2, strlen(buf1));
	}

	return 0;
}
