//Result:wizmann	2187	Accepted	1568K	204MS	G++	1737B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SIZE 100100

typedef struct point
{
	int x,y;
	inline void setpoint(int a,int b){x=a;y=b;}
}point;

point stack[SIZE];
point *p;
inline void push(point n){*p=n;	p++;}
inline void pop(){p--;}
inline void init()
{
	memset(stack,0,sizeof(stack));
	p=stack;
}

point array[100010];
int n;

double distance(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int cmp(point p1,point p2)
{
	if(xmult(p1,p2,array[0])>0) return 1;
	else if(xmult(p1,p2,array[0])==0 && distance(p1,array[0])<distance(p2,array[0])) return 1;
	else return 0;
}
int findtop()
{
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(array[i].y<array[res].y) res=i;
		else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
	}
	return res;
}

int graham()
{
	int top=findtop();
	push(array[top]);
	std::swap(array[0],array[top]);
	std::sort(array+1,array+n,cmp);
	
	push(array[1]);
	push(array[2]);
	for(int i=3;i<n;i++)
	{
		while(xmult(array[i],*(p-1),*(p-2))>0) pop();
		push(array[i]);
	}
	return p-stack;
}

int getans(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		array[i].setpoint(a,b);
	}
	init();
	int ans=0;
	int m=graham();
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++) ans=max(ans,getans(stack[i],stack[j]));
	}
		
	printf("%d\n",ans);
	return 0;
}
