//Result:Wizmann 	G++ 	18 ms 	404 kb 	1591 	2011-12-12 11:54:07
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <iostream>


using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl


#define SIZE 128
#define MOVE 4

const int mx[MOVE]={0, 1,0,-1};
const int my[MOVE]={-1,0,1, 0};

typedef struct node
{
	int x,y;
	int step;
	
	node(int i_x,int i_y,int i_step=0)
	{
		x=i_x;y=i_y;
		step=i_step;
	}
}node;


int m,n;
char visit[SIZE][SIZE][MOVE];
queue<node> q;
int spring;
int g[SIZE][SIZE];
int ansX,ansY;

int bfs()
{
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(now.y==ansY && now.x==ansX) return now.step;
		else
		{
			for(int i=0;i<MOVE;i++)
			{
				int xx=now.x+mx[i];
				int yy=now.y+my[i];
				if(xx>0 && xx<=n && yy>0 && yy<=m)
				{
					while(g[xx][yy])
					{
						yy+=g[xx][yy]*my[i];
						xx+=g[xx][yy]*mx[i];
						if(xx<1) xx=1;
						if(xx>n) xx=n;
						if(yy<1) yy=1;
						if(yy>m) yy=m;
					}

					if(!visit[xx][yy][i])
					{
						visit[xx][yy][i]=1;
						q.push(node(xx,yy,now.step+1));
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	freopen("e.txt","r",stdin);
	int a,b,val;
	while(input(n>>m))
	{
		memset(visit,0,sizeof(visit));
		memset(g,0,sizeof(g));
		while(!q.empty()) q.pop();
		
		input(spring);
		for(int i=0;i<spring;i++)
		{
			input(a>>b>>val);
			g[a][b]=val;
		}
		
		input(a>>b);
		node st(a,b);
		q.push(st);
		
		input(a>>b);
		ansY=b;ansX=a;
		int ans=bfs();
		if(ans>0) print(ans);
		else print("Impossible");
	}
	return 0;
}
		
