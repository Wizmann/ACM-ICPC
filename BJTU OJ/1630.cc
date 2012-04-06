//Result:Wizmann 	1492Kb 	2921ms 	C++ 	2012-04-06 13:02:36.0
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define SIZE 30010
#define MAX 200000100

int array[2][SIZE];
int n,k;

int miniNum(int val)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x=val-array[0][i];
		int *p=lower_bound(array[1],array[1]+n,x);
		ans+=p-array[1];
	}
	return ans;
}

int main()
{
	int T;
	input(T);
	int cas=1;
	while(T--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d%d",&n,&k);
		k--;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&array[i][j]);
			}
			sort(array[i],array[i]+n);
		}
		int l=0,r=MAX;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(k<miniNum(mid)) r=mid-1;
			else l=mid+1;
		}
		print(l-1);
	}
	return 0;
}



