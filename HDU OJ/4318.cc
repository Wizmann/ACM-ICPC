//Result:2012-07-26 19:09:27	Accepted	4318	2515MS	42544K	1901 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010

const double inf=1e12;

struct node
{
    int next;
    double cost;
    node(){}
    node(int inext,double icost)
    {
        next=inext;cost=icost;
    }
};

int n;
vector<node> g[SIZE+5];

double spfa(int st,int end)
{
    bitset<SIZE+5> visit;
    double dis[SIZE+5];

    fill(dis,dis+SIZE,-inf);
    dis[st]=0;
    queue<int> q;
    q.push(st);

    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        visit[now]=0;

        for(int i=0;i<(int)g[now].size();i++)
        {
            int next=g[now][i].next;
            if(dis[next]<dis[now]+g[now][i].cost)
            {
                dis[next]=dis[now]+g[now][i].cost;

                if(!visit[next])
                {
                    q.push(next);
                    visit[next]=1;
                }
            }
        }
    }

    return dis[end];
}


int main()
{

    int a,b;
    double c;
    while(input(n))
    {
        for(int i=0;i<n;i++)
        {
            int k;
            g[i].clear();
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                scanf("%d%d",&a,&b);
                if(b==100) continue;
                g[i].push_back(node(a-1,log10((100-b)/100.)));
                //print(i<<' '<<a-1<<' '<<log10((100-b)/100.));
            }
        }
        scanf("%d%d%lf",&a,&b,&c);
        double ans=spfa(a-1,b-1);
        //print(ans);
        if(ans<=-inf) print("IMPOSSIBLE!");
        else printf("%.2f\n",(1-pow(10,ans))*c);
        //print(pow(10,ans));
    }
    return 0;
}
