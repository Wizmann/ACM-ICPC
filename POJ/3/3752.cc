//Result:wizmann	3752	Accepted	728K	0MS	G++	903B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

char g[SIZE][SIZE];
const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};

int n,m;

bool inmap(int y,int x)
{
	if(g[y][x]) return false;
	else if(y<0 || y>=n) return false;
	else if(x<0 || x>=m) return false;
	else return true;
}

void slove(int step)
{
	int x,y;
	x=y=0;
	int ch=0;
	int dir=1;
	while(step--)
	{
		if(!g[y][x]) g[y][x]='A'+ch;
		if(!inmap(y+my[dir],x+mx[dir]))
		{
			dir++;
			dir%=4;
		}
		y+=my[dir];
		x+=mx[dir];
		ch++;
		ch%=26;
	}
}

int main()
{
	input(n>>m);
	memset(g,0,sizeof(g));
	slove(m*n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("   ");
			putchar(g[i][j]);
		}
		puts("");
	}
	return 0;
}

