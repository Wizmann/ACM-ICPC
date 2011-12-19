#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dp[250000];

int flag=1;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		int temp;
		char *p;
		int sum=0;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			p=&dp[250000];
			sum+=temp;
			while(p>=dp)
			{
				if(*p) *(p+temp)=1;
				p--;
			}
			dp[temp]=1;
		}
		
		int tsum=sum/2;
		while(tsum>0)
		{
			if(dp[tsum]) break;
			else tsum--;
		}
		
		printf("Case #%d:\n%d\n",flag++, 2*tsum-sum>0?2*tsum-sum:-2*tsum+sum );		
	}
	return 0;
}