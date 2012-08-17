//Result:wizmann	3667	Accepted	3840K	688MS	C++	3725B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010
#define INF 1<<25

inline int left(int x){return (x<<1)+1;}
inline int right(int x){return (x<<1)+2;}

struct node
{
	int l,r,val;
	int now,lson,rson;
	int st;//本段最长区间的开始位置

	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
		val=0;
		now=lson=rson=cover();
		st=il;
	}

	inline int getmid(){return (l+r)>>1;}
	inline int equal(int il,int ir)
	{
		return l==il && r==ir;
	}
	inline int cover()
	{
		return (r-l+1);
	}
	inline bool has_next()
	{
		if(l==r) return false;
		else return true;
	}
};

node stree[SIZE*3];
int n,q;
const int ROOT=0;

void stree_init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r);
	if(l<r)
	{
		int mid=(l+r)>>1;
		stree_init(l,mid,left(pos));
		stree_init(mid+1,r,right(pos));
	}
}

void stree_cover(int l,int r,int val,int pos=ROOT)
{
	if(stree[pos].equal(l,r))
	{
		stree[pos].val=val;
		if(val==0)
		{
			stree[pos].now=stree[pos].lson=stree[pos].rson=stree[pos].cover();
			stree[pos].st=stree[pos].l;
		}
		else
		{
			stree[pos].now=stree[pos].lson=stree[pos].rson=0;
			stree[pos].st=INF;
		}
		
	}
	else
	{
		if(stree[pos].val!=-1)
		{
			stree_cover(stree[left(pos)].l,stree[left(pos)].r,stree[pos].val,left(pos));
			stree_cover(stree[right(pos)].l,stree[right(pos)].r,stree[pos].val,right(pos));
			stree[pos].val=-1;
		}

		int mid=stree[pos].getmid();
		if(r<=mid) stree_cover(l,r,val,left(pos));
		else if(l>mid) stree_cover(l,r,val,right(pos));
		else
		{
			stree_cover(l,mid,val,left(pos));
			stree_cover(mid+1,r,val,right(pos));
		}

		stree[pos].now=0;
		stree[pos].st=INF;
		if(stree[left(pos)].now>stree[pos].now)
		{
			stree[pos].now=stree[left(pos)].now;
			stree[pos].st=stree[left(pos)].st;
		}
		if(stree[right(pos)].now>stree[pos].now)
		{
			stree[pos].now=stree[right(pos)].now;
			stree[pos].st=stree[right(pos)].st;
		}
		if(stree[left(pos)].rson+stree[right(pos)].lson>stree[pos].now)
		{
			stree[pos].now=stree[left(pos)].rson+stree[right(pos)].lson;
			stree[pos].st=stree[left(pos)].r-stree[left(pos)].rson+1;
		}

		if(stree[left(pos)].lson==stree[left(pos)].cover())
		{
			stree[pos].lson=stree[left(pos)].cover()+stree[right(pos)].lson;
		}
		else stree[pos].lson=stree[left(pos)].lson;
		

		if(stree[right(pos)].rson==stree[right(pos)].cover())
		{
			stree[pos].rson=stree[right(pos)].cover()+stree[left(pos)].rson;
		}
		else stree[pos].rson=stree[right(pos)].rson;
	}
	//printf("POS:%d L:%d R:%d VAL:%d NOW:%d LSON:%d RSON:%d ST:%d\n",
	//		pos,stree[pos].l,stree[pos].r,stree[pos].val,stree[pos].now,stree[pos].lson,stree[pos].rson,stree[pos].st);
}

int stree_query(int len,int pos=ROOT)
{
	int res=INF;
	if(stree[pos].now>=len)
	{
		res=min(res,stree[pos].st);
		if(stree[pos].has_next())
		{
			res=min(res,stree_query(len,left(pos)));
			if(stree[left(pos)].rson && stree[left(pos)].rson+stree[right(pos)].lson>=len)
			{
				res=min(res,stree[left(pos)].r-stree[left(pos)].rson+1);
			}
			if(stree[right(pos)].l<res)
			{
				res=min(res,stree_query(len,right(pos)));
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cmd,a,b;
	while(input(n>>q))
	{
		stree_init(1,n);
		while(q--)
		{
			scanf("%d",&cmd);
			if(cmd==1)
			{
				scanf("%d",&a);
				int pos=stree_query(a);
				printf("%d\n",pos<INF?pos:0);
				if(pos<INF) stree_cover(pos,pos+a-1,1);
			}
			else
			{
				scanf("%d%d",&a,&b);
				stree_cover(a,a+b-1,0);
			}
		}
		
	}
	return 0;
}


