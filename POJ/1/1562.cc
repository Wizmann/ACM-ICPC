//Result:wizmann	1562	Accepted	184K	0MS	C++	654B
#include <cstdio>
#include <cstdlib>
#include <cstring>

char g[120][120];
int h,w;
const int mx[]={1,1,1,0,0,0,-1,-1,-1};
const int my[]={1,0,-1,1,0,-1,1,0,-1};

void clear(int y,int x)
{
	g[y][x]='*';
	for(int i=0;i<9;i++)
	{
		int tx=x+mx[i];
		int ty=y+my[i];
		if(g[ty][tx]=='@') clear(ty,tx);
	}
}
	

int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		int ans=0;
		scanf("%d%d",&h,&w);
		if(h==0) break;
		for(int i=0;i<h;i++)
		{
			scanf("%s",g[i]);
		}
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(g[i][j]=='@')
				{
					ans++;
					clear(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
	
