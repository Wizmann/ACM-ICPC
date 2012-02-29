//Result:1297	Accepted	47MS	344K	G++	 1115B	2012-02-21 20:02:16
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define eps 1e-6

const double pi=acos(-1.0);
double r,l,h;


double halfCircle(double angle)
{
	return ( (pi*r*r*angle/(2*pi))-r*r*sin(angle)*cos(angle)/2 )*2;
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int cas=1;
	while(input(r>>l>>h))
	{
		printf("Case %d:\n",cas++);
		double ans=0;
		bool half=false;
		if(h>l/2)
		{
			ans=r;
			h-=l/2;
			half=true;
		}
		double val=pi*r*r*h/l;
		double lft=0,rht=r;
		double s;
		if(!half)
		{
			while(fabs(lft-rht)>eps)
			{
				double mid=(lft+rht)/2;
				double angle=acos((r-mid)/r);
				s=halfCircle(angle);
				if(s>val) rht=mid;
				else lft=mid;
			}
		}
		else
		{
			while(fabs(lft-rht)>eps)
			{
				double mid=(lft+rht)/2;
				double angle=acos(mid/r);
				s=pi*r*r/2-halfCircle(angle);
				if(s>val) rht=mid;
				else lft=mid;
			}
		}
		//print(2*r-ans-rht);
		printf("%.3lf\n",ans+lft);
	}
	return 0;
}
