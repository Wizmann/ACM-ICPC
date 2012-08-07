//Result:2012-08-07 23:33:04	Accepted	4348	281MS	24024K	3825 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000100

typedef long long llint;

inline int lowbit(int x)
{
	return x&(-x);
}

struct BIT
{
	llint baum[SIZE];
	void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,llint val)
	{
		while(x<SIZE)
		{
			baum[x]+=val;
			x+=lowbit(x);
		}
	}
	llint sum(int x)
	{
		llint res=0;
		while(x>0)
		{
			res+=baum[x];
			x-=lowbit(x);
		}
		return res;
	}
	llint sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};
		

struct SegBIT
{
	llint baum[SIZE];
	void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,llint val)
	{
		while(x>0)
		{
			baum[x]+=val;
			x-=lowbit(x);
		}
	}
	void addseg(int a,int b,llint val)
	{
		add(a-1,-val);
		add(b,val);
	}
	llint sum(int x)
	{
		llint res=0;
		while(x<SIZE)
		{
			res+=baum[x];
			x+=lowbit(x);
		}
		return res;
	}
};

struct SSBIT
{
	SegBIT A;
	BIT B;
	void init()
	{
		A.init();
		B.init();
	}
	void update(int pos,llint val)
	{
		A.add(pos,val);
		B.add(pos,val*pos);
	}
	void addseg(int a,int b,llint val)
	{
		update(b,val);
		if(a>1) update(a-1,-val);
	}

	llint sum(int x)
	{
		if(x) return A.sum(x)*x+B.sum(x-1);
		else return 0;
	}

	llint sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

struct node
{
	int st,end;
	int nr;
	int next;
	node(){}
	node(int ist,int iend,int inr,int inext)
	{
		nr=inr;
		st=ist;end=iend;
		next=inext;
	}
};

struct query
{
	char type;
	int a,b,c;

	query(){}
	query(char it,int ia,int ib,int ic)
	{
		type=it;
		a=ia;b=ib;c=ic;
	}
};

node history[SIZE>>3];
int head[SIZE];
int n,q;
llint his[SIZE>>3];
deque<query> Q;
SSBIT sb;
int ind;
stack<query> st;
int ask_for_his;

void add_history(int t,int a,int b)
{
	history[ind]=node(a,b,ask_for_his,head[t]);
	head[t]=ind++;
}

void slove()
{
	int t=0;
	for(int j=head[t];j!=-1;j=history[j].next)
	{
		llint t=sb.sum(history[j].st,history[j].end);
		his[history[j].nr]=t;
	}
	for(int i=0;i<q;i++)
	{
		if(Q[i].type=='C')
		{
			st.push(Q[i]);
		}

		if(Q[i].type=='C')
		{
			sb.addseg(Q[i].a,Q[i].b,Q[i].c);
			t++;
			for(int j=head[t];j!=-1;j=history[j].next)
			{
				llint t=sb.sum(history[j].st,history[j].end);
				his[history[j].nr]=t;
			}
		}
		else if(Q[i].type=='Q')
		{
			printf("%I64d\n",sb.sum(Q[i].a,Q[i].b));
		}
		else if(Q[i].type=='H')
		{
			printf("%I64d\n",his[Q[i].a]);
		}
		else if(Q[i].type=='B')
		{
			//TODO This is the most fucking part
			while(t>Q[i].a)
			{
				query now=st.top();
				st.pop();
				sb.addseg(now.a,now.b,-now.c);
				t--;
			}
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	llint a,b,c;
	char cmd[5];
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		ind=ask_for_his=0;
		sb.init();
		while(!st.empty()) st.pop();
		Q.clear();
		memset(his,0,sizeof(his));
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a);
			sb.addseg(i,i,a);
		}
		int t=0;
		for(int i=1;i<=q;i++)
		{
			scanf("%s",cmd);
			if(*cmd=='Q')
			{
				scanf("%I64d%I64d",&a,&b);
				Q.push_back(query('Q',a,b,-1));
			}
			else if(*cmd=='C')
			{
				scanf("%I64d%I64d%I64d",&a,&b,&c);
				Q.push_back(query('C',a,b,c));
				t++;
			}
			else if(*cmd=='H')
			{
				scanf("%I64d%I64d%I64d",&a,&b,&c);
				add_history(c,a,b);//time,[interval]
				Q.push_back(query('H',ask_for_his,-1,-1));
				ask_for_his++;
			}
			else if(*cmd=='B')
			{
				scanf("%I64d",&a);
				Q.push_back(query('B',a,-1,-1));
			}
		}
		slove();
		//puts("");
	}
	return 0;
}
