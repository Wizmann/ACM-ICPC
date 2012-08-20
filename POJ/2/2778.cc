//Result:wizmann	2778	Accepted	1420K	438MS	G++	4098B
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define NODE 250000
#define START 0
#define MOD 100000
#define CH 4

using namespace std;

struct matrix
{
	int y,x;
	long long m[101][101];
	matrix(){memset(m,0,sizeof(m));y=0,x=0;}
	matrix(int a,int b):y(a),x(b){memset(m,0,sizeof(m));}
	void init1(){for(int i=0;i<y;i++) m[i][i]=1;}

	friend matrix operator * (matrix a,matrix b)
	{
		matrix c(a.y,b.x);
		for(int i=0;i<a.y;i++)
		{
			for(int j=0;j<a.x;j++)
			{
				c.m[i][j]=0;
				for(int k=0;k<b.x;k++)
				{
					c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
				}
			}
		}
		return c;
	}

	friend matrix operator ^ (matrix a,int k)
	{
		matrix res(a.y,a.x);
		res.init1();
		while(k)
		{
			if(k&1) res=res*a;
			a=a*a;k>>=1;
		}
		return res;
	}
	long long sum()
	{
		long long res=0;
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++) res=(res+m[i][j])%MOD;
		}
		return res;
	}
};


struct node
{
	int next[CH];
	int fail;
	int frq;
	int end; 
};


node trie[NODE];
int n,sz,k;
char comp[1000004];
matrix trans;

inline int conv(char ch)
{
	switch(ch)
	{
		case 'A':return 0;break;
		case 'C':return 1;break;
		case 'G':return 2;break;
		case 'T':return 3;break;
		default:{cout<<ch<<endl;return -1;}break;
	}
}

void insert(char *str,int nr)//建立Trie树
{
	int p=START;
	for(int i=0;str[i];i++)
	{
		int c=conv(str[i]);
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
		if(trie[START].next[i])
		{
			trie[trie[START].next[i]].fail=START;
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
	int p=START;
	
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

void calc(int x)
{
	for(int i=0;i<CH;i++)
	{
		int p=x;
		while(p&&!trie[p].next[i]) p=trie[p].fail;
		if(trie[p].next[i])
		{
			if(!trie[trie[p].next[i]].end) trans.m[x][trie[p].next[i]]=1;
		}
		else trans.m[x][0]++;
	}
}

bool substr(char *a,char *b)
{
	char *p=strstr(b,a);
	if(p) return true;
	else return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int m;
	scanf("%d%d",&m,&k);
	sz=1;
	char str[10][20];
	char del[10];//找出重复子串，并删除
	memset(del,0,sizeof(del));
	for(int i=0;i<m;i++) scanf("%s",str[i]);
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++) if(i!=j)
		{
			if(substr(str[j],str[i])) del[i]=1;
		}
	}
	for(int i=0;i<m;i++) if(!del[i])
	{
		insert(str[i],i+1);
		puts(str[i]);
	}
	makeAC();//建立AC自动机
	n=sz;
	trans.x=trans.y=n+1;//状态转移矩阵初始化
	int pad;
	queue<int> q;
	for(int i=0;i<4;i++)
	{
		pad=trie[START].next[i];
		if(pad)
		{
			if(!trie[pad].end)
			{
				trans.m[0][pad]=1;
				q.push(pad);
			}
		}
		else trans.m[0][0]++;
	}//BFS的第一步
	for(int i=1;i<=n;i++) if(!trie[i].end) calc(i);//记录状态转移点
	matrix start(1,n+1);
	start.m[0][0]=1;
	start=start*(trans^k);
	//通过矩阵乘，求出最后的结果。。。矩阵是什么。。。不知道。。。＝ ＝。。。。
	printf("%lld\n",start.sum());
	return 0;
}
