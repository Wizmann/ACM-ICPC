#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int num[3];
	for(int i=0;i<3;i++) scanf("%d,",&num[i]);
	qsort(num,3,sizeof(int),cmp);
	printf("%d\n",(num[0]+num[1])*num[2]);
	return 0;
}