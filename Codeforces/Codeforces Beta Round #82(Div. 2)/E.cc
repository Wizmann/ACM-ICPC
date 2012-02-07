#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define INF 1e4
#define EPS 1e-7
#define MUL(x) ((x)*(x))

int n;
double x[101],y[101],z[101];
double xans,yans,zans;

double dis(double xt,double yt,double zt)
{
	double res=0,temp;
	for(int i=0;i<n;i++)
	{
		double dx=xt-x[i],
			   dy=yt-y[i],
			   dz=zt-z[i];
		temp=MUL(dx)+MUL(dy)+MUL(dz);
		res=max(res,temp);
	}
	return res;
}

double funz(double xt,double yt)
{
	double zl=-INF,zr=INF;
	while(zr-zl>=EPS)
	{
		double l=(zl*2+zr)/3.0;
		double r=(zl+zr*2)/3.0;
		double fl=dis(xt,yt,l);
		double fr=dis(xt,yt,r);
		if(fl>fr) zl=l;
		else zr=r;
	}
	zans=zr;
	return dis(xt,yt,zr);
}

double funy(double xt)
{
	double yl=-INF,yr=INF;
	while(yr-yl>=EPS)
	{
		double l=(yl*2+yr)/3.0;
		double r=(yl+yr*2)/3.0;
		double fl=funz(xt,l);
		double fr=funz(xt,r);
		if(fl>fr) yl=l;
		else yr=r;
	}
	yans=yr;
	return funz(xt,yr);
}

double funx()
{
	double xl=-INF,xr=INF;
	while(xr-xl>=EPS)
	{
		double l=(xl*2+xr)/3.0;
		double r=(xl+xr*2)/3.0;
		double fl=funy(l);
		double fr=funy(r);
		if(fl>fr) xl=l;
		else xr=r;
	}
	xans=xr;
	return funy(xr);
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",x+i,y+i,z+i);
	}
	funx();
	printf("%lf %lf %lf\n",xans,yans,zans);
	return 0;
}

