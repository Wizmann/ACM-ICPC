//Result:Wizmann	2031	Accepted	516K	16MS	G++	1267B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define INF 99999999
const double eps=1e-5;

inline double mul(double x)
{
	return x*x;
}

typedef struct point
{
	double x,y,z,r;
	
	inline void setpoint(){scanf("%lf%lf%lf%lf",&x,&y,&z,&r);}
	
	double cross(const point p)
	{
		double dis=mul(p.x-x)+mul(p.y-y)+mul(p.z-z);
		dis=sqrt(dis);
		if(dis<p.r+r) return 0;
		else return dis-p.r-r;
	}
}point;

point a[120];
double g[120][120];
char visit[120];
int n;

double prim()
{
	double res=0;
	double dis[120];
	memset(dis,0,sizeof(dis));
	for(int i=0;i<n;i++) dis[i]=g[0][i];
	memset(visit,0,sizeof(visit));
	visit[0]=1;
	for(int i=0;i<n-1;i++)
	{
		int minc;
		double t=INF;
		for(int j=0;j<n;j++)
		{
			if(!visit[j]&&dis[j]<t)
			{
				t=dis[j];
				minc=j;
			}
		}
		res+=t;
		visit[minc]=1;
		for(int j=0;j<n;j++)
		{
			if(dis[j]>g[minc][j]) dis[j]=g[minc][j];
		}
	}
	return res;
}
	

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++) a[i].setpoint();
		for(int i=0;i<n;i++)
		{
			g[i][i]=INF;
			for(int j=i+1;j<n;j++)
			{
				double t=a[i].cross(a[j]);
				g[i][j]=g[j][i]=t;
			}
		}
		
		printf("%.3f\n",prim()+eps);
	}
	return 0;
}
