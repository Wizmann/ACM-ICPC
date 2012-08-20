//Result:wizmann	1496	Accepted	216K	0MS	C++	880B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define print(x) std::cout<<x<<std::endl
#define input(x) std::cin>>x

int dp[15][30];

void init()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=26;j++)
		{
			for(int k=26;k>j;k--) dp[i][j]+=dp[i-1][k];
			dp[i][j]++;
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=26;j++) dp[i][j]+=dp[i][j-1];
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	char word[15];
	init();
	while(input(word))
	{
		bool flag=true;
		for(int i=0;word[i+1];i++)
		{
			if(word[i]>=word[i+1])
			{
				print(0);
				flag=false;
				break;
			}
		}
		if(flag)
		{
			long long ans=0;
			int len=strlen(word);
			for(int i=0;word[i];i++)
			{
				ans+=dp[len-i][word[i]-'a'+1];
				if(i) ans-=dp[len-i][word[i-1]-'a'+1];
			}
			print(ans);
		}
	}
	return 0;
}
