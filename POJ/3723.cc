//Result:wizmann	3723	Accepted	1172K	438MS	C++	1079B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using std::priority_queue;

#define SUM (m+n)

typedef struct node
{
	int st,end;
	int cost;
	
	void setnode(int a,int b,int c)
	{
		st=a;end=b;
		cost=c;
	}
	
	friend bool operator < (const node a,const node b)
	{
		return a.cost<b.cost;
	}
}node;

int n,m,r;
priority_queue<node> pq;
int father[20010];

int find(int x)
{
	if(father[x]==x) return x;
	else return father[x]=find(father[x]);
}

int kruskal()
{
	int ans=SUM*10000;
	for(int i=0;i<=SUM+5;i++) father[i]=i;
	while(!pq.empty())
	{
		node t=pq.top();
		pq.pop();
		int a=find(t.st);
		int b=find(t.end);
		if(a!=b)
		{
			father[a]=b;
			ans-=t.cost;
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		while(!pq.empty()) pq.pop();
		scanf("%d%d%d",&n,&m,&r);
		while(r--)
		{
			node t;
			scanf("%d%d%d",&a,&b,&c);
			t.setnode(a,b+n,c);
			pq.push(t);
		}
		printf("%d\n",kruskal());
	}
	return 0;
}
			
