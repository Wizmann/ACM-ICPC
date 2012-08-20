//Result:wizmann    2228    Accepted    808K    125MS    G++    1312B    
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 3850
#define INF 1<<30

int dp[2][SIZE][2];
//dp[x][y][z(0,1)]数组的意义是:在现在处于第x个时间段，已经休息了y时间段，现在的状态是(清醒/迷糊)
int array[SIZE];
int n,b;

int slove(bool ring=false)
{
    int pos=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=b;j++)
        {
            dp[pos][j][0]=max(dp[pos^1][j][0],dp[pos^1][j][1]);
            //=>max(保持清醒状态，从睡眠中醒过来)
            dp[pos][j][1]=max(dp[pos^1][j-1][0], j>1?dp[pos^1][j-1][1]+array[i]:0);
            //=>max(从这点开始睡，在这点接着睡)
        }
        pos^=1;
    }
    if(!ring) return max(dp[pos^1][b][0],dp[pos^1][b][1]);
    else return dp[pos^1][b][1];
}
    

int main()
{
    freopen("input.txt","r",stdin);
    while(input(n>>b))
    {
        int ans=-INF;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) input(array[i]);
        ans=max(ans,slove(false));//普通线性解
        
        memset(dp,0,sizeof(dp));
        //去环文艺解法
        //Eg. 有4个时间段
        //把环展开成线：
        // Nr.0 1 2 3 | 0 1 2 3
        //    0 1 2 3 | 4 5 6 7
        //如果属于环状情况，那么，在4点必为深睡眠
        dp[1][1][1]=array[0];//预处理：在3点处迷糊，4点睡着
        ans=max(ans,slove(true));
        print(ans);//213输出答案
    }
    return 0;
}
