//Result:wizmann	1573	Accepted	232K	0MS	C++	1412B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};
const int move=4;

inline int dir(char c)
{
	switch(c)
	{
		case 'N':return 0;
		case 'E':return 1;
		case 'S':return 2;
		case 'W':return 3;
		default:print("ERROR"<<c);break;
	}
	return -1;
}

char g[15][15];
int step[15][15];
int x,y,st;

int maze(int l,int w)
{
	int t=1;
	bool out=false;
	while(!step[l][w]&&!out)
	{
		//print(l<<','<<w<<','<<g[l][w]);
		step[l][w]=t++;
		char ch=g[l][w];
		l+=my[dir(ch)];
		w+=mx[dir(ch)];
		if(l<0||l>=y) out=true;
		else if(w<0||w>=x) out=true;
	}
	if(out) return --t;
	else
	{
		int loop=t-step[l][w];
		int first=step[l][w];
		print(first-1<<" step(s) before a loop of "<<loop<<" step(s)");
		return -1;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d%d",&y,&x,&st)==3)
	{
		if(y+x+st==0) break;
		st--;
		memset(g,0,sizeof(g));
		memset(step,0,sizeof(step));
		for(int i=0;i<y;i++) scanf("%s",g[i]);
		int t=maze(0,st);
		if(t>0)	print(t<<" step(s) to exit");
	}
	return 0;
}

