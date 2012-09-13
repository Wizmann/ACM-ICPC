//Result:2012-09-11 19:08:16	Accepted	4283	265MS	8524K	954 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define INF 0x3f3f3f3f

int dp[SIZE][SIZE][SIZE];
int que[SIZE];
int n;

int dfs(int st,int end,int show)
{
	if(st==end) return que[st]*show;
	else if(st>end) return 0;
	else if(dp[st][end][show]<INF) return dp[st][end][show];	
	else
	{
		int mini=dfs(st+1,end,show+1)+que[st]*show;
		for(int i=st+1;i<=end;i++)
		{
			int l=dfs(st+1,i,show);
			int r=dfs(i+1,end,show+(i+1-st));
			int now=que[st]*(show+i-st);
			mini=min(mini,l+r+now);
		}
		dp[st][end][show]=mini;
		return mini;
	}
}


int main()
{
	//freopen("input.txt","r",stdin);
	int T,cas=1;
	input(T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&que[i]);
		}
		memset(dp,INF,sizeof(dp));
		printf("Case #%d: ",cas++);
		print(dfs(0,n-1,0));
	}
	return 0;
}

