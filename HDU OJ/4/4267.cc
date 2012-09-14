//Result:2012-09-08 19:13:05	Accepted	4267	234MS	12240K	1608 B	C++	Wizmann
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
#define SIZE 50010
#define N 60

inline int lowbit(int x)
{
	return x&(-x);
}

struct SegBIT
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x>0)
		{
			baum[x]+=val;
			x-=lowbit(x);
		}
	}
	void addseg(int a,int b,int val)
	{
		add(a-1,-val);
		add(b,val);
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

int array[SIZE];
SegBIT sb[N];
int n;

int getsum(int pos,int mod,int x)
{
	int now=(x*(x-1))/2+mod;
	return sb[now].sum(pos);
}

int BIT_Query(int x)
{
	int ans=0;
	for(int i=1;i<=10;i++)
	{
		int pos=x/i;
		if(x%i) pos++;
		ans+=getsum(pos,x%i,i);
	}
	return ans;
}

void BIT_Add(int l,int r,int k,int val)
{
	int mod=l%k;
	int now=(k*(k-1))/2+mod;
	r=(r-l)/k;
	l=l/k;
	if(mod) l++;
	r+=l;
	sb[now].addseg(l,r,val);
}


int main()
{
	freopen("A.txt","r",stdin);
	int q;
	int cmd,a,b,k,c;
	while(input(n))
	{
		for(int i=0;i<N;i++) sb[i].init();
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++)
		{
			scanf("%d",array+i);
		}

		input(q);
		while(q--)
		{
			scanf("%d",&cmd);
			if(cmd==2)
			{
				scanf("%d",&a);
				printf("%d\n",BIT_Query(a)+array[a-1]);
			}
			else
			{
				scanf("%d%d%d%d",&a,&b,&k,&c);
				BIT_Add(a,b,k,c);
			}
		}
	}
	return 0;
}




