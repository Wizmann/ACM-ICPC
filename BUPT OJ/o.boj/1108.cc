#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

int father[N];
int bug[N];

int find(int n)
{
	if(n==father[n]) return n;
	else return father[n]=find(father[n]);
}

void set(int a,int b)
{
	int ta=find(a);
	int tb=find(b);
	
	father[ta]=tb;
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num,ask;
		scanf("%d%d",&num,&ask);
		
		for(int j=1;j<=num;j++) father[j]=j;
		memset(bug,0,sizeof(bug));
		
		int hand1,hand2;
		int sus=0;
		while(ask--)
		{
			scanf("%d%d",&hand1,&hand2);
			if(!sus)
			{
				if(find(hand1)==find(hand2)) sus++;
				else
				{
					if(bug[hand1]) set(bug[hand1],hand2);
					else if(bug[hand2]) set(hand1,bug[hand2]);
					else
					{
						bug[hand1]=hand2;
						bug[hand2]=hand1;
					}
				}
			}
		}
		
		printf("Scenario #%d:\n",i+1);
		if(sus) printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		printf("\n");	
	}
	return 0;
}