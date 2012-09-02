//Result:2012-08-31 21:32:47	Accepted	4036	421MS	352K	2126 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

const double eps=1e-8;

inline double mul(double x){return x*x;}

inline int zero(double x)
{
    if(x>eps) return 1;
    else if(x<-eps) return -1;
    else return 0;
}

struct point
{
    double x,y;
    point(){}
    point(double ix,double iy){x=ix;y=iy;}
};

int n,m,w;
point peak[SIZE];
point bit[SIZE];
double bitSpeed[SIZE];
double st;

int cmp(const point &a,const point &b)
{
    return a.x<b.x;
}

double calHeight(double h,double v=0)
{
    double deltah=h-st;
    return sqrt(mul(v)+2.*20*deltah);
}

inline bool cover(int a,int b,int c)
{
    double leftx=peak[a].x;
    double rightx=peak[b].x;
    double x=bit[c].x;
    
    if(zero((leftx-x)*(rightx-x))<=0) return true;
    else return false;
}

double slove()
{
    double res=0;
    //sort(bit,bit+m,cmp);
    //sort(peak,peak+n,cmp);
    int ptr=0;
    for(int i=0;i<m;i++)
    {
        ptr=0;
        bit[i].x+=peak[0].x;
        while(!cover(ptr,ptr+1,i)) ptr++;
        double dx=peak[ptr+1].x-peak[ptr].x;
        double dh=peak[ptr+1].y-peak[ptr].y;
        //h=(1.0*(p[j+1].h-p[j].h)/(p[j+1].x-p[j].x))*(pat[i].x-p[j].x) + p[j].h;
        bit[i].y=1.0*dh/dx*(bit[i].x-peak[ptr].x)+peak[ptr].y;
        //printf("%lf %lf %lf %lf\n",dh,dx,(bit[i].x-peak[ptr].x),peak[ptr].y);
        res=max(res,calHeight(bit[i].y,bitSpeed[i]));
    }
    return res;
}

int main()
{
    int T,cas=1;
    double a,b,c;
    input(T);
    while(T--)
    {
        memset(peak,0,sizeof(peak));
        memset(bit,0,sizeof(bit));
        memset(bitSpeed,0,sizeof(bitSpeed));
        scanf("%d%d%d",&n,&m,&w);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a,&b);
            peak[i]=point(a,b);
        }
        st=peak[0].y;
        double res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,calHeight(peak[i].y));
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lf%lf%lf",&a,&b,&c);
            //print(a<<' '<<b<<' '<<c);
            bit[i]=point(a,0);
            bitSpeed[i]=b;
        }
        res=max(res,slove());
        printf("Case %d: %.2lf\n",cas++,res);
    }
    return 0;
}
