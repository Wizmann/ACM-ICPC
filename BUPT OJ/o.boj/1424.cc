//Result:1424	Accepted	22MS	208K	G++	 1160B	2012-06-10 18:17:07	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 64
#define INF 1<<25

struct point
{
	int x,y;
	point(){}
	point(int i_x,int i_y){x=i_x;y=i_y;}
};

int cmp_x(const void* a,const void* b)
{
	point* ta=(point*)a;
	point* tb=(point*)b;
	return ta->x-tb->x;
}

int cmp_y(const void *a,const void *b)
{
	point* ta=(point*)a;
	point* tb=(point*)b;
	return ta->y-tb->y;
}

int n;
point array[SIZE];

int sum(int type,int val)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(type==0)
		{
			res+=abs(val-array[i].x);
		}
		else
		{
			res+=abs(val-array[i].y);
		}
	}
	return res;
}

int main()
{
	int a,b;
	input(n);
	for(int i=0;i<n;i++)
	{
		input(a>>b);
		array[i]=point(a,b);
	}
	int ansx,ansy;
	ansx=ansy=INF;
	qsort(array,n,sizeof(point),cmp_x);
	for(int i=0;i<n;i++)
	{
		ansx=min(ansx,sum(0,array[i].x));
	}
	qsort(array,n,sizeof(point),cmp_y);
	for(int i=0;i<n;i++)
	{
		ansy=min(ansy,sum(1,array[i].y));
	}
	print(ansx+ansy);
	return 0;
}
		
