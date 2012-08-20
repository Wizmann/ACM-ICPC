//Result:wizmann	2311	Accepted	508K	297MS	C++	765B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256

int sg[SIZE][SIZE];

int getSG(int x,int y)
{
	if(x>y) swap(x,y);
	if(sg[x][y]!=-1) return sg[x][y];
	bitset<SIZE*SIZE> visit;
	for(int i=2;i<=x/2;i++)
	{
		int t=getSG(x-i,y)^getSG(i,y);
		visit[t]=1;
	}
	for(int i=2;i<=y/2;i++)
	{
		int t=getSG(x,y-i)^getSG(x,i);
		visit[t]=1;
	}
	int ind=0;
	while(visit[ind]) ind++;
	return sg[x][y]=ind;
}


int main()
{
	int x,y;
	memset(sg,-1,sizeof(sg));
	while(input(x>>y))
	{
		if(getSG(x,y)) print("WIN");
		else print("LOSE");
	}
	return 0;
}
