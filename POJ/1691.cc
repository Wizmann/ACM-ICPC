//Result:wizmann	1691	Accepted	728K	16MS	G++	2424B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define COLOR 24
#define SIZE 16
#define INF 1<<25

typedef struct point
{
	int x,y;

	void setpoint(int i_x,int i_y)
	{
		x=i_x;
		y=i_y;
	}
}point;

typedef struct square
{
	point lu,rd;
	int color;

	bool upper(const square& sq)
	{
		if(rd.y==sq.lu.y)
		{
			if( (rd.x>=sq.lu.x && rd.x<=sq.rd.x) ||
				(lu.x>=sq.lu.x && lu.x<=sq.rd.x) )
			{
				return true;
			}
		}
		return false;
	}
}square;

typedef struct node
{
	int in[SIZE];
	int color;
	int step;
	int paint;

	node()
	{
		memset(in,0,sizeof(in));
		color=-1;
		step=1;
		paint=0;
	}
}node;

int n;
square array[SIZE];
queue<node> q;
int g[SIZE][SIZE];

int bfs()
{
	int ans=INF;
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(now.paint==n)
		{
			ans=min(ans,now.step);
			continue;
		}
		else if(now.step>=ans) continue;
		
		bitset<COLOR> bs;
		for(int i=0;i<n;i++)
		{
			if(now.in[i]==0 && !bs[array[i].color])
			{
				node t=now;
				bs[array[i].color]=1;
				if(array[i].color!=now.color)
				{
					t.step++;
					t.color=array[i].color;
				}
				
				bool flag=false;
				bitset<SIZE> visit;
				while(!flag)
				{
					flag=true;
					for(int j=0;j<n;j++)
					{
						if(t.in[j]==0 && array[j].color==t.color && !visit[j])
						{
							t.in[j]=-1;
							visit[j]=1;
							t.paint++;
							flag=false;
							for(int k=0;k<n;k++)
							{
								
								if(g[j][k]) t.in[k]--;
							}
						}
					}
				}
				q.push(t);
			}//ENDIF: if(now.in[i]==0)
		}
	}
	return ans;
}


int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		memset(g,0,sizeof(g));
		memset(array,0,sizeof(array));
		input(n);
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			array[i].lu.setpoint(b,a);
			input(a>>b);
			array[i].rd.setpoint(b,a);
			input(a);
			array[i].color=a;
		}
		node now;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;
				else
				{
					if(array[i].upper(array[j]))
					{
						now.in[j]++;
						g[i][j]=1;
					}
				}
			}
		}
		while(!q.empty()) q.pop();
		q.push(now);
		print(bfs()-1);
	}
	return 0;
}
