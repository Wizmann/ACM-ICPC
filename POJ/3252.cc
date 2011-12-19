//Result:wizmann	3252	Accepted	396K	0MS	G++	741B
#include <cstdio>
#include <cstring>
#include <cstdlib>

int dp[40][40];
int num[40];

int slove(int x)
{
	int ans=0;
	int pad=0;
	while(x>0)
	{
		num[pad++]=x%2;
		x/=2;
	}

	for(int i=pad-1;i>0;i--)
	{
		for(int j=(i+1)/2;j<i;j++) ans+=dp[i-j-1][j];
	}
	
	int t=1;
	for(int i=pad-2;i>=0;i--)
	{
		if(num[i])
		{
			int temp=t-(pad-i-1-t)-1;
			int loop=(temp+i+1)/2;
			if(loop<0) loop=0;
			for(int j=loop;j<=i;j++) ans+=dp[i-j][j];
			t++;
		}
	}
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	for(int i=0;i<=32;i++) dp[i][0]=dp[0][i]=1;
	for(int i=1;i<=32;i++)
	{
		for(int j=1;j<=32;j++) dp[i][j]=dp[i-1][j]+dp[i][j-1];
	}
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",slove(b+1)-slove(a));
	return 0;
}
