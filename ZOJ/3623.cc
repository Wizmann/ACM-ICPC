//Result:2012-07-29 20:36:19	 Accepted	3623	C++	0	188	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(_) cout<<_<<endl
#define input(_) cin>>_
#define SIZE 30
#define MAX 333

const int INF=1<<26;

int n,l;

struct ship
{
	int att,cost;
	ship(){}
	ship(int iatt,int icost)
	{
		att=iatt;
		cost=icost;
	}
	
	friend bool operator < (const ship& a,const ship& b)
	{
		return a.cost<b.cost;
	}
};

ship array[SIZE];

bool slove(int x)
{
	int blood=l;
	int attack=0;
	int next_t=-1;
	int next_v=-1;
	for(int i=0;i<x;i++)
	{
		if(next_t==i)
		{
			attack+=array[next_v].att;
			next_t=-1;
		}
		
		if(next_t==-1)
		{
			int ptr=-1;
			int value=-INF;
			for(int j=0;j<n;j++)
			{
				int t=(x-i-array[j].cost)*array[j].att;
				if(t>value)
				{
					ptr=j;
					value=t;
				}
			}
			next_t=i+array[ptr].cost;
			next_v=ptr;
		}
		

		blood-=attack;
		if(blood<=0) break;
	}

	if(blood<=0) return true;
	else return false;
}

int main()
{
	freopen("b.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			array[i]=ship(b,a);
		}
		sort(array,array+n);
		int left=0,right=MAX;
		
		while(left<=right)
		{
			int mid=(left+right+1)>>1;
			if(slove(mid)) right=mid-1;
			else left=mid+1;
		}
		print(left);		
	}
	return 0;
}

