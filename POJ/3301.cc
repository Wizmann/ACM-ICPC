//Result:wizmann	3301	Accepted	204K	0MS	C++	990B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const double eps=1e-5;
const double MAX=1e4;
const double pi=acos(-1.0);
int n;
double x[30],y[30];

double tri(double t)
{
	double tx,ty;
	double bx,by,sx,sy;
	bx=by=-MAX;
	sx=sy=MAX;
	for(int i=0;i<n;i++)
	{
		tx=x[i]*cos(t)-y[i]*sin(t);
		ty=x[i]*sin(t)+y[i]*cos(t);
		//旋转坐标系，求出旋转后的点应该在什么位置
		bx=max(tx,bx);
		sx=min(tx,sx);
		by=max(ty,by);
		sy=min(ty,sy);
	}
	return max(bx-sx,by-sy);
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i=0;i<n;i++) scanf("%lf%lf",x+i,y+i);
		double l=0,r=pi/2;
		double lt,rt,ltVal,rtVal;
		while(fabs(r-l)>eps)
		{
			lt=(l+r)/2;
			rt=(lt+r)/2;
			ltVal=tri(lt);
			rtVal=tri(rt);
			if(ltVal<=rtVal) r=rt;
			else l=lt;
		}
		double len=tri(l);
		printf("%.2lf\n",len*len);
	}
	return 0;
}
