//Result:wizmann	3691	Accepted	2748K	32MS	G++	2837B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

#define NODE 500
#define CH 4
#define ROOT 0
#define print(x) cout<<x<<endl
#define INF 1<<25

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
char comp[1010];
char word[25][55];
int dp[1010][NODE];
char del[55];

int conv(char ch)
{
	switch(ch)
	{
		case 'A':return 0;break;
		case 'C':return 1;break;
		case 'G':return 2;break;
		case 'T':return 3;break;
	}
	print("ERROR");
	return -1;
}

void insert(char *str,int nr)//建立Trie树
{
	int p=ROOT;
	for(int i=0;str[i];i++)
	{
		int c=conv(str[i]);
		if(!trie[p].next[c]) trie[p].next[c]=++sz;
		p=trie[p].next[c];
	}
	trie[p].frq++;
	trie[p].end=nr;
}

void makeAC()//AC自动机初始化
{
	queue<int> q;//BFS->Queue
	q.push(ROOT);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<CH;i++)
		{
			if(trie[p].next[i])
			{
				int v=trie[p].next[i];
				if(p!=ROOT)
				{
					trie[v].fail=trie[trie[p].fail].next[i];
				    if(trie[trie[v].end].end) trie[v].end=1;//如果此串后缀为病串，则标记
			
				}
				else trie[v].fail=ROOT;
				q.push(v);
			}
			else
			{
				if(p!=ROOT)	trie[p].next[i]=trie[trie[p].fail].next[i];
				else trie[p].next[i]=ROOT;
			}
		}
	}
}
void find()//字符串匹配
{
	int p=ROOT;
	
	for(int i=0;comp[i];i++)
	{
		while(trie[p].fail&&!trie[p].next[conv(comp[i])]) p=trie[p].fail;
		
		p=trie[p].next[conv(comp[i])];
		int t=p;
		while(t)
		{
			if(trie[t].end)
			{
				printf("FIND:%d\n",trie[t].end);
				trie[t].end=0;
			}
			t=trie[t].fail;
		}
	}
}

void dpSlove()
{
	int len=strlen(comp);
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=sz;j++) dp[i][j]=INF;
	}
	dp[0][0]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<=sz;j++) if(dp[i-1][j]<INF)
		{
			for(int k=0;k<CH;k++)
			{
				int t=trie[j].next[k];
				if(!trie[t].end)
				{
					int x=dp[i-1][j]+ ( conv(comp[i-1])!=k );
					dp[i][t]=min(x,dp[i][t]);
				}
			}
		}
	}
	int t=INF;
	for(int i=0;i<=sz;i++)
	{
		if(!trie[i].end) t=min(t,dp[len][i]);
	}
	if(t>=INF) t=-1;
	print(t);
}
	

int main()
{
	int cas=1;
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		printf("Case %d: ",cas++);
		memset(trie,0,sizeof(trie));
		memset(dp,0,sizeof(dp));
		memset(del,0,sizeof(del));
		sz=0;
		
		
		
		for(int i=1;i<=n;i++)
		{
			scanf("%s",word[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(strstr(word[i],word[j])&&strcmp(word[i],word[j])) del[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!del[i])
			{
				//print(word[i]);
				insert(word[i],i);
			}
		}
		makeAC();//建立AC自动机
		scanf("%s",comp);
		//find();
		dpSlove();
	}
	return 0;
}
