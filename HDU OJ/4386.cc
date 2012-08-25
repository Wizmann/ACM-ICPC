//Result:2012-08-21 20:58:36	Accepted	4386	234MS	504K	1555 B	G++	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double eps=1e-10;


double helen(double a,double b,double c)
{
	double p=(a+b+c)/2.;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double tri(double a,double b,double c,double d,double x)
{
	double p1=(a+b+x)/2;
	if(p1*(p1-a)*(p1-b)*(p1-x)<0) return 0;
	double p2=(c+d+x)/2;
	if(p2*(p2-c)*(p2-d)*(p2-x)<0) return 0;
	return helen(a,b,x)+helen(c,d,x);
}


double slove(double a,double b,double c,double d)
{
	double l,r;
	
	l=max(abs(a-b),abs(c-d));
	r=min(a+b,c+d);
	
	double lt,rt,ltVal,rtVal;
	while(fabs(r-l)>eps)
	{
		lt=(l+r)/2;
		rt=(lt+r)/2;
		ltVal=tri(a,b,c,d,lt);
		rtVal=tri(a,b,c,d,rt);
		//print(ltVal<<' '<<rtVal);
		if(ltVal>=rtVal) r=rt;
		else l=lt;
	}
	//print(a<<' '<<b<<' '<<c<<' '<<d);
	//print(l<<' '<<tri(a,b,c,d,l));
	return tri(a,b,c,d,l);
}
		


int main()
{
	freopen("7.txt","r",stdin);
	freopen("7.out","w",stdout);
	int T;
	double a[4];
	input(T);
	int cas=1;
	while(T--)
	{
		printf("Case %d: ",cas++);
		double ans=0;
		for(int i=0;i<4;i++) scanf("%lf",a+i);
		
		ans=max(ans,slove(a[0],a[1],a[2],a[3]));
		ans=max(ans,slove(a[0],a[2],a[1],a[3]));
		ans=max(ans,slove(a[0],a[3],a[1],a[2]));
		/*
		for(int i=0;i<2000;i++)
		{
			print(tri(a[0],a[1],a[2],a[3],i));
		}
		*/
		if(ans<eps) puts("-1");
		else printf("%.6lf\n",ans);
	}
	//print((double)clock()/CLOCKS_PER_SEC);
	return 0;
}
		
