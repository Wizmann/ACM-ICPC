//Result:wizmann	2706	Accepted	708K	0MS	G++	4928B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define mul(x) ((x)*(x))
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define SIZE 256

typedef struct point
{
    int x,y;
    
    point():x(-INF),y(-INF){}
    
    point(int i_x,int i_y)
    {
        x=i_x;y=i_y;
    }
    
    void setnode(int i_x,int i_y)
    {
        x=i_x;y=i_y;
    }
    
    void printPoint()
    {
        print(">"<<' '<<x<<' '<<y);
    }
    
    friend bool operator ==(const point& p1,const point& p2)
    {
        return (p1.x==p2.x && p1.y==p2.y);
    }
}point;

typedef struct segment
{
    point p1,p2;
    
    segment(){}
    segment(point i_p1,point i_p2)
    {
        p1=i_p1;
        p2=i_p2;
    }
    
    void setsegment(point i_p1,point i_p2)
    {
        p1=i_p1;
        p2=i_p2;
    }
    void clear()
    {
        p1.setnode(-INF,-INF);
        p2.setnode(-INF,-INF);
    }
    bool operator ==(const segment& seg)
    {
        if(seg.p1==p1 || seg.p1==p2 || seg.p2==p1 || seg.p2==p2) return true;
        else return false;
    }
    
    void printSeg()
    {
        p1.printPoint();
        p2.printPoint();
    }
}segment;

double vectorProduct(point sp,point ep,point op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}//可以进行重载

bool intersect(segment l1,segment l2)
{
    if(mul(l1.p1.x-l1.p2.x)+mul(l1.p1.y-l1.p2.y)==5 && mul(l2.p1.x-l2.p2.x)+mul(l2.p1.y-l2.p2.y)==5)
    {
        if((max(l1.p1.x,l1.p2.x)>min(l2.p1.x,l2.p2.x))&&
            (max(l1.p1.y,l1.p2.y)>min(l2.p1.y,l2.p2.y))&&
            (max(l2.p1.x,l2.p2.x)>min(l1.p1.x,l1.p2.x))&&
            (max(l2.p1.y,l2.p2.y)>min(l1.p1.y,l1.p2.y))&&//快速排斥实验
            fabs((vectorProduct(l1.p1,l2.p1,l2.p2)*vectorProduct(l1.p2,l2.p1,l2.p2))<=eps)&&
            fabs((vectorProduct(l2.p1,l1.p1,l1.p2)*vectorProduct(l2.p2,l1.p1,l1.p2))<=eps))//跨立实验
        {
            return false;
        }
        else return true;
    }
    else return true;
}

int n,k;
vector<point> g[2];
vector<segment> seg[2];
char visit[SIZE];

bool dfs(int pad,int pos)
{
    bool flag=false;
    if(visit[pos]) return false;
    else
    {
        if(pad ==0 && (seg[pad][pos].p1.x==n || seg[pad][pos].p2.x==n)) return true;
        if(pad ==1 && (seg[pad][pos].p1.y==n || seg[pad][pos].p2.y==n)) return true;
        visit[pos]=1;
        for(int i=0;i<(int)seg[pad].size()&&!flag;i++)
        {
            if(!visit[i] && seg[pad][i]==seg[pad][pos])
            {
                flag=dfs(pad,i);
            }
        }
    }
    return flag;
}

bool clearSeg(int pad,segment& tseg)
{
    for(int i=0;i<(int)seg[pad].size();i++)
    {
        if(!(tseg==seg[pad][i]) && !intersect(tseg,seg[pad][i]))
        {
            return false;
        }
    }
    return true;
}

bool win(int pad)
{
    bool flag=false;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<(int)seg[pad].size() && !flag;i++)
    {
        if(seg[pad][i].p1.x==0 || seg[pad][i].p2.x==0)
        {
            flag=dfs(pad,i);
        }
    }
    return flag;
}

int main()
{
    freopen("input.txt","r",stdin);
    int a,b;
    while(input(n>>k) && n+k)
    {
        g[0].clear();
        g[1].clear();
        seg[0].clear();
        seg[1].clear();
        int ans[2]={0,0};
        for(int i=0;i<k;i++)
        {
            input(a>>b);
            point p(a,b);
            segment tseg;
            tseg.clear();
            for(int j=0;j<(int)g[i&1].size();j++)
            {
                if(mul(p.x-g[i&1][j].x)+mul(p.y-g[i&1][j].y)!=5) continue;
                bool flag=true;
                tseg.setsegment(p,g[i&1][j]);
                for(int k=0;k<(int)seg[!(i&1)].size()&&flag;k++)
                {
                    if(intersect(tseg,seg[!(i&1)][k]))
                    {
                        flag=true;
                    }
                    else flag=false;
                }
                if(flag)
                {
                    if(clearSeg(i&1,tseg))
                    {
                        seg[i&1].pb(tseg);
                    }
                    else
                    {
                        //tseg.printSeg();
                    }
                    ans[i&1]++;
                }
            }
            g[i&1].pb(p);
        }
        if(win(0) || win(1)) print("yes");
        else print("no");
    }
    return 0;
}
