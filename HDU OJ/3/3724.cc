//Result:2012-09-14 11:30:43	Accepted	3724	593MS	27832K	1583 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 10010
#define M 2010
#define ALPHA 26

struct node
{
	int next[ALPHA];
	int mark;
};

struct arch
{
	double val;
	int nr;
	arch(){}
	arch(double ival,int inr)
	{
		val=ival;nr=inr;
	}
	friend bool operator < (const arch& a,const arch& b)
	{
		return a.val<b.val;
	}
};

node trie[N*ALPHA];
int ind;
int n,q,m;
arch tt[12];

void trie_insert(char cmd[])
{
	int ptr=0;
	for(int i=0;cmd[i];i++)
	{
		int nx=cmd[i]-'a';
		if(!trie[ptr].next[nx]) trie[ptr].next[nx]=++ind;
		ptr=trie[ptr].next[nx];
		trie[ptr].mark++;
	}
}

int trie_search(char cmd[])
{
	int ptr=0;
	for(int i=0;cmd[i];i++)
	{
		int nx=cmd[i]-'a';
		if(trie[ptr].next[nx]==0) return 0;
		else ptr=trie[ptr].next[nx];
	}
	return trie[ptr].mark;
}

int main()
{
	freopen("input.txt","r",stdin);
	double tmp;
	char cmd[48];
	while(input(n>>q))
	{
		ind=0;
		memset(trie,0,sizeof(trie));
		for(int i=0;i<n;i++)
		{
			scanf("%s",cmd);
			trie_insert(cmd);
		}
		int ans=0;
		while(q--)
		{
			scanf("%d",&m);
			memset(cmd,0,sizeof(cmd));
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<8;j++)
				{
					scanf("%lf",&tmp);
					tt[j]=arch(tmp,j);
				}
				sort(tt,tt+8);
				int aa=0;
				for(int j=0;j<8;j++)
				{
					cmd[i]|=(aa<<(7-tt[j].nr));
					if(aa==0 && tt[j+1].val>tt[j].val*1.5) aa++;
				}
			}
			ans+=trie_search(cmd);
		}
		print(ans);
	}
	return 0;
}
				




