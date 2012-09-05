//Result:2012-08-16 11:16:13	Accepted	4366	937MS	8012K	3178 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010
#define pb push_back

#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long llint;

inline int left(int x)
{
	return (x<<1)+1;
}
inline int right(int x)
{
	return (x<<1)+2;
}

struct node
{
	int l,r;
	int loy,able;
	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
		loy=-1;
		able=-1;
	}
	bool equal(int il,int ir){return l==il && r==ir;}
	bool equal(int x){return l==x && r==x;}
	inline int getmid(){return (l+r)>>1;}	
	inline bool under_cover(int il,int ir){return il<=l && ir>=r;}
	inline bool has_next(){return l!=r;}
};

struct man
{
	int loy,able;
	man(){}
	man(int il,int ia)
	{
		loy=il;able=ia;
	}
};

struct linka
{
	int val,next;
	linka(){}
	linka(int ival,int inext)
	{
		val=ival;
		next=inext;
	}
};

int n,q;
man mark[SIZE];
map<int,int> loy2id;
map<int,int> id2pos;
int ind,lin;
int lson[SIZE],rson[SIZE];
const int ROOT=0;
node stree[SIZE*3];
linka g[SIZE];
int head[SIZE];


inline void addEdge(int a,int b)
{
	g[lin]=linka(b,head[a]);
	head[a]=lin++;
}

void dfs(int pos)
{
	lson[pos]=rson[pos]=++ind;
	id2pos[pos]=ind;
	for(int i=head[pos];i!=-1;i=g[i].next)
	{
		int next=g[i].val;
		dfs(next);
		rson[pos]=rson[next];
	}
}

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

void stree_insert(int x,int loy,int able,int pos=ROOT)
{
	if(stree[pos].equal(x))
	{
		stree[pos].loy=loy;
		stree[pos].able=able;
	}
	else
	{
		stree[pos].loy=max(loy,stree[pos].loy);
		stree[pos].able=max(able,stree[pos].able);
		int mid=stree[pos].getmid();
		if(x<=mid) stree_insert(x,loy,able,left(pos));
		else stree_insert(x,loy,able,right(pos));
	}
}

int stree_query(int l,int r,int able,int loy,int pos=ROOT)
{
	if(stree[pos].able<=able || stree[pos].loy<=loy) return -1;
	else if(!stree[pos].has_next())
	{
		return stree[pos].loy;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(r<=mid) return stree_query(l,r,able,loy,left(pos));
		else if(l>mid) return stree_query(l,r,able,loy,right(pos));
		else
		{
			int a=stree_query(l,mid,able,loy,left(pos));
			int b=stree_query(mid+1,r,able,a,right(pos));
			return max(a,b);
		}
	}
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	int a,b,c;
	input(T);
	while(T--)
	{
		ind=lin=0;
		loy2id.clear();
		id2pos.clear();
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&q);		
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,i);
			mark[i]=man(b,c);
			loy2id[b]=i;
		}
		dfs(0);
		stree_init(0,ind);
		for(int i=1;i<n;i++)
		{
			stree_insert(id2pos[i],mark[i].loy,mark[i].able);
		}
		while(q--)
		{
			scanf("%d",&c);
			a=lson[c];b=rson[c];
			int val=stree_query(a,b,mark[c].able,0);
			if(val==-1) puts("-1");
			else printf("%d\n",loy2id[val]);
		}
	}
	return 0;
}

//======================================================================

//online_RMQ with BIT
//Result:2012-08-17 12:21:00	Accepted	4366	421MS	6956K	2684 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010
#define pb push_back

struct BIT_RMQ
{
	int baum[SIZE],num[SIZE];
	inline int lowbit(int x)
	{
		return x&(-x);
	}
	void init()
	{
		memset(baum,0,sizeof(baum));
		memset(num,0,sizeof(num));
	}
	int query(int a,int b)
	{
		int ans=num[b];
		while(1)
		{
			ans=max(ans,num[b]);
			if(a==b) break;
			else
			{
				b--;
				while(b-a>=lowbit(b))
				{
					ans=max(ans,baum[b]);
					b-=lowbit(b);
				}
			}
		}
		return ans;
	}

	void modify(int pos,int val)
	{
		num[pos]=val;
		for(int i=pos;i<SIZE;i+=lowbit(i))
		{
			baum[i]=max(val,baum[i]);
			for(int j=1;j<lowbit(i);j<<=1)
			{
				baum[i]=max(baum[i],baum[i-j]);
			}
		}
	}
};

struct man
{
	int loy,able,id;
	man(){}
	man(int il,int ia,int iid)
	{
		loy=il;able=ia;id=iid;
	}
	friend bool operator < (const man& a,const man& b)
	{
		return a.able>b.able;
	}
};

struct query
{
	int val,id;
	query(){}
	query(int ival,int iid)
	{
		val=ival;id=iid;
	}
};

int ind;
BIT_RMQ bit;
map<int,int> loy2id;
int n,q;
vector<int> g[SIZE];
man array[SIZE];
query ask[SIZE];
int lson[SIZE],rson[SIZE],result[SIZE];
int ability[SIZE];


void dfs(int pos)
{
    lson[pos]=rson[pos]=++ind;
    for(int i=0;i<(int)g[pos].size();i++)
    {
        int next=g[pos][i];
        dfs(next);
        rson[pos]=rson[next];
    }
}


bool cmp(const query& a,const query& b)
{
	return ability[a.val]>ability[b.val];
}

void slove()
{
	int ptr=1;
	for(int i=0;i<q;i++)
	{
		int able=ability[ask[i].val];
		int id=ask[i].val;
		
		while(ptr<n && array[ptr].able>able)
		{
			bit.modify(lson[array[ptr].id],array[ptr].loy);
			ptr++;
		}
		int res=bit.query(lson[id],rson[id]);
		if(res==0) result[ask[i].id]=-1;
		else result[ask[i].id]=loy2id[res];
	}
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T,a,b,c;
	input(T);
	while(T--)
	{
		ind=0;
		bit.init();
		loy2id.clear();
		for(int i=0;i<SIZE;i++) g[i].clear();
		scanf("%d%d",&n,&q);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a].pb(i);
			array[i]=man(b,c,i);
			loy2id[b]=i;
			ability[i]=c;
		}
		dfs(0);
		sort(array+1,array+n);
		for(int i=0;i<q;i++)
		{
			scanf("%d",&a);
			ask[i]=query(a,i);
		}
		sort(ask,ask+q,cmp);
		slove();
		for(int i=0;i<q;i++)
		{
			printf("%d\n",result[i]);
		}
	}
	return 0;
}




