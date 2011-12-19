#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <iostream>

using namespace std;

#define SIZE 100000
#define UNKNOWN -1
#define COLOR 30

typedef struct node
{
	int l,r;
	int color;
	
	void setnode(int a,int b,int c)
	{
		l=a;r=b;color=c;
	}
}node;

inline int left(int n){return (n<<1)+1;}
inline int right(int n){return (n<<1)+2;}
inline int mid(int a,int b){return (a+b)>>1;}

int len,t,ask;
node stree[SIZE*4];
char color[COLOR+5];
int ans;

void init(int pos,int l,int r)
{
	stree[pos].setnode(l,r,1);
	if(l<r)
	{
		int m=mid(l,r);
		init(left(pos),l,m);
		init(right(pos),m+1,r);
	}
}

void setcolor(int pos,int l,int r,int c)
{
	if(stree[pos].l==l&&stree[pos].r==r) stree[pos].color=c;
	else
	{
		int m=mid(stree[pos].l,stree[pos].r);
		if(stree[pos].color!=UNKNOWN)
		{
			setcolor(left(pos),stree[pos].l,m,stree[pos].color);
			setcolor(right(pos),m+1,stree[pos].r,stree[pos].color);
		}
		stree[pos].color=UNKNOWN;		
		if(l>m) setcolor(right(pos),l,r,c);
		else if(r<=m) setcolor(left(pos),l,r,c);
		else
		{
			setcolor(left(pos),l,m,c);
			setcolor(right(pos),m+1,r,c);
		}
	}
}

inline void newcolor(int c)
{
	if(!color[c])
	{
		color[c]=1;
		ans++;
	}
}

void query(int pos,int l,int r)
{
	if(stree[pos].color!=UNKNOWN) newcolor(stree[pos].color);
	else
	{
		int m=mid(stree[pos].l,stree[pos].r);
		if(l>m) query(right(pos),l,r);
		else if(m>=r) query(left(pos),l,r);
		else
		{
			query(left(pos),l,m);
			query(right(pos),m+1,r);
		}
	}
}		
	
int main()
{
	freopen("input.txt","r",stdin);
	char cmd[5];
	int a,b,c;
	scanf("%d%d%d",&len,&t,&ask);
	init(0,1,len);
	while(ask--)
	{
		scanf("%s%d%d",cmd,&a,&b);
		if(a>b) swap(a,b);
		if(*cmd=='C')
		{
			scanf("%d",&c);
			setcolor(0,a,b,c);
		}
		else
		{
			scanf("%d%d",&a,&b);
			memset(color,0,sizeof(color));
			ans=0;
			query(0,a,b);
			printf("%d\n",ans);
		}
	}
	return 0;
}
