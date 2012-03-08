//Result:wizmann	1654	Accepted	244K	422MS	C++	1158B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000100
#define eps 1e-4

struct point
{
	double x,y;

	point(){}
	point(double i_x,double i_y)
	{
		x=i_x;
		y=i_y;
	}
};

const int mx[]={0,-1, 0, 1,-1, 0, 1,-1, 0, 1};
const int my[]={0, 1, 1, 1, 0, 0, 0,-1,-1,-1};
double area;
point now;

inline void move(point& pnt,int m)
{
	pnt.x+=mx[m];
	pnt.y+=my[m];
}

void calArea(point pnt)
{
	area+=now.x*pnt.y;
	area-=now.y*pnt.x;
	now=pnt;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		area=0;
		char next;
		now=point(0,0);
		while(scanf("%c",&next)!=EOF)
		{
			if(next==' ' || next=='\n') continue;
			//printf("%c",next);
			if(next=='5') break;
			point pnt=now;
			move(pnt,next-'0');
			calArea(pnt);
		}
		calArea(point(0,0));
		area/=2;
		if(area<0) area=-area;
		long long ans=(long long)(10*(area+eps));
		if(ans%10==5) printf("%lld.5\n",ans/10);
		else printf("%lld\n",ans/10);
	}
	return 0;
}
