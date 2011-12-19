#include <stdio.h>

long long dp[35];

int main()
{
    dp[1]=1;
    for(int i=2;i<=30;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i]+=dp[i-j]*dp[j];
        }
    }
    
    int n;
    scanf("%d",&n);
    printf("%lld\n",dp[n]);
    return 0;
}
