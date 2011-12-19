#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dp[12000];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	while(counter--)
	{
		int n;
		double Rh,Ra,m,g;
		
		scanf("%d%lf%lf%lf%lf",&n,&Ra,&Rh,&g,&m);
		double fitV=-m*g/(Rh-Ra);
		
		memset(dp,0,sizeof(dp));
		int temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			dp[temp]=1;
			int *p=&dp[10000];
			while(p>=dp)
			{
				if(*p) 
				{
					if(*(p+temp))
				}*(p+temp)=1;
				p--;
			}
		}
		
		if(fitV-(int)fitV>1e-5)
		{
			int nr=(int)fitV+1;
			while(!dp[nr])
			{
				nr++;
			}
			printf("%d\n",nr);
		}
		else
		{
			int nr=(int)fitV;
			while(!dp[nr])
			{
				nr++;
			}
			printf("%d\n",nr);
		}
	}
	return 0;
	
}