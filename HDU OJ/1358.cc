//Result:2012-07-15 10:48:40	Accepted	1358	109MS	5400K	1024 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define inf 1e30
#define eps 1e-9
#define pb push_back

typedef long long llint;

#define SIZE 1000010

char str[SIZE+5];
int next[SIZE+5];
int len;

void kmp_get_next()
{
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0 and str[i]!=str[j]) j=next[j];
	}
}

int main()
{
	int cas=1;
	while(input(len)&&len)
	{
		memset(next,0,sizeof(next));
		scanf("%s",str);
		kmp_get_next();
		printf("Test case #%d\n",cas++);
		for(int i=1;i<=len;i++)
		{
			int t=i-next[i];
			//print(" > "<<i+1<<' '<<i-next[i]);
			if(i%t==0 and i/t>1) printf("%d %d\n",i,i/t);
		}
		//printf("%d ",i-next[i]);
		puts("");
	}
	return 0;
}


