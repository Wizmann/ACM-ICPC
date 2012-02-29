//Result:Accepted	1162	15MS	584K	1364 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bitset>


using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define inf 100000000000000.00

struct point
{
	double x,y;
	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;y=i_y;
	}
};

int n;
double g[SIZE][SIZE];
double dis[SIZE];
point array[SIZE];
double ans;

inline double mul(double x){return x*x;}

double pntDis(point& a, point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

void prim()
{
	bitset<SIZE> visit;
	ans=0;
	for(int i=0;i<SIZE;i++) dis[i]=inf;
	dis[0]=0;
	for(int i=0;i<n;i++)
	{
		double mindis=inf;
		int pos=-1;
		for(int j=0;j<n;j++)
		{
			//printf("%.2f ",dis[j]);
			if(!visit[j] && dis[j]<mindis)
			{
				mindis=dis[j];
				pos=j;
			}
		}
		//puts("");
		visit[pos]=1;
		ans+=mindis;
		for(int j=0;j<n;j++)
		{
			if(!visit[j] && g[pos][j]<dis[j])
			{
				dis[j]=g[pos][j];
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		double a,b;
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			array[i]=point(a,b);
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				g[i][j]=pntDis(array[i],array[j]);
			}
		}
		
		prim();
		printf("%.2f\n",ans);
	}
	return 0;
}
