//Result:2012-09-12 14:48:32	Accepted	4287	62MS	504K	734 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int cov[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main()
{
	freopen("input.txt","r",stdin);
	int T,t,n,m;
	char str[12];
	int press[5120];
	map<int,int> mp;
	input(T);
	while(T--)
	{
		mp.clear();
		input(n>>m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",press+i);
		}
		while(m--)
		{
			scanf("%s",str);
			t=0;
			for(int i=0;str[i];i++)
			{
				t=t*10+cov[str[i]-'a'];
			}
			//print(t);
			mp[t]++;
		}
		for(int i=0;i<n;i++)
		{
			printf("%d\n",mp[press[i]]);
		}
	}
	return 0;
}
	
