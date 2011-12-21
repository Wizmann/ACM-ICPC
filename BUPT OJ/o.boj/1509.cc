//Result:1509 	Accepted	169MS	8548K	G++	1687B	2011-11-30 10:51:46

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
#define mul(x) ((x)*(x))
#define SIZE 1024
#define SOURCE 0
#define SINK n+1

const double INF = 10000000000000000.0;

struct node
{
	double x,y,r;
	
	void setnode(double ix,double iy,double ir)
	{
		x=ix;y=iy;r=ir;
	}
	
	double miniDis(const node& t)
	{
		double res=sqrt(mul(t.x-x)+mul(t.y-y))-r-t.r;
		if(res<0.0) res=0.0;
		return res;
	}
};

int n;
node array[SIZE];
double g[SIZE][SIZE];
bitset<SIZE> visit;

void makeG()
{
	for(int i=SOURCE;i<=SINK;i++)
	{
		for(int j=i;j<=SINK;j++)
		{
			g[i][j]=g[j][i]=array[i].miniDis(array[j]);
			//print(i<<' '<<j<<' '<<g[i][j]);
		}
	}
}

double dij()
{
	int pos;
	double mini;
	double dis[SIZE];
	visit.reset();
	for(int i=SOURCE;i<=SINK;i++) dis[i]=INF;
	dis[SOURCE]=0;
	for(int i=SOURCE;i<=SINK;i++)
	{
		pos=-1;mini=INF;
		for(int j=SOURCE;j<=SINK;j++)
		{
			if(!visit[j]&&dis[j]<mini)
			{
				mini=dis[j];
				pos=j;
			}
		}
		visit[pos]=1;
		for(int j=SOURCE;j<=SINK;j++)
		{
			if(visit[j]) continue;
			else dis[j]=min(dis[j],dis[pos]+g[pos][j]);
		}
	}
	return dis[SINK];
}
		
		
		
int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		memset(g,0,sizeof(g));
		input(n);
		double x,y,r;
		input(x>>y);
		array[SOURCE].setnode(x,y,0);
		input(x>>y);
		array[SINK].setnode(x,y,0);
		for(int i=1;i<=n;i++)
		{
			input(x>>y>>r);
			array[i].setnode(x,y,r);
		}
		makeG();
		printf("%.3lf\n",dij());
	}
	return 0;
}
