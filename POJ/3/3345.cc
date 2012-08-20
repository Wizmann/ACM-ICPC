//Result:wizmann	3345	Accepted	964K	47MS	G++	2241B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 212
#define pb push_back
#define INF 1<<25


struct node
{
	int val;
	vector<int> next;
	
	void clear()
	{
		val=0;
		next.clear();
	}
};

node array[N];
int n,need,ind;
map<string,int> nameToInt;
bitset<N> inQueue;

int dp[N][N];
int num[N];
int tmp[N];

int min(int a,int b,int c)
{
	return min(min(a,b),c);
}

void slove(int pos=0)
{
	//dp[x][y]的含义是，在x节点取(至少)买到y票至少要花的银子
	num[pos]=1;
	dp[pos][1]=array[pos].val;
	for(int i=0;i<(int)array[pos].next.size();i++)
	{
		int nxt=array[pos].next[i];
		slove(nxt);
		num[pos]+=num[nxt];	
		for(int j=0;j<=num[pos];j++) tmp[j]=dp[pos][j];
		//因为在一棵子树内，存在有互斥点，所以先记录下来，再进行DP
		for(int j=0;j<=num[pos]-num[nxt];j++)
		{
			for(int k=1;k<=num[nxt];k++)
			{
				dp[pos][j+k]=min(dp[pos][j+k],dp[nxt][k]+tmp[j],array[pos].val);
				//转化为树状的01背包问题，Trick是如果dp[pos][x]>array[pos].val时
				//dp[pos][x]必为pos点的花费，因为这样可以达到花费最少
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	string tmpStr;
	while(input(tmpStr))
	{
		if(tmpStr[0]=='#') break;
		else n=atoi(tmpStr.c_str());
		input(need);
		
		inQueue.reset();
		nameToInt.clear();
		memset(num,0,sizeof(num));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++) dp[i][j]=INF;
			dp[i][0]=0;
		}
		for(int i=0;i<N;i++) array[i].clear();
		ind=1;
		array[0].val=INF;
		
		int tn=n;
		while(tn--)
		{
			input(tmpStr);
			if(nameToInt.find(tmpStr)==nameToInt.end())
			{
				nameToInt[tmpStr]=ind++;
			}
			int pos=nameToInt[tmpStr];
			input(array[pos].val);
			while(getchar()==' ')
			{
				input(tmpStr);
				if(nameToInt.find(tmpStr)==nameToInt.end())
				{
					nameToInt[tmpStr]=ind++;
				}
				array[pos].next.pb(nameToInt[tmpStr]);
				inQueue[nameToInt[tmpStr]]=1;
			}
		}
		//让人蛋疼菊紧的Input
		for(int i=1;i<=n;i++)
		{
			if(!inQueue[i]) array[0].next.pb(i);
		}//生成一个GOD节点，形成树状
		slove();
		int ans=INF;
		for(int i=need;i<N;i++) ans=min(ans,dp[0][need]);
		print(ans);
	}
	return 0;
}
			
