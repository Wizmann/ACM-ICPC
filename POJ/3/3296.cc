//Result:wizmann	3296	Accepted	772K	0MS	G++	1103B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define eps 1e-6

inline int zero(double x)
{
	if(fabs(x)<eps) return 0;
	else if(x<-eps) return -1;
	else return 1;
}

int k;
double vb,vw,vr,vc;

double cal(double x)
{
	double wine=vw/(x+vw)*vr;
	double water=min(vc-vr,(vb-x)/(k-1));
	for(int i=0;i<(k-1);i++)
	{
		wine=(wine/(vr+water))*vr;
	}
	return wine;
}

double tri(double l,double r)
{
	while(zero(l-r))
	{
		double lmid=l+(r-l)/3;
		double rmid=r-(r-l)/3;
		if(cal(lmid)<cal(rmid)) r=rmid;
		else l=lmid;
	}
	return l;
}

void slove()
{
	double left=0;
	double right=min(vb,vc-vw);
	double x=tri(left,right);
	double y=min(vc-vr,(vb-x)/(k-1));
	printf("%d %.2f ",k,x);
	for(int i=0;i<k-1;i++)
	{
		if(i) printf(" ");
		printf("%.2f",y);
	}
	puts("");
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(k) && k)
	{
		input(vb>>vw>>vr>>vc);
		if(vw+vb<vr) print(0);
		else slove();
		
	}
	return 0;
}
