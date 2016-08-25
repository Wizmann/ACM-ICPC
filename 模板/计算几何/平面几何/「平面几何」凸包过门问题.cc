/*
机器人工厂				
Time Limit: 2000MS  Memory Limit: 65536K

Description
第912号工厂，是专门生产机器人的。所有的机器人都是在厂房里面生产，装配完成之后再被送出厂房。所有的机器人的都是一个多边形（机器人的俯视图都是多边形并且都是凸多边形）的造型。厂房门口有一个大门，但是由于时间仓促大门的还没有设计好，希望您来帮忙设计一个大门。
现在将给你所有的生产成的机器人的多边形的周边上的点的坐标，然后希望你来设计大门（大门的高度不用您来设计，您只需要设计大门的宽度），由于需要节约材料，请你输出大门的最小宽度。

Input
首先第一行有一个整数N(3 <= N <= 100)，表示多边形机器人有N个顶点。
然后有N行输入，每行输入两个实数（最多到小数点后2位），每一行都代表该机器人的每个顶点的坐标。
当N 等于0 时，输入结束。

Output
一行数据，代表厂房大门的最小宽度，保留小数点后6位。（结果4舍5入）

Sample Input

3
0 0
1 0
0 1
0

Sample Output
0.707107

Hint
所有的点都是按照顺时针或逆时针的顺序给出的。
*/

//Result:1098 	Accepted	13MS	312K	G++	2636B	2012-10-19 16:09:28	Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 101

const double eps=1e-8;
const double inf=1e12;

struct point
{
	double x,y;
	point(){}
	point(double ix,double iy)
	{
		x=ix;y=iy;
	}
};

inline double xmult(point sp,point ep,point op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

double pntDis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct segment
{
	point p1,p2;
	segment(){}
	segment(const point& ip1,const point& ip2)
	{
		p1=ip1;p2=ip2;
	}
	double distoline(const point &c)
	{
		return fabs(xmult(c,p1,p2))/pntDis(p1,p2);
	}
};

struct polygen
{
	int sz;
	point array[SIZE];
	void init(int isz){sz=isz;}
};

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	double a,b;
	polygen poly;
	while(input(n) && n)
	{
		double ans=inf;
		poly.init(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			poly.array[i]=point(a,b);
		}

		for(int i=0;i<n;i++)
		{
			int j=(i+1)%n;
			double tmp=0;
			for(int k=0;k<n;k++)
			{
				double dis=segment(poly.array[i],poly.array[j]).distoline(poly.array[k]);
				tmp=max(tmp,dis);
			}
			ans=min(ans,tmp);
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}


