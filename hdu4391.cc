#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 320
#define PRIME 10007

typedef unsigned uint;

const uint mone=-1;

struct _link
{
	uint key,val;
	int next;
	_link(){}
	_link(uint ikey,uint ival,int inext)
	{
		key=ikey;val=ival;next=inext;
	}
};

struct hash
{
	int head[PRIME];
	_link pool[PRIME];
	int ptr;
	
	inline void init()
	{
		memset(head,-1,sizeof(head));
		ptr=0;
	}

	void add(uint t,int add_val)
	{
		uint pos=t%PRIME;
		int p=head[pos];
		int pre=-1;
		bool find=false;
		while(p!=-1)
		{
			if(pool[p].key==t)
			{
				pool[p].val+=add_val;
				find=true;
				
				if(pool[p].val==0)
				{
					if(pre==-1) head[pos]=-1;
					else pool[pre].next=pool[p].next;
				}
				break;
			}
			else
			{
				pre=p;
				p=pool[p].next;
			}
		}
		if(!find)
		{
			pool[ptr]=_link(t,add_val,head[pos]);
			head[pos]=ptr++;
		}
	}

	int find(uint t)
	{
		uint pos=t%PRIME;
		int p=head[pos];
		while(p!=-1)
		{
			if(pool[p].key==t)
			{
				return pool[p].val;
			}
			else p=pool[p].next;
		}
		return 0;
	}
};

struct node
{
	hash cnum;
	uint clist[SIZE];
	long long lazy;

	void init()
	{
		cnum.init();
		memset(clist,-1,sizeof(clist));
		lazy=-1;
	}

	void cover(int st,int end,int ic)
	{
		if(end-st+1==SIZE)
		{
			lazy=ic;
			cnum.init();
			return;
		}
		else
		{
			if(lazy!=-1)
			{
				fill(clist,clist+SIZE,lazy);
				cnum.add(lazy,SIZE);
				lazy=-1;
			}
			//print(">>"<<st<<' '<<end);
			for(int i=st;i<=end;i++)
			{
				cnum.add(clist[i],-1);
				clist[i]=ic;
			}
			cnum.add(ic,end-st+1);
		}
	}
	int count(int st,int end,uint ic)
	{
		if(lazy!=-1)
		{
			if(ic==lazy) return (end-st+1);
			else return 0;
		}
		else if(end-st+1==SIZE)
		{
			return cnum.find(ic);
		}
		else
		{
			int res=0;
			for(int i=st;i<=end;i++)
			{
				if(clist[i]==ic) res++;
			}
			return res;
		}
	}
};

node wall[SIZE];
int n,q;


void paint_wall(int st,int end,int c)
{
	int st_nr=st/SIZE;
	int end_nr=end/SIZE;
	for(int i=st_nr;i<=end_nr;i++)
	{
		int tst=0;
		if(st<=i*SIZE) tst=0;
		else if(i!=0) tst=st%(i*SIZE);
		else tst=st;
		if(end>=(i+1)*SIZE) wall[i].cover(tst,SIZE-1,c);
		else wall[i].cover(tst,end-i*SIZE,c);
	}
}

int count_wall(int st,int end,int c)
{
	int res=0;
	int st_nr=st/SIZE;
	int end_nr=end/SIZE;
	for(int i=st_nr;i<=end_nr;i++)
	{
		int tst=0;
		if(st<=i*SIZE) tst=0;
		else if(i!=0) tst=st%(i*SIZE);
		else tst=st;
		if(end>=(i+1)*SIZE) res+=wall[i].count(tst,SIZE-1,c);
		else res+=wall[i].count(tst,end-i*SIZE,c);
	}
	return res;
}


int main()
{
	freopen("1002.in","r",stdin);
	freopen("out.txt","w",stdout);
	uint a,b,c,d;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(int i=0;i<SIZE;i++) wall[i].init();
		b=-1;
		c=d=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%u",&a);
			if(a==b) d++;
			else
			{
				if(c!=mone) paint_wall(c,d,b);
				c=d=i;
				b=a;
			}
		}
		paint_wall(c,d,a);

		while(q--)
		{
			scanf("%u%u%u%u",&a,&b,&c,&d);
			if(a==1) paint_wall(b,c,d);
			else printf("%d\n",count_wall(b,c,d));
		}
	}
	return 0;
}




