#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

typedef struct node
{
	int st,end;
	int sum;
	
	void setnode(int a,int b,int c)
	{
		st=a;end=b;sum=c;
	}
}node;

node stree[200000];
int t=1;
int ans=0;

inline int left(int a) {return 2*a;}
inline int right(int a){return 2*a+1;}
inline int ave(int a,int b){return (a+b)/2;}


void init(int pos,int st,int end)
{
	int mid=ave(st,end);
	stree[pos].setnode(st,end,0);
	
	if(st<end)
	{
		init(left(pos),st,mid);
		init(right(pos),mid+1,end);
	}
}

int change(int pos,int st,int end,int num)
{
	if(stree[pos].st==st&&stree[pos].end==end)
	{
		int res=num-stree[pos].sum;
		stree[pos].sum=num;
		return res;
	}
	else
	{
		int mid=ave(stree[pos].st,stree[pos].end);
		int plus;
		if(mid+1<=st)
		{
			plus=change(right(pos),st,end,num);
			stree[pos].sum+=plus;
			return plus;
		}
		else if(mid>=end)
		{
			plus=change(left(pos),st,end,num);
			stree[pos].sum+=plus;
			return plus;
		}
		else
		{
			plus=change(left(pos),st,mid,num)+change(right(pos),mid+1,end,num);
			stree[pos].sum+=plus;
			return plus;
		}
	}
}

void query(int pos,int st,int end)
{
	if(stree[pos].st==st&&stree[pos].end==end) ans+=stree[pos].sum;
	else
	{
		int mid=ave(stree[pos].st,stree[pos].end);
		if(mid+1<=st) query(right(pos),st,end);
		else if(mid>=end) query(left(pos),st,end);
		else
		{
			query(left(pos),st,mid);
			query(right(pos),mid+1,end);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	int temp;
	while(scanf("%d",&n)!=EOF&&n)
	{
		printf("Case %d:\n",t++);
		memset(stree,0,sizeof(stree));
		init(1,1,n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			change(1,i,i,temp);
		}
		int ask,a,b;
		char cmd[10];
		scanf("%d",&ask);
		while(ask--)
		{
			scanf("%s%d%d",cmd,&a,&b);
			if(*cmd=='a')
			{
				if(a>b) std::swap(a,b);
				ans=0;
				query(1,a,b);
				printf("%d\n",ans);
			}
			else change(1,a,a,b);
		}
	}
	return 0;
}
			
