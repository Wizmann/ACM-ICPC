//Result:2012-09-03 20:41:30	Accepted	4039	781MS	664K	1955 B	C++	Wizmann
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 4096
#define pb push_back

map<string,int> hash;
map<int,string> anhash;
vector<int> g[SIZE];
map<int,int> com;
int ind,ptr,n,q;
string name[SIZE];

void slove(int x)
{
	ptr=0;
	com.clear();
	set<int> now;
	now.insert(x);
	for(int i=0;i<(int)g[x].size();i++)
	{
		now.insert(g[x][i]);
	}
	for(int i=0;i<(int)g[x].size();i++)
	{
		int next=g[x][i];
		for(int j=0;j<(int)g[next].size();j++)
		{
			int nextnext=g[next][j];
			if(now.find(nextnext)!=now.end()) continue;
			else com[nextnext]++;
		}
	}
	int num=-1;
	for(map<int,int>::iterator iter=com.begin();iter!=com.end();iter++)
	{
		num=max(num,iter->second);
	}
	int p=0;
	if(num==-1) puts("-");
	else
	{
		for(map<int,int>::iterator iter=com.begin();iter!=com.end();iter++)
		{
			if(iter->second==num)
			{
				name[p++]=anhash[iter->first];
			}
		}
		sort(name,name+p);
		for(int i=0;i<p;i++)
		{
			if(i) printf(" ");
			printf("%s",name[i].c_str());
		}
		puts("");
	}
}



int main()
{
	freopen("input.txt","r",stdin);
	int T,cas=1;
	char a[24],b[24];
	input(T);
	while(T--)
	{
		ind=1;
		for(int i=0;i<SIZE;i++) g[i].clear();
		hash.clear();
		anhash.clear();
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++)
		{
			scanf("%s%s",a,b);
			if(hash.find(a)==hash.end())
			{
				anhash[ind]=a;
				hash[a]=ind++;
			}
			if(hash.find(b)==hash.end())
			{
				anhash[ind]=b;
				hash[b]=ind++;
			}
			g[hash[a]].pb(hash[b]);
			g[hash[b]].pb(hash[a]);
		}
		printf("Case %d:\n",cas++);
		while(q--)
		{
			scanf("%s",a);
			if(hash.find(a)==hash.end())
			{
				anhash[ind]=a;
				hash[a]=ind++;
			}
			slove(hash[a]);
		}
	}
	return 0;
}
