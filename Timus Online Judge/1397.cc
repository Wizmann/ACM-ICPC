//Result:12:06:39 12 Jul 2012	Wizmann	1397. Points Game	C++	Accepted	0.093	228 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y)
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

point array[SIZE];
int n;
double dis[SIZE];

bool cmp(double a,double b)
{
	return a>b;
}

int main()
{
	int a,b;
	while(input(n))
	{
		n<<=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			array[i]=point(a,b);
		}

		for(int i=0;i<n;i++)
		{
			dis[i]=0;
			for(int j=0;j<n;j++)
			{
				dis[i]+=pntDis(array[i],array[j]);
			}
		}
		sort(dis,dis+n,cmp);
		double ans=0;
		for(int i=0;i<n;i++)
		{
			if(i&1) ans-=dis[i];
			else ans+=dis[i];
		}
		printf("%.3f\n",ans/2);
	}
	return 0;
}
		
			

