#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prim(int n)
{
	if(n==1) return 0;
	else if(n!=2&&n%2==0) return 0;
	else if(n!=3&&n%3==0) return 0;
	else
	{
		for(register int i=3;i*i<=n+1;i+=2)
		{
			if(n%i==0) return 0;
		}
		
		return 1;
	}
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int up,down;
	scanf("%d%d",&up,&down);
	
	int counter;
	scanf("%d",&counter);
	
	int temp;
	
	while(counter--)
	{
		scanf("%d",&temp);
		if(temp>=up&&temp<=down)
		{
			if(prim(temp)) printf("YES\n");
			else printf("NO\n");
		}
		else printf("ERROR\n");
	}
	
	return 0;
}