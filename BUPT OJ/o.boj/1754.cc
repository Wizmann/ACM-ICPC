#include <cstdio>
#include <cstdlib>

#define MOD 100007

int dp[255][255];
int high[255];

int cmp(const void *a,const void *b)
{
    return *(long long*)a-*(long long*)b;
}

int main()
{
	freopen("input.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    while(n&&k)
    {
        for(int i=1;i<=n;i++) scanf("%d",&high[i]);
        qsort(high,n+1,sizeof(int),cmp);
        for(int i=1;i<=n;i++) dp[1][i]=dp[1][i-1]+high[i];
        for(int i=2;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1]+((long long)(high[j]-i+1)*dp[i-1][j-1])%MOD;
            }
        }
        printf("%d\n",dp[k][n]%MOD);
        scanf("%d%d",&n,&k);
    }
    return 0;
}
    
