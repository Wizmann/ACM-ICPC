#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200005

int dp[SIZE];

int manacher(string& str)
{
	memset(dp,0,sizeof(dp));
	string s;
	int n=str.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		s+='#';
		s+=str[i];
	}
	s+='#';
	n=(n<<1)+1;
	int i=0,j=1,k;
	while(i<n)
	{
		while(i-j>=0 && i+j<n && s[i-j]==s[i+j]) j++;
		dp[i]=j-1;
		k=1;
		while(k<=dp[i] && dp[i]-k!=dp[i-k])
		{
			dp[i+k]=min(dp[i-k],dp[i]-k);
			k++;
		}
		i+=k;
		j=max(j-k,0);
	}
	for(i=0;i<n;i++) ans=max(ans,dp[i]);
	return ans;
}


int main()
{
	string str;
	while(input(str))
	{
		print(manacher(str));
	}
	return 0;
}
