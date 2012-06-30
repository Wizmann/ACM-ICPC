//Result:wizmann	1765	Accepted	6424K	1047MS	G++	2387B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 80010
#define LEFT 0
#define RIGHT 1

struct point
{
	int x,y;
	int id,pos;
	point(){}
	point(int i_x,int i_y,int i_id,int i_pos)
	{
		x=i_x;y=i_y;
		id=i_id;pos=i_pos;
	}

	friend bool operator < (const point& a,const point &b)
	{
		if(a.x!=b.x) return a.x<b.x;
		else return a.y<b.y;
	}
};

int n,ind,sz;
point g[SIZE];
int down[SIZE];//which is the down side of the roof
int que[SIZE],visit[SIZE];
double dx[SIZE],dy[SIZE],c[SIZE];
int sx[SIZE],sy[SIZE];//the lowest x,y of the roof;
vector<int> edge[SIZE];
int in[SIZE];//入度
int cov[SIZE],sum[SIZE];

void push_queue(point p)
{
	down[p.id]=p.pos;
	if(!visit[p.id])
	{
		visit[p.id]=1;
		int ptr=sz++;
		//队列中按照roof的高度排序
		while(ptr>0 && dy[que[ptr]]*p.x-p.y*dx[que[ptr]]>c[que[ptr]])
		{
			que[ptr+1]=que[ptr];
			ptr--;
		}
		que[++ptr]=p.id;
	}
	else visit[p.id]=2;
}

int main()
{
	freopen("d.txt","r",stdin);
	int x1,y1,x2,y2;
	input(n);
	ind=sz=0;
	for(int i=1;i<=n;i++)
	{
		int dir=-1;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(y1>y2) dir=LEFT;
		else dir=RIGHT;
		dy[i]=y2-y1;
		dx[i]=x2-x1;
		c[i]=x1*y2-x2*y1;
		sx[i]=min(x1,x2);
		sy[i]=min(y1,y2);
		g[ind++]=point(x1,y1,i,dir);
		g[ind++]=point(x2,y2,i,!dir);
	}
	sort(g,g+ind);
	int i=0;
	while(i<ind)
	{
		int x=g[i].x;
		push_queue(g[i++]);
		while(i<ind && g[i].x==x) push_queue(g[i++]);
		for(int j=1;j<=sz;j++)
		{
			if(!cov[que[j]]) sum[que[j]]+=x-sx[que[j]];
			sx[que[j]]=x;
		}
		for(int j=1;j<sz;j++)
		{
			if(down[que[j+1]])
			{
				edge[que[j+1]].push_back(que[j]);//位于上方的roof会流水到下方的roof
				in[que[j]]++;
			}
		}

		int k=0;
		for(int j=1;j<=sz;j++)
		{
			if(visit[que[j]]<2) que[++k]=que[j];
		}
		sz=k;
		for(int j=1;j<=sz;j++)
		{
			down[que[j]]=0;
			cov[que[j]]=1;//cover已经被覆盖
		}
		cov[que[sz]]=0;//队列的第一个没有被覆盖
	}
	sz=0;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) que[sz++]=i;
	}
	for(i=0;i<sz;i++)
	{
		for(int j=0;j<(int)edge[que[i]].size();j++)
		{
			int now=edge[que[i]][j];
			sum[now]+=sum[que[i]];
			in[now]--;
			if(in[now]==0)
			{
				que[sz++]=now;
			}
		}
	}
	for(i=1;i<=n;i++) print(sum[i]);
	return 0;
}
