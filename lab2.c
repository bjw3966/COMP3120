#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
	int n;
	char test[100];
	FILE *fp;
	FILE *fp1;

	fp = fopen("in.txt","r");
	fp1 = fopen("out.txt","w");

	fscanf(fp,"%s",test);
	fprintf(fp1,"%s",test);

	return 0;
}

