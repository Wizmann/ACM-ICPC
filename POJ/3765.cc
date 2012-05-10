//Result:wizmann	3765	Accepted	760K	0MS	G++	1493B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define GRAPH 128
#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define TOP 0
#define BUTTOM 23

char graph[GRAPH][GRAPH]={
"         _",
"       _/ \\_",
"     _/ \\_/ \\_",
"   _/ \\_/ \\_/ \\_",
" _/ \\_/ \\_/ \\_/ \\_",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"  \\_/ \\_/ \\_/ \\_/",
"    \\_/ \\_/ \\_/",
"      \\_/ \\_/",
"        \\_/"
};

int n;
char g[GRAPH][GRAPH];
void draw(int x,int y,char name)
{
	//print(name<<' '<<x<<' '<<y);
	if(y<=6)
	{
		int move=abs(x-4);
		x=(x<<1)+1;
		y=21-(y<<1)-(move);
		g[y][x]=name;
		
	}
	else
	{
		y=10-y;
		int move=abs(x-4);
		x=(x<<1)+1;
		y=1+(y<<1)-move;
		g[y][x]=name;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char cmd[5];
	char name[5];
	while(input(n) && n)
	{
		int pos;
		memcpy(g,graph,sizeof(graph));
		for(int i=0;i<n;i++)
		{
			scanf("%s%s",cmd,name);
			sscanf(cmd+1,"%d",&pos);
			draw(*cmd-'A',pos,*name);
		}
		for(int i=0;i<23;i++) puts(g[i]);
	}
	return 0;
}
