//Result:2011-08-21 23:41:35	Accepted	3065	281MS	27916K	1758 B	G++	Foc_Kuuy
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>

#define NODE 50000
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
int n,sz;
char comp[2000004];
int sum[1005];
string hash[1005];

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
	for(int i=0;comp[i];i++)
	{
		while(trie[p].fail&&!trie[p].next[comp[i]]) p=trie[p].fail;
		
		p=trie[p].next[comp[i]];
		int t=p;
		while(t)
		{
			if(trie[t].end) sum[trie[t].end]++;
			t=trie[t].fail;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	char word[50];
	
	while(scanf("%d",&n)!=EOF)
	{
		memset(trie,0,sizeof(trie));
		memset(sum,0,sizeof(sum));
		sz=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",word);
			hash[i]=word;
			insert(word,i);//建立Trie树
		}
		makeAC();//建立AC自动机
		
		*comp='\0';
		while(*comp=='\0') gets(comp);
		find();
		
		for(int i=1;i<=n;i++)
		{
			if(sum[i]) printf("%s: %d\n",hash[i].c_str(),sum[i]);
		}
	}
	return 0;
}
