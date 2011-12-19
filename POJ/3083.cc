//Result:wizmann	3083	Accepted	600K	0MS	G++	2853B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define SIZE 45
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

char maze[SIZE][SIZE];
char visit[SIZE][SIZE];
const short mx[]={-1,0,1,0};
const short my[]={0,1,0,-1};
int w,h;
int step;

typedef struct point
{
	int x,y,step;
	
	inline void setpoint(int a,int b,int c){x=a;y=b;step=c;}
	inline void printpoint(){printf("%d %d\n",x,y);}
	inline void mv(int n){x+=mx[n];y+=my[n];step++;}	
}point;
point start,end;

inline bool access(point p)
{
	if(p.y>0&&p.y<=h&&p.x>0&&p.x<=w)
	{
		if(maze[p.y][p.x]=='.'||maze[p.y][p.x]=='E') return true;
	}
	return false;
}

int shortpath()
{
	int cnt=0;
	queue<point> q;
	memset(visit,0,sizeof(visit));
	q.push(start);
	while(!q.empty())
	{
		point t=q.front();
		q.pop();

		if(t.x==end.x&&t.y==end.y)
		{
			//printf("CNT:%d\n",cnt);
			return t.step+1;
		}	
		visit[t.y][t.x]=1;
		for(int i=0;i<4;i++)
		{
			point tmp=t;
			tmp.mv(i);
			if(!visit[tmp.y][tmp.x]&&access(tmp))
			{
				cnt++;
				visit[tmp.y][tmp.x]=1;
				q.push(tmp);
			}
		}
	}
	return -1;
}

inline int turnleft(int n)
{
	return (n+1)%4;
}

inline int turnright(int n)
{
	return (n+3)%4;
}

inline int reverse(int n)
{
	return (n+2)%4;
}

int leftpath(point now,int n)
{
	while(now.x!=end.x||now.y!=end.y)
	{
		int m=turnleft(n);
		point t=now;
		t.mv(m);
		if(access(t)){now=t;n=m;}
		else
		{
			t=now;
			t.mv(n);
			if(access(t)){now=t;}
			else
			{
				t=now;
				m=turnright(n);
				t.mv(m);
				if(access(t)){now=t;n=m;}
				else
				{
					m=reverse(n);
					t=now;
					t.mv(m);
					{now=t;n=m;}
				}
			}
		}
	}
	return now.step;
}

int rightpath(point now,int n)
{
	while(now.x!=end.x||now.y!=end.y)
	{
		int m=turnright(n);
		point t=now;
		t.mv(m);
		if(access(t)){now=t;n=m;}
		else
		{
			t=now;
			t.mv(n);
			if(access(t)){now=t;}
			else
			{
				t=now;
				m=turnleft(n);
				t.mv(m);
				if(access(t)){now=t;n=m;}
				else
				{
					m=reverse(n);
					t=now;
					t.mv(m);
					{now=t;n=m;}
				}
			}
		}
	}
	return now.step;
}


int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(maze,0,sizeof(maze));
		scanf("%d%d",&w,&h);
		for(int i=1;i<=h;i++)
		{
			scanf("%s",maze[i]+1);
			for(int j=1;j<=w;j++)
			{
				if(maze[i][j]=='.') continue;
				else if(maze[i][j]=='S') start.setpoint(j,i,0);
				else if(maze[i][j]=='E') end.setpoint(j,i,0);
			}
		}
		point next;
		int i;
		for(i=0;i<4;i++)
		{
			next=start;
			next.mv(i);
			if(access(next)) break;
		}
		next.setpoint(next.x,next.y,1);
		
		printf("%d ",leftpath(next,i)+1);
		printf("%d ",rightpath(next,i)+1);
		printf("%d\n",shortpath());
	}
	return 0;
}
