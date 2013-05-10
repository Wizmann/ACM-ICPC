//Result:Wizmann	2216	Accepted	GNU C++	2.21k	50 ms	9440 KB	2013-04-20 19:57:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 1024;
const double inf = 1e30;
const double eps = 1e-8;

inline double mul(double x){return x*x;}

struct point
{
    double x,y;
    point(){}
    point(double ix,double iy)
    {
        x=ix;y=iy;
    }
    friend bool operator < (const point& a,const point &b)
    {
        return a.x<b.x;
    }
};

inline int zero(double x)
{
    if(x>eps) return 1;
    else if(x<-eps) return -1;
    else return 0;
}

int n;
point array[SIZE];
double dis[SIZE][SIZE];

double pntDis(const point& a,const point& b)
{
    return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

bool online(int i,int j,int k)
{
    if( zero( (array[i].y-array[j].y)*(array[i].x-array[j].x) -
               (array[j].y-array[k].y)*(array[j].x-array[k].x) ) ==0 )
    {
        return true;
    }
    else return false;
}

double solve()
{
    double ans = inf;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double w = dis[i][j];
            if(2*w >= ans) continue;

            double min1,min2;
            min1=min2=inf;
            for(int k=0;k<n;k++)
            {
                if(k!=i && k!=j)
                {
                    if(online(i,j,k)) continue;
                    double r = dis[k][i]+dis[k][j];
                    if(r<min1)
                    {
                        min2=min1;
                        min1=r;
                    }                        
                    else if(r<min2) min2=r;
                }
            }
            ans = min(ans, min1+min2);
        }
    }
    if(ans>=inf) return -1;
    else return ans;
}




int main()
{
    freopen("in","r",stdin);
    int a,b;
    while(input(n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            array[i]=point(a,b);
        }
        sort(array,array+n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=dis[j][i]=pntDis(array[i],array[j]);
            }
        }
        double ans=solve();
        if(ans<0) print(-1);
        else printf("%.6lf\n",ans+eps);
    }
    return 0;
}


