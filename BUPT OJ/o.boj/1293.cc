#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 1010

const int mx[3]={-1,0,1};

int g[N][N];
int t[N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int x,y,pos;
	while(scanf("%d%d",&y,&x)!=EOF&&y&&x)
	{
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++) scanf("%d",&g[i][j]);
		}
		
		for(int i=0;i<y-1;i++)
		{
			memset(t,-1,sizeof(t));
			for(int j=0;j<x;j++)
			{
				for(int k=0;k<3;k++)
				{
					pos=j+mx[k];
					if(pos>=0&&pos<x)
					{
						if(t[pos]<0||t[pos]>g[i][j]+g[i+1][pos])
						{
							t[pos]=g[i][j]+g[i+1][pos];
						}
					}
				}
			}
			memcpy(g[i+1],t,sizeof(t));
		}
		
		int ans=1<<20;
		for(int i=0;i<x;i++)
		{
			if(g[y-1][i]<ans) ans=g[y-1][i];
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
					
			
		
		
