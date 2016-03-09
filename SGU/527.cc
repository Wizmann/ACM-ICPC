/*
Explode 'Em All
Time Limit: 3000MS		Memory Limit: 524288KB

Description
The prime minister of Berland decided to build a new city in the country. It's hard to describe the excitement of all Berland citizens, but indeed this is great news from the economic, social and cultural standpoints.

The land in Berland is occupied almost entirely and it's very hard to find free space for construction, so it was decided to build the city on a stony terrain. The map of this terrain is represented as an nx m grid, where each cell of the grid is either an empty space or a rock.

Of course, before construction is started, the given terrain must be completely cleared from rocks. As you may guess, you were hired to complete this mission. Your goal is to destroy all rocks by dropping bombs from a plane. A bomb can be dropped on any cell of the map, and you are free to select where you want to drop each bomb. When a bomb targeted for cell (i, j) reaches the ground, it destroys all rocks in row i and also all rocks in column j of the grid. If cell (i, j) contains a rock, this rock is also destroyed.

Please help the prime minister of Berland to find the minimum number of bombs required to completely clear the given terrain from rocks.

Input
The first line of input contains two integers n and m (1 ≤ n,m ≤ 25) — the number of rows and columns correspondingly. Each of the next n lines contains m characters describing the terrain. An empty space is denoted by ".", while a rock is denoted by "*".

Output
Write a single integer to the output — the minimum numbers of bombs required for destroying all rocks on the terrain.

Sample Input

8 10
..........
..***..*.*
.*.......*
.*.......*
.*.......*
.....*****
..........
.........*

3 4
....
....
....


sample output

2
0

Hint
In the first sample test it's only required to drop 2 bombs from a plane: one bomb to cell (2,2) and another bomb to cell (6, 10). Row and column indices in this explanation are 1-based.
*/

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

