//Result:wizmann    3252    Accepted    252K    0MS    C++    1286B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define llint long long
#define SIZE 32
#define eps 1e-4

#define DP

#ifdef DP
#define C(x,y) C[x][y]
int C[SIZE][SIZE];

void init()
{
    for(int i=0;i<SIZE;i++)
    {
        C[0][i]=C[i][i]=1;
    }
    for(int i=2;i<SIZE;i++)
    {
        for(int j=1;j<i;j++)
        {
            C[j][i]=i*C[j-1][i-1]/j;
        }
    }
}
#else

int C(int a,int b)
{
    double res=1;
    for(int i=0;i<a;i++)
    {
        res=res*(b-i)/(i+1);
    }
    return int(res+eps);
}
#endif

llint slove(int x)
{
    llint ans=0;
    int len=0,tx=x;
    while(tx>0)
    {
        len++;
        tx>>=1;
    }
    //低位数值是没有大小限制的，先找低位的排列组合
    for(int i=2;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((j+1)*2<=i) ans+=C(j,i-1);
        }
    }
    //高位数据由于有大小限制，所以一位一位的找。
    //如果为1100,那么10XX都是可以01自由组合的
    //由此推出第二部分的值
    for(int i=len-2,eins=1;i>=0;i--)
    {
        if(x&(1<<i))
        {
            tx=x;
            tx=tx>>(i+1)<<(i+1);
            for(int j=0;j<=i;j++)
            {
                if((j+eins)*2<=len) ans+=C(j,i);
            }
            eins++;
        }
    }
    return ans;
}        

int main()
{
    freopen("e.txt","r",stdin);
    int st,end;
    #ifdef DP
    init();
    #endif
    //print(C(2,10));
    input(st>>end);
    print(slove(end+1)-slove(st));
    return 0;
}
