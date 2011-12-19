//Result:wizmann	3342	Accepted	252K	16MS	C++	1596B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

#define SIZE 205
#define BOSS 0
#define pb push_back

vector<int> g[SIZE];
map<string,int> htable;
int n,pad;
int dp[SIZE][2];
char visit[SIZE];

void baumDP(int pos)
{
	if(visit[pos])
	{
		for(int i=0;i<(int)g[pos].size();i++) baumDP(g[pos][i]);
		for(int i=0;i<(int)g[pos].size();i++)
		{
			int t=g[pos][i];
			dp[pos][1]+=dp[t][0];
			dp[pos][0]+=max(dp[t][0],dp[t][1]);
		}
		dp[pos][1]++;
	}
	else{dp[pos][0]=0;dp[pos][1]=1;}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		memset(dp,0,sizeof(dp));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<=n;i++) g[i].clear();
		htable.clear();
		
		pad=0;
		string temp;
		cin>>temp;
		htable[temp]=BOSS;
		
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>temp;
			if(htable.find(temp)==htable.end()) htable[temp]=++pad;
			a=htable[temp];
			
			cin>>temp;
			if(htable.find(temp)==htable.end()) htable[temp]=++pad;
			b=htable[temp];
			g[b].pb(a);
			visit[b]=1;
		}
		baumDP(BOSS);
		printf("%d ",max(dp[BOSS][0],dp[BOSS][1]));

		if(n==2) puts("No");
		else
		{
			bool flag=true;
			for(int i=BOSS;i<n;i++)
			{
				if(dp[i][1]==dp[i][0])
				{
					for(int j=0;j<(int)g[i].size();j++)
					{
						int t=g[i][j];
						if(dp[t][1]==dp[t][0])
						{
							flag=false;//如果子节点两个值相等，而且这个子节点影响到了其父节点的结果，于是就NO了。。。－ －
							break;
						}
					}
				}
				if(!flag) break;
			}
			if(!flag) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}

