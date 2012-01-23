//Result:Wizmann     E - Lucky Subsequence     GNU C++    Accepted     280 ms     6300 KB

//参考代码by: Archon.JK

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define elif else if
#define pb push_back
#define MOD 1000000007
#define DPSize 1<<10
//any sequence of length n has exactly 2^n different subsequences 
//and max length == 10
#define PRESize 100005

typedef long long llint;

map<int,int> numMap;
int n,k;
int dp[DPSize][DPSize];
int ind,cnt;

int F[PRESize],R[PRESize];

int fastpow(int a,int b)//快速幂取模
{
    int r=1;
    while(b)
    {
        if(b&1) r=llint(r)*a%MOD;
        a=llint(a)*a%MOD;
        b>>=1;
    }
    return r;
}

void init()
{
    F[0]=R[0]=1;
    
    //求i!%MOD的值
    for(int i=1;i<PRESize;i++) F[i]=llint(F[i-1])*i%MOD;
    
    //关键点在这里！
    //欧拉定理：
    //    if(a,b 互素):
    //    => ( a^eular(b) )%b == 1
    //因为在题目中，MOD是一个大素数，所以eular(MOD)==MOD-2
    //    => ( i^(MOD-2) )%MOD == 1
    //    => (R[i]*F[i])%MOD ==1
    for(int i=1;i<PRESize;i++) R[i]=llint(R[i-1])*fastpow(i,MOD-2)%MOD;
}

llint C(int n, int m)
{
    if(m>n || m<0 || n<0) return 0;
    return llint(F[n])*R[m]%MOD*R[n-m]%MOD;
    //C(n,m)==n!/(n-m)!/m!
    //    =>(F[n]*R[n-m]*R[m])%MOD
}

bool lucky(int x)//是否是幸运数
{
    while(x)
    {
        if(x%10!=4 && x%10!=7) return false;
        x/=10;
    }
    return true;
}

int main()
{
    input(n>>k);
    int tmpNum;
    ind=1;cnt=0;
    vector<int> num;
    init();

    for(int i=0;i<n;i++)
    {
        input(tmpNum);
        bool isLucky=lucky(tmpNum);
        //题意是：对于幸运数字，成01背包
        //对于普通数字，成无限背包
        if(isLucky) numMap[tmpNum]++;//幸运数字要记录每一个字串的对就数目
        else cnt++;//无限背包只要记录总数目就好
        //A subsequence is considered lucky
        //if it does not contain two identical lucky numbers
    }

    num.pb(0);//占位
    for(map<int,int>::iterator iter=numMap.begin();iter!=numMap.end();iter++)
    {
        num.pb(iter->second);//只要数目
        ind++;
    }
    
    dp[0][0]=1;//背包：0个东西，0个重量，有1种方法
    for(int i=1;i<ind;i++)
    {
        for(int j=0;j<=i;j++)
        {
            //明显的0/1背包
            dp[i][j]=dp[i-1][j];
            if(j) dp[i][j]=(dp[i][j]+llint(dp[i-1][j-1])*num[i])%MOD;
            //因为有数量的条件，所以要乘一个num[i]
        }
    }
    llint ans=0;
    for(int i=0;i<ind;i++)
    {
        //因为题目中对顺序没做要求，所以可以用C
        //C表示在cnt个普通数字中，挑出k-i个
        
        llint now=C(cnt,k-i);// <- THIS IS FABULOUS
        
        //dp[ind-1][i]表示从ind-1个幸运子串中选出i个的组合个数
        ans=(ans+now*dp[ind-1][i])%MOD;
    }
    print(ans%MOD);
    return 0;
}
            
        
