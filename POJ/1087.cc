#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>
#include <string>
#include <queue>

#define SIZE 510
#define SOURCE 0
#define SINK 505

using namespace std;

map<string,int> dict;
int g[SIZE][SIZE];
int plug,ele,alt,pos=SOURCE+1;
char used[SIZE];
int pre[SIZE];

int EK()
{
	int flow=0;
	while(1)
	{
		memset(used,0,sizeof(used));
		memset(pre,-1,sizeof(pre));
		
		queue<int> q;
		q.push(SOURCE);
		used[SOURCE]=1;
		
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=1;i<pos;i++)
			{
				if(!used[i]&&g[now][i]>0)
				{
					used[i]=1;
					q.push(i);
					pre[i]=now;
					//printf("%d -> %d\n",now,i);
				}
			}
			if(!used[SINK]&&g[now][SINK]>0)
			{
				used[SINK]=1;
				q.push(SINK);
				pre[SINK]=now;
				//printf("%d -> %d\n",now,SINK);
				break;
			}
		}
		if(pre[SINK]==-1) break;
		int p=SINK;
		int minc=1<<20;
		while(p!=SOURCE)
		{
			int t=pre[p];
			if(g[t][p]<minc) minc=g[t][p];
			p=t;
		}
		
		flow+=minc;
		p=SINK;
		while(p!=SOURCE)
		{
			int t=pre[p];
			g[t][p]-=minc;
			g[p][t]+=minc;
			p=t;
		}
	}
	return flow;
}

int main()
{
	freopen("input.txt","r",stdin);
	char a[100],b[100];
	scanf("%d",&plug);
	for(int i=0;i<plug;i++)
	{
		scanf("%s",a);
		dict[a]=pos;
		g[SOURCE][pos]=1;
		pos++;
	}
	scanf("%d",&ele);
	for(int i=0;i<ele;i++)
	{
		scanf("%s%s",a,b);
		dict[a]=pos;
		g[pos][SINK]=1;
		//printf("ELE->%d\n",pos);
		
		if(dict.count(b)==0) dict[b]=++pos;
		
		g[dict[b]][dict[a]]=1;
		pos++;
	}
	scanf("%d",&alt);
	for(int i=0;i<alt;i++)
	{
		scanf("%s%s",b,a);
		
		if(dict.count(a)==0) dict[a]=pos++;		
		if(dict.count(b)==0) dict[b]=pos++;
		
		g[dict[a]][dict[b]]=1<<20;
	}
	
	printf("%d\n",ele-EK());
	return 0;
}
	
	
		
