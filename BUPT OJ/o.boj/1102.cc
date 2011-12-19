#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 10010
#define pb push_back

using namespace std;

typedef struct node
{
	int end,w;
	
	void setnode(int a,int b)
	{
		end=a;w=b;
	}
}node;

vector<node> edge[MAX];
char flag[MAX];
char no[MAX];

int len=0,root=0;
int ans=-1<<20;

void dfs(int pos,int len,char *boolen)
{
	boolen[pos]=1;
	if(len>ans)
	{
		ans=len;
		root=pos;
	}
	
	vector<node>::iterator iter;
	for(iter=edge[pos].begin();iter!=edge[pos].end();iter++)
	{
		if(!boolen[iter->end]) dfs(iter->end,len+iter->w,boolen);
	}
	flag[pos]=0;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int v,e;
	scanf("%d%d",&v,&e);
	
	node input;
	int a,b,c;
	while(e--)
	{
		scanf("%d%d%d",&a,&b,&c);
		input.setnode(b,c);
		edge[a].pb(input);
		input.setnode(a,c);
		edge[b].pb(input);
	}
	
	memset(no,0,sizeof(no));
	int key=0;
	for(int i=1;i<=v;i++)
	{
		if(!no[i])
		{
			ans=-1<<20;
			dfs(i,0,no);
			
			ans=-1<<20;
			memset(flag,0,sizeof(flag));
			dfs(root,0,flag);
			if(ans>key) key=ans;
		}
	}		
	printf("%d\n",key);
	
	return 0;
}
