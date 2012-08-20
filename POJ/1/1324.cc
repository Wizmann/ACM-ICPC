//Result:wizmann	1324	Accepted	3112K	3454MS	G++	3200B
//What's Wrong:
//	1.位压缩的效率，减少无关位
//	2.蛇的走动方向没有经过检测
//	3.没有自己出数据检验
//	4.对于某些数据相当然了
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

#define SIZE 21
#define INF 1<<25
#define STATUS 1<<14
#define print(x) cout<<x<<endl

const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};
int n,m,l;

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
};

struct snake
{
	point head;
	int status;
	int step;

	snake()
	{
		status=0;
		step=0;
	}
	
	void makeStatus(point *body)
	{
		status=0;
		int ptr=0;
		for(int i=1;i<l;i++)
		{
			int now=i;
			int pre=i-1;
			int dir=-1;
			for(int i=0;i<4;i++)
			{
				if(body[pre].x-body[now].x==mx[i] &&
					body[pre].y-body[now].y==my[i])
				{
					dir=i;
					break;
				}
			}
			//print("DIR:"<<dir);
			status |= (dir<<ptr);
			//print(status);
			ptr+=2;
		}
	}
};

point stone[SIZE*SIZE];
queue<snake> q;
bitset<STATUS> visit[SIZE][SIZE];
//char visit[SIZE][SIZE][STATUS];
int stone_num;

inline bool inMap(int x,int y)
{
	if(x>0 && x<=m && y>0 && y<=n) return true;
	else return false;
}

int moveSnake(int x,int y,snake& py)
{
	for(int i=0;i<stone_num;i++)
	{
		if(x==stone[i].x && y==stone[i].y) return -1;
	}
	int status=0;
	point now=py.head;
	point head=point(x,y);
	int ptr=0;
	for(int i=0;i<l;i++)
	{
		int dir;
		if(now.x==x && now.y==y) return -1;
		else
		{
			//print(now.x<<' '<<now.y);
			for(int j=0;j<4;j++)
			{
				if(head.x-now.x==mx[j] && head.y-now.y==my[j])
				{
					dir=j;
					break;
				}
			}
			if(i<l-1)
			{
				status |= (dir<<ptr);
				dir=( (3<<ptr) & py.status )>>ptr;
				//print("DIR:"<<dir);
				ptr+=2;
				head=now;
				now.x-=mx[dir];
				now.y-=my[dir];
			}
		}
	}
	py.head=point(x,y);
	py.status=status;
	py.step++;
	//puts("");
	return py.status;
}

int bfs()
{
	int ans=INF;
	while(!q.empty())
	{
		snake now=q.front();
		q.pop();
		int now_x=now.head.x;
		int now_y=now.head.y;
		//print(now_x<<' '<<now_y);
		if(now.step>=ans || visit[now_y][now_x][now.status]) continue;
		if(now_x==1 && now_y==1)
		{
			ans=now.step;
			continue;
		}
		visit[now_y][now_x][now.status]=1;
		
		point head=now.head;

		for(int i=0;i<4;i++)
		{
			int nx=head.x+mx[i];
			int ny=head.y+my[i];
			if(!inMap(nx,ny)) continue;
			snake npy=now;
			int nstatus=moveSnake(nx,ny,npy);
			//print(nstatus);
			if(nstatus==-1) continue;
			else q.push(npy);
		}
	}
	return ans;
}




int main()
{
	int cas=1;
	point body[10];
	while(scanf("%d%d%d",&n,&m,&l)!=EOF && n+m+l)
	{
		snake py;
		int a,b;
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				visit[i][j].reset();
			}
		}
		while(!q.empty()) q.pop();
		
		for(int i=0;i<l;i++)
		{
			scanf("%d%d",&a,&b);
			body[i]=point(b,a);
		}
		py.head=body[0];
		py.makeStatus(body);
		py.step=0;
		q.push(py);
		
		scanf("%d",&stone_num);
		for(int i=0;i<stone_num;i++)
		{
			scanf("%d%d",&a,&b);
			stone[i]=point(b,a);
		}
		int ans=bfs();
		if(ans>=INF) ans=-1;
		
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}
