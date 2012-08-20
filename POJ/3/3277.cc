//Result:wizmann	3277	Accepted	7804K	266MS	G++	3334B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 40010
#define MOD 234569


typedef long long llint;

inline int left(int x)
{
	return (x<<1)+1;
}
inline int right(int x)
{
	return left(x)+1;
}

struct node
{
	int l,r;
	int val,len;

	node(){}
	node(int il,int ir,int ival)
	{
		l=il;r=ir;val=ival;len=0;
	}

	inline int getmid()
	{
		return (l+r)>>1;
	}

	inline bool equal(int il,int ir)
	{
		return l==il && r==ir;
	}
	
	inline bool under_cover(int il,int ir)
	{
		return il<=l && ir>=r;
	}
};

struct query
{
	int st,end,hi;
	query(){}
	query(int ist,int iend,int ihi)
	{
		st=ist;end=iend;hi=ihi;
	}
	friend bool operator < (const query& a,const query& b)
	{
		return a.hi<b.hi;
	}
};

struct hash_node
{
	int val,mir,next;
	hash_node(){}
	hash_node(int ival,int imir,int inext)
	{
		val=ival;mir=imir;next=inext;
	}
};

node stree[SIZE*7];
query city[SIZE];
int n,ind;
int array[SIZE<<1];
const int ROOT=0;
int len[SIZE<<1];
int head[MOD+10];
hash_node hash[SIZE<<1];
int hash_ptr;





void stree_init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r,-1);
	if(l<r)
	{
		int mid=(l+r)>>1;
		stree_init(l,mid,left(pos));
		stree_init(mid+1,r,right(pos));
		stree[pos].len=stree[left(pos)].len+stree[right(pos)].len;
	}
	else stree[pos].len=len[l];
}

void stree_fill(int st,int end,int val,int pos=ROOT)
{
	if(stree[pos].equal(st,end))
	{
		stree[pos].val=val;
	}
	else
	{
		if(stree[pos].val!=-1)
		{
			stree[left(pos)].val=stree[pos].val;
			stree[right(pos)].val=stree[pos].val;
			stree[pos].val=-1;
		}
		int mid=stree[pos].getmid();
		if(mid>=end) stree_fill(st,end,val,left(pos));
		else if(mid<st) stree_fill(st,end,val,right(pos));
		else
		{
			stree_fill(st,mid,val,left(pos));
			stree_fill(mid+1,end,val,right(pos));
		}
	}
}

llint stree_cal(int st,int end,int pos=ROOT)
{
	if(stree[pos].under_cover(st,end) && stree[pos].val!=-1)
	{
		//print(stree[pos].len<<" "<<stree[pos].val);
		return (llint)stree[pos].len*stree[pos].val;
	}
	else
	{
		return (llint)stree_cal(st,end,left(pos))+stree_cal(st,end,right(pos));
	}
}

int hash_find(int val)
{
	for(int i=head[val%MOD];i!=-1;i=hash[i].next)
	{
		if(hash[i].val==val) return hash[i].mir;
	}
	return -1;
}

void hash_insert(int val,int mir)
{
	hash[hash_ptr]=hash_node(val,mir,head[val%MOD]);
	head[val%MOD]=hash_ptr++;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	ind=hash_ptr=0;
	input(n);
	memset(head,-1,sizeof(head));
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		city[i]=query(a,b,c);
		array[ind++]=a;
		array[ind++]=b;
	}
	sort(array,array+ind);
	int ptr=0;
	for(int i=0;i<ind;i++)
	{
		if(hash_find(array[i])==-1)
		{
			if(array[i]==array[i+1]) continue;
			hash_insert(array[i],ptr);
			if(i!=ind-1)
			{
				len[ptr]=array[i+1]-array[i];
				ptr++;
			}
		}
	}
	sort(city,city+n);
	stree_init(0,ptr);
	for(int i=0;i<n;i++)
	{
		//printf("%d<->%d   %d\n",hash[city[i].st],hash[city[i].end],city[i].hi);
		stree_fill(hash_find(city[i].st),hash_find(city[i].end)-1,city[i].hi);
	}
	print(stree_cal(0,ptr));
	return 0;
}
		

	
