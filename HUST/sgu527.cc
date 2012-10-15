//Result:Wizmann	SGU 527	Accepted	1139 KB	671 ms	Visual Studio 8 C++	485 B	2012-10-06 21:07:57
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32
#define MUL 16

int g[SIZE];
int num[1<<MUL];
int n,m;
char mp[SIZE][SIZE];

void init()
{
	for(int i=0;i<(1<<MUL);i++)
	{
		int sum=0;
		for(int j=0;j<MUL;j++)
		{
			if(i & (1<<j)) sum++;
		}
		num[i]=sum;
	}
}

inline int getnum(int x)
{
	return num[x&0xffff]+num[x>>16];
}

int dfs(int deep,int x,int y)
{
	if(deep==n)
	{
		return max(0,getnum(y)-x)+x;
	}
	else
	{
		return min(dfs(deep+1,x+1,y),dfs(deep+1,x,y|g[deep]));
	}
}

int main()
{
	init();
	while(input(n>>m))
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			int tmp=0;
			scanf("%s",mp[i]);
			for(int j=0;j<m;j++)
			{
				if(mp[i][j]=='*')
				{
					tmp|=(1<<j);
				}
			}
			g[i]=tmp;
		}
		print(dfs(0,0,0));
	}
	return 0;
}

/*
#include <cstdio>
#include <algorithm>
int g[32],n,m,num[1<<16];char mp[32];int getnum(int x){return num[x&0xffff]+num[x>>16];}int dfs(int deep,int x,int y){	return deep==n? (std::max(0,getnum(y)-x)+x) : std::min(dfs(deep+1,x+1,y),dfs(deep+1,x,y|g[deep]));}int main(){for(int i=0;i<(1<<16);i++)	for(int j=0;j<16;j++) num[i]+=(i & (1<<j))==0?0:1;scanf("%d%d",&n,&m);for(int i=0;scanf("%s",mp)&&i<n;i++) for(int j=0;j<m;j++) g[i]|=(mp[j]=='*')<<j;printf("%d\n",dfs(0,0,0));return 0;}
*/
