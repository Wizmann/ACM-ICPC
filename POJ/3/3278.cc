#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>

#define SIZE 200000

using namespace std;

typedef struct node
{
	int pos;
	int step;
	
	void setnode(int p,int s)
	{
		pos=p;
		step=s;
	}
}node;

queue<node> bfs;
char flag[200000];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int start,cow,min=1<<20;
	node temp,p;
	scanf("%d%d",&start,&cow);
	temp.setnode(start,0);
	bfs.push(temp);
	while(!bfs.empty())
	{
		memcpy(&temp,&(bfs.front()),sizeof(node));
		bfs.pop();
		if(temp.step>min) continue;
		else if(temp.pos==cow) min=temp.step;
		else
		{
			p.setnode(temp.pos+1,temp.step+1);
			if(p.pos<SIZE&&flag[p.pos]==0)
			{
				bfs.push(p);
				flag[p.pos]=1;
			}
			p.setnode(temp.pos-1,temp.step+1);
			if(p.pos>=0&&flag[p.pos]==0)
			{
				bfs.push(p);
				flag[p.pos]=1;
			}
			p.setnode(temp.pos*2,temp.step+1);
			if(p.pos<SIZE&&flag[p.pos]==0)
			{
				bfs.push(p);
				flag[p.pos]=1;
			}
		}
	}
	
	printf("%d\n",min);
	return 0;
}
