//Result:wizmann    3155    Accepted    904K    3094MS    G++    2247B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 1<<25
#define eps 1e-8
#define pb push_back
#define mul(x) ((x)*(x))
#define SOURCE 0
#define SINK n+1


vector<int> cnc[SIZE];
int n,m;
int xrange[SIZE];
vector<int> g[SIZE];
bitset<SIZE> visit;
int pre[SIZE];
double flow[SIZE][SIZE];


void makeEdge(double mid)
{
    for(int i=0;i<SIZE;i++) g[i].clear();
    memset(flow,0,sizeof(flow));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)cnc[i].size();j++)
        {
            g[i].pb(cnc[i][j]);
            flow[i][cnc[i][j]]=1;
        }
        g[SOURCE].pb(i);
        flow[SOURCE][i]=m;
        g[i].pb(SINK);
        flow[i][SINK]=m+2.0*mid-xrange[i];
    }
}

double EK()
{
    double ans=0;
    memset(pre,0,sizeof(pre));
    while(1)
    {
        visit.reset();
        memset(pre,-1,sizeof(pre));
        queue<int> q;//EK算法使用queue，FF算法使用stack，在某些SPJ里可以尝试一下不同算法
        q.push(SOURCE);
        while(!q.empty())
        {
            int now=q.front();
            q.pop();            
            for(int i=0;i<(int)g[now].size();i++)
            {
                int t=g[now][i];
                if(flow[now][t]>eps&&!visit[t])//在整数流量时用flow>0就足够了
                {
                    q.push(t);
                    visit[t]=1;
                    pre[t]=now;
                }
            }
        }
            
        if(pre[SINK]==-1) break;
        
        int now=SINK;
        double minf=(double)(INF);
        while(now!=SOURCE)
        {
            int p=pre[now];
            minf=min(minf,flow[p][now]);
            now=p;
        }
        now=SINK;
        ans+=minf;
        while(now!=SOURCE)
        {
            int p=pre[now];
            flow[p][now]-=minf;
            flow[now][p]+=minf;
            now=p;
        }
    }
    return ans;
}


int main()
{
    int a,b;
    double flow;
    input(n>>m);
    for(int i=0;i<m;i++)
    {
        input(a>>b);
        cnc[a].pb(b);cnc[b].pb(a);
        xrange[a]++;xrange[b]++;//记录度
    }
    
    if(m==0)//特殊数据的处理
    {
        printf("1\n1\n");
        return 0;
    }
    
    double l=0,r=m;//二分答案
    while((r-l)*mul(n)>=1.)
    {
        double mid=(l+r)/2;
        makeEdge(mid);//每次重新建一次图
        flow=EK();
        flow=(m*n-flow)/2.0;
        if(flow>eps) l=mid;
        else r=mid;
    }
    
    //计算出二分结果，再运算出结果
    makeEdge(l);
    flow=EK();
    
    //输出点集中点的个数，以及各个点的编号
    print((int)visit.count());
    for(int i=1;i<=n;i++)
    {
        if(visit[i]) print(i);
    }
    return 0;
}
    
