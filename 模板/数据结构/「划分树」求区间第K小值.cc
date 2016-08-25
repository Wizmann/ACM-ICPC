#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define DIVSIZE SIZE*3
#define LOGSIZE 20

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
			m[x]=-1;val[x]=vt[1].val;
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

divtree DT;

int main()
{
	int num[SIZE];//输入数列，从1开始
	int n,m;
	int a,b,c;

	while(input(n>>m))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",num+i);
		}
		DT.init(num,n);//划分树初始化
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			printf("%d\n",num[DT.kth(a,b,c)]);
			//返回的是第K小数在数列中的位置
		}
	}
	return 0;
}
