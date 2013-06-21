//Result:3930756	 Jun 21, 2013 9:28:45 AM	Wizmann	 E - Balance	 GNU C++	Accepted	 171 ms	 2900 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 320;

struct entry
{
    int u, v, w;
    entry(){}
    entry(int iu, int iv,int iw)
    {
        u = iu; v = iv; w = iw;
    }
};



int A[SIZE],B[SIZE];
char g[SIZE][SIZE];
int pre[SIZE][SIZE];
vector<entry> ans;

void push_ans(int u, int v, int w)
{
    if(w)
    {
        ans.push_back(entry(u, v, w));
        A[u] -= w;
        A[v] += w;
    }
}

void dfs(int u, int v, int trans)
{
    if(u == v) return;
    int t = pre[u][v];
    int w = min(A[t], trans);
    push_ans(t, v, w);
    dfs(u, t, trans);
    push_ans(t, v, trans - w);
}

void solve(int u,int v)
{
    if(A[u] < B[u]) swap(u, v);
    int trans = min(A[u] - B[u], B[v] - A[v]);
    dfs(u, v, trans);
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,v,e;
    int a,b;
    input(n>>v>>e);
    memset(g,0,sizeof(g));

    for(int i=0;i<n;i++) input(A[i]);
    for(int i=0;i<n;i++) input(B[i]);

    for(int i=0;i<e;i++)
    {
        input(a>>b);
        a--;b--;

        g[a][b]=g[b][a]=1;
        pre[a][b] = a;
        pre[b][a] = b;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(!g[j][k] && g[j][i] & g[i][k])
                {
                    pre[j][k] = pre[i][k];
                    g[j][k] = 1;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(A[i]==B[i]) continue;

        for(int j=0;j<n;j++) if(i!=j && A[j]!=B[j])
        {
            if(g[i][j])
            {
                if((A[i]<B[i]) ^ (A[j]<B[j]))
                {
                    solve(i,j);
                }
            }
        }
    }

    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=B[i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        print(ans.size());
        for(int i=0;i<(int)ans.size();i++)
        {
            print(ans[i].u+1<<' '<<ans[i].v+1<<' '<<ans[i].w);
        }
    }
    else puts("NO");

    return 0;
}




