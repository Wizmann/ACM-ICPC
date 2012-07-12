//Result:wizmann	2688	Accepted	896K	375MS	G++	3326B	2012-07-10 13:52:30
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 24
#define DIRTY 11
#define INF 1<<30

const int mx[]={1,0,-1,0};
const int my[]={0,1,0,-1};

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
	inline void move(int dir)
	{
		x+=mx[dir];
		y+=my[dir];
	}
};

struct node
{
	int next,cost;
	node(){}
	node(int i_next,int i_cost)
	{
		next=i_next;cost=i_cost;
	}
	friend bool operator < (const node& a,const node& b)
	{
		return a.cost<b.cost;
	}
};


int r,c;
char maze[SIZE][SIZE];
point robot;
int ind;
deque<point> dirty;
vector<node> g[DIRTY];
int hash[SIZE][SIZE];

struct bnode
{
	point pos;int step;
	bnode(){}
	bnode(const point& ip,int i_s)
	{
		pos=ip;step=i_s;
	}
};

bool inMap(const point& p)
{
	if(p.y>=0 && p.y<r && p.x>=0 && p.x<c)
	{
		if(maze[p.y][p.x]!='x') return true;
		else return false;
	}
	return false;
}

void bfs(const point& start)
{
	for(int i=0;i<SIZE;i++) fill(hash[i],hash[i]+SIZE,INF);
	queue<bnode> q;
	q.push(bnode(start,0));
	while(!q.empty())
	{
		bnode now=q.front();
		q.pop();

		point p=now.pos;
		int step=now.step;

		if(hash[p.y][p.x]<=step) continue;
		else hash[p.y][p.x]=step;

		for(int i=0;i<4;i++)
		{
			point next=p;
			next.move(i);
			if(inMap(next)) q.push(bnode(next,step+1));
		}
	}
}

int makeG()
{
	memset(g,0,sizeof(g));
	for(int i=0;i<(int)dirty.size();i++)
	{
		bfs(dirty[i]);
		for(int j=0;j<(int)dirty.size();j++)
		{
			point next=dirty[j];
			g[i].push_back(node(j,hash[next.y][next.x]));
			if(hash[next.y][next.x]==INF) return -1;
		}
		sort(g[i].begin(),g[i].end());
	}
	return 0;
}

int visit[1<<DIRTY][DIRTY];
int end;

int dfs(int pos=0,int dis=0,int status=0)
{
	//print(pos<<' '<<status<<' '<<dis);
	int now_status=status|(1<<pos);
	if(visit[now_status][pos]<=dis) return INF;
	else visit[now_status][pos]=dis;
	
	if(now_status==end) return dis;

	int ans=INF;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int next=g[pos][i].next;
		int cost=g[pos][i].cost;
		ans=min(dfs(next,dis+cost,now_status),ans);
	}

	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&c,&r)!=EOF && r+c)
	{
		ind=1;
		for(int i=0;i<(1<<DIRTY);i++)
		{
			for(int j=0;j<DIRTY;j++) visit[i][j]=INF;
		}
		dirty.clear();
		for(int i=0;i<r;i++)
		{
			scanf("%s",maze[i]);
			for(int j=0;maze[i][j];j++)
			{
				if(maze[i][j]=='o')
				{
					robot=point(j,i);
					maze[i][j]='0';
				}
				else if(maze[i][j]=='*')
				{
					maze[i][j]='0'+ind++;
					dirty.push_back(point(j,i));
				}
			}
		}
		dirty.push_front(robot);
		end=(1<<ind)-1;
		//print(end);
		int cb=makeG();
		if(cb==-1)
		{
			print(-1);
			continue;
		}
		/*
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				printf("%c",maze[i][j]);
			}
			puts("");
		}
		
		for(int i=0;i<ind;i++)
		{
			for(int j=0;j<(int)g[i].size();j++)
			{
				printf("(%d,%d) ",g[i][j].next,g[i][j].cost);
			}
			puts("");
		}
		*/
		int ans=dfs();
		printf("%d\n",(ans<INF?ans:-1));
	}
	return 0;
}

