//Result:1027779 	5990 	Array Diversity 	Accepted 	C++ 	0.160 	2012-07-03 05:04:02
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100000
#define MOD 1000000007LL
#define INF 1LL<<60

typedef long long llint;

llint min(llint a,int b)
{
	return a<b?a:b;
}

llint safemul(llint a,llint b,llint c=MOD)
{
	llint ans=0;
	while(b)
	{
		if(b&1) ans+=a;
		if(b>1) a+=a;
		ans%=c;
		a%=c;
		b>>=1;
	}
	return ans;
}


llint fastmod(llint a,llint b,llint c=MOD)
{
	if(b<0) return 1;
	else if(b==0) return 1;
	else if(b==1) return a%c;
	else
	{
		llint tmp=fastmod(a,b>>1);
		tmp=safemul(tmp,tmp);
		if(b&1) return tmp*a%c;
		else return tmp;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	llint array[SIZE];
	llint T,n;
	int max_pos[SIZE],min_pos[SIZE];
	llint ans_a,ans_b;
	input(T);
	while(T--)
	{
		llint maxv=-INF,minv=INF;
		llint mindis=INF;
		llint maxn,minn;
		int maxptr=0,minptr=0;
		maxn=minn=0;
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",array+i);
			maxv=max(maxv,array[i]);
			minv=min(minv,array[i]);
		}
		llint a=-INF,b=-INF;
		for(int i=0;i<n;i++)
		{
			if(array[i]==minv)
			{
				mindis=min(mindis,i-b);
				min_pos[minptr++]=i;
				a=i;
				minn++;
			}
			if(array[i]==maxv)
			{
				mindis=min(mindis,i-a);
				max_pos[maxptr++]=i;
				b=i;
				maxn++;
			}
		}
		if(maxv!=minv)
		{
			ans_a=0;
			for(int i=0;i<n;i++)
			{
				int max_dis=lower_bound(max_pos,max_pos+maxptr,i)-max_pos;
				int min_dis=lower_bound(min_pos,min_pos+minptr,i)-min_pos;
				if(max_dis==maxptr || min_dis==minptr) break;
				else
				{
					max_dis=max_pos[max_dis];
					min_dis=min_pos[min_dis];
				}
				int dis=max(max_dis,min_dis);
				ans_a+=n-dis;
				ans_a%=MOD;
			}
			ans_b=fastmod(2LL,(n-minn-maxn))*((fastmod(2,minn)-1)*(fastmod(2,maxn)-1)%MOD)%MOD;
			
		}
		else
		{
			ans_a=0;
			for(int i=0;i<n;i++)
			{
				ans_a+=n-i;
				ans_a%=MOD;
			}
			ans_b=fastmod(2LL,n)-1;
		}
		printf("%lld %lld\n",ans_a,ans_b);
	}
	return 0;
}
