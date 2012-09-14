//Result:2012-09-08 20:49:31	Accepted	4277	859MS	4776K	982 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 15

int n,sum;
int array[SIZE+5];
set< pair<int,int> > st;

void dfs(int a,int b,int step)
{
	int c=sum-a-b;
	if(a>c || b>c || a>sum/3) return;
	if(step==n)
	{
		if(a+b>c && b+c>a && a+c>b)
		{
			st.insert(make_pair(max(a,b),min(a,b)));
		}
	}
	else
	{
		dfs(a+array[step],b,step+1);
		dfs(a,b+array[step],step+1);
		dfs(a,b,step+1);
	}
}



int main()
{
	freopen("input.txt","r",stdin);
	int T,ans;
	input(T);
	while(T--)
	{
		sum=ans=0;
		st.clear();
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",array+i);
			sum+=array[i];
		}

		dfs(0,0,0);
		/*
		for(set<pair<int,int> >::iterator iter=st.begin();iter!=st.end();iter++)
		{
			printf("%d %d\n",iter->first,iter->second);
		}
		*/
		print(st.size());
	}
	return 0;
}
