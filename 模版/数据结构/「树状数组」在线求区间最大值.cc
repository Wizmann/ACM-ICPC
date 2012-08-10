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

inline int lowbit(int x){return x&(-x);}

int num[SIZE];//原数组
int baum[SIZE];//树状数组
int n,q;

void init()//初始化
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

int query(int a,int b)//求[a,b]之间的最大值
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

void modify(int pos,int val)//对于pos位置上的点进行修改
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
	char cmd[5];
	int a,b;
	while(input(n>>q))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		init();//初始化
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
	
