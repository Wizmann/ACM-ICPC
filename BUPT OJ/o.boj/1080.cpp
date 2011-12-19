#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int c,n;
	scanf("%d%d",&c,&n);
	
	char *time=(char*)calloc(n+1,sizeof(char));
	while(c--)
	{
		int temp;
		scanf("%d",&temp);
		int start=0;
		while(start<=n)
		{
			time[start]++;
			start+=temp;
		}
	}
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(time[i]) sum++;
	}
	
	printf("%d\n",sum);
	
	return 0;
}