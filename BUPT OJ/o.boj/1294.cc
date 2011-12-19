#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int time=1;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter;
	scanf("%d",&counter);
	int bag,people;
	while(counter--)
	{
		printf("Case %d:\n",time++);
		scanf("%d%d",&bag,&people);
		int money=0,temp;
		int i,ans=0;
		for(i=1;i<=bag;i++)
		{
			scanf("%d",&temp);
			if(ans) continue;
			money+=temp;
			money%=people;
			if(money==0) ans=i;
		}
		
		if(!money)
		{	
			printf("Need %d bag",ans);
			if(ans==1) printf("\n");
			else printf("s\n");
		}
		else printf("Bad boy\n");
	}
	return 0;
}
		 	
		
		
