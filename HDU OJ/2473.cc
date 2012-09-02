//Result:2012-09-01 14:13:05	Accepted	2473	625MS	5012K	1117 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define SIZE 100100
#define NODE 1000100


int father[SIZE<<3];
int ptr;
int m,n;

int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}

void makeLink(int a,int b)
{
	father[findfather(a)]=findfather(b);
}

void erase(int a)
{
	father[a]=ptr++;
}

int slove()
{
	set<int> st;
	for(int i=0;i<n;i++)
	{
		st.insert(findfather(i));
	}
	return st.size();
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,cas=1;
	char cmd[5];
	while(input(n>>m))
	{
		if(n+m==0) break;
		ptr=SIZE<<1;
		for(int i=0;i<SIZE;i++) father[i]=i+SIZE;
		for(int i=SIZE;i<SIZE<<3;i++) father[i]=i; 
		for(int i=0;i<m;i++)
		{
			scanf("%s",cmd);
			if(*cmd=='M')
			{
				scanf("%d%d",&a,&b);
				makeLink(a,b);
			}
			else
			{
				scanf("%d",&a);
				erase(a);
			}
		}
		printf("Case #%d: ",cas++);
		print(slove());
	}
	return 0;
}


