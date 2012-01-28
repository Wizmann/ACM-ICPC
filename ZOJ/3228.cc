//Result:2012-01-28 12:49:29	 Accepted	3228	C++	2130MS	25416KB	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define STRLEN 100001
#define N 100010
#define SHORTSTR 8
#define ALPHA 26
#define SIZE 60000
#define ROOT 0

struct node
{
	int next[ALPHA];
	int fail,last,len;
	int olap,nolap;
};

node trie[SIZE];
int num[N];
char str[STRLEN];
int n,ind;
int father[N];

int findFather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findFather(father[x]);
}

void trieInsert(char *instr,int endMark,int type)
{
	int ptr=ROOT;
	for(int i=0;instr[i];i++)
	{
		int now=instr[i]-'a';
		if(!trie[ptr].next[now])
		{
			trie[ptr].next[now]=ind++;
		}
		ptr=trie[ptr].next[now];
	}
	//type = 0 denotes substring a is allowed to overlap and type = 1 denotes not.
	if(type)
	{
		father[trie[ptr].nolap]=endMark;
		trie[ptr].nolap=endMark;
	}
	else
	{
		father[trie[ptr].olap]=endMark;
		trie[ptr].olap=endMark;
	}
	trie[ptr].last=-1;
	trie[ptr].len=strlen(instr);
}

void makeAC()
{
	queue<int> q;
	for(int i=0;i<ALPHA;i++)
	{
		if(trie[ROOT].next[i])
		{
			trie[trie[ROOT].next[i]].fail=ROOT;
			q.push(trie[ROOT].next[i]);
		}
	}
	
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=0;i<ALPHA;i++)
		{
			if(trie[now].next[i])
			{
				int v=trie[now].next[i];
				int fail=trie[now].fail;
				q.push(v);
				trie[v].fail=trie[fail].next[i];
			}
			else
			{
				int fail=trie[now].fail;
				trie[now].next[i]=trie[fail].next[i];
			}
		}
	}
}

void search()
{
	int ptr=ROOT;
	for(int i=0;str[i];i++)
	{
		int now=str[i]-'a';
		while(trie[ptr].fail && !trie[ptr].next[now]) ptr=trie[ptr].fail;
		ptr=trie[ptr].next[now];
		
		int t=ptr;
		while(t)
		{
			if(trie[t].olap||trie[t].nolap)
			{
				if(trie[t].olap) num[findFather(trie[t].olap)]++;
				if(trie[t].nolap && i-trie[t].last>=trie[t].len)
				{
					num[findFather(trie[t].nolap)]++;
					trie[t].last=i;
				}
			}
			t=trie[t].fail;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	char sstr[SHORTSTR];
	int type;
	int cas=1;
	while(scanf("%s",str)!=EOF)
	{
		print("Case "<<cas++);
		ind=1;
		input(n);
		
		for(int i=0;i<=n;i++) father[i]=i;
		memset(trie,0,sizeof(trie));
		memset(num,0,sizeof(num));
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d%s",&type,sstr);
			trieInsert(sstr,i,type);
		}
		makeAC();
		search();
		for(int i=1;i<=n;i++)
		{
			printf("%d\n",num[findFather(i)]);
		}
		print("");
	}
	return 0;
}
	
