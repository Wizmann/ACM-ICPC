//Result:wizmann	2486	Accepted	1256K	438MS	G++	2186B	2011-11-01 12:13:33
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define SIZE 256
#define pb push_back

int gn,gk;
int num[SIZE];
bitset<SIZE> visit;
vector<int> freetree[SIZE];
vector<int> tree[SIZE];
int dp[SIZE][SIZE]；//表示以I为根，在I上走J步的最大苹果数
int back[SIZE][SIZE];//表示以I为根，在I上走J步并返回I的最大苹果数
int tmpBack[SIZE];//表示在不经过Y节点（是I的子节点）并往回走到根的最大苹果数

void makeTree(int pos=0)//从自由树转化为有根树
{
	visit[pos]=1;
	int sz=freetree[pos].size();
	for(int i=0;i<sz;i++)
	{
		if(!visit[freetree[pos][i]])
		{
			tree[pos].pb(freetree[pos][i]);
			makeTree(freetree[pos][i]);
		}
	}
}

void slove(int pos=0)
{
	int sz=tree[pos].size();
	for(int i=0;i<sz;i++) slove(tree[pos][i]);
	
	for(int i=0;i<sz;i++)
	{
		for(int j=gk;j>=1;j--)
		{
			for(int k=2;k<=j;k++)
			{
				back[pos][j]=max(back[pos][j],back[pos][j-k]+back[tree[pos][i]][k-2]);
				//权举选择不同子树，走来回的最大苹果数
			}
		}
	}
	for(int i=0;i<sz;i++)
	{
		//枚举不住回走的结点
		for(int j=0;j<=gk;j++) tmpBack[j]=num[pos];
		for(int j=0;j<sz;j++)
		{
			//枚举往回走的点,得出不经过以T为根的子树的步数
			if(i==j) continue;
			for(int k=gk;k>=1;k--)
			{
				for(int l=2;l<=k;l++)
				{
					tmpBack[k]=max(tmpBack[k],tmpBack[k-l]+back[tree[pos][j]][l-2]);
				}
			}
		}
		for(int j=1;j<=gk;++j)
		{
			//不要搞错,这里J从1开始递增
			for(int k=1;k<=j;++k)
			{
				dp[pos][j]=max(dp[pos][j],dp[tree[pos][i]][k-1]+tmpBack[j-k]);
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(gn>>gk))
	{
		memset(dp,0,sizeof(dp));
		memset(back,0,sizeof(back));
		for(int i=0;i<SIZE;i++)
		{
			freetree[i].clear();
			tree[i].clear();
		}
		for(int i=0;i<gn;i++) input(num[i]);
		for(int i=0;i<gn-1;i++)
		{
			input(a>>b);
			a--;b--;
			freetree[a].pb(b);
			freetree[b].pb(a);
		}
		visit.reset();
		makeTree();
		
		for(int i=0;i<gn;++i)
		{
			for(int j=0;j<=gk;++j) dp[i][j]=back[i][j]=num[i];
		}
		
		slove();
		print(dp[0][gk]);
	}
	return 0;
}
