//Result:2012-07-29 20:38:50	 Accepted	3631	C++	290	188	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32

typedef long long llint;

llint n,val;

llint slove(llint *item)
{
	int ind=0;
	int mid=n/2;
	llint tmp[100000];
	llint ans=0;

	for(int i=0;i<(1<<mid);i++)
	{
		llint res=0;
		for(int j=0;j<mid;j++)
		{
			if(i&(1<<j)) res+=item[j];
		}
		if(res<=val) tmp[ind++]=res;
	}
	sort(tmp,tmp+ind);
	int left=n-mid;
	for(int i=0;i<(1<<left);i++)
	{
		llint res=0;
		for(int j=0;j<left;j++)
		{
			if(i&(1<<j)) res+=item[mid+j];
		}
		if(res<=val)
		{
			if(val-res<val-ans) ans=res;
			int ptr=upper_bound(tmp,tmp+ind,val-res)-tmp-1;
			if(ptr>0) res+=tmp[ptr];
			if(val-res<val-ans) ans=res;			
		}
	}
	return ans;
}

int main()
{
	freopen("j.txt","r",stdin);
	llint item[SIZE];
	while(scanf("%lld%lld",&n,&val)!=EOF)
	{
		for(int i=0;i<n;i++) scanf("%lld",item+i);
		printf("%lld\n",slove(item));
	}
	return 0;
}
	
