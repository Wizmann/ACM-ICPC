//Using Seg-Tree
//Result: Wizmann	3321	Accepted	49032K	625MS	C++	 2236B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 100010

using namespace std;

inline int left(int n){return (n<<1)+1;}
inline int right(int n){return (n<<1)+2;}
inline int mid(int a,int b){return (a+b)>>1;}

typedef struct node
{
	int l,r;
	int apple;
	
	inline void setnode(int a,int b,int c)
	{
		l=a;r=b;apple=c;
	}
}node;

node stree[SIZE*4];
node hash[SIZE];
int g[SIZE][100];
int n;
int nr=1;

void init(int pos,int l,int r)
{
	stree[pos].setnode(l,r,0);
	if(l<r)
	{
		int m=mid(l,r);
		init(left(pos),l,m);
		init(right(pos),m+1,r);
	}
}

void settree(int pos,int l,int r,int plus)
{
	if(stree[pos].l==l&&stree[pos].r==r)
	{
		stree[pos].apple+=plus;		
	}
	else
	{
		if(stree[pos].l<=l&&stree[pos].r>=r) stree[pos].apple+=plus;
		int m=mid(stree[pos].l,stree[pos].r);
		if(l>m) settree(right(pos),l,r,plus);
		else if(r<=m) settree(left(pos),l,r,plus);
		else
		{
			settree(left(pos),l,m,plus);
			//settree(right(pos),m+1,r,plus);
		}
	}
}

int query(int pos,int l,int r)
{
	if(stree[pos].l==l&&stree[pos].r==r)
	{
		return stree[pos].apple;
	}
	else
	{
		int m=mid(stree[pos].l,stree[pos].r);
		if(l>m) return query(right(pos),l,r);
		else if(r<=m) return query(left(pos),l,r);
		else
		{
			int res=query(left(pos),l,m)+query(right(pos),m+1,r);
			return res;
		}
	}
}
	

void dfs(int now)
{
	int l=nr;
	nr++;
	for(int i=1;i<=g[now][0];i++)
	{
		nr++;
		dfs(g[now][i]);
	}
	int r=nr;
	hash[now].setnode(l,r,1);
	settree(0,l,r,1);
}

void pb(int a,int b)
{
	g[a][0]++;
	g[a][g[a][0]]=b;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,m;
	char cmd[3];
	scanf("%d",&n);
	init(0,1,2*n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		pb(a,b);
	}
	dfs(1);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",cmd);
		if(*cmd=='Q')
		{
			scanf("%d",&c);
			printf("%d\n",query(0,hash[c].l,hash[c].r));
		}
		else
		{
			scanf("%d",&c);
			if(hash[c].apple==1)
			{
				settree(0,hash[c].l,hash[c].r,-1);
				hash[c].apple=0;
			}
			else
			{
				settree(0,hash[c].l,hash[c].r,1);
				hash[c].apple=1;
			}
		}
	}
	return 0;
}
		
//Using Baum-Array
//Result:Wizmann	3321	Accepted	43648K	407MS	C++	1339B

/*
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 100005

typedef struct node
{
	int l,r,apple;
	
	inline void setnode(int a,int b,int c)
	{
		l=a;r=b;apple=c;
	}
}node;

int baum[SIZE];
node hash[SIZE];
int n;
int g[SIZE][100];
int nr=1;

inline int lowbit(int x){return x&(-x);}
inline void pb(int a,int b)
{
	g[a][0]++;
	g[a][g[a][0]]=b;
}

void setbaum(int pos,int plus)
{
	while(pos<SIZE)
	{
		baum[pos]+=plus;
		pos+=lowbit(pos);
	}
}

inline void init()
{
	memset(baum,0,sizeof(baum));
}

int sum(int pos)
{
	int res=0;
	while(pos>0)
	{
		res+=baum[pos];
		pos-=lowbit(pos);
	}
	return res;
}

inline int query(int l,int r)
{
	return sum(r)-sum(l-1);
}

void dfs(int pos=1)
{
	hash[pos].l=nr++;
	for(int i=1;i<=g[pos][0];i++)
	{
		nr++;
		dfs(g[pos][i]);
	}
	hash[pos].r=nr;
	hash[pos].apple=1;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,m;
	char cmd[5];
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		pb(a,b);
	}
	dfs();
	for(int i=1;i<=n;i++) setbaum(hash[i].l,1); 
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d",cmd,&c);
		if(*cmd=='C')
		{
			if(hash[c].apple==1)
			{
				setbaum(hash[c].l,-1);
				hash[c].apple=0;
			}
			else
			{
				setbaum(hash[c].l,1);
				hash[c].apple=1;
			}
		}
		else printf("%d\n",query(hash[c].l,hash[c].r));
	}
	return 0;
}
*/
