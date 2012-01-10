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
#define mp make_pair
#define np next_permutation

int w,h;
char g[32][32];
const int mx[]={0,0,1,-1};
const int my[]={1,-1,0,0};

int dfs(int x,int y)
{
	int res=0;
	if(g[y][x]!='#'&&g[y][x]!='V')
	{
		res++;
		g[y][x]='V';
	}
	for(int i=0;i<4;i++)
	{
		int ty=y+my[i];
		int tx=x+mx[i];
		if(ty<h&&ty>=0 && tx<w&&tx>=0 && g[ty][tx]!='#'&&g[ty][tx]!='V')
		{
			res+=dfs(tx,ty);
		}
	}
	return res;
}

int main()
{
	freopen("B.txt","r",stdin);
	while(input(w>>h))
	{
		if(w+h==0) break;
		int sx,sy;
		memset(g,0,sizeof(g));
		for(int i=0;i<h;i++)
		{
			input(g[i]);
			for(int j=0;g[i][j];j++)
			{
				if(g[i][j]=='@')
				{
					sx=j;sy=i;
				}
			}
		}
		print(dfs(sx,sy));
	}
	return 0;
}
	
