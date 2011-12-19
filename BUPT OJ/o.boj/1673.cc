#include <iostream>
#include <cmath>
#include <algorithm>

#define N 50010

typedef struct point
{
	int x,y;
	
	void setpoint()
	{
		scanf("%d%d",&x,&y);
	}
}point;

point array[N];
point stack[N];
point *st;

void init()
{
	st=stack;
}

void push(point a)
{
	*st=a;
	st++;
}

void pop()
{
	st--;
}

double distance(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
} 

int cross(point a,point mid,point b)
{
	return (a.x-mid.x)*(b.y-mid.y)-(a.y-mid.y)*(b.x-mid.x);
}

void top(int n)
{
	int pad=0;
	for(int i=1;i<n;i++)
	{
		if(array[i].y<array[pad].y) pad=i;
		else if(array[i].y==array[pad].y&&array[i].x<array[pad].x) pad=i;
	}
	std::swap(array[0],array[pad]);
}

int cmp(point a,point b)
{
	if(cross(array[0],a,b)>0) return 1;
	else if(cross(array[0],a,b)==0&&distance(array[0],a)<distance(array[0],b)) return 1;
	else return 0;
}

int gsearch(int n)
{
	init();
	std::sort(array+1,array+n,cmp);
	
	push(array[0]);
	push(array[1]);
	if(n>3) push(array[2]);
	
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
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;i++) array[i].setpoint();
		
		int num=gsearch(n);
		double dis=-(double)(1<<30);
		for(int i=0;i<num;i++)
		{
			for(int j=i+1;j<num;j++)
			{
				double temp=distance(stack[i],stack[j]);
				if(temp>dis) dis=temp;
			}
		}
		
		printf("%.3lf\n",dis);
	}
	return 0;
}