//Result:wizmann	3923	Accepted	260K	16MS	C++	1806B	2012-08-18 15:33:11
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

const int mx[]={0,1,-1,0};
const int my[]={1,0,0,-1};

char g[SIZE][SIZE];
char visit[SIZE][SIZE];
int step[SIZE][SIZE];
int n,m,s;
bitset<SIZE> notok;

inline bool inMap(int y,int x)
{
	return y>=0 && y<n && x>=0 && x<m;
}

bool dfs(int y ,int x,char mark)
{
	if(visit[y][x]==mark && step[y][x]<s) return true;
	else
	{
		visit[y][x]=mark;
		step[y][x]=++s;
		for(int i=0;i<4;i++)
		{
			int ny=y+my[i];
			int nx=x+mx[i];
			if(inMap(ny,nx) && g[ny][nx]==mark && step[ny][nx]!=s-1)
			{
				return dfs(ny,nx,mark);
			}
		}
		return false;
	}
}

void check_two_sides(int y,int x,char now)
{
	set<char> ff;
	for(int i=0;i<x;i++)
	{
		if(g[y][i]!='.' && g[y][i]!=now) ff.insert(g[y][i]);
	}
	for(int i=x+1;i<m;i++)
	{
		if(g[y][i]!='.' && g[y][i]!=now)
		{
			if(ff.find(g[y][i])!=ff.end())
			{
				notok[int(g[y][i])]=1;
			}
		}
	}
}
		
	
int main()
{
	freopen("input.txt","r",stdin);
	char ans[SIZE];
	int ind;

	while(scanf("%d%d",&n,&m)!=EOF && n+m)
	{
		notok.reset();
		s=ind=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",g[i]);
		}
		memset(visit,0,sizeof(visit));
		memset(step,0,sizeof(step));

			
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!visit[i][j] && g[i][j]!='.')
				{
					if(dfs(i,j,g[i][j]))
					{
						check_two_sides(i,j,g[i][j]);
						ans[ind++]=g[i][j];
					}
				}
			}
		}
		sort(ans,ans+ind);
		ans[ind]=0;
		for(int i=0;i<ind;i++)
		{
			if(!notok[int(ans[i])]) putchar(ans[i]);
		}
		puts("");
	}
	return 0;
}
