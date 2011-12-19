//Result:wizmann	1321	Accepted	388K	79MS	G++	877B
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct point
{
	int x,y;
	inline void setpoint(int a,int b){x=a;y=b;}
}point;

char inx[10],iny[10];
char g[10][10];
int n,k,pad,ans;
point array[10];

void dfs(int pos=0,int in=0)
{
	if(in==k) ans++;
	else
	{
		for(int i=pos;i<pad;i++)
		{
			point t=array[i];
			if(inx[t.x]||iny[t.y]) continue;
			else
			{
				inx[t.x]=1;iny[t.y]=1;
				dfs(i+1,in+1);
				inx[t.x]=0;iny[t.y]=0;
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		pad=0,ans=0;
		scanf("%d%d",&n,&k);
		if(n+k<0) break;
		memset(g,0,sizeof(g));
		memset(inx,0,sizeof(inx));
		memset(iny,0,sizeof(iny));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=n;j++)
			{
				if(g[i][j]=='#') array[pad++].setpoint(j,i);
			}
		}
		
		dfs();
		printf("%d\n",ans);
	}
	return 0;
}
