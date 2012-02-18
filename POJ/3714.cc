//Result:wizmann    3714    Accepted    9148K    2329MS    G++    1630B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200010
#define pb push_back
#define INF 1<<30
#define mul(x) ((x)*(x))
#define abs(x) ((x)>0?(x):-(x))

typedef long long llint;

struct point
{
    llint x,y;
    bool flag;
    
    point(){}
    point(llint i_x,llint i_y,bool i_f)
    {
        x=i_x;y=i_y;flag=i_f;
    }
    
    inline double pointDis(const point &p)
    {
        return sqrt(mul(p.x-x)+mul(p.y-y));
    }
    
    friend bool operator < (const point& a,const point& b)
    {
        if(a.x!=b.x) return a.x<b.x;
        else return a.y<b.y;
    }
};

int n;
point pnt[SIZE];

int ind;

double check(llint l,llint r)
{
    if(l>=r) return INF;
    double ans=INF;
    
    llint mid=(l+r)>>1;
    ans=min(check(l,mid),check(mid+1,r));
    
    int vec[SIZE>>2];
    int ind=0;
    for(int i=l;i<=r;i++)
    {
        if(abs(pnt[i].x-pnt[mid].x)<ans) vec[ind++]=i;
    }
    for(int i=0;i<ind;i++)
    {
        for(int j=i+1;j<ind;j++)
        {
            if(pnt[vec[i]].flag^pnt[vec[j]].flag)
            {
                ans=min(ans,pnt[vec[i]].pointDis(pnt[vec[j]]));
            }
        }
    }
    return ans;
}


int main()
{
    freopen("input.txt","r",stdin);
    llint T,x,y;
    input(T);
    while(T--)
    {
        ind=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&x,&y);
            pnt[ind++]=point(x,y,true);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&x,&y);
            pnt[ind++]=point(x,y,false);
        }
        sort(pnt,pnt+ind);
        llint l=0,r=ind-1;
        printf("%.3f\n",check(l,r));
    }
    return 0;
}

