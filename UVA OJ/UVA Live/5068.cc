//Result:1032934	5068	Balloon Collecting	Accepted	C++	0.004	2012-07-10 03:13:50
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define inf 1e30
#define eps 1e-9
#define TIME 50010
#define ROAD 105
#define BALL 45


struct car
{
	int pos,k,dis,get;
	car(){}
	car(int i_pos,int i_k,int i_dis,int i_get)
	{
		pos=i_pos;
		k=i_k;
		dis=i_dis;
		get=i_get;
	}
};

struct ball
{
	int x,t;

	ball(){}
	ball(int i_x,int i_t)
	{
		x=i_x;t=i_t;
	}
	friend bool operator < (const ball& a,const ball& b)
	{
		return a.t<b.t;
	}
};

int hash[BALL][5];
int n;
ball ballon[BALL];

int bfs()
{
	queue<car> q;
	q.push(car(0,0,0,0));
	int maxget=-1;
	while(!q.empty())
	{
		car now=q.front();
		q.pop();
		
		if(hash[now.get][now.k]>now.dis)
		{
			hash[now.get][now.k]=now.dis;
		}
		else continue;
				
		maxget=max(maxget,now.get);

		int next=now.get;
		int tim=ballon[next].t;
		int dis=abs(now.pos-ballon[next].x);
		int cost=now.k+1;
		if(now.k<3)
		{
			if(dis*cost<=tim)
			{
				q.push(car(ballon[next].x,now.k+1,now.dis+dis,now.get+1));
			}
		}

		if(now.pos*cost+ballon[next].x<=tim)
		{
			q.push(car(ballon[next].x,1,now.dis+now.pos+ballon[next].x,now.get+1));
		}
	}
	return maxget;
}




int main()
{
	freopen("f.txt","r",stdin);
	int a,b;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<BALL;i++)
		{
			for(int j=0;j<5;j++) hash[i][j]=INF;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			ballon[i]=ball(a,b);
		}
		ballon[n++]=ball(0,INF);
		sort(ballon,ballon+n);
		for(int i=n-1;i>0;i--)
		{
			ballon[i].t-=ballon[i-1].t;
		}
		int get=bfs();
		if(get<n)
		{
			printf("NG %d\n",get+1);
		}
		else
		{
			int ans=INF;
			for(int i=0;i<5;i++)
			{
				ans=min(ans,hash[n][i]);
			}
			printf("OK %d\n",ans);
		}
	}
	return 0;
}



