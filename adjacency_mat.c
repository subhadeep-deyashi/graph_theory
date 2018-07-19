#include<stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp, *ft;
	fp = fopen("g.txt", "r");
	int a[5][5];
	int v, i, j;
	if(fp == NULL)
		exit(0);
	fscanf(fp, "%i", &v);
	printf("\n%i\n", v);
	for(i = 0; i < v; ++i)
	{
		for(j = 0; j < v; ++j)
		{
			fscanf(fp, "%i", &a[i][j]);
		}
	}
	for(i = 0; i < v; ++i)
	{
		for(j = 0; j < v; ++j)
		{
			printf("%i ", a[i][j]);
		}
		printf("\n");
	}
	ft = fopen("output.txt", "w");
	for(i = 0; i < v; ++i)
	{
		for(j = 0; j < v; ++j)
		{
			fprintf(ft, "%i ", a[i][j]);
		}
		fprintf(ft, "\n");
	}
	fclose(fp);
	fclose(ft);
	return 0;
}
