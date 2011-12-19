//Result:Accepted	852K	16MS	G++	 1693B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef struct point
{
	int a,b,c;
	
	void setpoint(int m,int n,int o)
	{
		c=m;b=n;a=o;
	}		
}point;

char g[35][35][35];
int z,y,x;
point start,end;
int ans;
int val[35][35][35];
queue<point> q;

const int mx[]={1,-1,0,0,0,0};
const int my[]={0,0,1,-1,0,0};
const int mz[]={0,0,0,0,1,-1};

void bfs()
{
	val[start.c][start.b][start.a]=0;
	q.push(start);
	int a,b,c;
	point temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		a=temp.a;b=temp.b;c=temp.c;
		//printf("POS:%c\n",g[c][b][a]);
		if(g[c][b][a]=='E')
		{
			if(ans>val[c][b][a]) ans=val[c][b][a];
		}
		else
		{
			int ta,tb,tc;
			point next;
			for(int i=0;i<6;i++)
			{
				ta=a+mx[i];tb=b+my[i];tc=c+mz[i];
				if(ta>=0&&ta<x && tb>=0&&tb<y && tc>=0&&tc<z && g[tc][tb][ta]!='#' &&val[c][b][a]+1<val[tc][tb][ta])
				{
					val[tc][tb][ta]=val[c][b][a]+1;
					next.setpoint(tc,tb,ta);
					q.push(next);
				}
			}
		}
	}
}
				

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d%d",&z,&y,&x)!=EOF&&x&&y&&z)
	{
		while(!q.empty()) q.pop();
		ans=1<<20;
		memset(g,0,sizeof(g));
		for(int i=0;i<z;i++)
		{
			for(int j=0;j<y;j++)
			{
				for(int k=0;k<x;k++) val[i][j][k]=1<<20;
			}
		}
		
		for(int i=0;i<z;i++)
		{
			for(int j=0;j<y;j++)
			{
				scanf("%s",g[i][j]);
				for(int k=0;k<x;k++)
				{
					if(g[i][j][k]=='S') start.setpoint(i,j,k);
					else if(g[i][j][k]=='E') end.setpoint(i,j,k);
				}
			}
		}
		bfs();
		if(ans>=1<<20) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n",ans);
	}
	return 0;
}
