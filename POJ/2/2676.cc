#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#define N 9

using namespace std;

typedef struct node
{
	int pos;
	char table[12][12];
	
	inline void clear()
	{
		pos=0;
		memset(table,0,sizeof(table));
	}
	
	void print()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++) printf("%d",table[i][j]);
			printf("\n");
		}
	}
	
	friend bool operator < (const node &a,const node &b)
	{
		if(a.pos>b.pos) return true;
		else return false;
	}
	
	void operator = (const node &a)
	{
		memcpy(this,&a,sizeof(a));
	}
}node;

typedef struct point
{
	int x,y;
	inline void setpoint(int a,int b)
	{
		x=a,y=b;
	}
}point;

priority_queue<node> sear;
node input;
node temp;
node p;
char possible[12];

inline void init()
{
	while(!sear.empty()) sear.pop();
	input.clear();
	scanf("\n");
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%c",&input.table[i][j]);
			input.table[i][j]-='0';
		}
		scanf("\n");
	}
	//input.print();	
}

void getNext(point pos)
{
	int x=pos.x,y=pos.y;
	p=temp;
	memset(possible,0,sizeof(possible));
	
	for(int i=0;i<N;i++)
	{
		possible[p.table[y][i]]=1;
		possible[p.table[i][x]]=1;
	}
	
	x=3*(x/3);y=3*(y/3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++) possible[p.table[y+i][x+j]]=1;
	}
	
	p.pos=0;
	for(int i=1;i<=N;i++)
	{
		if(!possible[i]) p.pos++;
	}
	
	if(!p.pos) return;
	for(int i=1;i<=N;i++)
	{
		if(!possible[i])
		{
			p.table[pos.y][pos.x]=i;
			sear.push(p);
		}
	}
}	

void bfs()
{
	point f;
	int next;
	while(!sear.empty())
	{
		next=0;	
		temp=sear.top();
		sear.pop();
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!temp.table[i][j])
				{
					f.setpoint(j,i);
					next++;
					break;
				}
			}
		}

		if(!next)
		{
			temp.print();
			return;
		}
		else getNext(f);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;	
	scanf("%d",&t);
	while(t--)
	{
		init();
		sear.push(input);
		bfs();
	}
	return 0;
}
		
