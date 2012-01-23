//Result: Accepted	2222	750MS	31640K	1567 B	C++	Foc_Kuuy
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define NODE 250000
#define CH 28
#define ROOT 0

using namespace std;

struct node
{
	int next[CH];
	int fail;
	int frq;
	char end; 
};

node trie[NODE];
int n,sz;
char comp[1000004];

void insert(char *str)
{
	int p=ROOT;
	for(int i=0;str[i];i++)
	{
		int c=str[i]-'a';
		if(!trie[p].next[c]) trie[p].next[c]=sz++;
		p=trie[p].next[c];
	}
	trie[p].frq++;;
	trie[p].end=1;
}

void makeAC()
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

int find()
{
	long long ans=0;
	int p=ROOT;
	
	for(int i=0;comp[i];i++)
	{
		while(trie[p].fail && !trie[p].next[comp[i]-'a'])
		{
			p=trie[p].fail;
		}
		
		p=trie[p].next[comp[i]-'a'];
		int t=p;
		while(t)
		{
			if(trie[t].end)
			{
				ans+=trie[t].frq;
				trie[t].end=0;
			}
			t=trie[t].fail;
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	char word[66];
	scanf("%d",&t);
	while(t--)
	{
		sz=1;
		memset(trie,0,sizeof(trie));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",word);
			insert(word);//建立Trie树
		}
		makeAC();//建立AC自动机
		scanf("%s",comp);
		printf("%d\n",find());
	}
	return 0;
}
		
