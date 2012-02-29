//Result:Accepted	1142	421MS	988K	2046 B	G++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define INF 0x3fffffff
#define FROM 1
#define TO 2
#define pb push_back

struct node
{
    int dest,dist;
    node(){}
    node(int i_dest,int i_dist)
    {
        dest=i_dest;
        dist=i_dist;
    }
};

int n,m;
vector<node> g[SIZE];
int dis[SIZE];
bitset<SIZE> visit;
int dp[SIZE];

void SPFA(int from)
{
    queue<int> q;
    visit.reset();
    for(int i=0;i<SIZE;i++) dis[i]=INF;
    
    dis[from]=0;
    visit[from]=1;
    q.push(from);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        visit[now]=0;
        
        for(int i=0;i<(int)g[now].size();i++)
        {
            int dest=g[now][i].dest;
            int w=g[now][i].dist;
            if (dis[now]+w<dis[dest])
            {
                dis[dest]=dis[now]+w;
                if (!visit[dest])
                {
                    q.push(dest);
                    visit[dest]=true;
                }
            }
        }
    }
}


int dfs(int from)
{
    if(dp[from]) return dp[from];
    for (int i=0;i<(int)g[from].size();i++)
    {
        int dest = g[from][i].dest;
        if (dis[dest]<dis[from]) dp[from]+=dfs(dest);
    }
    return dp[from];
}

int main()
{
    int from,to,dist;
    while(input(n) && n)
    {
        input(m);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<SIZE;i++) g[i].clear();
        while(m--)
        {
            input(from>>to>>dist);
            g[from].pb(node(to,dist));
            g[to].pb(node(from,dist));
        }
        SPFA(TO);
        dp[TO]=1;
        print(dfs(FROM));
        /*
         * 题意是找到距离家更近的点
         * 所以找到距离家的最短路
         * 所以先SPFA(HOME)
         * 再dfs(OFFICE)
         */
    }
    return 0;
}
