#include <cstdio>

#define MOD 1000000000

unsigned long long ans[100010];

long long mul(int pad,int n)
{
    if(n==2)
    {
        return ((long long)pad*pad)%MOD;
    }
    else if(n==1) return pad;
    else
    {
        long long temp=mul(pad,n/2);
        if(n%2) return (((long long)temp*temp)%MOD)*pad%MOD;
        else return (long long)temp*temp%MOD;
    }
}
        

int main()
{
	
	freopen("input.txt","r",stdin);
	
    int n;
    while(scanf("%d",&n)!=EOF)
    {
		long long temp=0;
        for(int i=1;i<=n;i++)
        {
			if(!ans[i]) ans[i]=mul(i,i);
            temp+=ans[i];
            temp%=MOD;
        }
        printf("%09lld\n",temp);
    }
    return 0;
}
