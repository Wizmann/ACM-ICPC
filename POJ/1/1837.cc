#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MID 7500

int bag[15050][25];
short hook[100];

int main()
{
	freopen("input.txt","r",stdin);
	int g,c,t;
	scanf("%d%d",&c,&g);
	for(int i=0;i<c;i++) scanf("%hd",&hook[i]);
	
	bag[MID][0]=1;
	for(int i=1;i<=g;i++)
	{
		scanf("%d",&t);
		for(int j=0;j<=15000;j++)
		{
			if(bag[j][i-1])
			{
				for(int k=0;k<c;k++) bag[j+t*hook[k]][i]+=bag[j][i-1];
			}
		}
	}
	
	printf("%d\n",bag[MID][g]);
	return 0;
}
