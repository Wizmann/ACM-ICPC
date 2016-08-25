#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010

typedef long long llint;

inline int left(int x){return (x<<1)+1;}
inline int right(int x){return left(x)+1;}

struct node
{
	int l,r;
	llint val,p;

	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
		val=p=0;
	}

	void add(int iv)
	{
		val+=iv;
	}

	bool equal(int x)
	{
		return l==x && r==x;
	}

	bool equal(int il,int ir)
	{
		return l==il && r==ir;
	}

	int getmid()
	{
		return (l+r)>>1;
	}
	
	bool has_next()
	{
		return l!=r;
	}
	
	int size()
	{
		return (r-l+1);
	}
};

node stree[SIZE*3];
int n,m;
const int ROOT=0;

void init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r);
	if(l<r)
	{
		int mid=(l+r)>>1;
		init(l,mid,left(pos));
		init(mid+1,r,right(pos));
	}
}

void insert(int l,int r,int val,int pos=ROOT)
{
	int add=(r-l+1)*val;
	if(stree[pos].equal(l,r)) stree[pos].p+=val;
	else
	{
		stree[pos].add(add);
		int mid=stree[pos].getmid();
		if(r<=mid) insert(l,r,val,left(pos));
		else if(l>mid) insert(l,r,val,right(pos));
		else
		{
			insert(l,mid,val,left(pos));
			insert(mid+1,r,val,right(pos));
		}
	}
}
	
llint query(int l,int r,int pos=ROOT)
{
	if(stree[pos].equal(l,r))
	{
		return stree[pos].val+stree[pos].p*(r-l+1);
	}
	else
	{
		if(stree[pos].p)
		{
			stree[left(pos)].p+=stree[pos].p;
			stree[right(pos)].p+=stree[pos].p;
			stree[pos].val+=stree[pos].p*stree[pos].size();
			stree[pos].p=0;
		}
		int mid=stree[pos].getmid();
		if(r<=mid) return query(l,r,left(pos));
		else if(l>mid) return query(l,r,right(pos));
		else
		{
			return query(l,mid,left(pos))+query(mid+1,r,right(pos));
		}
	}
}

int main()
{
	int a,b,c;
	char cmd[5];
	while(input(n>>m))
	{
		init(0,n-1);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			insert(i,i,a);
		}
		while(m--)
		{
			scanf("%s",cmd);
			if(*cmd=='Q')//Q：查询[a,b]区间和
			{
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(a-1,b-1));
			}
			else
			{
				scanf("%d%d%d",&a,&b,&c);
				insert(a-1,b-1,c);//C：向[a,b]区间的每一个数加上c
			}
		}
	}
	return 0;
}

			

	
