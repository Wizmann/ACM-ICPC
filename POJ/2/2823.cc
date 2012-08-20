#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

typedef struct node
{
	int n;
	int pos;
	
	void setnode(int i)
	{
		scanf("%d",&n);
		pos=i;
	}
	
	friend bool operator < (const node &left,const node &right)
	{
		if(left.n>right.n) return true;
		else return false;
	}
}node;

struct lowercmp
{
	bool operator() (const node &a, const node &b)
	{
		 if(a<b) return false;
		 else return true;
	}
};

struct uppercmp
{
	bool operator() (const node &a, const node &b)
	{
		 if(a<b) return true;
		 else return false;
	}
};

priority_queue<node,vector<node>,uppercmp> up;
priority_queue<node,vector<node>,lowercmp> low;

int resupper[1000010];
int reslower[1000010];
int *u;
int *l;

inline void init()
{
	u=resupper;
	l=reslower;
}

inline void pushupper(int n)
{
	*u=n;
	u++;
}

inline void pushlower(int n)
{
	*l=n;
	l++;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,k;
	int pos;
	node input;
	init();
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		input.setnode(i);
		//printf("%d ",input.n);
		up.push(input);
		low.push(input);
	}
	pushupper(up.top().n);
	pushlower(low.top().n);
	
	pos=1;
	for(int i=k;i<n;i++)
	{
		input.setnode(i);
		up.push(input);
		low.push(input);
		while(up.top().pos<pos)
		{
			//printf("POP:%d\n",up.top().n);
			up.pop();
		}
		pushupper(up.top().n);
		//printf("%d\n",up.top().n);
		
		while(low.top().pos<pos)
		{
			//printf("POP:%d\n",low.top().n);
			low.pop();
		}
		pushlower(low.top().n);
		pos++;
	}
	
	int *p=resupper;
	printf("%d",*p++);
	while(p!=u) printf(" %d",*p++);
	printf("\n");
	
	p=reslower;
	printf("%d",*p++);
	while(p!=l) printf(" %d",*p++);
	printf("\n");
	return 0;
}
