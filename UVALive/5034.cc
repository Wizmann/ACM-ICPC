//Result:5034	Jewel	Accepted	C++	0.576	2012-09-15 12:52:02
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
#define DIVSIZE SIZE*4
#define LOGSIZE 20

typedef long long llint;

struct POOL
{
	enum{POOLSIZE=SIZE*LOGSIZE};
	int memo[POOLSIZE],ptr;
	void init(){ptr=0;}
	int* malloc(int len)
	{
		ptr+=len;
		return memo+ptr-len;
	}
};

struct VAL
{
	int val,rank;
	VAL(){}
	VAL(int iv,int ir)
	{
		val=iv;rank=ir;
	}
	friend bool operator < (const VAL &a,const VAL &b)
	{
		return a.val<b.val;
	}
};

struct divtree
{
	POOL p;
	int lk[DIVSIZE],rk[DIVSIZE],m[DIVSIZE],*s[DIVSIZE],val[DIVSIZE],tp;
	VAL tmp[SIZE],v[SIZE];

	void init(int num[],int n)
	{
		for(int i=1;i<=n;i++)
		{
			tmp[i]=VAL(num[i],i);
		}
		sort(tmp+1,tmp+n+1);
		for(int i=1;i<=n;i++)
		{
			v[tmp[i].rank]=VAL(tmp[i].rank,i);
		}
		p.init();
		tp=0;
		build(n,v);
	}
	int build(int n,VAL vt[])
	{
		int x=++tp;
		if(n!=1)
		{
			m[x]=n>>1;
			s[x]=p.malloc(n+1);
			s[x][0]=0;
			for(int i=1,j=0,k=0;i<=n;i++)
			{
				if(vt[i].rank<=m[x])
				{
					s[x][i]=s[x][i-1]+1;
					vt[++j]=vt[i];
				}
				else
				{
					s[x][i]=s[x][i-1];
					tmp[++k]=vt[i];
					tmp[k].rank-=m[x];
				}
			}
			for(int i=m[x]+1,j=1;i<=n;i++,j++) vt[i]=tmp[j];
			lk[x]=build(m[x],vt);
			rk[x]=build(n-m[x],vt+m[x]);
		}
		else
		{
			m[x]=-1;
			val[x]=vt[1].val;
		}
		return x;
	}


	int kth(int l,int r,int k,int x=1)
	{
		if(m[x]==-1) return val[x];
		if(s[x][r]-s[x][l-1]>=k) return kth(s[x][l-1]+1,s[x][r],k,lk[x]);
		return kth(l-s[x][l-1],r-s[x][r],k-s[x][r]+s[x][l-1],rk[x]);
	}
};

struct node
{
	int type;
	int a,b,c;
	node(){}
	node(int itype,int ia,int ib=-1,int ic=-1)
	{
		type=itype;
		a=ia;b=ib;c=ic;
	}
};

divtree DT;
int array[SIZE];
int sz,ind;
node op[SIZE<<1];

int main()
{
	int Q,cas=1;
	char cmd[24];
	llint ans[5];
	int a,b,c;
	while(input(Q))
	{
		memset(ans,0,sizeof(ans));
		ind=0;
		sz=1;
		while(Q--)
		{
			scanf("%s",cmd);
			if(*cmd=='I')
			{
				scanf("%d",&a);
				array[sz++]=a;
				op[ind++]=node(0,a);
			}
			else
			{
				int type=cmd[6]-'0';
				if(type==1)
				{
					scanf("%d%d%d",&a,&b,&c);
					op[ind++]=node(type,a,b,c);
				}
				else
				{
					scanf("%d",&a);
					op[ind++]=node(type,a);
				}
			}
		}
		DT.init(array,sz-1);
		
		printf("Case %d:\n",cas++);

		int cnt=0;
		for(int i=0;i<ind;i++)
		{
			if(op[i].type==0) cnt++;
			else if(op[i].type==1)
			{
				ans[0]+=array[DT.kth(op[i].a,op[i].b,op[i].c)];
				//print("Q1: "<<array[DT.kth(op[i].a,op[i].b,op[i].c)]);
			}
			else if(op[i].type==2)
			{
				int l=1,r=cnt;
				c=op[i].a;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					int num=array[DT.kth(1,cnt,mid)];
					if(num>=c) r=mid-1;
					else l=mid+1;
				}
				//print("Q2: "<<l);
				ans[1]+=l;
			}
			else
			{
				//print("Q3: "<<array[DT.kth(1,cnt,op[i].a)]);
				ans[2]+=array[DT.kth(1,cnt,op[i].a)];
			}
		}
		for(int i=0;i<3;i++) print(ans[i]);
	}
	return 0;
}
						



