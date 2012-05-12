//Result:wizmann	3771	Accepted	752K	0MS	G++	1687B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
//I'm the std::bad_allocer
#define SIZE 55

const double inf=1e10;

//I wanna home.
//Why home?
//It's just a place to throw away all my tired and pain.
//I hate programming. but i can't stop.
int n;


struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
	{
		x=i_x;
		y=i_y;
	}
};

point pnt[SIZE];

inline double mul(double x){return x*x;}
inline double pntDistance(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double g[SIZE][SIZE];

double prim(int ban)
{
	bitset<SIZE> visit;
	double ans=0;
	double dis[SIZE];
	for(int i=0;i<n;i++) dis[i]=inf;
	if(ban) dis[0]=0;
	else dis[1]=0;
	for(int i=0;i<n;i++)
	{
		double mindis=inf;
		int ptr=-1;
		for(int j=0;j<n;j++)
		{
			if(!visit[j] && dis[j]<mindis && j!=ban)
			{
				mindis=dis[j];
				ptr=j;
			}
		}
		if(ptr==-1) break;

		ans+=mindis;
		visit[ptr]=1;

		for(int j=0;j<n;j++)
		{
			if(!visit[j] && j!=ban)
			{
				dis[j]=min(dis[j],g[ptr][j]);
			}
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
		//I'm bad.
		//B-A-D
		input(n);
		for(int i=0;i<n;i++) 
		{
			input(a>>b);
			pnt[i]=point(a,b);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				g[i][j]=pntDistance(pnt[i],pnt[j]);
			}
		}
		double ans=inf;
		for(int i=0;i<n;i++)
		{
			ans=min(ans,prim(i));
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
