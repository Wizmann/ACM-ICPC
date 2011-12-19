//Result:Wizmann	3026	Accepted	856K	63MS	G++	3247B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int mx,my;
char word[125];
int maze[125][125];
int g[125][125];
int pos[55][55];
int dis[125];
char mark[55][55];
char used[125];
int n;

const int mtx[]={1,-1,0,0};
const int mty[]={0,0,1,-1};

typedef struct node
{
	int x,y;
	int step;
	
	void setnode(int a,int b,int c)
	{
		x=a;y=b;step=c;	
	}
	
	friend bool operator < (const node a,const node b)
	{
		return a.step<b.step;
	}
}node;

typedef struct alien
{
	int x,y,nr;
	
	void setalien(int a,int b,int c)
	{
		x=a;y=b;nr=c;
	}
}alien;

alien mat[125];

void bfs(int nr,int x,int y)
{
	int finish=0;
	memset(mark,0,sizeof(mark));
	for(int i=0;i<my+5;i++)
	{
		for(int j=0;j<mx+5;j++) pos[i][j]=1<<20;
	}
	node start;
	start.setnode(x,y,0);
	mark[y][x]=1;
	queue<node> q;
	q.push(start);
	while(!q.empty())
	{
		node t=q.front();
		if(finish==n-1) break;
		if(pos[t.y][t.x]>t.step)
		{
			pos[t.y][t.x]=t.step;
			if(maze[t.y][t.x]>0) finish++;
		}
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=t.x+mtx[i];
			int ty=t.y+mty[i];
			if(tx>=0&&tx<mx  &&  ty>=0&&ty<my  &&  maze[ty][tx]!=-1 && !mark[ty][tx])
			{
				mark[ty][tx]=1;
				node p;
				p.setnode(tx,ty,1+t.step);
				q.push(p);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		if(pos[mat[i].y][mat[i].x]<g[nr][mat[i].nr])
		{
			g[nr][mat[i].nr]=g[mat[i].nr][nr]=pos[mat[i].y][mat[i].x];
			//printf("%d %d %d\n",nr,mat[i].nr,g[nr][mat[i].nr]);
		}
	}
}

int dij()
{
	for(int i=1;i<=n;i++) dis[i]=1<<20;
	
	memset(used,0,sizeof(used));
	int nr=1;
	dis[nr]=0;
	for(int i=1;i<=n;i++)
	{
		int minc=1<<20;
		for(int j=1;j<n;j++)
		{
			if(!used[j]&&dis[j]<minc)
			{
				nr=j;
				minc=dis[j];
			}
		}
		used[nr]=1;
		for(int j=1;j<n;j++)
		{
			if(!used[j]&&nr!=j&&dis[j]>g[nr][j]) dis[j]=g[nr][j];
		}
	}
	int sum=0;
	for(int i=1;i<n;i++) sum+=dis[i];
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&mx,&my);
		memset(maze,0,sizeof(maze));
		memset(pos,0,sizeof(pos));
		memset(g,0,sizeof(g));
		n=1;
		for(int i=0;i<my;i++)
		{
			bool re=true;
			while(re)
			{
				gets(word);
				for(int j=0;j<strlen(word);j++)
				{
					if(word[j]!=' ')
					{
						re=false;
						break;
					}
				}
			}
			//puts(word);
			for(int j=0;j<mx;j++)
			{
				if(word[j]=='#') maze[i][j]=-1;
				else if(word[j]=='A')
				{
					mat[n].setalien(j,i,n);
					maze[i][j]=n++;
				}
				else if(word[j]=='S')
				{
					mat[n].setalien(j,i,n);
					maze[i][j]=n++;
				}
			}
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++) g[i][j]=1<<20;
		}
		
		for(int i=1;i<n;i++)
		{
			bfs(mat[i].nr,mat[i].x,mat[i].y);
		}
		printf("%d\n",dij());
	}
	return 0;
}
