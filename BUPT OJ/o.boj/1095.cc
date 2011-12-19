#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define elif else if
#define SIZE 310
#define INF 1<<25

typedef struct node
{
    int to,len;

    void setNode(int a,int b)
    {
        to=a;len=b;
    }
}node;

vector<node> g[SIZE];
int n,m;
int st,end;
int dp[SIZE];
bitset<SIZE> visit;
int dis[SIZE];

bool dij()
{
    for(int i=0;i<=n;i++) dis[i]=INF;
    dis[st]=0;
    visit.reset();
    memset(dp,0,sizeof(dp));
    dp[st]=1;
    for(int tim=0;tim<=n;tim++)
    {
        int mini=INF,pos;
        for(int i=0;i<=n;i++)
        {
            if(dis[i]<mini&&!visit[i])
            {
                mini=dis[i];
                pos=i;
            }
        }
        if(mini>=INF) continue;
        visit[pos]=1;
        for(int i=0;i<(int)g[pos].size();i++)
        {
            int t=g[pos][i].to;
            int len=g[pos][i].len;

            if(!visit[t])
            {
                //print(pos<<' '<<t<<' '<<mini);
                if(dis[t]>dis[pos]+len)
                {
                    dp[t]=dp[pos];
                    dis[t]=dis[pos]+len;
                }
                elif(dis[t]==dis[pos]+len) dp[t]+=dp[pos];
            }
        }
    }
    if(dis[end]<INF) return true;
    else return false;
}



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        input(n>>m);
        for(int i=0;i<SIZE;i++) g[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            node tmp;
            tmp.setNode(b,c);
            g[a].pb(tmp);
            tmp.setNode(a,c);
            g[b].pb(tmp);
        }
        scanf("%d%d",&st,&end);
        if(dij()) print(dis[end]<<' '<<dp[end]);
        else print("Poor Javaman");
        if(t) print("");
    }
    return 0;
}

