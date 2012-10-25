/*
Paint The Wall
Time Limit: 10000MS		Memory Limit: 32768KB

Description
As a amateur artist, Xenocide loves painting the wall. The wall can be considered as a line consisting of n nodes. Each node has its own color.

Xenocide spends all day in front of the wall. Sometimes, he paints some consecutive nodes so that these nodes have the same color. When he feels tired, he focuses on a particular color and counts the number of nodes that have this color within a given interval.

Now Xenocide is tired of counting, so he turns to you for help.
 
Input
The input consists of several test cases.
The first line of each test case contains two integer n, m(1<=n, m<=100000) indicating the length of the wall and the number of queries.
The following line contains N integers which describe the original color of every position.
Then m lines follow. Each line contains 4 non-negative integers a, l, r, z(1<=a<=2, 0<=l<=r<n ,0<=z<231).
a = 1 indicates that Xenocide paints nodes between l and r and the resulting color is z.
a = 2 indicates that Xenocide wants to know how many nodes between l and r have the color z.
 
Output
Print the corresponding answer for each queries.
 
Sample Input
5 5
1 2 3 4 0
2 1 3 3
1 1 3 1
2 1 3 3
2 0 3 1
2 3 4 1
 
Sample Output
1
0
4
1
*/

/*
n个单位长度，m个操作
n个数，表示n个单位长度中起始颜色
m行， a, l, r, z
a== 1表示把l到r涂为z色（z>= 0 && z<= 2^31)
a==2 表示询问l到r为z色的有多少
*/

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
