//Result:2012-08-02 21:37:32	Accepted	4337	15MS	400K	1490 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256
#define pb push_back

int n,m;
int visit[SIZE];
stack<int> st;
vector<int> g[SIZE];

bool dfs(int pos,int step=0)
{
    visit[pos]=step;
    st.push(pos);
    for(int i=0;i<(int)g[pos].size();i++)
    {
        int next=g[pos][i];
        if(visit[next]==-1)
        {
            if(dfs(next,step+1)) return true;
        }
        else if(visit[next]+n-1==step)
        {
            return true;
        }
    }
    visit[pos]=-1;
    st.pop();
    return false;
}

int main()
{
    int a,b;
    while(input(n>>m))
    {
        memset(visit,-1,sizeof(visit));
        while(!st.empty()) st.pop();
        for(int i=0;i<SIZE;i++) g[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].pb(b);
            g[b].pb(a);
        }
        if(dfs(1))
        {
            bool flag=false;
            while(!st.empty())
            {
                if(flag) printf(" ");
                else flag=true;
                printf("%d",st.top());
                st.pop();
                //There is a pe point;
            }
            puts("");
        }
        else puts("no solution");
    }
    return 0;
}
