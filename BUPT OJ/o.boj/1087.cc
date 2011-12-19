//Result:1087 	Accepted	440MS	344K	G++	740B	2011-11-04 10:33:16	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define pb push_back

char visit[SIZE];
int n,m;
std::vector<int> g[SIZE];

int dfs(int pos)
{
    int sum=1;
    visit[pos]=1;
    int sz=g[pos].size();
    for(int i=0;i<sz;i++)
    {
        if(!visit[g[pos][i]]) sum+=dfs(g[pos][i]);
    }
    return sum;
}
    

int main()
{
    int a,b,sum=0;
    input(n>>m);
    for(int i=0;i<m;i++)
    {
        input(a>>b);
        g[a].pb(b);
    }
    
    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        sum+=dfs(i)-1;
    }
    
    print( (n*(1+n)/2-sum-n) );
    return 0;
}
