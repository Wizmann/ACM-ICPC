//Result:wizmann	3373	Accepted	16832K	1125MS	G++	1281B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

int dp[SIZE][SIZE*SIZE];
int path[SIZE][SIZE*SIZE][2];
int mod[SIZE][10];
char bigNum[SIZE];
int modNum,len;

void printNum(int cur,int left)
{
	if(cur>=len) return;
	printf("%d",path[cur][left][1]);
	printNum(cur+1,path[cur][left][0]);
}

void DP()
{
	memset(dp,-1,sizeof(dp));
	dp[len][0]=0;
	for(int i=len-1;i>=0;i--)
	{
		int j=(i==0?1:0);//首位不能为0
		for(;j<=9;j++)
		{
			for(int k=0;k<modNum;k++)
			{
				if(dp[i+1][k]==-1) continue;//如果上一位不存在，此位也不存在
				int next=(k+mod[i][j])%modNum;//此处的模值＝(k+上一位的模值)%modNum;
				if(dp[i][next]==-1 || dp[i+1][k]+(j!=bigNum[i]-'0')<dp[i][next])
				//如果dp[i][next]没有被标记 或 dp[i+1][k]的变化次数小于dp[i][next]
				{
					dp[i][next]=dp[i+1][k]+(j!=bigNum[i]-'0');
					path[i][next][0]=k;//上一位是模为K的
					path[i][next][1]=j;//这一位的值是j。。。
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(bigNum>>modNum))
	{
		//Initialize
		len=strlen(bigNum);
		for(int i=0;i<=9;i++) mod[len-1][i]=i%modNum;
		for(int i=len-2;i>=0;i--)
		{
			for(int j=0;j<=9;j++) mod[i][j]=mod[i+1][j]*10%modNum;
		}
		//预处理，将每一位取模后的结果都存储起来
		
		DP();
		printNum(0,0);
		print("");
	}
	return 0;
}



