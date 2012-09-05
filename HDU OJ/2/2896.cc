//Result:2011-08-21 22:44:24	Accepted	2896	187MS	29252K	1874 B	G++	Foc_Kuuy
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>

#define NODE 400000
#define CH 128
#define ROOT 0

using namespace std;

struct node
{
	int next[CH];
	int fail;
	int frq;
	int end; 
};

node trie[NODE];
int n,m,sz;
char comp[10004];
set<int> st;
set<int>::iterator iter;

void insert(char *str,int nr)//建立Trie树
{
	int p=ROOT;
	for(int i=0;str[i];i++)
	{
		int c=str[i];
		if(!trie[p].next[c]) trie[p].next[c]=sz++;
		p=trie[p].next[c];
	}
	trie[p].frq++;
	trie[p].end=nr;
}

void makeAC()//AC自动机初始化
{
	queue<int> q;//BFS->Queue
	for(int i=0;i<CH;i++)
	{
		if(trie[ROOT].next[i])
		{
			trie[trie[ROOT].next[i]].fail=ROOT;
			q.push(trie[0].next[i]);
		}
	}
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<CH;i++)
		{
			if(trie[p].next[i])
			{
				int v=trie[p].next[i];
				q.push(v);
				trie[v].fail=trie[trie[p].fail].next[i];
			}
			else trie[p].next[i]=trie[trie[p].fail].next[i];
		}
	}
}

void find()//字符串匹配
{
	int p=ROOT;
	st.clear();
	for(int i=0;comp[i];i++)
	{
		while(trie[p].fail&&!trie[p].next[comp[i]]) p=trie[p].fail;
		
		p=trie[p].next[comp[i]];
		int t=p;
		while(t)
		{
			if(trie[t].end) st.insert(trie[t].end);
			t=trie[t].fail;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	char word[210];
	sz=1;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		*word='\0';
		while(*word=='\0') gets(word);
		insert(word,i);//建立Trie树
	}
	makeAC();//建立AC自动机
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		*comp='\0';
		while(*comp=='\0') gets(comp);
		find();
		if(!st.empty())
		{
			ans++;
			printf("web %d:",i);
			iter=st.begin();
			while(iter!=st.end())
			{
				printf(" %d",*iter);
				++iter;
			}
			puts("");
		}
	}
	printf("total: %lld\n",ans);
	return 0;
}
