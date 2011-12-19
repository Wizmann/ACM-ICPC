//Result: Wizmann	2828	Accepted	11912K	1657MS	C++	1222B

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define left(x) ((x<<1)+1)
#define right(x) ((x<<1)+2)
#define START 0
#define SIZE 200010

typedef struct people
{
	int val,nr;
	
	void setp()
	{
		scanf("%d%d",&nr,&val);
	}
}people;

typedef struct node
{
	int l,r,val;
	
	void setnode(int a,int b,int c)
	{
		l=a;r=b;val=c;
	}
	
	int mid()
	{
		return (l+r)>>1;
	}
}node;

int n;
people q[SIZE];
node stree[SIZE<<3];
int ans[SIZE];

void init(int pos,int l,int r)
{
	stree[pos].setnode(l,r,r-l+1);
	
	if(l<r)
	{
		int m=(l+r)>>1;
		init(left(pos),l,m);
		init(right(pos),m+1,r);
	}
}

void ins(int pos,int p,int val)
{
	stree[pos].val--;
	
	if(stree[pos].l==stree[pos].r) ans[stree[pos].l]=val;
	else
	{
		int t=stree[left(pos)].val;
		if(t>p) ins(left(pos),p,val);
		else ins(right(pos),p-t,val);
	}
}		

int main()
{
	freopen("input.txt","r",stdin);
	
	while(scanf("%d",&n)!=EOF)
	{
		memset(stree,-1,sizeof(stree));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++) q[i].setp();
		
		init(START,0,n-1);
		
		for(int i=n-1;i>=0;i--) ins(START,q[i].nr,q[i].val);
		
		printf("%d",ans[0]);
		for(int i=1;i<n;i++) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
