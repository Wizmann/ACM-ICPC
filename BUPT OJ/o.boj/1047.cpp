#include <stdio.h>
#include <string.h>

int FT[42];

int main()
{
	//freopen("input.txt","r",stdin);
	memset(FT,-1,sizeof(FT));
	int num;
	while(scanf("%d",&num)==1)
	{
		int temp=num%42;
		FT[temp]++;
	}
	int sum=0;
	for(int i=0;i<42;i++)
	{
		if(FT[i]!=-1) sum++;
	}
	printf("%d\n",sum);
	return 0;
}