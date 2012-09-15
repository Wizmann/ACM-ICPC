//Result:2012-09-15 15:25:02	Accepted	3729	250MS	3452K	1867 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100000

const int INF=0x3f3f3f3f;

struct node
{
	int dest,cost;
	node(){}
	node(int idest,int icost)
	{
		dest=idest;
		cost=icost;
	}
};

vector<int> g[SIZE];
int q,ind;
int array[SIZE<<2];
pair<int,int> query[SIZE];
vector<int> ans;
map<int,int> mp;
int pre[SIZE],match[SIZE];

bool deal(int nr,int *match)
{
	for(int i=0;i<(int)g[nr].size();i++)
	{
		int next=g[nr][i];
		if(!match[next])
		{
			match[next]=true;
			if(!pre[next] || deal(pre[next],match))
			{
				pre[next]=nr;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int sum=0;
	memset(pre,0,sizeof(pre));
	
	for(int i=q-1;i>=0;i--)
	{
		memset(match,0,sizeof(match));
		if(deal(i,match))
		{
			sum++;
			ans.push_back(i);
		}
	}
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		ans.clear();
		set<int> st;
		mp.clear();
		for(int i=0;i<SIZE;i++) g[i].clear();
		
		ind=0;
		input(q);
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&a,&b);
			query[i]=make_pair(a,b);
			if(st.find(a)==st.end())
			{
				array[ind++]=a;
				st.insert(a);
			}
			if(st.find(b)==st.end())
			{
				array[ind++]=b;
				st.insert(b);
			}
		}
		sort(array+0,array+ind);
		for(int i=0;i<ind;i++)
		{
			mp[array[i]]=i;
		}
		for(int i=0;i<q;i++)
		{
			a=query[i].first;
			b=query[i].second;
			for(int j=a;j<=b;j++) g[i].push_back(j);
		}
		print(hungary());
		sort(ans.begin(),ans.end());
		for(int i=0;i<(int)ans.size();i++)
		{
			if(i) printf(" ");
			printf("%d",ans[i]+1);
		}
		puts("");
	}
	return 0;
}
