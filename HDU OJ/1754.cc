//Result:2012-08-06 15:36:42	Accepted	1754	437MS	1868K	1207 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200010

inline int lowbit(int x)
{
	return x&(-x);
}

int num[SIZE];
int baum[SIZE];
int n,q;

void init()
{
	for(int i=1;i<=n;i++)
	{
		baum[i]=num[i];
		for(int j=1;j<lowbit(i);j<<=1)
		{
			baum[i]=max(baum[i],baum[i-j]);
		}
	}
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
	for(int i=pos;i<=n;i+=lowbit(i))
	{
		baum[i]=val;
		for(int j=1;j<lowbit(i);j<<=1)
		{
			baum[i]=max(baum[i],baum[i-j]);
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	char cmd[5];
	int a,b;
	while(input(n>>q))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		init();
		while(q--)
		{
			scanf("%s%d%d",cmd,&a,&b);
			if(*cmd=='Q')
			{
				printf("%d\n",query(a,b));
			}
			else modify(a,b);
		}
	}
	return 0;
}
	
