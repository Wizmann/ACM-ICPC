#include <cstdio>
#include <cstring>
#include <cstdlib>

char array[5550];
long long dp[5550];

bool zweiDigit(int n)
{
    int temp=(array[n-1]-'0')*10+(array[n]-'0');
    if(array[n-1]=='0') return false;
    else return temp<=26&&temp>0;
}

int main()
{
    scanf("%s",array);
    while(*array!='0')
    {
        int len=strlen(array);
        memset(dp,0,sizeof(dp));
        dp[0]=1;dp[1]=1;
        for(int i=1;i<len;i++)
        {
            int sum=0;
            if(zweiDigit(i)) sum+=dp[i-1];
            if(array[i]!='0') sum+=dp[i];
            dp[i+1]=sum;
        }
        printf("%lld\n",dp[len]);
        scanf("%s",array);
    }
    return 0;
}
