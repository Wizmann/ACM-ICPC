#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 24
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define mul(x) ((x)*(x))

const double pi=3.1415926;

typedef struct node
{
	int x,r;

	void setnode(int a,int b)
	{
		x=a;r=b;
	}
}node;

int n;
node array[SIZE];

double coscal(double a,double b,double c)
{
	return acos( (mul(a)+mul(b)-mul(c))/(2*a*b) );
}

int main()
{
	freopen("input.txt","r",stdin);
	double area=0;
	input(n);
	int a,b;
	for(int i=0;i<n;i++)
	{
		input(a>>b);
		array[i].setnode(a,b);
		area+=pi*mul(b);
	}
	for(int i=0;i<n-1;i++)
	{
		double t=0;
		double delta=fabs(array[i].x-array[i+1].x);
		
		double aga=coscal(array[i].r,delta,array[i+1].r);
		double agb=coscal(array[i+1].r,delta,array[i].r);
		
		t-=(double)mul(array[i].r)*aga;
		t-=(double)mul(array[i+1].r)*agb;
		t+=(double)mul(array[i].r)*sin(aga*2)/2;
		t+=(double)mul(array[i+1].r)*sin(agb*2)/2;
		
		area+=t;
	}

	printf("%.2lf\n",area);
	return 0;
}
