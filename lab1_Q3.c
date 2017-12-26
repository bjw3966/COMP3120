#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int pid = fork();
	int i,j,k;


	if(pid == 0){
		printf("hello\n");
	}
	else{
		for(i=0; i<1000000;i++);
		for(j=0; j<1000000;j++);
		for(k=0; k<1000000;k++);
		printf("goodbye\n");
	}

	return 0;
}

