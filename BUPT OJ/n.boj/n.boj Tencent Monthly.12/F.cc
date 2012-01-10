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

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define np next_permutation

#define SOURCE 0
#define SINK n+6
#define SIZE 128

map<char,int> mp;

void init()
{
	mp['S']=1;
	mp['M']=2;
	mp['L']=3;
	mp['X']=4;
	mp['T']=5;
}

int flow[SIZE][SIZE];
int n;
int ans;
char visit[SIZE];
int pre[SIZE];

void EK()
{
	ans=0;
	while(1)
	{
		memset(visit,0,sizeof(visit));
		memset(pre,-1,sizeof(pre));
		queue<int> q;//EK算法使用queue，FF算法使用stack，在某些SPJ里可以尝试一下不同算法
		q.push(SOURCE);
		while(!q.empty())
		{
			int now=q.front();
			q.pop();			
			for(int i=SOURCE;i<=SINK;i++)
			{
				if(flow[now][i]&&!visit[i])//在整数流量时用flow>0就足够了
				{
					q.push(i);
					visit[i]=1;
					pre[i]=now;
				}
			}
		}
			
		if(pre[SINK]==-1) break;
		
		int now=SINK;
		int minf=INF;
		while(now!=SOURCE)
		{
			int p=pre[now];
			minf=min(minf,flow[p][now]);
			now=p;
		}
		now=SINK;
		ans+=minf;
		while(now!=SOURCE)
		{
			int p=pre[now];
			flow[p][now]-=minf;
			flow[now][p]+=minf;
			now=p;
		}
	}
}


int main()
{
	freopen("F.txt","r",stdin);
	init();
	char str[12];
	while(input(n) && n)
	{
		memset(flow,0,sizeof(flow));
		memset(pre,0,sizeof(pre));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;i++)
		{
			flow[SOURCE][i]=1;
			input(str);
			for(int j=mp[str[0]];j<=mp[str[1]];j++) flow[i][n+j]=1;
		}
		for(int i=0;i<5;i++)
		{
			input(flow[n+i+1][SINK]);
		}
		EK();
		//print(ans);
		if(ans==n) print("YES");
		else print("NO");
	}
	return 0;
}
		
