//Result:2012-08-24 20:31:29	Accepted	2094	31MS	336K	884 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

map<string,int> hash;
int ind,n;
int in[SIZE];
vector<int> g[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	char a[128],b[128];
	while(input(n) && n)
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		hash.clear();
		ind=1;
		memset(in,0,sizeof(in));
		for(int i=0;i<n;i++)
		{
			scanf("%s%s",a,b);
			if(hash.find(a)==hash.end()) hash[a]=ind++;
			if(hash.find(b)==hash.end()) hash[b]=ind++;
			g[hash[a]].push_back(hash[b]);
			in[hash[b]]++;
		}
		set<int> winner;
		for(int i=1;i<ind;i++)
		{
			if(!in[i]) winner.insert(i);
		}
		if(winner.size()!=1) puts("No");
		else puts("Yes");
	}
	return 0;
}


