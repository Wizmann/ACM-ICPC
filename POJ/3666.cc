//Result:wizmann	3666	Accepted	33140K	266MS	C++	964B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2048
#define llint long long
#define INF 1LL<<60

llint dp[SIZE][SIZE];
int array[SIZE],sortArray[SIZE];
int n;

llint slove()
{
	llint ans=INF;
	for(int i=1;i<n;i++)
	{
		llint tmp=dp[i-1][0];
		for(int j=0;j<n;j++)
		{
			tmp=min(tmp,dp[i-1][j]);
			dp[i][j]=tmp+abs(array[i]-sortArray[j]);
		}
		//我们要求的数列是递增的，又因为我们的sortArray是递增的
		//所以关键值就应该是sortArray的顺序
	}
	for(int i=0;i<n;i++) ans=min(ans,dp[n-1][i]);
	return ans;
}
	

int main()
{
	freopen("a.txt","r",stdin);
	while(input(n))
	{
		memset(array,0,sizeof(array));
		memset(sortArray,0,sizeof(sortArray));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%d",array+i);
			sortArray[i]=array[i];
		}
		sort(sortArray,sortArray+n);
		
		//DP初始化，首先制造一个有序的初始状态
		//dp[x][y]中，x是指位置，而y指的是这个位置选取的关键值
		
		for(int i=0;i<n;i++)
		{
			dp[0][i]=abs(array[0]-sortArray[i]);
			//指的是在第0个的位置上，替换到第i个关键值的代价
		}
		print(slove());
	}
	return 0;
}
