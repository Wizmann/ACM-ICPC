//Result:2012-08-12 13:44:40	Accepted	4351	812MS	11016K	3495 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
#define FORCE 1024

inline int left(int x){return (x<<1)+1;}
inline int right(int x){return (x<<1)+2;}

struct node
{
	int l,r,val;
	int now,lson,rson;
	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
		val=now=lson=rson=0;
	}
	inline void init(int ival)
	{
		val=now=lson=rson=(1<<ival);
	}
	inline int getmid(){return (l+r)>>1;}
	inline int equal(int il,int ir){return l==il&&r==ir;}
	inline int has_next(){return l!=r;}
};

struct result
{
	int val,now,lson,rson;
	result(){}
	result(int ival,int inow,int ilson,int irson)
	{
		val=ival;
		now=inow;
		lson=ilson;
		rson=irson;
	}
};

node stree[SIZE*3];
int n;
int k[SIZE];
int mp[FORCE+10][FORCE+10];
const int ROOT=0;

void init()
{
	for(int i=0;i<FORCE;i++)
	{
		for(int j=0;j<FORCE;j++)
		{
			for(int a=0;a<=9;a++) if(i&(1<<a))
			{
				for(int b=0;b<=9;b++) if(j&(1<<b))
				{
					int val=(a+b-1)%9+1; 
					mp[i][j]|=(1<<val);
				}
			}
		}
	}
}

void stree_init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r);
	if(l==r) stree[pos].init(k[l]);
	else if(l<r)
	{
		int mid=(l+r)>>1;
		stree_init(l,mid,left(pos));
		stree_init(mid+1,r,right(pos));

		stree[pos].val=mp[stree[left(pos)].val][stree[right(pos)].val];
		stree[pos].lson=stree[left(pos)].lson \
							| mp[stree[left(pos)].val][stree[right(pos)].lson];
		stree[pos].rson=stree[right(pos)].rson \
							| mp[stree[right(pos)].val][stree[left(pos)].rson];
		stree[pos].now=stree[left(pos)].now \
						| stree[right(pos)].now \
						| mp[stree[left(pos)].rson][stree[right(pos)].lson];
	}
}

result stree_query(int l,int r,int pos=ROOT)
{
	if(stree[pos].equal(l,r))
	{
		return result(stree[pos].val,stree[pos].now,stree[pos].lson,stree[pos].rson);
	}
	else
	{
		int mid=stree[pos].getmid();
		if(r<=mid) return stree_query(l,r,left(pos));
		else if(l>mid) return stree_query(l,r,right(pos));
		else
		{
			result a=stree_query(l,mid,left(pos));
			result b=stree_query(mid+1,r,right(pos));

			int val=mp[a.val][b.val];
			//val代表[l,r]区间的DigitalRoot
			//mp[a.val][b.val]，由于a.val和b.val都只有一个"1"位，所以mp[a.val][b.val]==DigitalRoot(a+b)，也只有一位
			int lson=a.lson | mp[a.val][b.lson];
			//lson是指[l,r]区间的前辍，由a（左边）的lson与a.val与b.lson的和组成
			int rson=b.rson | mp[a.rson][b.val];
			//同上
			int now = a.now | b.now | mp[a.rson][b.lson];
			//now代表当前区间能表示的DigitalRoot的种类数
			//a.now | b.now 父节点是继承子节点的可行值（这个好理解）
			//mp[a.rson][b.lson]是指在[l,r]的中点mid处，[...mid][mid...]这种类型的合并
			
			return result(val,now,lson,rson);
		}
	}
}


int main()
{
	
	int T,a,b,q;
	input(T);
	init();
	int res[10];
	int cas=1;
	while(T--)
	{
		printf("Case #%d:\n",cas++);
		input(n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			k[i]=(a-1)%9+1;
		}
		stree_init(1,n);
		input(q);
		while(q--)
		{
			scanf("%d%d",&a,&b);
			result r=stree_query(a,b);
			int ptr=0,val=9;
			memset(res,-1,sizeof(res));
			while(ptr<5 && val>=0)
			{
				if(r.now & (1<<val))
				{
					res[ptr++]=val;
				}
				val--;
			}
			for(int i=0;i<5;i++)
			{
				if(i) printf(" ");
				printf("%d",res[i]);
			}
			puts("");
		}
		if(T) puts("");
	}
	return 0;
}
