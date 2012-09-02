//Result:2012-08-25 23:47:51	Accepted	4391	3171MS	24964K	3365 B	G++	Wizmann
//分段哈希，对一个区间进行覆盖，以及对一个区间的某种颜色个数进行查询
//哈希表的作用是对区间某种颜色的个数进行统计
//对于修改采用Lazy标记，从而降低时间复杂度
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
#define SIZE 512
#define PRIME 10007

typedef unsigned uint;

const uint mone=-1;

struct _link//链表类
{
	uint key,val;
	int next;
	_link(){}
	_link(uint ikey,uint ival,int inext)
	{
		key=ikey;val=ival;next=inext;
	}
};

struct hash//哈希表类
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

struct node//分段哈希类
{
	hash cnum;//记录数据的Hash表，[Key->Value][颜色->个数]
	uint clist[SIZE];//记录本段的颜色
	long long lazy;//Lazy标记，如果本段只有一种颜色，做标记，否则为-1
	bool ready;//修改只修改clist的内容，并不进行统计，所以做标记是否已经统计完

	void init()
	{
		cnum.init();
		memset(clist,-1,sizeof(clist));
		lazy=-1;
		ready=true;
	}
	
	void push()//进行统计
	{
		if(lazy==-1)
		{
			cnum.init();
			lazy=-1;
			for(int i=0;i<SIZE;i++)
			{
				cnum.add(clist[i],1);
			}
		}
		ready=true;
	}
	
	void cover(int st,int end,int ic)//区间覆盖
	{
		if(end-st+1==SIZE) lazy=ic;
		else
		{
			if(lazy!=-1)
			{
				fill(clist,clist+SIZE,lazy);
				lazy=-1;
			}
			for(int i=st;i<=end;i++)
			{
				clist[i]=ic;
			}
		}
		ready=false;
	}
	
	int count(int st,int end,uint ic)//区间查询
	{
		if(!ready) push();
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


void paint_wall(int st,int end,int c)//大区间覆盖
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

int count_wall(int st,int end,int c)//大区间统计
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
