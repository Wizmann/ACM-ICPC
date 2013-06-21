//Result:wizmann	1088	Accepted	360K	0MS	C++	1173B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 128;

const int my[]={-1,0,1,0};
const int mx[]={0,1,0,-1};

int g[SIZE][SIZE];
int dp[SIZE][SIZE];
int n,m;

inline bool inMap(int y,int x)
{
    return y>=0 && y<n && x>=0 && x<m;
}

int dfs(int y, int x)
{
    if(dp[y][x]!=-1) return dp[y][x];
    int res = 1;
    for(int i=0;i<4;i++)
    {
        int ny = y+my[i];
        int nx = x+mx[i];

        if(inMap(ny,nx) && g[ny][nx]<g[y][x])
        {
            res = max(res, dfs(ny,nx)+1);
        }
    }
    dp[y][x] = res;
    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    while(input(n>>m))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans, dfs(i,j));
            }
        }
        print(ans);
    }
    return 0;
}
