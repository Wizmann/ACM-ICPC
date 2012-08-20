//Result:wizmann	3009	Accepted	192K	329MS	C++	1785B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int w,h;
const int mx[]={1,-1,0,0};
const int my[]={0,0,1,-1};
int ans;

typedef struct point
{
	int x,y;
	
	inline void setpoint(int a,int b){x=a;y=b;}
	inline void mv(int i)
	{
		x+=mx[i];y+=my[i];
	}
	void reverse(int i)
	{
		int m;
		switch(i)
		{
			case 0:m=1;break;
			case 1:m=0;break;
			case 2:m=3;break;
			case 3:m=2;break;
		}
		this->mv(m);
	}
}point;

typedef struct node
{
	char g[25][25];
	point goal,now;
	int step;
	
	void setnode()
	{
		memset(g,-1,sizeof(g));
		step=0;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&g[i][j]);
				if(g[i][j]==2) now.setpoint(j,i);
				else if(g[i][j]==3) goal.setpoint(j,i);
			}
		}
	}
	
	int mv(int i)
	{
		//0是普通移动,1是成功移动，-1是失败移动
		step++;
		if(step>10||step>=ans) return -1;
		else
		{
			point t;
			t=now;
			t.mv(i);
			if(g[t.y][t.x]==1) return -1;
			while(g[now.y][now.x]==0||g[now.y][now.x]==2)
			{
				t=now;
				now.mv(i);
			}
			if(g[now.y][now.x]==-1) return -1;
			else if(g[now.y][now.x]==3) return 1;
			else
			{
				g[now.y][now.x]=0;
				now=t;return 0;
			}
		}
	}
}node;

int main()
{
	freopen("input.txt","r",stdin);
	node init;
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(w*h==0) break;
		
		init.setnode();
		stack<node> st;
		st.push(init);
		ans=1<<20;
		while(!st.empty())
		{
			node t=st.top();
			st.pop();
			
			for(int i=0;i<4;i++)
			{
				node tmp=t;
				int ret=tmp.mv(i);
				if(ret==1) ans=min(ans,tmp.step);
				else if(ret==0) st.push(tmp);
			}
		}
		
		if(ans>=1<<20) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
			
		
		
	
