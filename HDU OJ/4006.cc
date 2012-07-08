#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int n,k;
multiset<int> pq;

int query()
{
	multiset<int>::iterator iter=pq.begin();
	return *iter;
}

void insert_pq(int a)
{
	if(pq.size()<k) pq.insert(a);
	else
	{
		multiset<int>::iterator iter=pq.begin();
		if(*iter<a)
		{
			pq.erase(iter);
			pq.insert(a);
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	char cmd[5];
	int a;
	while(input(n>>k))
	{
		pq.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s",cmd);
			if(*cmd=='Q')
			{
				printf("%d\n",query());
			}
			else 
			{
				scanf("%d",&a);
				insert_pq(a);
			}
		}
	}
	return 0;
}
			

