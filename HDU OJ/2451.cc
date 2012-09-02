//Result:2012-09-01 15:12:10	Accepted	2451	296MS	6672K	849 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE=10;

llint zehn[SIZE];
llint array[800000];
int ptr;

void dfs(int len,llint val=0)
{
	if(len==SIZE) return;
	else if(len==0)
	{
		for(int i=0;i<=2;i++)
		{
			array[ptr++]=i;
			dfs(len+1,i);
		}
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			llint tmp=val+i*zehn[len];
			array[ptr++]=tmp;
			dfs(len+1,tmp);
		}
		dfs(len+1,val);
	}
}
		

void init()
{
	ptr=0;
	zehn[0]=1;
	for(int i=1;i<SIZE;i++) zehn[i]=zehn[i-1]*10;
	dfs(0);
}

int main()
{
	freopen("input.txt","r",stdin);
	llint x;
	init();
	sort(array,array+ptr);
	while(input(x))
	{
		print(lower_bound(array,array+ptr,x)-array);
	}
	return 0;
}
