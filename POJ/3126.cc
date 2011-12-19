#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <bitset>
#include <iostream>

using namespace std;

int ans;
bitset<10020> prim;
bitset<10020> hash;

typedef struct node
{
	int num;
	int step;
	
	void setnode(int a,int b)
	{
		num=a;step=b;
	}
}node;

void init()
{
	prim[1]=1;
	for(int i=2;i<=10000;i+=2) prim[i]=1;
	for(int i=3;i<=101;i+=2)
	{
		if(!prim[i])
		{
			for(int j=i;j<=10000;j+=i) prim[j]=1;
		}
	}
}

inline int pow(int i)
{
	int res=1;
	while(i--) res*=10;
	return res;
}

void bfs(int a,int b)
{
	queue<node> q;
	node number;
	number.setnode(a,0);
	q.push(number);
	while(!q.empty())
	{
		number=q.front();
		//printf("%d\n",number.num);
		int now=number.num;
		int s=number.step;
		q.pop();
		if(s>ans) continue;
		if(now==b)
		{
			ans=s;
			continue;
		}
		for(int i=1;i<=4;i++)
		{
			int t=now;
			t=t/pow(i)*pow(i)+t%pow(i-1);
			for(int j=0;j<=9;j++)
			{
				int in=t+pow(i-1)*j;
				if(!hash[in]&&in>=1000&&!prim[in])
				{
					number.setnode(in,s+1);
					q.push(number);
					hash[in]=1;
				}
			}
		}
	}
}
			

int main()
{
	freopen("input.txt","r",stdin);
	int n,a,b;
	init();
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		ans=1<<20;
		hash.reset();
		bfs(a,b);
		printf("%d\n",ans);
	}
	return 0;
}
		
