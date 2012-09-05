//Result:2012-07-16 16:07:34	Accepted	2108	0MS	484K	853 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10240

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
point poly[SIZE+5];

double xmult(point a,point b,point o)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int main()
{
	double a,b;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly[i]=point(a,b);
		}
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			int j=(i+1)%n;
			int k=(i+2)%n;

			if(xmult(poly[j],poly[k],poly[i])<0)
			{
				flag=false;
				break;
			}
		}
		if(flag) print("convex");
		else print("concave");
	}
	return 0;
}



