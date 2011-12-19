#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct point
{
	double x,y;

	void setpoint()
	{
	    scanf("%lf%lf",&x,&y);
	}
}point;

point array[1010];
point stack[1010];
point *st;

void push(point num)
{
	*st=num;
	st++;
}

void pop()
{
	st--;
}

double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double cross(point a,point mid,point b)
{
	return (a.x-mid.x)*(b.y-mid.y)-(a.y-mid.y)*(b.x-mid.x);
}

void top(int n)
{
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(array[i].y<array[res].y) res=i;
		else if(fabs(array[i].y-array[res].y)<1e-8)
		{
			if(array[i].x<array[res].x) res=i;
		}
	}

	swap(array[0],array[res]);
}

int cmp(point a,point b)
{
	if(cross(array[0],a,b)>0) return 1;
	else if(fabs(cross(array[0],a,b))<1e-8&&dis(a,array[0])<dis(b,array[0])) return 1;
	else return 0;
}

int gsearch(int n)
{
	top(n);
	push(array[0]);
	sort(array+1,array+n,cmp);

	if(n>1) push(array[1]);
	if(n>2) push(array[2]);

	for(int i=3;i<n;i++)
	{
		while(cross(*(st-2),*(st-1),array[i])<=0) pop();
		push(array[i]);
	}
	return st-stack;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	double r;
	while(scanf("%d%lf",&n,&r)!=EOF)
	{
		st=stack;
		
	    for(int i=0;i<n;i++) array[i].setpoint();
	    int num=gsearch(n);

	    double ans=0;
	    for(int i=1;i<num;i++) ans+=dis(stack[i-1],stack[i]);
	    ans+=dis(stack[0],stack[num-1]);
	    ans+=2*r*acos(-1.0);

	    printf("%.3lf\n",ans);
    }
    return 0;
}
