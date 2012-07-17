//Result:2012-07-15 11:35:29	Accepted	3336	31MS	1452K	940 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>
#include <ctime>
#include <cctype>


using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<30
#define inf 1e30
#define eps 1e-9
#define pb push_back

typedef long long llint;

#define SIZE 200010

int len;
char str[SIZE+5];
int next[SIZE+5];

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
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		int ans=0;
		input(len);
		scanf("%s",str);
		kmp_get_next();
		
		for(int i=1;i<=len;i++)
		{
			if(next[i]+1!=next[i+1]) ans+=next[i];
		}
		print((ans+len)%10007);
	}
	return 0;
}
