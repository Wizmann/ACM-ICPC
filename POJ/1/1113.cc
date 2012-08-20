#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

#define N 1000+10

typedef struct point
{
	int x,y;

	void setpoint()
	{
	    scanf("%d%d",&x,&y);
	}
}point;

point mat[N];
point stack[N];
point *p;

inline void push(point n){*p=n;	p++;}
inline void pop(){p--;}


int find(int n)
{
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(mat[i].y<mat[res].y)
		{
			res=i;
		}
		else if(mat[i].y==mat[res].y&&mat[i].x<mat[res].x)
		{
			res=i;
		}
	}
	return res;
}

double distance(point p1,point p2)
{
	return sqrt( (p1.y-p2.y)*(p1.y-p2.y)+(p1.x-p2.x)*(p1.x-p2.x) );
}

int cross(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int cmp(point p1,point p2)
{
	if(cross(p1,p2,mat[0])>0) return 1;
	else if( cross(p1,p2,mat[0])==0 && distance(p1,mat[0])<distance(p2,mat[0]) ) return 1;
	else return 0;
}

int gsearch(int n)
{
	int top=find(n);
	push(mat[top]);

	std::swap(mat[0],mat[top]);

	std::sort(mat+1,mat+n,cmp);

	for(int i=1;i<3;i++) push(mat[i]);
	for(int i=3;i<n;i++)
	{
	    while(cross(mat[i],*(p-1),*(p-2))>=0) pop();
	    push(mat[i]);
	}
	return p-stack;
}

int main()
{
	freopen("input.txt","r",stdin);
	
    double ans=0;
    int m,dis;
    scanf("%d%d",&m,&dis);
    p=stack;

    for(int i=0;i<m;i++) mat[i].setpoint();

    int sum=gsearch(m);

    for(int i=0;i<sum;i++)
    {
        ans+=distance(stack[i],stack[(i+1)%sum]);
    }

    ans+=2*dis*acos(-1.0);
    printf("%d\n",(int)(ans+0.5));
    return 0;
}
