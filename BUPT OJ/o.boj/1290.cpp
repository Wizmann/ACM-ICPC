#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lineA[1010];
char lineB[1010];

int main()
{
	//freopen("input.txt","r",stdin);
	
	memset(lineA,0,sizeof(lineA));
	memset(lineB,0,sizeof(lineB));
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		lineA[a]++;lineB[b]++;
	}
	int sum=0;
	for(int i=0;i<1010;i++)
	{
		if(lineA[i]>lineB[i]) sum+=lineA[i];
		if(lineA[i]<lineB[i]) sum+=lineB[i];
		if(lineA[i]==lineB[i]) sum+=lineB[i];
	}
	printf("%d\n",sum);
	return 0;
}