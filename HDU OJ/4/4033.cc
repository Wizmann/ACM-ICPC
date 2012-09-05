//Result:2012-08-31 10:42:34	Accepted	4033	31MS	508K	1559 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double inf=1e8;
const double eps=1e-9;
const double pi=acos(-1.);

int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

const double mul(double x){return x*x;}

double edge[128];
int n;

double cal(double x)
{
	double res=0;
	for(int i=0;i<n;i++)
	{
		double a=edge[i];
		double b=edge[(i+1)%n];

		res+=acos((mul(a)+mul(b)-mul(x))/(2*a*b));
	}
	return res;
}

double getmin()
{
	double res=-inf;
	for(int i=0;i<n;i++)
	{
		double a=edge[i];
		double b=edge[(i+1)%n];
		
		res=max(res,fabs(a-b));
	}
	return res;
}

double getmax()
{
	double res=inf;
	for(int i=0;i<n;i++)
	{
		double a=edge[i];
		double b=edge[(i+1)%n];
		
		res=min(res,fabs(a+b));
	}
	return res;
}


double slove()
{
	double mini=getmin();
	double maxi=getmax();
	double l=mini,r=maxi;
	while(zero(l-r)<0)
	{
		double mid=(l+r)/2;
		double val=cal(mid);
		//print(mid);
		if(zero(val-2*pi)>0) r=mid;
		else l=mid;
	}
	if(l<mini || l>maxi) l=inf;
	return l;
}

int main()
{

	int T,cas=1;
	input(T);
	while(T--)
	{
		printf("Case %d: ",cas++);
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",edge+i);
		}
		double ans=slove();
		if(fabs(cal(ans)-2*pi)>1e-8) ans=inf;
		if(ans<inf) printf("%.3lf\n",ans);
		else puts("impossible");
	}
	return 0;
}
