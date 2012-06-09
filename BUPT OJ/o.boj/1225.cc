//Result:1225	Accepted	860MS	204K	G++	 889B	2012-05-22 11:13:02
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 16
#define INF 1<<25

const int mx[]={1,0};
const int my[]={0,1};

int n,m;
int miniturn;

inline int score(int x,int y){return y+1;}
inline bool check(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<n) return true;
	else return false;
}

void dfs(int x,int y,int sum,int turn,int dir)
{
	if(turn>miniturn) return;
	sum+=score(x,y);
	if(x==n-1&&y==n-1 && sum==m)
	{
		miniturn=min(turn,miniturn);
		return;
	}
	for(int i=0;i<2;i++)
	{
		int nx=x+mx[i];
		int ny=y+my[i];
		if(check(nx,ny))
		{
			dfs(nx,ny,sum,turn+(dir!=i),i);
		}
	}
}



int main()
{
	freopen("input.txt","r",stdin);
	miniturn=INF;
	input(n>>m);
	dfs(0,0,0,0,0);
	dfs(0,0,0,0,1);
	print(miniturn);
	return 0;
}
