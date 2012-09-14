//Result:2012-09-08 18:49:29	Accepted	4268	2828MS	10728K	2242 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 200100

inline int lowbit(int x)
{
	return x&(-x);
}

struct card
{
	int x,y;
	int type;
	card(){}
	card(int ix,int iy,int it){x=ix;y=iy;type=it;}
	friend bool operator < (const card &a,const card &b)
	{
		if(a.y!=b.y) return a.y<b.y;
		else if(a.x!=b.x) return a.x<b.x;
		else return a.type>b.type;
	}
};

struct BIT
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x<SIZE)
		{
			baum[x]+=val;
			x+=lowbit(x);
		}
	}
	int sum(int x)
	{
		int res=0;
		while(x>0)
		{
			res+=baum[x];
			x-=lowbit(x);
		}
		return res;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

int array[SIZE];
map<int,int> hash;
int n;
card pocket[SIZE];
BIT bit;
int ind,sz;

int slove()
{
	int ans=0;
	bit.init();
	for(int i=0;i<2*n;i++)
	{
		if(pocket[i].type==1)
		{
			bit.add(pocket[i].x,1);
		}
		else
		{
			int l=0,r=pocket[i].x;
			int now=bit.sum(0,pocket[i].x);
			if(now==0) continue;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int now=bit.sum(pocket[i].x-mid,pocket[i].x);
				if(now) r=mid-1;
				else l=mid+1;
			}
			//print("L:"<<l);
			ans++;
			bit.add(pocket[i].x-l,-1);
		}
	}
	return ans;
}
			


int main()
{
	freopen("2.txt","r",stdin);
	int T;
	int a,b;
	input(T);
	while(T--)
	{
		ind=0;
		sz=1;
		hash.clear();
		input(n);
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			a++;b++;
			pocket[i]=card(a,b,0);
			array[ind++]=a;
			//array[ind++]=b;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			a++;b++;
			pocket[i+n]=card(a,b,1);
			array[ind++]=a;
			//array[ind++]=b;
		}
		sort(array,array+ind);
		for(int i=0;i<ind;i++)
		{
			if(array[i]!=array[i+1])
			{
				hash[array[i]]=sz++;
			}
		}
		for(int i=0;i<2*n;i++)
		{
			pocket[i].x=hash[pocket[i].x];
			//pocket[i].y=hash[pocket[i].y];
		}
			
		sort(pocket,pocket+n*2);
		print(slove());
	}
	return 0;
}



