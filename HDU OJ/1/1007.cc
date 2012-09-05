//Result:2012-07-17 10:10:27	Accepted	1007	1093MS	2052K	2194 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
#define eps 1e-9
#define inf 1e10

inline int zero(double x)
{
    if(x<-eps) return -1;
    else if(fabs(x)<eps) return 0;
    else return 1;
}

inline double mul(double x)
{
    return x*x;
}

struct point
{
    double x,y;
    point(){}
    point(double i_x,double i_y)
    {
        x=i_x;y=i_y;
    }
    friend bool operator == (const point& pa,const point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};


inline double pointDis(point p1,point p2)
{
    return sqrt(mul(p1.x-p2.x)+mul(p1.y-p2.y));
}


int n;
point array[SIZE+5];


bool cmp(const point& a,const point& b)
{
    return a.x<b.x;
}

double minDisPointPair(int st,int end)
{
    double res=inf;
    
    
    if(end-st<=3)
    {
        for(int i=st;i<=end;i++)
        {
            for(int j=i+1;j<=end;j++)
            {
                res=min(res,pointDis(array[i],array[j]));
            }
        }
        return res;
    }
    else
    {
        int mid=(st+end)>>1;
        res=min(res,minDisPointPair(st,mid));
        res=min(res,minDisPointPair(mid+1,end));
        double left=array[mid].x-res;
        double right=array[mid].x+res;
        
        int a=lower_bound(array+st,array+end+1,point(left,-1),cmp)-array;
        int b=lower_bound(array+st,array+end+1,point(right,-1),cmp)-array;
        b=min(end,b);
        for(int i=a;i<=b;i++)
        {
            for(int j=i+1;j<=b;j++)
            {
                res=min(res,pointDis(array[i],array[j]));
            }
        }
        return res;
    }
}
    
        

int main()
{
	freopen("input.txt","r",stdin);
    double a,b;
    while(input(n) && n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a,&b);
            array[i]=point(b,a);
        }
        sort(array,array+n,cmp);
        printf("%.2f\n",minDisPointPair(0,n-1)/2.0);
    }
    printf("%.4lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
