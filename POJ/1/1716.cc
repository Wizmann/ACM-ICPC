//Result:wizmann    1716    Accepted    1328K    922MS    G++    1413B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define SIZE 10010

struct node
{
    int dest,cost;
    node(){}
    node(int i_dest,int i_cost)
    {
        dest=i_dest;
        cost=i_cost;
    }
};

vector<node> g[SIZE];
int n;

int spfa(int st,int end)
{
    int dis[SIZE];
    fill(dis,dis+SIZE,INF);
    bitset<SIZE> visit;
    queue<int> q;

    q.push(st);
    visit[st]=1;
    dis[st]=0;

    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        visit[now]=0;

        for(int i=0;i<(int)g[now].size();i++)
        {
            int next=g[now][i].dest;
            int cost=g[now][i].cost;

            if(dis[now]+cost<dis[next])
            {
                dis[next]=dis[now]+cost;
                if(!visit[next])
                {
                    visit[next]=1;
                    q.push(next);
                }
            }
        }
    }
    return dis[end];
}

int main()
{
    freopen("input.txt","r",stdin);
    int a,b;
    while(input(n) && n)
    {
        int start=INF,end=-INF;
        for(int i=0;i<SIZE;i++) g[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            a++;b++;
            if(a>b) swap(a,b);
            g[a-1].push_back(node(b,-2));
            start=min(start,a-1);
            end=max(end,b);
        }
        for(int i=start;i<end;i++)
        {
            g[i].push_back(node(i+1,0));
            g[i+1].push_back(node(i,1));
        }
        print(-spfa(start,end));
    }
    return 0;
}
        


