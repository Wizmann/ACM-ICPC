//Result:2012-08-07 11:09:12	Accepted	4031	1765MS	656K	1567 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20010

inline int lowbit(int x)
{
	return x&(-x);
}

struct SegBIT
{
	int baum[SIZE];
	void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void _add(int x,int val)
	{
		while(x>0)
		{
			baum[x]+=val;
			x-=lowbit(x);
		}
	}
	void addseg(int a,int b,int val)
	{
		_add(a-1,-val);
		_add(b,val);
	}
	int sum(int x)
	{
		int res=0;
		while(x<SIZE)
		{
			res+=baum[x];
			x+=lowbit(x);
		}
		return res;
	}
};

struct node
{
	int st,end;
	node(){}
	node(int ist,int iend)
	{
		st=ist;end=iend;
	}
	bool cover(int x)
	{
		return st<=x && end>=x;
	}
};

node att[SIZE+100];
int n,q,t,ind;

int main()
{
	freopen("input.txt","r",stdin);
	int def_time[SIZE],def_num[SIZE];
	int a,b,T;
	input(T);
	SegBIT sb;
	char cmd[20];
	int cas=1;
	while(T--)
	{
		printf("Case %d:\n",cas++);
		input(n>>q>>t);
		memset(def_time,0,sizeof(def_time));
		memset(def_num,0,sizeof(def_num));
		sb.init();
		ind=0;
		for(int i=0;i<q;i++)
		{
			scanf("%s",cmd);
			if(*cmd=='A')
			{
				scanf("%d%d",&a,&b);
				sb.addseg(a,b,1);
				att[ind++]=node(a,b);
			}
			else
			{
				scanf("%d",&a);
				int p=def_time[a];
				while(p<ind)
				{
					if(att[p].cover(a))
					{
						def_num[a]++;
						def_time[a]=p+t;
						p+=t;
					}
					else p++;
				}
				printf("%d\n",sb.sum(a)-def_num[a]);
			}
		}
	}
	return 0;
}




