//Result:Aug 28, 2011 5:47:14 PM 	Wizmann 	D - Treasure Island 	MS C++ 	Accepted 	250 ms 	19500 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3
#define SIZE 1010
#define pq priority_queue

typedef struct node
{
	int x,y;

	inline void setnode(int a,int b){x=a;y=b;}
}node;

typedef struct start:public node
{
	char nr;

	inline void setnode(int a,int b,char c)
	{
		x=a;y=b;nr=c;
	}

	friend bool operator < (const start a,const start b)
	{
		return a.nr>b.nr;
	}
}start;

char g[SIZE][SIZE];
int dis[4][SIZE][SIZE];
pq<start> q;
start mv[100010];
int ans=0;
int l,w,m;

inline bool ing(int x,int y)
{
	if(x>=0&&x<w&&y>=0&&y<l) return true;
	else return false;
}

void check(start t)
{
	int x=t.x,y=t.y;
	for(int i=0;i<m;i++)
	{
		int pos;
		switch(mv[i].nr)
		{
			case 'N':pos=NORTH;break;
			case 'S':pos=SOUTH;break;
			case 'E':pos=EAST;break;
			case 'W':pos=WEST;break;
		}
		int ox=x,oy=y;
		x+=mv[i].x;y+=mv[i].y;
		if(!ing(x,y)) return;
		if(pos==NORTH)
		{
			if(y<=dis[NORTH][oy][ox]) return;
		}
		else if(pos==SOUTH)
		{
			if(y>=dis[SOUTH][oy][ox]) return;
		}
		else if(pos==WEST)
		{
			if(x<=dis[WEST][oy][ox]) return;
		}
		else if(pos==EAST)
		{
			if(x>=dis[EAST][oy][ox]) return;
		}
	}
	ans++;
	printf("%c",t.nr);
}



int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d%d",&l,&w);
	for(int i=0;i<l;i++)
	{
		scanf("%s",g[i]);
		for(int j=0;j<w;j++)
		{
			if(g[i][j]>='A'&&g[i][j]<='Z')
			{
				start t;
				t.setnode(j,i,g[i][j]);
				q.push(t);
			}
		}
	}

	int last;
	for(int i=0;i<w;i++)
	{
		last=-1;
		for(int j=0;j<l;j++)
		{
			dis[NORTH][j][i]=last;
			if(g[j][i]=='#') last=j;
		}
	}
	for(int i=0;i<w;i++)
	{
		last=-1;
		for(int j=l-1;j>=0;j--)
		{
			dis[SOUTH][j][i]=last;
			if(g[j][i]=='#') last=j;
		}
	}
	for(int i=0;i<l;i++)
	{
		last=-1;
		for(int j=0;j<w;j++)
		{
			dis[WEST][i][j]=last;
			if(g[i][j]=='#') last=j;
		}
	}
	for(int i=0;i<l;i++)
	{
		last=-1;
		for(int j=w-1;j>=0;j--)
		{
			dis[EAST][i][j]=last;
			if(g[i][j]=='#') last=j;
		}
	}

	int len;
	char d[5];
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s%d",d,&len);
		switch(*d)
		{
			case 'N':mv[i].setnode(0,-len,'N');break;
			case 'S':mv[i].setnode(0,len,'S');break;
			case 'W':mv[i].setnode(-len,0,'W');break;
			case 'E':mv[i].setnode(len,0,'E');break;
		}
	}

	while(!q.empty())
	{
		check(q.top());
		q.pop();
	}
	if(ans) puts("");
	else puts("no solution");
	return 0;
}
