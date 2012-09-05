//Result:2012-07-07 09:43:39	Accepted	1875	46MS	716K	1914 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

const double inf=1e20;


struct node
{
	int dest;
	double cost;
	node(){}
	node(int i_dest,double i_cost)
	{
		dest=i_dest;cost=i_cost;
	}
};

struct point
{
	double x,y;
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

inline double mul(double x)
{
	return x*x;
}

inline double pntDis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

int n;
vector<node> g[SIZE];
point array[SIZE];

double prim()
{
	double dis[SIZE];
	fill(dis,dis+SIZE,inf);
	bitset<SIZE> visit;
	double res=0;
	int intree=0;

	dis[0]=0;
	for(int i=0;i<n;i++)
	{
		double minval=inf;
		int ptr=-1;
		for(int j=0;j<n;j++)
		{
			if(dis[j]<minval && !visit[j])
			{
				minval=dis[j];
				ptr=j;
			}
		}

		if(ptr==-1) break;
		else
		{
			visit[ptr]=1;
			intree++;
			res+=minval;
		}

		for(int j=0;j<(int)g[ptr].size();j++)
		{
			int next=g[ptr][j].dest;
			double cost=g[ptr][j].cost;

			if(dis[next]>cost) dis[next]=cost;
		}
	}
	if(intree<n) return inf;
	else return res;
}





int main()
{
	freopen("input.txt","r",stdin);
	int T;
	double a,b;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i]=point(a,b);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				double val=pntDis(array[i],array[j]);
				if(val>=10 && val<=1000)
				{
					g[i].push_back(node(j,val));
					g[j].push_back(node(i,val));
				}
			}
		}

		double ans=prim();
		if(ans>=inf) printf("oh!\n");
		else printf("%.1f\n",ans*100);
	}
	return 0;
}


