//Result:2012-08-09 19:39:31	Accepted	4355	703MS	1016K	1011 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define SIZE 50000

const double eps=1e-4;
const double inf=1e20;

int n;
double pos[SIZE],w[SIZE];

inline double tri(double x)
{
	return x*x*x;
}

double cal(double now)
{
	double res=0;
	for(int i=0;i<n;i++)
	{
		res+=tri(fabs(pos[i]-now))*w[i];
	}
	return res;
}
		

double slove(double l,double r)
{
	double lval,rval,lt,rt;
	while(fabs(l-r)>eps)
	{
		lt=(l+r)/2;
		rt=(lt+r)/2;
		lval=cal(lt);
		rval=cal(rt);
		if(lval<=rval) r=rt;
		else l=lt;
	}
	return l;
}
		

int main()
{
	freopen("6.txt","r",stdin);
	int T;
	scanf("%d",&T);
	int cas=1;
	while(T--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d",&n);
		double maxi=-inf;
		double mini=inf;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",pos+i,w+i);
			maxi=max(pos[i],maxi);
			mini=min(pos[i],mini);
		}
		
		double pos=slove(mini,maxi);
		printf("%.0lf\n",cal(pos));

	}
	return 0;
}
		
