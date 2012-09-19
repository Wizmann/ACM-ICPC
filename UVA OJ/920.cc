//Result:Wizmann	UVA 920	Accepted	0 KB	16 ms	C++ 4.5.3	1391 B	2012-09-18 10:14:03
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 30010

inline double mul(double x)
{
	return x*x;
}

struct point
{
	double x,y;
	point(){}
	point(double ix,double iy)
	{
		x=ix;y=iy;
	}
	
	friend bool operator < (const point &a,const point &b)
	{
		return a.x>b.x;
	}
};



inline double pntDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

point array[SIZE];
int n;
char peak[SIZE];



int main()
{
	freopen("input.txt","r",stdin);
	int T;
	double a,b;
	input(T);
	while(T--)
	{
		memset(peak,0,sizeof(peak));
		memset(array,0,sizeof(array));
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i]=point(a,b);
		}
		
		
			
		
		sort(array,array+n);

		if(array[0].y>array[1].y)
		{
			for(int i=0;i<n;i+=2) peak[i]=1;
		}
		else
		{
			for(int i=1;i<n;i+=2) peak[i]=1;
		}


		double sp=0;
		double sum=0;
		
		for(int i=0;i<n;i++) if(peak[i])
		{
			if(i==0) sp=array[i].y;
			else if(array[i].y>sp)
			{
				double c=pntDis(array[i],array[i-1]);
				double h=(array[i].y-array[i-1].y);
				double hh=array[i].y-sp;
				
				sum+=c*hh/h;
				sp=array[i].y;
			}
		}

		printf("%.2lf\n",sum);
	}
	return 0;
}



