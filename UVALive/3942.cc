//Result:3942	Remember the Word	Accepted	C++	0.232	2012-08-13 15:52:32
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 300100
#define ALPHA 26
#define MOD 20071027

typedef long long llint;

struct node
{
	int next[ALPHA];
	int cnt;
};

node trie[SIZE];
char str[SIZE];
int n,ind;
const int ROOT=1;
int len;

void trie_insert(char *s,int pos=ROOT)
{
	if(!(*s)) trie[pos].cnt++;
	else
	{
		int v=*s-'a';
		if(trie[pos].next[v]==0)
		{
			trie[pos].next[v]=++ind;
		}
		trie_insert(s+1,trie[pos].next[v]);
	}
}

void query(const int pos,llint *dp)
{
	int ptr=ROOT;
	for(int i=0;i+pos<=len;i++)
	{
		if(trie[ptr].cnt)
		{
			dp[i+pos]+=dp[pos];
			dp[i+pos]%=MOD;
		}
		
		ptr=trie[ptr].next[str[pos+i]-'a'];
		if(!ptr) break;
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	llint dp[SIZE];
	char clip[128];
	int cas=1;
	while(scanf("%s",str)!=EOF)
	{
		printf("Case %d: ",cas++);
		ind=1;
		memset(trie,0,sizeof(trie));
		len=strlen(str);
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",clip);
			trie_insert(clip);
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<len;i++) query(i,dp);
		print(dp[len]);
	}
	return 0;
}


	
	
		
