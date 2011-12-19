//Result:wizmann	1584	Accepted	396K	0MS	G++	2012B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define MAXN 1000
#define offset 10000
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
#define min(a,b) (a>b?b:a)

struct point{double x,y;};
struct line
{
	point a,b;
	line(point p1,point p2){a=p1;b=p2;}
};

double vectorProduct(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}//可以进行重载


double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判定凸多边形,顶点按顺时针或逆时针给出,允许相邻边共线
int is_convex(int num,point* p){
	int i,s[3]={1,1,1};
	for (i=0;i<num&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%num],p[(i+2)%num],p[i]))]=0;
	return s[1]|s[2];
}

int inside_convex_v2(point q,int n,point* p){
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[0]&&s[1]|s[2];
}

double distance(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


double disPointToSeg(point p,line l)
{
	point t=p;
	t.x+=l.a.y-l.b.y,t.y+=l.b.x-l.a.x;
	if (vectorProduct(l.a,t,p)*vectorProduct(l.b,t,p)>eps) return min(distance(p,l.a),distance(p,l.b));
	return fabs(vectorProduct(p,l.a,l.b))/distance(l.a,l.b);
}


point peg;
double r;
int n;
point array[500];

int main()
{
	freopen("a.txt","r",stdin);
	while(1)
	{
		scanf("%d",&n);
		if(n<3) break;
		scanf("%lf%lf%lf",&r,&peg.x,&peg.y);
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++) scanf("%lf%lf",&array[i].x,&array[i].y);
		if(!is_convex(n,array)) puts("HOLE IS ILL-FORMED");
		else
		{
			bool flag=true;
			if(inside_convex_v2(peg,n,array))
			{
				for(int i=0;i<n-1;i++)
				{
					line l(array[i],array[i+1]);
					if(disPointToSeg(peg,l)<r)
					{
						flag=false;
						puts("PEG WILL NOT FIT");
						break;
					}
				}
				if(flag) puts("PEG WILL FIT");
			}
			else puts("PEG WILL NOT FIT");
		}
	}
	return 0;
}
